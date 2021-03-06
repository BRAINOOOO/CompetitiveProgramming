// ICPC champion is here
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
double arr[29][29][29];
int pre[29][29][20];
double no;
int n;
vector<int> ans;

void floyed()
{

   for(int l=2;l<=n;l++)
   {

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {

                if(arr[i][k][l-1]*arr[k][j][1]>arr[i][j][l])
                {
                   arr[i][j][l]=arr[i][k][l-1]*arr[k][j][1];
                   pre[i][j][l]=k;
                }

            }
        }
    }
   }
}

void path(int i,int j,int s)
{
    int I=i;
    int J=j;
    int S=s;
    ans.pb(J);
    while(1)
    {
        if(pre[I][J][S]==-1)
            break;
        ans.pb(pre[I][J][S]);

        J=pre[I][J][S];
        S-=1;
    }
    ans.pb(i);


}






int main()
{
    while(cin>>n)
    {

   clr(pre,-1);
   clr(arr,0);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)
            {
                arr[i][j][1]=1.0;
            }
            else
            {
                cin>>no;
                arr[i][j][1]=no;
            }
        }
    }

    floyed();
    bool ok=1;
    int I,S;
    for(int s=2;s<=n&&ok;s++)
    {

      for(int i=1;i<=n&&ok;i++)
      {
          if(arr[i][i][s]>1.01)
          {
              I=i;
              S=s;
              ok=0;
          }
      }
    }


   if(ok)
   {
       cout<<"no arbitrage sequence exists\n";
   }
   else
   {
          ans.clear();
          path(I,I,S);
          reverse(all(ans));

       for(int i=0;i<sz(ans);i++)
        if(i)
        cout<<" "<<ans[i];
       else
        cout<<ans[i];

        cout<<endl;
   }
    }
}

