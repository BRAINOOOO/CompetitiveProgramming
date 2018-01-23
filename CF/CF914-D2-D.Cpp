/*
explanation : here the idea is the gcd of a range can inform me all elements of the range divisable by a certain number let it be x or
not if not so there is at least one number doesn't diviable by it , i can change one number in the range so we can let it be x but i must
have the rest diviable by x so i can query on the number of elements that doesn't diviable by x if < 2 so the ans is yes else ans is no
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
int tree[1048575+9],arr[500000+9];
int build(int s,int e,int p)
{
    if(s==e)
    {
       return tree[p]=arr[s];
    }
   int mid=(s+e)/2;
   return  tree[p]=  __gcd( build(s,mid,p*2),build(mid+1,e,p*2+1));
}
int q(int a,int b,int x,int s,int e,int p)
{
    if(s>b||e<a||tree[p]%x==0)
        return 0;
    if(s==e)
        return tree[p]%x==0 ? 0: 1;
    if(s>=a&&e<=b&&tree[p*2]%x!=0&&tree[p*2+1]%x!=0)
        return 2;
    int mid=(s+e)/2;
    return  q(a,b,x,s,mid,p*2)+q(a,b,x,mid+1,e,p*2+1);
}
int update(int pos,int v,int s,int e,int p)
{
    if(s>pos||e<pos)
     return tree[p];
    if(s==e)
    {
       return tree[p]=v;
    }
   int mid=(s+e)/2;
   return  tree[p]=  __gcd( update(pos,v,s,mid,p*2),update(pos,v,mid+1,e,p*2+1));
}
int main()
{

   int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    build(0,n-1,1);
    int qr;
   scanf("%d",&qr);
  int st,a,b,x;
  while(qr--)
  {
      scanf("%d",&st);
      if(st==1)
      {
          scanf("%d %d %d",&a,&b,&x);
          a--;
          b--;
          ( q(a,b,x,0,n-1,1) < 2 ? printf("YES\n") : printf("NO\n") );
      }
      else
      {
          scanf("%d %d",&a,&b);
          a--;
          update(a,b,0,n-1,1);
      }
  }
}





