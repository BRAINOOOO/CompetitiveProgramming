/*
just simulate
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
#define     point                    complex<double>
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
vector< pair< pair<int,int>,pair<int,int> > > v;
vector< pair<int,pair< pair<int,int>,pair<int,int> > > > v1;
int getkey(int x,int y,int strx,int stry)
{
    int key;
       if(strx==x)
        {
            if(stry>y)
                key=2;
            else
              key=1;
        }
        else if(stry==y)
        {
            if(strx>x)
                key=3;
            else
                key=4;
        }
        return key;
}
int main()
{

    int n;
    cin>>n;
    int x,y;
    cin>>x>>y;
    int x1,y1,x2,y2,stop=-100000;
    for(int i=1;i<=n/2;i++)
    {
        cin>>x1>>y1>>x2>>y2;

        v.pb(mp(mp(x1,y1),mp(x2,y2)));
        stop=max(stop,max(x1,x2));
    }
    for(int i=0;i<sz(v);i++)
    {

        int strx= v[i].first.first;
        int stry= v[i].first.second;
        int enx= v[i].second.first;
        int eny= v[i].second.second;

        int nsx=x;   int nex=strx;
        int nsy=y;   int ney=stry;

        int key1=getkey(x,y,strx,stry);
        int key2=getkey(strx,stry,enx,eny);


        v1.pb(mp(key1,mp(mp(nsx,nsy),mp(nex,ney))));
        v1.pb(mp(key2,mp(mp(strx,stry),mp(enx,eny))));

        x=enx; y=eny;

    }
   int cnt=0;
   for(int i=0;i<sz(v1)-1;i++)
   {

       int cur= v1[i].first;
       int nxt= v1[i+1].first;


       if((cur==3&&nxt==2)||(cur==4&&nxt==1)||(cur==2&&nxt==4)||(cur==1&&nxt==3))
        cnt++;
   }

  cout<<cnt<<endl;
}


