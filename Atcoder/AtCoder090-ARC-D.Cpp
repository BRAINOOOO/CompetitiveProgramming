/*
explanation : the idea is about the order of putting the distances for eg
                  
                                                 A*----------------------*B                 *C---------------*D
                      
                                         if i connects point A to point B so i will say dist[A]=0  dist[B]=dist[A]+d 
                                         and do the same for C to D then after that if he want to connect B and C i can
                                         do so i will set dist[C] to dist[B]+d but the problem is i need to adjust every dist 
                                         from C which is TL but observe that if i first connect B to C then C and D it will be okay
                                         but how can i do so first i will record for each one people standing at its left and at 
                                         its right so i will connect it to them ( start to build the tree branching ) then all of those
                                         on the left and on the right i will do the same with them okay but takecare they may be disjoint
                                         if they are disjoint i don't care about their relations to gether i only care about the relation
                                         in each partion so i can always set the first person where i start branching from it at any 
                                         distance for example zero.
    
 complexity : n*log(n)
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
const ll oo=100000000000000;
vector< pair< pair<int,int> , int > > v;
vector<int> v1;
vector< vector<pair<int,int> > > r(1000000),l(1000000);
ll arr[1000000],vis[1000000];
int main()
{
    int n,m;
    cin>>n>>m;
    if(m==0)
    {
        cout<<"Yes\n";
        return 0;
    }
    int a,b,d;
    set<int> st;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>d;
        st.insert(a);
        st.insert(b);
        r[a].pb(mp(b,d));
        l[b].pb(mp(a,d));
    }
    v1.pb(a);
    vis[a]=1;
    st.erase(st.find(a));
    arr[a]=0;
    int fl=0;
    for(int i=0;i<1000000;i++)
        arr[i]=-oo;
    while(sz(st)>0)
   {
    for(int i=0;i<sz(v1);i++)
    {
       int c=v1[i];
        for(int j=0;j<sz(r[c]);j++)
        {
          int  ri= r[c][j].first;
          int  d= r[c][j].second;
            if(arr[ri]==-oo)
            arr[ri]=arr[c]+d;
            else
            {
                int dist=arr[ri]-arr[c];
                if(dist!=d)
                {
                    fl=1;
                    break;
                }
            }
            if(!vis[ri])
            {
                v1.pb(ri);
                vis[ri]=1;
                st.erase(st.find(ri));
            }
        }
        if(fl)
            break;
        for(int j=0;j<sz(l[c]);j++)
        {
           int lf=l[c][j].first;
           int d= l[c][j].second;
           if(arr[lf]==-oo)
            arr[lf]=arr[c]-d;
            else
            {
                int dist=arr[c]-arr[lf];
                if(dist!=d)
                {
                    fl=1;
                    break;
                }
            }
            if(!vis[lf])
           {
             v1.pb(lf);
             vis[lf]=1;
             st.erase(st.find(lf));
           }
        }
        if(fl)
            break;
    }
    if(fl)
        break;
    v1.pb((*st.begin()));
   }
     if(fl)
            cout<<"No\n";
     else
        cout<<"Yes\n";
}
