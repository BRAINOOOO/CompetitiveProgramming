/*
explanation : here the problem is direct dp the state will be on the number of matches and the 
number of the win matches so far as to win n number of matches there are alot of sequences can
happened so we will consider all the sequences that can happen and result in n win matches.

complexity : (2n-1)*n*t
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
int n;
double p,q,mem[50+9][25+9];
double fun(int i,int c)
{
    if(c==n)
    {
        return 1;
    }
    if(i==2*n-1)
    return 0;
    if(dcmp(mem[i][c],-1)!=0)
        return mem[i][c];
    double res=0.0;
    res+= p * fun(i+1,c+1);
    res+= q * fun(i+1,c);
    return mem[i][c]=res;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    cin>>n>>p;
    q=1-p;
     for(int i=0;i<=52;i++)
       for(int j=0;j<=25;j++)
        mem[i][j]=-1;
    cout<<fixed<<setprecision(2)<< fun(0,0) <<endl ;
    }
}
