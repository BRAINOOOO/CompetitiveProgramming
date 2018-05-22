/*
treat the string as a disjoint partions 
*/


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
string v;
ll mem[709][3][3],cross[709];
ll MOD=1e9+7;

ll solve(int id,int bef,int after)
{
    if(id==sz(v)||(v[id]==')'))
        return 1;


    ll &ret= mem[id][bef][after];

    if(ret!=-1)
        return ret;
    ret=0;
    bool no= cross[id]+1<sz(v)&&v[cross[id]+1]==')';
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {

            if((!i&&!j)||(i&&j))
             continue;

             if(i&&i==bef)
                continue;
             if(j&&j==after&&no)
                continue;

            ret= (ret+(( solve(id+1,i,j)%MOD)*(solve(cross[id]+1,j,after)%MOD))%MOD)%MOD;
        }
    }

    return ret;
}

int main()
{

    cin>>v;
    vector<int> v1;

    for(int i=0;i<sz(v);i++)
    {

        if(v[i]==')')
        cross[v1.back()]=i,v1.pop_back();
        else
        v1.pb(i);

    }
    clr(mem,-1);
    cout<<solve(0,0,0)<<endl;
}
/*
((()())(((((()()()())()()())))))

((()())((()())))
*/
