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
int n,m,k;
map<int,int> A,B;
vector<pair<int,pair<int,int> >> v;
int main()
{
    cin>>n>>m>>k;
    int no;
    for(int i=0;i<n;i++)
    {
        cin>>no;
        A[no]++;
    }
    for(int i=0;i<m;i++)
    {
        cin>>no;
        B[no]++;
    }

   int st=-1,l=0;
   for(auto i=A.begin();i!=A.end();i++,l++)
   {
       int val=(*i).first;
       int cntA=(*i).second;
       int cntB;
       if(B.find(val)==B.end())
        cntB=0;
       else
        cntB=B[val];
      if(cntA>cntB)
      v.pb(mp(val,mp(cntA-cntB,0)));
      else if(cntB>cntA)
        v.pb(mp(val,mp(0,cntB-cntA)));

     B[val]=0;

   }
   for(auto i=B.begin();i!=B.end();i++)
   {
       int val=(*i).first;
       int cntB=(*i).second;
       if(cntB==0)
        continue;
       v.pb(mp(val,mp(0,cntB)));
   }
   sort(all(v));
   int cntB=0; int cntA=0;
   for(int i=0;i<sz(v);i++)
   {
      // cout<<v[i].first<<" "<<v[i].second<<endl;
       if(v[i].second.first>v[i].second.second)
       {
          if(cntA>cntB)
          {
              cntA+=v[i].second.first;
              cntB+=v[i].second.second;
          }
          else
          {
              cntA=v[i].second.first;
              cntB=0;
          }
          continue;
       }
       cntA+= v[i].second.first;
       cntB+= v[i].second.second;


   }

   if(cntA>cntB)
    cout<<"YES\n";
   else
    cout<<"NO\n";
}




