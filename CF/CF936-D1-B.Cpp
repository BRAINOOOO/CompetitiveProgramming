/*
explanation : here the idea is when its my turn so i will try to win or at least draw  and when its his turn i will try to lose or
at least draw .
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
int mem[2000000][2],vis[2000000][2],st[2000000][2];
vector< vector<int> > v(200000+9);
int solve(int n,int t)
{

    if(vis[n][t])
        return mem[n][t];

        if(sz(v[n])==0)
            return mem[n][t]=1;

        vis[n][t]=1;
    mem[n][t]=-1;
    int res=1,ans=1;
    for(int i=0;i<sz(v[n]);i++)
    {
         st[n][t]=v[n][i];
        res=solve(v[n][i],!t);

         if(res==1&&t==1)
         {

            return mem[n][t]=0;
         }
         else if(res==0&&t==0)
            return mem[n][t]=1;
         else
            ans=min(ans,res);
    }


     if(t==1)
     {
         if(ans==-1)
            return mem[n][t]=-1;
         return mem[n][t]=1;
     }
     else
     {
         if(ans==-1)
            return mem[n][t]=-1;
         return mem[n][t]=0;
     }
}
int main()
{
    int n,m;
    cin>>n>>m;
    ll l;
    for(int i=1;i<=n;i++)
    {
        cin>>l;
        ll to;
        for(int j=0;j<l;j++)
        {
            cin>>to;
            v[i].pb(to);
        }
    }
    int s;
    cin>>s;

    clr(st,-1);
    int ans=solve(s,1);

    if(ans==-1)
        cout<<"Draw\n";
    else if(ans==0)
        cout<<"Win\n";
    else
        cout<<"Lose\n";

        int t=1;
        int node=s;
       if(ans==0)
       {
           cout<<s<<" ";
           while(1)
           {
              int res= st[node][t];
              if(res==-1)
                break;
                cout<<res<<" ";

              node=res;
              t=!t;
           }
       }
}
