/*
explanation : it isnot a shortest path problem because it is the same cost to reach any cell
according to the allowed motions so i can do dfs, know how i could know whether it is allowed 
to move to a certain cell or not so i will count the moves the trains do and check by using a 
preproceeded array in it the start and end of each train in a specific row , i will make 2 checks
first if i can go to a cell and if the train moves i can be at this cell.

complexity : O( (n*3)log(n*3) )
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
 vector< vpi > arr(4);
 int vis[3+9][100+9],n,flag;
 vs v;
bool check(int r,int c,int m)
{
    for(int i=0;i<sz(arr[r]);i++)
    {
       int a=arr[r][i].first-m;
       int b=arr[r][i].second-m;
        if(c>=a&&c<=b)
            return 0;
    }
    return 1;
}
void dfs(int r,int c,int m)
{
    if(c>=n-1)
    {
        flag=1;
        return ;
    }
    if(r+1<3&&c+1<n&&check(r+1,c+1,m)&&check(r,c+1,m)&&!vis[r+1][c+1]&&check(r+1,c+1,m+2))
    dfs(r+1,c+1,m+2),vis[r+1][c+1]=1;
    if(c+1<n&&check(r,c+1,m)&&!vis[r][c+1]&&check(r,c+1,m+2))
    dfs(r,c+1,m+2),vis[r][c+1]=1;
    if(r-1>=0&&c+1<n&&check(r-1,c+1,m)&&check(r,c+1,m)&&!vis[r-1][c+1]&&check(r-1,c+1,m+2))
    dfs(r-1,c+1,m+2),vis[r-1][c+1]=1;



}
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
     int k;
    cin>>n>>k;
    string st;
    v.clear();
    arr.clear();
    arr.resize(4);

    int sr;
    for(int i=0;i<3;i++)
    {
        cin>>st;
        st+='.';
        v.pb(st);
        if(st[0]=='s')
         sr=i,st[0]='.';
    }
  int start,en;
    for(int i=0;i<3;i++)
    {
        start=-1;
        for(int j=0;j<n;j++)
        {
            if(v[i][j]==v[i][j+1]&&v[i][j]!='.')
            {
                if(start==-1)
                start=j;
                en=j+1;
            }
            else
            {
                if(start!=-1)
                {
                  arr[i].pb(mp(start,en));
                  start=-1;
                }

            }


        }
    }
    flag=0;
    clr(vis,0);
    dfs(sr,0,0);

    if(flag)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    }
}
