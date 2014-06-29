//
//  UserInfo.h
//  flyfight_branch
//
//  Created by snowcold on 29/6/14.
//
//

#ifndef __flyfight_branch__UserInfo__
#define __flyfight_branch__UserInfo__

#include <iostream>
#include "cocos2d.h"
#include "game/module/BaseUnit.h"

class UserInfo : public cocos2d::Ref
{
    
public:
    
    static UserInfo* create();
    
    void initUserInfoFromDB(int userID);//读取数据
    
    void initUserInfoFromProtobuf(int userID);//从本地数据读取,protobuf序列化格式
    
    bool saveUserInfoToClien();
    
    void dump();
public:
    
    void addNewUnitAsData(BaseData* data);
    void addUnit(BaseUnit* unit);
    void removeUnit(int sid);
    BaseUnit* getUnit(int sid);
    
protected:
    
    UserInfo();
    
    ~UserInfo();
    
    void* generateUserInfoRecordProto();
    
protected:
    
    int     mCurrentFighterSID;//当前使用的战机
    
    typedef std::map<int, BaseUnit*> UnitMap; //SID,BaseUnit
    typedef std::list<BaseUnit*> UnitList;
    
    UnitMap     mAllUnitMap;
    UnitList    mAllUnitList;
    
    int         mUserID;
    std::string mUserName;
};

#endif /* defined(__flyfight_branch__UserInfo__) */
