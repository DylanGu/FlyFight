module(..., package.seeall )

local M = M or {}
M.__index = M

function M:onTouchBegin(sender, event_type)
    print("Touch begin")
end

function M:onTouchEnd(sender, event_type)
    print("Touch end")
end

function M:new()
    local o = o or {}
    o.__index = self
    return o
end

local function createBattleBgLayer()
    local layer = cc.Layer:create()
    local sprite = cc.Sprite:create("res/battle_bg/bg_1001.jpg");
    sprite:setPosition(cc.p(ConstanInfo.center_x, ConstanInfo.center_y))
    layer:addChild(sprite)
    return layer
end

local function createFighter()
    local sprite = cc.Sprite:create("res/module/fighter/f_1001.png")
    return sprite
end

function CreateBattleScene()
    --[[
    local scene = cc.Scene:create()
    --bg
    local bg = createBattleBgLayer()
    scene:addChild(bg)

    --fighter
    local fighter = createFighter()
    fighter:setPosition(cc.p(ConstanInfo.fighter_x, ConstanInfo.fighter_y))
    scene:addChild(fighter)

    return scene
    --]]
    return BattleScene:create()
end

_G.CreateBattleScene = CreateBattleScene