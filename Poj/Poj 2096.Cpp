/*
explanation : here its dp we move from state f(i,j) let i is the count of bugs in the  new categories we
find and j is the bugs in the new subsystems we find.
1- we can find a new bug in a new subsystem but still in an old category fun(i,j+1)
2- we can find a new bug in a old subsystem but still in an new category fun(i+1,j)
3- we can find a new bug in a new subsystem and  in a new category fun(i+1,j+1)
4- we can find a new bug in an old subsystem and in an old category fun(i,j)

okay here is a new problem the last call may go to inf it makes a cycle and as you know 
at dp there must be no cycles so 
the recurrance is f(i,j) = stuff + p4 * (1+fun(i,j));
p4 is the probability of fun(i,j) and +1 bec this count a day
we can put f(i,j) in one side so the recurrance will be fun(i,j)=(stuff+p4)/(1-p4)

know lets move to the probability calculations part :
the probability of finding an old bug is n/N so the probability
of finding a new bug is 1-(n/N).

so here the problem is solvable :)

complexity : O( S*N )
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
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
int setBit0(int num, int idx) {return num & ~(1<<idx);}
int flipBit(int num, int idx) {return num ^ (1<<idx);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
int vis[1000+9][1000+9],S,N;
double mem[1000+9][1000+9];
double  fun(int n,int s)
{
    if(n==N&&s==S)
        return 0.0;
    if(vis[n][s])
        return mem[n][s];
    vis[n][s]=1;
    double p0,p1,p2,p4;
    p0=p1=p2=p4=0.0;
     if(n+1<=N)
   p0+= (1-((n+0.0)/N))*((s+0.0)/S)*(1+fun(n+1,s));
   if(n+1<=N&&s+1<=S)
    p1+= (1-((n+0.0)/N))*(1-((s+0.0)/S))*(1+fun(n+1,s+1));
   if(s+1<=S)
    p2+= (1-((s+0.0)/S))*(((n+0.0)/N))*(1+fun(n,s+1));
    p4+= ((n+0.0)/N)*((s+0.0)/S);
   double ret;
   ret= p0+p1+p2+p4;
    ret/= (1-p4);
    mem[n][s]=ret;
    return ret;
}
int main()
{
    cin>>N>>S;
  cout<<fixed<<setprecision(4);
   cout<< fun(0,0) <<endl;
}
