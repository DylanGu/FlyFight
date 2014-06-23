//
//  ConstantInfo.cpp
//  flyfight_branch
//
//  Created by snowcold on 21/6/14.
//
//

#include "ConstantInfo.h"

using namespace cocos2d;

#define DESIGN_RESOLTION_WIDTH  640
#define DESIGN_RESOLTION_HEIGHT 960

ResolutionPolicy ConstantInfo::_DesignResolutionPolicy = ResolutionPolicy::EXACT_FIT;
Size ConstantInfo::_DesignResolutionSize = Size::ZERO;

void ConstantInfo::INIT()
{
    _DesignResolutionSize.setSize(DESIGN_RESOLTION_WIDTH, DESIGN_RESOLTION_HEIGHT);
    
    _DesignResolutionPolicy = ResolutionPolicy::EXACT_FIT;
}
