//
//  BaseFighter.cpp
//  flyfight_branch
//
//  Created by snowcold on 29/6/14.
//
//

#include "BaseFighter.h"

USING_NS_CC;

//ePart BaseFighter::_PART_TYPE_ = kPart_Fighter;

BaseFighter* BaseFighter::create()
{
    BaseFighter* pRet = new BaseFighter();
    if (pRet && pRet->init())
    {
        pRet->autorelease();
        return pRet;
    }
    
    delete pRet;
    return NULL;
}

BaseFighter::BaseFighter()
{
    
}

BaseFighter::~BaseFighter()
{
}

bool BaseFighter::init()
{
    BaseUnit::init();
    return true;
}

void BaseFighter::setEffectiveRect(cocos2d::Rect &r)
{
    mEffectiveRect = r;
}

void BaseFighter::addOffsetPoi(const Point &offset)
{
    if (mRenderNode)
    {
        const Point preP = mRenderNode->getPosition();
        Point current = preP + offset;
        if (current.x < mEffectiveRect.getMinX())
        {
            current.x = mEffectiveRect.getMinX();
        }
        else if (current.x >mEffectiveRect.getMaxX())
        {
            current.x = mEffectiveRect.getMaxX();
        }
        
        if (current.y < mEffectiveRect.getMinY())
        {
            current.y = mEffectiveRect.getMinY();
        }
        else if (current.y > mEffectiveRect.getMaxY())
        {
            current.y = mEffectiveRect.getMaxY();
        }
        
        mRenderNode->setPosition(current);
    }
}





