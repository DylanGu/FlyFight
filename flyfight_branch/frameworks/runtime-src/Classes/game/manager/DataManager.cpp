//
//  DataManager.cpp
//  flyfight_branch
//
//  Created by coldouyang on 14-6-17.
//
//

#include "DataManager.h"
#include "ability_data_table.h"

using namespace cocos2d;
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
    static DataManager M;
    return &M;
}

DataManager::DataManager() : mAbilityDataTable_(NULL)
{
    init();
}

bool DataManager::init()
{
    RegisterAsyncLoadHandle<AbilityDataTable>(&mAbilityDataTable_, "test.csv");
    
    return true;
}

int DataManager::getTestVersion()
{
    return 1001;
}




