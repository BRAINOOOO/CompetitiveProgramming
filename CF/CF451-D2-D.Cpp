/*
explanation : the idea of the problem based on one observation which is to be good palindrome not necessary being a palindrome and after
merging the string will be alternating between as and bs so every substring ending and begining with the same character will be a palindrome 

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
ll getBit(ll num, int idx) {return ((num >> idx) & 1ll) == 1ll;}
ll setBit1(ll num, int idx) {return num | (1ll<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
int countNumBit1(ll mask) {int ret=0; while (mask) 	{mask &= (mask-1ll);++ret;	}return ret;}
int main()
{
    string st;
    cin>>st;
    ll oddb=0,evenb=0,odda=0,evena=0,even=0,odd=0;
    for(int i=0;i<sz(st);i++)
    {
        if(st[i]=='a')
        {
            if(i%2==0)
             {
                evena++;
                odd+= evena;
                even+= odda;
             }
            else
              {
                   odda++;
                  even+= evena;
                  odd+= odda;
              }
        }
        else
        {
            if(i%2==0)
            {
                evenb++;
                odd+= evenb;
                even+= oddb;
            }
            else
             {
                 oddb++;
                 odd+= oddb;
                 even+= evenb;
             }
        }
    }
 cout<<even<<" "<<odd<<endl;
}
