module(..., package.seeall )


local function createWelcomeLayer()
    local sprite = cc.Sprite:create("res/dog.png");
    return sprite
end

function CreateWelcomeScene()
    local scene = cc.Scene:create()
    scene:addChild(createWelcomeLayer())
    return scene
end

_G.CreateWelcomeScene = CreateWelcomeScene