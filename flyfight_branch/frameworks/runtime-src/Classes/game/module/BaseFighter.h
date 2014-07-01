//
//  BaseFighter.h
//  flyfight_branch
//
//  Created by snowcold on 29/6/14.
//
//

#ifndef __flyfight_branch__BaseFighter__
#define __flyfight_branch__BaseFighter__

#include "game/module/BaseUnit.h"

//-基础战机，
class BaseFighter : public BaseUnit
{
private:
    
    static const ePart    _PART_TYPE_ = kPart_Fighter;
    
public:

    static BaseFighter*     create();
    
    virtual bool init();
    
public:
    
    void    setEffectiveRect(cocos2d::Rect& r);
    const cocos2d::Rect&    getEffectiveRect() { return mEffectiveRect; };
    
    void    addOffsetPoi(const cocos2d::Point& offset);
    
protected:
    
    BaseFighter();

    virtual ~BaseFighter();
    
private:
    
    cocos2d::Rect       mEffectiveRect;//活动范围
};















#endif /* defined(__flyfight_branch__BaseFighter__) */
