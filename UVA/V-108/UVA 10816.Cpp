/*
explanation : here the idea is to simply binary search on the MAX temp then run dijkstra
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
double dist[109],D;
int vis[109];
vector<int> pre(109),path,P;
int s,d;
typedef struct NODE
{
    int no;
    double w,t;

    NODE(int no,double w,double t) : no(no),w(w),t(t) {}

    bool operator < (const NODE &e) const
    {
        return w>e.w;
    }
}N;
vector< vector<N> > v(109);
bool dijk(double MAX)
{

    for(int i=0;i<=100;i++)
        dist[i]=inf,pre[i]=-1,vis[i]=0;

    dist[s]=0;

    priority_queue< N> pq;

    pq.push(N(s,0,0));

    while(!pq.empty())
    {
        N cur=pq.top();
        pq.pop();
        if(vis[cur.no])
            continue;

        vis[cur.no]=1;

        double add=cur.w;

        for(int i=0;i<sz(v[cur.no]);i++)
        {
            N nw= v[cur.no][i];

            if(dist[nw.no]>add+nw.w&&dcmp(nw.t,MAX)!=1)
            {
                dist[nw.no]= add+nw.w;
                pq.push(N(nw.no,add+nw.w,0));
                pre[nw.no]=cur.no;
            }
        }
    }



    if(dist[d]==inf)
        return 0;

    D=dist[d];

    path=pre;
    return 1;

}





void pr(int num)
{
    if(num==-1)
    {

        return;
    }



    pr(path[num]);
    P.pb(num);
}














int main()
{
    int n,e;
    while(cin>>n>>e)
    {
        v.clear();
        v.resize(109);
        P.clear();
        cin>>s>>d;
        int f,t;
        double l,temp;
        for(int i=0;i<e;i++)
        {
            cin>>f>>t>>temp>>l;
            v[f].pb(N(t,l,temp));
            v[t].pb(N(f,l,temp));
        }


       double lw=20,hg=50,ans;
       int T=200;
       while(T--)
       {

           double mid=(lw+hg)/2;

           if(dijk(mid))
            hg=mid-1,ans=mid;
           else
            lw=mid+1;
       }

       pr(d);
       for(int i=0;i<sz(P);i++)
        if(i!=0)
        cout<<" "<<P[i];
        else
            cout<<P[i];

       cout<<endl<<fixed<<setprecision(1)<<D<<" "<<ans<<endl;
    }
}


