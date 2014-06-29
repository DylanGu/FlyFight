//
//  UserInfo.cpp
//  flyfight_branch
//
//  Created by snowcold on 29/6/14.
//
//

#include "UserInfo.h"
#include "engine/script/lua_tinker_manager.h"
#include "game/data_table/pb/UserInfoRecordProto.pb.h"
#include "game/module/UnitFactory.h"
#include "game/module/BaseUnit.h"
#include "game/manager/IDManager.h"

USING_NS_CC;

UserInfo* UserInfo::create()
{
    UserInfo* pRet = new UserInfo();
    if (pRet)
    {
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return NULL;
}

UserInfo::UserInfo() : mCurrentFighterSID(0), mUserID(-1)
{
    
}

UserInfo::~UserInfo()
{
    
}

void UserInfo::initUserInfoFromDB(int userID)
{
    mUserID = userID;
}

void UserInfo::initUserInfoFromProtobuf(int userID)
{
    mUserID = userID;
    std::string path = FileUtils::getInstance()->getWritablePath();
    char name[64];
    sprintf(name, "user_%d.db", userID);
    path += name;
    log("Path:[%s]", path.c_str());
    std::string msg = FileUtils::getInstance()->getStringFromFile(path);
    if (msg.size() > 0)
    {
        log("UserInfo Success read from file");
        UserInfoRecordProto record;
        record.ParseFromString(msg);
        
        mUserID = record.userid();
        mUserName = record.username();
        mCurrentFighterSID = record.currentfighterid();
        
        mAllUnitList.clear();
        mAllUnitMap.clear();
        
        for(int i = 0; i < record.unitattr_size(); ++i)
        {
            const BaseAttrProto& attr = record.unitattr(i);
            BaseData* data = BaseDataHelper::createDataAsAttrProto(&attr);
            BaseUnit* unit = UnitFactory::createUnit(data);
            unit->setBaseData(data);
            unit->rebuildAsData();
            addUnit(unit);
        }
    }
    else//初始游戏，运行游戏脚本,初始化当前角色
    {
        log("UserInfo begin a init new user");
        LuaTinkerManager::GetInstance().CallLuaFunc<bool>("src/data/userinfo_loader.lua", "InitUserInfo", mUserID);
        saveUserInfoToClien();
    }
    
    dump();
}

bool UserInfo::saveUserInfoToClien()
{
    std::string path = FileUtils::getInstance()->getWritablePath();
    char name[64];
    sprintf(name, "user_%d.db", mUserID);
    path += name;
    log("Path:[%s]", path.c_str());

    FILE* fp = fopen(path.c_str(), "wb");
    if (fp)
    {
        UserInfoRecordProto* record = static_cast<UserInfoRecordProto*>(generateUserInfoRecordProto());
        std::string msg;
        record->SerializeToString(&msg);
        size_t ret = fwrite(msg.c_str(), 1, msg.size(), fp);
        CCASSERT(ret != 0, "fwrite function returned zero value");
        fclose(fp);
        delete record;
        if (ret != 0)
        {
            log("Writing file to writable path succeed.");
            return false;
        }
        return true;
    }
    
    return false;
}


void* UserInfo::generateUserInfoRecordProto()
{
    UserInfoRecordProto* record = new UserInfoRecordProto();
    record->set_userid(mUserID);
    record->set_username(mUserName);
    record->set_currentfighterid(mCurrentFighterSID);
    
    UnitList::iterator it = mAllUnitList.begin();
    for (; it != mAllUnitList.end(); ++it)
    {
        BaseAttrProto* attr = record->add_unitattr();
        BaseData* data = (*it)->getBaseData();
        BaseDataHelper::saveData2AttrProto(data, attr);
    }
    return record;
}

/////////////////////////////////////////////////////////////////////////////

void UserInfo::addNewUnitAsData(BaseData *data)
{
    BaseUnit* unit = UnitFactory::createUnit(data);
    //生成SID
    int id = IDManager::GetInstance()->registerBaseUnit(unit);
    log("!!!!! new fighter sid = %d", id);
    addUnit(unit);
}

void UserInfo::addUnit(BaseUnit *unit)
{
    if (unit)
    {
        BaseData* data = unit->getBaseData();
        mAllUnitMap.insert(std::make_pair(data->getSID(), unit));
        mAllUnitList.push_back(unit);
        CC_SAFE_RETAIN(unit);
    }
}

BaseUnit* UserInfo::getUnit(int sid)
{
    return mAllUnitMap.find(sid)->second;
}

void UserInfo::removeUnit(int sid)
{
    BaseUnit* unit = mAllUnitMap.find(sid)->second;
    if (unit)
    {
        mAllUnitMap.erase(sid);
        UnitList::iterator it = mAllUnitList.begin();
        for (; it != mAllUnitList.end(); ++it)
        {
            if ((*it)->getBaseData()->getSID() == sid)
            {
                mAllUnitList.erase(it);
            }
        }
        
        CC_SAFE_RELEASE(unit);
    }
}

void UserInfo::dump()
{
    log("UseInfo[id=%d, name=%s, fighter=%d, unitCount=%d]", mUserID, mUserName.c_str(), mCurrentFighterSID, mAllUnitList.size());
}



