//
//  DecorationObj.cpp
//  flyfight_branch
//
//  Created by snowcold on 22/6/14.
//
//

#include "game/scene/ui/DecorationObj.h"
#include "engine/script/lua_tinker_manager.h"
#include "engine/util/Helper.h"

using namespace cocos2d;

DecorationObj::DecorationObj(int mID) : mRenderNode(NULL)
{
    
}

DecorationObj::~DecorationObj()
{
    CC_SAFE_RELEASE(mRenderNode);
    mRenderNode = NULL;
}

void DecorationObj::initWithContainerAndPoi(cocos2d::ParallaxNode *container, const char* path, cocos2d::Point &poi)
{
    initWithContainerAndPoi(container, path, poi.x, poi.y);
}

void DecorationObj::initWithContainerAndPoi(cocos2d::ParallaxNode *container, const char* path, float x, float y)
{
    mDecPath = path;
    if (is_CCBI_File(mDecPath))
    {
        
    }
    else    //png
    {
        if (!mRenderNode)
        {
            mRenderNode = Sprite::create(path);
            mRenderNode->retain();
        }
        else
        {
            mRenderNode->removeFromParentAndCleanup(true);
        }
    }
    
    mSpeedRadio = CCRANDOM_0_1() + 1;
    container->addChild(mRenderNode, 1, Vec2(1, mSpeedRadio), Vec2(x, y));
    mRenderNode->setLocalZOrder(100);
    mRenderNode->setPosition(x, y);
    mTopY = (mRenderNode->getContentSize().height * 0.5f + y) / mSpeedRadio;
}

bool DecorationObj::updatePosition(float parentY)
{
    if ((mTopY + parentY) < 0)
    {
        mRenderNode->removeFromParentAndCleanup(true);
        return false;
    }
    return true;
}


