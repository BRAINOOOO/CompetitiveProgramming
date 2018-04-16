/*
the idea is that i have two cases the first is to close the current bracket with a bracket already exist the second case is to
close it with extra braket .
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
int dcmp(long double a,long double b){   return fabsl(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
ll getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
ll setBit1(ll num, int idx) {return num | (1ll<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(ll mask) {int ret=0; while (mask) 	{mask &= (mask-1ll);++ret;	}return ret;}
string s;
int mem[109][109];
map<int,int> v1;
int solve(int st,int en)
{
    int &ret=mem[st][en];

    if(ret!=-1)
        return ret;

    if(en<st)
        return ret=0;
    int ans=200;

        for(int i=st+1;i<=en;i++)
        {
            if((s[i]==')'&&s[st]=='(')||(s[i]==']'&&s[st]=='['))
            {
                ans=min(ans,solve(st+1,i-1)+solve(i+1,en));
            }
        }


    ans=min(ans,1+solve(st+1,en));

    return ret=ans;
}

void toprint(int st,int en)
{

       if(en<st)
       return ;


        for(int i=st+1;i<=en;i++)
        {
            if((s[i]==')'&&s[st]=='(')||(s[i]==']'&&s[st]=='['))
            {
                if(solve(st+1,i-1)+solve(i+1,en)==mem[st][en])
                {
                    toprint(st+1,i-1);
                    toprint(i+1,en);
                    return;
                }
            }
        }


    if(1+solve(st+1,en)==mem[st][en])
    {
        v1[st]=1;
        toprint(st+1,en);

        return ;
    }


}












int main()
{
   int t,in=0;
    cin>>t;
    cin.ignore();
    string blk;
    while(t--)
    {
        if(in==1)
            cout<<endl;
        getline(cin,blk);
        getline(cin,s);
        if(s=="")
        {
            cout<<""<<endl;
            continue;
        }
        clr(mem,-1);
        v1.clear();
        solve(0,sz(s)-1);

        toprint(0,sz(s)-1);
        in=1;
       for(int i=0;i<sz(s);i++)
       {
           if((s[i]==')'||s[i]==']')&&v1[i]==1)
           {
               cout<<(s[i]==')'? '(':'[');
           }
           cout<<s[i];
           if((s[i]=='('||s[i]=='[')&&v1[i]==1)
           {
               cout<<(s[i]=='('? ')':']');
           }
       }
       cout<<endl;

    }
}


