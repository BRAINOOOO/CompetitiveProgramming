/*
explanation : here you will do dp normaly as if i want to get all the permutations so i need vis array
this will be the mask and the logic is if i am at cell i in the array i can know what this cell will add
to answer by counting all the unvisited numbers smaller than ai we could calculated by a function or
you may observe that at each cell i will try all the numbers from smaller to greater so at each if i 
move to the next available choice i will leave one smaller than me so i will count it .

complexity : T*n*(2^n-1)*K
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
int n,k,mem[13][(1<<13)-1][101];
int fun(int id,int msk,int val)
{
    if(val>k)
        return 0;
    if(id==n)
    {
        if(val==k)
        {
             return 1;
        }
        return 0;
    }
    if(mem[id][msk][val]!=-1)
    return mem[id][msk][val];
    int ans=0,cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(getBit(msk,i))
            continue;
      int tmsk=setBit1(msk,i);
      int  v= cnt;
       ans+= fun(id+1,tmsk,val+v);
       cnt++;
    }
   mem[id][msk][val]=ans;
    return ans;
}
int main()
{
    int d;
    cin>>d;
    while(d--)
    {
    cin>>n>>k;
    int ans=0;
    clr(mem,-1);
    ans= fun(0,0,0);
    cout<<ans<<endl;
    }
}
