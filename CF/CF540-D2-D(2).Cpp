/*
use the geometric series
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
int dcmp(long double a,long double b){   return fabsl(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
ll getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
ll setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
double dp[101][101][101];
double sl(int n)
{
    return n*(n-1)/2.0;
}
int main()
{
    int r,s,p;
    cin>>r>>s>>p;

    dp[r][s][p]=1;

    for(int i=r;i>=0;i--)
    {
        for(int j=s;j>=0;j--)
        {
            for(int k=p;k>=0;k--)
            {

               double pr= (sl(i)+sl(j)+sl(k))/(sl(i+j+k));

                if(i&&j)
                {
                    dp[i][j-1][k]+= dp[i][j][k]*((i*j)/(sl(i+j+k)))*(1.0/(1-pr));
                }
                if(i&&k)
                {
                    dp[i-1][j][k]+= dp[i][j][k]*((i*k)/(sl(i+j+k)))*(1.0/(1-pr));
                }

                if(j&&k)
                {
                    dp[i][j][k-1]+= dp[i][j][k]*((k*j)/(sl(i+j+k)))*(1.0/(1-pr));
                }
            }
        }
    }
    double a1=0,a2=0,a3=0;
    for(int i=1;i<=r;i++)
        a1+= dp[i][0][0];
    for(int i=1;i<=s;i++)
        a2+= dp[0][i][0];
        for(int i=1;i<=p;i++)
        a3+= dp[0][0][i];

    cout<<fixed<<setprecision(13)<<a1<<" "<<a2<<" "<<a3<<endl;
}



