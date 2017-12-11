/*
explanation : here the idea is if we have a range ( 0 , M ) and we want to know how
many numbers in this range divisible by X so simply you will make M/X but here the 
ranges wont start with zero so you will do ( a,b) b/x-(a-1)/x but we arenot allowed
to check every pair so we note that if a number will make greater than k so no need 
to go farther so i will get the farest number that can do k and the nearest one then
count range.

complexity : O( n*log(n) )
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
vector<int > v;
int x,k;
ll bin(int val,int f,int n)
{
    int l=0,h=n-1,ans=-1;
     while(l<=h)
    {
       int mid=(l+h)/2;
        if(v[mid]<val)
            l=mid+1;
        else if(v[mid]/x-(val-1)/x==k)
        {
            if(!f)
                l=mid+1,ans=mid;
            else
                h=mid-1,ans=mid;
        }
        else if(v[mid]/x-(val-1)/x>k)
            h=mid-1;
        else if(v[mid]/x-(val-1)/x<k)
            l=mid+1;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n>>x>>k;
    int no;
    for(int i=0;i<n;i++)
    {
        cin>>no;
        v.pb(no);
    }
    sort(all(v));
   ll cnt=0;
    for(int i=0;i<n;i++)
    {
        ll a=bin(v[i],0,n);
        ll b=bin(v[i],1,n);
        if(a!=-1&&b!=-1)
            cnt+=(a-b+1);
    }
    cout<<cnt<<endl;
}
