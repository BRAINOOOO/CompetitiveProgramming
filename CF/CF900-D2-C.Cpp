/*
explanation : here the idea is if ai can be a record by removing only one element so before it there
must be only one element greater than it so if i removed this number one record will be added plus the
default records which are the records that doesn't need to remove any number to make it.

complexity : O(N*log(N))
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
set<int> s;
vector<int> v;
int vis[100000+9],defl[100000+9];
int main()
{
    int n;
    cin>>n;
    int no;
  int minn=n+1;
    for(int i=0;i<n;i++)
    {
        cin>>no;
        minn=min(no,minn);
        v.pb(no);
    }
   int def=0;
    for(int i=0;i<n;i++)
    {
        int num=v[i];
        if(sz(s)==0)
        {
            s.insert(num);
             def++;
             defl[num]=1;
            continue;
        }
        set<int> :: iterator id,id2;
       id= s.upper_bound(num);
       id2=id;
       id2++;
        if(id==s.end())
        {
            def++;
            defl[num]=1;
            s.insert(num);
            continue;
        }
       if( id2==s.end() )
       {
         int idex=(*id);
          vis[idex]++;
       }
       s.insert(num);
    }
      for(int i=0;i<n;i++)
      {
          vis[v[i]]+=def;
          if(defl[v[i]])
            vis[v[i]]-=1;
      }
       int  mx=0;
      for(int i=0;i<n;i++)
      {
          mx=max(mx,vis[v[i]]);
      }
       int  mi=n+1;
      for(int i=0;i<n;i++)
      {
          if(vis[v[i]]==mx)
            mi=min(v[i],mi);
      }
        cout<<mi<<endl;
}
