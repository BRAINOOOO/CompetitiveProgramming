/*
explanation : here the idea is if the input string of length n starts with 'c' so i can count all the permutions of len n-1 starts
with a and b as they are still smaller than c ( take care its permuatation with exceptions as repeated chars may exist ) and when
i reached c if the next char in the input string is b for example so i can make n-2 permutations starting from a then when it comes 
to b i will do the same it is like D&C .
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
ll fact(vector<ll> up,vector<ll> down)
{
    ll ans=1;
     for(int i=0;i<sz(down);i++)
     {
         for(int j=0;j<sz(up);j++)
         {
            ll g=__gcd(down[i],up[j]);
             up[j]/=g;
             down[i]/=g;
         }
     }
     for(int i=0;i<sz(up);i++)
     {
         ans*=up[i];
     }
    return ans;
}
int main()
{
    string st;
    while(cin>>st)
    {
        if(st=="#")
            break;
        set<char> st2;
        for(int i=0;i<sz(st);i++)
            st2.insert(st[i]);
       ll n=sz(st);
        ll vis[27];
        clr(vis,0);
        for(int i=0;i<sz(st);i++)
        {
            vis[st[i]-'a']++;
        }
        vector<ll> up,down;
        for(int i=0;i<26;i++)
        {
            if(!vis[i])
            continue;
            for(int j=2;j<=vis[i];j++)
            {
                down.pb(j);
            }
        }
         for(int i=2;i<=sz(st);i++)
                up.pb(i);
       double f= fact(up,down);
        ll ans=0;
        for(int j=0;j<n;j++)
        {
            int p=-1;
            for(auto i=st2.begin();i!=st2.end();i++)
            {
                int cur=(*i)-'a';
                    if(p!=-1)
                        vis[p]++;
                    vis[cur]--;
                    p=cur;
                if(cur==st[j]-'a')
                {
                    break;
                }
               int len=n-1-j;
              ll  a= (f/(n-j))*(vis[cur]+1);
                ans+=a;
            }
            if(vis[st[j]-'a']==0)
            st2.erase(st2.find(st[j]));
            f/=(n-j);
            f=f*(vis[st[j]-'a']+1);
        }
        printf("%10d\n",ans+1);
    }
}
