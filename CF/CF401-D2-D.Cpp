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
string n;
ll mem[105][(1<<18)];
ll P[19],m;
ll solve(int mod,int msk,int id)
{
    ll &ret=mem[mod][msk];
    if(ret!=-1)
        return ret;

    if(id==sz(n))
    {

        if(mod==0)
          return ret=1;
       return ret=0;
    }

    ll ans=0;

    for(int i=0;i<sz(n);i++)
    {
        if(i!=0&&n[i]==n[i-1]&&getBit(msk,i-1)==0)
         {
             //cout<<n[i]<<" "<<n[i-1]<<endl;
            continue;
         }

        if(getBit(msk,i)==1||(id==0&&n[i]=='0'))
            continue;

        ll pw=P[sz(n)-1-id];

        ll nwmod= (mod+(((n[i]-'0')*(pw%m))%m))%m;


       ans+= solve(nwmod,setBit1(msk,i),id+1);

    }

    return ret=ans;
}
char ch[109];


int main()
{
    scanf("%s %d",ch,&m);
    n=ch;

    sort(all(n));

    P[0]=1;

    for(int i=1;i<=18;i++)
        P[i]=P[i-1]*10;

        clr(mem,-1);


   printf("%I64d", solve(0,0,0));
}

