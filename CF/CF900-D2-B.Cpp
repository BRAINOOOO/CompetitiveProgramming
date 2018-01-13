/*
explanation : it is just long division with decimals
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
vector<ll> v;
int vis[100000+9];
int main()
{
     ll a,b,c;
    cin>>a>>b>>c;

    ll up=a;
    ll down=b;
    ll tup=up;
    ll tdown=down;
    ll u,ui;
    int flag=0;
    while(1)
    {
        vis[tup]=1;

        if(tup<tdown)
        {
            flag=1;
          int f=0;
           while(tup<tdown)
           {
               tup*=10;
               if(f)
                v.pb(0);
               f=1;
           }
        }
            u= tup/tdown;
            if(flag)
                v.pb(u);
            ui= u*down;
            tup= tup-ui;
            if(tup==0)
            {
                v.pb(0);
                break;
            }
            if(vis[tup])
                break;
            tdown=down;
        }
        string ans="";
        for(int i=0;i<sz(v);i++)
        {
           string s1= to_string(v[i]);
            ans+=s1;
        }
        for(int i=0;i<sz(ans);i++)
        {
            if(ans[i]-'0'==c)
            {
                cout<<i+1<<endl;
                return 0;
            }
        }
        cout<<"-1\n";
}
