/*
explanation : the idea is i can partion the problem to what is the probability that X for example can be the paid value okay to be
so i must have no more than one value greater than it and one or more value equal it so the number of greater than it and equal to it 
will affect the solution but smaller than it won't affect it so simply i will seprate the states which i will choose equal value or 
greater one.

complexity : O( n*n*n*max(r-l+1)+10000 )
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
int countNumBit1(ll mask) {int ret=0; while (mask) 	{mask &= (mask-1ll);++ret;	}return ret;}
int n;
double mem[7][10009][7][7];
int L[7],R[7];
double solve(int i,int b,int eq,int gr)
{
    if(i==n)
    {
        if(eq+gr>1&&gr<=1)
            return b;
        else
            return 0;
    }
    if(mem[i][b][eq][gr]!=-1)
        return mem[i][b][eq][gr];
    double res=0.0;
    if(b>=L[i]&&b<=R[i])
    {
        res= ((b-L[i])*solve(i+1,b,eq,gr)+solve(i+1,b,eq+1,gr))/(R[i]-L[i]+1);
        if(gr<1)
        res+= ((R[i]-b)*solve(i+1,b,eq,gr+1))/(R[i]-L[i]+1);
    }
    else if(b>R[i])
    {
         res=solve(i+1,b,eq ,gr);
    }
    else if(b<L[i]&&gr<1)
    {
        res= solve(i+1,b,eq,gr+1);
    }
   return mem[i][b][eq][gr]=res;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>L[i]>>R[i];
    }
    for(int i=0;i<=6;i++)
    {
        for(int j=0;j<=10008;j++)
        {
            for(int k=0;k<=6;k++)
            {
                for(int r=0;r<=6;r++)
                {
                    mem[i][j][k][r]=-1;
                }
            }
        }
    }
    double res=0.0;
    for(int i=1;i<=10000;i++)
    {
        res+= solve(0,i,0,0);
    }
  cout<<setprecision(9)<<fixed<<res<<endl;
}
