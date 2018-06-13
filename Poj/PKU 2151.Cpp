/*
first of all try to divide the problem to subproblems i should endup with a list of contestants some of them are champions and
others are not and the champion should have between n to m solved problems so i will fix a certain number of the problems the champion
should solve and run dp with 2 choices whether a champion or not if its a champion so he should solve the decided number of problems
else he should solve less than that number so from here you may notice that i need to calculate the probability of a team to solve
a certain number of problems so i did another dp for that :) happy solving
*/

// ICPC champion is here
//#include <bits/stdc++.h>

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
int L,T,m,n,t;
double mem[32][32],p[1009][32],lss[1009][32],pro[1009][32],mem2[1009][2];


double solve(int id,int cnt)
{
    //cout<<id<<" "<<cnt<<endl;

    if(id==m+1)
    {
        if(cnt==L)
        return 1;
       return 0;
    }
    double &ret=mem[id][cnt];
    if(ret==ret)
        return ret;

     double ans=0.0;



       ans+= p[T][id]*solve(id+1,cnt+1);
       ans+= (1-p[T][id])*solve(id+1,cnt);




   return ret=ans;
}

double solve2(int id,int f)
{

    if(id==t+1)
    {
        if(f)
            return 1;
        return 0;
    }
    double &ret=mem2[id][f];
    if(ret==ret)
        return ret;


    double ans=0.0;

    ans+= pro[id][L]*solve2(id+1,1);
    ans+= lss[id][L-1]*solve2(id+1,f);

    return ret=ans;
}














int main()
{

    while(cin>>m>>t>>n)
    {
        if(!n&&!m&&!t)
            break;


        for(int i=1;i<=t;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>p[i][j];
            }
        }
        double ans;


        for(int i=1;i<=t;i++)
        {
            for(int j=1;j<=m;j++)
            {
              L=j;
              clr(mem,-1);
              T=i;
              ans=solve(1,0);
              //cout<<ans<<endl;
              pro[i][L]=ans;
              lss[i][L]=ans;
            }
        }

        for(int i=1;i<=t;i++)
        {
            for(int j=1;j<=m;j++)
            {
                lss[i][j]+=lss[i][j-1];
            }
        }


        ans=0.0;
//cout<<lss[2][2]<<endl;
        for(int i=n;i<=m;i++)
        {
            L=i;
           clr(mem2,-1);
           ans+= solve2(1,0);
        }

        cout<<fixed<<setprecision(3)<<ans<<endl;
    }
}







