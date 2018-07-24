#include <bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<map>
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
#define OO 100000000

typedef  long long     ll ;
typedef  unsigned long long ull;
const double eps= (1e-5);
using namespace std;
int dcmp(long double a,long double b){   return fabsl(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
ll getBit(ll num, int idx) {return ((num >> idx) & 1ll) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
const int MAX_SIZE=400;
int v[MAX_SIZE][MAX_SIZE];
int vis[MAX_SIZE];
int path[400],pathlen;


double d;int n;
vector<point> places;
vector<int> pcnt;
vector<int> maxjump;

int dfs(int S,int T,int len,int mi)
{
    path[len]=S;
    if(S==T)
    {
        pathlen=len;
        return mi;
    }

    vis[S]=1;

    for(int i=0;i<400;i++)
    {
        if(vis[i]||v[S][i]<=0)
            continue;

       int res= dfs(i,T,len+1,min(mi,v[S][i]));

       if(res>0)
        return res;
    }

    return 0;
}








ll ford_fulkerson(int S,int T)
{
    ll flows=0;

    while(1)
    {
        clr(vis,0);
        int val=dfs(S,T,0,INT_MAX);
        if(!val)
            break;

        for(int i=1;i<=pathlen;i++)
        {
           int f=path[i-1];
           int t=path[i];

            v[f][t]-=val;
            v[t][f]+=val;


        }

        flows+=val;
    }
    return flows;
}






bool canreach(int i,int j)
{
    return (dcmp(length(vec(places[i],places[j])),d)!=1);
}

void construct_graph(){
    //0->n-1  n->2n-1
    clr(v,0);
    clr(vis,0);
    for(int i=0; i<n; i++){
        v[i][i+n]=maxjump[i];
        v[n+n+i][i]=pcnt[i];

    }
    for(int i=0; i<places.size(); i++)
    {
        for(int j=0; j<places.size(); j++)
        {
            if(i==j) continue;
            if(canreach(i,j)){
                v[i+n][j]=OO;
            }

        }
    }

    for(int i=0;i<n;i++)
        v[n+n+n+3][n+n+i]=INT_MAX;



}

int main()
{

int t;
cin>>t;
while(t--)
{
    cin>>n>>d;
    places.clear();
    pcnt.clear();
    maxjump.clear();

    places=vector<point>(n);
    pcnt=vector<int>(n);
    maxjump=vector<int>(n);
    int sum=0;
    for(int i=0; i<n; i++)
    {
        int a,b,c;
        cin>>a>>b>>c>>maxjump[i];
        places[i]=point(a,b);
        pcnt[i]=c;
        sum+=c;
    }


    vector<int> nodes;
    for(int i=0; i<n; i++)
    {
        construct_graph();
        if(ford_fulkerson(n+n+n+3,i)==sum)
        {
            nodes.push_back(i);

        }
    }

    for(int i=0; i<nodes.size(); i++)
    {
        cout<<nodes[i];
        if(i!=nodes.size()-1) cout<<" ";
    }
    if(nodes.size()==0)
    {
        cout<<"-1";
    }
    cout<<endl;
}
}


