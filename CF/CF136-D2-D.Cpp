/*
the idea is the square should have all sides equal and angles equal to 90 degree
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
#define     point                    complex<double>
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
vector< pair<int,int> > v;
int sq[10],vis[10],fl;
vector<int> ans;
int dist(pair<int,int> a,pair<int,int> b)
{
    return ((b.first-a.first)*(b.first-a.first)+(b.second-a.second)*(b.second-a.second));
}
bool ok1(int ul,int ur,int dl,int dr)
{
    if(dist(v[ul],v[ur])==dist(v[dl],v[dr])&&dist(v[ul],v[dl])==dist(v[ur],v[dr])&&dist(v[ul],v[ur])==dist(v[ul],v[dl])&& dist(v[ur],v[dl])==2*dist(v[ul],v[ur]) && dist(v[ur],v[dl])==dist(v[ul],v[dr]))
    {

           return 1;
    }
    return 0;
}
bool ok2(int ul,int ur,int dl,int dr)
{
    if(dist(v[ul],v[ur])==dist(v[dl],v[dr])&&dist(v[ul],v[dl])==dist(v[ur],v[dr])&& dist(v[ur],v[dl])==dist(v[ul],v[ur])+dist(v[ur],v[dr]) && dist(v[ur],v[dl])==dist(v[ul],v[dr]))
    {
           return 1;
    }
    return 0;
}



bool issq(vector<int> v1)
{


     for(int i=0;i<4;i++)
     {
         for(int j=0;j<4;j++)
         {
             for(int k=0;k<4;k++)
             {
                 for(int l=0;l<4;l++)
                 {
                     if(!(i!=j&&i!=k&&i!=l&&j!=k&&j!=l&&k!=l))
                     continue;


                     if(ok1(v1[i],v1[j],v1[k],v1[l]))
                       return 1;
                 }
             }
         }
     }

   return 0;
}

bool isreq(vector<int> v1)
{


     for(int i=0;i<4;i++)
     {
         for(int j=0;j<4;j++)
         {
             for(int k=0;k<4;k++)
             {
                 for(int l=0;l<4;l++)
                 {
                     if(!(i!=j&&i!=k&&i!=l&&j!=k&&j!=l&&k!=l))
                     continue;


                     if(ok2(v1[i],v1[j],v1[k],v1[l]))
                       return 1;
                 }
             }
         }
     }
return 0;
}
bool isokay(vector<int> v1)
{
    vector<int> v2;
    for(int i=0;i<8;i++)
    {
        if(v1[0]!=i&&v1[1]!=i&&v1[2]!=i&&v1[3]!=i)
            v2.pb(i);
    }

    if(issq(v1)&&isreq(v2))
        return 1;
    return 0;
}
















int fun(vector<int > v1)
{
    if(sz(v1)==4)
    {
        if(isokay(v1))
        {
            ans=v1;
            return 1;
        }
        return 0;
    }


    for(int i=0;i<8;i++)
    {
        if(vis[i])
            continue;

        vis[i]=1;
        v1.pb(i);
       if( fun(v1))
        return 1;
        v1.pop_back();
        vis[i]=0;

    }

    return 0;
}

int main()
{
    int x,y;
    for(int i=0;i<8;i++)
    {
        cin>>x>>y;
        v.pb(mp(x,y));
    }


    if(fun(vector<int>()))
    {
        cout<<"YES\n";
        for(int i=0;i<sz(ans);i++)
            sq[ans[i]]=1,cout<<ans[i]+1<<" ";
        cout<<endl;
        for(int i=0;i<8;i++)
            if(!sq[i])
            cout<<i+1<<" ";
        cout<<endl;
    }
    else
        cout<<"NO\n";


}
