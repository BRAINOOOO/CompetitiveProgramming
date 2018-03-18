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
pair<int,int> tree[2000000],lazy[2000000];

void apply(int root,int st,int mid,int en)
{
    if(lazy[root].first==-1)
        return ;

    int r=root*2;
    int l=root*2+1;

    lazy[r].first=lazy[root].first;
    lazy[l].first=lazy[root].first;
    tree[r].first=lazy[r].first;
    tree[l].first=lazy[l].first;
    lazy[root].first=-1;
    lazy[r].second=lazy[root].second;
    lazy[l].second=lazy[root].second;
    tree[r].second=lazy[r].second;
    tree[l].second=lazy[l].second;
    lazy[root].second=-1;

}
void update(int l,int r,int val,int st,int en,int root=1)
{

    if(l>en||r<st)
        return ;
    if(st==en)
    {
        if(tree[root].first<=val)
        {
           tree[root].first=val;
           tree[root].second=val;
           lazy[root].first=val;
           lazy[root].second=val;

        }

        return;
    }

    if(l<=st&&en<=r)
    {
        if(tree[root].first<=val)
        {
           tree[root].first=val;
           tree[root].second=val;
           lazy[root].first=val;
           lazy[root].second=val;
           return;
        }
        else if(tree[root].second>=val)
            return ;
    }

    int mid=(st+en)>>1;

    apply(root,st,mid,en);

    update(l,r,val,st,mid,root*2);
    update(l,r,val,mid+1,en,root*2+1);

    tree[root].first=max(tree[root*2].first,tree[root*2+1].first);
    tree[root].second=min(tree[root*2].second,tree[root*2+1].second);

}


int query(int l,int r,int val,int st,int en,int root=1)
{

    if(l>en||r<st)
        return 0;

    if(st==en)
    {

        if(tree[root].first<=val)
        {
             return (en-st+1);
        }
        else
            return 0;
    }

    if(l<=st&&en<=r)
    {
        if(tree[root].first<=val)
        {
             return (en-st+1);
        }
        else if(tree[root].second>=val)
            return 0;
    }
    int mid= (st+en)>>1;
    apply(root,st,mid,en);
    return query(l,r,val,st,mid,root*2)+query(l,r,val,mid+1,en,root*2+1);
}
int main()
{
    int T;
    cin>>T;
    int num;
    while(1)
    {
       cin>>num;
       if(num==0)
        break;
       int ans=0,l,r,h;
       clr(lazy,-1);
       clr(tree,0);
       for(int i=0;i<num;i++)
       {
           cin>>l>>r>>h;
           ans+=query(l+1,r,h,1,100000);
           update(l+1,r,h,1,100000);
       }
       cout<<ans<<endl;
    }
}
