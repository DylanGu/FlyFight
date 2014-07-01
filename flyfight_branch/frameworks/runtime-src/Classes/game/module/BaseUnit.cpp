//
//  BaseUnit.cpp
//  flyfight_branch
//
//  Created by snowcold on 21/6/14.
//
//

#include "BaseUnit.h"

using namespace cocos2d;

/*
BaseUnit* BaseUnit::create()
{
    BaseUnit* pRet = new BaseUnit();
    if (pRet && pRet->initWithEID())
    {
        pRet->autorelease();
        return pRet;
    }
    
    delete pRet;
    return NULL;
}
*/

BaseUnit::BaseUnit() : mRenderNode(NULL), mBaseData(NULL)
{
    
}

BaseUnit::~BaseUnit()
{
    CC_SAFE_RELEASE(mRenderNode);
    mRenderNode = NULL;
    
    CC_SAFE_RELEASE(mBaseData);
    mBaseData = NULL;
}

bool BaseUnit::init()
{
    return true;
}


void BaseUnit::addModule()
{
    log("NOT SUPPORT ADD MODULE");
}

void BaseUnit::rebuildAsData()
{
    
}

void BaseUnit::setBaseData(BaseData *data)
{
    CC_SAFE_RELEASE(mBaseData);
    
    mBaseData = data;
    
    CC_SAFE_RETAIN(mBaseData);
}



