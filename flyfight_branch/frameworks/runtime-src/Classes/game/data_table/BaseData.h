//
//  BaseData.h
//  flyfight_branch
//
//  Created by snowcold on 28/6/14.
//
//

#ifndef __flyfight_branch__BaseData__
#define __flyfight_branch__BaseData__

#include <iostream>
#include "cocos2d.h"
//#include "game/data_table/pb/BaseAttr.pb.h"
//--基础数据模板

enum ePart
{
    kPart_Null = 0,
    kPart_Fighter = 1,//战机
    kPart_Armor = 2,//装甲
    kPart_Wingman = 3,//僚机
    kPart_Attache = 4,//附武器
};

enum eQuality
{
    kQuality_Gray = 0,
    kQuality_White = 1,
    kQuality_Green= 2,
    kQuality_Blue = 3,
    kQuality_Purple = 4,
    kQuality_Orange = 5,
};

enum eQualityRank
{
    kQuaRank_0 = 0,
    kQuaRank_1 = 1,
    kQuaRank_2 = 2,
    kQuaRank_Max = 3,
    kQuaRank_Gold = 4,
};

class BaseDataHelper;

class BaseData : public cocos2d::Ref
{
    
public:
    
    static BaseData* create();
    
    void    setSID(int sid) { _sID = sid; }
    void    setEID(int eid) { _eID = eid; }
    void    setPart(int part) { _part = part; }
    void    setLevel(int level) { _level = level; }
    void    setQuality(int quality) { _quality = quality; }
    void    setQualityRank(int qR) { _qualityRank = qR; }
    void    setHp(int hp) { _hp = hp; }
    void    setDefence(int defence) { _defence = defence; }
    void    setAtk(int atk) { _atk = atk; }
    void    setAtkSpeed(int atkSpeed) { _atkSpeed = atkSpeed; }
    
    inline int     getSID() { return _sID; }
    inline int     getEID() { return _eID; }
    inline int     getPart() { return _part; }
    inline int     getLevel() { return _level; }
    inline int     getQuality() { return _quality; }
    inline int     getQualityRank() { return _qualityRank; }
    inline int     getHp() { return _hp; }
    inline int     getDefence() { return _defence; }
    inline int     getAtk() { return _atk; }
    inline int     getAtkSpeed() { return _atkSpeed; }
    
protected:
    BaseData();
    
private:
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
    int             _sID;
    int             _eID;
    int             _part;
    int             _level;
    int             _quality;
    int             _qualityRank;
    
    int             _hp;
    int             _defence;
    int             _atk;
    int             _atkSpeed;
    
    friend class BaseDataHelper;
};

class BaseDataHelper
{
public:
    
    static  void*   createAttrProtoAsData(const BaseData* data);
    static  void    saveData2AttrProto(const BaseData* data, void* attr);
    static BaseData* createDataAsAttrProto(const void* attr);
};

#endif /* defined(__flyfight_branch__BaseData__) */
