/*
explanation : here the idea is to play with data structures and preprocessing
so first i need to know all elements that smaller than me and to know the largest
index so first by sorting the array and lower bound i will know the last element smaller
than me so i will reach all the elements that smaller than me but know i want another thing
which is to know the largest idex of those smaller than me if its before me so it will be -1
else i will print the distance between it and me, i will do so by a preprocessing array contain 
the largest index of the range of prefix of the sorted array.

complexity : O( N*log(N) )
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
vpi v1;
vi v3,v,v2;
int arr[100000+9];
int main()
{
    int n;
    cin>>n;
    int no;
    for(int i=0;i<n;i++)
    {
        cin>>no;
        v.pb(no);
        v1.pb(mp(no,i));
        v3.pb(no);
    }
    sort(all(v1));
    sort(all(v3));
     int id;
     for(int i=0;i<n;i++)
     {
         id= v1[i].second;
         v2.pb(id);
     }
     arr[0]=v2[0];
    for(int i=1;i<n;i++)
    {
        arr[i]=max(v2[i],arr[i-1]);
    }
    for(int i=0;i<n;i++)
    {
        if(v3[0]>=v[i])
        {
            cout<<"-1 ";
            continue;
        }
      id=  lower_bound(all(v3),v[i])-v3.begin() ;

      if(v3[id]==v[i])
        id--;

     int idx= arr[id];

      if(idx<i)
        cout<<"-1 ";
      else
        cout<< idx-i-1 <<" ";
    }
}
