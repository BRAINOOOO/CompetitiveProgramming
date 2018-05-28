/*
just observe that a contradiction means a cycle
*/

// ICPC Champion is here

#include <bits/stdc++.h>
#include<iostream>
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
int dcmp(long double a,long double b){   return fabsl(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
ll getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
ll setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
map<string,int> mb;
vector<vector<int>> v,comp;
const ll MAX=1000009;
int dfsN[MAX],lowlink[MAX],instack[MAX],F;
stack<int> st;
map<int,string> rmb;
void dfs(int n)
{
    dfsN[n]=lowlink[n]=F++;
    st.push(n);
    instack[n]=1;

    for(int i=0;i<sz(v[n]);i++)
    {
        int no=v[n][i];
        if(dfsN[no]==0)
        {
            dfs(no);
            lowlink[n]=min(lowlink[no],lowlink[n]);
        }
        else if(instack[no]==1)
        {
            lowlink[n]=min(lowlink[no],lowlink[n]);
        }
    }

    if(lowlink[n]==dfsN[n])
    {
        int x=-1;
        comp.pb(vector<int>());
        while(x!=n)
        {
            x=st.top(); st.pop();
            comp.back().pb(x);
            instack[x]=0;
        }
    }

}















void I()
{
    mb.clear();
    v.clear();
    v.resize(MAX);
    comp.clear();
    clr(dfsN,0);
    clr(instack,0);
    clr(lowlink,0);
    F=1;
    rmb.clear();
}
int main()
{
    int in=0,n;
    while(cin>>n)
    {
    	if(n==0)
            break;
      
        I();
        int id=1;
        if(in)
            cout<<endl;
          
        in=1;
        string a,b,c,d,e,ans;
        for(int i=0;i<n;i++)
        {
            cin>>a>>b>>c>>d>>e>>ans;
              if(mb[a]==0)
               rmb[id]=a, mb[a]=id++;

               if(mb[b]==0)
                rmb[id]=b,mb[b]=id++;

                if(mb[c]==0)
                rmb[id]=c,mb[c]=id++;

                if(mb[d]==0)
                rmb[id]=d,mb[d]=id++;
                if(mb[e]==0)
                rmb[id]=e,mb[e]=id++;

            if(mb[a]!=mb[ans])
                v[mb[ans]].pb(mb[a]);
            if(mb[b]!=mb[ans])
                v[mb[ans]].pb(mb[b]);
            if(mb[c]!=mb[ans])
                v[mb[ans]].pb(mb[c]);
            if(mb[d]!=mb[ans])
                v[mb[ans]].pb(mb[d]);
            if(mb[e]!=mb[ans])
                v[mb[ans]].pb(mb[e]);
        }


        for(int i=1;i<id;i++)
         if(dfsN[i]==0)
           dfs(i);
        vector<string> res;
        for(int i=0;i<sz(comp);i++)
        {
        	string s="";
        	for(int j=0;j<sz(comp[i]);j++)
        	s+=rmb[comp[i][j]];
        	
            sort(all(s));
            res.pb(s);
        }
        sort(all(res));
        for(int i=0;i<sz(res);i++)
        {
        	for(int j=0;j<sz(res[i]);j++)
         {
         	cout<<(j==0?"":" ")<<res[i][j];
         }
         cout<<endl;
        }

    }
}


