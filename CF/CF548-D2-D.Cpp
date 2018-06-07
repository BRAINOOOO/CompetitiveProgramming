// ICPC champion is here
#include <bits/stdc++.h>
#include<iostream>
#include<map>
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
#define     point                    complex<long double>
typedef  long long     ll ;
typedef  unsigned long long ull;
const double eps= (1e-10);
using namespace std;
int dcmp(long double a,long double b){   return fabsl(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
ll getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
ll setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
const int MAX=524288,inf=1e9+1000000;
int n,a[MAX][19],arr[200009],ans[200009];

int minquery(int l,int r)
{
    int siz=r-l+1;
    int mx=log2(siz);

    if(arr[a[l][mx]]<=arr[a[r-(1<<(mx))+1][mx]])
        return arr[a[l][mx]];

    return arr[a[r-(1<<(mx))+1][mx]];
}



bool ok(int l,int r,int val)
{
    int vv=minquery(l,r);

    if(vv==val)
        return 1;
    return 0;
}
int BS(int val,int id)
{

   int l=id; int h=n-1; int ans1;

   while(l<=h)
   {
       int mid=(l+h)>>1;

       if(ok(id,mid,val))
        l=mid+1,ans1=mid;
        else
         h=mid-1;
   }

    l=0;  h=id; int ans2;

   while(l<=h)
   {
       int mid=(l+h)>>1;

       if(ok(mid,id,val))
        h=mid-1,ans2=mid;
        else
         l=mid+1;
   }

  return ans1-ans2+1;
}

void ST()
{
    for(int i=0;i<n;i++)
        a[i][0]=i;

    for(int j=1;(1<<j)<=n;j++)
    {
        for(int i=0;(i+(1<<j)-1)<n;i++)
        {
            if(arr[a[i][j-1]]<arr[a[i+(1<<(j-1))][j-1]])
            a[i][j]=a[i][j-1];
            else
               a[i][j]= a[i+(1<<(j-1))][j-1];

        }

    }

}




















int main()
{
    M();


    scanf("%d",&n);

   for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);

   ST();

   int val,siz;
   for(int i=0;i<n;i++)
   {

       val=arr[i];

       siz= BS(val,i);

       ans[siz]=max(ans[siz],val);
   }


   for(int i=n;i>=1;i--)
    ans[i-1]=max(ans[i],ans[i-1]);

   for(int i=1;i<=n;i++)
    printf("%d ",ans[i]);

}









