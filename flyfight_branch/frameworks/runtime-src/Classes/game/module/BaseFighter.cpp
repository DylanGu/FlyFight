//
//  BaseFighter.cpp
//  flyfight_branch
//
//  Created by snowcold on 21/6/14.
//
//

#include "BaseFighter.h"

using namespace cocos2d;

BaseFighter* BaseFighter::create(int id_)
{
    BaseFighter* pRet = new BaseFighter();
    if (pRet && pRet->init(id_))
    {
        pRet->autorelease();
        return pRet;
    }
    
    delete pRet;
    return NULL;
}

BaseFighter::BaseFighter() : mRenderNode(NULL)
{
    
}

BaseFighter::~BaseFighter()
{
    CC_SAFE_RELEASE(mRenderNode);
    mRenderNode = NULL;
}

bool BaseFighter::init(int id_)
{
    mID = id_;
    return true;
}


void BaseFighter::addModule(int id_)
{
    
}
