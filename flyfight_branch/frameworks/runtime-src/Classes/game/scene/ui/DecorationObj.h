//
//  DecorationObj.h
//  flyfight_branch
//
//  Created by snowcold on 22/6/14.
//
//

#ifndef __flyfight_branch__DecorationObj__
#define __flyfight_branch__DecorationObj__

#include "cocos2d.h"

class DecorationObj : public cocos2d::Ref
{
public:
    DecorationObj(int mID);
    ~DecorationObj();
    
    void initWithContainerAndPoi(cocos2d::ParallaxNode* container,const char* path, cocos2d::Point& poi);
    void initWithContainerAndPoi(cocos2d::ParallaxNode* container,const char* path, float x, float y);
    
    bool updatePosition(float parentY);
    
private:
    
    cocos2d::Node*      mRenderNode;
    float               mSpeedRadio;
    float               mTopY;

    std::string         mDecPath;
};

#endif /* defined(__flyfight_branch__DecorationObj__) */
