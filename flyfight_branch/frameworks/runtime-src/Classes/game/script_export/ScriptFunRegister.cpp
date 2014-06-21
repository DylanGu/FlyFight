//
//  ScriptFunRegister.cpp
//  flyfight_branch
//
//  Created by snowcold on 20/6/14.
//
//

#include "ScriptFunRegister.h"

using namespace cocos2d;

void ScriptFunRegister::RegistCFun2Lua(lua_State* tolua_S)
{
    register_all_(tolua_S);
}