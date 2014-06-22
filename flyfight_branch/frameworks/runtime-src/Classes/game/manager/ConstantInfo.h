//
//  ConstantInfo.h
//  flyfight_branch
//
//  Created by snowcold on 21/6/14.
//
//

#ifndef __flyfight_branch__ConstantInfo__
#define __flyfight_branch__ConstantInfo__

#include "cocos2d.h"

class ConstantInfo : public cocos2d::Ref
{
    
public:
    
    static void INIT();
    
    static cocos2d::Size    _DesignResolutionSize;
    static ResolutionPolicy _DesignResolutionPolicy;
    
private:

};

#endif /* defined(__flyfight_branch__ConstantInfo__) */
