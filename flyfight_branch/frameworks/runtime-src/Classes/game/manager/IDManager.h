//
//  IDManager.h
//  flyfight_branch
//
//  Created by coldouyang on 14-6-26.
//
//

#ifndef __flyfight_branch__IDManager__
#define __flyfight_branch__IDManager__

#include <iostream>
#include "cocos2d.h"

class IDManager : public cocos2d::Ref
{
    
public:
    
    static IDManager* GetInstance();
    
};

#endif /* defined(__flyfight_branch__IDManager__) */
