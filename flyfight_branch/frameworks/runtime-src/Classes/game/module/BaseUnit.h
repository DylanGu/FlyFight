//
//  BaseUnit.h
//  flyfight_branch
//
//  Created by snowcold on 21/6/14.
//
//

#ifndef __flyfight_branch__BaseUnit__
#define __flyfight_branch__BaseUnit__

#include "cocos2d.h"

#include "game/data_table/BaseData.h"
//1.mID, 2.sID
class BaseUnit : public cocos2d::Ref
{
    
public:
    
    //static BaseUnit*    create();
    
    virtual bool    init();
    
    BaseUnit();
    
    virtual ~BaseUnit();
    
    virtual void    addModule();

public:

    /*
    int     getEID() { return mBaseData->getEID(); }
    int     getSID() { return mBaseData->getSID(); }
    */
    
    BaseData* getBaseData() { return mBaseData; }
    void    setBaseData(BaseData* data);
    
    virtual void    rebuildAsData();

protected:
    
    cocos2d::Node*      mRenderNode;//主体节点
    
    BaseData*           mBaseData;
};

#endif /* defined(__flyfight_branch__BaseFighter__) */
