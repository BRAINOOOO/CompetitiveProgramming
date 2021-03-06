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
ll setBit1(ll num, int idx) {return num | (1ll<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
int arr[59][59],mb[59][59],par[2500+9],rnk[2500+9],vis[2500+9],f[2500+9],ans;
vector< pair<int,pair<int,int> > > ed;
void I()
{
    for(int i=0;i<=2500;i++)
        par[i]=i,rnk[i]=1;
}

int getpar(int n)
{
    if(par[n]==n)
        return n;
    return par[n]=getpar(par[n]);
}

void lnk(int a ,int b,int w)
{
    a=getpar(a);
    b=getpar(b);
    if(a==b)
    {

        return;
    }
    ans+=w;
    if(rnk[a]>=rnk[b])
    {
        par[b]=a;
        rnk[a]+=rnk[b];
        rnk[b]=0;
    }
    else
    {
        par[a]=b;
        rnk[b]+=rnk[a];
        rnk[a]=0;
    }
}

class ActivateGame
{
public :

    int findMaxScore(vector<string> grid)
    {
        I();
        int n=sz(grid);
        int m=sz(grid[0]);
        int id=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mb[i][j]=++id;
                int c;
                if(isdigit(grid[i][j]))
                    c=grid[i][j]-'0';
                else if(isupper(grid[i][j]))
                    c=36+grid[i][j]-'A';
                else
                    c=10+grid[i][j]-'a';

                arr[i][j]=c;
               // cout<<c;

            }
           // cout<<endl;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {

                if(j+1<m)
                    ed.pb(mp(abs(arr[i][j]-arr[i][j+1]),mp(mb[i][j],mb[i][j+1])));
                if(i+1<n)
                    ed.pb(mp(abs(arr[i][j]-arr[i+1][j]),mp(mb[i][j],mb[i+1][j])));



            }
        }

        sort(allr(ed));
        ans=0;
         vis[1]=1;
        for(int i=0;i<sz(ed);i++)
        {

            lnk(ed[i].second.first,ed[i].second.second,ed[i].first);
        }

  return ans;
    }
};
