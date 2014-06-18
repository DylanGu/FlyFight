-- �ⲿ�� �Ǽ�
local package_list = {
    bit = true 
}

-- ȫ��������/���ֹ���¼��ص��ļ���¼
local ignored_file_list = {
    global = true ,
}

--�����¼��ص��ļ���¼
local loaded_file_list = {}

--��ͼ�Ű����
function leading_tag( indent )
    -- body
    if indent < 1 then
        return ''
    else
        return string.rep( '    |',  indent - 1  ) .. '    '
    end
end

--�ؼ��ݹ����¼��غ���
--filename �ļ���
--indent   �ݹ����, ���ڿ����Ű���ʾ
function recursive_reload( filename, indent )
    -- body
	
    if package_list[ filename] then 
        --���� �ⲿ��, ֻ�������¼���, �����ݹ����ļ�
        --ж�ؾ��ļ�
        package.loaded[ filename] = nil

        --װ�����ļ�
        require( filename )

        --���"�ѱ����¼���"
        loaded_file_list[ filename] = true

        print( leading_tag(indent) .. filename .. "... done" )
        return true
    end
	
    --��ͨ�ļ�
    --���� "�ѱ����¼���" ���
    if loaded_file_list[ filename] then 
        print( leading_tag(indent) .. filename .. "...already been reloaded IGNORED" )
        return true
    end

    --��ȡ��ǰ�ļ�����, �Խ������ļ��ݹ����¼���
    local file, err = io.open( filename..".lua" )
    if file == nil then 
        print( string.format( "failed to reaload file(%s), with error:%s", filename, err or "unknown" ) )
        return false
    end

    print( leading_tag(indent) .. filename .. "...")
    --��ȡÿһ��
    for line in file:lines() do 
        --ʶ�� require(...)��, ������? ģʽƥ��? ��ʰȡ�ļ��� �� subFileName
        line = string.gsub( line, '%s', '' )
        local subFileName = nil 

        local ret = string.gsub( line, '^require"(.+)"', function ( s ) subFileName = ""..s end )

        if subFileName then
            --���еݹ� 
            local success = recursive_reload( subFileName, indent + 1 )
            if not success then 
                print( string.format( "failed to reload sub file of (%s)", filename ) )
                return false 
            end

        end
        
    end    


    -- "����" ����ǰ�ļ�...

    
    if ignored_file_list[ filename] then
        --���� "��ֹ�����¼���"���ļ�
        print( leading_tag(indent) .. filename .. "... IGNORED" )
        return true
    else

        --ж�ؾ��ļ�
        package.loaded[ filename] = nil

        --װ�����ļ�
        require( filename )

        --����"�ѱ����¼���" ���
        loaded_file_list[ filename] = true
        print( leading_tag(indent) .. filename .. "... done" )
        return true
    end
end

--����ں���
function reload_script_files()
    
    print( "[reload_script_files...]")

    loaded_file_list = {}

    --����Ŀ���� main.lua Ϊ���ļ�
    recursive_reload( "res/Script/main", 0 )
    
    print( "[reload_script_files...done]")

    return "reload ok"
end