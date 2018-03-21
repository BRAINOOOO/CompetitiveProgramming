/*
explanation : simply brudeforce but take care the same code with map or/and cin,cout is TLE so by knowing the range used we can use
array instead of map.
*/
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
int dcmp(double a,double b){   return fabs(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
ll getBit(ll num, int idx) {return ((num >> idx) & 1ll) == 1ll;}
ll setBit1(ll num, int idx) {return num | (1ll<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(ll mask) {int ret=0; while (mask) 	{mask &= (mask-1ll);++ret;	}return ret;}
int sh=2500;
const int N=5000+2500+9;
int v[N][N];
queue< pair<int,int> > q;
int main()
{
    //M();
    int n,m;
    scanf("%d %d",&n,&m);

    v[0+sh][0+sh]=n;
    int val;
    q.push(mp(0+sh,0+sh));

    while(!q.empty())
   {
       int cr=q.front().first;
       int cc=q.front().second;
       q.pop();
       if(v[cr][cc]<4)
        continue;
       int val= v[cr][cc]/4;
       v[cr+1][cc]+=val;
       v[cr-1][cc]+=val;
       v[cr][cc+1]+=val;
       v[cr][cc-1]+=val;
       v[cr][cc]%=4;
        q.push(mp(cr+1,cc));
        q.push(mp(cr-1,cc));
        q.push(mp(cr,cc+1));
        q.push(mp(cr,cc-1));
        q.push(mp(cr,cc));
   }
   int x,y;
   while(m--)
   {
         scanf("%d %d",&x,&y);
        printf("%d\n",(x+sh<N&&y+sh<N&&x+sh>=0&&y+sh>=0 ? v[x+sh][y+sh] : 0) );
   }
}
