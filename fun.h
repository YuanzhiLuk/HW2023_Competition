#ifndef FUN_H
#define FUN_H

void robot_var(int (&robot_int)[4][2],float (&robot_float)[4][8]);
void workplace(int (&workplace_var)[50][4],float (&workplace_xy)[50][2],int K); //输入工作台参数
void MapInput(char (&Map)[101][101],float (&A)[4][2]); //输入地图
bool readUntilOK();

#endif
