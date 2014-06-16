--

function cclog( ... )
    print(string.format(...))
end


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