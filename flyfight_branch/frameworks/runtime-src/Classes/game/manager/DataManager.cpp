//
//  DataManager.cpp
//  flyfight_branch
//
//  Created by coldouyang on 14-6-17.
//
//

#include "DataManager.h"

#include "game/data_table/ability_data_table.h"
#include "game/event/GameEventConstant.h"
#include "engine/script/lua_tinker_manager.h"

using namespace cocos2d;

static const char* KEY_CURRENT_USER_ID = "k_cur_user_id";


template <class TableDataType>
void LoadSingleTable(TableDataType** data_table, std::string table_file_name)
{
    if(*data_table == NULL)
    {
        *data_table = new TableDataType();
        
        if(!(*data_table)->InitWithFileName(table_file_name.c_str()))
        {
            log(" loadfile failed: %s", table_file_name.c_str());
        }
    }
}

template <class TableDataType>
void RegisterAsyncLoadHandle(TableDataType** data_table, std::string table_file_name)
{
    //std::function<void (TableDataType**, std::string)> handle_function = &LoadSingleTable <TableDataType>;
    auto loadFunction = std::bind(&LoadSingleTable<TableDataType>, data_table, table_file_name);
    std::function<void()> loadF = std::bind(&LoadSingleTable<TableDataType>, data_table, table_file_name);
    //loadFunction();
    loadF();
    //return loadF;
    //UpdateController::GetInstance().RegisterLoadFunctionHandle(handle_delegate);
}

////////////////////////////////////////////////////////////////////

DataManager* DataManager::GetInstance()
{
    static DataManager* M = NULL;
    if (!M)
    {
        M = new DataManager();
        M->init();
    }
    return M;
}

DataManager::DataManager() : mAbilityDataTable_(NULL)
    , mCurrentUserInfo(NULL)
    , mCurrentUserID(-1)
{
}

DataManager::~DataManager()
{
    CC_SAFE_RELEASE(mCurrentUserInfo);
    mCurrentUserInfo = NULL;
}

bool DataManager::init()
{
    RegisterAsyncLoadHandle<AbilityDataTable>(&mAbilityDataTable_, "test.csv");
    
    //------------------------------------------------------------------------
    LuaTinkerManager::GetInstance().CallLuaFunc<bool>("src/data/data_loader.lua", "InitDataTable");
    
    log("DataManager Begin init UserInfo");
    mCurrentUserID = UserDefault::getInstance()->getIntegerForKey(KEY_CURRENT_USER_ID, 502);
    mCurrentUserInfo = UserInfo::create();
    mCurrentUserInfo->retain();
    mCurrentUserInfo->initUserInfoFromProtobuf(mCurrentUserID);
    return true;
}

void DataManager::changerUser(int userID)
{
    CC_SAFE_RELEASE(mCurrentUserInfo);
    mCurrentUserInfo = NULL;
    
    mCurrentUserID = userID;
    mCurrentUserInfo = UserInfo::create();
    mCurrentUserInfo->initUserInfoFromProtobuf(mCurrentUserID);
    mCurrentUserInfo->retain();
    
    UserDefault::getInstance()->setIntegerForKey(KEY_CURRENT_USER_ID, mCurrentUserID);
    UserDefault::getInstance()->flush();
    
    //send change userinfo event
    Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(A_EVENT_USER_CHANGE);
}


BaseData* DataManager::getBaseData(int eID)
{
    DataMap::iterator it = mDataMap.find(eID);
    if (it == mDataMap.end())
    {
        log("IDManager ERROR [BaseData Not find id=%d]", eID);
        return NULL;
    }
    
    return it->second;
}

void DataManager::registerBaseData(BaseData *data)
{
    mDataMap.insert(std::make_pair(data->getEID(), data));
}