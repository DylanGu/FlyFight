//
//  RepectScrollLaayer.h
//  flyfight_branch
//
//  Created by snowcold on 22/6/14.
//
//

#ifndef __flyfight_branch__RepectScrollLaayer__
#define __flyfight_branch__RepectScrollLaayer__

#include "cocos2d.h"

class DecorationObj;

class RepeatScrollObj : public cocos2d::Ref
{
    
public:
    RepeatScrollObj();
    ~RepeatScrollObj();
    
    //主题背景，层级
    void initWithContainerAndPoi(cocos2d::ParallaxNode* container,int themeID, int layerIndex);
    
    bool updatePosition(float parentY);
    
    const char*     getNextBgPath();
    float           getLayerSpeedRadio();
    
private:
    
    cocos2d::Sprite*    mBgSprite1;
    cocos2d::Sprite*    mBgSprite2;
    
    cocos2d::ParallaxNode*  mContainer;
    
    float               mNextSwapY;
    float               mNextSpriteY;
    
    int                 mThemeID;
    int                 mBgIndex;
    int                 mLayerIndex;//todo
    float               mSpeedRadio;
};

#endif /* defined(__flyfight_branch__RepectScrollLaayer__) */
