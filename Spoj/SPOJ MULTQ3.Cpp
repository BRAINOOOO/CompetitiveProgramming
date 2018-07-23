#include <bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<map>
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
const double eps= (1e-5);
using namespace std;
int dcmp(long double a,long double b){   return fabsl(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
ll getBit(ll num, int idx) {return ((num >> idx) & 1ll) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
pair<int,pair<int,int>> tree[500009];
int  lazy[500009];
int n,q;

void down(int p)
{
    if(lazy[p]%3==0)
        return;

        int v=lazy[p]%3,val[4],z,o,t;

         val[0]=tree[p*2].first;
         val[1]=tree[p*2].second.first;
         val[2]=tree[p*2].second.second;

         z= val[((0-v)+3)%3];
         o=  val[((1-v)+3)%3];
         t=  val[((2-v)+3)%3];

         tree[p*2].first=z;
         tree[p*2].second.first=o;
         tree[p*2].second.second=t;

         val[0]=tree[p*2+1].first;
         val[1]=tree[p*2+1].second.first;
         val[2]=tree[p*2+1].second.second;

         z=  val[((0-v)+3)%3];
         o=  val[((1-v)+3)%3];
         t=  val[((2-v)+3)%3];

         tree[p*2+1].first=z;
         tree[p*2+1].second.first=o;
         tree[p*2+1].second.second=t;

    lazy[p*2]+=v;
    lazy[2*p+1]+=v;

    lazy[p]=0;
}

void build(int s,int e,int p)
{

    if(s==e)
    {
        tree[p].first=1;
        return;
    }

    int mid=(s+e)/2;

    build(s,mid,p*2);
    build(mid+1,e,p*2+1);

    tree[p].first=tree[p*2].first+tree[p*2+1].first;

}

void update(int s,int e,int p,int a,int b)
{
     if(s>b||e<a)
        return;
      int z,o,t,tempO,tempt;

     if(s>=a&&e<=b)
     {

         z=tree[p].first;
         o=tree[p].second.first;
         t=tree[p].second.second;

         tempO=o;
         tempt=t;

         o=z;
         t=tempO;
         z=tempt;

         tree[p]=mp(z,mp(o,t));
         lazy[p]++;
         return ;
     }

    int mid=(s+e)/2;

    down(p);

    update(s,mid,p*2,a,b);
    update(mid+1,e,p*2+1,a,b);

   tree[p].first=tree[p*2].first+tree[p*2+1].first;
   tree[p].second.first=tree[p*2].second.first+tree[p*2+1].second.first;
   tree[p].second.second=tree[p*2].second.second+tree[p*2+1].second.second;


}
int query(int s,int e,int p,int a,int b)
{
    if(s>b||e<a)
        return 0;

    if(s>=a&&e<=b)
    {

        return tree[p].first;

    }

    int mid=(s+e)/2;

    down(p);

    return query(s,mid,p*2,a,b)+query(mid+1,e,p*2+1,a,b);
}

















int main()
{
    scanf("%d %d",&n,&q);

    build(0,n-1,1);

    while(q--)
    {
       int st,a,b;
       scanf("%d %d %d",&st,&a,&b);

       if(st==0)
       {
           update(0,n-1,1,a,b);
       }
       else
        printf("%d\n",query(0,n-1,1,a,b));
    }
}










