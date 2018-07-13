#include <bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<map>
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
const double eps= (1e-5);
using namespace std;
int dcmp(double a,double b){   return fabs(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
ll getBit(ll num, int idx) {return ((num >> idx) & 1ll) == 1;}
ll setBit1(ll num, int idx) {return num | (1ll<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
const int H=1000+20+9;
int v[H][H],pathlen,vis[H],path[H],n,cat,arr[28];
vector< set<int> > ans;

void I()
{
    clr(v,0);
    ans.clear();
    ans.resize(H);
}
int dfs(int S,int T,int len,int mi)
{
    path[len]=S;
    vis[S]=1;
    if(S==T)
    {
        pathlen=len;
        return mi;
    }

    for(int i=0;i<H;i++)
    {
        if(vis[i]||v[S][i]<=0)
            continue;

        int f=dfs(i,T,len+1,min(mi,v[S][i]));
        if(f>0)
            return f;
    }

    return 0;



}
int MaxFlow(int S,int T)
{

    int flows=0;

    while(1)
    {
        //cout<<sz(ans[1])<<endl;
        clr(vis,0);
        int pth=dfs(S,T,0,INT_MAX);

        if(pth==0)
            break;
         int fr,to;
        for(int i=1;i<=pathlen;i++)
        {
            fr=path[i-1];
            to=path[i];

            v[fr][to]-=pth;
            v[to][fr]+=pth;

            if((to>n&&to<n+cat+1)&&(fr<=n&&fr>0))
            {

                ans[to].insert(fr);
            }
            else if((fr>n&&fr<n+cat+1)&&(to<=n&&to>0))
            {

                auto it=ans[fr].find(to);
                if(it!=ans[fr].end())
                {
                    ans[fr].erase(it);
                }
            }
        }

        flows+=pth;
    }
    return flows;
}



int main()
{

    while(cin>>cat>>n)
    {
        if(!cat&&!n)
            break;
        I();
        int S=0;
        int T=n+cat+1,s=0,c;
        for(int i=1;i<=cat;i++)
        {
            cin>>c;
            arr[i]=c;
            v[n+i][T]=c;
            s+=c;
        }
        int cnt;
        for(int i=1;i<=n;i++)
        {
            cin>>cnt;
            v[S][i]=1;
            for(int j=0;j<cnt;j++)
            {
                cin>>c;
                v[i][n+c]=1;
            }
        }

        int val=MaxFlow(S,T);

        if(val<s)
            cout<<"0\n";
        else
        {
            cout<<"1\n";

            for(int i=1;i<=cat;i++)
            {
                int f=0;
                int Y=arr[i];
                for(auto j=ans[i+n].begin();j!=ans[i+n].end()&&Y--;j++)
                {
                    if(!f)
                    cout<<(*j),f=1;
                    else
                     cout<<" "<<(*j);

                }
                cout<<endl;
            }
        }
    }
}









