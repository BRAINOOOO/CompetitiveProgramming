/*
here the idea is if one can reach me at any point so it can reach me at the end too 
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
ll getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
ll setBit1(ll num, int idx) {return num | (1ll<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(ll mask) {int ret=0; while (mask) 	{mask &= (mask-1ll);++ret;	}return ret;}
const int inf=INT_MAX;
int vis[1009][1009],n,m,cost,ans;
int dr[]={1,0,-1,0};
int dc[]={0,1,0,-1};

vector< string> v;
typedef struct NODE
{
    int r,c,cost;
    NODE(int r,int c,int cost) : r(r),c(c),cost(cost) {}
}N;
queue< N > q;
int BFS1(int sr,int sc,int er,int ec)
{


    q.push(N(sr,sc,0));
    vis[sr][sc]=1;
    while(!q.empty())
    {

       N cur= q.front();
        q.pop();

        if(cur.r==er&&cur.c==ec)
            return cur.cost;



        for(int i=0;i<=3;i++)
        {
          int  nwr=dr[i]+cur.r; int nwc=dc[i]+cur.c;

            if(nwr<0||nwc<0||nwr>=n||nwc>=m||vis[nwr][nwc]||v[nwr][nwc]=='T')
             continue;
             vis[nwr][nwc]=1;

             q.push(N(nwr,nwc,cur.cost+1));

        }
    }
}
void BFS2(int sr,int sc)
{



    q.push(N(sr,sc,0));
     vis[sr][sc]=1;

    while(!q.empty())
    {

       N cur= q.front();
        q.pop();

        if(v[cur.r][cur.c]>='0'&&v[cur.r][cur.c]<='9'&&cur.cost<=cost)
            ans+=v[cur.r][cur.c]-'0';


        for(int i=0;i<=3;i++)
        {
            int nwr=dr[i]+cur.r; int  nwc=dc[i]+cur.c;

            if(nwr<0||nwc<0||nwr>=n||nwc>=m||vis[nwr][nwc]!=0||v[nwr][nwc]=='T')
              continue;
              vis[nwr][nwc]=1;
             q.push(N(nwr,nwc,cur.cost+1));

        }
    }
}










int main()
{
    cin>>n>>m;
    string st;
    int sr,sc,er,ec;
    for(int i=0;i<n;i++)
    {
        cin>>st;
        v.pb(st);
        for(int j=0;j<m;j++)
        {
            if(v[i][j]=='S')
            {
                sr=i;
                sc=j;
            }
            if(v[i][j]=='E')
            {
                er=i;
                ec=j;
            }
        }
    }

 cost =BFS1(sr,sc,er,ec);
  while(!q.empty())
    q.pop();
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      vis[i][j]=0;

   BFS2(er,ec);


 cout<<ans<<endl;
}

