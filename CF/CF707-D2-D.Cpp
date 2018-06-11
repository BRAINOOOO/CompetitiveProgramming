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
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
int Q[100009][3],arr[1009][1009],val[100009],n,m;
vector<vector<int> > v(100009);
int cnt,rw[1009],cntrow[1009],vv[1009][1009];



void dfs(int no)
{


      val[no]=cnt;
     for(int i=0;i<sz(v[no]);i++)
     {
         int nw= v[no][i];
        int f=0;
    int q=nw,st=Q[nw][0],x,y,r;

    if(st==1)
    {
        x=Q[q][1]; y=Q[q][2];

        if(((vv[x][y]+rw[x])&1)==0)
        {
            f=1;
            cnt++;
            vv[x][y]++;
            cntrow[x]++;
        }

    }
    if(st==2)
    {

        x=Q[q][1]; y=Q[q][2];

        if(((vv[x][y]+rw[x])&1)!=0)
        {
            f=1;
            cnt--;
            vv[x][y]++;
            cntrow[x]--;
        }

    }
    if(st==3)
    {
        r=Q[q][1];
        f=1;
        cnt-=cntrow[r];
        cnt+= m-cntrow[r];
        cntrow[r]=m-cntrow[r];
        rw[r]++;

    }


         dfs(nw);

    if(f)
    {

    if(st==1)
    {
        x=Q[q][1]; y=Q[q][2];

            cnt--;
            vv[x][y]--;
            cntrow[x]--;
    }
    if(st==2)
    {

        x=Q[q][1]; y=Q[q][2];

            cnt++;
            vv[x][y]--;
            cntrow[x]++;

    }
    if(st==3)
    {
        r=Q[q][1];

        cnt-=cntrow[r];
        cnt+= m-cntrow[r];
        cntrow[r]=m-cntrow[r];
        rw[r]--;

    }

  }

  }


}

















int main()
{
		std::ios::sync_with_stdio(false);


    int q;
    scanf("%d %d %d",&n,&m,&q);
    int x,y,k,id=0,st;
    for(int i=1;i<=q;i++)
    {

        scanf("%d",&st);
        if(st!=4)
        {
             v[i-1].pb(i);

        }

        if((st==1)||(st==2))
        {
            scanf("%d %d",&x,&y);
            Q[i][0]=st;
            Q[i][1]=x;
            Q[i][2]=y;
        }
        if(st==3)
        {
            scanf("%d",&x);
            Q[i][0]=st;
            Q[i][1]=x;
        }
        if(st==4)
        {
            scanf("%d",&k);
            Q[i][0]=st;
            Q[i][1]=k;

            v[k].pb(i);

        }
    }


     dfs(0);

for(int i=1;i<=q;i++)
{

    printf("%d\n",val[i]);
}
}

