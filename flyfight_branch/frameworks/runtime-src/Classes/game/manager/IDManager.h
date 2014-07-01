//
//  IDManager.h
//  flyfight_branch
//
//  Created by coldouyang on 14-6-26.
//
//

#ifndef __flyfight_branch__IDManager__
#define __flyfight_branch__IDManager__

#include <iostream>
#include "cocos2d.h"
#include "game/data_table/BaseData.h"
#include "game/module/BaseUnit.h"

//DataManager帮助类
class IDManager : public cocos2d::Ref
{
    
public:
    
    static IDManager*   GetInstance();
    
    int     generateUnitSID();
    
    BaseUnit*   getBaseUnit(int sID);
    
    int     registerBaseUnit(BaseUnit* unit);
    
private:
    
    IDManager();

    ~IDManager();
    
    typedef std::map<int, BaseUnit*> UnitMap;
    
    UnitMap     mUnitMap;
    
    int         mMaxSID;
    
    pthread_mutex_t mSidLock;
};

#endif /* defined(__flyfight_branch__IDManager__) */
