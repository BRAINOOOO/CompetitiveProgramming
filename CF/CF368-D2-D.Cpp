/*
algo used KMP with a some changes
*/

// ICPC Champion is here

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
//#define     point                    complex<long double>
#define      PI                      acos(-1)
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
int A[200009],B[200009];
map< int,int> previs,vis;
set<int> s;
int main()
{
    M();
    int n,m,p;
    cin>>n>>m>>p;

    for(int i=1;i<=n;i++)
    {
        cin>>A[i];
        s.insert(i);
    }
    for(int i=1;i<=m;i++)
    {
        cin>>B[i];
        previs[B[i]]++;
    }
   vector<int> ans;
    while(!s.empty())
   {


       int st=(*s.begin());
       int cnt=0;
       vis.clear();
       for(int i=st,j=st;i<=n;i+=p)
       {

          int num=A[i];
          s.erase(s.find(i));
          vis[num]++;
          cnt++;
          //cout<<i<<" "<<j<<endl;
          if(vis[num]<=previs[num])
          {
            ;
          }
          else
          {
              while(vis[num]>previs[num]&&j<=n)
              {

                  vis[A[j]]--;
                  j+=p;
                  cnt--;
              }

          }

          if(cnt==m)
          {
             ans.pb(j);

          }
       }

   }
   sort(all(ans));
   cout<<sz(ans)<<endl;
   for(int i=0;i<sz(ans);i++)
    cout<<ans[i]<<" ";
}










