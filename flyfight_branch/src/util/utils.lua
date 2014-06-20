---[[该加载模式加载的是短模块名
function LoadScriptFile( file_name )
    local i = 0
    local preI = 0
    while true do
        preI = i
        i = string.find(file_name, "/", i + 1)
        if i == nil then
            i = preI
            break
        end
    end
    local j = string.find(file_name, ".lua", i)
    if j ~= nil then
        local module_name = string.sub(file_name, i + 1, j - 1)
        --print("FileName = " .. file_name)
        --print("ModuleName = " .. module_name)
        require(module_name)
    else
        print("LUA ERROR: Not Find File : " .. file_name)
        return false
    end
    return true
end
--]]
-------------------------------
--[[
local function delFileSuffix(file_path, file_suffix)
    if string.sub(file_path, -string.len(file_suffix), -1) == file_suffix then
        return string.sub(file_path, 0, - (string.len(file_suffix) + 1))
    end
    return file_path    
end

function LoadScriptFile(file_path)
    file_path = delFileSuffix(file_path, ".lua")
    print("!!!! ##### path = " .. file_path)
    return require(file_path) ~= nil
end
--]]