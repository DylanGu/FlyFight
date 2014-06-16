function PleaseCallMe(v)
    if v == 1 then
        return "snowcold"
    elseif v == 2 then
        return "cicigirl"
    end
    return "default"
end

local tt = tt or 1
print("I am load " .. tt)
tt = tt + 1