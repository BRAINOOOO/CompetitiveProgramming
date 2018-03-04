/*
explanation : here the idea about accumulation if i have acertain subset i know its sum mod M then i can subtract from it another subset
i know its sum mod M then i can get the sum mod M of the remaining subset and i want subsets that divisible by M which means, let the 
subset be X,  (x1+x2+x3)%M==0  and i have the sum mod M accumulated for all the N elements so if i got a value and the same value so
the subset in between its sum mod M ==0 so i count it .
complexity : O(N*T)
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
int arr[10009],v[10009],vis[10009];


int main()
{


    int T;
    cin>>T;
     int cs=1;
    while(T--)
    {
        clr(vis,0);
        int A,B,C,M,N;
        cin>>A>>B>>C>>M>>N;

        v[0]=A;
        arr[0]=A%M;
        for(int i=1;i<N;i++)
        {
            v[i]=(((v[i-1]*B+C)%M)+1);
            arr[i]=v[i]%M;
        }

         for(int i=1;i<N;i++)
         {
             arr[i]=(arr[i]+arr[i-1])%M;
         }
         set<int> s;
         for(int i=0;i<N;i++)
         {
             vis[arr[i]]++;
             s.insert(arr[i]);
         }
         ll ans=0;
         for(auto i=s.begin();i!=s.end();i++)
         {
             int num=vis[(*i)];
              
             ans+= (num*(num-1))/2;
         }
         cout<<"Case "<<cs++<<": "<<ans+vis[0]<<endl;
    }
}
