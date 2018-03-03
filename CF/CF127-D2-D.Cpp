/*
explanation : off course i can get each common prefix with suffix not only the longest and i can get the frequency of each prefix so from
here i can know whether this common prefix with suffix exists in the middel or not.
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
vector<int> v;
int freq[1000009];
vector<int> compF(string pat)
{
    int m=sz(pat);
    vector<int> F(m);
    for(int i=1,k=0;i<m;i++)
    {
        while(k>0&&pat[i]!=pat[k])
            k=F[k-1];
        if(pat[i]==pat[k])
            F[i]=++k;
        else
            F[i]=k;
    }
    return F;
}
int main()
{
    string st;
    cin>>st;
    int n=sz(st);
    vector<int> F=compF(st);
    int X=F[n-1];
    if(X>0)
        v.pb(X);
    while(X>0)
    {
        X=F[X-1];

        if(X>0)
        v.pb(X);
    }
    for(int i=0;i<n;i++)
        freq[F[i]]++;
    for(int i=n-1;i>0;i--)
        freq[F[i-1]]+=freq[i];
    for(int i=0;i<sz(v);i++)
    {
        if(freq[v[i]]-1 >0)
         {
             cout<<st.substr(0,v[i])<<endl;
             return 0;
         }
    }
    cout<<"Just a legend\n";
}
