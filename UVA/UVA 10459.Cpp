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
vector< vector<int> > v(5005);
int vis[5005];
int mx,node,fr;
vector< int> temp,path,W,B;
void dfs(int n,int c)
{
    vis[n]=1;
    if(sz(v[n])==1)
    {
        if(c>mx)
        {
              node=n;
              mx=c;
        }
        if(fr)
            W.pb(n);
    }



   for(int i=0;i<sz(v[n]);i++)
   {
       if(vis[v[n][i]])
        continue;

       dfs(v[n][i],c+1);
   }

}

void dfs2(int f,int t)
{
    vis[f]=1;

    if(f==t)
    {

        path=temp;
        return ;
    }


   for(int i=0;i<sz(v[f]);i++)
   {
       if(vis[v[f][i]])
        continue;
         temp.pb(v[f][i]);

       dfs2(v[f][i],t);

       temp.pop_back();
   }

}


















int main()
{
    int n;
    while(1)
    {
        if(cin.eof())
            break;
        cin>>n;
        int m,t;
        v.clear();
        v.resize(5005);
        W.clear();
        B.clear();
        temp.clear();
        path.clear();

        for(int i=1;i<=n;i++)
        {
            scanf("%d",&m);
            for(int j=0;j<m;j++)
            {
                scanf("%d",&t);
                v[i].pb(t);
            }
        }


       clr(vis,0);
       mx=-1;
       fr=0;
       dfs(1,0);
       int node1=node;

       clr(vis,0);
       mx=-1;
       fr=1;
       dfs(node,0);

       int node2=node;

       clr(vis,0);
       dfs2(node1,node2);
       path.emplace(path.begin());



       if(sz(path)%2!=0)
       {
           int mid=sz(path)/2;
           B.pb(path[mid]);

       }
       else
       {
           int mid=sz(path)/2;
           B.pb(path[mid]);
           B.pb(path[mid-1]);

       }
        printf("Best Roots  : ");
        sort(all(B));
       for(int i=0;i<sz(B);i++)
       {
           if(i!=sz(B)-1)
            printf("%d ",B[i]);
           else
            printf("%d",B[i]);
       }
       printf("\n");
       printf("Worst Roots : ");
       sort(all(W));
        for(int i=0;i<sz(W);i++)
       {
           if(i!=sz(W)-1)
             printf("%d ",W[i]);
           else
             printf("%d",W[i]);
       }
         printf("\n");
    }
}
