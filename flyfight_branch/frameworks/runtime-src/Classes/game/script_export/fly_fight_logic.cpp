#include "fly_fight_logic.hpp"
#include "BattleScene.h"
#include "DataManager.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



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

int lua__DataManager_getTestVersion(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua__DataManager_getTestVersion'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getTestVersion();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getTestVersion",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__DataManager_getTestVersion'.",&tolua_err);
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
int lua__DataManager_constructor(lua_State* tolua_S)
{
    int argc = 0;
    DataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new DataManager();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"DataManager");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "DataManager",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua__DataManager_constructor'.",&tolua_err);
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
        tolua_function(tolua_S,"getTestVersion",lua__DataManager_getTestVersion);
        tolua_function(tolua_S,"new",lua__DataManager_constructor);
        tolua_function(tolua_S,"GetInstance", lua__DataManager_GetInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(DataManager).name();
    g_luaType[typeName] = "DataManager";
    g_typeCast["DataManager"] = "DataManager";
    return 1;
}
TOLUA_API int register_all_(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,nullptr,0);
	tolua_beginmodule(tolua_S,nullptr);

	lua_register__BattleScene(tolua_S);
	lua_register__DataManager(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

