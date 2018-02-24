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
map< string,int> vis;
map< string, pair< vector<string> ,ll > > lst;
string arr[1000][18500],col[1000][18500];
void topo(string s)
{

    vis[s]=1;
    vector<string> vv=lst[s].first;
    for(int i=0;i<sz(vv);i++)
    {
        if(vis[vv[i]])
            continue;
        topo(vv[i]);
    }
    if(sz(vv)==0)
     ;
     else
     {
    ll sum=0;
    for(int i=0;i<sz(vv);i++)
    {
       ll val= lst[vv[i]].second;
       sum+=val;
    }
    lst[s].second=sum;
     }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int c,r;
        vis.clear();
        lst.clear();
        cin>>c>>r;
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                cin>>arr[i][j];
            }
        }
        for(int i=1;i<=r;i++)
        {
            string ro=to_string(i);
            string cll="A";
            char   cl='A';
            for(int j=1;j<=c;j++)
            {
                col[i][j]=cll+ro;
                int bk=sz(cll)-1;
                if(cll[bk]=='Z'&&sz(cll)==1)
                {
                    cl='A';
                    cll="AA";
                    continue;
                }
                if(sz(cll)==2&&cll[0]=='Z'&&cll[1]=='Z')
                {
                    cl='A';
                    cll="AAA";
                    continue;
                }
                if(sz(cll)==2&&cll[0]!='Z'&&cll[1]=='Z')
                {
                    cl='A';
                    cll[1]='A';
                    char ch=((cll[0]-'A')+1)+'A';
                    cll[0]=ch;
                    continue;
                }
                if(sz(cll)==3&&cll[0]!='Z'&&cll[1]!='Z'&&cll[2]=='Z')
                {
                    cl='A';
                    cll[2]='A';
                    char ch=((cll[1]-'A')+1)+'A';
                    cll[1]=ch;
                    continue;
                }
                if(sz(cll)==3&&cll[0]!='Z'&&cll[1]=='Z'&&cll[2]=='Z')
                {
                    cl='A';
                    cll[2]='A';
                    cll[1]='A';
                    char ch=((cll[0]-'A')+1)+'A';
                    cll[0]=ch;
                    continue;
                }
                cl=((cl-'A')+1)+'A';
                cll[sz(cll)-1]=cl;
            }
        }
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                if(arr[i][j][0]=='=')
                {
                   vector<string> v;
                   string s="";
                   for(int k=1;k<sz(arr[i][j]);k++)
                   {
                       if(arr[i][j][k]=='+')
                       {
                           v.pb(s);
                           s="";
                       }
                       else
                       {
                           s+=arr[i][j][k];
                       }
                   }
                   v.pb(s);
                   string cd=col[i][j];
                   for(int l=0;l<sz(v);l++)
                   {
                       lst[cd].first.pb(v[l]);
                   }
                }
                else
                {
                    string cd=col[i][j];
                    int num=atoi(arr[i][j].c_str());
                    lst[cd].second=num;
                }
            }
        }
    for(auto i=lst.begin();i!=lst.end();i++)
    {
        if(!vis[(*i).first])
            topo((*i).first);
    }
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                string cd=col[i][j];
                ll res=lst[cd].second;
                if(j==c)
                    cout<<res;
                else
                cout<<res<<" ";
            }
            cout<<endl;
        }
    }
}
