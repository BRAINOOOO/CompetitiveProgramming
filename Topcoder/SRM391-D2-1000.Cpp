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
int n,m;
const int MAX=409;
vector< vector<int> > comp,v1(MAX);
int instack[MAX],lowlink[MAX],dfsN[MAX],F=1,com[MAX];
stack<int> st;
vector<string> v;
int mem[MAX],W[MAX],WC[MAX];
map< pair<int,int> ,int> mb;

bool valid(int r,int c)
{
    if(r>=0&&r<n&&c>=0&&c<m)
        return 1;
    return 0;
}

void dfs(int no)
{

    dfsN[no]=lowlink[no]=F++;
    instack[no]=1;
    st.push(no);



   for(int i=0;i<sz(v1[no]);i++)
   {
       int nw=v1[no][i];

       if(dfsN[nw]==0)
       {
           dfs(nw);
           lowlink[no]=min(lowlink[no],lowlink[nw]);
       }
       else if(instack[nw])
       {
           lowlink[no]=min(lowlink[no],lowlink[nw]);
       }
   }

   if(lowlink[no]==dfsN[no])
   {
       comp.pb(vector<int>());
       int x=-1;
       while(x!=no)
       {
           x=st.top(); st.pop();
           instack[x]=0;
           comp.back().pb(x);
           com[x]=sz(comp)-1;


       }


   }
}


int solve(int co)
{

    int &ret=mem[co];
    if(ret!=-1)
        return ret;
    ret=0;

    int fl=0;
    for(int i=0;i<sz(comp[co]);i++)
    {
        int node= comp[co][i];

        for(int j=0;j<sz(v1[node]);j++)
        {
            int to= v1[node][j];

            if(com[to]==co)
                continue;
            fl=1;
            ret=max(ret, WC[co]+solve(com[to]));

        }

    }
    if(!fl)
        return ret=WC[co];
    else
    return ret;


}




























class  MarbleCollectionGame
{
public:

    int collectMarble(vector <string> board)
    {
        v=board;
        n=sz(v);
        m=sz(v[0]);
     int id=1;
     for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
         mb[mp(i,j)]=id++;
    int fr=0,to=0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {

             int we=(isdigit(v[i][j]) ? (v[i][j]-'0') : 0);
             W[mb[mp(i,j)]]=we;
            if(valid(i,j+1)&&v[i][j+1]!='#')
           {
            //nr=i;
           // nc=j+1;
            //int we=(isdigit(v[nr][nc]) ? -(v[nr][nc]-'0') : 0);
             fr=mb[mp(i,j)]; to=mb[mp(i,j+1)];
              v1[fr].pb(to);

            }
        if(valid(i+1,j)&&v[i+1][j]!='#')
        {
           // nr=i+1;
           // nc=j;
           // int we=(isdigit(v[nr][nc]) ? -(v[nr][nc]-'0'): 0);
            fr=mb[mp(i,j)]; to=mb[mp(i+1,j)];
              v1[fr].pb(to);

        }
        if(valid(i,j-1)&&v[i][j]=='L'&&v[i][j-1]!='#')
        {
            //nr=i;
            //nc=j-1;
            //int we=(isdigit(v[nr][nc]) ? -(v[nr][nc]-'0') : 0);
            fr=mb[mp(i,j)]; to=mb[mp(i,j-1)];
              v1[fr].pb(to);

        }
        if(valid(i-1,j)&&v[i][j]=='U'&&v[i-1][j]!='#')
        {
            //nr=i-1;
            //nc=j;
           // int we=(isdigit(v[nr][nc]) ? -(v[nr][nc]-'0') : 0);
            fr=mb[mp(i,j)]; to=mb[mp(i-1,j)];
              v1[fr].pb(to);

        }
        }
    }


    for(int i=1;i<id;i++)
        if(dfsN[i]==0)
        dfs(i);
  //  cout<<"in";
    int MYcom=0;
    for(int i=0;i<sz(comp);i++)
    {

        int s=0;
        for(int j=0;j<sz(comp[i]);j++)
        {
            int no=comp[i][j];
            if(no==1)
                MYcom=i;
            s+=W[no];
        }

        WC[i]=s;
    }
    clr(mem,-1);
    return solve(MYcom);
    }
};
