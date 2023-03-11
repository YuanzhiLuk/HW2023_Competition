#include<iostream>
using namespace std;
#include "fun.h"


char Map[101][101] = {0}; // 地图的每一点
float A[4][2] = {0}; //机器人的序号及坐标

int workplace_var[50][4] = {0}; //初始化工作台的参数 不多于50个工作台，每个工作台有5个整型
float workplace_xy[50][2] = {0}; //初始化工作台坐标

int robot_int[4][2] = {0}; //初始化机器人的参数 一共4个，2个整形
float robot_float[4][8] = {0}; //8个浮点型

int target[4] = {0}; //初始化target目标，每个值代表按顺序输入K的目标 存储在workplace中

int main()
{ //初始化参数
    int fps=0,money=0,K=0; //帧数、金钱、工作台数量
    MapInput(Map,A); //地图初始化 载入各个A的坐标
    if(readUntilOK())
    {
        cout << "OK" << "\n";
        fflush(stdout);
    }//完成初始化
    while(scanf("%d",&fps)!=EOF) //进行每一帧的操作 并且输入第一个判断是否为EOF
    {
        cin >> money; //第一行输入两个整数
        cin >> K; //场上工作台数量
        workplace(workplace_var,workplace_xy,K); //输入工作台参数
        robot_var(robot_int,robot_float); //输入机器人参数
        if(readUntilOK())
        {
            cout << fps << "\n";
            fflush(stdout);
            //输出动作
            cout << "forward 0 6\nrotate 0 3.14159";
            cout << "OK\n";
            fflush(stdout);
        }
    } 

    return 0;
}
