module(..., package.seeall )

Lan = Lan or {}

Lan.current = nil
Lan.default = "cn"

Lan.support = 
{
    cn = "string_cn",
    en = "string_en" 
}

--Lan.string = Lan.string or {}

function setLanguage( language_name )
    if Lan.current ~= language_name then
        local oldModuleName = Lan.support[Lan.current]
        
        if oldModuleName ~= nil then
            package.loaded[oldModuleName] = nil
            Lan.string = nil
        end
        
        Lan.current = language_name
        local moduleName = Lan.support[Lan.current]

        if moduleName == nil then
            print("Change to default language")
            Lan.current = Lan.default
            moduleName = Lan.support[Lan.current]
        end
        
        if moduleName ~= nil then
            Lan.string = {}
            local M = require(moduleName)
            M.loadLanguage(Lan.string)
            print("success load lan : " .. moduleName)
        else
            print("ERROR NOT SUPPORT LAN : " .. language_name)
        end
    end
    --]]
    print("Lan has loaded : " .. language_name)
end

function getLuaString( key )
    return Lan.string[key]
end

_G.getLuaString = getLuaString