/*
explanation : its a direct dp bec the graph is DAG  there is no cycles the logic of the dp [first player node postion]
[second player node position][last char taken in the prev turn] i will reverse the nodes to keep the first one is the one that
the current turn belongs to it and if the next turn returns 0 to the current turn then the current turn wins which is the target 
of the current player so its directly returns one which indicates that he wins but if the next turn returns one so the current turn
lose which is not the target of the curret player so he will loop untill he win if possible.

complexity : O( 26*n*n )
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
vector< vector< pair<int ,int > > > v(105);
int mem[105][105][28];
int solve(int mxn,int ln,int c)
{
     int &ret=mem[mxn][ln][c];
     if(ret!=-1)
        return ret;
         int ans;
         for(int i=0;i<sz(v[mxn]);i++)
         {
             int ch=v[mxn][i].second;
             int no=v[mxn][i].first;
             if(ch>=c||c==27)
               if(! solve(ln,no,ch))
                  return ret=1;
         }
     return ret=0;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int f,t;
    string ch;
    for(int i=0;i<m;i++)
    {
        cin>>f>>t>>ch;
        v[f].pb(mp(t,ch[0]-'a'));
    }
    clr(mem,-1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
           int y= solve(i,j,27);
            if(!y)
             cout<<'B';
            else
                cout<<'A';
        }
        cout<<endl;
    }
}
