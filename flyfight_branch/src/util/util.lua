--[[--暂时不可用]]
module ("util",  package.seeall)
require("script/config/ui_tag_table")

function TableCount(table_t)
	local n = 0
	for i,v in pairs(table_t) do n = n + 1 end
	return n
end

function TableToCCArray(src_table) 
	local ccarray = CCArray:create()
	for i = 1, #src_table  do
		ccarray:addObject(CCInteger:create(src_table[i]))
	end
	return ccarray
end

function StringSpilt(str, spilter)
	local result = {}
    string.gsub(str, '[^'..spilter..']+', function(w) table.insert(result, w) end )
    return result
end

function GetTimeStampYMDHMStr(time_stamp)
	local str_temp = GetTimeStampStrYMDHMS(time_stamp)
	local table_ymdhms = StringSpilt(str_temp, ",")
	local result_str = string.format(UITextTable["time_stamp_y_m_d_h_m"]["CN"], table_ymdhms[1], table_ymdhms[2], table_ymdhms[3], table_ymdhms[4], table_ymdhms[5])
	return result_str
end	

function GetTimeStampOfToday(time_stamp)
	return math.mod(time_stamp, 86400)
end

function GetRemainTimeToMidnight(cur_time_stamp, time_zone)
	return (24 - time_zone) * 3600 - GetTimeStampOfToday(cur_time_stamp)
end

function GetTimeStampConvertToDay(time_stamp)
	local day = math.floor(time_stamp / 86400)
	return day
end	

-- return :3333 day
function GetTimeStampConvertToDayText(time_stamp)
	local day = math.floor(time_stamp / 86400)
	local result_str = (day .. UITextTable["time_day"]["CN"])
	return result_str
end	

-- return :22 day 12 hour
function GetTimeStampConvertToDHText(time_stamp)
	local day = math.floor(time_stamp / 86400)
	local hours = math.floor(GetTimeStampOfToday(time_stamp) / 3600)
	local result_str = (day .. UITextTable["time_day"]["CN"])
	result_str = (result_str .. hours .. UITextTable["time_hour"]["CN"])
	return result_str
end	

-- return :148 hour 23 minute
function GetTimeStampConvertToHMText(time_stamp)	
	local hours = math.floor(time_stamp / 3600)
	local minute = math.floor(math.mod(GetTimeStampOfToday(time_stamp), 3600) / 60)			
    local result_str = (hours .. UITextTable["time_hour"]["CN"])	
	result_str = (result_str .. minute .. UITextTable["time_minute"]["CN"])
	return result_str
end

function GetTimeStampConvertToDHMText(time_stamp)
	print ("GetTimeStampConvertToDHMText: " .. time_stamp)
	local day = math.floor(time_stamp / 86400)
	local hours = math.floor(GetTimeStampOfToday(time_stamp) / 3600)
	local minute = math.floor(math.mod(GetTimeStampOfToday(time_stamp), 3600) / 60)		
	local result_str = ""
	if (day ~= 0) then
		result_str = (result_str .. day .. UITextTable["time_day"]["CN"])
		return result_str
	elseif (hours ~= 0) then
		result_str = (hours .. UITextTable["time_hour"]["CN"])
		return result_str
	elseif(minute ~= 0) then
		result_str = (minute .. UITextTable["time_minute"]["CN"])
		return result_str
	end
	return 0
end	

-- return **d**H or **H**m(if day==0)  or **m**s(if day==0 and H==0)
function GetTimeStampConvertToTwoParamterText(time_stamp)
	local day = math.floor(time_stamp / 86400)
	local hour = math.floor(GetTimeStampOfToday(time_stamp) / 3600)
	local minute = math.floor(math.mod(GetTimeStampOfToday(time_stamp), 3600) / 60)	
	local second = math.floor(math.mod(math.mod(GetTimeStampOfToday(time_stamp), 3600) , 60))		
	local result_str = ""
	if (day ~= 0) then
		result_str = string.format("%2d%s%2d%s", day, GetLuaText("time_day"), hour, GetLuaText("time_hour"))
	elseif (hour ~= 0) then
		result_str = string.format("%2d%s%2d%s", hour, GetLuaText("time_hour"), minute, GetLuaText("time_minute"))
	else
		result_str = string.format("%2d%s%2d%s", minute, GetLuaText("time_minute"), second, GetLuaText("time_second"))
	end
	return result_str
end

function ReplaceName(str, name)
	local str_temp, count = string.gsub(str, "%[name%]", name)
	return str_temp
end

function ReplaceNumber(str, number)
	local str_temp, count = string.gsub(str, "%[number%]", number)
	return str_temp
end

function GetReplaceNameTexttable(table_key, name)
	print("ReplaceNameTexttable " .. name)
	return ReplaceName(GetLuaText(table_key), name)
end

function GetReplaceNumberTexttable(table_key, number)
	return ReplaceNumber(GetLuaText(table_key), number)
end

-- return time offset from current time
-- table format: {days = 1, hours = 1, minutes = 1, second = 1}
function getTimeStringFromTimeStamp(last_stamp)
	local current_time_stamp = os.time()
	print(current_time_stamp)
	print(last_stamp)
	print(current_time_stamp - last_stamp)
	local total_second = math.floor((current_time_stamp - last_stamp))
	local result_table = {days = 0, hours = 0, minutes = 0, seconds = 0}
	if total_second <= 0 then
		return result_table
	end

	local seconds = 0
	local minutes = 0
	local hours = 0
	local days = 0

	print(total_second)
	days = math.floor(total_second / (86400))
	total_second = total_second - days * 86400
	print(total_second)
	hours = math.floor(total_second / 3600)
	total_second = total_second - hours * 3600
	print(total_second)
	minutes = math.floor(total_second / 60)
	total_second = total_second - minutes * 60
	print(total_second)
	seconds = total_second

	result_table["days"] = days
	result_table["hours"] = hours
	result_table["minutes"] = minutes
	result_table["seconds"] = seconds
	
	return result_table
end