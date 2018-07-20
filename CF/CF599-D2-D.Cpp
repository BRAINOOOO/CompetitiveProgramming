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
ll val;
vector< pair<ll,ll> > ans;
ll mod=(1ll<<60);
long double p[5];
ll check(long double n,long double val)
{
    //cout<<m<<endl;
    long double g=n;
    g-=1;

     long double L=(g*(g+1))/2;

     p[0]=(n*L);
     p[2]=(g*(g+1)*(2*g+1))/6;


    long double m=(val-p[2]+p[0])/((n*(g+1))-L);

    if(n<m&&ceil(m)==floor(m))
        return m;
    return -1;
}


int main()
{

    M();
    cin>>val;

    ll mi=mod;
    for(int i=1;i<=10000000;i++)
    {
        if(i>=mi)
            break;
       ll m= check(i,val);

       if(m==-1)
        continue;

        mi=min(mi,m);

        ans.pb(mp(i,m));

        if(i!=m)
        {

        ans.pb(mp(m,i));
        }

    }


   sort(all(ans));
   cout<<sz(ans)<<endl;
   for(int i=0;i<sz(ans);i++)
    cout<<ans[i].first<<" "<<ans[i].second<<endl;

   // cout<<check(2,9,val)<<endl;
}



