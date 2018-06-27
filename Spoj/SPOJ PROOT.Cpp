/*
see 
http://zobayer.blogspot.com/2010/02/primitive-root.html
*/
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

const int MAXN=70000;

int flag[MAXN];
ll prime[MAXN];
ll total;
void seive(){

    flag[0]=flag[1]=1;
    for(ll i=2; i<MAXN; i++)
    {
        if(flag[i]==1) continue;
        prime[total++]=i;
        for(ll j=i*i; j<MAXN; j+=i)
        {
            flag[j]=1;
            //cout<<j<<endl;
        }

    }

}
ll mypow(ll r, ll n, ll mod){

    if(n==0) return 1;
    if(n==1) return r%mod;

    if(n%2==1){
        return (r*mypow(r,n-1,mod))%mod;
    }else{
        ll ret=mypow(r,n/2,mod);
        return (ret*ret)%mod;
    }

}

ll primefactor[MAXN];
ll pfc;

void primefactorize(ll n)
{

   ll temp=n;
    pfc=0;
    for(ll i=0; i<total; i++)
    {
        if(prime[i]*prime[i]> temp) break;

        while(n%prime[i]==0){
            n/=prime[i];
            primefactor[pfc++]=prime[i];
        }


    }
    if(n!=1)
        primefactor[pfc++]=n;

}

bool checkprim(ll r, ll n)
{

    ll phin=n-1;
    primefactorize(phin);

    for(ll i=0; i<pfc; i++)
    {
        if(mypow(r,phin/primefactor[i],n)%n ==1)
          return 0;

    }
    return 1;

}
int main()
{

    seive();
    int p,t;


   while( scanf("%d%d",&p,&t)==2)
    {
    if(!p && !t) return 0;
    while(t--)
    {
        int r;
        scanf("%d",&r);
        if(checkprim(r,p))
        {
            printf("YES\n");
        }else
        {
            printf("NO\n");
        }
    }
   }
}


