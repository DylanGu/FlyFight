//
//  BattleScene.h
//  flyfight_branch
//
//  Created by snowcold on 21/6/14.
//
//

#ifndef __flyfight_branch__BattleScene__
#define __flyfight_branch__BattleScene__

#include "game/scene/BaseScene.h"

static std::string BATTLE_SCENE_NAME    =   "battle_scene";

class BattleBgLayer;

class BattleScene : public BaseScene
{
    
public:
    
    static BattleScene* create(std::string& name = BATTLE_SCENE_NAME);
    
protected:
    
    bool    init();
    
    BattleScene(std::string& name);
    
    ~BattleScene();
    
    bool    onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
    void    onTouchMoved(cocos2d::Touch*, cocos2d::Event*);
    void    onTouchEnded(cocos2d::Touch*, cocos2d::Event*);
    void    onTouchCancelled(cocos2d::Touch*, cocos2d::Event*);
    
private:
    
    cocos2d::Point  mPreTouchPoi;
    
    cocos2d::Sprite*    mFighter;
    BattleBgLayer*  mBgLayer;
};


#endif /* defined(__flyfight_branch__BattleScene__) */
