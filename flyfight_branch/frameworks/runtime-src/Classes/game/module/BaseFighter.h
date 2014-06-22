//
//  BaseFighter.h
//  flyfight_branch
//
//  Created by snowcold on 21/6/14.
//
//

#ifndef __flyfight_branch__BaseFighter__
#define __flyfight_branch__BaseFighter__

#include "cocos2d.h"

//1.mID, 2.sID
class BaseFighter : public cocos2d::Ref
{
    
public:
    
    static BaseFighter* create(int id_);
    
    bool init(int id_);
    
    BaseFighter();
    ~BaseFighter();
    
    virtual void addModule(int id_);
    
protected:
    
    cocos2d::Node*  mRenderNode;//主体节点
    int mID;

};

#endif /* defined(__flyfight_branch__BaseFighter__) */
