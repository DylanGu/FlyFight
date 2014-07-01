//
//  BattleScene.cpp
//  flyfight_branch
//
//  Created by snowcold on 21/6/14.
//
//

#include "BattleScene.h"
#include "engine/script/lua_tinker_manager.h"
#include "game/scene/layer/BattleBgLayer.h"
#include "game/module/BaseFighter.h"

USING_NS_CC;
using namespace std;
using namespace std::placeholders;

BattleScene* BattleScene::create(std::string& name)
{
    BattleScene* pRet = new BattleScene(name);
    if (pRet && pRet->init())
    {
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return NULL;
}

BattleScene::BattleScene(std::string& name) : BaseScene(name),
    mBgLayer(NULL),
    mOwnFighter(NULL)
{
    
}

BattleScene::~BattleScene()
{
    CC_SAFE_RELEASE(mBgLayer);
    mBgLayer = NULL;
    
    CC_SAFE_RELEASE(mOwnFighter);
    mOwnFighter = NULL;
}

////////////////////////////////////////////////////////////////////////////////////
bool BattleScene::init()
{
    //1.Load bg Layer
    mBgLayer = BattleBgLayer::create();
    mBgLayer->retain();
    addChild(mBgLayer);
    
    auto listener = EventListenerTouchOneByOne::create();
    //bind 到 非静态成员函数
    listener->onTouchBegan = std::bind(&BattleScene::onTouchBegan,this, _1, _2);
    listener->onTouchEnded = std::bind(&BattleScene::onTouchEnded, this, _1, _2);
    listener->onTouchMoved = std::bind(&BattleScene::onTouchMoved, this, _1, _2);
    listener->setSwallowTouches(false);
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    initSelfFighter();
    
    return true;
}

bool BattleScene::initSelfFighter()
{
    /*
    mFighter = Sprite::create("res/module/fighter/f_1001.png");
    mFighter->retain();
    addChild(mFighter);
    mFighter->setPosition(320, 120);
    */
}

////////////////////////////////////////////////////////////////////////////////////


bool BattleScene::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    auto target = static_cast<Node*>(event->getCurrentTarget());
    
    mPreTouchPoi = target->convertToNodeSpace(touch->getLocation());
    
    //log("Position[%f, %f]", p.x, p.y);
    
    return true;
}


void BattleScene::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
{
    auto target = static_cast<Node*>(event->getCurrentTarget());
    
    const Point& p = target->convertToNodeSpace(touch->getLocation());
    const Point& offset = p - mPreTouchPoi;
    mPreTouchPoi = p;
    //const Point& cP = mFighter->getPosition();
    //mFighter->setPosition(cP + offset);
}

void BattleScene::onTouchEnded(cocos2d::Touch *, cocos2d::Event *)
{

}

void BattleScene::onTouchCancelled(cocos2d::Touch *, cocos2d::Event *)
{
    
}





