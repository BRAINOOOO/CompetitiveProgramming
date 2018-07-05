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
ll getBit(ll num, int idx) {return ((num >> idx) & 1ll) == 1;}
ll setBit1(ll num, int idx) {return num | (1ll<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
vector< vector<int> > v(100009);
int dfsN[100009],lowlink[100009],instack[100009],F=1,n,comp=0;
stack<int> st;

void dfs(int no)
{

    dfsN[no]=lowlink[no]=F++;
    instack[no]=1;
    st.push(no);

    for(int i=0;i<sz(v[no]);i++)
    {
        int nw=v[no][i];

        if(dfsN[nw]==0)
        {
            dfs(nw);
            lowlink[no]=min(lowlink[no],lowlink[nw]);
        }
        else if(instack[nw]==1)
        {
            lowlink[no]=min(lowlink[no],lowlink[nw]);
        }
    }

    if(lowlink[no]==dfsN[no])
    {

        int x=-1;
        comp++;

        while(x!=no)
        {
            x=st.top();
            st.pop();
            instack[x]=0;

        }
    }
}








void SCC()
{

    for(int i=0;i<n;i++)
    {
        if(dfsN[i]==0)
            dfs(i);
    }


}
int main()
{

    scanf("%d",&n);
    int no;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&no);
            if(no>0)
                v[i].pb(j);
        }
    }


    SCC();
    //cout<<comp<<endl;
    if(comp==1)
        printf("YES\n");
    else
        printf("NO\n");
}


