--[[
-- file:three-max.lua
-- desc:输入3个数字，将这3个数字按从大小的顺序输出
--]]

print("请输入第一个数字：")
local num1 = io.read("*number")
if num1 == nil then
    print("您输入的不是数字")
end

local num2 = io.read("*number")
if num2 == nil then
    print("您输入的不是数字")
end

local num3 = io.read("*number")
if num3 == nil then
    print("您输入的不是数字")
end

local max1,max2,max3

if num1 >= num2 then
    max1 = num1
    max2 = num2
else
    max1 = num2
    max2 = num1
end

if max1 >= num3 then
    if max2 >= num3 then
        max3 = num3
    else
        max3 = max2
        max2 = num3
    end
else
    max3 = max2
    max2 = max1
    max1 = num3
end

print(string.format("排序后从大到小的顺序为：%d %d %d", max1, max2, max3))
