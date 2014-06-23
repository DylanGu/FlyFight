//
//  BattleBgLayer.h
//  flyfight_branch
//
//  Created by snowcold on 22/6/14.
//
//

#ifndef __flyfight_branch__BattleBgLayer__
#define __flyfight_branch__BattleBgLayer__

#include "cocos2d.h"

class DecorationObj;
class RepeatScrollObj;

//--滚动地图,双层叠加式样最低高度1136
class BattleBgLayer : public cocos2d::ParallaxNode
{
    
public:
    
    static  BattleBgLayer* create();
    
    BattleBgLayer();
    ~BattleBgLayer();
    
    void update(float dt);
    
protected:
    
    bool            init();
    const char*     getRandomDecPath();
    int             getBgLayerCount();
    
private:
    
    float               mSpeedY;
    float               mCurrentY;
    
    int                 mThemeID;
    
    typedef std::list<DecorationObj*>   DecorationList;
    typedef std::list<RepeatScrollObj*> RepeatBgList;
    DecorationList      mDecorationList;
    RepeatBgList        mRepeatBgList;
};

#endif /* defined(__flyfight_branch__BattleBgLayer__) */
