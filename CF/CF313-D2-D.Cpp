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
ll getBit(ll num, int idx) {return ((num >> idx) & 1ll) == 1;}
ll setBit1(ll num, int idx) {return num | (1ll<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
int k,m,n;
ll mem[309][309],best[309][309];

ll solve(int id,int cnt)
{

   if(id==n)
   {
       if(cnt>=k)
        return 0;
       return 1e15;
   }
   ll &ret=mem[id][cnt];
   if(ret!=-1)
    return ret;
   ret=1e15;

   ret=min(ret, solve(id+1,cnt));

   for(int i=id;i<n;i++)
   {

       ret=min(ret,solve(i+1,cnt+(i-id+1))+best[id][i]);

   }

return ret;
}











int main()
{
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<=300;i++)
        for(int j=0;j<=300;j++)
         best[i][j]=1e15;
    int l,r;
    ll w;
    while(m--)
    {
        scanf("%d %d %I64d",&l,&r,&w);
        l--;
        r--;

        best[l][r]=min(best[l][r],w);
    }

    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<n;j++)
        {
            if(j)
            best[j][i]=min(best[j-1][i],best[j][i]);

        }
    }
    clr(mem,-1);
    ll ans=solve(0,0);
    if(ans>300000000000)
        ans=-1;
    printf("%I64d\n",ans);
}





