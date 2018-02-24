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
string v;
int fl,arr[27][27],n;
map< char,int> vis;
bool valid(string a,char b)
{
    for(int i=0;i<26;i++)
    {
        if(arr[b-'A'][i]==1&&vis[i+'A'])
            return 0;
    }
    return 1;
}
void bk(string s)
{
    if(sz(s)==sz(v))
    {
        for(int j=0;j<sz(s);j++)
        {
            if(j==sz(s)-1)
                cout<<s[j];
            else
            cout<<s[j]<<" ";
        }
        cout<<endl;
        fl=1;
        return ;
    }
    for(int i=0;i<sz(v);i++)
    {
        if(vis[v[i]])
            continue;
        char ch=v[i];
        if(!valid(s,ch))
            continue;
        vis[v[i]]=1;
        bk(s+v[i]);
        vis[v[i]]=0;
    }
}
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    string blk;
    getline(cin,blk);
    for(int ww=0;ww<t;ww++)
    {
        if(ww>0)
         {
             cout<<endl;
             getline(cin,blk);
         }
        v.clear();
        vis.clear();
        clr(arr,0);
        string l1,l2;
       getline(cin,l1);
       stringstream ss(l1);
       v="";
       char s1;
       while(ss>>s1)
        v+=s1;
       getline(cin,l2);
       stringstream ee(l2);
       string sw;
       while(ee>>sw)
       {
           int a=sw[0]-'A';
           int b=sw[2]-'A';
           arr[a][b]=1;
       }
       fl=0;
       sort(all(v));
       bk("");
      if(!fl)
        cout<<"NO\n";
    }
}
