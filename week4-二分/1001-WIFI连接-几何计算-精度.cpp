/*
WiFi 连接
Description

假设手机在连接 WiFi 时总是连接最近的路由器, 因此拿着手机移动时, 随着与每个路由器距离的变化会进行路由器(相同SSID)连接的转换.

畅春园宿舍楼的每一间宿舍都安装了一个路由器, 路由器安装的具体位置不固定, Alice 拿着手机在宿舍楼附近移动, 现在他想知道移动的过程中共进行了多少次路由器连接的转换.

为了简化问题, 现在假设 Alice 每次选择一个起点和一个终点, 移动的路线为直线.


Input
输入的第一行为两个正整数 n, m (n\in [3,50], m\in [2,50])n,m(n∈[3,50],m∈[2,50]), nn 表示 Alice 移动的可能起点或终点的坐标个数, mm 表示宿舍楼安装的路由器个数.

随后 nn 行, 每一行两个整数 x, y \in [0,1000]x,y∈[0,1000], 表示起点或终点的坐标.

接下来 mm 行,每一行两个整数 x, y \in [0,1000]x,y∈[0,1000], 表示路由器位置的坐标.

接下来一行为一个整数 kk, 表示 Alice 实验的次数.

后续 kk 行, 每一行两个正整数 a, b \in [1, n]a,b∈[1,n], aa 表示起点坐标的序号, bb 表示终点坐标的序号. (序号指的是前面输入起点和终点坐标的顺序)


Output
对于 Alice 的每次实验, 输出单独的一行, 表示实验过程中路由器连接转换的次数.


Sample Input 1 

4 4
0 2
1 3
1 0
2 0
1 2
1 1
2 2
2 1
4
1 2
1 3
1 4
3 4
Sample Output 1

0
1
2
1
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1010; 
int n,m;
int flag[N];
int times = 0;
vector<int>df_times;

struct P
{
    double x;
    double y;
}p[N],q[N];

struct D
{
    double d;
    double x;
    double y;
    double d0;
    int num;
}dis[N];

void dis_P2L(int point,double A,double B,double C,int a,int b)
{
    dis[point].d = abs((A * q[point].x + B * q[point].y + C)/sqrt(A * A + B * B));
    dis[point].num = point;
    dis[point].x = (B*B*q[point].x-A*B*q[point].y-A*C)/(A*A+B*B);
    dis[point].y = (A*A*q[point].y-A*B*q[point].x-B*C)/(A*A+B*B);
    dis[point].d0 = sqrt((dis[point].x - p[a].x) * (dis[point].x - p[a].x) + (dis[point].y - p[a].y) * (dis[point].y - p[a].y));
    if(p[a].x != p[b].x)
    {
        if((dis[point].x - p[a].x)/abs((dis[point].x - p[a].x)) == (dis[point].x - p[b].x)/abs((dis[point].x - p[b].x))) flag[dis[point].num ] = 1;
    }
    else
    {
        if((dis[point].y - p[a].y)/abs((dis[point].y - p[a].y)) == (dis[point].y - p[b].y)/abs((dis[point].y - p[b].y))) flag[dis[point].num ] = 1;
    }
}

double dist(double x1,double x2,double y1,double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) ;
}

bool com2(const D& a,const D& b)
{
    return a.d0 < b.d0;
}

void change_times(int a,int b)
{
    double A,B,C;
    A = (p[b].y - p[a].y);
    B = - (p[b].x - p[a].x);
    C = p[a].y * (p[b].x - p[a].x) - p[a].x * (p[b].y - p[a].y);

    int link,ori_link;
    double ori_dis = 100000200000;

    for(int i = 0; i < m; i ++)dis_P2L(i,A,B,C,a,b);

    sort(dis,dis+m,com2);    

    for(int i = 0; i < m; i ++)
    {
        //cout << i <<' ' << link <<' ' <<dist(p[a].x,q[dis[i].num].x,p[a].y,q[dis[i].num].y) << ' '<<dis[i].d<< endl;
        double temp_dis1 = dist(p[a].x,q[dis[i].num].x,p[a].y,q[dis[i].num].y);
        if(ori_dis > temp_dis1)
        {   
            ori_dis = temp_dis1;
            link = i;
        }
    }

    ori_link = link;
    //flag[dis[link].num] = 1;
    int orinum = 0;
    while(flag[dis[orinum].num]) orinum ++;

    double temp_x,temp_y;
    if(p[a].x != p[b].x){
        double x_gap = (p[b].x - p[a].x)/100000;
        for(int i = 0; i < 100000; i ++)
        {   
            temp_x = p[a].x + x_gap * (i + 1);
            temp_y = p[a].y + (temp_x - p[a].x) * (-A/B);
            //if(i<300)cout <<i << ' '<< temp_x << ' ' << temp_y <<' ' <<  p[a].x <<' ' << p[a].y <<' '<< dis[orinum].x <<' ' << dis[orinum].y << ' ' <<  p[b].x <<' ' << p[b].y << endl;
            ori_dis = dist(temp_x,q[dis[link].num].x,temp_y,q[dis[link].num].y);
            for(int j = 0; j < m; j ++)
            {
                //if(flag[dis[j].num]!=1)continue;
                double t_d = dist(temp_x,q[dis[j].num].x,temp_y,q[dis[j].num].y);
                if(ori_dis > t_d)
                {
                    //cout << i << ' '<< times <<' ' << link <<' ' << ori_dis <<' '<< dist(temp_x,q[dis[j].num].x,temp_y,q[dis[j].num].y)<<' '<< temp_x << ' ' << temp_y <<' ' <<  p[a].x <<' ' << p[a].y <<' '<< dis[orinum].x <<' ' << dis[orinum].y << ' ' <<  p[b].x <<' ' << p[b].y << endl;
                    ori_dis = t_d;
                    link = j;
                }
            }
            if(ori_link!=link)
            {
                times++;
                ori_link = link;
                //cout << 1 << ' ' << dist(p[a].x,p[b].x,p[a].y,p[b].y) <<' '<<dis[link].d0<<' ' << link << q[dis[link].num].x << ' '<<q[dis[link].num].y << times <<  endl;
            }
        }
    }
    else
    {
        double y_gap = (p[b].y - p[a].y)/100;
        for(int i = 0; i < 100; i ++)
        {
            temp_x = p[a].x;
            temp_y = p[a].y + y_gap * (i + 1);
            ori_dis = dist(temp_x,q[dis[link].num].x,temp_y,q[dis[link].num].y);
            for(int j = 0; j < m; j ++)
            {
                //if(flag[dis[j].num]!=1)continue;
                double t_d = dist(temp_x,q[dis[j].num].x,temp_y,q[dis[j].num].y);
                if(ori_dis > t_d)
                {
                    ori_dis = t_d;
                    link = j;
                }
            }
            if(ori_link!=link)
            {
                times++;
                ori_link = link;
            }
        }
    }
}

int main()
{
    
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; i ++)scanf("%lf %lf",&p[i].x,&p[i].y);
    for(int i = 0; i < m; i ++)scanf("%lf %lf",&q[i].x,&q[i].y);

    int k,x,y;
    scanf("%d",&k);
    for(int i = 0; i < k; i ++)
    {
        times = 0;
        for(int j = 0;j < m;j ++)flag[j] = 0;
        scanf("%d %d",&x,&y);
        change_times(x-1,y-1);
        df_times.push_back(times);
    }
    for(int i = 0; i < k; i ++)printf("%d ",df_times[i]);
    //int o;
    //scanf("%d",&o);

    return 0;
}