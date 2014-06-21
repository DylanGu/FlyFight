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

class AbilityDataTable;

class DataManager : public cocos2d::Ref
{
    
public:
    
    static DataManager* GetInstance();
    
    DataManager();
    
    int getTestVersion();
    
protected:
    
    bool init();
    
private:
    
    AbilityDataTable* mAbilityDataTable_;

};

#endif /* defined(__flyfight_branch__DataManager__) */
