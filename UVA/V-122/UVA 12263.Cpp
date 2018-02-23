/*
explanation : here if the last year order was 1 2 3 4   means 1 depends on 2,3,4 and 2 depends on 3,4 and 3 depends 4 so i will
get the topological sort normally but with the m updates but before i get it i will check for a cycle if there is so it is impossible 
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
int timer,cycle,str[509],en[509],v[509][509],vis[509];
stack<int> st;
void checkforcycle(int n)
{
    str[n]=timer++;
    for(int i=0;i<=500;i++)
    {
        if(v[n][i]==0)
            continue;
        int ch=i;
        if(str[ch]==-1)
            checkforcycle(ch);
        else
        {
            if(en[ch]==-1)
            {
                cycle=1;
            }
        }
    }
     en[n]=timer++;
}
void topo(int n)
{
    vis[n]=1;
    for(int i=0;i<=500;i++)
    {
        if(v[n][i]==0)
            continue;
        if(vis[i])
            continue;

        topo(i);
    }
    st.push(n);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        clr(str,-1);
        clr(en,-1);
        clr(v,0);
        int n;
        cin>>n;
        int no;
        vector<int> v1;
        for(int i=0;i<n;i++)
        {

            cin>>no;
            v1.pb(no);
        }
        for(int i=n-1;i>=0;i--)
        {
            int cur=v1[i];
            for(int j=i+1;j<n;j++)
            {
                v[cur][v1[j]]=1;
            }
        }
        int m;
        cin>>m;
        int a,b,fl=0;
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            swap(v[a][b],v[b][a]);
        }
        for(int i=1;i<=n;i++)
        {
            cycle=0;
            timer=0;
            clr(str,-1);
            clr(en,-1);
            checkforcycle(i);
            if(cycle)
                break;
        }
        if(cycle)
        {
            cout<<"IMPOSSIBLE\n";
            continue;
        }
        clr(vis,0);
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
                topo(i);
        }
        while(!st.empty())
        {
            int cur=st.top();
            st.pop();
            if(st.empty())
                cout<<cur;
            else
            cout<<cur<<" ";
        }
        cout<<endl;
    }
}
