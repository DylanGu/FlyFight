//
//  DataManager.h
//  flyfight_branch
//
//  Created by coldouyang on 14-6-17.
//
//

#ifndef __flyfight_branch__DataManager__
#define __flyfight_branch__DataManager__

#include <iostream>
#include "cocos2d.h"

class DataManager
{
    
public:
    
    static DataManager& GetInstance();
    
    DataManager();
    
protected:
    
    bool init();
    
};

#endif /* defined(__flyfight_branch__DataManager__) */
