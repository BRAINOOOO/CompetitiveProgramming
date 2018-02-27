/*
explanation : first express the relationships as a graph so if i am at node A then within t i will go to node B and the winner
is B okay if i started from B there must be a path to A equal in length so the cycle must be symmetric 

                                                                A
                                                               / \
                                                              /   \
                                                             B    D
                                                             \   /
                                                              \ /
                                                               C
                                                 so if t=2
                                                 A to B to C ( C is the winner ) 
                                                 starting from C to D to A ( A is the winner )
                                                 and for every node in the cycle the condition holds 
   
   but if it was an odd cycle so the cycle can't be symmetric so the only way is to let t be the length of the cycle so the winner
   will be the starter. okay there is off course alot of cycles seprated if i choose a t= no of cycle edges ,if t will be its multiple \
   so this is okay too doesn't break the condition so i will get the lcm of all the cycles' cost and this will be the min t.
   
   and if there is no path from a node and itself so there is no answer.
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
vector< vector<int> > v(109);
int vis[109],fl,pth,in,Des;
void dfs(int n,int lv)
{
    if(n==Des&&in)
    {
        fl=1;
        pth=lv;
        return;
    }
    if(vis[n])
        return ;
    vis[n]=1;
    in=1;
    for(int i=0;i<sz(v[n]);i++)
    {
        dfs(v[n][i],lv+1);
    }
}
int main()
{
    int n;
    cin>>n;
    int cr;
    for(int i=1;i<=n;i++)
    {
        cin>>cr;
        v[i].pb(cr);
    }
    int no=1;
    for(int i=1;i<=n;i++)
    {
        if(vis[i])
            continue;
        fl=0;
        Des=i;
        in=0;
        dfs(i,0);
        if(!fl)
        {
            cout<<"-1";
            return 0;
        }
        if(pth%2==0)
            pth/=2;
        no=lcm(pth,no);
    }
    cout<<no<<endl;
}
