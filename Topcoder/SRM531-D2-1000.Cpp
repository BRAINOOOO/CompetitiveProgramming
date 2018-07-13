// ICPC champion is here
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
int arr[59][59],par[50],rnk[59],vis[50],cnt;
vector< pair<int,pair<int,int>> > ed,ed2;
void I()
{
    for(int i=0;i<=50;i++)
        par[i]=i,rnk[i]=1;
}
int getpar(int n)
{
    if(par[n]==n)
        return n;
    return par[n]=getpar(par[n]);
}
void lnk(int a,int b)
{
    a=getpar(a);
    b=getpar(b);

    if(a==b)
        return ;

    if(rnk[a]>=rnk[b])
    {
        par[b]=a;
        rnk[a]+=rnk[b];
        rnk[b]=0;
    }
    else
    {
        par[a]=b;
        rnk[b]+=rnk[a];
        rnk[a]=0;
    }

}
void dfs(int no)
{
    vis[no]=1;
    cnt++;
    for(int i=0;i<=50;i++)
    {
        if(vis[i]||arr[no][i]==0)
            continue;
        dfs(i);
    }
}
class 	KingdomReorganization
{
public:

    	int getCost(vector<string> kingdom, vector<string> build, vector<string> destroy)
    	{

    	    I();
    	    int n=sz(kingdom);
    	    for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(kingdom[i][j]=='1')
                    {
                        arr[i][j]=1;
                        lnk(i,j);


                    }
                }
            }
            int co=0;
    	    for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {

                    if(isupper(build[i][j]))
                    co= build[i][j]-'A';
                    else
                        co=26+build[i][j]-'a';

                    ed.pb(mp(co,mp(i,j)));
                }
            }
            for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    if(!arr[i][j])
                     continue;
                    if(isupper(destroy[i][j]))
                    co= destroy[i][j]-'A';
                    else
                        co=26+destroy[i][j]-'a';

                    ed2.pb(mp(co,mp(i,j)));
                }
            }
            sort(all(ed2));
    	    sort(all(ed));
    	    int ans=0,fr=0,to=0,frp=0,top=0;
    	    for(int i=0;i<sz(ed);i++)
            {
                fr=ed[i].second.first;
                to=ed[i].second.second;
                frp=getpar(fr);
                top=getpar(to);

                if(frp==top)
                    continue;

                ans+= ed[i].first;
                arr[fr][to]=1;
                arr[to][fr]=1;
                lnk(frp,top);
            }


    	    for(int i=0;i<sz(ed2);i++)
            {
                fr=ed2[i].second.first;
                to=ed2[i].second.second;

                arr[fr][to]=0;
                arr[to][fr]=0;

                cnt=0;
                clr(vis,0);
                dfs(0);

                if(cnt==n)
                {

                    ans+=ed2[i].first;
                }
                else
                {
                    arr[fr][to]=1;
                    arr[to][fr]=1;

                }
                //cout<<endl;
            }

    	    return ans;
    	}
};
