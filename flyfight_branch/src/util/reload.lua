-- 外部库 登记
local package_list = {
    bit = true 
}

-- 全局性质类/或禁止重新加载的文件记录
local ignored_file_list = {
    global = true ,
}

--已重新加载的文件记录
local loaded_file_list = {}

--视图排版控制
function leading_tag( indent )
    -- body
    if indent < 1 then
        return ''
    else
        return string.rep( '    |',  indent - 1  ) .. '    '
    end
end

--关键递归重新加载函数
--filename 文件名
--indent   递归深度, 用于控制排版显示
function recursive_reload( filename, indent )
    -- body
	
    if package_list[ filename] then 
        --对于 外部库, 只进行重新加载, 不做递归子文件
        --卸载旧文件
        package.loaded[ filename] = nil

        --装载信文件
        require( filename )

        --标记"已被重新加载"
        loaded_file_list[ filename] = true

        print( leading_tag(indent) .. filename .. "... done" )
        return true
    end
	
    --普通文件
    --进行 "已被重新加载" 检测
    if loaded_file_list[ filename] then 
        print( leading_tag(indent) .. filename .. "...already been reloaded IGNORED" )
        return true
    end

    --读取当前文件内容, 以进行子文件递归重新加载
    local file, err = io.open( filename..".lua" )
    if file == nil then 
        print( string.format( "failed to reaload file(%s), with error:%s", filename, err or "unknown" ) )
        return false
    end

    print( leading_tag(indent) .. filename .. "...")
    --读取每一行
    for line in file:lines() do 
        --识别 require(...)行, 正则表达? 模式匹配? 并拾取文件名 到 subFileName
        line = string.gsub( line, '%s', '' )
        local subFileName = nil 

        local ret = string.gsub( line, '^require"(.+)"', function ( s ) subFileName = ""..s end )

        if subFileName then
            --进行递归 
            local success = recursive_reload( subFileName, indent + 1 )
            if not success then 
                print( string.format( "failed to reload sub file of (%s)", filename ) )
                return false 
            end

        end
        
    end    


    -- "后序" 处理当前文件...

    
    if ignored_file_list[ filename] then
        --忽略 "禁止被重新加载"的文件
        print( leading_tag(indent) .. filename .. "... IGNORED" )
        return true
    else

        --卸载旧文件
        package.loaded[ filename] = nil

        --装载新文件
        require( filename )

        --设置"已被重新加载" 标记
        loaded_file_list[ filename] = true
        print( leading_tag(indent) .. filename .. "... done" )
        return true
    end
end

--主入口函数
function reload_script_files()
    
    print( "[reload_script_files...]")

    loaded_file_list = {}

    --本项目是以 main.lua 为主文件
    recursive_reload( "res/Script/main", 0 )
    
    print( "[reload_script_files...done]")

    return "reload ok"
end