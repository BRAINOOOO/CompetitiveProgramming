/*
the idea is to decide a one of the two paths and try to get the other indepentant path which have the max length :)
*/


// ICPC Champion is here

#include <bits/stdc++.h>
#include<iostream>
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
#define     point                    complex<long double>
typedef  long long     ll ;
typedef  unsigned long long ull;
const double eps= (1e-10);
using namespace std;
int dcmp(long double a,long double b){   return fabsl(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
ll getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
ll setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
int n,cost,mem[209],vis[209],MX,NO2;
vector<int> v2,v1,vis2;
vector<vector<int> > v(209);
pair<int,vector<int> > arr[209][209];
void dfs(int id,int d,int c)
{
    vis[id]=1;

    if(id==d)
    {
        cost=c;
        v2=v1;
        return;
    }
   for(int i=0;i<sz(v[id]);i++)
   {

       int no=v[id][i];

       if(vis[no])
        continue;
       v1.pb(no);
       dfs(no,d,c+1);
       v1.pop_back();
   }
}

void dfs1(int id,int c)
{
     vis[id]=1;
    int fl=0;
   for(int i=0;i<sz(v[id]);i++)
   {

       int no=v[id][i];

       if(vis[no]||vis2[no])
        continue;
        fl=1;
       dfs1(no,c+1);

   }
   if(!fl)
   {
       if(c>=MX)
       {

           MX=c;
           NO2=id;
       }
   }

}





int main()
{

    cin>>n;
    int fr,to;
    for(int i=0;i<n-1;i++)
    {
        cin>>fr>>to;
        v[fr].pb(to);
        v[to].pb(fr);
    }

   for(int i=1;i<=n;i++)
   {
       for(int j=i+1;j<=n;j++)
       {
           clr(vis,0);
           v1.pb(i);
           dfs(i,j,0);
           v1.pop_back();

           vector<int> vv(n+1,0);
           for(int l=0;l<sz(v2);l++)
            vv[v2[l]]=1;

           arr[i][j]=mp(cost,vv);
           arr[j][i]=mp(cost,vv);
       }
   }
   int ans=0;
   for(int i=1;i<=n;i++)
   {

       for(int j=i+1;j<=n;j++)
       {

           vis2=arr[i][j].second;
           int co=arr[i][j].first;
           int No;
           No=-1;
           for(int h=1;h<=n;h++)
           {
               if(!vis2[h])
                {
                    No=h;
                    break;
                }
           }
           MX=0;
           clr(vis,0);
           if(No!=-1)
           {

           dfs1(No,0);
           MX=0;
           clr(vis,0);
           dfs1(NO2,0);
           }

          ans=max(ans,co*MX);
       }
   }

   cout<<ans<<endl;
}





