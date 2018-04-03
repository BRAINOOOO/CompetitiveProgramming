/*
algo used dijkstra 

it is direct dijkstra but add the cost of each node you passed by except for the des node
*/
#include <bits/stdc++.h>
#define sz(v)   ((int)(v).size())
#define  all(v)    ((v).begin()),((v).end())
#define  allr(v)    ((v).rbegin()),((v).rend())
#define   pb         push_back
#define   mp         make_pair
#define   mt         make_tuple
#define    clr(v,d)      memset( v, d ,sizeof(v))
#define   angle(n)      atan2((n.imag()),(n.real()))
#define   vec(a,b)       ((b)-(a))
#define   length(a)      hypot( (a.imag()),(a.real()) )
#define   normalize(a)      (a)/(length(a))
#define    dp(a,b)          (((conj(a))*(b)).real())
#define    cp(a,b)          (((conj(a))*(b)).imag())
#define    lengthsqrt(a)       dp(a,a)
#define    rotate0( a,ang)    ((a)*exp( point(0,ang) ))
#define    rotateA(about,p,ang)   (rotate0(vec(about,p),ang)+about)
#define    lcm(a,b)                ((a*b)/(__gcd(a,b)))
#define    reflection0(m,v)         (conj((v)/(m))*(m))
#define     reflectionA(m,v,p0)     (conj( (vec(p0,v))/(vec(p0,m)) ) * (vec(p0,m)) ) + p0
#define     same(p1,p2)               ( dp(  vec(p1,p2),vec(p1,p2)) < eps )
#define     point                    complex<double>
typedef  long long     ll ;
typedef  unsigned long long ull;
const double eps= (1e-10);
using namespace std;
int dcmp(double a,double b){   return fabs(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
ll getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
ll setBit1(ll num, int idx) {return num | (1ll<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(ll mask) {int ret=0; while (mask) 	{mask &= (mask-1ll);++ret;	}return ret;}
int main() 
{
    int t;
    char s[505];
    
    int g[505][505], gv[505];
    
    scanf("%d", &t);
    
    while(getchar() != '\n');
    
    while(getchar() != '\n');
    
    while(t--) 
    {
        gets(s);
        stringstream sin(s);
        int n = 1, x, y, i, j;
    
        while(sin >> g[1][n])
            n++;
        n--;
        for(i = 2; i <= n; i++)
            for(j = 1; j <= n; j++)
                scanf("%d", &g[i][j]);
                
        for(i = 1; i <= n; i++)
            scanf("%d", &gv[i]);
            
        while(getchar() != '\n');
        
        int pflag = 0;
        while(gets(s) && s[0]) 
        {
            if(pflag)   
                puts("");
            
            pflag = 1;
            int st, ed;
            int dis[505] = {}, used[505] = {}, prev[505];
            
            sscanf(s, "%d %d", &st, &ed);
            
            for(i = 1; i <= n; i++)
                dis[i] = 0xfffffff;
                
            dis[st] = 0;
            queue<int> Q;
            Q.push(st);
            while(!Q.empty()) 
            {
                x = Q.front(), Q.pop();
                used[x] = 0;
                for(i = 1; i <= n; i++) 
                {
                    if(g[x][i] == -1)
                        continue;
                    if(dis[i] > dis[x]+gv[i]+g[x][i])
                     {
                        dis[i] = dis[x]+gv[i]+g[x][i];
                        prev[i] = x;
                        if(used[i] == 0)
                         {
                            used[i] = 1;
                            Q.push(i);
                        }
                    }
                }
            }
            printf("From %d to %d :\n", st, ed);
            int stk[105], stkidx = 0;
            x = ed;
            while(x != st) 
            {
                stk[stkidx++] = x;
                x = prev[x];
            }
            printf("Path: %d", st);
            for(i = stkidx-1; i >= 0; i--)
                printf("-->%d", stk[i]);
            if(st == ed) {
                printf("-->%d", ed);
                dis[ed] = gv[ed];
            }
            
            cout<<endl;
            
            printf("Total cost : %d\n", dis[ed]-gv[ed]);
        }
        if(t)
            cout<<endl;
    
    }

}

