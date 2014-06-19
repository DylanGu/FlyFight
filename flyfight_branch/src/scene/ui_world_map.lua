require("script/scene/main_map_controller")
require("script/config/common_func")
require("script/ui/ui_message_tips")
require("script/city_map/city_map_contants")

local glayer_wrapper
local world_map_layer


local function endWorldMap()
	glayer_wrapper:removeFromParentAndCleanup(true)
	CCSpriteFrameCache:sharedSpriteFrameCache():removeSpriteFramesFromFile("ui/ui_world_map/ui_world_map_ex.plist")

	local png_fullPath = CCFileUtils:sharedFileUtils():fullPathForFilename("ui/ui_world_map/ui_world_map_ex.pvr.ccz")
	CCTextureCache:sharedTextureCache():removeTextureForKey(png_fullPath)

	local png_fullPath = CCFileUtils:sharedFileUtils():fullPathForFilename("textures/map/map_bg.pvr.ccz")
	CCTextureCache:sharedTextureCache():removeTextureForKey(png_fullPath)

	for idx = 0, GetCityMapCount() - 1 do	
		local png_fullPath = CCFileUtils:sharedFileUtils():fullPathForFilename("ui/ui_world_map/country_0" .. idx .. ".png")
		CCTextureCache:sharedTextureCache():removeTextureForKey(png_fullPath)
	end
end

local function getCountryID(country_name)
	local firstidx, lastidx, value = string.find(country_name, ".+_([%d]+)")
	return tonumber(value)
end

local  function onTouchCountry(sender, event_type )
  if event_type == TOUCH_EVENT_ENDED then

  	print("onTouchCountry")
  	
	local country_button = tolua.cast(sender,"UIImageView")
	local country_id = getCountryID(country_button:getName())
	assert(country_id >= 0 and country_id < 6)
	print(country_id)
	if DataManager:GetInstance():user_info():get_current_city_map_id() == country_id then
		endWorldMap()
	elseif QueryNextMissionShoudBeTodo() < GetCityMapUnlockMissionIdById(country_id) then 
		--TODO Add lock tips
		local layer = CreateMessageTips(GetLuaText("main_menu_click_tips"))
		--local parent_layer = GetMainMenuLayer()
		glayer_wrapper:addChild(layer)
	else
		taomee.city.CityController:GetInstance():SendSwithCityMapRequest(country_id)
	end
	
  end
end


local function addName(country_button)
	CCSpriteFrameCache:sharedSpriteFrameCache():addSpriteFramesWithFile("ui/ui_world_map/ui_world_map_ex.plist")
	
	local country_id = getCountryID(country_button:getName())
	local name = GetCityMapNameById(country_id)

	local sprite_right = CCSprite:createWithSpriteFrameName("map_alphabox.png");
	sprite_right:setAnchorPoint(ccp(0,0.5))
	sprite_right:setPosition(0, -26)
	country_button:getRenderer():addChild(sprite_right)

	local sprite_left = CCSprite:createWithSpriteFrameName("map_alphabox.png");
	sprite_left:setAnchorPoint(ccp(1,0.5))
	sprite_left:setFlipX(true)
	sprite_left:setPosition(1, -26)
	country_button:getRenderer():addChild(sprite_left)

	-- label
	local label = CCLabelBMFont:create(name, "ui/font/font_2.fnt")
	label:setScale(0.6)
	label:setPosition(0, -28)
	country_button:getRenderer():addChild(label)

	-- add current map head
	if DataManager:GetInstance():user_info():get_current_city_map_id() == country_id then
		local role_id = DataManager:GetInstance():user_info():role_id()
		local role_img = CCSprite:createWithSpriteFrameName(string.format("map_protagonist_%d.png", role_id))
		local arrow_img = CCSprite:createWithSpriteFrameName("arrow_l.png")

		role_img:setPosition(ccp(0, 30))
		arrow_img:setPosition(ccp(0, role_img:getContentSize().height + 20))
		arrow_img:setRotation(-90)
		local move_array = CCArray:create()
		move_array:addObject(CCMoveBy:create(0.4, ccp(0, 10)))
		move_array:addObject(CCMoveBy:create(0.4, ccp(0, -10)))
		arrow_img:runAction(CCRepeatForever:create(CCSequence:create(move_array)))
							
		country_button:getRenderer():addChild(role_img)
		country_button:getRenderer():addChild(arrow_img)
	end
end

function CreateWorldMapUI()

	world_map_layer = CCSGUIReader:shareReader():widgetFromJsonFile("ui/ui_world_map.json")
	local layer_wrapper = UILayer:create()
	layer_wrapper:addWidget(world_map_layer)

	local image_background = tolua.cast(world_map_layer:getChildByName("map_bg"), "UIImageView")
	local bg_tex_path = "textures/map/map_bg.pvr.ccz"
	image_background:loadTexture(bg_tex_path,UI_TEX_TYPE_LOCAL)

	local country_button = {}
	for idx = 0, GetCityMapCount() - 1 do	
		print(idx)
		local country_name = "Image_Country_"..idx
		country_button[idx] = tolua.cast(world_map_layer:getChildByName(country_name), "UIImageView")
		assert(country_button[idx])

		local polygonImageView = taomee.UIPolygonImageView:create()
		polygonImageView:loadTexture("ui/ui_world_map/country_0"..idx..".png")
		polygonImageView:setZOrder(country_button[idx]:getZOrder())
		polygonImageView:setPosition(country_button[idx]:getPosition())
		polygonImageView:setAnchorPoint(country_button[idx]:getAnchorPoint())
		polygonImageView:setTouchEnabled(true)
		--polygonImageView:registerTouchEventScriptHandle(onTouchCountry)
		polygonImageView:setName(country_name)
		world_map_layer:addChild(polygonImageView)

		country_button[idx]:removeFromParentAndCleanup(true)
	
		country_button[idx] = polygonImageView
		country_button[idx]:registerTouchEventScriptHandle(onTouchCountry)
		-- can touch
		if QueryNextMissionShoudBeTodo() >= GetCityMapUnlockMissionIdById(idx) then
			country_button[idx]:setColor(ccc3(255,255,255))
			addName(country_button[idx])

		else
			country_button[idx]:setColor(ccc3(120,120,120))
			country_button[idx]:setPressEffectType(taomee.kPolygonImageEffectTypeDarkLight);
		end
	end

	--showNextArrow(world_map_layer)
	
	--[[
	local polygonImageView = taomee.UIPolygonImageView:create()
	polygonImageView:loadTexture("ui/ui_world_map/test7.png")
	polygonImageView:setZOrder(10000)
	polygonImageView:setPosition(ccp(800, 300))
	polygonImageView:setTouchEnabled(true)
	polygonImageView:registerTouchEventScriptHandle(onTouchCountry)
	world_map_layer:addChild(polygonImageView)
	]]
  
	-- ÏµÍ³²Ëµ¥
	--OpenMainMenu()
	return layer_wrapper
end

local function onBackButtonTouched(sender, event_type)
	if event_type == TOUCH_EVENT_ENDED and glayer_wrapper ~= nil then
		endWorldMap()
	end
end

function bindElements()
	local button_back = tolua.cast(world_map_layer:getChildByName("Button_back"), "UIButton")
	button_back:registerTouchEventScriptHandle(onBackButtonTouched)
	button_back:setPressedActionEnabled(true)
	button_back:setSoundEffectFilePath(QueryCloseButtonSoundFilePath())
end

function EnterWorldMap()
	print("EnterWorldMap")
	glayer_wrapper = CreateWorldMapUI()	

	bindElements();

	--taomee.SoundManager:GetInstance():PlayBackgroundMusic(QueryWorldMapBgm(), true)		
	taomee.city.CityController:GetInstance():AddUILayerOnCity(glayer_wrapper)
end
