/*
explanation : the idea of the pronlem is that if the max in a in greater than min in b so through the coming ends there is 
no hope for finding max a= min b .
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
ll getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
ll setBit1(ll num, int idx) {return num | (1ll<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(ll mask) {int ret=0; while (mask) 	{mask &= (mask-1ll);++ret;	}return ret;}
const int MAX= (1<<19);
int tree1[MAX],tree2[MAX];
int inf=INT_MAX;
int n,a[200009],b[200009];
void build1(int s,int e,int root)
{

    if(s==e)
    {
        tree1[root]=a[s];
        return;
    }
    int mid= (s+e)>>1;

    build1(s,mid,root*2);
    build1(mid+1,e,root*2+1);

    tree1[root]=max(tree1[root*2],tree1[root*2+1]);
}
void build2(int s,int e,int root)
{

    if(s==e)
    {
        tree2[root]=b[s];
        return;
    }
    int mid= (s+e)>>1;

    build2(s,mid,root*2);
    build2(mid+1,e,root*2+1);

    tree2[root]=min(tree2[root*2],tree2[root*2+1]);
}
int query1(int a,int b,int s=1,int e=n,int root=1)
{

    if(a<=s&&e<=b)
    {
        return tree1[root];
    }
    int mid=(s+e)>>1;
    if(b<=mid)
      return query1(a,b,s,mid,root*2);
   else if(a>mid)
      return  query1(a,b,mid+1,e,root*2+1);


   return max(query1(a,b,s,mid,root*2),query1(a,b,mid+1,e,root*2+1));
}

int query2(int a,int b,int s=1,int e=n,int root=1)
{

    if(a<=s&&e<=b)
        return tree2[root];

    int mid=(s+e)>>1;


    if(b<=mid)
      return  query2(a,b,s,mid,root*2);
    else if(a>mid)
      return  query2(a,b,mid+1,e,root*2+1);


   return min(query2(a,b,s,mid,root*2),query2(a,b,mid+1,e,root*2+1));
}
bool check1(int l,int r)
{
    int v1= query1(l,r);
    int v2= query2(l,r);

    if(v1>v2)
        return 1;
    return 0;

}
bool check2(int l,int r)
{

    int v1=query1(l,r);
    int v2=query2(l,r);

    if(v1==v2)
        return 1;
    return 0;


}
int BS1(int l)
{


    int h=n,lw=l;
    int ans=n+1;
    while(lw<=h)
    {

        int mid=(lw+h)/2;

        if(check1(l,mid))
        {
            ans=mid;
            h=mid-1;
        }
        else
            lw=mid+1;
    }

    return ans;


}

int BS2(int l,int r)
{


    int h=r;
    int lw=l;
    int ans=-1;
    while(lw<=h)
    {
        int mid=(lw+h)/2;

        if(check2(l,mid)==1)
        {
            ans=mid;
            h=mid-1;
        }
        else
            lw=mid+1;

    }
    return ans;
}








int main()
{

    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }

    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);

    build1(1,n,1);
    build2(1,n,1);

  ll cnt=0,w;
  for(int l=1;l<=n;l++)
  {

      int q= BS1(l)-1;
      int r= BS2(l,q);
       if(r==-1)
       w=0;
      else
      w=q-r+1;
      cnt+= w;

  }

   printf("%I64d",cnt);
}
