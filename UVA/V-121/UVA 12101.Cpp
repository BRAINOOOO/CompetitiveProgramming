/*
explantion : the idea is imagine it is a graph and the edge between a node and another node is when the difference between them is one
letter so simply i will go and check and construct the graph then do simple bfs
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
vector<int> p;
int vis[10000],vis2[100000];
vector< vector<int> > v(10000);
void sieve(int n)
{

    for(int i=2;i<=n;i++)
    {

       if(vis[i])
        continue;

       for(int j=i*2;j<=n;j+=i)
        vis[j]=1;
    }
}
bool check(int a,int b)
{

    vector<int> A,B;

    while(a>0)
    {
        A.pb(a%10);
        a/=10;
    }
    while(b>0)
    {
        B.pb(b%10);
        b/=10;
    }
    int cnt=0;
    for(int i=0;i<4;i++)
        if(A[i]!=B[i])
         cnt++;

    return cnt==1 ;
}

int main()
{
  int T;
  cin>>T;
    sieve(9999);

    for(int i=1000;i<=9999;i++)
    {
        if(!vis[i])
            p.pb(i);
    }


    for(int i=0;i<sz(p);i++)
    {
        for(int j=i+1;j<sz(p);j++)
        {
            int a=p[i];
            int b=p[j];

            if(check(a,b))
                v[a].pb(b),v[b].pb(a);

        }
    }

    while(T--)
    {
        int f,t;
        cin>>f>>t;

   queue< pair<int,int>> q;
   clr(vis2,0);
   q.push(mp(f,0));
  int ans=-1;

   while(!q.empty())
   {

       int no=q.front().first;
       int co=q.front().second;

       q.pop();

       vis2[no]=1;

       if(no==t)
       {
           ans=co;
           break;
       }

       for(int i=0;i<sz(v[no]);i++)
       {
           if(vis2[v[no][i]])
            continue;


           q.push(mp(v[no][i],co+1));
       }

   }
   if(ans==-1)
    cout<<"Impossible\n";
   else
    cout<<ans<<endl;
    }
}
