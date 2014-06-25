
print("-----begin------")
local kTable = nil
local vTable = {}
function Key( o )
    print("-key-")
    kTable = o
end
function Entry( o )
    print("-Entry-")
    vTable[o[1]] = o
end

dofile("src/data/base_data.lua")
--[[
print("-----end--------")
for k,v in pairs(vTable) do
    for i,vv in ipairs(v) do
            print(kTable[i],vv)
    end
end
--]]
local function getEntry( id )
    return vTable[id]
end

print("--------")
local v = getEntry(1001)
if v ~= nil then
    print(v[kTable.name])
end