#include "fly_fight_logic.hpp"
#include "LuaExportHeader.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua__BaseData_setPart(lua_State* tolua_S)
{
    int argc = 0;
    BaseData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BaseData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (BaseData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua__BaseData_setPart'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setPart(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setPart",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__BaseData_setPart'.",&tolua_err);
#endif

    return 0;
}
int lua__BaseData_getAtkSpeed(lua_State* tolua_S)
{
    int argc = 0;
    BaseData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BaseData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (BaseData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua__BaseData_getAtkSpeed'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getAtkSpeed();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getAtkSpeed",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__BaseData_getAtkSpeed'.",&tolua_err);
#endif

    return 0;
}
int lua__BaseData_setAtkSpeed(lua_State* tolua_S)
{
    int argc = 0;
    BaseData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BaseData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (BaseData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua__BaseData_setAtkSpeed'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setAtkSpeed(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setAtkSpeed",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__BaseData_setAtkSpeed'.",&tolua_err);
#endif

    return 0;
}
int lua__BaseData_getQuality(lua_State* tolua_S)
{
    int argc = 0;
    BaseData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BaseData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (BaseData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua__BaseData_getQuality'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getQuality();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getQuality",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__BaseData_getQuality'.",&tolua_err);
#endif

    return 0;
}
int lua__BaseData_setQualityRank(lua_State* tolua_S)
{
    int argc = 0;
    BaseData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BaseData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (BaseData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua__BaseData_setQualityRank'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setQualityRank(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setQualityRank",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__BaseData_setQualityRank'.",&tolua_err);
#endif

    return 0;
}
int lua__BaseData_setAtk(lua_State* tolua_S)
{
    int argc = 0;
    BaseData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BaseData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (BaseData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua__BaseData_setAtk'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setAtk(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setAtk",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__BaseData_setAtk'.",&tolua_err);
#endif

    return 0;
}
int lua__BaseData_setLevel(lua_State* tolua_S)
{
    int argc = 0;
    BaseData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BaseData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (BaseData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua__BaseData_setLevel'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setLevel(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setLevel",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__BaseData_setLevel'.",&tolua_err);
#endif

    return 0;
}
int lua__BaseData_getQualityRank(lua_State* tolua_S)
{
    int argc = 0;
    BaseData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BaseData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (BaseData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua__BaseData_getQualityRank'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getQualityRank();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getQualityRank",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__BaseData_getQualityRank'.",&tolua_err);
#endif

    return 0;
}
int lua__BaseData_setHp(lua_State* tolua_S)
{
    int argc = 0;
    BaseData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BaseData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (BaseData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua__BaseData_setHp'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setHp(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setHp",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__BaseData_setHp'.",&tolua_err);
#endif

    return 0;
}
int lua__BaseData_setDefence(lua_State* tolua_S)
{
    int argc = 0;
    BaseData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BaseData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (BaseData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua__BaseData_setDefence'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setDefence(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setDefence",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__BaseData_setDefence'.",&tolua_err);
#endif

    return 0;
}
int lua__BaseData_setEID(lua_State* tolua_S)
{
    int argc = 0;
    BaseData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BaseData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (BaseData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua__BaseData_setEID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setEID(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setEID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__BaseData_setEID'.",&tolua_err);
#endif

    return 0;
}
int lua__BaseData_setQuality(lua_State* tolua_S)
{
    int argc = 0;
    BaseData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BaseData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (BaseData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua__BaseData_setQuality'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setQuality(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setQuality",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__BaseData_setQuality'.",&tolua_err);
#endif

    return 0;
}
int lua__BaseData_setSID(lua_State* tolua_S)
{
    int argc = 0;
    BaseData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BaseData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (BaseData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua__BaseData_setSID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setSID(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setSID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__BaseData_setSID'.",&tolua_err);
#endif

    return 0;
}
int lua__BaseData_getEID(lua_State* tolua_S)
{
    int argc = 0;
    BaseData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BaseData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (BaseData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua__BaseData_getEID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getEID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getEID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__BaseData_getEID'.",&tolua_err);
#endif

    return 0;
}
int lua__BaseData_getLevel(lua_State* tolua_S)
{
    int argc = 0;
    BaseData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BaseData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (BaseData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua__BaseData_getLevel'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getLevel();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getLevel",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__BaseData_getLevel'.",&tolua_err);
#endif

    return 0;
}
int lua__BaseData_getAtk(lua_State* tolua_S)
{
    int argc = 0;
    BaseData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BaseData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (BaseData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua__BaseData_getAtk'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getAtk();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getAtk",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__BaseData_getAtk'.",&tolua_err);
#endif

    return 0;
}
int lua__BaseData_getHp(lua_State* tolua_S)
{
    int argc = 0;
    BaseData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BaseData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (BaseData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua__BaseData_getHp'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getHp();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getHp",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__BaseData_getHp'.",&tolua_err);
#endif

    return 0;
}
int lua__BaseData_getPart(lua_State* tolua_S)
{
    int argc = 0;
    BaseData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BaseData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (BaseData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua__BaseData_getPart'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getPart();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getPart",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__BaseData_getPart'.",&tolua_err);
#endif

    return 0;
}
int lua__BaseData_getDefence(lua_State* tolua_S)
{
    int argc = 0;
    BaseData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BaseData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (BaseData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua__BaseData_getDefence'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getDefence();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDefence",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__BaseData_getDefence'.",&tolua_err);
#endif

    return 0;
}
int lua__BaseData_getSID(lua_State* tolua_S)
{
    int argc = 0;
    BaseData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BaseData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (BaseData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua__BaseData_getSID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getSID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getSID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__BaseData_getSID'.",&tolua_err);
#endif

    return 0;
}
int lua__BaseData_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"BaseData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        BaseData* ret = BaseData::create();
        object_to_luaval<BaseData>(tolua_S, "BaseData",(BaseData*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__BaseData_create'.",&tolua_err);
#endif
    return 0;
}
static int lua__BaseData_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (BaseData)");
    return 0;
}

int lua_register__BaseData(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"BaseData");
    tolua_cclass(tolua_S,"BaseData","BaseData","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"BaseData");
        tolua_function(tolua_S,"setPart",lua__BaseData_setPart);
        tolua_function(tolua_S,"getAtkSpeed",lua__BaseData_getAtkSpeed);
        tolua_function(tolua_S,"setAtkSpeed",lua__BaseData_setAtkSpeed);
        tolua_function(tolua_S,"getQuality",lua__BaseData_getQuality);
        tolua_function(tolua_S,"setQualityRank",lua__BaseData_setQualityRank);
        tolua_function(tolua_S,"setAtk",lua__BaseData_setAtk);
        tolua_function(tolua_S,"setLevel",lua__BaseData_setLevel);
        tolua_function(tolua_S,"getQualityRank",lua__BaseData_getQualityRank);
        tolua_function(tolua_S,"setHp",lua__BaseData_setHp);
        tolua_function(tolua_S,"setDefence",lua__BaseData_setDefence);
        tolua_function(tolua_S,"setEID",lua__BaseData_setEID);
        tolua_function(tolua_S,"setQuality",lua__BaseData_setQuality);
        tolua_function(tolua_S,"setSID",lua__BaseData_setSID);
        tolua_function(tolua_S,"getEID",lua__BaseData_getEID);
        tolua_function(tolua_S,"getLevel",lua__BaseData_getLevel);
        tolua_function(tolua_S,"getAtk",lua__BaseData_getAtk);
        tolua_function(tolua_S,"getHp",lua__BaseData_getHp);
        tolua_function(tolua_S,"getPart",lua__BaseData_getPart);
        tolua_function(tolua_S,"getDefence",lua__BaseData_getDefence);
        tolua_function(tolua_S,"getSID",lua__BaseData_getSID);
        tolua_function(tolua_S,"create", lua__BaseData_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(BaseData).name();
    g_luaType[typeName] = "BaseData";
    g_typeCast["BaseData"] = "BaseData";
    return 1;
}

int lua__BaseUnit_getBaseData(lua_State* tolua_S)
{
    int argc = 0;
    BaseUnit* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BaseUnit",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (BaseUnit*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua__BaseUnit_getBaseData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        BaseData* ret = cobj->getBaseData();
        object_to_luaval<BaseData>(tolua_S, "BaseData",(BaseData*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getBaseData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__BaseUnit_getBaseData'.",&tolua_err);
#endif

    return 0;
}
int lua__BaseUnit_addModule(lua_State* tolua_S)
{
    int argc = 0;
    BaseUnit* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BaseUnit",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (BaseUnit*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua__BaseUnit_addModule'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->addModule();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addModule",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__BaseUnit_addModule'.",&tolua_err);
#endif

    return 0;
}
int lua__BaseUnit_init(lua_State* tolua_S)
{
    int argc = 0;
    BaseUnit* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BaseUnit",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (BaseUnit*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua__BaseUnit_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__BaseUnit_init'.",&tolua_err);
#endif

    return 0;
}
int lua__BaseUnit_rebuildAsData(lua_State* tolua_S)
{
    int argc = 0;
    BaseUnit* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BaseUnit",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (BaseUnit*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua__BaseUnit_rebuildAsData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->rebuildAsData();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "rebuildAsData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__BaseUnit_rebuildAsData'.",&tolua_err);
#endif

    return 0;
}
int lua__BaseUnit_setBaseData(lua_State* tolua_S)
{
    int argc = 0;
    BaseUnit* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BaseUnit",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (BaseUnit*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua__BaseUnit_setBaseData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        BaseData* arg0;

        ok &= luaval_to_object<BaseData>(tolua_S, 2, "BaseData",&arg0);
        if(!ok)
            return 0;
        cobj->setBaseData(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBaseData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__BaseUnit_setBaseData'.",&tolua_err);
#endif

    return 0;
}
int lua__BaseUnit_constructor(lua_State* tolua_S)
{
    int argc = 0;
    BaseUnit* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new BaseUnit();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"BaseUnit");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "BaseUnit",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua__BaseUnit_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua__BaseUnit_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (BaseUnit)");
    return 0;
}

int lua_register__BaseUnit(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"BaseUnit");
    tolua_cclass(tolua_S,"BaseUnit","BaseUnit","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"BaseUnit");
        tolua_function(tolua_S,"getBaseData",lua__BaseUnit_getBaseData);
        tolua_function(tolua_S,"addModule",lua__BaseUnit_addModule);
        tolua_function(tolua_S,"init",lua__BaseUnit_init);
        tolua_function(tolua_S,"rebuildAsData",lua__BaseUnit_rebuildAsData);
        tolua_function(tolua_S,"setBaseData",lua__BaseUnit_setBaseData);
        tolua_function(tolua_S,"new",lua__BaseUnit_constructor);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(BaseUnit).name();
    g_luaType[typeName] = "BaseUnit";
    g_typeCast["BaseUnit"] = "BaseUnit";
    return 1;
}

int lua__UserInfo_getUnit(lua_State* tolua_S)
{
    int argc = 0;
    UserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua__UserInfo_getUnit'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        BaseUnit* ret = cobj->getUnit(arg0);
        object_to_luaval<BaseUnit>(tolua_S, "BaseUnit",(BaseUnit*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getUnit",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__UserInfo_getUnit'.",&tolua_err);
#endif

    return 0;
}
int lua__UserInfo_addUnit(lua_State* tolua_S)
{
    int argc = 0;
    UserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua__UserInfo_addUnit'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        BaseUnit* arg0;

        ok &= luaval_to_object<BaseUnit>(tolua_S, 2, "BaseUnit",&arg0);
        if(!ok)
            return 0;
        cobj->addUnit(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addUnit",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__UserInfo_addUnit'.",&tolua_err);
#endif

    return 0;
}
int lua__UserInfo_removeUnit(lua_State* tolua_S)
{
    int argc = 0;
    UserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua__UserInfo_removeUnit'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->removeUnit(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeUnit",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__UserInfo_removeUnit'.",&tolua_err);
#endif

    return 0;
}
int lua__UserInfo_initUserInfoFromProtobuf(lua_State* tolua_S)
{
    int argc = 0;
    UserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua__UserInfo_initUserInfoFromProtobuf'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->initUserInfoFromProtobuf(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initUserInfoFromProtobuf",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__UserInfo_initUserInfoFromProtobuf'.",&tolua_err);
#endif

    return 0;
}
int lua__UserInfo_initUserInfoFromDB(lua_State* tolua_S)
{
    int argc = 0;
    UserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua__UserInfo_initUserInfoFromDB'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->initUserInfoFromDB(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initUserInfoFromDB",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__UserInfo_initUserInfoFromDB'.",&tolua_err);
#endif

    return 0;
}
int lua__UserInfo_saveUserInfoToClien(lua_State* tolua_S)
{
    int argc = 0;
    UserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua__UserInfo_saveUserInfoToClien'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->saveUserInfoToClien();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "saveUserInfoToClien",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__UserInfo_saveUserInfoToClien'.",&tolua_err);
#endif

    return 0;
}
int lua__UserInfo_addNewUnitAsData(lua_State* tolua_S)
{
    int argc = 0;
    UserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua__UserInfo_addNewUnitAsData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        BaseData* arg0;

        ok &= luaval_to_object<BaseData>(tolua_S, 2, "BaseData",&arg0);
        if(!ok)
            return 0;
        cobj->addNewUnitAsData(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addNewUnitAsData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__UserInfo_addNewUnitAsData'.",&tolua_err);
#endif

    return 0;
}
int lua__UserInfo_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        UserInfo* ret = UserInfo::create();
        object_to_luaval<UserInfo>(tolua_S, "UserInfo",(UserInfo*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__UserInfo_create'.",&tolua_err);
#endif
    return 0;
}
static int lua__UserInfo_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (UserInfo)");
    return 0;
}

int lua_register__UserInfo(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"UserInfo");
    tolua_cclass(tolua_S,"UserInfo","UserInfo","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"UserInfo");
        tolua_function(tolua_S,"getUnit",lua__UserInfo_getUnit);
        tolua_function(tolua_S,"addUnit",lua__UserInfo_addUnit);
        tolua_function(tolua_S,"removeUnit",lua__UserInfo_removeUnit);
        tolua_function(tolua_S,"initUserInfoFromProtobuf",lua__UserInfo_initUserInfoFromProtobuf);
        tolua_function(tolua_S,"initUserInfoFromDB",lua__UserInfo_initUserInfoFromDB);
        tolua_function(tolua_S,"saveUserInfoToClien",lua__UserInfo_saveUserInfoToClien);
        tolua_function(tolua_S,"addNewUnitAsData",lua__UserInfo_addNewUnitAsData);
        tolua_function(tolua_S,"create", lua__UserInfo_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(UserInfo).name();
    g_luaType[typeName] = "UserInfo";
    g_typeCast["UserInfo"] = "UserInfo";
    return 1;
}

int lua__IDManager_generateUnitSID(lua_State* tolua_S)
{
    int argc = 0;
    IDManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IDManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IDManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua__IDManager_generateUnitSID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->generateUnitSID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "generateUnitSID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__IDManager_generateUnitSID'.",&tolua_err);
#endif

    return 0;
}
int lua__IDManager_getBaseUnit(lua_State* tolua_S)
{
    int argc = 0;
    IDManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IDManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IDManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua__IDManager_getBaseUnit'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        BaseUnit* ret = cobj->getBaseUnit(arg0);
        object_to_luaval<BaseUnit>(tolua_S, "BaseUnit",(BaseUnit*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getBaseUnit",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__IDManager_getBaseUnit'.",&tolua_err);
#endif

    return 0;
}
int lua__IDManager_registerBaseUnit(lua_State* tolua_S)
{
    int argc = 0;
    IDManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IDManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IDManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua__IDManager_registerBaseUnit'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        BaseUnit* arg0;

        ok &= luaval_to_object<BaseUnit>(tolua_S, 2, "BaseUnit",&arg0);
        if(!ok)
            return 0;
        int ret = cobj->registerBaseUnit(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "registerBaseUnit",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__IDManager_registerBaseUnit'.",&tolua_err);
#endif

    return 0;
}
int lua__IDManager_GetInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"IDManager",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        IDManager* ret = IDManager::GetInstance();
        object_to_luaval<IDManager>(tolua_S, "IDManager",(IDManager*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "GetInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__IDManager_GetInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua__IDManager_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (IDManager)");
    return 0;
}

int lua_register__IDManager(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"IDManager");
    tolua_cclass(tolua_S,"IDManager","IDManager","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"IDManager");
        tolua_function(tolua_S,"generateUnitSID",lua__IDManager_generateUnitSID);
        tolua_function(tolua_S,"getBaseUnit",lua__IDManager_getBaseUnit);
        tolua_function(tolua_S,"registerBaseUnit",lua__IDManager_registerBaseUnit);
        tolua_function(tolua_S,"GetInstance", lua__IDManager_GetInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(IDManager).name();
    g_luaType[typeName] = "IDManager";
    g_typeCast["IDManager"] = "IDManager";
    return 1;
}

int lua__DataManager_getCurrentUserInfo(lua_State* tolua_S)
{
    int argc = 0;
    DataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"DataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (DataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua__DataManager_getCurrentUserInfo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        UserInfo* ret = cobj->getCurrentUserInfo();
        object_to_luaval<UserInfo>(tolua_S, "UserInfo",(UserInfo*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getCurrentUserInfo",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__DataManager_getCurrentUserInfo'.",&tolua_err);
#endif

    return 0;
}
int lua__DataManager_changerUser(lua_State* tolua_S)
{
    int argc = 0;
    DataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"DataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (DataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua__DataManager_changerUser'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->changerUser(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "changerUser",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__DataManager_changerUser'.",&tolua_err);
#endif

    return 0;
}
int lua__DataManager_getBaseData(lua_State* tolua_S)
{
    int argc = 0;
    DataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"DataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (DataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua__DataManager_getBaseData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        BaseData* ret = cobj->getBaseData(arg0);
        object_to_luaval<BaseData>(tolua_S, "BaseData",(BaseData*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getBaseData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__DataManager_getBaseData'.",&tolua_err);
#endif

    return 0;
}
int lua__DataManager_registerBaseData(lua_State* tolua_S)
{
    int argc = 0;
    DataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"DataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (DataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua__DataManager_registerBaseData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        BaseData* arg0;

        ok &= luaval_to_object<BaseData>(tolua_S, 2, "BaseData",&arg0);
        if(!ok)
            return 0;
        cobj->registerBaseData(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "registerBaseData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__DataManager_registerBaseData'.",&tolua_err);
#endif

    return 0;
}
int lua__DataManager_GetInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"DataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        DataManager* ret = DataManager::GetInstance();
        object_to_luaval<DataManager>(tolua_S, "DataManager",(DataManager*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "GetInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__DataManager_GetInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua__DataManager_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (DataManager)");
    return 0;
}

int lua_register__DataManager(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"DataManager");
    tolua_cclass(tolua_S,"DataManager","DataManager","",nullptr);

    tolua_beginmodule(tolua_S,"DataManager");
        tolua_function(tolua_S,"getCurrentUserInfo",lua__DataManager_getCurrentUserInfo);
        tolua_function(tolua_S,"changerUser",lua__DataManager_changerUser);
        tolua_function(tolua_S,"getBaseData",lua__DataManager_getBaseData);
        tolua_function(tolua_S,"registerBaseData",lua__DataManager_registerBaseData);
        tolua_function(tolua_S,"GetInstance", lua__DataManager_GetInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(DataManager).name();
    g_luaType[typeName] = "DataManager";
    g_typeCast["DataManager"] = "DataManager";
    return 1;
}

int lua__BattleScene_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"BattleScene",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        BattleScene* ret = BattleScene::create();
        object_to_luaval<BattleScene>(tolua_S, "BattleScene",(BattleScene*)ret);
        return 1;
    }
    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        BattleScene* ret = BattleScene::create(arg0);
        object_to_luaval<BattleScene>(tolua_S, "BattleScene",(BattleScene*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__BattleScene_create'.",&tolua_err);
#endif
    return 0;
}
static int lua__BattleScene_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (BattleScene)");
    return 0;
}

int lua_register__BattleScene(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"BattleScene");
    tolua_cclass(tolua_S,"BattleScene","BattleScene","BaseScene",nullptr);

    tolua_beginmodule(tolua_S,"BattleScene");
        tolua_function(tolua_S,"create", lua__BattleScene_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(BattleScene).name();
    g_luaType[typeName] = "BattleScene";
    g_typeCast["BattleScene"] = "BattleScene";
    return 1;
}
TOLUA_API int register_all_(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,nullptr,0);
	tolua_beginmodule(tolua_S,nullptr);

	lua_register__IDManager(tolua_S);
	lua_register__BattleScene(tolua_S);
	lua_register__UserInfo(tolua_S);
	lua_register__DataManager(tolua_S);
	lua_register__BaseData(tolua_S);
	lua_register__BaseUnit(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

