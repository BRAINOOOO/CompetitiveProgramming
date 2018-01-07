/*
explanation : here if i will find a solution it will fit with the m system responses so it will fit with 
for eg the first response and the other so i will generate all the possibilities for the first response (can be any of them)
and check wether the rest of the responces fit with it or not if they fit and its not one of them so i will count it 
but to generate all the possibilities of the first response its comb( n,right ) but this order couldnt fit with the time
here it is okay bec right<=5 so it will fit. generally its brudeforce.

complexity: O(  M*N*comb(N,right) )

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
string str;
vector<string> v1;
vector< pair<string,int> > v;
map<string,int> vis;
int n,num,vs[63];
void put(int  vs[])
{
    string strr=str;
    for(int i=0;i<n;i++)
    {
        if(!vs[i])
        {
            strr[i]=(strr[i]=='0'?'1':'0');
        }
    }
    v1.pb(strr);
}
void fun(int st,int c)
{
      if(c==num)
      {
        put(vs);
        return ;
      }
      for(int i=st;i<n;i++)
      {
           vs[i]=1;
          fun(i+1,c+1);
          vs[i]=0;
      }
      return ;
}
bool check(string s1,string s2,int sam)
{
    int cnt=0;
    for(int i=0;i<sz(s1);i++)
    {
        if(s1[i]==s2[i])
            cnt++;
    }
    if(cnt==sam)
        return 1;
    return 0;
}
int main()
{
    int m;
    scanf("%d %d",&n,&m);
    char stt[39];
    string st;
    int rig;
    for(int i=0;i<m;i++)
    {
      scanf("%s %d",&stt,&rig);
        st=stt;
        vis[st]=1;
        v.pb(mp(st,rig));
    }
    str=v[0].first;
    num=v[0].second;
    fun(0ll,0);
     ll ans=0;
     for(int i=0;i<sz(v1);i++)
     {
         st=v1[i];
         bool ok=1;
         for(int j=1;j<m&&ok;j++)
         {
             if(!check(st,v[j].first,v[j].second))
                ok=0;
         }
         if(ok)
         {
             if(vis.find(v1[i])==vis.end())
                ans++;
         }
     }
   printf("%I64d\n",ans);
}
