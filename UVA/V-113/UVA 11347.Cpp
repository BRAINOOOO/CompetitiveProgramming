
// ICPC champion is here
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
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
int vis[10009];
set<ll> s;
ll power[63];
ll lim=1e18;
void Factors(int n)
{
    if(n<=1)
        return ;

    for(int i=2;i*i<=n;i++)
    {
        while(n%i==0)
        {
            n/=i;
            vis[i]++;
            s.insert(i);
        }
    }


    if(n>1)
    {
        vis[n]++;
        s.insert(n);
    }




}







int main()
{

    int T,cs=1;
    cin>>T;
    power[0]=1;
    for(int i=1;i<=62;i++)
        power[i]=power[i-1]*2;

    while(T--)
    {
        s.clear();
        clr(vis,0);
      int n,k=0;
      string st,ss="";
      cin>>st;
      for(int i=0;i<sz(st);i++)
      {
          if(isdigit(st[i]))
          ss+=st[i];
          else
            k++;
      }
      n=atoi(ss.c_str());
      int N=n;
//cout<<N<<" "<<K<<endl;
      while(1)
      {
         // cout<<N<<endl;
          Factors(N);
          if(N==k)
            break;
          if(N==(n%k))
            break;
        if(N>=k)
          N-=k;


      }

     int siz=sz(s);
      cout<<"Case "<<cs++<<": ";

     int fl=0;
     ll ans=1.0;
     for(auto i=s.begin();i!=s.end()&&!fl;i++)
     {
         int num=(*i);

         ans*=(vis[num]+1);
         if(ans>lim)
         {
             fl=1;
         }

     }

      if(fl)
        cout<<"Infinity\n";
      else
     cout<<ans<<endl;
    }
}

