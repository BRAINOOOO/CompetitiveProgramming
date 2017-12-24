/*
explanation : here it is obvious that we want as much red towers as possible so we can observe that 
every connected component can have at least 1 blue tower, the connected component is like a tree all
the children can be red if the root is blue so we can turn all the nodes to red except for the root
so we will do so for every connected component.

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
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
int setBit0(int num, int idx) {return num & ~(1<<idx);}
int flipBit(int num, int idx) {return num ^ (1<<idx);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
const int MX=500+9;
int vis[MX][MX],n,m;
int dr[]={0,1,0,-1};
int dc[]={1,0,-1,0};
vector<string> v;
stringstream ss;
int cnt;
void add(char c,int r,int cl)
{
    cnt++;
    ss<<c<<" "<<r+1<<" "<<cl+1<<endl;
}

void dfs(int r,int c)
{
    if(r<0||r==n||c<0||c==m||vis[r][c]||v[r][c]=='#')
       return ;
       vis[r][c]=1;
       for(int i=0;i<4;i++)
       {
           dfs(r+dr[i],c+dc[i]);
       }
       add('D',r,c);
       add('R',r,c);
}
int main()
{
    cin>>n>>m;
    string st;
    for(int i=0;i<n;i++)
    {
        cin>>st;
        v.pb(st);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(v[i][j]=='.')
                add('B',i+1,j+1);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j]&&v[i][j]=='.')
            {
                vis[i][j]=1;
                for(int k=0;k<4;k++)
                {
                    dfs(i+dr[k],j+dc[k]);
                }
            }
        }
    }
   cout<<cnt<<endl<<ss.str();
}
