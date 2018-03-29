/*
explanation : here the idea is we do nested dp to min lec number first then min ID valure second
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
ll getBit(ll num, int idx) {return ((num >> idx) & 1ll) == 1ll;}
ll setBit1(ll num, int idx) {return num | (1ll<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(ll mask) {int ret=0; while (mask) 	{mask &= (mask-1ll);++ret;	}return ret;}
int inf=INT_MAX,mem1[1009][509],mem2[1009][509],top[1009],vis[1009][509];
int n,l,c;
int ID(int d)
{

    if(d>=1&&d<=10)
        return -c;
    if(d>10)
        return (d-10)*(d-10);
    return 0;
}
int solve1(int t,int tm)
{
    if(t==n+1)
        return 1;

    if(mem1[t][tm]!=-1)
        return mem1[t][tm];


    int p1=inf,p2=inf;
    if(tm>=top[t])
      p1=  solve1(t+1,tm-top[t]);

    p2= solve1(t+1,l-top[t])+1;

    return mem1[t][tm]=min(p1,p2);


}
int solve2(int t,int tm)
{


    if(t==n+1)
      return ID(tm);

    if(vis[t][tm])
        return mem2[t][tm];

     vis[t][tm]=1;

     int r1=inf,r2=inf;
       if(tm>=top[t])
      r1= solve1(t+1,tm-top[t]);
      r2= solve1(t+1,l-top[t])+1;
     int an;
    if(r1>r2)
    {
        an= solve2(t+1,l-top[t])+ID(tm);
    }
    else if(r1<r2)
    {
        an= solve2(t+1,tm-top[t]);
    }
    else
    {
        an= min(solve2(t+1,tm-top[t]),solve2(t+1,l-top[t])+ID(tm));
    }

   return mem2[t][tm]=an;
}



int main()
{
    int cs=1;
    while(1)
    {
      cin>>n;
      if(n==0)
        break;
    if(cs>1)
        cout<<endl;
    cin>>l>>c;
    for(int i=1;i<=n;i++)
    {
        cin>>top[i];
    }
    clr(mem1,-1);
   int mn=solve1(1,l);
   clr(vis,0);
   int id= solve2(1,l);

    cout<<"Case "<<cs++<<":\n"<<"Minimum number of lectures: "<<mn<<endl<<"Total dissatisfaction index: "<<id<<endl;
    }
}
