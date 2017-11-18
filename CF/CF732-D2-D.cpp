/*
explanation : here it is easy to realize that we could binary search on answer till we reach the min one 
okay and we could see that if we have a fixed end day let it be X so if the end day will be x i will choose
for each subject the farest exam to give more chance for preparing but now the problem is if i make a counter
to count the free days to prepare i cant prepare for a subject after passing its exam so i will subtract from 
the needed days till it becomes -ve if its -ve it means that i am know adding days to a subject's exam dont 
come yet so i will reset it to zero.

complexity : O( n*log(n) )
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
vi day(100000+9),sub(100000+9);
int vis[100000+9],n,m;
bool check(int d)
{
    int cnt=0,fr=0;
    clr(vis,0);
    for(int i=d;i>=1;i--)
    {
        if(!day[i])
            fr--;
        else
        {
            int subj=day[i];
            if(vis[subj])
                fr--;
            else
            {
                fr+=sub[subj];
                vis[subj]=1;
                cnt++;
            }
        }
        fr=max(0,fr);
        if(cnt==m&&fr==0)
            return 1;
    }
    return 0;
}
int main()
{
    cin>>n>>m;
    int no;
    for(int i=1;i<=n;i++)
    {
        cin>>day[i];
    }
    for(int i=1;i<=m;i++)
    {
       cin>> sub[i];
    }
    int l,h;
    l=1; h=n;
   int ans=-1;
    while(l<=h)
    {
        int mid=(l+h)/2;
        if(check(mid))
            h=mid-1,ans=mid;
        else
            l=mid+1;
    }
    cout<<ans<<endl;
   return 0;
}
