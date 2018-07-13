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
int n,m,par[20],rnk[20],arr[20],A[20][20];
vector< pair< int,pair<int,int> > > ed;
void I()
{
    for(int i=0;i<n;i++)
        par[i]=i,rnk[i]=1;
}

int getpar(int n)
{
    if(par[n]==n)
        return n;
    return par[n]=getpar(par[n]);
}

void lnk(int a ,int b)
{
    a=getpar(a);
    b=getpar(b);
    if(a==b)
        return;

    if(rnk[a]>=rnk[b])
    {
        par[b]=a;
        rnk[a]+=rnk[b];
        rnk[b]=0;
    }
    else
    {
        par[a]=b;
        rnk[b]+=rnk[a];
        rnk[a]=0;
    }
}

pair<int,int> check(int msk)
{
    I();
    int ans=0,a=0;
    for(int i=0;i<sz(ed);i++)
    {
        int w=ed[i].first;
        int fr=ed[i].second.first;
        int to=ed[i].second.second;
        int frp=getpar(fr);
        int top=getpar(to);

        if((getBit(msk,fr)&&getBit(msk,to))&&((frp!=top)))
        {
            lnk(frp,top);
            ans+=w;
        }

    }
    for(int i=0;i<n;i++)
        if(getBit(msk,i))
         a+=arr[i];
  return mp(ans,a);
}


















int main()
{

   while(cin>>n>>m)
   {
       if(!n&&!m)
        break;
       ed.clear();
       for(int i=0;i<n;i++)
        cin>>arr[i];
       int c;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<n;j++)
           {
               cin>>A[i][j];

           }
       }
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<n;j++)
           {

               ed.pb(mp(A[i][j],mp(i,j)));
           }
       }

       sort(all(ed));
       int up=1000000,down=1;
       int msk=0;
       for(int i=0;i<(1<<n);i++)
       {

           if(countNumBit1(i)!=m)
            continue;

           pair<int,int> val=check(i);
          // cout<<i<<" "<<val.first<<" "<<val.second<<endl;
           if((1ll*val.first*down)<(1ll*up*val.second))
           {
              // cout<<val.first<<" "<<val.second<<endl;
               up=val.first;
               down=val.second;
               msk=i;
           }


       }
       int f=0;
       for(int i=0;i<n;i++)
       {
           if(getBit(msk,i))
           {
               if(f)
            cout<<" "<<i+1;
             else
              cout<<i+1,f=1;
           }
       }
       cout<<endl;
   }
}



