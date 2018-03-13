/*
explanation : first note that if in the range i have element 2^x and 2^x-1 is will result in the max xor but what if i haven't
so this means the most significant bit is the same for all so the next max is that i get the rest of the bits and its opposite 
which is a sub problem i will search again for 2^x and 2^x-1 but in the new range after removing the most signaficant bit and so on.
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
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(ll mask) {int ret=0; while (mask) 	{mask &= (mask-1ll);++ret;	}return ret;}
int converttobin(ll n)
{
    string s="";

    while(n>0)
    {
        s+= (n%2)+'0';
        n/=2;
    }
    return sz(s);
}
ll power(ll b,ll p)
{
    if(p==0)
        return 1;
    if(p&1)
        return b*power(b*b,p/2);
    else
        return power(b*b,p/2);
}
int main()
{
    M();
    ll l,r;
    cin>>l>>r;
    ll lf,ri;
    lf=l; ri=r;
    int noofbits= converttobin(r);
    while(noofbits)
    {
        for(int i=0;i<noofbits;i++)
        {
            ll p=power(2,i);
           if((lf<=p&&ri>=p)&&(lf<=p-1&&ri>=p-1))
           {
               cout<<power(2,noofbits)-1<<endl;
               return 0;
           }
        }
        ll pp=power(2,noofbits-1);
        lf-=pp;
        ri-=pp;
        noofbits=converttobin(ri);
    }
    cout<<"0";
}
