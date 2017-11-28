/*
explanation : we can easily observe that it is a binary tree and we want to work on it 
as ranges so we build the tree and dp on it the state will be the node i am in it and the
country the recurence will be the probability to reach this node is the probability to reach 
one before and the opponebt to reach one before and the cost to beat the opponent.
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
double dp[31+9][31+9], arr[16+9][16+9];
void build(int p,int l,int r)
{
    if(l==r)
    {
        dp[p][l]=1;
        return;
    }
    int m=(l+r)/2;
    build(p*2,l,m);
    build(p*2+1,m+1,r);
    for(int i=l;i<=m;i++)
    {
        for(int j=m+1;j<=r;j++)
        {
            dp[p][i]+= dp[p*2][i]*dp[p*2+1][j]*arr[i][j];
            dp[p][j]+= dp[p*2][i]*dp[p*2+1][j]*arr[j][i];
        }
    }
}
int main()
{
    char v[20][20];
    string st;
    for(int i=0;i<16;i++)
    {
        scanf("%s",&v[i]);
    }
    for(int i=0;i<16;i++)
    {
        for(int j=0;j<16;j++)
        {
            cin>>arr[i][j];
            arr[i][j]/=100;
        }
    }
     build(1,0,15);
    for(int i=0;i<16;i++)
    {
      printf("%-10s p=%.2f%\n",v[i],dp[1][i]*100);
    }
}
