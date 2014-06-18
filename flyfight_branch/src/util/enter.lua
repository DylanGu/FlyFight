-- cclog
cclog = function(...)
    print(string.format(...))
end

-- for CCLuaEngine traceback
--[[function __G__TRACKBACK__(msg)
    cclog("----------------------------------------")
    cclog("LUA ERROR: " .. tostring(msg) .. "\n")
    cclog(debug.traceback())
    cclog("----------------------------------------")
end]]

local function delFileSuffix(file_path, file_suffix)
	if string.sub(file_path, -string.len(file_suffix), -1) == file_suffix then
		return string.sub(file_path, 0, - (string.len(file_suffix) + 1))
	end
	return file_path	
end

function LoadScriptFile(file_path)
    file_path = delFileSuffix(file_path, ".lua")
	return require(file_path) ~= nil
end

local function main()
    -- avoid memory leak
    collectgarbage("setpause", 100)
    collectgarbage("setstepmul", 5000)

	print ("----------------------------------------")
end

function reload_file(filename)
	package.loaded[ filename] = nil  
	require( filename )
end

xpcall(main, __G__TRACKBACK__)
