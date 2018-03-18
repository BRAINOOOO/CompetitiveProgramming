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
ll pos[524287+9],tree[524287+9],arr[524287+9];

ll build(int st,int en,int root)
{
   if(st==en)
   {
       tree[root]=1;
       return st;
   }
   ll mid=(st+en)>>1;
   build(st,mid,root*2);
   build(mid+1,en,root*2+1);
   tree[root]=tree[root*2]+tree[root*2+1];
   return tree[root];
}
void update(int id,int v,int st=1,int en=200000,int root=1)
{

    if(id<st||id>en)
        return ;
    if(st==en)
    {
        tree[root]+=v;
        return;
    }
    int mid=(st+en)>>1;
    update(id,v,st,mid,root*2);
    update(id,v,mid+1,en,root*2+1);
   tree[root]=tree[root*2]+tree[root*2+1];
}
ll query(int v,int st=1,int en=200000,int root=1)
{
    if(st==en)
        return st;


    int mid=(st+en)>>1;

    if(v<=tree[root*2])
        return query(v,st,mid,root*2);
    else
    {
        return query(v-tree[root*2],mid+1,en,root*2+1);
    }
}
int main()
{

    int T;
    cin>>T;

    while(T--)
    {
       int n;
       cin>>n;

       clr(tree,0);
       build(1,200000,1);

       int x;
       for(int i=1;i<=n;i++)
       {
           cin>>arr[i];

       }

       for(int i=n;i>=1;i--)
       {
           int val= i-arr[i];

          pos[i]= query(val);
          update(pos[i],-1);
       }
       for(int i=1;i<=n;i++)
       {
          cout<<pos[i]<<" ";
        }
       cout<<endl;
    }
}
