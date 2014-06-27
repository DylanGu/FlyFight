//
//  BaseFighter.cpp
//  flyfight_branch
//
//  Created by snowcold on 21/6/14.
//
//

#include "BasePart.h"

using namespace cocos2d;

BasePart* BasePart::create(int id_)
{
    BasePart* pRet = new BasePart();
    if (pRet && pRet->init(id_))
    {
        pRet->autorelease();
        return pRet;
    }
    
    delete pRet;
    return NULL;
}

BasePart::BasePart() : mRenderNode(NULL)
{
    
}

BasePart::~BasePart()
{
    CC_SAFE_RELEASE(mRenderNode);
    mRenderNode = NULL;
}

bool BasePart::init(int id_)
{
    mID = id_;
    return true;
}


void BasePart::addModule(int id_)
{
    
}
