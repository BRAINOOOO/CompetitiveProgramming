/*
the algorithsm used is toplogical sort 
it can be done iteratively as my code and recursively by sorting the adjlist[i] of the graph.
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
ll getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
ll setBit1(ll num, int idx) {return num | (1ll<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(ll mask) {int ret=0; while (mask) 	{mask &= (mask-1ll);++ret;	}return ret;}
map< string,int> mb;
vector< vector<int> > v(109);
string v1[109];
int in[109],n;
vector<int> topo()
{
    multiset<int> s;
    vector<int> ans;
    for(int i=1;i<=n;i++)
    {
        if(in[i]==0)
            s.insert(i);
    }

    while(!s.empty())
    {
       int no=(*s.begin());
        s.erase(s.begin());
       ans.pb(no);
       for(int i=0;i<sz(v[no]);i++)
       {

           in[v[no][i]]--;

           if(in[v[no][i]]==0)
            s.insert(v[no][i]);


       }
    }

    return ans;



}



int main()
{
    int cs=1;
    while(cin>>n)
    {

        v.clear();
        v.resize(109);
        string st;
        for(int i=1;i<=n;i++)
        {
            cin>>st;
            mb[st]=i;
            v1[i]=st;
        }


        int m;
        cin>>m;
        string b1,b2;
        vector<int> t;
        clr(in,0);
        for(int i=0;i<m;i++)
        {
            cin>>b1>>b2;
            int a=mb[b1];
            int b=mb[b2];

            in[b]++;
            v[a].pb(b);
        }


       vector<int> ans= topo();

         cout<<"Case #"<<cs++<<": Dilbert should drink beverages in this order:";

         for(int i=0;i<n;i++)
         {
             cout<<" "<<v1[ans[i]];
         }
         cout<<"."<<endl<<endl;
    }
}

