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
ll getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
ll setBit1(ll num, int idx) {return num | (1ll<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(ll mask) {int ret=0; while (mask) 	{mask &= (mask-1ll);++ret;	}return ret;}
const int inf=INT_MAX;
const int MAX=1000000+9;
int par[MAX];
int v[MAX],rem[MAX];
int N;

void intial()
{
    for(int i=1;i<=N;i++)
        par[i]=i;

}
int getpar(int n)
{

    if(par[n]==n)
        return n;

    return par[n]=getpar(par[n]);
}
int main()
{
    scanf("%d",&N);
    intial();
    int no;
    for(int i=1;i<=N;i++)
    {
        scanf("%d",&no); v[i]=no; rem[i]=no;

    }
   int q;
    cin>>q;
    while(q--)
    {
        int st,p,x;
        scanf("%d %d",&st,&p);
        if(st==1)
        {
            scanf("%d",&x);

            int prev=-1,fl=0;

            while(p<=N&&fl==0)
            {

               if(rem[p]<=x)
               {
                   x-=rem[p];
                   rem[p]=0;
                   if(prev!=-1)
                    par[prev]=p;

                    prev=p;
                    int w=getpar(p);
                    p=(w==p? p+1:w);

               }
               else
               {
                 rem[p]-=x,x=0;
                 par[prev]=p;
                 fl=1;
               }
            }
        }
        else
            printf("%d\n",v[p]-rem[p]);
    }
}

