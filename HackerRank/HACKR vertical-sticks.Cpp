/*
explanation : the idea depends mainly on the linearity of expectation 
                
                E(V(yp1,...,ypn)) = E(v1+v2+...+vn) = ( E(v1|y)+E(v2|y)...+E(vn|y) )
                
    so now i have to calculate E( v1|y ) i will fix a y to it and possible values which are seg loop 
    and off course to multiplied by the probability of having thiy which is 1/n  :)
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
int n,lessthan[1009];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
     clr(lessthan,0);
     v.clear();
    cin>>n;
    int no;
    for(int i=0;i<n;i++)
    {
        cin>>no;
        v.pb(no);
        lessthan[no+1]++;
    }
    for(int i=1;i<=1000;i++)
        lessthan[i]+=lessthan[i-1];
   double ans=0.0;
    for(int id=1;id<=n;id++)
    {
        double res=0;
        for(int y=0;y<n;y++)
        {
            int Y=v[y];
            int l= lessthan[Y];
            int g= n-1-l;
            for(int seg=1;seg<=id;seg++)
            {
                if(seg-1<=l&&(g>=1||seg==id))
                {
                   int tot,tl;
                     tl=l;
                     tot=n-1;
                    double p=1.0;
                    for(int i=0;i<seg-1;i++)
                    {
                        p*=((tl+0.0)/tot);
                        tl--;
                        tot--;
                    }
                     if(id!=seg)
                    p*=((g+0.0)/(n-1-(seg-1)));
                    res+= p*seg;
                }
            }
        }
        ans+=res/n;
    }
   cout<<fixed<<setprecision(2)<<ans<<endl;
    }
}
