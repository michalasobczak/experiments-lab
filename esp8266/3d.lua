-- ***********************
--  getT
--    sin = 0
--    cos = 1
-- ***********************
getT = function(f, val)
  newEntry = 0;
  -- sin
  if (f == 0) then
    newEntry = 0;
  -- cos
  elseif (f == 1) then
    newEntry = 1;
  end
  return newEntry;
end -- getT


-- ***********************
--  transform3Into2_NEW
-- ***********************
transform3Into2_NEW = function(x,y,z, cx,cy,cz, th_x,th_y,th_z)
  -- ***********************
  --  DATA
  -- ***********************
  -- floating point factor
  factor = 10;
  --
  -- matM
  p1,p2,p3,p4,p5,p6,p7,p8,p9 = 0;
  matM= {0,0,0,0,0,0,0,0,0};
  matM2 = {0,0,0,0,0,0,0,0,0};
  --
  -- getM
  d1 = {
    1,               0,                0                  ,
    0,               100,              100                ,
    0,               100,              100                };
  d2= {
    100,             0,                100                ,
    0,               1,                0                  ,
    100,             0,                100                };
  d3 = {
    100,            100,               0                  ,
    100,            100,               0                  ,
    0,              0,                 1                  };
  --
  -- d4 AND d5
  d4 = {0,0,0};
  d5 = {0,0,0};
  --
  -- matS
  matS = {0,0,0,0,0,0,0,0,0};
  --
  -- matMV
  matMV = {};
  --
  -- getB
  ezDivDz = 0;
  newEntry_x = 0;
  newEntry_y = 0;
  canvasWidthHalf = 160;
  --
  -- ***********************
  --  PROGRAM
  -- ***********************
  --print(string.format("p  => %d %d %d", x, y, z));
  --print(string.format("c  => %d %d %d", cx, cy, cz));
  --print(string.format("th => %d %d %d", th_x, th_y, th_z));
  -- getM
  -- d1
  d1[5] = getT(1, th_x);
  d1[6] = -1 * getT(0, th_x);
  d1[8] = getT(0,th_x);
  d1[9] = getT(1,th_x);
  --print(string.format("d1    => %d %d %d %d %d %d %d %d %d",
  --  d1[1],d1[2],d1[3],d1[4],d1[5],d1[6],d1[7],d1[8],d1[9]));
  -- d2
  d2[1] = getT(1,th_y);
  d2[3] = getT(0,th_y);
  d2[7] = -1*getT(0,th_y);
  d2[9] = getT(1,th_y);
  --print(string.format("d2    => %d %d %d %d %d %d %d %d %d\n",
  --  d2[1],d2[2],d2[3],d2[4],d2[5],d2[6],d2[7],d2[8],d2[9]));
  -- d3
  d3[1] = getT(1,th_z);
  d3[2] = -1*getT(0,th_z);
  d3[4] = getT(0,th_z);
  d3[5] = getT(1,th_z);
  --print(string.format("d3    => %d %d %d %d %d %d %d %d %d\n",
  --  d3[1],d3[2],d3[3],d3[4],d3[5],d3[6],d3[7],d3[8],d3[9]));
  --
  --
  -- matM
  p1 = d1[1]*d2[1] + d1[2]*d2[4] + d1[3]*d2[7];
  p2 = d1[1]*d2[2] + d1[2]*d2[5] + d1[3]*d2[8];
  p3 = d1[1]*d2[3] + d1[2]*d2[6] + d1[3]*d2[9];
  p4 = d1[4]*d2[1] + d1[5]*d2[4] + d1[6]*d2[7];
  p5 = d1[4]*d2[2] + d1[5]*d2[5] + d1[6]*d2[8];
  p6 = d1[4]*d2[3] + d1[5]*d2[6] + d1[6]*d2[9];
  p7 = d1[7]*d2[1] + d1[8]*d2[4] + d1[9]*d2[7];
  p8 = d1[7]*d2[2] + d1[8]*d2[5] + d1[9]*d2[8];
  p9 = d1[7]*d2[3] + d1[8]*d2[6] + d1[9]*d2[9];
  matM[1] = p1;
  matM[2] = p2;
  matM[3] = p3;
  matM[4] = p4;
  matM[5] = p5;
  matM[6] = p6;
  matM[7] = p7;
  matM[8] = p8;
  matM[9] = p9;
  --print(string.format("matM  => %d %d %d %d %d %d %d %d %d\n",
  --  matM[1],matM[2],matM[3],matM[4],matM[5],matM[6],matM[7],matM[8],matM[9]));
  --
  -- matM2
  p1 = matM[1]*d3[1] + matM[2]*d3[4] + matM[3]*d3[7];
  p2 = matM[1]*d3[2] + matM[2]*d3[5] + matM[3]*d3[8];
  p3 = matM[1]*d3[3] + matM[2]*d3[6] + matM[3]*d3[9];
  p4 = matM[4]*d3[1] + matM[5]*d3[4] + matM[6]*d3[7];
  p5 = matM[4]*d3[2] + matM[5]*d3[5] + matM[6]*d3[8];
  p6 = matM[4]*d3[3] + matM[5]*d3[6] + matM[6]*d3[9];
  p7 = matM[7]*d3[1] + matM[8]*d3[4] + matM[9]*d3[7];
  p8 = matM[7]*d3[2] + matM[8]*d3[5] + matM[9]*d3[8];
  p9 = matM[7]*d3[3] + matM[8]*d3[6] + matM[9]*d3[9];
  matM2[1] = p1;
  matM2[2] = p2;
  matM2[3] = p3;
  matM2[4] = p4;
  matM2[5] = p5;
  matM2[6] = p6;
  matM2[7] = p7;
  matM2[8] = p8;
  matM2[9] = p9;
  --print(string.format("matM2 => %d %d %d %d %d %d %d %d %d\n",
  --  matM2[1],matM2[2],matM2[3],matM2[4],matM2[5],matM2[6],matM2[7],matM2[8],matM2[9]));
  --
  -- d4 AND d5
  -- d4
  d4[1] = x;
  d4[2] = y;
  d4[3] = z;
  --// d5
  d5[1] = cx;
  d5[2] = cy;
  d5[3] = cz;
  --
  -- ***********************
  --  matS
  -- ***********************
  matS[1] = d4[1]-d5[1];
  matS[2] = d4[2]-d5[2];
  matS[3] = d4[3]-d5[3];
  --print(string.format("matS  => %d %d %d %d %d %d %d %d %d\n",
  --  matS[1],matS[2],matS[3],matS[4],matS[5],matS[6],matS[7],matS[8],matS[9]));
  --
  -- ***********************
  --  matMV
  -- ***********************
  -- => matMV = f(matM2, matS)
  p1 = matM2[1]*matS[1] + matM2[2]*matS[2] + matM2[3]*matS[3];
  p2 = matM2[4]*matS[1] + matM2[5]*matS[2] + matM2[6]*matS[3];
  p3 = matM2[7]*matS[1] + matM2[8]*matS[2] + matM2[9]*matS[3];
  matMV[1] = p1;
  matMV[2] = p2;
  matMV[3] = p3;
  --print(string.format("matMV => %d %d %d\n",matMV[1],matMV[2],matMV[3]));
  --
  -- ***********************
  --  getB
  -- ***********************
  ezDivDz = (-700*factor) / matMV[3];
  newEntry_x = -1*(matMV[1]*ezDivDz)/factor + canvasWidthHalf;
  newEntry_y = (matMV[2]*ezDivDz)/factor;

  --print(string.format("result => %d, %d\n", newEntry_x, newEntry_y));

  -- ***********************
  --  return
  -- ***********************
  return {newEntry_x,newEntry_y};
end -- transform3Into2_NEW


-- ***********************
--  MAIN
-- ***********************
px=250
py=40
pz=1500
cx=200
cy=335
cz=-250
tx=0
ty=0
tz=0

local x = os.clock()
local s = 0
for i=1,1000 do
  result = transform3Into2_NEW(px,py,pz, cx,cy,cz, tx,ty,tz);
end
print(string.format("elapsed time: %.2f\n", os.clock() - x))
