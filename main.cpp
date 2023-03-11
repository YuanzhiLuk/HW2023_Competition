#include<iostream>
using namespace std;

void MapInput(); //地图的输入 以及机器人的初始化
//void MapOutput();
void workplace(int K); //工作台参数的输入
void robot_var(); //机器人参数的输入


bool readUntilOK(); //读取到OK
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
    MapInput(); //地图初始化 载入各个A的坐标
    if(readUntilOK())
    {
        cout << "OK" << "\n";
        fflush(stdout);
    }//完成初始化
    while(scanf("%d",&fps)!=EOF) //进行每一帧的操作 并且输入第一个判断是否为EOF
    {
        cin >> money; //第一行输入两个整数
        cin >> K; //场上工作台数量
        workplace(K); //输入工作台参数
        robot_var(); //输入机器人参数
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

bool readUntilOK()
{
    char aOK[100]; //存储位置
    while(fgets(aOK,sizeof(aOK),stdin)) //输入字符
    {
        if(aOK[0]=='O'&&aOK[1]=='K') //如果输入字符为OK 返回真
        {
            return true;
        }
    }
    return false;
}

void MapInput() //输入地图
{
    int Anumber = 0;
    for(int i = 0;i<100;i++)
    {
        for(int j = 0;j<100;j++) //对每一个点进行输入
        {
            cin >> Map[i][j]; //将地图存储在Map
            if(Map[i][j]=='A') //如果此时
            {
                A[Anumber][0] = (100-i)/2-0.25; //转换成坐标形式 y
                A[Anumber][1] = (j+1)/2-0.25; // x
                Anumber++; //下一个点
            }
        }
    }
    //cout << A[2][0] << " " << A[2][1] << "\n";
}

// void MapOutput()
// {
//     for(int i = 0;i<100;i++)
//     {
//         for(int j = 0;j<100;j++)
//         {
//             cout << Map[i][j];
//         }
//         cout << endl;
//     }
// }

void workplace(int K) //输入工作台参数
{
    for(int i = 0;i<K;i++)
    {
        cin >> workplace_var[i][0] >> workplace_xy[i][0] >> workplace_xy[i][1]; //输入前三个数
        cin >> workplace_var[i][1] >> workplace_var[i][2] >> workplace_var[i][3]; //输入后三个数
    }
}

void robot_var()
{
    for(int i = 0;i<4;i++)
    {
        cin >> robot_int[i][0] >> robot_int[i][1];
        for(int j = 0;j<8;j++)
        {
            cin >> robot_float[i][j];
        }
    }
}
