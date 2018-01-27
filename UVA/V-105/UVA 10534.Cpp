/*
explanation : here the idea is easier what it sounds to be first i tried to think of the idea which is to iterate on orginal vector 
consider the point at the ith index the top point eg  1 2 (3) 1 0 3 is the top point here and get LIS to that element and LDS from that
element to the end and min between them *2 -1 will be the answer -1 bec here i count the top element twice Now the problem is LIS dp
in n^2 so it is TLE so i need to get LIS in nlogn the complexity will be n*n*log(n) which is TLE too now lets think of preprocessing in
LIS to store the number of elements making LIS ending with ith element and the same LDS till end here the overall complexity will be 
nlogn which is okay :)
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
vector<int> v;
int n;
vector<int> LIS()
{
    vector<int> L,len(n,0);
    for(int i=0;i<n;i++)
    {
      int id= lower_bound(all(L),v[i])-L.begin();
       if(id==sz(L))
       {
           L.pb(v[i]);
       }
       else
       {
           L[id]=v[i];
       }
        len[i]=id+1;
    }
   return len;
}
int main()
{
   while(cin>>n)
  {
    int no;
    v.clear();
    for(int i=0;i<n;i++)
    {
        cin>>no;
        v.pb(no);
    }
    vector<int> lenLIS=LIS();
    reverse(all(v));
    vector<int> lenLDS=LIS();
    int mx=1;
    for(int i=0;i<n;i++)
    {
        mx=max(mx,min(lenLIS[i],lenLDS[n-1-i])*2-1);
    }
    cout<<mx<<endl;
  }
}
