/*
explanation : here first you may think to dfs from each node and calculate the sum of each node sub tree 
and then check if the 2 nodes are not at the same sub tree and maximize okay it doesn't fit in time off course
but i want to drive you to observe something which is the sum of a subtree is the sum of its children subtrees plus
its node so there is overlap i can easily do it button up dp with dfs and all the children of a certain node are not at
the same subtree so its okay but not only the child subtree only but any subtree in a child subtree could be with any subtree
and the other child subtree so to maxmize if i will take a sub tree from a child and other subtree from another child i need the 
max one so i will store 2 things the max sub tree in this node tree and the sum of this tree but why i stored the sum bec the max
can be the max among all the max of the children subtree or the current tree which is the sum of all the children subtrees plus its 
node :) , Draw the tree and trace.

complexity : Nlog(N)
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
const ll inf=100000000000000000,MAX=200000+9;
ll vis[MAX],sum[MAX],maxi[MAX],arr[MAX];
vector<ll> v[MAX];
vector<ll> ans;
void solve(int id)
{
    vis[id]=1;
    multiset<ll> v1;
    ll mx=-inf;
    for(int i=0;i<sz(v[id]);i++)
    {
        if(vis[v[id][i]])
            continue;

        solve(v[id][i]);

        mx=max(mx,maxi[v[id][i]]);

        sum[id]+=sum[v[id][i]];

        v1.insert(maxi[v[id][i]]);

    }
    sum[id]+=arr[id];
    maxi[id]=max(sum[id],mx);
    if(sz(v1)>=2)
    {
       ll a=*(v1.rbegin());
       auto it=v1.end();
       it--;
        v1.erase(it);
      ll  b=*(v1.rbegin());

        ans.pb(a+b);
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    ll f,t;
    for(int i=0;i<n-1;i++)
    {
        cin>>f>>t;
        v[f].pb(t);
        v[t].pb(f);
    }
      solve(1);
   ll mx=-inf;
   if(sz(ans)==0)
    {
       cout<<"Impossible\n";
       return 0;
    }
   for(int i=0;i<sz(ans);i++)
   {
       mx=max(mx,ans[i]);
   }
  cout<<mx<<endl;
}
