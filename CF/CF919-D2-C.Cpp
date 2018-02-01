/*
explanation : here i will count the number of the conscutive empty cells along each row and each column and calculate what i can
take from it but if K equals to 1 you will dublicate so i consider it as a seprate case

complexity : O( n*m )
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
vector<string> v;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    string s;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        v.pb(s);
    }
     int ans=0,cnt=0;
     for(int i=0;i<n;i++)
     {
         int em=0;
         for(int j=0;j<m;j++)
         {
             if(v[i][j]=='.')
             {
                 em++;
                 cnt++;
             }
             else
             {
                 if(em-k+1>0)
                 ans+=em-k+1;
                 em=0;
             }
         }
         if(em-k+1>0)
         ans+= em-k+1;
     }
      for(int i=0;i<m;i++)
     {
        int  em=0;
         for(int j=0;j<n;j++)
         {
             if(v[j][i]=='.')
             {
                 em++;
             }
             else
             {
                 if(em-k+1>0)
                 ans+=em-k+1;
                 em=0;
             }
         }
         if(em-k+1>0)
         ans+= em-k+1;
     }
      if(k!=1)
     cout<<ans<<endl;
     else
        cout<<cnt<<endl;
}
