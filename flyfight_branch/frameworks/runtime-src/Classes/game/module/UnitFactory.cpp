//
//  UnitFactory.cpp
//  flyfight_branch
//
//  Created by snowcold on 29/6/14.
//
//

#include "UnitFactory.h"
#include "cocos2d.h"
#include "game/module/BaseFighter.h"

USING_NS_CC;

UnitFactory::NullCreaterMap UnitFactory::_creater_map;
bool UnitFactory::_has_init = false;

void UnitFactory::RegisterAll()
{
    RegisterCreater(ePart::kPart_Fighter, BaseFighter::create);
}

void UnitFactory::RegisterCreater(int type, FuncBaseUnitCreater callBack)
{
    _creater_map.insert(make_pair(type, callBack));
}

BaseUnit* UnitFactory::createUnit(BaseData* data)
{
    if (!_has_init)
    {
        RegisterAll();
        _has_init = true;
    }
    
    NullCreaterMap::iterator it = _creater_map.find(data->getPart());
    if (it != _creater_map.end())
    {
        FuncBaseUnitCreater call = it->second;
        BaseUnit* unit = call();
        if (data)
        {
            unit->setBaseData(data);
        }
        return unit;
    }
    log("ERROR Create CallBack not find type = %d", data->getPart());
    return NULL;
}
