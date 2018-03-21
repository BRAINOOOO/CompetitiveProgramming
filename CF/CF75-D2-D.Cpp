/*
explanation : the idea is if the sum of elemrnts i take it sofar is -ve so why should i take it, it only reduces my summation sofar 
and if its positive but the summation from the right is greater so i will choose to take the greater .
see Kadane's algorithsm for MSS and its proof
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
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(ll mask) {int ret=0; while (mask) 	{mask &= (mask-1ll);++ret;	}return ret;}
ll inf=100000000000000,arr[250000+9];
typedef struct
{
    ll maxright,maxleft,tot,maxgeneral;
}node;
vector< node > v1(59);
vector< vector<ll> > v(59);
int main()
{
    int n,m;
    cin>>n>>m;
    int l,no;
    for(int i=1;i<=n;i++)
    {
        cin>>l;

        for(int j=0;j<l;j++)
        {
            cin>>no;
            v[i].pb(no);
        }
    }


    for(int i=1;i<=n;i++)
    {
        ll tot=0,maxleft=-inf,maxright=-inf;
        for(int j=0;j<sz(v[i]);j++)
        {
            tot+=v[i][j];

            maxleft=max(tot,maxleft);

        }
        tot=0;
        for(int j=sz(v[i])-1;j>=0;j--)
        {
            tot+=v[i][j];

            maxright=max(tot,maxright);


        }

        v1[i].maxleft=maxleft;
        v1[i].maxright=maxright;
        v1[i].tot=tot;

        int maxsofar=-inf,maxendhere=0;

        for(int j=0;j<sz(v[i]);j++)
        {
            maxendhere+=v[i][j];
            maxsofar=max(maxsofar,maxendhere);
            if(maxendhere<0)
                maxendhere=0;
        }
        v1[i].maxgeneral=maxsofar;
    }
        for(int i=0;i<m;i++)
        {
            cin>>arr[i];
        }
        ll mx=-inf;
        ll  maxsofar=max(v1[arr[0]].maxright,0ll);
        mx=max(mx,v1[arr[0]].maxgeneral);

       for(int i=1;i<m;i++)
       {
           int id=arr[i];

           ll e=maxsofar+v1[id].maxleft;
           mx=max(mx,v1[id].maxgeneral);
           mx=max(mx,e);
           maxsofar=max(maxsofar+v1[id].tot,max(v1[id].maxright,0ll));
       }
    cout<<mx<<endl;
}
