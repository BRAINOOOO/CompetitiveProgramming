/*
explanation : the idea is the graph is Acyclic is there must be leaves which has exactly one egde so we can know it and from that we
could build the graph from buttom to up.
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
vector<int > v(100000);
vector< pair<int,int> > ed,v1;
int D[100000],S[100000],vis[100000];
int main()
{
    int n;
    cin>>n;
    int d,s;
    for(int i=0;i<n;i++)
    {
        cin>>d>>s;
        D[i]+=d;
        S[i]=s;
        if(d==1)
        {
            v[i]^=s;
            D[i]--;
            D[s]--;
            v[s]^=i;
            if(i<s)
            ed.pb(mp(i,s));
            else
                ed.pb(mp(s,i));
        }
    }
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        if(D[i]==1)
         q.push(i);
    }
    while(!q.empty())
    {
       int no= q.front();
       q.pop();
       if(D[no]<=0)
        continue;
       int val=S[no];
       int X=v[no];
        int num=0;
        for(int j=0;j<16;j++)
        {
            if(getBit(X,j)==1)
            {
                if(getBit(val,j)==0)
                   num= setBit1(num,j);
                else
                   num= setBit0(num,j);
            }
            else
            {
                if(getBit(val,j)==0)
                   num= setBit0(num,j);
                else
                   num= setBit1(num,j);
            }
        }
        D[no]--;
        D[num]--;
        v[num]^=no;
        v[no]^=num;
        if(no<num)
        ed.pb(mp(no,num));
        else
        ed.pb(mp(num,no));
         if(D[num]==1)
         q.push(num);
    }
    sort(all(ed));
    ed.erase(unique(all(ed)),ed.end());
    cout<<sz(ed)<<endl;
    for(int i=0;i<sz(ed);i++)
        cout<<ed[i].first<<" "<<ed[i].second<<endl;
}
