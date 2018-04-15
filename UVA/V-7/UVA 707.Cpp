/*
 topic is dp with graph
 idea of the problem is at each step try all the possible cells and dfs till the step t if the returning is one means there is
 a way this cell can reach end else there is no way so if there is a way just count it .
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
int dcmp(long double a,long double b){   return fabsl(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
ll getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
ll setBit1(ll num, int idx) {return num | (1ll<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(ll mask) {int ret=0; while (mask) 	{mask &= (mask-1ll);++ret;	}return ret;}
int arr[109][109][109];
int mem[109][109][109];
int vis[109][109][109];

int dr[]={0,0,1,0,-1};
int dc[]={0,1,0,-1,0};
pair<pair<int,int>,int> pre[109][109][109];
vector< pair<int,int>> v1;
int Fc,Fr,t,w,h;
vector< set<pair<int,int> > > cnt(109);
bool valid(int r,int c)
{
    if(r>=1&&r<=h&&c>=1&&c<=w)
        return 1;
    return 0;
}
void fun(int r,int c,int lv)
{

    if(r==-1&&c==-1&&lv==-1)
        return ;


    fun(pre[r][c][lv].first.first,pre[r][c][lv].first.second,pre[r][c][lv].second);

    v1.pb(mp(r,c));
}

int dfs(int r,int c,int lv)
{

     int &ret=mem[r][c][lv];

     if(ret!=-1)
        return ret;
    if(lv==t)
     {
         Fr=r; Fc=c;
        return ret=1;
     }
    int fl=0;


     for(int i=0;i<5;i++)
     {
         int nr= r+dr[i]; int nc= c+dc[i];
         int nlv=lv+1;

         if(valid(nr,nc)&&arr[nlv][nr][nc]==0)
         {

             pre[nr][nc][nlv]=mp(mp(r,c),lv);
             if(dfs(nr,nc,nlv))
              {
                cnt[nlv].insert(mp(nr,nc));

                fl=1;
              }
         }

     }
     if(!fl)
     {

        return ret=0;
     }
    else
    {
        return ret=1;
    }
}

int main()
{
    int cs=1;
    while(cin>>w>>h>>t)
    {
        clr(arr,0);
        clr(vis,0);
        clr(mem,-1);
        clr(pre,-1);
        cnt.clear();
        cnt.resize(109);
        if(w==0&&h==0&&t==0)
            break;

         int n;
         cin>>n;
         int N=n;
         while(N--)
         {
            int ti,x1,x2,y1,y2;
           cin>>ti>>x1>>y1>>x2>>y2;

            for(int i=y1;i<=y2;i++)
                for(int j=x1;j<=x2;j++)
                 arr[ti][i][j]=1;
         }


         for(int i=1;i<=h;i++)
         {
             for(int j=1;j<=w;j++)
           {
             if(arr[1][i][j]==0)
             {


                if( dfs(i,j,1)==1)
                {
                    cnt[1].insert(mp(i,j));
                }

             }
           }
         }

         cout<<"Robbery #"<<cs++<<":\n";

         int fl=0;
         if(sz(cnt[t])==0)
         {
             fl=1;
             cout<<"The robber has escaped.\n";

         }
         else
         {
             v1.clear();
             fun(Fr,Fc,t);
             for(int i=0;i<sz(v1);i++)
             {
                 if(sz(cnt[i+1])==1)
                 cout<<"Time step "<<i+1<<": The robber has been at "<<v1[i].second<<","<<v1[i].first<<".\n",fl=1;

             }

         }

         if(!fl)
            cout<<"Nothing known.\n";

                      cout<<"\n";

    }

}
