/*
Solution: Since each antenna can only cover the current location and one adjacent cell, 
we can model the graph as a bipartite graph. We can treat each place of interest as a node,
and place an edge between every adjacent places of interest. If the sum of row number and column
number is odd, we can place such node on the left side, and even the right side.

So this problem can be reduced to calculate the Maximum Independent Set of this bipartite graph,
which can be solved by find the Maximum Cardinality Bipartite Matching.
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
vector<string> v1;
vector<int> A,B;
int v[409][409],mb[409][409],vis[409],r,c,L[409],R[409],part[409];
bool canmatch(int n)
{
    for(int i=1;i<=r*c;i++)
    {
        if(vis[i]||v[n][i]==0)
            continue;
        vis[i]=1;
        if(L[i]==-1||canmatch(L[i]))
        {
            L[i]=n; R[n]=i;
            return 1;
        }
    }
    return 0;

}

int Bipart()
{

    int flows=0;
    clr(L,-1);
    clr(R,-1);
    vector<int> V;


    for(int i=0;i<sz(A);i++)
    {

        clr(vis,0);
        if(canmatch(A[i]))
            flows++;
    }

    return flows;
}







int main()
{

    int T;
    cin>>T;
    while(T--)
    {
           clr(v,0);
           v1.clear();
           A.clear();
           B.clear();
          cin>>r>>c;
          string st;
          int id=1;
          for(int i=0;i<r;i++)
          {
              cin>>st;
              v1.pb(st);
              for(int j=0;j<c;j++)
              {
                  mb[i][j]=id++;

              }
          }
          int cnt=0;
          clr(part,-1);
          for(int i=0;i<r;i++)
          {
              for(int j=0;j<c;j++)
              {
                  if(v1[i][j]!='*')
                    continue;
                    cnt++;

                  if(j+1<c&&v1[i][j+1]=='*')
                  {
                      v[mb[i][j]][mb[i][j+1]]=1;
                      v[mb[i][j+1]][mb[i][j]]=1;


                  }
                  if(i+1<r&&v1[i+1][j]=='*')
                  {
                      v[mb[i][j]][mb[i+1][j]]=1;
                      v[mb[i+1][j]][mb[i][j]]=1;

                  }
                  if((j%2==0&&i%2==0)||(j%2!=0&&i%2!=0))
                        A.pb(mb[i][j]);
              }
          }

         cout<<cnt-Bipart()<<endl;

    }
}



