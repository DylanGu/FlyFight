module(..., package.seeall )


local theme = {}

theme[1] = { layer = {1,2,3}, dec = {4, 6, 7, 10} }
theme[2] = { layer = {1, 2}, dec = {1, 2} }
theme[3] = { layer = {1, 2}, dec = {1, 2} }
theme[4] = { layer = {1, 2}, dec = {1, 2} }
theme[5] = { layer = {1, 2}, dec = {1, 2} }
theme[6] = { layer = {1, 2}, dec = {1, 2} }

------------------------------------------------
layer = {}
layer[1] = { bg = {1, 2}, speed = 0.5 }
layer[2] = { bg = {4, 5}, speed = 1.0 }
layer[3] = { bg = {4, 5}, speed = 0.6 }
layer[4] = { bg = {1, 2}, speed = 0.5 }
layer[5] = { bg = {1, 2}, speed = 0.5 }
layer[6] = { bg = {1, 2}, speed = 0.5 }
layer[7] = { bg = {1, 2}, speed = 0.5 }
layer[8] = { bg = {1, 2}, speed = 0.5 }
layer[9] = { bg = {1, 2}, speed = 0.5 }
layer[10] = { bg = {1, 2}, speed = 0.5 }

------------------------------------------------

bg = 
{
    "res/battle_bg/bg_1.jpg",
    "res/battle_bg/bg_2.jpg",
    "res/battle_bg/bg_3.jpg",
    "res/battle_bg/bg_4.png",
    "res/battle_bg/bg_5.png",
    "res/battle_bg/bg_6.jpg",
    "res/battle_bg/bg_7.jpg",
    "res/battle_bg/bg_8.jpg",
    "res/battle_bg/bg_9.jpg",
    "res/battle_bg/bg_10.jpg",
    "res/battle_bg/bg_11.jpg",
}

------------------------------------------------


--有些装饰物可以合成一组
dec_group =
{

}

dec =
{
    "res/decoration/decor_1.png",
    "res/decoration/decor_2.png",
    "res/decoration/decor_3.png",
    "res/decoration/decor_4.png",
    "res/decoration/decor_5.png",
    "res/decoration/decor_6.png",
    "res/decoration/decor_7.png",
    "res/decoration/decor_8.png",
    "res/decoration/decor_9.png",
    "res/decoration/decor_10.png",
    "res/decoration/decor_11.png",
    "res/decoration/decor_12.png",
    "res/decoration/decor_13.png",
    "res/decoration/decor_14.png",
}

function _G.GetRandomBattleBgPath()
    return bg[math.random(#bg)]
end

function _G.GetRandomDecorationPath()
    return dec[math.random(#dec)]
end

--Bg begin
function _G.GetThemeBgLayerCount(theme_id)
    local theme = theme[theme_id]
    if theme == nil then
        print("!!!Lua Error [Theme not exist]")
        return -1
    end

    return #theme.layer
end

function _G.GetBattleBgIndexForTheme( theme_id , layer_index, pre_index)
    local theme = theme[theme_id]
    if theme == nil then
        print("!!!Lua Error [Theme not exist]")
        return -1
    end

    pre_index = pre_index + 1
    local layerId = theme.layer[layer_index]
    local layer = layer[layerId]

    if pre_index > #layer.bg then
        pre_index = 1
    end
    return pre_index
end

function _G.GetBattleBgPathByIndex(theme_id, layer_index, index)
    local theme = theme[theme_id]
    if theme == nil then
        print("!!!Lua Error [Theme not exist]")
        return nil
    end

    if index < 1 then
        print("!!!Lua Error [Bg index not index]")
        return nil
    end

    local layerId = theme.layer[layer_index]
    local layer = layer[layerId]
    local id = layer.bg[index]
    return bg[id]
end

function _G.GetLayerSpeedForTheme( theme_id, layer_index)
    local theme = theme[theme_id]
    if theme == nil then
        print("!!!Lua Error [Theme not exist]")
        return -1
    end

    local layerId = theme.layer[layer_index]
    local layer = layer[layerId]
    return layer.speed
end
--Bg end


--Dec begin

function _G.GetDecorationPathForTheme( theme_id )
    local theme = theme[theme_id]
    if theme == nil then
        print("!!!Lua Error [Theme not exist]")
        return nil
    end
    if theme.dec == nil then
        return nil
    end
    return dec[theme.dec[math.random(#theme.dec)]]
end

--Dec end








