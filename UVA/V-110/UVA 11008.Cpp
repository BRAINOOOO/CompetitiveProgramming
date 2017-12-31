/*
explanation : here there is 2 tricks first the preprocessing second one is instead of looping n^2 inside 
the dp we will reduce it by looping on the trees that we dont cut only but what if the amount of trees remaining
are only one tree so we will add to the answer 1 only.
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
int m,n,arr[18+9][18+9],mem[(1<<18)+10];
int fun(int ms)
{
    if((n-countNumBit1(ms))>=m)
        return 0;
    if(mem[ms]!=-1)
        return mem[ms];
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        if(getBit(ms,i))
            v.pb(i);
    }
    int ret=INT_MAX;
    for(int i=0;i<sz(v);i++)
    {
        for(int j=0;j<sz(v);j++)
        {
               if(i==j)
                continue;
            ret=min(ret,1+fun(ms & arr[v[i]][v[j]] ));
        }
    }
    if(ret==INT_MAX)
        ret=1;
    return mem[ms]=ret;
}
int main()
{
    int cases;

   scanf("%d",&cases);

  for(int cs=1;cs<=cases;cs++)
  {
     if(cs>1)
        printf("\n");

     clr(arr,0);

      scanf("%d %d",&n,&m);
       vector<pair<int,int> > v;
       int x,y;
      for(int i=0;i<n;i++)
      {

          scanf("%d %d",&x,&y);
          v.pb(mp(x,y));
      }

      for(int i=0;i<n;i++)
      {

          for(int j=0;j<n;j++)
          {

             if(j==i)
                continue;

              int mask=(1<<n)-1;
             mask= setBit0(mask,i);
             mask= setBit0(mask,j);
              for(int k=0;k<n;k++)
              {

                 if(k==i||k==j)
                    continue;
               int x1= v[i].first;
               int y1= v[i].second;
               int x2= v[j].first;
               int y2= v[j].second;
               int x22=v[k].first;
               int y22=v[k].second;
                if( (x2-x1)*(y22-y1) == (x22-x1)*(y2-y1) )
                {
                  mask=  setBit0(mask,k);
                }
              }
              arr[i][j]=mask;
          }
      }
       clr(mem,-1);
     printf("Case #%d:\n%d\n",cs,fun((1<<n)-1));
  }
}
