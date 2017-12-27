/*
explanation : here the idea is if i could get all the distances sorted from each node to leaves so you can 
observe that there is a great dependency in this binary tree suppose we have a start node S we can get all
the paths leading to it for all the nodes in its subtree but what about the other nodes we can get the paths 
of the nodes in its parent subtree right we want only the right part so we can only subtract the the edge
between it and its parent and get it but it will enter the left side which i dont want to it will enter it with
H subtracted from it the the edge between it and its parent twice so i will get it and subtract it.

if you couldnt get it just trace the code and draw the tree :)

complexity : O( (n+m)*(log(n)^2) )
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
ll edg[1000000+9];
vector<ll> v[1000000+9];
vector<ll> sum[1000000+9];
ll fun(ll st,ll h)
{
    if(h<=0)
        return 0;
   int id = upper_bound(all(v[st]),h)-v[st].begin()-1;
   return (id+1)*h-sum[st][id] ;
}
int main()
{
    ll n,m;
     scanf("%I64d %I64d",&n,&m);
    for(int i=2;i<=n;i++)
        scanf("%I64d",&edg[i]);
    for(int i=n;i>=1;i--)
    {
        for(int j=i,l=0;j>=1;l+=edg[j],j>>=1)
        {

            v[j].pb(l);
            sum[j].pb(0);
        }
        sort(all(v[i]));

        for(int j=0;j<sz(v[i]);j++)
        {
            if(j>0)
           sum[i][j]=sum[i][j-1]+v[i][j];
           else
                sum[i][j]=v[i][j];
        }
    }
    ll st,h;
    for(int i=0;i<m;i++)
    {
        scanf("%I64d %I64d",&st,&h);

        ll ans= fun(st,h);

        while(st>1&&h>0)
        {
            ans-=   fun(st,h-2*edg[st]) - fun(st>>1,h-=edg[st]);
            st>>=1;
        }

        printf("%I64d\n",ans);
    }
}
