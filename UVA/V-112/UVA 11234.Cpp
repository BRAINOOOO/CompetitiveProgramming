/*
see  https://blog.csdn.net/shuangde800/article/details/7707123
*/


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
stack<int> st;
string s;
vector< vector<int> > v,lv;
int main()
{
    int T;

    cin>>T;

    while(T--)
    {
       cin>>s;
       lv.clear();
       lv.resize(10009);
       v.clear();
       v.resize(10009);

       int fr,t1,t2;
       for(int i=0;i<sz(s);i++)
       {
           if(isupper(s[i]))
           {


               fr=i;
               t1=st.top();
               st.pop();
               t2=st.top();
                st.pop();
               v[fr].pb(t1);
               v[fr].pb(t2);
               st.push(fr);

           }
           else
            st.push(i);
       }


      int root= sz(s)-1;

       queue<pair<int,int>> q;
       q.push(mp(root,0));
       lv[0].pb(root);

       while(!q.empty())
       {
           int cur=q.front().first;
           int  lvv=q.front().second;
           q.pop();
           for(int i=0;i<sz(v[cur]);i++)
           {
               int nw= v[cur][i];

               q.push(mp(nw,lvv+1));


           }
           if(sz(v[cur])>0)
           {lv[lvv+1].pb(v[cur][0]);
            lv[lvv+1].pb(v[cur][1]);
           }
       }

       for(int i=10000;i>=0;i--)
       {
           for(int j=0;j<sz(lv[i]);j++)
           {
               cout<<s[lv[i][j]];
           }
       }

        cout<<endl;
    }
}






