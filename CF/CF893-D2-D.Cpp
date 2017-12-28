/*
explanation : first we can simply dont add any deposit at any cell except for ai==0 here we will just 
add deposit to make it equal to zero so if it is initially valid it will always be valid this way, but
it is not optimal as we can add some value when ai=0 to increase the chance of not adding deposit at 
next zero but we afraid that it goes greater than d so we will preprocess maxsuffix array to add the 
max deposit to dont be negative and possible to not go greater than the limit.

complexity : O(n)
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
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
int setBit0(int num, int idx) {return num & ~(1<<idx);}
int flipBit(int num, int idx) {return num ^ (1<<idx);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
ll sum[100000+9],mx[100000+9];
int main()
{
    int n,d;
    cin>>n>>d;
    int no;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        cin>>no;
        v.pb(no);
    }
    sum[0]=v[0];
    for(int i=1;i<n;i++)
    {
        sum[i]=sum[i-1]+v[i];
    }
    mx[n-1]=sum[n-1];
    for(int i=n-2;i>=0;i--)
    {
        mx[i]=max(mx[i+1],sum[i]);
    }
    int ans=0,add=0;
    for(int i=0;i<n;i++)
    {
        if(sum[i]+add>d)
        {
            cout<<"-1\n";
            return 0;
        }
        if(!v[i]&&sum[i]+add<0)
        {
           int tadd= d-mx[i]-add;
            if(tadd+sum[i]+add<0)
            {
                cout<<"-1\n";
                return 0;
            }
            add+=tadd;
            ans++;
        }
    }
      cout<<ans<<endl;
}
