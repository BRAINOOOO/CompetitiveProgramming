/*
explanation : first the problem is hoew to get the second MST, the path of the 2nd MST differ from the 
path of the first MST by at least one edge so i will simly remove one edge from the first MST path
and run MST and minmize thats all :)

complexity : O( (n-1)*(n)*log(E)*T)
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
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
int setBit0(int num, int idx) {return num & ~(1<<idx);}
int flipBit(int num, int idx) {return num ^ (1<<idx);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
int oo=1000000000,parent[100+9],rnk[100+9];
int par(int n)
{
    if(parent[n]==n)
        return n;
    return parent[n]=par(parent[n]);
}
struct edge
{
    int f,t,w;
    edge(int f,int t,int w) : f(f),t(t),w(w) {}
    bool operator < (const edge &e) const
    {
        return w>e.w;
    }
};
void intil(int n)
{
    for(int i=0;i<=n;i++)
    {
        parent[i]=i;
        rnk[i]=1;
    }
}
bool unon(int f,int t)
{
    int ff=par(f);
    int tt=par(t);
    if(ff==tt)
    {
        return 0;
    }
    if(rnk[ff]>rnk[tt])
    {
        rnk[ff]+=rnk[tt];
        parent[tt]=ff;
    }
    else
    {
        rnk[tt]+=rnk[ff];
        parent[ff]=tt;
    }
    return 1;
}
pair<int,vector<edge>> mst(vector<edge> v,int n,edge e)
{
    intil(n);
    vector< edge > edges;
    int mi=0;
    priority_queue < edge > q;
        int f=0;
        for(int i=0;i<sz(v);i++)
        {
            if((v[i].f==e.f&&v[i].t==e.t&&v[i].w==e.w&&f<2)||(v[i].f==e.t&&v[i].t==e.f&&v[i].w==e.w&&f<2))
            {
                f++;
                continue;
            }
            q.push(v[i]);
        }
       while(!q.empty())
       {
           edge cur=q.top();
           q.pop();
           if( unon(cur.f,cur.t))
           {
               mi+=cur.w;
               edges.pb(cur);
           }
       }
       if(sz(edges)!=n-1)
       {
           return mp(oo,edges);
       }
    return mp(mi,edges);
}
int main()
{
    int n,e,cs=1,tst;
    cin>>tst;
    while(tst--)
    {
      cin>>n>>e;
    vector< edge > v;
    int s,en,c;
    for(int i=0;i<e;i++)
    {
        cin>>s>>en>>c;
        v.pb(edge(s,en,c));
        v.pb(edge(en,s,c));
    }
   cout<<"Case #"<<cs++<<" : ";
   pair<int,vector<edge>> p;
   p= mst(v,n,edge(-1,-1,-1));
   if(p.first==oo)
   {
       cout<<"No way\n";
       continue;
   }
   int mi=oo;
   for(int i=0;i<sz(p.second);i++)
   {
       mi=min(mi,mst(v,n,p.second[i]).first);
   }
   if(mi==oo)
   {
       cout<<"No second way\n";
       continue;
   }
   cout<<mi<<endl;
    }
}
