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
ll arr[100009],lookup[100009][29];
ll mx=0;
ll n,h;

pair<ll,ll> query(ll l,ll r)
{
    ll mx= (int)log2(r-l+1);
    if(arr[lookup[l][mx]]<arr[lookup[r-(1<<mx)+1][mx]])
        return mp(arr[lookup[l][mx]],lookup[l][mx]);

    return mp(arr[lookup[r-(1<<mx)+1][mx]],lookup[r-(1<<mx)+1][mx]);
}


void SparseTable()
{
    for(int i=0;i<n;i++)
        lookup[i][0]=i;

    for(int j=1;(1<<j)<=n;j++)
    {
        for(int i=0;(i+(1<<j)-1)<n;i++)
        {
            if(arr[lookup[i][j-1]]<arr[lookup[i+(1<<(j-1))][j-1]])
            lookup[i][j]=lookup[i][j-1];
            else
                lookup[i][j]=lookup[i+(1<<(j-1))][j-1];

        }
    }
}

void DC(ll l,ll r)
{


   if(r<l)
    return;

   pair<ll,ll> p= query(l,r);
   mx=max(mx,(r-l+1)*p.first);
   DC(l,p.second-1);
   DC(p.second+1,r);



}

int main()
{


    while(cin>>n)
    {
        if(!n)
            break;
       for(int i=0;i<n;i++)
       {
         cin>>arr[i];
       }

      // build(0,n-1,1);
       clr(lookup,0);
      SparseTable();
      mx=0;

      DC(0,n-1);


    cout<<mx<<endl;
    }
}






