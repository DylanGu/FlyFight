//
//  BaseScene.h
//  flyfight_branch
//
//  Created by snowcold on 21/6/14.
//
//

#ifndef __flyfight_branch__BaseScene__
#define __flyfight_branch__BaseScene__

#include "cocos2d.h"

class BaseScene :public cocos2d::Scene
{
    
public:
    
    BaseScene(std::string& name);
    
protected:
    
    std::string mSceneName;
};

#endif /* defined(__flyfight_branch__BaseScene__) */
