//////////////////////////////////////////////////////////////
//
//  Copyright 2008 - 2012 TaoMee Inc. 
//
//      FileName: lua_tinker_manager.cpp
//        Author: robbiepan
//          Date: 2013/9/6 16:34
//   Description: Copy from Ahero 
//
// History:
//      <author>    <time>        <descript>
//     robbiepan    2013/9/6      add
//////////////////////////////////////////////////////////////
#include "lua_tinker_manager.h"
#include "CCLuaEngine.h"
#include "lua_cocostudio_gui.h"
#include "game/script_export/lua_client_export.h"
#include "lua_cjson.h"


int GetLuaSoundEffect(const char *key)
{
  return LuaTinkerManager::GetInstance().GetLuaSoundEffect<int>(key);
}

int GetLuaMusic(const char *key)
{
  return LuaTinkerManager::GetInstance().GetLuaMusic<int>(key);
}

char* GetLuaText(const char *key)
{
  return LuaTinkerManager::GetInstance().GetLuaText<char *>(key);
}


LuaTinkerManager::LuaTinkerManager()
{
  CCLuaStack *pStack = CCLuaEngine::defaultEngine()->getLuaStack();
  curLuaState_ = pStack->getLuaState();
  std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename("script/main.lua");
  unsigned long fileSize = 0;
  unsigned char* buffer = CCFileUtils::sharedFileUtils()->getFileData("script/main.lua", "rt", &fileSize);
  int ret = luaL_dostringEx(this->curLuaState_, (char*)buffer, fileSize);
	free(buffer);
}

LuaTinkerManager::~LuaTinkerManager()
{
  loadedFiles_.clear();
}

bool LuaTinkerManager::checkAnyLoadFile(string filePath)
{
    
    bool ret = false;
    ret = lua_tinker::call<bool>(this->curLuaState_, "LoadScriptFile",  filePath.c_str());
    return ret;
}

bool LuaTinkerManager::registerAllCustomLuaApi() {
  tolua_cocostudio_gui_open(curLuaState_);
  tolua_lua_client_export_open(curLuaState_);
  luaopen_cjson(curLuaState_);
  luaopen_cjson_safe(curLuaState_);
  return true;
}
