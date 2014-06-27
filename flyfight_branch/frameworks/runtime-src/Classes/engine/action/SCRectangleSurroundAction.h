//
//  SCRectangleSurroundAction.h
//  PetBubble
//
//  Created by snowcold on 14-1-8.
//
//

#ifndef __PetBubble__SCRectangleSurroundAction__
#define __PetBubble__SCRectangleSurroundAction__

#include <iostream>
#include <cocos2d.h>

class SCRectangleSurroundAction
{
    
public:
    
    static cocos2d::CCActionInterval* create(const cocos2d::CCPoint& left_bottom, const cocos2d::CCPoint& right_top, float radium, bool is_clockwise);
    
    static cocos2d::CCBezierTo* createBezierTo(const cocos2d::CCPoint& end, const cocos2d::CCPoint& control);
};

#endif /* defined(__PetBubble__SCRectangleSurroundAction__) */
