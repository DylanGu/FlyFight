//
//  DataManager.h
//  flyfight_branch
//
//  Created by coldouyang on 14-6-17.
//
//

#ifndef __flyfight_branch__DataManager__
#define __flyfight_branch__DataManager__

#include <iostream>
#include "cocos2d.h"
#include "game/manager/UserInfo.h"
#include "game/manager/IDManager.h"

class AbilityDataTable;

class DataManager : public cocos2d::Ref
{
    
public:
    
    static DataManager* GetInstance();

    ~DataManager();
    
    UserInfo* getCurrentUserInfo() { return mCurrentUserInfo; };
    void changerUser(int userID);
    
    BaseData*   getBaseData(int eID);
    
    void    registerBaseData(BaseData* data);
    
protected:
    
    DataManager();
    
    bool init();
    
private:
    
    typedef std::map<int, BaseData*> DataMap;
    
    DataMap     mDataMap;
    
    AbilityDataTable* mAbilityDataTable_;
    IDManager*  mIDManager;
    UserInfo*   mCurrentUserInfo;
    int     mCurrentUserID;//0,默认
};

#endif /* defined(__flyfight_branch__DataManager__) */
