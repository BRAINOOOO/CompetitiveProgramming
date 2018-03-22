/*
explanation : the idea is if i enter an index in the array with the same operation i mean i need to subtract or add so it will always
add to y a fixed value from here the essence of dp comes .
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
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(ll mask) {int ret=0; while (mask) 	{mask &= (mask-1ll);++ret;	}return ret;}
vector< int > v(200009);
ll arr[200009][2],vis[200009][2],vis2[200009][2],n;
ll inf=100000000000000000;
ll solve(int id,int f)
{
    if(id<=0||id>n)
        return 0;

     if(vis[id][f])
     {
         arr[id][f]=-1;
         vis[id][f]=0;
         return -1;
     }

     vis[id][f]=1;

    if(vis2[id][f])
        return arr[id][f];

    vis2[id][f]=1;

    if(f)
    {
      ll res=solve(id+v[id],!f);

      if(res==-1)
      {
          arr[id][f]=-1;
      }
      else
        arr[id][f]=v[id]+res;


    }

    else
    {

     ll res=solve(id-v[id],!f);

      if(res==-1)
      {
          arr[id][f]=-1;
      }
      else
        arr[id][f]=v[id]+res;
    }
    return arr[id][f];
}
int main()
{
    scanf("%I64d",&n);
    int no;
    for(int i=2;i<=n;i++)
    {
        scanf("%I64d",&v[i]);
    }
    for(int i=1;i<=n-1;i++)
    {
        clr(vis,0);
        vis[1][1]=1;
        ll ans=solve(i+1,0);
        vis[1][1]=0;
        if(ans==-1)
            printf("-1\n");
        else
            printf("%I64d\n",i+ans);

    }
}
