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
#define     point                    complex<long double>
typedef  long long     ll ;
typedef  unsigned long long ull;
const double eps= (1e-10);
using namespace std;
//int dcmp(long double a,long double b){   return fabsl(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
const int MAX=209;
vector< vector<int> > v(MAX);
int fl,cycle[MAX],vis[MAX];
vector<int> v1;
map<vector<int>,int> mb;
void dfs(int no,int pre)
{
    if(vis[no]==1)
    {
       int C=v1.back(),f=0;
        for(int i=0;i<sz(v1)-1;i++)
        {
            if(v1[i]==C&&!f)
                f=1;
            if(f)
                cycle[v1[i]]++;

        }

        return;
    }


    vis[no]=1;

    for(int i=0;i<sz(v[no]);i++)
    {
        int nw=v[no][i];
        if(nw==pre)
            continue;
        v1.pb(nw);
        dfs(nw,no);
        v1.pop_back();
    }

}

void dfs2(int no)
{
    if(cycle[no]>1)
    {

        fl=1;
        return;
    }
    vis[no]=1;


    for(int i=0;i<sz(v[no]);i++)
    {
        int nw=v[no][i];
        if(vis[nw])
            continue;
        dfs2(nw);
    }
}


class CactusCount
{
public :
    int countCacti(int n,vector<string> vv)
    {
        //cerr<<"in";
        string s="";
        for(int i=0;i<sz(vv);i++)
          s+=vv[i];
         s+=',';
         string st="";
         int fr=0,to=0;
        // cerr<<"in";
        for(int i=0;i<sz(s)&&sz(s)>1;i++)
        {
            if(isdigit(s[i]))
                st+=s[i];
            if(s[i]==' ')
            {
                fr=atoi(st.c_str());

                st="";
            }

            if(s[i]==',')
            {
                to=atoi(st.c_str());

                v[fr].pb(to);

                v[to].pb(fr);
                st="";
            }
        }


       for(int i=1;i<=n;i++)
       {
           v1.clear();
           if(vis[i])
            continue;
           v1.pb(i);
           dfs(i,-1);
           v1.pop_back();

       }

       clr(vis,0);
       int cnt=0;
      // cout<<cycle[6]<<endl;
       for(int i=1;i<=n;i++)
       {
           if(!vis[i])
           {
               fl=0;
               dfs2(i);
               if(!fl)
                cnt++;//,cout<<i<<endl;
           }
       }

   return cnt;
    }
};
