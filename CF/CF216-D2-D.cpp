/*
explaination : here is the problem is strightforward we will iterate on the sectors 
and we only care about the left and the right sectors and their affect on the current
one so i will sort all the attachment points and get the number of points in range with
every range of the current sector and put them at 2 vectors one for left and one for right
and compare if the number of points not equal so count, the 2 pointers working the first 
pointer(p1) is at the current sector and the other pointer(p2) is at the second sector
beginning and p2 will move on till it will be greater than the end of range but i only count
iff it is greater than the beginning of the range then when i end i will put what i count 
at the vector and continue to the next range.

*/
#include <bits/stdc++.h>
#define sz(v)   ((int)(v).size())
#define  all(v)    ((v).begin()),((v).end())
#define  allr(v)    ((v).rbegin()),((v).rend())
#define   pb         push_back
#define   mp         make_pair
#define   mt         make_tuple
#define    clr(v,d)      memset( v, d ,sizeof(v))
#define    vi       vector<int>
#define    vd       vector<double>
#define    vvi      vector< vector<int> >
#define    vvll      vector< vector<long long> >
#define    vvpi     vector< vector< pair<int,int> > >
#define    vvpll     vector< vector< pair<long long,long long> > >
#define    vvd      vector< vector<double> >
#define    vs       vector<string>
#define    vvs      vector< vector<string> >
#define     vpi        vector< pair<int ,int> >
#define      pi        pair<int ,int>
#define      pll       pair<long long ,long long>
#define     vpd        vector< pair<double ,double> >
#define     vpll        vector< pair<long long ,long long> >
#define    vll       vector<long long>
#define    dqi        deque< int >
#define     si         set<int>
#define     spi        set< pair<int ,int > >
#define     row          vector< ll >
#define     matrix            vector< row >
#define     si         set<int>
#define    oo         900000000000000000
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
vvi lst;
vi fun1(vi v1,vi v2)
{
    vi v3;
   int l=1, r=0;
    while(l<sz(v1))
    {
        int cnt=0;
        while(r<sz(v2)&&v2[r]<v1[l])
        {
            if(v2[r]>v1[l-1])
            cnt++;
             r++;
        }
        v3.pb(cnt);
        l++;
    }
  return v3;
}
int comp(vi v1, vi v2)
{
    int cnt=0;
    for(int i=0;i<sz(v1);i++)
    {    
        if(v1[i]!=v2[i])
            cnt++;
    }
    return cnt;
}
int main()
{
  int n;
    cin>>n;
   int k;
    for(int i=0;i<n;i++)
    {
        cin>>k;
        vi v;
        int no;
        for(int j=0;j<k;j++)
        {
            cin>>no;
            v.pb(no);
        }
        sort(all(v));
        lst.pb(v);
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
      if(sz(lst[i])==1)
        continue;
      vi v1=  fun1(lst[i],lst[(i==n-1? 0 : i+1)]);
      vi v2=  fun1(lst[i],lst[(i==0? n-1 : i-1)]);
    int cnt=  comp(v1,v2);
      ans+=cnt;

    }
       cout<<ans<<endl;
}
