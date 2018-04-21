/*
the idea is to detect the cycle first if there is no cycle so go dp 
btw, you can dectect it in the dp
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
int R,C,SZ,n;
int mem[1001][1001];
string st;
bool valid(int r,int c)
{
    if(r<=n&&r>=1&&c<=n&&c>=1)
        return 1;
    return 0;
}

bool check(int r,int c)
{
    int R=r,C=c,fl=0;
    for(int i=0;i<sz(st);i++)
    {
        if(!valid(R,C))
         {
             fl=1;
            break;
         }
        if(st[i]=='U')
            R+= -1;
        if(st[i]=='D')
            R+=1;
        if(st[i]=='L')
            C+=-1;
        if(st[i]=='R')
            C+=1;

    }

    if(!fl&&R==r&&C==c)
     return 1;

    return 0;


}

int solve(int r,int c)
{
    if(!valid(r,c))
        return 0;

        if(mem[r][c]!=-1)
            return mem[r][c];


         int ans=0;
         int R=r,C=c,cnt=0;
        for(int i=0;i<sz(st);i++)
       {

         cnt++;
        if(st[i]=='U')
            R+= -1;
        if(st[i]=='D')
            R+=1;
        if(st[i]=='L')
            C+=-1;
        if(st[i]=='R')
            C+=1;
        if(!valid(R,C))
            break;

      }


      ans= cnt+solve(R,C);

    return mem[r][c]=ans;

}

class RobotTesting
{

  public :


    double estimateCommands(int L, string str)
    {
        n=L;
        st=str;
    double pro=0.0;
    clr(mem,-1);
    int res=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(check(i,j))
                res=50000;
            else
            res=solve(i,j);

           pro+= res;
        }
    }

    return pro/(n*n*1.0);
    }
};
