/*
observe that each time i change only one element in one of the matrixes so i can calculate the product matrix first then just update 
it according to the element the query asks to update.
To know how just trace the product of 2 matrixes :)
*/


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
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
ll A[109][109],B[109][109],P[109][109];
int main()
{
    int n;
    cin>>n;

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
            cin>>B[i][j];
        }
    }
   ll cnt=0;
   for(int i=0;i<n;i++)
   {
     for(int k=0;k<n;k++)
     {

       for(int j=0;j<n;j++)
       {
          P[i][k]+= A[i][j]*B[j][k];
       }
       cnt+=P[i][k];
     }

   }
  int q;
  cin>>q;
  char ch;
  ll r,c,val;
  while(q--)
  {
      ll pre;
      cin>>ch>>r>>c>>val;

      if(ch=='A')
      {



          for(int j=0;j<n;j++)
          {


              pre=B[c][j]*A[r][c];
              P[r][j]-=pre;
              cnt-=pre;
              P[r][j]+=B[c][j]*val;
              cnt+=B[c][j]*val;

          }

          A[r][c]=val;
      }
      else
      {

          for(int j=0;j<n;j++)
          {

              pre=A[j][r]*B[r][c];
              P[j][c]-=pre;
              cnt-=pre;
              P[j][c]+= A[j][r]*val;
              cnt+=A[j][r]*val;

          }

           B[r][c]=val;
      }

      cout<<cnt<<endl;
  }


}




