#ifndef FUN_H
#define FUN_H

// 初始化函数
void robot_var(int (&robot_int)[4][2],float (&robot_float)[4][8]); //输入机器人参数
void workplace(int (&workplace_var)[50][4],float (&workplace_xy)[50][2],int K); //输入工作台参数
void MapInput(char (&Map)[101][101],float (&A)[4][2],int (&placeorder)[50],int (&placeAmount)[9]); //输入地图
bool readUntilOK();

//动作函数
bool checkItem(int (&robot_int)[4][2],int w); //检查是否有目标
int checkProduce(int workplace_var[][4],float workplace_xy[][2],int placeorder[50],int K,int (&target)[4],int w,int placeAmount[9]); //从7到1检查生产线的需求 返回目标需求
int checkMaterial(int workplace_var[][4],int placeorder[50],int i); //检查原材料缺失情况


#endif
