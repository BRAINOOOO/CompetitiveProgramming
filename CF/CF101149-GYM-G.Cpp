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
vector< pair< pair<int,int>,int> > v1,v2;
set<pair<int,int> > st;
int ans[200009];
int main()
{

    int n;
    cin>>n;
    int w,c;
    for(int i=0;i<n;i++)
    {
        cin>>w>>c;
        v1.pb(mp(mp(w,c),i+1));
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>w>>c;
        v2.pb(mp(mp(w,c),i+1));
    }


    sort(allr(v1));
    sort(allr(v2));
    int j=0;
    for(int i=0;i<n;i++)
    {

        while(j<m&&v2[j].first.first>=v1[i].first.first)
        {
            st.insert(mp(v2[j].first.second,v2[j].second));
            j++;
        }



       auto it= st.lower_bound(mp(v1[i].first.second,0));

       if(it==st.end())
       {
           cout<<"-1\n";
           return 0;
       }

        ans[v1[i].second]=(*it).second;

        st.erase(it);




    }

  for(int i=1;i<=n;i++)
    cout<<ans[i]<<" ";
}







