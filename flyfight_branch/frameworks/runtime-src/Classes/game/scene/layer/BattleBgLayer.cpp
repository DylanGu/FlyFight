//
//  BattleBgLayer.cpp
//  flyfight_branch
//
//  Created by snowcold on 22/6/14.
//
//

#include "game/scene/layer/BattleBgLayer.h"
#include "game/scene/ui/DecorationObj.h"
#include "game/scene/ui/RepeatScrollObj.h"
#include "engine/script/lua_tinker_manager.h"
#include "engine/util/Helper.h"

using namespace cocos2d;
using namespace std;

#define RES_LUA             "src/config/battle_res_control.lua"
#define FUNC_GET_BG_LAYER_COUNT   "GetThemeBgLayerCount"
#define FUNC_GET_DEC_PATH   "GetDecorationPathForTheme"

BattleBgLayer* BattleBgLayer::create()
{
    BattleBgLayer* pRet = new BattleBgLayer();
    if (pRet && pRet->init())
    {
        pRet->autorelease();
        return pRet;
    }
    
    CC_SAFE_DELETE(pRet);
    return NULL;
}

BattleBgLayer::BattleBgLayer()
{
    mSpeedY = -150;
    mThemeID = 1;
}

BattleBgLayer::~BattleBgLayer()
{
    release_Std_List<DecorationList, DecorationList::iterator>(mDecorationList);
    release_Std_List<RepeatBgList, RepeatBgList::iterator>(mRepeatBgList);
    Director::getInstance()->getScheduler()->unscheduleUpdate(this);
}

bool BattleBgLayer::init()
{
    int layer_count = getBgLayerCount();
    for (int i = 1; i <= layer_count; ++i)
    {
        RepeatScrollObj* obj = new RepeatScrollObj();
        obj->initWithContainerAndPoi(this, mThemeID, i);
        mRepeatBgList.push_back(obj);
    }
    
    const char* path = getRandomDecPath();
    if (path)
    {
        //add decoration;
        for (int i = 0; i < 20; ++i)
        {
            path = getRandomDecPath();
            float x = CCRANDOM_0_1() * 500;
            float y = i * 350;
            DecorationObj* obj = new DecorationObj(i);
            obj->initWithContainerAndPoi(this, path, x, y);
            mDecorationList.push_back(obj);
        }
    }
    Director::getInstance()->getScheduler()->scheduleUpdate(this, 1, false);
    return true;
}

const char* BattleBgLayer::getRandomDecPath()
{
    const char* path = LuaTinkerManager::GetInstance().CallLuaFunc<const char*>(RES_LUA, FUNC_GET_DEC_PATH, mThemeID);
    return path;
}

int BattleBgLayer::getBgLayerCount()
{
    return LuaTinkerManager::GetInstance().CallLuaFunc<int>(RES_LUA, FUNC_GET_BG_LAYER_COUNT, mThemeID);
}

void BattleBgLayer::update(float dt)
{
    float offset = mSpeedY * dt;
    mCurrentY = getPositionY() + offset;
    setPositionY(mCurrentY);
    
    if (mRepeatBgList.size() > 0)
    {
        RepeatBgList::iterator it = mRepeatBgList.begin();
        for (; it != mRepeatBgList.end(); ++it)
        {
            (*it)->updatePosition(mCurrentY);
        }
    }
    
    if (mDecorationList.size() > 0)
    {
        DecorationList::iterator it = mDecorationList.begin();
        for (; it != mDecorationList.end(); )
        {
            auto obj = *it;
            if (!obj->updatePosition(mCurrentY))
            {
                delete obj;
                mDecorationList.erase(it++);
            }
            else
            {
                ++it;
            }
        }
    }
}
