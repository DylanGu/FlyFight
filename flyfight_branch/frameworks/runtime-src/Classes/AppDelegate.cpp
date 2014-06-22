#include "AppDelegate.h"
#include "CCLuaEngine.h"
#include "SimpleAudioEngine.h"
#include "cocos2d.h"
#include "engine/script/lua_tinker_manager.h"
#include "game/manager/DataManager.h"
#include "game/script_export/ScriptFunRegister.h"
#include "game/manager/ConstantInfo.h"

using namespace CocosDenshion;

USING_NS_CC;
using namespace std;

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate()
{
    SimpleAudioEngine::end();
}

bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    auto director = Director::getInstance();
	auto glview = director->getOpenGLView();
	if(!glview) {
		glview = GLView::createWithRect("flyfight_branch", Rect(0,0,512,768));
		director->setOpenGLView(glview);
	}

    ConstantInfo::INIT();

    glview->setDesignResolutionSize(ConstantInfo::_DesignResolutionSize.width, ConstantInfo::_DesignResolutionSize.height, ConstantInfo::_DesignResolutionPolicy);

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);
    
    auto engine = LuaEngine::getInstance();
    ScriptEngineManager::getInstance()->setScriptEngine(engine);
    
    ScriptFunRegister::RegistCFun2Lua(engine->getLuaStack()->getLuaState());

    DataManager::GetInstance();
    
    Scene* scene = LuaTinkerManager::GetInstance().CallLuaFunc<Scene*>("src/scene/battle_scene.lua", "CreateBattleScene");
    Director::getInstance()->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    Director::getInstance()->stopAnimation();

    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    Director::getInstance()->startAnimation();

    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
