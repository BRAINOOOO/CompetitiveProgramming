// ICPC champion is here
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
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
vector< pair<int,int> > e;
map<pair<int,int> ,int> mb;
int main()
{
    int k;
    cin>>k;

    if(k%2==0)
    {
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    if(k==1)
    {
        cout<<"2 1\n1 2\n";
        return 0;
    }

  int prs= (k-1)/2;
  int S= 2*k+3;
  int T=S+1;
  int id=1;
   for(int i=1;i<=prs;i++)
   {
       e.pb(mp(id,S));
       e.pb(mp(id+1,S));
       mb[mp(id,id+1)]=1;
       id+=2;

   }

   id=k+2;
   for(int i=1;i<=prs;i++)
   {
       e.pb(mp(id,T));
       e.pb(mp(id+1,T));
       mb[mp(id,id+1)]=1;

       id+=2;
   }

   e.pb(mp(S,T));

    for(int i=1;i<=k+1;i++)
    {
        for(int j=i+1;j<=k+1;j++)
         if(mb[mp(i,j)]==0)
         e.pb(mp(i,j));
    }

    for(int i=k+2;i<=2*k+2;i++)
    {
        for(int j=i+1;j<=2*k+2;j++)
         if(mb[mp(i,j)]==0)
         e.pb(mp(i,j));
    }


    cout<<(k+1)*2+2<<" "<<sz(e)<<endl;
    for(int i=0;i<sz(e);i++)
        cout<<e[i].first<<" "<<e[i].second<<endl;

}









