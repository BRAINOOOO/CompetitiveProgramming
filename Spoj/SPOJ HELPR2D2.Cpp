/*
explanation : here we need to know the leftmost idex which have >= volume so we
can use segment tree to do that by express the the range by its max first we will
try to move left but if the max of the range you are going isnot less than the 
volume otherwise go right, then i will maxmize on the index of the ship i used 
bec surely if i go to right there wont be a ship on my left not used.

complexity : O( T*N*log(n) )
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
int v,k,sum,cnt;
int  tree[2097151+9] ;
void build(int s,int e,int p)
{
    if(s>e)
        return ;
    if(s==e)
    {
       tree[p]=k;
       return;
    }
    int mid=(s+e)/2;
   build(s,mid,p*2);
   build(mid+1,e,p*2+1);
   tree[p]=max(tree[p*2],tree[2*p+1]);
}
int query(int s,int e,int p)
{
    if(tree[p]<v)
        return -1;
    if(s==e)
    {
        tree[p]-=v;
        return s;
    }
    int mid=(s+e)/2;
   int q1= query(s,mid,p*2);
     if(q1==-1)
      q1=  query(mid+1,e,p*2+1);
     tree[p]=max(tree[2*p],tree[2*p+1]);
     return q1;
}
int main()
{
    int t;
   scanf("%d",&t);
   while(t--)
   {
       clr(tree,0);
       int n;
       scanf("%d %d",&k,&n);
        build(0,n-1,1);
       char stt[100];
       string st;
       int up,nv,mx=0,W=0;
       for(int i=0;i<n;)
       {
          scanf("%s",stt);
          st=stt;
          if(st=="b")
          {
              scanf("%d %d",&up,&v);
              for(int j=0;j<up;j++)
              {
                 int id= query(0,n-1,1);
                   mx=max(mx,id);
                   W+=v;
              }
              i+=up;
          }
          else
          {
              v=atoi(st.c_str());
              int id= query(0,n-1,1);
              W+=v;
               mx=max(mx,id);
                 i++;
          }
       }
       printf("%d %d\n",mx+1,(mx+1)*k-W);
   }
}
