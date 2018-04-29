/*
the idea is that you will end up having 2 senarios the first is that you will need only one rotation which can be done if the positions
of zero and one are ordered in the right order but you may ask zero and one only no not only but if they are ordered angd the 
rest are not ordered so there will be no solution so it is enough to check them only else you will need to flip.

please simulate alot of cases by your hand :)
*/
// ICPC Champion is here

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
int dcmp(long double a,long double b){   return fabsl(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
ll getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
ll setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
int T[2000009],K[2000009],pos[2000009];
int main()
{
    int n,m;
    cin>>n>>m;
    int pos=0,posz=0,poso=1;
    int N=n*2;
    int ty,k;
    while(m--)
    {

        cin>>ty>>k;
        if(ty==1)
        {
            poso+= k*2;
            poso%=N;
            posz+=k*2;
            posz%=N;
        }
        else
        {
            posz=posz-N;

            posz= k+((k-posz)%N);
            posz%=N;

            poso=poso-N;

            poso= k+((k-poso)%N);
            poso%=N;


        }
    }
    if(posz<poso)
    {
       cout<<"1 "<< (N-posz)/2 <<endl;
    }
    else
    {
        int d= N-posz;
        d/=2;

        int p= posz+d;

        p= (p>n? p-n:p);

        cout<<"2 "<<p<<endl;
    }
}



