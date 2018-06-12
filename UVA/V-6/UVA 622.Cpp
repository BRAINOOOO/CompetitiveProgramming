/*
it is obvious that it can be solved recursively 
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
int id,fl,n;
int comp();
int fact();
string st;
int expression()
{
    if(fl)
        return 0;

    int ret= comp();

    if(id<n&&st[id]=='+')
    {
        id++;
        return ret+expression();
    }

    return ret;
}

int comp()
{
    if(fl)
        return 0;

    int ret=fact();


    if(id<n&&st[id]=='*')
    {
        id++;
        return ret*comp();
    }
   return ret;
}


int fact()
{
    if(fl)
        return 0;
    int num=0;

  if(id<n&&isdigit(st[id]))
  {

    while(id<n&&isdigit(st[id]))
    {
        num= num*10+(st[id]-'0');
        id++;
    }
  // if(num==0)
      // return fl=1;

    return num;

  }
  else
  {
      if(id<n&&st[id]=='(')
      {
          id++;
          int ret=expression();

          if(id<n&&st[id]==')')
          {
              id++;
             return ret;
          }

          return fl=1;
      }
  }

  return fl=1;

}



int main()
{
    int T;
    cin>>T;
   while(T--)
   {

       cin>>st;
       n=sz(st);
       id=0;
       fl=0;
       int val=expression();
       if(id!=n)
        fl=1;

       if(fl)
        cout<<"ERROR\n";
       else
        cout<<val<<endl;
   }
}







