/*
the idea is that if i go through an edge so this the optimal answer till now but if i go through the reversed edge to it so it is like i 
cancel this move .
*/


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
int v[205][205],path[205],vis[205],pathlen,S,T;
string ans;
int dfs(int s,int d,int l,int m)
{
    path[l]=s;
    if(s==d)
    {
        pathlen=l+1;
        return m;
    }
    int ret=0;
    vis[s]=1;
    for(int i=0;i<=T;i++)
    {
        if(vis[i]||v[s][i]<=0)
            continue;


        ret=dfs(i,d,l+1,min(m,v[s][i]));
        if(ret>0)
            return ret;

    }
    return ret;
}
int MaxFlow()
{
    int flows=0;
    while(1)
    {
        clr(vis,0);
        int fl=dfs(S,T,0,INT_MAX);
        if(fl==0)
            break;

        for(int i=1;i<pathlen;i++)
        {
            int fr=path[i-1]; int to=path[i];
            //cout<<fr<<" "<<to<<endl;
            if(fr>=1&&fr<=26&&to>=27&&to<=36)
            {
                ans[to-26-1]=fr-1+'A';
            }
            if(to>=1&&to<=26&&fr>=27&&fr<=36)
            {
                if(ans[fr-26-1]==to-1-'A')
                    ans[fr-26-1]='_';
            }
            v[fr][to]-=fl;
            v[to][fr]+=fl;
        }
      //  cout<<endl;
        flows+=fl;
    }
    return flows;
}

int main()
{
    string line;

        int nxt=1;

        while(nxt)
        {
            nxt=0;
            clr(v,0);
            int cnt=0;
            while(getline(cin,line))
            {
                S=0;
                T=37;
               if(line=="")
                {
                    nxt=1;
                    break;
                }
                stringstream ss(line);
                char app;
                int ap,ocrr;
                ss>>app;
                ap=app-'A'+1;

                ss>>ocrr;
                cnt+=ocrr;
                v[S][ap]=ocrr;
                char ch;
                while(ss>>ch)
                {
                    if(ch>='0'&&ch<='9')
                        v[ap][ch-'0'+27]=1;
                }

            }
            for(int i=27;i<=36;i++)
                v[i][T]=1;



            ans="__________";
           int res= MaxFlow();
           if(res==cnt)
            cout<<ans<<endl;
            else
                cout<<"!\n";

        }
}
