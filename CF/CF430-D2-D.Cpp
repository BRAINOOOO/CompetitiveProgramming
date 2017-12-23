/*
explanation : first of all read the announcement note because it turns the problem to another one 
okay so we want to have exactly one common cell during each one path think of the ways they can
reach this common cell you will find that there is exactly 2 possibilities :      
          .
        . X .  1-the one at (1,1) can reach it from the top and leave from the button and the one at (n,1) can reach it from the left side only and leave from 
          .    the right side .
               2-the one at (1,1) can reach it from the left side and leave from the right side and the one at (n,1) can reach it from the button
               and leave it from the top.
so i will use dp to get the max gain .

complexity : O(n*m*4)
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
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
int setBit0(int num, int idx) {return num & ~(1<<idx);}
int flipBit(int num, int idx) {return num ^ (1<<idx);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
int n,m,arr[1000+9][1000+9];
ll mem[1000+9][1000+9][4];
int dr[]={-1,1,1,-1};
int dc[]={-1,1,-1,1};
const int oo=100000000000000;
ll solve(int r,int c,int i)
{
   if(r<1||c<1||r>n||c>m)
    return -oo;
    if((r==1||r==n)&&(c==1||c==m))
        return arr[r][c];
   ll &ret=mem[r][c][i];
   if(ret!=-1)
    return ret;
   ret=0;
   ret= max(solve(r+dr[i],c,i),solve(r,c+dc[i],i))+arr[r][c];
   return ret;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>arr[i][j];
        }
    }
    ll mx=0;
    clr(mem,-1);
    for(int i=2;i<n;i++)
    {
        for(int j=2;j<m;j++)
        {
            ll a= solve(i+1,j,1)+solve(i-1,j,0);
            ll b= solve(i,j-1,2)+solve(i,j+1,3);
            ll c= solve(i,j-1,0)+solve(i,j+1,1);
            ll d= solve(i-1,j,3)+solve(i+1,j,2);
            mx=max(mx,max(a+b,c+d));
        }
    }
    cout<<mx<<endl;
}
