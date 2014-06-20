module(..., package.seeall )

--M = M or {}
Actor = Actor or {}
Actor.name = "BaseActor"
Actor.poi = { x=10, y =10 }
Actor.__index = Actor

function Actor:setPosition( p )
    self.poi = p
end

function Actor:setName( name )
    self.name = name
end

function Actor:show()
    print("!!!!! Name:" .. self.name)
    print("!!!!!P :" .. self.poi.x)
end

function Actor:new(o)
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

function CreateActor(name )
    local o = Actor:new()
    --o:setName(name）
    return o
end

showModuleName()