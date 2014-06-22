//
//  RepectScrollLaayer.cpp
//  flyfight_branch
//
//  Created by snowcold on 22/6/14.
//
//

#include "game/scene/ui/RepeatScrollObj.h"
#include "game/scene/ui/DecorationObj.h"
#include "engine/script/lua_tinker_manager.h"
#include "engine/util/Helper.h"

USING_NS_CC;

#define RES_LUA             "src/config/battle_res_control.lua"
#define FUNC_GET_BG_INDEX   "GetBattleBgIndexForTheme"
#define FUNC_GET_BG_PATH    "GetBattleBgPathByIndex"

#define FUNC_GET_LAYER_SPEED   "GetLayerSpeedForTheme"

RepeatScrollObj::RepeatScrollObj() : mBgSprite1(NULL), mBgSprite2(NULL), mContainer(NULL)
{
    
}

RepeatScrollObj::~RepeatScrollObj()
{
    mBgSprite1 = NULL;
    CC_SAFE_RELEASE(mBgSprite1);
    
    mBgSprite2 = NULL;
    CC_SAFE_RELEASE(mBgSprite2);
}

void RepeatScrollObj::initWithContainerAndPoi(cocos2d::ParallaxNode *container, int themeID, int layerIndex)
{
    mContainer = container;
    mThemeID = themeID;
    mBgIndex = 0;
    mLayerIndex = layerIndex;
    mSpeedRadio = getLayerSpeedRadio();
    mNextSpriteY = 0;
    mNextSwapY = 0;
    
    mBgSprite1 = Sprite::create(getNextBgPath());
    mBgSprite1->retain();
    mBgSprite1->setAnchorPoint(Point::ZERO);
    mContainer->addChild(mBgSprite1, -10, Vec2(1, mSpeedRadio), Vec2(0, mNextSpriteY));
    mNextSpriteY = mBgSprite1->getContentSize().height;
    
    mBgSprite2 = Sprite::create(getNextBgPath());
    mBgSprite2->setFlippedY(true);
    mBgSprite2->retain();
    mBgSprite2->setAnchorPoint(Point::ZERO);
    mContainer->addChild(mBgSprite2, -10, Vec2(1, mSpeedRadio), Vec2(0, mNextSpriteY));
    mNextSpriteY += mBgSprite2->getContentSize().height;
    
    mNextSwapY = mBgSprite1->getContentSize().height + mBgSprite1->getPositionY();
    mNextSwapY = mNextSwapY / mSpeedRadio;
}

bool RepeatScrollObj::updatePosition(float parentY)
{
    //parentY = parentY * mSpeedRadio;
    if ((parentY + mNextSwapY) <= 0)
    {
        mNextSwapY = mNextSpriteY / mSpeedRadio;
        
        mBgSprite1->removeFromParentAndCleanup(false);
        
        mBgSprite1->setTexture(getNextBgPath());
        mBgSprite1->setAnchorPoint(Point::ZERO);

        mBgSprite1->setPosition(Point::ZERO);
        mContainer->addChild(mBgSprite1, -10, Vec2(1, mSpeedRadio), Vec2(0, mNextSpriteY));
        mNextSpriteY += mBgSprite1->getContentSize().height;

        Sprite* temp = mBgSprite1;
        mBgSprite1 = mBgSprite2;
        mBgSprite2 = temp;
    }
    
    return true;
}

///////////////
const char* RepeatScrollObj::getNextBgPath()
{
    mBgIndex = LuaTinkerManager::GetInstance().CallLuaFunc<int>(RES_LUA, FUNC_GET_BG_INDEX, mThemeID, mLayerIndex, mBgIndex);
    const char* path = LuaTinkerManager::GetInstance().CallLuaFunc<const char*>(RES_LUA, FUNC_GET_BG_PATH, mThemeID, mLayerIndex, mBgIndex);
    return path;
}

float RepeatScrollObj::getLayerSpeedRadio()
{
    return LuaTinkerManager::GetInstance().CallLuaFunc<float>(RES_LUA, FUNC_GET_LAYER_SPEED, mThemeID, mLayerIndex);
}


