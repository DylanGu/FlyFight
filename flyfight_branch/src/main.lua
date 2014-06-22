require "Cocos2d"
require "Cocos2dConstants"

local search_path = 
{
    "src",
    "src/util",
    "src/language",
    "src/logic",
    "src/config",
    "res",
    "src/scene"
}

local init_module =
{
    "utils",
    "constan_info",
    "language_loader"
}

function cclog( ... )
    print(string.format(...))
end

function __G__TRACKBACK__(msg)
    cclog("----------------------------------------")
    cclog("LUA ERROR: " .. tostring(msg) .. "\n")
    cclog(debug.traceback())
    cclog("----------------------------------------")
    return msg
end

function reload_file(filename)
    package.loaded[filename] = nil  
    require( filename )
end

local function main()
    collectgarbage("collect")
    collectgarbage("setpause", 100)
    collectgarbage("setstepmul", 5000)

    -----------------------------------
    --默认寻找路径初始化
    local function registAllSearchPath()
        for k,v in pairs(search_path) do
            cc.FileUtils:getInstance():addSearchResolutionsOrder(v);
        end
    end
    registAllSearchPath()
    -----------------------------------
    --必要模块初始化
    local function loadInitModule()
        for k,v in pairs(init_module) do
            require(v)
        end
    end
    loadInitModule()
    -----------------------------------
    --环境初始化
    language_loader.setLanguage("cn")
    print("#Current language:" .. getLuaString("lan_name"))
    -----------------------------------
end


local status, msg = xpcall(main, __G__TRACKBACK__)

if not status then
    error(msg)
end

---------------------------------------------------------
--local version = DataManager:GetInstance():getTestVersion()
--print("!!!!!!!!!!!! ... version = " .. version)
--[[
    local a = actor.CreateActor("snowcold")
    a:show()

    setLanguage("cn")
    print("!!! Lan:" .. getLuaString("lan_name"))

    setLanguage("en")
    print("!!! Lan:" .. getLuaString("lan_name"))

    setLanguage("jp")
    print("!!! LanJP...:" .. getLuaString("lan_name"))

--]]




