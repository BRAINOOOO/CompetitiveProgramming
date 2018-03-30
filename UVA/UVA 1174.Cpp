/*
direct min spanning tree 
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
typedef struct No
{
    int to,w,fr;
    No(int fr,int to,int w) : fr(fr),to(to),w(w) {}

    bool operator < ( const No &e) const
    {
        return w> e.w;
    }
} N;
priority_queue< N > pq;
int par[2009],rnk[2009];
map< string,int> mb;
void intial()
{
    for(int i=1;i<=2000;i++)
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
    int A=p(a); int B=p(b);
    if(A==B)
        return 0;

    if(rnk[A]>rnk[B])
    {
        par[B]=A;
        rnk[A]+=rnk[B];
    }
    else
    {
        par[A]=B;
        rnk[B]+=rnk[A];
    }
    return 1;
}








int MST()
{
    int ans=0;
    while(!pq.empty())
    {
        N cur=pq.top();
        pq.pop();
       if( lnk(cur.fr,cur.to) )
        ans+=cur.w;


    }


    return ans;
}




int main()
{
    int t;
    cin>>t;

    while(t--)
   {
       intial();
        int n,m;
        mb.clear();
       cin>>n>>m;
       int id=1;
       while(m--)
       {
           string fr,to;
           int w;
          cin>>fr>>to>>w;

          if(mb[fr]==0)
            mb[fr]=id++;
          if(mb[to]==0)
            mb[to]=id++;

          pq.push(N(mb[fr],mb[to],w));
       }

      cout<< MST() <<endl;
   }
}
