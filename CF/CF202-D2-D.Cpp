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
ll arr[1008][1008],n,m,SX[1009],SY[1009];

int main()
{
     M();
    cin>>n>>m;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
            SX[i]+=arr[i][j];
            SY[j]+=arr[i][j];
        }
    }

    ll partx1=0,partx2=0,partx3=0,party1=0,party2=0,party3=0;

   for(int i=2,ii=0;i<=4*n;i+=4,ii++)
   {
       //cout<<i<<" "<<ii<<endl;

           partx2+=SX[ii]*i;
           partx1+=SX[ii];
           partx3+= SX[ii]*i*i;
   }
   for(int i=2,ii=0;i<=4*m;i+=4,ii++)
   {


           party2+=SY[ii]*i;
           party1+=SY[ii];
           party3+= SY[ii]*i*i;
   }
   ll miresx=-1,miresy=-1,mix,miy;
   for(int i=0;i<=n*4;i+=4)
   {
          ll res= i*i*partx1-2*i*partx2+partx3;
          if(miresx==-1||res<miresx)
          {
              mix=i/4;
              miresx=res;
          }

   }

   for(int i=0;i<=4*m;i+=4)
   {
          ll res= i*i*party1-2*i*party2+party3;
          if(miresy==-1||res<miresy)
          {
              miy=i/4;
              miresy=res;
          }

   }
 cout<<miresx+miresy<<endl<<mix<<" "<<miy<<endl;

}




