/*
greedy brudeforce solution will AC but it can be DP
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
#define     point                    complex<long double>
typedef  long long     ll ;
typedef  unsigned long long ull;
const double eps= (1e-10);
using namespace std;
//int dcmp(long double a,long double b){   return fabsl(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
int vis[3009],F[3009],CNT[3009];
vector<int> VEC[3009];
vector<int> res;
int fact(int n)
{
    int sq=ceil(sqrt(n)),i,s=0;
    for(i=1;i<sq;i++)
    {
        if(n%i==0)
        {
            string ss=to_string(i);
            for(int j=0;j<sz(ss);j++)
                s+=ss[j]-'0';
             ss=to_string(n/i);
            for(int j=0;j<sz(ss);j++)
                s+=ss[j]-'0';
        }
    }

    if(i*i==n)
    {
          string ss=to_string(i);
            for(int j=0;j<sz(ss);j++)
                s+=ss[j]-'0';
    }

    return s;
}

int main()
{
    for(int i=1;i<3009;i++)
        F[i]=fact(i);


      int mi=INT_MAX,mx=-1;
  for(int st=1;st<=3000;st++)
  {
     clr(vis,0);
     int cnt=0;
     vector<int> v;

    for(int i=st;;)
    {
        vis[i]++;
        if(vis[i]==2)
         {
             break;
         }
        cnt++;
        v.pb(i);
        i=F[i];


    }
    CNT[st]=cnt;
    VEC[st]=v;

  }

    int n,m,cs=1;
    while(scanf("%d %d",&m,&n)==2)
    {
        int N=n;
        int M=m;
        if(m>n)
            swap(n,m);
        res.clear();

     printf("Input%d: %d %d\n",cs,M,N);
    mx=-1;
    for(int i=m;i<=n;i++)
    {
        mx=max(mx,CNT[i]);
    }
    int st;
    for(int i=m;i<=n;i++)
        if(mx==CNT[i])
    {
        st=i;
        break;
    }


    printf("Output%d: ",cs++);

    for(int i=0;i<sz(VEC[st]);i++)
        if(i)
        printf(" %d",VEC[st][i]);
       else
        printf("%d",VEC[st][i]);

       printf("\n");
    }
}







