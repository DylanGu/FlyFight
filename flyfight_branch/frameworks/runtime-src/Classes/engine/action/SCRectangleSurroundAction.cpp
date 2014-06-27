//
//  SCRectangleSurroundAction.cpp
//  PetBubble
//
//  Created by snowcold on 14-1-8.
//
//

#include "SCRectangleSurroundAction.h"

USING_NS_CC;

CCActionInterval* SCRectangleSurroundAction::create(const cocos2d::CCPoint& p0, const cocos2d::CCPoint& p1, float radium, bool is_clockwise)
{
    
    CCPoint p01 = ccp(p0.x + radium, p1.y);
    CCMoveTo* set = CCMoveTo::create(0.001f, p01);
    
    CCPoint p20 = ccp(p1.x - radium, p1.y);
    CCMoveTo* line1 = CCMoveTo::create(0.7f, p20);
    
    CCPoint p21 = ccp(p1.x, p1.y - radium);
    //R.
    CCBezierTo* r2 = createBezierTo(p21, p1);
    
    CCPoint p30 = ccp(p1.x, p0.y + radium);
    CCMoveTo* line2 = CCMoveTo::create(0.7f, p30);
    
    CCPoint p31 = ccp(p1.x - radium, p0.y);
    //R.
    CCBezierTo* r3 = createBezierTo(p31, ccp(p1.x, p0.y));
    
    CCPoint p10 = ccp(p0.x + radium, p0.y);
    CCMoveTo* line3 = CCMoveTo::create(0.7f, p10);
    
    CCPoint p11 = ccp(p0.x, p0.y + radium);
    //R.
    CCBezierTo* r1 = createBezierTo(p11, p0);
    
    CCPoint p00 = ccp(p0.x, p1.y - radium);
    CCMoveTo* line4 = CCMoveTo::create(0.7f, p00);
    
    //R.
    CCBezierTo* r0 = createBezierTo(p01, ccp(p0.x, p1.y));
    
    CCActionInterval* sequence = CCSequence::create(set, line1, r2, line2, r3, line3, r1, line4, r0, NULL);
    
    return sequence;
}

CCBezierTo* SCRectangleSurroundAction::createBezierTo(const cocos2d::CCPoint &end, const cocos2d::CCPoint &control)
{
    ccBezierConfig bezier;
    bezier.controlPoint_1 = control;
    bezier.controlPoint_2 = control;
    bezier.endPosition = end;
    
    CCBezierTo* result = CCBezierTo::create(0.25f, bezier);
    return result;
}













