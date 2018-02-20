/*
explanation : I'll write in details. We consider each possible split set of all bidders into 3 (possibly empty) subsets.
Call them A, B and C. We assume that every bidder in A has made bid strictly more than b, each member of B made a bid
equal to b and each member of C has bid strictly less than b. Now for each split, we calculate it's probability.
First of all, we are not interested in splits, where A contains more than 1 element, because it would mean that b
is no longer a second best. Also, set B can't be empty. One more thing to check is that if A is empty, than B must contain 
at least 2 elements. If all of these constraints are satisfied, then we just calculate probability the following way: For
each member of A, calculate the probability that it's bid is more than b and multiply these probabilities, as they're mutually 
independent of each other. (Product of an empty set is supposed to be 1) Let's do the similar thing for B and C and in the end
just multiply all these probabilities. Then we have an outer loop to sum up all those products and it's gonna be our answer.

One more important thing to note is how we implement the splitting into 3 parts and how many splits are there. As we said that
A is either empty or contains just a single element, we have (n + 1) choices or A: Either be empty, or contain any bidder out of
n possibilities. Once we pick A, we have either (n - 1) or n more bidders. Than we have either 2n - 1 or 2n possibility for B.
After we pick A and B, the others will automatically go to C. From here we see that number of states is O(2n·n) and we also see 
the way to implement it easily: First we make an outer loop for A, and then inside we make inner loop of bitmasks for B, after 
which C becomes fixed.

complexity : O( 2^n*n*n*max(R-l+1) )
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
int n;
double L[7],R[7];
double high(int i,int b)
{
    if(b>R[i])
        return 0;
    if(b<L[i])
        return 1;
    return  (R[i]-b)/(R[i]-L[i]+1);
}
double low(int i,int b)
{
    if(b<L[i])
        return 0;
    if(b>R[i])
        return 1;
    return  (b-L[i])/(R[i]-L[i]+1);
}
double prob(vector<int> v,int b)
{
    if(sz(v)==n)
        return 1;
    int vis[7];
    clr(vis,0);
    for(int i=0;i<sz(v);i++)
        vis[v[i]]=1;
    double p=1,res=0.0,pp=1.0;
    for(int i=0;i<n;i++)
    {
        p=1.0;
        if(vis[i])
        continue;
       pp*=low(i,b);
       p*=high(i,b);
        for(int j=0;j<n;j++)
        {
            if(vis[j]||j==i)
                continue;
            p*= low(j,b);
        }
        res+= p;
    }
    if(sz(v)==1)
        pp=0;
    res+= pp;
    return res;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>L[i]>>R[i];
    }
    double ans=0.0;
    for(int b=1;b<=10000;b++)
    {
          double res=0.0;
        for(int i=1;i<(1<<n);i++)
        {
            vector<int> v1;
            int fl=0;
            double p=1.0;
            for(int j=0;j<n;j++)
            {
                if(getBit(i,j))
                {
                    if(L[j]<=b&&b<=R[j])
                    {
                        v1.pb(j);
                       p*= 1/(R[j]-L[j]+1);
                    }
                    else
                    {
                        fl=1;
                       break;
                    }
                }
            }
            if(fl)
                continue;
           res+= p*prob(v1,b);
        }
        ans+=res*b;
    }
    cout<<fixed<<setprecision(9)<<ans<<endl;
}
