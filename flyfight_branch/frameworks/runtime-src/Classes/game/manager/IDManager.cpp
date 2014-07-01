//
//  IDManager.cpp
//  flyfight_branch
//
//  Created by coldouyang on 14-6-26.
//
//

#include "IDManager.h"
#include "engine/util/ThreadLock.h"

USING_NS_CC;

static const char* KEY_MAX_SID = "k_max_sid";

IDManager* IDManager::GetInstance()
{
    static IDManager M;
    return &M;
}

IDManager::IDManager()
{
    mMaxSID = UserDefault::getInstance()->getIntegerForKey(KEY_MAX_SID, 10000);
}

IDManager::~IDManager()
{
    UserDefault::getInstance()->setIntegerForKey(KEY_MAX_SID, mMaxSID);
    UserDefault::getInstance()->flush();
}

BaseUnit* IDManager::getBaseUnit(int sID)
{
    UnitMap::iterator it = mUnitMap.find(sID);
    if (it == mUnitMap.end())
    {
        log("IDManager ERROR [BaseUnit Not find id=%d]", sID);
        return NULL;
    }
    return it->second;
}

int IDManager::registerBaseUnit(BaseUnit *unit)
{
    int id = unit->getBaseData()->getSID();
    if (id <= 0)
    {
        id = generateUnitSID();
        unit->getBaseData()->setSID(id);
    }
    mUnitMap.insert(std::make_pair(id, unit));
    return id;
}

int IDManager::generateUnitSID()
{
    ThreadLock(&mSidLock);
    mMaxSID++;
    return mMaxSID;
}








