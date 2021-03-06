// ICPC Champion is here

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
int dcmp(long double a,long double b){   return fabsl(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
ll getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
ll setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
vector< string > v;
int dr[]={-1,-1,0,1,1,1,0,-1};
int dc[]={0,1,1,1,0,-1,-1,-1};
const int N=1009,inf=INT_MAX;
int dist[N][N],r,c;
typedef struct edge
{
    int ro,cl,w;
    edge(int ro,int cl,int w) : ro(ro),cl(cl),w(w) {}

}e;

bool valid(int ro,int cl)
{
    return (ro<r&&ro>=0&&cl<c&&cl>=0);
}











int dijk(int sr,int sc,int dsr,int dsc)
{

    
    for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
        dist[i][j]=inf;

    dist[sr][sc]=0;
    deque< e> dq;
    dq.push_back(e(sr,sc,0));

    while(!dq.empty())
   {
       e cur=dq.front();
       dq.pop_front();

      
       if(cur.ro==dsr&&cur.cl==dsc)
        break;

       int add=cur.w;

       for(int i=0;i<8;i++)
      {
           if(!valid(cur.ro+dr[i],cur.cl+dc[i]))
            continue;

            int nr=cur.ro+dr[i];
            int nc=cur.cl+dc[i];
            int addedw= ((v[cur.ro][cur.cl]-'0')==i ? 0 : 1);


            if(dist[nr][nc]>addedw+add)
            {
                dist[nr][nc]=addedw+add;
                if(addedw==0)
                dq.push_front(e(nr,nc,addedw+add));
                else
                dq.push_back(e(nr,nc,addedw+add));
            }
       }
   }
   return dist[dsr][dsc];
}










int main()
{

    cin>>r>>c;
    string st;
    for(int i=0;i<r;i++)
    {
        cin>>st;
        v.pb(st);
    }
    int q;
    cin>>q;
    int sr,sc,dsr,dsc;
    while(q--)
    {
        cin>>sr>>sc>>dsr>>dsc;

        cout<<dijk(sr-1,sc-1,dsr-1,dsc-1)<<endl;
    }
}




