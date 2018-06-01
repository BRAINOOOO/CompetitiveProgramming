// ICPC champion is here
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
vector<vector<int>> v,mb(12);
int sr,sc,Dr,Dc,m,n,vis[1001][1001][4],dist[1001][1001][4];
int mi=INT_MAX;
int dr[]={1,0,-1,0};
int dc[]={0,1,0,-1};

bool valid(int r,int c)
{
    if(r<n&&r>=0&&c<m&&c>=0)
        return 1;
    return 0;
}
int isok(vector<int > &v1,vector<int> &v2,int &FF,int &ro)
{




        int mi=INT_MAX;
        int p1,p2,d1,d2,oth;
        for(int i=0;i<sz(v1);i++)
        {
            p1=(v1[i]+ro);
            if(p1>4)
                p1-=4;

            if(FF==0)
            {    oth=2;
            }
            if(FF==1)
            {
                oth=1;

            }
            if(FF==2)
            {
                oth=0;

            }
            if(FF==3)
            {
                oth=3;

            }

            if(p1<=oth)
                d1=oth-p1;
            else
                d1=oth-p1+4;
            for(int j=0;j<sz(v2);j++)
            {
                p2= (v2[j]+ro);
                if(p2>4)
                    p2-=4;


                if(FF==0)
                {
                    oth=0;
                }
                if(FF==1)
                {
                    oth=3;
                }
                if(FF==2)
                 {
                     oth=2;
                 }
                if(FF==3)
                {
                    oth=1;
                }
                if(p2<=oth)
                d2=oth-p2;
               else
                d2=oth-p2+4;

                if(d1==d2)
                {
                    mi=min(mi,d1);
                }

            }
        }

        if(mi==INT_MAX)
            return -1;
        return mi;
    }




typedef struct NODE
{
    int r,c,w,ro;

    NODE(int r,int c,int w,int ro) : r(r),c(c),w(w),ro(ro) {}

    bool operator <(const NODE &e) const{

       return w>e.w;
    }
}N;

int dij(int sr,int sc,int Dr,int Dc)
{

    for(int i=0;i<1001;i++)
        for(int j=0;j<1001;j++)
         for(int k=0;k<4;k++)
         dist[i][j][k]=INT_MAX;


    dist[sr][sc][0]=0;



    priority_queue<N> pq;
    pq.push(N(sr,sc,0,0));

    while(!pq.empty())
    {

        N cur=pq.top();
        pq.pop();

       if(cur.r==Dr&&cur.c==Dc)
              mi=min(mi,cur.w);

        if(vis[cur.r][cur.c][cur.ro])
            continue;

        vis[cur.r][cur.c][cur.ro]=1;

        int add=cur.w;

        for(int i=0;i<4;i++)
        {
            if(!valid(cur.r+dr[i],cur.c+dc[i]))
                continue;

            int res=isok(mb[v[cur.r][cur.c]],mb[v[cur.r+dr[i]][cur.c+dc[i]]],i,cur.ro);
            if(res==-1)
            continue;
            int ans=(cur.ro+res);
            if(ans>4)
                ans-=4;

            if(dist[cur.r+dr[i]][cur.c+dc[i]][ans]> add+res+1)
            {

                dist[cur.r+dr[i]][cur.c+dc[i]][ans]=add+res+1;
                pq.push(N(cur.r+dr[i],cur.c+dc[i],add+res+1,ans));
            }

        }
    }


}








int main()
{
    M();

    char ch[1001];
    string st;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {

        scanf("%s",ch);
        st=ch;
        vector<int> v1;
        for(int j=0;j<m;j++)
        {
            if(st[j]=='+')
                v1.pb(0);
            if(st[j]=='-')
                v1.pb(1);
            if(st[j]=='^')
                v1.pb(2);
            if(st[j]=='>')
                v1.pb(3);
            if(st[j]=='<')
                v1.pb(4);
            if(st[j]=='L')
                v1.pb(5);
            if(st[j]=='R')
                v1.pb(6);
            if(st[j]=='U')
                v1.pb(7);
            if(st[j]=='D')
                v1.pb(8);
            if(st[j]=='|')
                v1.pb(9);
            if(st[j]=='*')
                v1.pb(10);
            if(st[j]=='v')
                v1.pb(11);


        }
        v.pb(v1);
    }

    scanf("%d %d %d %d",&sr,&sc,&Dr,&Dc);
    sr--; sc--; Dr--; Dc--;


    mb[0].pb(0); mb[0].pb(1); mb[0].pb(2); mb[0].pb(3);
    mb[1].pb(1); mb[1].pb(3);
    mb[9].pb(0); mb[9].pb(2); mb[11].pb(2);
    mb[2].pb(0); mb[3].pb(1); mb[4].pb(3);
    mb[5].pb(0); mb[5].pb(1); mb[5].pb(2);
    mb[6].pb(0); mb[6].pb(2);  mb[6].pb(3);
    mb[7].pb(1); mb[7].pb(2); mb[7].pb(3);
    mb[8].pb(0); mb[8].pb(1); mb[8].pb(3);

    mb[10]=vector<int>();


    int res=dij(sr,sc,Dr,Dc) ;


   if(mi==INT_MAX)
    printf("-1\n");
   else
    printf("%d\n",mi);



}

