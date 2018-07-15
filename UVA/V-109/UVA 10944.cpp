#include <bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<map>
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
const double eps= (1e-5);
using namespace std;
int dcmp(double a,double b){   return fabs(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
ll getBit(ll num, int idx) {return ((num >> idx) & 1ll) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
int n,m,mb[29][29],vis[21][21][(1<<15)+1];
int dr[]={1,0,-1,0,1,1,-1,-1};
int dc[]={0,1,0,-1,1,-1,1,-1};
vector<string> v;
typedef struct node
{
    int r,c,msk;
    node(int ro,int cl,int mk)
    {
        r=ro; c=cl; msk=mk;
    }
}N;
bool valid(int r,int c)
{
    return (r>=0&&r<n&&c>=0&&c<m);
}
int main()
{

    while(cin>>n>>m)
    {
        v.clear();
        string st;
        int SR,SC;
        clr(mb,0);
        clr(vis,0);
        int id=0;
        for(int i=0;i<n;i++)
        {
            cin>>st;
            v.pb(st);

            for(int j=0;j<m;j++)
            {
                if(v[i][j]=='L')
                    SR=i,SC=j;
                if(v[i][j]=='#')
                {
                    mb[i][j]=id++;
                }
            }
        }

        queue< N> q;
        int lv=0;
        q.push(N(SR,SC,0));
        vis[SR][SC][0]=1;
        bool ok=0;
        int ans=0;

        while(!q.empty()&&!ok)
        {
           int siz=sz(q);
            lv++;
            while(siz--)
            {

            N cur=q.front();
            q.pop();
            if(cur.msk==((1<<id)-1)&&cur.r==SR&&cur.c==SC)
            {

                ans=lv-1;
                ok=1;
                break;
            }


            for(int i=0;i<8;i++)
            {
                int nr=cur.r+dr[i];
                int nc=cur.c+dc[i];
                int nmsk=cur.msk;
                 if(!valid(nr,nc)||vis[nr][nc][nmsk])
                    continue;

                if(v[nr][nc]=='#')
                    nmsk=setBit1(nmsk,mb[nr][nc]);



                vis[nr][nc][nmsk]=1;

                q.push(N(nr,nc,nmsk));
            }
            }
        }

    cout<<ans<<endl;
    }
}
