--    eid = 1, part = 2, level = 3, quality = 4, qualityRank = 5, hp = 6, defence = 7, atk = 8, atkSpeed = 9, name = 10

--[[
local function getEntry( id )
    return vTable[id]
end

print("--------")
local v = getEntry(1001)
if v ~= nil then
    print(v[kTable.name])
end
--]]

function InitDataTable()
    local kTable = nil

    function Key( o )
        kTable = o
    end

    function Entry( o )
        local data = BaseData:create();
        --data:setSID()
        data:setEID(o[1])
        data:setPart(o[2])
        data:setLevel(o[3])
        data:setQuality(o[4])
        data:setQualityRank(o[5])
        data:setHp(o[6])
        data:setDefence(o[7])
        data:setAtk(o[8])
        data:setAtkSpeed(o[9])

        local M = DataManager:GetInstance()
        M:registerBaseData(data)
        print("-Lua : registerBaseData-")
    end

    require("src/data/fighter_data.lua")

    return true
end