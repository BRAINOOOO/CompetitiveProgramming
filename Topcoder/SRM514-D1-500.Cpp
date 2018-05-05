// ICPC Champion is here

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
//void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
int w,h,N,M;
ll mem[12][(1<<10)+9],fact[12][12][3],factmsk[12][(1<<10)+9];
const ll MOD=1000000007;

int solve(int i,int msk)
{

     if(i==N)
     {
         if(msk==(1<<M)-1)
          return 1;
        return 0;
     }

     ll &ret=mem[i][msk];
     if(ret!=-1)
        return ret;
     ret=0;
     for(int j=0;j<(1<<M);j++)
     {
         ret= (ret%MOD+ (factmsk[i][j]* solve(i+1,msk^j))%MOD)%MOD;

     }

  return ret;
}























class MagicalGirlLevelTwoDivOne
{
public :

    int theCount(vector <string> palette, int n, int m)
    {

        h=sz(palette);
        w=sz(palette[0]);
        N=n;
        M=m;


        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {

                for(int k=0;k<2;k++)
                {
                    ll p=1;
                    for(int r=i;r<h;r+=n)
                    {
                        for(int c=j;c<w;c+=m)
                        {
                            if(palette[r][c]=='.')
                                p=(p*(4+k))%MOD;
                            else if((palette[r][c])%2!=k)
                                p=0;

                        }
                    }
                    fact[i][j][k]=p;

                }
            }
        }


        for(int i=0;i<n;i++)
        {

            for(int msk=0;msk<(1<<m);msk++)
            {
                ll p=1,c=0;
                for(int j=0;j<m;j++)
                {
                    int k=getBit(msk,j);

                        p=(p*fact[i][j][k])%MOD;
                    c+=k;
                }

                if(c%2==0)
                    p=0;
                factmsk[i][msk]=p;
            }
        }

        clr(mem,-1);

        return solve(0,0);
    }

};





