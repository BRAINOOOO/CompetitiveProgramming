/*
explanation : first of all if i could get the number of strings permutation of a certain string that 
>= other string so we can solve the problem since no of srings >=a - no of strings >=b -1 is the answer
(-1) because we wont count the string a it self we can easily check wether we can form a string from
the string a or not in many ways so lets focus on how we can count the strings > certain string okay
so we can iterate over all the idexes and consider the ith idex is the letter that make the string greater
if so then we can consider all the permutations of the letters after it as it doesnt matter their arrangement
but we can do this only if there is a letter in a equal to i-1, take care there nultiplecative inverse mod 
so deal with it.

complexity : O( n*26 )
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
const int M=1000000007;
int n;
string s1,s2;
ll fact[1000000+9],vis[26+9];
ll power(ll b,ll p)
{
    if(p==0)
        return 1;
    if(p&1)
        return  ((b%M)*(power((b*b)%M,p/2)%M))%M;
    else
        return  (power((b*b)%M,p/2)%M);
}
ll  fun(string s)
{
   ll temp= fact[n-1];
    for(int i=0;i<26;i++)
    {
        if(!vis[i])
            continue;
        temp= (temp * power(fact[vis[i]],M-2))%M;
    }
    ll ans=0;
    int i;
    for(i=0;i<n;i++)
    {
        for(int j= s[i]-'a' +1;j<26;j++)
        {
                ans= (ans + (temp * (vis[j]))%M)%M;
        }
       if(!vis[s[i]-'a'])
        break;
        temp= (temp * vis[s[i]-'a'])%M;
        temp= (temp * power(n-i-1,M-2))%M;
         vis[s[i]-'a']--;
    }
    if(i==n)
        ans= (ans+1)%M;
    if(i==n)
    {
        for(int i=0;i<n;i++)
            vis[s[i]-'a']++;
    }
    else
    {
        for(int j=0;j<i;j++)
            vis[s[j]-'a']++;
    }
    return ans;
}
int main()
{
    cin>>s1>>s2;
     n=sz(s1);
    fact[0]=1;
    for(int i=1;i<=1000000;i++)
        fact[i]=((fact[i-1]%M)*(i%M))%M;
    for(int i=0;i<n;i++)
    {

       int num = s1[i]-'a';

        vis[num]++;
    }

    cout<< (fun(s1)-fun(s2)-1+M)%M <<endl;
    return 0;
}
