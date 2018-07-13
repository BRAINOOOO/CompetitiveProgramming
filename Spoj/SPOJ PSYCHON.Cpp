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
bool vis[10000001];
bool res[10000001];
bool ok[10000001];
vector<int> pr;

void fact(int n)
{
    int N=n;

    if(ok[n])
    {

        if(res[n])
    printf("Psycho Number\n");
   else
    printf("Ordinary Number\n");

    return ;
    }
    ok[n]=1;
   int odd=0,even=0,cnt;
    for(int i=0;i<sz(pr);i++)
    {
        int pm=pr[i];
        if(pm*pm>n)
            break;
        if(n==1)
            break;
        cnt=0;
        while(n%pr[i]==0)
        {
            n/=pr[i];
            cnt++;
        }

        if(cnt&1)
            odd++;
        else if(cnt!=0)
            even++;
    }

    if(n>1)
    {
            odd++;

    }

   if(even>odd)
    printf("Psycho Number\n"),res[N]=1;
   else
    printf("Ordinary Number\n"),res[N]=0;
}








void p()
{
    for(ll i=2;i*i<=10000000;i++)
    {
        if(vis[i])
            continue;

        for(ll j=i*i;j<=10000000;j+=i)
            vis[j]=1;
    }
    for(int i=2;i<=10000000;i++)
     if(!vis[i])
        pr.pb(i);


}
int main()
{
    p();
    int T;
    scanf("%d",&T);
    int n;
    while(T--)
    {
        scanf("%d",&n);

        fact(n);
    }
}







