/*
the idea is to represent every X-axis line as a side of a bipartite graph and Y-axis line the other side and get Max cardinality 
bipartite matching 
*/


// ICPC champion is here
#include <bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<cstring>
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
#define     point                    complex<double>
typedef  long long     ll ;
typedef  unsigned long long ull;
const double eps= (1e-5);
using namespace std;
int dcmp(double a,double b){   return fabs(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
int vis[129];
bool canmatch(vector< vector<int> > &v,vector<int> &L,vector<int> &R,int i)
{


    for(int j=0;j<120;j++)
    {
        if(v[i][j]&&!vis[j])
        {
            vis[j]=1;
            if(L[j]<0||canmatch(v,L,R,L[j]))
            {
                L[j]=i;
                R[i]=j;
                return 1;
            }
        }
    }

    return 0;


}
int BMM(vector<vector<int>> &v)
{

    int nodes=0;
    vector<int>L(129,-1),R(129,-1);
    clr(vis,0);

    for(int i=0;i<120;i++)
    {
        clr(vis,0);

        if(canmatch(v,L,R,i))
         nodes++;

    }

    return nodes;




}
int main()
{
    int n,T;
    cin>>T;
    while(T--)
    {

        cin>>n;
        int x,y;
        vector<vector<int> >  v(129,vector<int>(129,0));
        for(int i=0;i<n;i++)
        {
            cin>>x>>y;

            v[x][y]=1;
        }

     cout<< BMM(v)<<endl;
    }
}



