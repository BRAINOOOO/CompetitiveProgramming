/*
topic : segment tree( with lazy propagation )

explanation : the idea of the problem is that if the intial array have different values we couldnt make lazy bec 
i cant express the range with one value but here since the intial array have the same value so adding some value 
to the range will make them the same so i can express the range at lazy.

complexity : O( T*q*log(n) )
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
ll tree[262143+9],lazy[262143+9],val;
void spread(int s,int e,int p)
{
     if(lazy[p]!=0)
    {
        tree[p]+= (e-s+1)*lazy[p];
        if(s!=e)
        {
            lazy[2*p]+=lazy[p];
            lazy[2*p+1]+=lazy[p];
        }
        lazy[p]=0;
    }
}
void lazyupdate(int a,int b,int s,int e,int p)
{
   spread(s,e,p);
    if(a>e||b<s||s>e)
        return ;
    if(a<=s&&b>=e)
    {
        tree[p]+=(e-s+1)*val;
        if(s!=e)
        {
            lazy[p*2]+=val;
            lazy[2*p+1]+=val;
        }
        return ;
    }
    int mid=(s+e)/2;
    lazyupdate(a,b,s,mid,2*p);
    lazyupdate(a,b,mid+1,e,2*p+1);
    tree[p]=tree[2*p]+tree[2*p+1];
}
ll lazyquery(int a,int b,int s,int e,int p)
{
    if(a>e||b<s||s>e)
        return 0;
    spread(s,e,p);
    if(a<=s&&b>=e)
        return tree[p];
    int mid=(s+e)/2;
    return lazyquery(a,b,s,mid,p*2)+lazyquery(a,b,mid+1,e,p*2+1);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
     clr(tree,0);
     clr(lazy,0);
    int n,qy;
    cin>>n>>qy;
    int state,p,q;
    while(qy--)
    {
        cin>>state>>p>>q;
        p--;
        q--;
        if(!state)
        {
            cin>>val;
            lazyupdate(p,q,0,n-1,1);
        }
        else
          {
             cout<< lazyquery(p,q,0,n-1,1)<<endl;
          }
    }
    }
}
