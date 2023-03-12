#include<iostream>
using namespace std;
#include "fun.h"

//参数设置
const char * movement[5] = {"forward","rotate","buy","sell","destroy"}; //设定5个动作
const int speed[2] = {-2,6}; //设定2个速度

char Map[101][101] = {0}; // 地图的每一点
float A[4][2] = {0}; //机器人的序号及坐标

//工作台参数
int workplace_var[50][4] = {0}; //初始化工作台的参数 不多于50个工作台，每个工作台有5个整型
float workplace_xy[50][2] = {0}; //初始化工作台坐标
int placeorder[50] = {0}; //工作台顺序
int placeAmount[9] = {0}; //每个工作台的数量

//机器人参数
int robot_int[4][2] = {0}; //初始化机器人的参数 一共4个，2个整形
float robot_float[4][8] = {0}; //8个浮点型

int target[4] = {0}; //初始化target目标，每个值代表按顺序输入K的目标 存储在workplace中

int main()
{ //初始化参数
    int fps=0,money=0,K=0; //帧数、金钱、工作台数量
    MapInput(Map,A,placeorder,placeAmount); //地图初始化 载入各个A的坐标
    for(int i = 0;i<50;i++)
    {
        cout << placeorder[i] << " ";
    }
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
            for(int i = 0;i<4;i++) //四个机器
            {
                if(!checkItem(robot_int,i)) //如果没有携带物品
                {
                    int now_target = checkProduce(workplace_var,workplace_xy,placeorder,K,target,i,placeAmount); //决策目标位于now_target,上一级目标位于target[]
                    cout << now_target << "\n";
                }
                else //如果有物品
                {
                    //检查目标是否在范围内
                }
            }
            cout << "OK\n";
            fflush(stdout);
        }
    }

    return 0;
}
