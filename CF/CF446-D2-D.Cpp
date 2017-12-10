/*
explanation : here if we put againest each number in ( a ) number greater than it in ( b ) 
so the sum of any elements in ( a ) cant be equal to the elements in ( b ) so but there is
another subproblem which is the greatest number in ( a ) will be againest the smallest number 
so how it works lets say that it always works if this greatest number is not a part of the sequence 
but if it is a part of the sequence so the reminder after taking the sequence wont equal the other
reminder in b -----> (1)
and the sum of the ( a ) reminder and the sequence =  the sum of the ( b ) reminder and the sequence ----->(2)
from 1 and 2 
we will conclude that even if the sequence contain this number it works.

complexity : O(n)
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
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>>  v;
   int no;
    for(int i=0;i<n;i++)
    {
        cin>>no;
        v.pb(mp(no,i));
    }
   int b[30];
    sort(all(v));
    for(int i=0;i<n;i++)
    {
        b[v[i].second]=v[(i+1)%n].first;
    }
  for(int i=0;i<n;i++)
    cout<<b[i]<<" ";
}
