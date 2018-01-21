/*
explanation :  first of all you have to observe that all the numbers of the same number of 1s bits will reach 1 in the same steps
we know that 2^1000 is very large that we can't iterate on it but with the pervious observation we are intersted in acertain amount of
numbers that their number of bits can reach 1 in k operations but what we need to know now is the count of those numbers so we will use
dp the recurrance depends on to keep the number always smaller than n so for each bit i can always set it to 0 but i can't set it to 1 
unless there is a pervious 1 i set it to zero thats it.
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
string n;
int k,N;
ll mem[1000+9][1000+9][2];
const ll M=1000000007;
int cnt[1000+9];
ll solve(int id,int c,int f)
{
    if(id==N)
    {
        if(c==0)
        return 1;
        else
            return 0;
    }
    ll &ret=mem[id][c][f];
    if(ret!=-1)
        return ret;
    ll ans=0;
    if(n[id]=='1')
   ans= (ans + solve(id+1,c,1))%M;
   else
    ans= (ans + solve(id+1,c,f))%M;

    if(n[id]=='1'&&c)
   ans= (ans + solve(id+1,c-1,f))%M;
    if(n[id]=='0'&&f&&c)
    ans= (ans + solve(id+1,c-1,f))%M;
    ret=ans;
    return ret;
}
int main()
{
       cin>>n>>k;
       N=sz(n);
    cnt[1]=1;
    for(int i=2;i<=1000;i++)
        cnt[i]= cnt[__builtin_popcount(i)]+1;
  ll ans=0;
  clr(mem,-1);
   for(int i=1;i<=N;i++)
   {
       if(cnt[i]==k)
        ans=(ans+solve(0,i,0))%M;

   }
   if(k==0)
    ans=1;
    else if(k==1)
        ans-=1;
   cout<<ans<<endl;
}
