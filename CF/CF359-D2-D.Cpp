#include <bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<cstring>
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
#define     point                    complex<double>
typedef  long long     ll ;
typedef  unsigned long long ull;
const double eps= (1e-5);
using namespace std;
int dcmp(double a,double b){   return fabs(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
ll getBit(ll num, int idx) {return ((num >> idx) & 1ll) == 1;}
ll setBit1(ll num, int idx) {return num | (1ll<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
int n,arr[300009],v[300009],lookup[300009][21],vis[300009];

void Sparsetable()
{

    for(int i=0;i<n;i++)
        lookup[i][0]=arr[i];

    for(int j=1;(1<<j)<=n;j++)
    {
        for(int i=0;(i+(1<<j)-1)<n;i++)
        {
            int x= lookup[i][j-1];
            int y= lookup[i+(1<<(j-1))][j-1];
            lookup[i][j]= __gcd(x,y);

        }

    }
}

int query(int l,int r)
{
    int mx=(int)log2(r-l+1);

    int x= lookup[l][mx];
    int y= lookup[r-(1<<mx)+1][mx];


    return __gcd(x,y);





}
bool check(int l,int r,int val)
{
    int res =query(l,r);

    if(res%val==0)
        return 1;
    return 0;


}







int BSL(int l,int r,int val)
{

    int L=l,ans=l;

    while(l<=r)
    {

       int mid=(l+r)/2;

       if(check(L,mid,val))
        l=mid+1,ans=mid;
       else
       {
           r=mid-1;
       }
    }

    return ans;
}
int BSR(int l,int r,int val)
{

    int R=r,ans=r;

    while(l<=r)
    {
        int mid=(l+r)/2;

        if(check(mid,R,val))
            r=mid-1,ans=mid;
        else
            l=mid+1;

    }

    return ans;
}














int main()
{

    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];

    Sparsetable();

   int mx=0,cnt=0;
   for(int i=0;i<n;i++)
   {
      int r= BSL(i,n-1,arr[i]);
      int l= BSR(0,i,arr[i]);

      if(r-l>mx)
      {
          //cout<<l<<" "<<r<<endl;
          mx=r-l;
          cnt=0;
          v[cnt++]=l;
      }
      else if(r-l==mx)
      {
          v[cnt++]=l;
      }
   }
   sort(v,v+cnt);
    int c=0;
    stringstream ss;
   for(int i=0;i<cnt;i++)
   {
       if(vis[v[i]+1])
        continue;
     ss<<v[i]+1<<" ";
     c++;
   }
   cout<<c<<" "<<mx<<endl;
   cout<<ss.str()<<endl;
}





