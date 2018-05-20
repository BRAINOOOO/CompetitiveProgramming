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
#define      PI                      acos(-1)
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
vector<vector<point> > pol;
int n;
double mem[14][(1<<13)],dist[14][14],inf=1e17;
double D(point a,point b)
{
    return fabs(length(vec(a,b)));
}
double fixangle(double A)
{
    return (A>1 ? 1: (A<-1 ? -1: A));
}

double angle0(point a,point O,point c)   // point O is the point from it vector a goes and vector c goes
{
   point v1=vec(O,a); point v2=vec(O,c);
   return acos(fixangle(dp(v1,v2)/length(v1)/length(v2)));
}
double getstdist(point p0,point p1,point p2)
{
   double res= fabs(cp(p1-p0,p2-p0)/length(vec(p1,p0)));
   double ang1,ang2;
    ang1=angle0(p0,p1,p2)*(180.0/PI);
    ang2=angle0(p1,p0,p2)*(180.0/PI);
   if(ang1<=90&&ang1>0&&ang2>0&&ang2<=90)
    return res;


        return min(D(p2,p0),D(p2,p1));//min(D(p0,p2),D(p1,p2));
}
double mindist(int a,int b)
{
    double mi=1e17;
    for(int l=0;l<sz(pol[b]);l++)
    {

       point p=pol[b][l];

    for(int i=0;i<sz(pol[a])-(a==0||a==n+1? 1:0);i++)
    {

        point cur= pol[a][i];
        point nxt= pol[a][(i+1)%sz(pol[a])];
 //cout<<getstdist(cur,nxt,p)<<" "<<cur<<" "<<nxt<<" "<<p<<endl;
       mi= min(mi,getstdist(cur,nxt,p));

    }
    }
    for(int l=0;l<sz(pol[a]);l++)
    {

       point p=pol[a][l];

    for(int i=0;i<sz(pol[b])-(b==0||b==n+1? 1:0);i++)
    {

        point cur= pol[b][i];
        point nxt= pol[b][(i+1)%sz(pol[b])];
      // cout<<getstdist(cur,nxt,p)<<" "<<cur<<" "<<nxt<<" "<<p<<endl;
       mi= min(mi,getstdist(cur,nxt,p));

    }
    }

    return mi;
}

double solve(int no,int msk)
{

    if(no==n+1)
        return 0;
    double &ret=mem[no][msk];
    if(ret==ret)
        return ret;
    ret=1e16;

    for(int i=1;i<=n+1;i++)
    {
        if(getBit(msk,i)==1)
            continue;

        int nmsk=setBit1(msk,i);

        ret=min(ret,dist[no][i]+solve(i,nmsk));

    }
   return ret;
}

























int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        int r1,r2;
        cin>>r1>>r2>>n;
        pol.clear();
        pol.resize(15);
        double x=0.0,y=0.0;
        for(int i=0;i<r1;i++)
        {
            cin>>x>>y;
            pol[0].pb(point(x,y));
        }
        for(int i=0;i<r2;i++)
        {
            cin>>x>>y;
            pol[n+1].pb(point(x,y));
        }
        int no;
       for(int i=1;i<=n;i++)
       {
           cin>>no;
           for(int j=0;j<no;j++)
           {
               cin>>x>>y;
               pol[i].pb(point(x,y));
           }
       }

       for(int i=0;i<=n+1;i++)
       {
           for(int j=i+1;j<=n+1;j++)
           {
             double rs=mindist(i,j);
             dist[i][j]=rs;
             dist[j][i]=rs;
           }
       }


       clr(mem,-1);
       cout<<fixed<<setprecision(3)<<solve(0,0)<<endl;
    }
}









