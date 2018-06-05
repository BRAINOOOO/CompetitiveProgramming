// ICPC champion is here
#include <bits/stdc++.h>
#include<iostream>
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
#define     point                    complex<long double>
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
int n,m,fl,vis[100009],a[100009],cnt;
vector< vector<int> > v(100009),v1(100009);
vector<int> ans;
int in[100009];

int id=1;


void topo()
{
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(in[i]==0)
            q.push(i);
    }

    while(!q.empty())
    {
        int cur=q.front();
        q.pop();

        ans.pb(cur);

        for(int i=0;i<sz(v1[cur]);i++)
        {
            in[v1[cur][i]]--;
            if(in[v1[cur][i]]==0)
                q.push(v1[cur][i]);
        }
    }

}

void dfs(int no)
{
    vis[no]=1;
    cnt++;
    for(int i=0;i<sz(v[no]);i++)
    {
        int node=v[no][i];
        if(!(a[node]==node||a[node]==a[no]))
           fl=1;
         if(a[node]==node)
         {
             v1[a[no]].pb(node);
             in[node]++;
         }
         else
         {
             v1[node].pb(a[no]);
             in[a[no]]++;
         }
        dfs(node);
    }
}

int main()
{

    cin>>n>>m;
    int f,t;
    for(int i=0;i<m;i++)
    {
        cin>>f>>t;
        v[f].pb(t);
    }

     for(int i=1;i<=n;i++)
        cin>>a[i];
     fl=0;
     for(int i=1;i<=n;i++)
     {
         if(!vis[i])
         {
            cnt=0;
           dfs(i);

         }
     }
     if(fl)
    {
       cout<<"-1\n";
       return 0;
    }

     topo();
     cout<<sz(ans)<<endl;
     for(int i=sz(ans)-1;i>=0;i--)
        cout<<ans[i]<<endl;
}
