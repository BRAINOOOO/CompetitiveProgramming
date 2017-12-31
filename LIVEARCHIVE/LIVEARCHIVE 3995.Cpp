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
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
int setBit0(int num, int idx) {return num & ~(1<<idx);}
int flipBit(int num, int idx) {return num ^ (1<<idx);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
const int MAX=16;
typedef bitset<MAX> mask;
int n,mem[16+9][(1<<16)+9];
vector< vector<int > > v;
int fun(int r,mask msk)
{
    if(r==n)
        return 0;
    int &ret=mem[r][msk.to_ulong()];
    if(ret!=-1)
        return ret;
    ret=0;
   mask  parentmsk= msk;
   msk.flip();
  mask curmsk= msk.to_ulong() & ((1<<n)-1);
   int ans=0;
   for(mask m=curmsk;;m= (m.to_ulong()-1)&(curmsk.to_ulong()))
   {
       int tans=0;
       int ok=1;
       for(int j=0;j<n;j++)
       {
           if( m[j])
           {
               if((j+1<n&&m[j+1])||(j+1<n&&parentmsk[j+1])||(j-1>=0&&parentmsk[j-1]))
               {
                   ok=0;
                   break;
               }
               tans+=v[r][j];
           }
       }
       if(ok)
         ret=max(ret, tans + fun(r+1,m));
       if(m.to_ulong()==0)
        break;
   }
   return ret;
}
int main()
{
    while(!cin.eof())
    {
      string line;
      v.clear();
    while(!cin.eof()&&getline(cin,line)&&line!="")
    {
         stringstream ss(line);
         vector<int> v1;
         int no;
         while(ss>>no)
            v1.pb(no);
            v.pb(v1);
    }
    n=sz(v);
    if(n==0)
       continue;
   clr(mem,-1);
   cout<< fun(0,0) <<endl;
    }
}
