/*
explanation : the problem is strightforward i will construct the string s based on m given subsequences then using KMP to check whether
it is right or not if its right so every place i don't need to fill can be any of 26 chars.

complexity : O(n+m+n+sz(p))
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
vector<int> v(1000009);
const ll MOD=1000000007;
int M[1000009];
vector<int> compF(string pat)
{
    int m=sz(pat);
    vector<int> F(m);
    for(int i=1,k=0;i<m;i++)
    {
        while(k>0&&pat[i]!=pat[k])
            k=F[k-1];
        if(pat[i]==pat[k])
            F[i]=++k;
        else
            F[i]=k;
    }
    return F;

}
void KMP(string str,string pat)
{
    vector<int> F=compF(pat);
    int n=sz(str);
    int m=sz(pat);

    for(int i=0,k=0;i<n;i++)
    {
        while(k>0&&str[i]!=pat[k])
            k=F[k-1];
        if(str[i]==pat[k])
            k++;
        if(k==m)
        {
            v[i-m+1]=1;
            k=F[k-1];
        }
    }
}
int main()
{
    int n,m;
    string p;
    cin>>n>>m>>p;
    for(int i=0;i<m;i++)
    {
        cin>>M[i];
        M[i]--;
    }
    string s="";
    for(int i=0;i<n;i++)
        s+='@';
    int en=-1,str;
    for(int i=0;i<m;i++)
    {
        int st=M[i];
        int myen=st+sz(p)-1;
        if(en<st)
            str=0,en=st-1;
        else if(myen<=en)
        {
            continue;
        }
        else
        {
            str=(en-st+1);
        }
        for(int i=en+1,j=str;j<sz(p);i++,j++)
        {
            s[i]=p[j];
            en++;
        }
    }
    KMP(s,p);
   for(int i=0;i<m;i++)
   {
       if(v[M[i]]==0)
       {
           cout<<"0\n";
           return 0;
       }
   }
   int cnt=0;
   for(int i=0;i<n;i++)
   {
       if(s[i]=='@')
        cnt++;
   }
   ll ans=1;
   for(int i=0;i<cnt;i++)
   {
       ans= (ans*26)%MOD;
   }
   cout<<ans<<endl;
}
