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
vector<vector<int> > e(209);
map<string,int> mb;
vector<pair<int,int> > q;
vector<string> v;
int vis[209];
int BFS(int s,int d)
{
    clr(vis,0);
    queue<pair<int,int> > q;

    q.push(mp(s,0));
    vis[s]=1;
    while(!q.empty())
    {
        int cur=q.front().first;
        int cost=q.front().second;
        q.pop();
        if(cur==d)
        {
            return cost;
        }

        for(int i=0;i<sz(e[cur]);i++)
        {

            if(vis[e[cur][i]])
                continue;

            q.push(mp(e[cur][i],cost+1));
             vis[e[cur][i]]=1;

        }
    }

}





int main()
{
    int T;
    cin>>T;

    for(int t=0;t<T;t++)
    {

        mb.clear();
        v.clear();
        e.clear();
        e.resize(209);
        q.clear();

        if(t>0)
            cout<<endl;
       string st;
       int id=0;
       while(1)
       {
           cin>>st;

           if(st=="*")
            break;

           v.pb(st);
           mb[st]=id++;

       }

       cin.ignore();
       string line;
       while( getline(cin,line))
       {


           if(line=="")
            break;

           stringstream ss(line);
           string s1,s2;
           ss>>s1>>s2;

           q.pb(mp(mb[s1],mb[s2]));
       }

       for(int i=0;i<sz(v);i++)
       {
           for(int j=i+1;j<sz(v);j++)
           {
               

               if(sz(v[i])!=sz(v[j]))
                continue;

               int cnt=0;
               for(int l=0;l<sz(v[i]);l++)
               {
                   if(v[i][l]!=v[j][l])
                    cnt++;
               }

               if(cnt==1)
                e[i].pb(j),e[j].pb(i);


           }
       }

        for(int i=0;i<sz(q);i++)
        {
            int src= q[i].first;
            int des= q[i].second;
            cout<<v[src]<<" "<<v[des]<<" ";
            cout<<BFS(src,des)<<endl;

        }

    }
}
