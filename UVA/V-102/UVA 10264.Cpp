/*
first understand what N-D means then yu will realize that it can be with D&C approach
*/


// ICPC Champion is here

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
int dcmp(long double a,long double b){   return fabsl(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
ll getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
ll setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
int arr[1000000],arr2[1000000],vr[1000000];
vector< vector<int> > v;
int idx;
void fun(int n,int st)
{

    if(n==0)
    {
        int w;
        cin>>w;
        arr[st]=w;
        idx++;
        return;
    }

        fun(n-1,st);
        fun(n-1,st+vr[n-1]);
    int j,l;
    j=st;
    l=st+vr[n-1];
    for(int i=0;i<vr[n-1];i++,l++,j++)
    {
        int fr=j;
        int to=l;
        v[fr].pb(to);
        v[to].pb(fr);

    }
}




















int main()
{

    int n;
    vr[0]=1;
    for(int i=1;i<=14;i++)
        vr[i]=2*vr[i-1];

    while(cin>>n)
    {

        v.clear();
        v.resize(1000000);


        idx=0;
        fun(n,1);




        for(int i=1;i<=idx;i++)
        {
            int s=arr[i];

            for(int j=0;j<sz(v[i]);j++)
            {
                s+= arr[v[i][j]];

            }
            arr2[i]=s;
        }

        int mx=-1;

        for(int i=1;i<=idx;i++)
        {

            for(int j=0;j<sz(v[i]);j++)
            {

                int ni= arr2[v[i][j]];
                int me= arr2[i];
                int wi= me+ni-arr[i]-arr[v[i][j]];
                mx=max(mx,wi);
            }
        }

        cout<<mx<<endl;
    }
}
