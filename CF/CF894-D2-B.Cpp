/*
explanation : here In case of k == 1 if we have -1 in some cell in last row, let's say it's cell[n][x], for cells in that column x (cells from [1][x] to [m-1][x]) we we can say that there is odd number of -1, because their product should be -1.
If we have 1 in same cell, we can say that number of -1 is even for that column, because their product should be -1.
If we have -1 in some cell in last column, let's say it's cell [x][m], for cells in that row x (cells from [x][1] to [x][m-1]) we can say that there is odd number of -1, because their product should be -1.
If we have 1 in same cell, we can say that number of -1 is even for that column, because their product should be -1.

Let's say there is P -1 in (n-1)(m-1) filled area

Let's say we have x1 -1 elements in last column (without [n][m] element). Let's calculate parity of number of -1 in (n-1)x(m-1) filled area. Sum of -1 in all rows ending (ending meaning [i][m] element is -1) with 1 will be even (sum of whatever number of even numbers is even). Sum of -1 in all rows ending with -1 will depend on x1. For every such row there is odd number of -1. If a1 is even (sum of even number of odd numbers is even), if a1 is odd, sum is odd (sum of odd number of odd numbers is odd). So, we can say that x1= P (mod 2).
For last row (without [n][m] element), let's say we have x2 -1 elements. Using same logic as above, we'll discover that x2 = P(mod 2), giving us that x1 = x2(mod 2). (parity is same)
Therefore, we won't have any conflicts in [n][m] cell.

We'll apply almost similar logic to k == -1 case.

In case of k == -1, if we have -1 in some cell in last row, let's say it's cell[n][x], for cells in that column x (cells from [1][x] to [m-1][x]) we we can say that there is even number of -1, because their product should be -1.
If we have 1 in same cell, we can say that number of -1 is odd for that column, because their product should be -1.
If we have -1 in some cell in last column, let's say it's cell [x][m], for cells in that row x (cells from [x][1] to [x][m-1]) we can say that there is even number of -1, because their product should be -1.
If we have 1 in same cell, we can say that number of -1 is odd for that column, because their product should be -1.

We can do the same as we did before, but this time we'll prove that y1 = y2(mode 2), where y1 and y2 are number of 1 elements in last row / column (not number of -1 elements, as before).
B we already know that for k == -1 case, n = m (mod 2). Therefore, x1 =x2 (mode2), where x1 and x2 are number of -1 elements in last row/column (parity is same)
Therefore, we won't have any conflicts in [n][m] cell
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
const int M=1000000000+7;
ll power(ll b,ll p)
{
    if(p==0)
        return 1;

    if(p&1)
    return ((b%M)*(power(((b%M)*(b%M))%M,p/2)%M))%M;
    else
        return (power(((b%M)*(b%M))%M,p/2)%M);
}
int main()
{
    ll n,m,k;
    cin>>n>>m>>k;

    if(k==-1&&(n+m)%2!=0)
    {
        cout<<"0\n";
        return 0;
    }

   cout<< power(power(2,n-1),m-1);
}
