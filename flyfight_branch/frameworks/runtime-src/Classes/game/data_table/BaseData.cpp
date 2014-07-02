//
//  BaseData.cpp
//  flyfight_branch
//
//  Created by snowcold on 28/6/14.
//
//

#include "BaseData.h"

#include "game/data_table/pb/UserInfoRecordProto.pb.h"

using namespace snowcold;

BaseData* BaseData::create()
{
    BaseData* pRet = new BaseData();
    pRet->autorelease();
    return pRet;
}

BaseData::BaseData() : _sID(-1), _eID(-1), _part(0),
        _level(1), _quality(1), _qualityRank(0), _hp(0), _defence(0),
        _atk(0), _atkSpeed(0)
{
    
}

void* BaseDataHelper::createAttrProtoAsData(const BaseData* data)
{
    BaseAttrProto* attr = new BaseAttrProto();
    attr->set_eid(data->_eID);
    attr->set_part((BaseAttrProto::ePart)data->_part);
    attr->set_level(data->_level);
    attr->set_quality((BaseAttrProto::eQuality)data->_quality);
    attr->set_quarank((BaseAttrProto::eQualityRank)data->_qualityRank);
    attr->set_hp(data->_hp);
    attr->set_defence(data->_defence);
    attr->set_atk(data->_atk);
    attr->set_atkspeed(data->_atkSpeed);
    return attr;
}

void    BaseDataHelper::saveData2AttrProto(const BaseData* data, void* attr_)
{
    BaseAttrProto* attr = (BaseAttrProto*) attr_;
    attr->set_sid(data->_sID);
    attr->set_eid(data->_eID);
    attr->set_part((BaseAttrProto::ePart)data->_part);
    attr->set_level(data->_level);
    attr->set_quality((BaseAttrProto::eQuality)data->_quality);
    attr->set_quarank((BaseAttrProto::eQualityRank)data->_qualityRank);
    attr->set_hp(data->_hp);
    attr->set_defence(data->_defence);
    attr->set_atk(data->_atk);
    attr->set_atkspeed(data->_atkSpeed);
}

/*
 required int32 sid = 1[default = 0];
 required int32 eid = 2[default = 0];
 required ePart part = 3[default = kPart_Null];
 required int32 level = 4[default = 1];
 required eQuality quality = 5[default = kQuality_White];
 required eQualityRank quaRank = 6[default = kQuaRank_0];
 
 optional int32 hp = 7;
 optional int32 defence = 8;
 optional int32 atk = 9;
 optional int32 atkSpeed = 10;
 */

BaseData* BaseDataHelper::createDataAsAttrProto(const void* attr_)
{
    BaseData* data = BaseData::create();
    const BaseAttrProto* attr = (BaseAttrProto*)(attr_);
    
    data->_sID = attr->sid();
    data->_eID = attr->eid();
    data->_part = attr->part();
    data->_level = attr->level();
    data->_quality = attr->quality();
    data->_qualityRank = attr->quarank();
    
    if (attr->has_hp())
    {
        data->_hp = attr->hp();
    }
    
    if (attr->has_defence())
    {
        data->_defence = attr->defence();
    }
    
    if (attr->has_atk())
    {
        data->_atk = attr->atk();
    }
    
    if (attr->has_atkspeed())
    {
        data->_atkSpeed = attr->atkspeed();
    }

    return data;
}







