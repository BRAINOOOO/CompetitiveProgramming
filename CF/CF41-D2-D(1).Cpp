/*
explanation : here it is a simple dp state(row,column,sumMod) on the max number of peas divisible by k+1 
with building output.

complexity : O(n*m*(K+1)).
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
int countNumBit1(ll mask) {int ret=0; while (mask) 	{mask &= (mask-1ll);++ret;	}return ret;}
int n,m,k,mem[100+9][100+9][11+9],arr[100+9][100+9],nxtc[100+9][100+9][11+9];
string print[100+9][100+9][11+9];
int fun(int r,int c,int M)
{
     if(c<=0||c>m)
        return -900000;
     if(r==0)
     {
         if(M==0)
            return 0;
         return -900000;
     }
    int &ret=mem[r][c][M];
    if(ret!=-1)
        return ret;
    ret=0;
    int a1=0,a2=0;
   a1= arr[r][c]+fun(r-1,c-1,(M+arr[r][c])%k);
   a2= arr[r][c]+fun(r-1,c+1,(M+arr[r][c])%k);
   if(a1>a2)
   print[r][c][M]="L",nxtc[r][c][M]=c-1;
   else
    print[r][c][M]="R",nxtc[r][c][M]=c+1;

   ret=max(a1,a2);

   return ret;
}
int main()
{
    cin>>n>>m>>k;
    k+=1;
    string st;
    for(int i=0;i<n;i++)
    {
        cin>>st;
        for(int j=0;j<m;j++)
            arr[i+1][j+1]=st[j]-'0';
    }
    int mx=-1;
     clr(mem,-1);
     int str;
     for(int i=1;i<=m;i++)
     {
        int val=fun(n,i,0);
         if(val>mx)
         {
             mx=val;
             str=i;
         }
     }
    if(mx==-1)
    {
        cout<<"-1\n";
        return 0;
    }
    cout<<mx<<endl<<str<<endl;
   int r=n;
   int c=str;
   int M=0;
    int T=n-1;
    for(;T--;)
    {
       cout<< print[r][c][M];
      int tM=(M+arr[r][c])%k;
       c=nxtc[r][c][M];
       r=r-1;
       M=tM;
    }
    cout<<endl;
}
