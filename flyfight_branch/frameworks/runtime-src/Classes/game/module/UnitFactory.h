//
//  UnitFactory.h
//  flyfight_branch
//
//  Created by snowcold on 29/6/14.
//
//

#ifndef __flyfight_branch__UnitFactory__
#define __flyfight_branch__UnitFactory__

#include "game/module/BaseUnit.h"
#include "game/data_table/BaseData.h"

typedef std::function<BaseUnit*()> FuncBaseUnitCreater;

class UnitFactory
{
    
public:
    
    static void RegisterAll();
    static void RegisterCreater(int type, FuncBaseUnitCreater callBack);
    static BaseUnit* createUnit(BaseData* data);
    
    typedef std::map<int, FuncBaseUnitCreater>   NullCreaterMap;
    static NullCreaterMap    _creater_map;
    
    static bool _has_init;
};

#endif /* defined(__flyfight_branch__UnitFactory__) */
