module(..., package.seeall )

--M = M or {}
M = M or {}
M.name = "BaseFighter"
M.poi = { x=10, y =10 }
M.body = nil
M.__index = M

function M:setPosition( p )
    self.poi = p
end

function M:setName( name )
    self.name = name
end

function M:show()
    print("!!!!! Name:" .. self.name)
    print("!!!!!P :" .. self.poi.x)
end

function M:new(o)
    o = o or {}
    setmetatable(o, self)
    --self.__index = self
    return o
end

function showModuleName()
    print("!!!!!!!!!!!!!!!!!!!!!!!!!!")
    print("Module Name : " .. _NAME)
    print("Package Name : " .. _PACKAGE)
end

function CreateBaseFighter(name )
    local o = M:new()
    --o:setName(name）
    return o
end

--showModuleName()