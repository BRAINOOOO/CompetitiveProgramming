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
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
ll n,m,par[100009],rnk[100009],arr[100009];
vector< pair<int,int> > v1;
vector<vector<int> > v(100009);
ll ans;
int getpar(int n)
{
    if(par[n]==n)
        return n;
    return par[n]=getpar(par[n]);
}
void lnk(int a,int b,int cost)
{
     a=getpar(a);
     b=getpar(b);

    if(a==b)
        return;

    ans+= 1ll*rnk[a]*rnk[b]*cost;
    if(rnk[a]>=rnk[b])
    {
        rnk[a]+=rnk[b];
        rnk[b]=0;
        par[b]=a;
    }
    else
    {
        rnk[b]+=rnk[a];
        rnk[a]=0;
        par[a]=b;
    }
}

void I()
{
    for(int i=1;i<=n;i++)
        par[i]=i,rnk[i]=1;
}
int main()
{
    cin>>n>>m;

    I();
    int no;
    for(int i=1;i<=n;i++)
    {
        cin>>no;
        arr[i]=no;
        v1.pb(mp(no,i));
    }
    sort(allr(v1));
    int f,t;
    for(int i=0;i<m;i++)
    {
        cin>>f>>t;
        v[f].pb(t);
        v[t].pb(f);
    }

    for(int i=0;i<n;i++)
    {
        int node=v1[i].second;

        for(int j=0;j<sz(v[node]);j++)
        {
            int nw=v[node][j];

            if(arr[node]>arr[nw])
                continue;

            lnk(node,nw,arr[node]);
        }


    }
    double res;
    res= (2.0*ans)/(n*(n-1));
    cout<<fixed<<setprecision(4)<<res <<endl;




}

