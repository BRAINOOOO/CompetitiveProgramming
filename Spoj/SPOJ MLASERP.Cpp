/*
explanation :the idea is the number of needed mirrors is directly proportional with the number of corners in my path so at each corner
i will increase the cost , and to know it is a corner you need to store the parent of my current node.
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
vector<string> v;
int vis[109][109];
int dist[109][109];
int n,m;
const int inf=1000000000;
struct node
{
    int rw,cl,pr,pc,cost;

    node(int rw,int cl,int pr,int pc,int cost) : rw(rw),cl(cl),pr(pr),pc(pc),cost(cost) {}

    bool operator < ( const node &e) const
    {
        return cost> e.cost;
    }
};

int dijk(int sr,int sc,int dr,int dc)
{
    for(int i=0;i<109;i++)
    {
        for(int j=0;j<109;j++)
            dist[i][j]=inf;
    }


    dist[sr][sc]=0;

    priority_queue< node > q;

    q.push(node(sr,sc,sr,sc,0));

    while(!q.empty())
    {

       node cur= q.top();
       q.pop();

       int r=cur.rw ; int cl=cur.cl; int pr=cur.pr; int pc=cur.pc; int cost=cur.cost;

       if(vis[r][cl])
        continue;

       vis[r][cl]=1;

       if(cl+1<m&&v[r][cl+1]!='*')
       {

           if(pr==r)
           {
               int nc= cost;


               if(dist[r][cl+1]>= nc)
               {

                   dist[r][cl+1]=nc;
                   q.push(node(r,cl+1,r,cl,nc));
               }
           }
           else
           {
               int nc= cost+1;

               if(dist[r][cl+1]>= nc)
               {

                   dist[r][cl+1]=nc;
                   q.push(node(r,cl+1,r,cl,nc));
               }
           }
       }


       if(r+1<n&&v[r+1][cl]!='*')
       {

           if(pc==cl)
           {
               int nc= cost;
               if(dist[r+1][cl]>= nc)
               {
                   dist[r+1][cl]=nc;
                   q.push(node(r+1,cl,r,cl,nc));
               }
           }
           else
           {
               int nc= cost+1;
               if(dist[r+1][cl]>= nc)
               {
                   dist[r+1][cl]=nc;
                   q.push(node(r+1,cl,r,cl,nc));
               }
           }
       }


        if(cl-1>=0&&v[r][cl-1]!='*')
       {


           if(pr==r)
           {
               int nc= cost;

               if(dist[r][cl-1]>= nc)
               {
                   dist[r][cl-1]=nc;
                   q.push(node(r,cl-1,r,cl,nc));
               }
           }
           else
           {
               int nc= cost+1;

               if(dist[r][cl-1]>= nc)
               {
                   dist[r][cl-1]=nc;
                   q.push(node(r,cl-1,r,cl,nc));
               }
           }
       }
        if(r-1>=0&&v[r-1][cl]!='*')
       {

           if(pc==cl)
           {
               int nc= cost;

               if(dist[r-1][cl]>= nc)
               {
                   dist[r-1][cl]=nc;
                   q.push(node(r-1,cl,r,cl,nc));
               }
           }
           else
           {
               int nc= cost+1;

               if(dist[r-1][cl]>= nc)
               {
                   dist[r-1][cl]=nc;
                   q.push(node(r-1,cl,r,cl,nc));
               }
           }
       }

    }

    return dist[dr][dc];
}









int main()
{
    cin>>m>>n;
    if(m==1&&n==1)
    {
        cout<<"-1\n";
        return 0;
    }
    string st;
    vector<pair<int,int> > w;
    for(int i=0;i<n;i++)
    {
        cin>>st;
        v.pb(st);
        for(int j=0;j<m;j++)
        {
            if(v[i][j]=='C')
            {
                w.pb(mp(i,j));
            }
        }

    }
 if(sz(w)!=2)
 {
     cout<<"0\n";
     return 0;
 }
    int sr= w[0].first;
    int sc= w[0].second;
    int dr= w[1].first;
    int dc= w[1].second;
    cout<<dijk(dr,dc,sr,sc)<<endl;


}
