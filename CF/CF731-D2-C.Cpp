/*
explanation : here each pair of socks i will use in ith day must be of the same colour so suppose at first day i will use
left from 1st socks and second from third one the next day i will use left from 1st socks and right from 4th socks so as each
pair must be the same colour so 1st = 3rd and 1st = 4th since 1st colour will have the same colour so 3rd must have the same 
colour as 4th so  1st=3rd=4th from the idea of using the disjoint set comes.
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
int p[200009],rnk[200009],col[200009],vis[200009];
vector<vector<int> > v(200009);
void intil()
{
    for(int i=0;i<200009;i++)
        p[i]=i,rnk[i]=1;
}
int par(int n)
{
    if(p[n]==n)
        return n;
    return p[n]=par(p[n]);
}
void lnk(int a,int b)
{
    int A=par(a);
    int B=par(b);
    if(A!=B)
    {
        if(rnk[A]>=rnk[B])
        {
            rnk[A]+=rnk[B];
            p[B]=A;
        }
        else
        {
            rnk[B]+=rnk[A];
            p[A]=B;
        }
    }
}
int main()
{
    int k,m,n;
    cin>>n>>m>>k;
    set<int > s;

    for(int i=1;i<=n;i++)
        cin>>col[i];
    intil();
    int l,r;
    for(int i=1;i<=m;i++)
    {
        cin>>l>>r;
       lnk(l,r);
    }
    int ans=0,mx,id=1;
     for(int i=1;i<=n;i++)
     {
         int w=par(i);
         s.insert(w);
         v[w].pb(i);
     }
     for(auto i=s.begin();i!=s.end();i++)
     {
         int parent= (*i);
         int mx=0;
         for(int j=0;j<sz(v[parent]);j++)
         {
             vis[col[v[parent][j]]]++;
         }
          for(int j=0;j<sz(v[parent]);j++)
         {
             mx=max(mx,vis[col[v[parent][j]]]);
             vis[col[v[parent][j]]]=0;
         }
         ans+=sz(v[parent])-mx;
     }
     cout<<ans<<endl;
}
