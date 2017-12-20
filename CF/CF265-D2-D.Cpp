/*
explanation : here the idea is to note that if two numbers have gcd > 1 so there is common factor in their
prime factors so i will calculate all the prime factors for each number if and maxmize on the answer and longest
sequence sofar and all the factors should have the longest sequence so far as if i find a number have the same 
factor it will take it will take the past max sequence.

complexity : O( n*squrt(n) )
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
int arr[100000+9];
int main()
{
    int n;
    cin>>n;
    int a;
    int ans=1;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        int ta=a;
        int tmx=0;
        for(int i=2; i*i<=a;i++)
        {
            while(ta%i==0)
            {
                tmx=max(tmx,arr[i]+1);
                ta/=i;
            }
        }
        if(ta>1)
            tmx=max(tmx,arr[ta]+1);
        ans=max(ans,tmx);
        ta=a;
        for(int i=2; i*i<=a;i++)
        {
            while(ta%i==0)
            {
                arr[i]=max(arr[i],tmx);
                ta/=i;
            }
        }
        if(ta>1)
            arr[ta]=max(tmx,arr[ta]);
    }

     cout<<ans<<endl;
}
