//global transformation data
float objects_GLOBAL[9]={
0.000000, 0.000000, 0.000000, //rotation
0.000000, 0.000000, 0.000000, //location
1.000000, 1.000000, 1.000000, //size
};

//transformation data
float objects_TRANS[18]={
//data block 0
0.000000, -0.000000, 0.000000,
0.000000, 10.000000, 1.000000,
1.000000, 1.000000, 1.000000,
//data block 1
0.000000, -0.000000, 0.000000,
-2.000000, 12.000000, 1.000000,
1.000000, 1.000000, 1.000000,
};

//point data
float objects_POINT[192]={
//data array 0
1.000000, 1.000000, -1.000000,
1.000000, -1.000000, -1.000000,
-1.000000, -1.000000, -1.000000,
-1.000000, 1.000000, -1.000000,
1.000000, 0.999999, 1.000000,
0.999999, -1.000001, 1.000000,
-1.000000, -1.000000, 1.000000,
-1.000000, 1.000000, 1.000000,
0.733333, 0.733333, -1.000000,
0.733333, -0.733333, -1.000000,
-0.733333, 0.733334, -1.000000,
-0.733333, -0.733333, -1.000000,
0.733333, 0.733333, 1.000000,
-0.733333, 0.733333, 1.000000,
0.733333, -0.733334, 1.000000,
-0.733334, -0.733333, 1.000000,
1.000000, 0.733333, -0.733333,
1.000000, 0.733333, 0.733333,
1.000000, -0.733334, -0.733333,
1.000000, -0.733334, 0.733333,
0.733333, -1.000000, -0.733333,
0.733333, -1.000000, 0.733333,
-0.733334, -1.000000, -0.733333,
-0.733334, -1.000000, 0.733333,
-1.000000, -0.733333, -0.733333,
-1.000000, -0.733333, 0.733333,
-1.000000, 0.733334, -0.733333,
-1.000000, 0.733334, 0.733333,
0.733334, 1.000000, 0.733333,
0.733333, 1.000000, -0.733333,
-0.733333, 1.000000, 0.733333,
-0.733333, 1.000000, -0.733333,
//data array 1
1.000000, 1.000000, -1.000000,
1.000000, -1.000000, -1.000000,
-1.000000, -1.000000, -1.000000,
-1.000000, 1.000000, -1.000000,
1.000000, 0.999999, 1.000000,
0.999999, -1.000001, 1.000000,
-1.000000, -1.000000, 1.000000,
-1.000000, 1.000000, 1.000000,
0.733333, 0.733333, -1.000000,
0.733333, -0.733333, -1.000000,
-0.733333, 0.733334, -1.000000,
-0.733333, -0.733333, -1.000000,
0.733333, 0.733333, 1.000000,
-0.733333, 0.733333, 1.000000,
0.733333, -0.733334, 1.000000,
-0.733334, -0.733333, 1.000000,
1.000000, 0.733333, -0.733333,
1.000000, 0.733333, 0.733333,
1.000000, -0.733334, -0.733333,
1.000000, -0.733334, 0.733333,
0.733333, -1.000000, -0.733333,
0.733333, -1.000000, 0.733333,
-0.733334, -1.000000, -0.733333,
-0.733334, -1.000000, 0.733333,
-1.000000, -0.733333, -0.733333,
-1.000000, -0.733333, 0.733333,
-1.000000, 0.733334, -0.733333,
-1.000000, 0.733334, 0.733333,
0.733334, 1.000000, 0.733333,
0.733333, 1.000000, -0.733333,
-0.733333, 1.000000, 0.733333,
-0.733333, 1.000000, -0.733333,
};

//line data
int objects_LINE[360]={
//data array 0
2, 2, 3,
2, 3, 10,
2, 10, 11,
2, 11, 2,
2, 0, 8,
2, 8, 10,
2, 3, 0,
2, 0, 1,
2, 1, 9,
2, 9, 8,
2, 1, 2,
2, 11, 9,
2, 20, 22,
2, 22, 2,
2, 1, 20,
2, 22, 23,
2, 23, 6,
2, 6, 2,
2, 24, 2,
2, 6, 25,
2, 25, 24,
2, 1, 5,
2, 5, 21,
2, 21, 20,
2, 5, 6,
2, 23, 21,
2, 0, 16,
2, 16, 18,
2, 18, 1,
2, 18, 19,
2, 19, 5,
2, 4, 5,
2, 19, 17,
2, 17, 4,
2, 12, 14,
2, 14, 5,
2, 4, 12,
2, 6, 7,
2, 7, 13,
2, 13, 15,
2, 15, 6,
2, 12, 13,
2, 7, 4,
2, 0, 4,
2, 17, 16,
2, 0, 29,
2, 29, 28,
2, 28, 4,
2, 3, 31,
2, 31, 29,
2, 3, 7,
2, 7, 30,
2, 30, 31,
2, 28, 30,
2, 26, 27,
2, 27, 7,
2, 3, 26,
2, 24, 26,
2, 27, 25,
2, 14, 15,
//data array 1
2, 34, 35,
2, 35, 42,
2, 42, 43,
2, 43, 34,
2, 32, 40,
2, 40, 42,
2, 35, 32,
2, 32, 33,
2, 33, 41,
2, 41, 40,
2, 33, 34,
2, 43, 41,
2, 52, 54,
2, 54, 34,
2, 33, 52,
2, 54, 55,
2, 55, 38,
2, 38, 34,
2, 56, 34,
2, 38, 57,
2, 57, 56,
2, 33, 37,
2, 37, 53,
2, 53, 52,
2, 37, 38,
2, 55, 53,
2, 32, 48,
2, 48, 50,
2, 50, 33,
2, 50, 51,
2, 51, 37,
2, 36, 37,
2, 51, 49,
2, 49, 36,
2, 44, 46,
2, 46, 37,
2, 36, 44,
2, 38, 39,
2, 39, 45,
2, 45, 47,
2, 47, 38,
2, 44, 45,
2, 39, 36,
2, 32, 36,
2, 49, 48,
2, 32, 61,
2, 61, 60,
2, 60, 36,
2, 35, 63,
2, 63, 61,
2, 35, 39,
2, 39, 62,
2, 62, 63,
2, 60, 62,
2, 58, 59,
2, 59, 39,
2, 35, 58,
2, 56, 58,
2, 59, 57,
2, 46, 47,
};

//color data
int objects_COLOR[120]={
//data array 0
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
//data array 1
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
0x3060,
};

//point data array sizes
int objects_POINTDATSZ[2]={
96,
192,
};

//line data array sizes
int objects_LINEDATSZ[2]={
180,
360,
};

//color data array sizes
int objects_COLORDATSZ[2]={
60,
120,
};

//number of meshes
int objects_MESHCNT = 2;
