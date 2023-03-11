#include<iostream>
using namespace std;

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

void MapInput(char (&Map)[101][101],float (&A)[4][2]) //输入地图
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

void workplace(int (&workplace_var)[50][4],float (&workplace_xy)[50][2],int K) //输入工作台参数
{
    for(int i = 0;i<K;i++)
    {
        cin >> workplace_var[i][0] >> workplace_xy[i][0] >> workplace_xy[i][1]; //输入前三个数
        cin >> workplace_var[i][1] >> workplace_var[i][2] >> workplace_var[i][3]; //输入后三个数
    }
}

void robot_var(int (&robot_int)[4][2],float (&robot_float)[4][8])
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
