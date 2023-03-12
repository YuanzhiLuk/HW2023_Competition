#include<iostream>
#include<algorithm>
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

void MapInput(char (&Map)[101][101],float (&A)[4][2],int (&placeorder)[50],int (&placeAmount)[9]) //输入地图
{
    int Anumber = 0;
    int workplaceIndex = 0;
    for(int i = 0;i<100;i++)
    {
        for(int j = 0;j<100;j++) //对每一个点进行输入
        {
            cin >> Map[i][j]; //将地图存储在Map
            if(Map[i][j]=='A')
            {
                A[Anumber][0] = (100-i)/2-0.25; //转换成坐标形式 y
                A[Anumber][1] = (j+1)/2-0.25; // x
                Anumber++; //下一个点   
            }
            else if(Map[i][j]=='.') ;
            else
            {
                placeorder[workplaceIndex] = int(Map[i][j])-48;
                workplaceIndex++;
                placeAmount[int(Map[i][j])-48-1]+=1; //此工作台数量加一
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

bool checkItem(int (&robot_int)[4][2],int w) //第w个机器人
{
    if(robot_int[w][1]==0) return false; //如果没有物品 返回false
    return true;
}


int checkMaterial(int workplace_var[][4],int placeorder[50],int i) //第i个工作台的参数 检查原材料缺失情况 返回的是缺失的最大的工作台
{
    int mat[7] = {0,0,0,3,5,6,112}; //每个工作台的原材料总共需求
    int loss = mat[placeorder[i]-1] - workplace_var[i][2]; //loss表示第i个工作台的缺失情况
    int n = 0; //n表示loss应右移多少位到达零,即从缺失数最大的开始寻找
    while(loss!=0)
    {
        loss>>=1; //向右位移
        n+=1;
    }
    return n-1; //返回缺失的最大工作台 如果返回-1 说明不缺原材料(123工作台) checkProduce函数将返回0
}


int checkProduce(int workplace_var[][4],float workplace_xy[][2],int placeorder[50],int K,int (&target)[4],int w,int placeAmount[9]) //没有target时 寻找target 并返回target w表示机器人编号
// target[]包含的是机器人target的目标上一级
{
    target[w] = find(placeorder,placeorder+K+1,8)-placeorder; //target的上一级设为第8工作台的序号
    for(int j = 7;j>0;j--) //从7-1寻找
    {
        int count = 0; //计数器 负责遍历某一级别工作台的次数
        for(int i = 0;i<K;i++) //遍历order
        {
            if(placeorder[i] == j) //从7到1找 检查能否设定为target
            {
                count += 1; //找到一个此级别工作台
                if(workplace_var[i][3]==1)
                {
                    return i; //如果有产品输出 设为目标
                }
                //相当于else
                if(count==placeAmount[j-1]) //如果没有产品 无论有无生产 只要没有此级别工作台了 就找它的原料
                {
                    target[w] = i;
                    if(checkMaterial(workplace_var,placeorder,i)==-1) //如果返回-1说明不缺原材料 为123工作台 返回目标工作台
                    {
                        return j;
                    }//否则重置j继续遍历
                    j = checkMaterial(workplace_var,placeorder,i); //返回要寻找的最大工作台j
                    i = 0; //从零遍历
                    count = 0; //初始化计数器
                }//否则 没有产品 有此级别的工作台就继续遍历 跳过这个工作台  要是没有这个级别的工作台 即设定1为目标工作台等待工作台生产
            }
        }
        return j;
    }
    return -1;
}


