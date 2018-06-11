// ICPC champion is here
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
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
string s;
int vis[26];
int main()
{
    int k;
    cin>>k>>s;
    int n=sz(s);
    int fl=0;
    for(int i=0;i<(n/2+(n%2!=0))&&!fl;i++)
    {
        int j=n-1-i;
        if(s[i]!='?'&&s[j]!='?'&&s[i]!=s[j])
            fl=1;

        else if(s[i]!='?'&&s[j]=='?')
            s[j]=s[i],vis[s[j]-'a']+=2;
        else if(s[j]!='?'&&s[i]=='?')
            s[i]=s[j],vis[s[i]-'a']+=2;
        else if(s[i]!='?'&&s[j]!='?'&&s[i]==s[j])
            vis[s[i]-'a']+=2;


    }

    for(int i=k-1;i>=0&&!fl;i--)
    {
        if(vis[i])
            continue;
        for(int j=(n/2+(n%2!=0))-1;j>=0;j--)
        {
            int k=n-1-j;
            if(s[j]=='?')
            {
                s[j]=i+'a';
                s[k]=i+'a';
                vis[i]+=2;
                break;
            }
        }
        if(!vis[i])
            fl=1;
    }

        for(int j=0;j<(n/2+(n%2!=0))&&!fl;j++)
        {
            int k=n-1-j;
            if(s[j]=='?')
            {
                s[j]='a';
                s[k]='a';

            }
        }

        if(fl)
        {
            cout<<"IMPOSSIBLE\n";
        }
        else
        {
            cout<<s<<endl;
        }




}



