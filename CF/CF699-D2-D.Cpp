/*
explanation : the idea is it is obvious that the min cost i can spend to erase a cycle formed is one for every cycle and that there must
must be exactly one root so i will decide a root with min cost and to be min it is whether a node cause cycle by its parent or node that
its parent is it self then for every node cause cycle or its parent is itself except for the root make its parent is the root.

complexity : O( nlogn )
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
int par[200009],rnk[200009],arr[200009],mrk[200009];
vector< vector<int> > v(200009);
void intial()
{
    for(int i=0;i<200009;i++)
        par[i]=i,rnk[i]=1;
}
int p(int n)
{
    if(par[n]==n)
        return n;
    return par[n]=p(par[n]);
}
bool lnk(int a,int b)
{
    int aa=p(a);
    int bb=p(b);

    if(aa!=bb)
    {
        if(rnk[aa]>=rnk[bb])
            rnk[aa]+=rnk[bb],par[bb]=aa;
        else
            rnk[bb]+=rnk[aa],par[bb]=aa;
       return 1;
    }
    return 0;
}
int main()
{
    M();
    int n;
    cin>>n;
    int pr;
    intial();
    int fre=-1;
    for(int i=1;i<=n;i++)
    {
        cin>>pr;
        arr[i]=pr;
        if(!lnk(pr,i))
        {
            mrk[i]=1;
        }
        if(pr==i)
            fre=i;
    }
    set<int> s;
    for(int i=1;i<=n;i++)
    {
        int pp=p(i);
        s.insert(pp);
        v[pp].pb(i);
    }
    bool ok=1;
    int re;
    for(auto i=s.begin();i!=s.end()&&ok&&fre==-1;i++)
    {
        int num=(*i);
        for(int j=0;j<sz(v[num])&&ok;j++)
        {
            if(mrk[v[num][j]])
            {
                re=v[num][j];
                ok=0;
            }
            else
             re=v[num][j];
        }
    }
    int ans=0,root;
    if(fre!=-1)
    {
        root=fre;
    }
    else
    {
        ans++;
        arr[re]=re;
        root=re;
    }
     for(auto i=s.begin();i!=s.end();i++)
    {
        int num=(*i);
        for(int j=0;j<sz(v[num]);j++)
        {
            if(v[num][j]==root)
             {
                continue;
             }
            if(mrk[v[num][j]])
            {
                arr[v[num][j]]=root;
                 ans++;
            }
            else if(arr[v[num][j]]==v[num][j])
            {
                arr[v[num][j]]=root;
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++)
        cout<<arr[i]<<" ";
}
