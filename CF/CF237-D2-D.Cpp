// ICPC champion is here
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
int dcmp(double a,double b){   return fabs(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
ll getBit(ll num, int idx) {return ((num >> idx) & 1ll) == 1;}
ll setBit1(ll num, int idx) {return num | (1ll<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
int n,vis[100009];
vector< vector<pair<int,int>> > v(100009);
vector<pair<int,int> > ans,edd;
void bfs()
{

    queue<pair<int,pair<int,int>>> q;
    q.push(mp(v[1][0].first,mp(1,v[1][0].second)));
    vis[v[1][0].first]=1;
    while(!q.empty())
    {

        int fr=q.front().second.first;
        int sec=q.front().second.second;
        int ed=q.front().first;
        q.pop();

        for(int i=0;i<sz(v[fr]);i++)
        {
            int nw=v[fr][i].second;
            int e=v[fr][i].first;

            if(vis[e])
                continue;
            vis[e]=1;
            ans.pb(mp(ed,e));
            q.push(mp(e,mp(fr,nw)));
        }

        for(int i=0;i<sz(v[sec]);i++)
        {
            int nw=v[sec][i].second;
            int e=v[sec][i].first;

            if(vis[e])
                continue;
             vis[e]=1;
            ans.pb(mp(ed,e));
            q.push(mp(e,mp(fr,nw)));
        }
    }
}












int main()
{
    int n;
   cin>>n;
   int f,t;
   for(int i=0;i<n-1;i++)
   {
       cin>>f>>t;
       edd.pb(mp(f,t));
       v[f].pb(mp(i+1,t));
       v[t].pb(mp(i+1,f));
   }
   bfs();
   cout<<n-1<<endl;

   for(int i=0;i<n-1;i++)
   {
       cout<<2<<" "<<edd[i].first<<" "<<edd[i].second<<endl;
   }

   for(int i=0;i<sz(ans);i++)
    cout<<ans[i].first<<" "<<ans[i].second<<endl;

}








