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
int setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
map< ll, set<ll> > v1,v2,v3,v4;
char ch[500009];
int X[500009],Y[500009];
int main()
{
     M();
    int n,KX,KY;
    cin>>n;
    cin>>KX>>KY;
    v1[KY].insert(KX);
    v2[KX].insert(KY);
    v3[KX-KY].insert(KY);
    v4[KX+KY].insert(KY);
    int x,y;
    char c;
    for(int i=0;i<n;i++)
    {
        cin>>c>>x>>y;
        ch[i]=c;
        X[i]=x;
        Y[i]=y;
    }

    for(int i=0;i<n;i++)
    {
        int x=X[i];
        int y=Y[i];

        v1[y].insert(x);  // row
        v2[x].insert(y);  // clown
        v3[x-y].insert(y); // diag rg
        v4[x+y].insert(y); // dig  lf
    }


   for(int i=0;i<n;i++)
   {
      x=X[i];
      y=Y[i];


      if(ch[i]=='R')
      {

          if(KY==y&&KX>x)
          {
             auto it= v1[y].upper_bound(x);

             if(it!=v1[y].end()&&(*it)==KX)
             {
                 cout<<"YES\n";
                 return 0;
             }
          }
           if(KY==y&&KX<x)
          {
              auto it= v1[y].upper_bound(KX);
              if(it!=v1[y].end()&&(*it)==x)
              {
                  cout<<"YES\n";
                  return 0;
              }

          }
           if(KX==x&&KY>y)
          {
              auto it= v2[x].upper_bound(y);

              if(it!=v2[x].end()&&(*it)==KY)
              {
                  cout<<"YES\n";
                  return 0;
              }
          }
           if(KX==x&&KY<y)
          {
              auto it= v2[x].upper_bound(KY);

              if(it!=v2[x].end()&&(*it)==y)
              {
                  cout<<"YES\n";
                  return 0;
              }

          }
      }

      if(ch[i]=='Q')
      {
          if(KY==y&&KX>x)
          {
             auto it= v1[y].upper_bound(x);


             if(it!=v1[y].end()&&(*it)==KX)
             {
                 cout<<"YES\n";
                 return 0;
             }
          }
           if(KY==y&&KX<x)
          {
              auto it= v1[y].upper_bound(KX);
              if(it!=v1[y].end()&&(*it)==x)
              {
                  cout<<"YES\n";
                  return 0;
              }

          }
           if(KX==x&&KY>y)
          {
              auto it= v2[x].upper_bound(y);

              if(it!=v2[x].end()&&(*it)==KY)
              {
                  cout<<"YES\n";
                  return 0;
              }
          }
           if(KX==x&&KY<y)
          {
              auto it= v2[x].upper_bound(KY);

              if(it!=v2[x].end()&&(*it)==y)
              {
                  cout<<"YES\n";
                  return 0;
              }

          }
           if((x-y==KX-KY)&&KY>y)
          {
              auto it=v3[x-y].upper_bound(y);

              if(it!=v3[x-y].end()&&(*it)==KY)
              {
                  cout<<"YES\n";
                  return 0;
              }
          }
           if((x-y==KX-KY)&&KY<y)
          {
              auto it=v3[x-y].upper_bound(KY);

              if(it!=v3[x-y].end()&&(*it)==y)
              {
                  cout<<"YES\n";
                  return 0;
              }
          }
           if((x+y==KX+KY)&&KY>y)
          {
              auto it=v4[x+y].upper_bound(y);

              if(it!=v4[x+y].end()&&(*it)==KY)
              {
                  cout<<"YES\n";
                  return 0;
              }
          }
           if((x+y==KX+KY)&&KY<y)
          {
              auto it=v4[x+y].upper_bound(KY);

              if(it!=v4[x+y].end()&&(*it)==y)
              {
                  cout<<"YES\n";
                  return 0;
              }
          }
      }

      if(ch[i]=='B')
      {
         if((x-y==KX-KY)&&KY>y)
          {
              auto it=v3[x-y].upper_bound(y);

              if(it!=v3[x-y].end()&&(*it)==KY)
              {
                  cout<<"YES\n";
                  return 0;
              }
          }
           if((x-y==KX-KY)&&KY<y)
          {
              auto it=v3[x-y].upper_bound(KY);

              if(it!=v3[x-y].end()&&(*it)==y)
              {
                  cout<<"YES\n";
                  return 0;
              }
          }
           if((x+y==KX+KY)&&KY>y)
          {
              auto it=v4[x+y].upper_bound(y);

              if(it!=v4[x+y].end()&&(*it)==KY)
              {
                  cout<<"YES\n";
                  return 0;
              }
          }
           if((x+y==KX+KY)&&KY<y)
          {
              auto it=v4[x+y].upper_bound(KY);

              if(it!=v4[x+y].end()&&(*it)==y)
              {
                  cout<<"YES\n";
                  return 0;
              }
          }

      }

   }

   cout<<"NO\n";
}
