//
//  ScriptFunRegister.h
//  flyfight_branch
//
//  Created by snowcold on 20/6/14.
//
//

#ifndef __flyfight_branch__ScriptFunRegister__
#define __flyfight_branch__ScriptFunRegister__

#include "cocos2d.h"
#include "fly_fight_logic.hpp"

class ScriptFunRegister : public cocos2d::Ref
{
public:
    
    static void RegistCFun2Lua(lua_State* tolua_S);
};

#endif /* defined(__flyfight_branch__ScriptFunRegister__) */
