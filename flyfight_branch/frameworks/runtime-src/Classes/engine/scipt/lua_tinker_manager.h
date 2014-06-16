//////////////////////////////////////////////////////////////
//
//  Copyright 2008 - 2012 TaoMee Inc. 
//
//      FileName: lua_tinker_manager.h
//        Author: robbiepan
//          Date: 2013/9/6 16:34
//   Description: Copy from Ahero
//
// History:
//      <author>    <time>        <descript>
//     robbiepan    2013/9/6      add
//////////////////////////////////////////////////////////////

#ifndef LUATINKERMANAGER_H
#define LUATINKERMANAGER_H

#include <cocos2d.h>
#include <string>
#include <set>

#pragma warning(disable:4700)

extern "C" {
#	include "lua.h"
#	include "lualib.h"
#	include "lauxlib.h"
}
#include "lua_tinker.h"

struct lua_State;

using namespace std;
using namespace cocos2d;

int GetLuaSoundEffect(const char *key);
int GetLuaMusic(const char *key);
char* GetLuaText(const char *key);


class LuaTinkerManager
{
public:
  static LuaTinkerManager& GetInstance()
  {
    static LuaTinkerManager instance;
    return instance;
  }
  virtual ~LuaTinkerManager();

  //通用调用接口，不支持返回值为void
  template<typename RVal>
  RVal CallLuaFunc(const char* filePath, const char* funcName)
  {
    RVal ret;
    if (false == this->checkAnyLoadFile(filePath))
      return ret;

    ret = lua_tinker::call<RVal>(this->curLuaState_, funcName);
    return ret;
  }

  template<typename RVal, typename T1>
  RVal CallLuaFunc(const char* filePath, const char* funcName, T1 arg)
  {
    RVal ret;
    if (false == this->checkAnyLoadFile(filePath))
      return ret;

    ret = lua_tinker::call<RVal>(this->curLuaState_, funcName, arg);
    return ret;
  }

  template<typename RVal, typename T1, typename T2>
  RVal CallLuaFunc(const char* filePath, const char* funcName, T1 arg1, T2 arg2)
  {
    RVal ret;
    if (false == this->checkAnyLoadFile(filePath))
      return ret;

    ret = lua_tinker::call<RVal>(this->curLuaState_, funcName, arg1, arg2);
    return ret;
  }

  template<typename RVal, typename T1, typename T2, typename T3>
  RVal CallLuaFunc(const char* filePath, const char* funcName, T1 arg1, T2 arg2, T3 arg3)
  {
    RVal ret;
    if (false == this->checkAnyLoadFile(filePath))
      return ret;

    ret = lua_tinker::call<RVal>(this->curLuaState_, funcName, arg1, arg2, arg3);
    return ret;
  }   

  template<typename RVal, typename T1, typename T2, typename T3, typename T4>
  RVal CallLuaFunc(const char* filePath, const char* funcName, T1 arg1, T2 arg2, T3 arg3, T4 arg4)
  {
    RVal ret;
    if (false == this->checkAnyLoadFile(filePath))
      return ret;

    ret = lua_tinker::call<RVal>(this->curLuaState_, funcName, arg1, arg2, arg3, arg4);
    return ret;
  }  

  template<typename RVal, typename T1, typename T2, typename T3, typename T4, typename T5>
  RVal CallLuaFunc(const char* filePath, const char* funcName, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5)
  {
    RVal ret;
    if (false == this->checkAnyLoadFile(filePath))
      return ret;

    ret = lua_tinker::call<RVal>(this->curLuaState_, funcName, arg1, arg2, arg3, arg4, arg5);
    return ret;
  }  

  //读取配置
  template<typename RVal, typename T1, typename T2>
  RVal GetLuaConfig(string configFileName, const char * tableName, T1 idName, T2 typeName)
  {
    RVal ret;
    if (false == this->checkAnyLoadFile("script/config/" + configFileName + ".lua"))
      return ret;

    lua_tinker::table gTable = lua_tinker::get<lua_tinker::table>(this->curLuaState_, tableName);
    lua_tinker::table inTable = gTable.get<lua_tinker::table>(idName);
    ret = inTable.get<RVal>(typeName);
    return ret;
  }

  //读取配置
  template<typename RVal, typename T1>
  RVal GetLuaText(T1 arg)
  {
    RVal ret;
    if (false == this->checkAnyLoadFile("script/config/text_table.lua"))
      return ret;

    ret = lua_tinker::call<RVal>(this->curLuaState_, "GetLuaText", arg);
    return ret;
  }

  //读取音效
  template<typename RVal, typename T1>
  RVal GetLuaSoundEffect(T1 arg)
  {
    RVal ret;
    if (false == this->checkAnyLoadFile("script/config/sound_constants.lua"))
      return ret;

    ret = lua_tinker::call<RVal>(this->curLuaState_, "GetLuaSoundEffect", arg);
    return ret;
  }

  //读取音乐
  template<typename RVal, typename T1>
  RVal GetLuaMusic(T1 arg)
  {
    RVal ret;
    if (false == this->checkAnyLoadFile("script/config/sound_constants.lua"))
      return ret;

    ret = lua_tinker::call<RVal>(this->curLuaState_, "GetLuaMusic", arg);
    return ret;
  }
  
   lua_State* get_cur_lua_state() {return curLuaState_;}
   bool registerAllCustomLuaApi();
private:
  LuaTinkerManager();
  bool checkAnyLoadFile(string filePath);
private:
  lua_State *curLuaState_;

  //已经加载的lua文件集合
  set<string> loadedFiles_;
};




#endif