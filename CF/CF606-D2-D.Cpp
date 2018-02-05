/*
explanation : simply it depends on MST logic i can ignore edge with cost x from MST and accept edge with cost y and x is less than y 
if x connects 2 nodes already connected before so thats what i will do first of all i will connect all the MST nodes stated then 
for each edge out of MST i will try to put it between 2 nodes the max edge betwwen the 2 nodes is less than it ( why ? to not use 
it in MST and leave one of the MST edges ) if i couldn't do that so the answer is -1 .
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
int countNumBit1(ll mask) {int ret=0; while (mask) 	{mask &= (mask-1ll);++ret;	}return ret;}
map< ll,pair<ll,ll> > ans;
vector< pair< pair<ll,ll> ,ll> > v;
int main()
{
    int n,m;
    cin>>n>>m;
    ll w,inc;
    for(int i=0;i<m;i++)
    {
        cin>>w>>inc;
        v.pb(mp(mp(-inc,w),i));
    }
    sort(all(v));
    int id=1;
    for(int i=0;i<m;i++)
    {
        if(v[i].first.first==-1)
        {
            int index=v[i].second;
            ans[index]=mp(id,id+1);
            id++;
        }
    }
    id=1;
    ll nx=id+2;
    ll mx=max(v[0].first.second,v[1].first.second);
    int j=2;
    for(int i=n-1;i<m;i++)
    {
        ll index=v[i].second;
        ll no=v[i].first.second;
         if(id==nx-1)
        {
            nx++;
            mx=max(mx,v[id].first.second);
            id=1;
        }
        if(no<mx)
        {
            cout<<"-1";
             return 0;
        }
        ans[index]=mp(id,nx);
        id++;
    }
      for(int i=0;i<m;i++)
            cout<<ans[i].first<<" "<<ans[i].second<<endl;
}
