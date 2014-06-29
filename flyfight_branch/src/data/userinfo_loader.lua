
function InitUserInfo( user_id )
    print("--Lua begin init new user....")
    local data_manager = DataManager:GetInstance()
    local user_info = data_manager:getCurrentUserInfo()

    local base_data = data_manager:getBaseData(1001)
    user_info:addNewUnitAsData(base_data)
    return true
    --1.datamanager get user_info
    --2.添加战机
    --3.返回真假
end