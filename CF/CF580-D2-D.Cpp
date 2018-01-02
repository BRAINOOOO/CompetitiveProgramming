/*
explanation : here it is stright forward dp with masks the state will be the mask 
as a visted boolean vector record the dishes assigned and the previous dish base 
case if i already selected m dishes so return .

complexity : N*N*2^N
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
ll mem[(1<<18)-1+9][18+9],c[18+9],add[18+9][18+9];
int n,m,k;
ll fun(int msk,int p)
{
    if(countNumBit1(msk)==m)
        return 0;
    if(mem[msk][p]!=-1)
    return mem[msk][p];
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        if(getBit(msk,i))
            continue;
      ans=max(ans,c[i]+add[p][i]+fun(setBit1(msk,i),i));
    }
    mem[msk][p]=ans;
    return ans;
}
int main()
{
    cin>>n>>m>>k;

    for(int i=0;i<n;i++)
        cin>>c[i];
    int x,y,c;
    for(int i=0;i<k;i++)
    {

        cin>>x>>y>>c;
        x--;
        y--;
        add[x][y]=c;
    }

  clr(mem,-1);
  cout<< fun(0,n) <<endl;

}
