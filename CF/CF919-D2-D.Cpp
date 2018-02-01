/*
explanation : here it is obvious that if there is a cycle so the answer will be inf so print -1 else it become a DAG so we
can dp on the max number of a certain char i will try all 26 char thats it.

complexity : alph * n + n log m
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
int countNumBit1(ll mask) {int ret=0; while (mask) 	{mask &= (mask-1ll);++ret;	}return ret;}
int fl,tim,en[300005],st[300005];
vector<vector<int>> v(300005);
string s;
int mem[300005],ch;
void dfs(int n)
{
    st[n]=tim++;
    for(int i=0;i<sz(v[n]);i++)
    {
        int no=v[n][i];
        if(st[no]==-1)
            dfs(no);
        else
       {
         if(en[no]==-1)
            fl=1;
       }
    }
    en[n]=tim++;
}
int solve(int no)
{
    if(sz(v[no])==0)
        return (s[no-1]-'a'==ch ? 1 :0);
    int &ret=mem[no];
    if(ret!=-1)
        return ret;
    int ans=0;
    for(int i=0;i<sz(v[no]);i++)
    {
        ans=max(ans,(s[no-1]-'a'==ch ? 1 :0)+  solve(v[no][i]));
    }
    ret=ans;
    return ret;
}
int main()
{
    int n,m;
    cin>>n>>m>>s;
    int f,t;
    for(int i=0;i<m;i++)
    {
        cin>>f>>t;
        v[f].pb(t);
    }
   fl=0;
   clr(en,-1);
   clr(st,-1);
   for(int i=1;i<=n;i++)
   {
       if(!vis[i])
       {
           dfs(i);
           if(fl)
           {
               cout<<"-1\n";
               return 0;
           }
       }
   }
   int mx=1;
   for(ch=0;ch<26;ch++)
   {
       clr(mem,-1);
       for(int no=1;no<=n;no++)
       {
           mx=max(mx,solve(no));
       }
   }
  cout<<mx<<endl;
}
