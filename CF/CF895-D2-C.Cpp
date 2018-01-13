/*
explanation :

first lets divide the problem to subproblems 
1- you have to observe that i need to make the product of some numbers in the array a perfect square okay
so there must be an even prime factor in this product.
2- the prime factors in the range of 70 is only 19 prime the greatest of it is 67 but its only 19 so i can represent for each
number a mask represnt its prime factors but here is a problem there is repetitions in the prime factors how could i express it
in the mask off course you can't but i don't care about the real number of each prime factor i only care about whether its even 
or odd and odd+odd=even
           even+even=even
           odd+even=odd
           even+odd=odd
 so i can express even by zero odd by 1 and Xor okay here i can dp but it is N*(2^19) which is TLE so i am xoring right so if i xor num
 with one another number let it be x so the result will be the same if i num^x^x^x i mean xoring odd numbers with a number will be the same 
 and the same for even numbers so i will try to take even numbers of x and odd and see this will be the recurrence here it is 70*(2^19)
 which is okay :)
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
const ll M=1000000007;
int primid[79],cnt[79];
int mem[79][(1<<19)],mask[79];
ll powerr[100000+9];
int v[]={ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67 };
ll power(ll b,ll p)
{
    if(p==0)
        return 1ll;
    if(p&1ll)
        return ((b%M)*(power((b*b)%M,p/2)%M))%M;
    else
        return (power((b*b)%M,p/2)%M)%M ;
}
ll solve(int i,ll msk)
{
    if(i==71)
        return msk==0 ;
      int &ret=mem[i][msk];
    if(ret!=-1)
        return ret;
    int ans=0;
    if(cnt[i]!=0)
        ans+= (powerr[cnt[i]]*solve(i+1,msk^mask[i]))%M;
        ans%=M;
    ans+= (powerr[cnt[i]]*solve(i+1,msk))%M;
    ans%=M;
    ret=ans;
    return ret;
}
int main()
{
    int n;
    scanf("%d",&n);
    int no;
    for(int i=0;i<n;i++)
        scanf("%d",&no),cnt[no]++;
   for(int i=0;i<=18;i++)
   {
        primid[v[i]]=i;
   }
   for(int i=2;i<=70;i++)
   {
       int t=i;
       for(int j=2;j<=70;j++)
       {
           while(t%j==0)
           {

               mask[i]^=(1<<primid[j]);
               t/=j;
           }
       }
   }
   powerr[0]=1;
   powerr[1]=1;
   for(int i=2;i<=100000;i++)
    powerr[i]=power(2,i-1);
   clr(mem,-1);
   printf("%d\n", solve(1,0)-1) ;
}
