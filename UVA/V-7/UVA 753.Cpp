// ICPC Champion is here

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
int v[10009][10009];
int pathlen,id,path[100009],vis[100009];
vector<string> lst,lst2;

map<string,int> mb;

int dfs(int sr,int des,int len,int mi)
{
    //cout<<mi<<endl;
    path[len]=sr;
    if(sr==des)
    {
        pathlen=len+1;
        return mi;
    }
    vis[sr]=1;

    int ret=0;

    for(int i=0;i<=id;i++)
    {
        if(v[sr][i]>0&&!vis[i])
        {  // cout<<"i  "<<i<<endl;
            ret=dfs(i,des,len+1,min(mi,v[sr][i]));

            if(ret>0)
             return ret;
        }
    }
    return ret;
}













int MaxFlow()
{

    int flows=0;
    int T=2;
    while(1)
    {
      clr(vis,0);
      int fl= dfs(0,id,0,100000);
     // cout<<fl<<endl;

      if(!fl)
        break;

      for(int i=1;i<pathlen;i++)
      {
          int fr=path[i-1]; int to=path[i];
         // cout<<fr<<" "<<to<<endl;
         // if(fr==0||to==id)
          //  continue;

          v[fr][to]-=fl;
          v[to][fr]+=fl;
      }
      //cout<<endl;
       flows+=fl;
    }
    return flows;
}
void clearall()
{
    clr(v,0);
    lst.clear();
    lst2.clear();
    mb.clear();
}
int main()
{
    int T,cs=0;
    scanf("%d",&T);

    while(T--)
    {

        clearall();

        if(cs)
            printf("\n");
       int n;
       scanf("%d",&n);
       string st;
       id=1;
       char ch[30];
       for(int i=0;i<n;i++)
       {
           scanf("%s",ch);
           st=ch;
           lst.pb(st);
           if(mb.find(st)==mb.end())
            mb[st]=id++;

       }
       cs=1;
       int m;
       scanf("%d",&m);
       string name,plug;
       for(int i=0;i<m;i++)
       {
           scanf("%s",ch);
           name=ch;
           lst2.pb(name);
           scanf("%s",ch);
           plug=ch;
           mb[name]=id++;
           if(mb.find(plug)==mb.end())
            mb[plug]=id++;
           v[mb[plug]][mb[name]]=1;
       }
       int dev;
       scanf("%d",&dev);
       string out,in;
       char ch1[30],ch2[30];
       for(int i=0;i<dev;i++)
       {
           scanf("%s %s",ch1,ch2);
           out=ch1;
           in=ch2;
           if(mb.find(in)==mb.end())
            mb[in]=id++;
           if(mb.find(out)==mb.end())
            mb[out]=id++;

           v[mb[in]][mb[out]]=INT_MAX;
       }

       for(int i=0;i<sz(lst);i++)
       {
           int num=mb[lst[i]];
          // cout<<lst[i]<<" "<<num<<endl;
           v[0][num]++;
       }
       for(int i=0;i<sz(lst2);i++)
       {
           int num=mb[lst2[i]];
           v[num][id]=1;
       }

      printf("%d\n",m- MaxFlow());
    }
}
