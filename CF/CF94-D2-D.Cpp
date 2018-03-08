/*
explanation : here the idea is if i have a bottle and i pour from it before and the remaining is greater than the needed so
i have to pour from it more than 2 times which is wrong so the answer will be no.
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
double M[59],W[59];
vector< vector<pair<int,double>> > ans(59);
int main()
{
    int n,m,w;
    cin>>n>>w>>m;

    double av=((w*n)+0.0)/m;

    for(int i=0;i<n;i++)
        W[i]=w;
    for(int i=0;i<m;i++)
        M[i]=av;
   int goo=m;
    for(int i=0,j=0;;)
    {
        if(i==n)
         break;
        if(dcmp(W[i],M[j])==1&&W[i]!=w)
        {
           cout<<"NO\n";
           return 0;
        }
        else if(dcmp(W[i],M[j])==1&&W[i]==w)
        {

            ans[j].pb(mp(i+1,M[j]));
            W[i]-=M[j];

            M[j]=0;
            j++;
        }
        else if(dcmp(W[i],M[j])==0)
        {
            ans[j].pb(mp(i+1,W[i]));
            M[j]=0;
            W[i]=0;
            i++;
            j++;
        }
        else if(W[i]<M[j])
        {
            ans[j].pb(mp(i+1,W[i]));
            M[j]-=W[i];
            W[i]=0;
            i++;

        }
    }
    cout<<"YES\n";
    for(int j=0;j<m;j++)
    {
        for(int i=0;i<sz(ans[j]);i++)
            cout<<fixed<<setprecision(7)<<ans[j][i].first<<" "<<ans[j][i].second<<" ";
        cout<<endl;
    }
}
