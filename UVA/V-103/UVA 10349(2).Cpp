/*
the state of the dp is the current row , current column , msk on the next row which states what is taken and what is not
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
vector<string> v;
int r,c,mem[50][12][(1<<10)+9];

int solve(int ro,int cl,int msk)
{

    if(ro>=r)
        return 0;



    int &ret=mem[ro][cl][msk];
    if(ret!=-1)
        return ret;

    int p1=1e9,p2=1e9,p3=1e9;

     if(!(getBit(msk,cl)==1||v[ro][cl]!='*'))
     {

    if(ro+1<r&&getBit(msk,cl)==0&&v[ro][cl]=='*')
    {
        int nmsk=setBit1(msk,cl);
        if(cl+1<c)
       p1=1+ solve(ro,cl+1,nmsk);
        else
       p1= 1+solve(ro+1,0,nmsk);

    }
    if(cl+1<c&&getBit(msk,cl)==0&&v[ro][cl]=='*')
    {
        int nmsk=setBit0(msk,cl);
        nmsk=setBit0(nmsk,cl+1);
         if(cl+2<c)
        p2=1+ solve(ro,cl+2,nmsk);
        else
        p2=1+solve(ro+1,0,nmsk);

    }

     if(getBit(msk,cl)==0&&v[ro][cl]=='*')
    {
        int nmsk=setBit0(msk,cl);
         if(cl+1<c)
        p3=1+ solve(ro,cl+1,nmsk);
        else
        p3=1+solve(ro+1,0,nmsk);

    }
     }
   else if(getBit(msk,cl)==1||v[ro][cl]!='*')
    {
        int nmsk=setBit0(msk,cl);
        if(cl+1<c)
        {
           p1=0+ solve(ro,cl+1,nmsk);
        }
        else
        {
            p1=0+solve(ro+1,0,nmsk);
        }

    }


  return ret=min(p1,min(p2,p3));
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>r>>c;
        v.clear();
        string st;
        for(int i=0;i<r;i++)
        {
            cin>>st;
            v.pb(st);
        }
        clr(mem,-1);
        cout<<solve(0,0,0)<<endl;
    }
}

