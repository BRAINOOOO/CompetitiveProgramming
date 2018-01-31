/*
explanation : the idea is i will define sc1 and sc2 for the total score of brackets ( the balance of the brackets ) sc1 when it is
a '?' i will turn it in to closed bracket and close the opened brackets before it so the balance will be decreased by one the problem
is i may need it to be opened bracket in the future which means when i come to a closed bracket sc1 will be negative so i will increase
it by two considering i don't turn it in to a closed bracket in the past and i will keep sc2 as i will put every '?' to open bracket 
which indicates the non-balanced string as if i will turn all '?' to open brackets and still have extra closed brackets it will be non-
balanced string .

complexity : O(n^2)
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
    int n=sz(st);
    int ans=0,sc1,sc2;
    for(int l=0;l<n;l++)
    {
        sc1=sc2=0;
        for(int r=l;r<n;r++)
        {
            if(st[r]=='(')
            {
                sc1++;
                sc2++;
            }
            else if(st[r]==')')
            {
                sc1--;
                sc2--;
            }
            else
            {
                sc1--;
                sc2++;
            }
            if(sc2<0)
                break;
            if(sc1<0)
                sc1+=2;
            if(sc1==0)
                ans++;
        }
    }
    cout<<ans<<endl;
}
