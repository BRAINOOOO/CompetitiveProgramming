/*
explanation :  the idea is if i tried to get the longest matching subsequence from left of each postion in string S and the reverse 
from right if l[i]>=r[i] so ican grantee that the rest of left can be obtained .
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
int l[200009],r[200009],arr[29];
int inf=10000000;
int main()
{
    string s,t;
   cin>>s>>t;
     clr(arr,-1);

   for(int i=0,j=0;i<sz(s);i++)
   {
       if(j<sz(t)&&s[i]==t[j])
       {
           l[i]=j;
           arr[t[j]-'a']=j;
           j++;
       }
       else
        l[i]=arr[s[i]-'a'];
   }
   for(int i=0;i<200009;i++)
    arr[i]=inf;
   for(int i=sz(s)-1,j=sz(t)-1;i>=0;i--)
   {
       if(j>=0&&s[i]==t[j])
       {
           r[i]=j;
           arr[t[j]-'a']=j;
           j--;
       }
       else
        r[i]=arr[s[i]-'a'];
   }
   int cnt=0;
   for(int i=0;i<sz(s);i++)
   {

       cnt+= (l[i]>=r[i]);
   }
  cout<<(cnt==sz(s) ? "Yes\n" : "No\n");
}
