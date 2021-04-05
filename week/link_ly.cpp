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
    //cout <<  dis[link].x <<' ' << dis[link].y << endl;

    ori_link = link;
    //flag[dis[link].num] = 1;
    int orinum = 0;
    while(flag[dis[orinum].num]) orinum ++;

    double temp_x,temp_y;
    if(p[a].x != p[b].x){
        double x_gap = (dis[orinum].x - p[a].x)/100;
        for(int i = 0; i < 100; i ++)
        {   
            temp_x = p[a].x + x_gap * ((p[b].x - p[a].x)/abs(p[b].x - p[a].x)) * (i + 1);
            temp_y = p[a].y + (temp_x - p[a].x) * (-A/B);
            //cout <<i << ' '<< temp_x << ' ' << temp_y <<' ' <<  p[a].x <<' ' << p[a].y <<' '<< dis[orinum].x <<' ' << dis[orinum].y << ' ' <<  p[b].x <<' ' << p[b].y << endl;
            ori_dis = dist(temp_x,q[dis[link].num].x,temp_y,q[dis[link].num].y);
            for(int j = 0; j < m; j ++)
            {
                if(flag[dis[j].num]!=1)continue;
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
                //cout << 1 << ' ' << dist(p[a].x,p[b].x,p[a].y,p[b].y) <<' '<<dis[link].d0<<' ' << link << q[dis[link].num].x << ' '<<q[dis[link].num].y << times <<  endl;
            }
        }
    }
    else
    {
        double y_gap = (q[dis[orinum].num].y - p[a].y)/100;
        for(int i = 0; i < 100; i ++)
        {
            temp_x = p[a].x;
            temp_y = p[a].y + y_gap * ((p[b].y - p[a].y)/abs(p[b].y - p[a].y)) * (i + 1);
            ori_dis = dist(temp_x,q[dis[link].num].x,temp_y,q[dis[link].num].y);
            for(int j = 0; j < m; j ++)
            {
                if(flag[dis[j].num]!=1)continue;
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
    
    for(int k = 0; k < link; k ++)flag[dis[k].num] = 1;

    for(int i = 0; i < m; i ++)
    {
        ori_link = link;

        if(dist(p[a].x,p[b].x,p[a].y,p[b].y) < dis[i].d0)
        {
            double temp_x,temp_y;
            if(p[a].x != p[b].x){
                double x_gap = (p[b].x - dis[i-1].x)/100;
                for(int ii = 0; ii < 100; ii ++)
                {
                    temp_x = dis[i-1].x + x_gap * ((p[b].x - p[a].x)/abs(p[b].x - p[a].x)) * (ii + 1);
                    temp_y = dis[i-1].y + (temp_x - p[a].x) * (-A/B);
                    //cout <<i << ' '<< temp_x << ' ' << temp_y <<' ' <<  dis[i-1].x <<' ' << dis[i-1].y <<' '<< p[b].x <<' ' << p[b].y << ' '  << endl;
                    ori_dis = dist(temp_x,q[dis[link].num].x,temp_y,q[dis[link].num].y);
                    for(int j = i; j < m; j ++)
                    {
                        if(flag[dis[j].num]==1)continue;
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
                        //cout << 3 << ' ' <<  dist(p[a].x,p[b].x,p[a].y,p[b].y) <<' '<<dis[link].d0<<' ' << link << q[dis[link].num].x << ' '<<q[dis[link].num].y << endl;
                    }
                }
            }
            else
            {
                double y_gap = (p[a].y - dis[i-1].y)/100;
                for(int ii = 0; ii < 100; ii ++)
                {
                    
                    temp_x = p[i-1].x;
                    temp_y = p[i-1].y + y_gap * ((p[b].y - p[a].y)/abs(p[b].y - p[a].y)) * (ii + 1);
                    ori_dis = dist(temp_x,q[dis[link].num].x,temp_y,q[dis[link].num].y);
                    for(int j = i; j < m; j ++)
                    {
                        if(flag[dis[j].num]==1)continue;
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
                        //cout << 4 << ' ' <<  dist(p[a].x,p[b].x,p[a].y,p[b].y) <<' '<<dis[link].d0<<' ' << link << q[dis[link].num].x << ' '<<q[dis[link].num].y << endl;
                    }
                }
            }
            break;
        }
        
        if(flag[dis[i].num]==1)continue;
 
        double temp_dis2 = dist(dis[i].x,q[dis[link].num].x,dis[i].y,q[dis[link].num].y);

        if(dis[i].d <= temp_dis2)
        {
            ori_dis = dis[i].d;
            link = i;
        }
        else
        {
            ori_dis = temp_dis2;
        }

        int j = i;
        while(j < m)
        {
            //cout << j << ' ' << link << ' ' << times << ' ' <<  dis[j].x << ' ' << dis[j].y << ' '<< dis[i].d << ' ' <<  dist(dis[i].x,q[dis[j].num].x,dis[i].y,q[dis[j].num].y) <<' '<< ori_dis << ' '<<flag[dis[j].num] << endl;

            if(flag[dis[j].num]==1)
            {
                j ++;
                continue;
            }
 
            double temp_dis3 = dist(dis[i].x,q[dis[j].num].x,dis[i].y,q[dis[j].num].y);
            if(ori_dis > temp_dis3)
            {
                ori_dis = temp_dis3;
                link = j;
            }
            j++;
        }
        for(int k = i; k < link; k ++)flag[dis[k].num] = 1;
        if(link!=ori_link)times++;

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
    int o;
    scanf("%d",&o);


    return 0;
}