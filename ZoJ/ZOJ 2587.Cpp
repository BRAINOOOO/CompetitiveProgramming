// ICPC champion is here
#include <bits/stdc++.h>
#include<iostream>
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
#define     point                    complex<long double>
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
int n,m,vis[52],Cost,L,path[52],visi[52],arr[52][52];
vector< pair<int,int> > e,ans;
ll dfs(int no,int des,int len,int mi)
{
    path[len]=no;
    vis[no]=1;
    if(no==des)
    {
        L=len;
        return mi;
    }
    int ret=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]||arr[no][i]<=0)
            continue;

      ret= dfs(i,des,len+1,min(mi,arr[no][i]));

       if(ret>0)
        return ret;
    }

    return ret;
}




void MaxFlow(int src,int sink)
{
    while(1)
    {

    clr(vis,0);
    Cost=dfs(src,sink,0,INT_MAX);
    if(!Cost)
        break;
    for(int i=0;i<L;i++)
    {
        int fr= path[i];
        int to= path[i+1];

        arr[fr][to]-=Cost;
        arr[to][fr]+=Cost;

    }


    }
}
void dfs2(int no)
{
    visi[no]=1;


    for(int i=1;i<=n;i++)
    {
        if(arr[no][i]<=0||visi[i])
            continue;
        dfs2(i);
    }
}
void I()
{
    clr(visi,0);
    clr(arr,0);
    e.clear();
    ans.clear();
}







int main()
{
	freopen("attack.in", "r", stdin);
	freopen("attack.out", "w", stdout);

      int A,B;
      cin>>n>>m>>A>>B;
         I();

        int fr,to,w;
       for(int i=0;i<m;i++)
       {
           cin>>fr>>to>>w;

           arr[fr][to]=w;
           arr[to][fr]=w;
           e.pb(mp(fr,to));
       }

       MaxFlow(A,B);

     dfs2(A);

      for(int i=0;i<sz(e);i++)
      {
        //  cout<<e[i].first<<" "<<e[i].second<<endl;
          if(visi[e[i].first]&&!visi[e[i].second])
            ans.pb(mp(e[i].first,e[i].second));
          else if(visi[e[i].second]&&!visi[e[i].first])
             ans.pb(mp(e[i].first,e[i].second));
      }
      int fl=0;

      for(int i=0;i<sz(ans);i++)
      {
          int fr= ans[i].first; int to= ans[i].second;

          arr[fr][to]=1;
          arr[to][fr]=1;
          clr(visi,0);
          dfs2(A);

          if(!visi[B])
          {
            fl=1;

            break;
           }
           arr[fr][to]=0;
           arr[to][fr]=0;

      }

      if(!fl)
        cout<<"UNIQUE\n";
      else
        cout<<"AMBIGUOUS\n";


}






