/*
First you may get the solution at first as a brude force but it will TLE so think of obtimization
1- memorize the states 
2- try to obtimaize the Dp code eg return once the len reach t and other things
3- in general if there is a thing that its value is 1 or 0 only define it boolean this can TL :)
4- obtimize in the code contant time like getting the path array alone which will TL

good luck
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
ll getBit(ll num, int idx) {return ((num >> idx) & 1ll) == 1;}
ll setBit1(ll num, int idx) {return num | (1ll<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
int mem[150][1001][15],vis[305],n,t,idx;
vector<int> p;
int ans[14];
bool comp(int a, int b)
{
    stringstream ss1;
    stringstream ss2;
    ss1 << a;
    ss2 << b;
    return ss1.str() < ss2.str();
}
void primes()
{

    for(int i=2;i<300;i++)
    {
        if(vis[i])
        continue;

        for(int j=i*i;j<300;j+=i)
            vis[j]=1;
    }

   p.pb(2);

   for(int i=3;i<300;i++)
    if(!vis[i])
     p.pb(i),p.pb(i);

    sort(all(p),comp);


}













int solve(int id,int sum,int len)
{
    int &ret=mem[id][sum][len];
    if(ret!=-1)
        return 0;

    if(id==sz(p))
    {

        return ret=0;
    }
    if(len==t)
    {
        if(sum==n)
            return ret=1;
       return ret=0;
    }
   if(sum>=n)
    return ret=0;

    int p1,p2;
    p1=p2=0;

     ans[len]=p[id];
    p1=solve(id+1,sum+p[id],len+1);
    if(p1)
        return ret=1;
    p2=solve(id+1,sum,len);
    if(p2)
        return ret=1;

    return ret=0;
}





int main()
{
    int cs=1;
    primes();
    while(cin>>n>>t)
    {
        if(!n&&!t)
            break;


        printf("CASE %d:\n",cs++);

        clr(mem,-1);

        int fl=solve(0,0,0);

        if(!fl)
        printf("No Solution.\n");
       else
        {

            for(int i=0;i<t;i++)
                if(i)
                printf("+%d",ans[i]);
                else
                printf("%d",ans[i]);

             printf("\n");

        }

    }
}



