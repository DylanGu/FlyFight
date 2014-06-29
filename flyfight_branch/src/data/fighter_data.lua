--[[

 required int32 sid = 1[default = 0];
 required int32 eid = 2[default = 0];
 required ePart part = 3[default = kPart_Null];
 required int32 level = 4[default = 1];
 required eQuality quality = 5[default = kQuality_White];
 required eQualityRank quaRank = 6[default = kQuaRank_0];
 
 optional int32 hp = 7;
 optional int32 defence = 8;
 optional int32 atk = 9;
 optional int32 atkSpeed = 10;

--]]

Key{
    eid = 1, part = 2, level = 3, quality = 4, qualityRank = 5, hp = 6, defence = 7, atk = 8, atkSpeed = 9, name = 10
}

Entry{
    1001,    1,         1,         1,           1,              1000,   100,          100,      10, "暴风狮鹫"
}

Entry{
    1002,    1,         1,         1,           1,              2000,   80,          80,      12, "尖峰零式"
}
