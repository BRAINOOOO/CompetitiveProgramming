/*
explanation : here by simulation you will find that exactly half of the space n place allowed
and the other half not allowed and every length will take from the pervious one.

First of all, write n = 2,3,4 cases and found that the probability is 1/2:

Possible situps with n = 2: (1,2) (2,1);

Possible sit-ups with n = 3: (1,2,3) (2,1,3) (2,3,1) (3,2,1)

Possible sitings with n = 4: (1,2,3,4) (2,1,3,4) (2,3,1,4) (3,2,1,4) 

(2,3,4,1) (2,4,3,1) (3,2,4,1) (4,2,3,1)

Then, the observation found that the data per hour can be divided into two parts: replacement + unchanged, rewrite the above state:

n = 2: () + (1,2), (2,1) + ();

(2) + (3), (2, 3, 1) + (), (3, 1) + (2)

When n = 4: () + (1,2,3,4), (2,1) + (3,4), (2,3,1) + (4), (3,1) + , 4) 

(2,3,4,1) + (), (2,4,1) + (3), (3,4,1) + (2), (4,1) + (2,3)

Finally, we conclude that n = k + 1 can be constructed by n = k, half remains unchanged, and half is added to the map so the probability is known as 0.5.

complexity : O(1)
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
   while( cin>>n)
   {
    if(n==0)
        break;
   cout<<  "1/2" <<endl;
   }
}
