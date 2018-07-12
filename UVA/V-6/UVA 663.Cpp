// ICPC champion is here
/*
idea : the essensial edge can't connect with out it , get the max cardinality bipartite matching if there is no specific edge
*/


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
const int H=10009;
int n,Xmax[H],Ymax[H],Ymin[H],Xmin[H],X[H],Y[H],out[H];
vector< vector<int> > v;
vector<pair<int,int> > ans;
bool check(int p,int sh)
{

    return (X[p]>=Xmin[sh]&&X[p]<=Xmax[sh])&&(Y[p]>=Ymin[sh]&&Y[p]<=Ymax[sh]);
}
bool canmatch(vector<int> &vis,vector<int> &L,vector<int> &R,int no)
{


    for(int i=0;i<sz(v[no]);i++)
    {
        int nw=v[no][i];

        if(vis[nw])
            continue;

        vis[nw]=1;
        if(L[nw]<0||canmatch(vis,L,R,L[nw]))
        {
            L[nw]=no;
            R[no]=nw;
            return 1;
        }
    }

    return 0;
}




int MCBM()
{

    int flows=0;

    vector<int> vis(1009,0),L(1009,-1),R(1009,-1);


    for(int i=1;i<=n;i++)
    {
        fill(all(vis),0);
        if(canmatch(vis,L,R,i))
            flows++;

    }

    return flows;
}











int main()
{
    int cs=1;
    while(cin>>n)
    {
        if(!n)
            break;
        v.clear();
        v.resize(H);
        ans.clear();
        for(int i=0;i<n;i++)
        {
            cin>>Xmin[i]>>Xmax[i]>>Ymin[i]>>Ymax[i];
        }

        for(int i=0;i<n;i++)
            cin>>X[i]>>Y[i];


        for(int i=0;i<n;i++)
        {

            for(int j=0;j<n;j++)
            {

                if(check(i,j))
                    v[i+1].pb(n+j+1);


            }
        }
//cout<<sz(v[4])<<endl;
       for(int i=1;i<=n;i++)
       {

          for(int j=0;j<sz(v[i]);j++)
          {

              int no= (*(v[i].begin()));

              v[i].erase(v[i].begin());

              int val=MCBM();

              if(val!=n)
              {
                  ans.pb(mp(no-n,i));
              }

              v[i].pb(no);
          }
       }

       sort(all(ans));
       printf("Heap %d\n",cs++);
       if(sz(ans)==0)
       {
           cout<<"none\n";
       }
       else
       {
           for(int i=0;i<sz(ans);i++)
            if(i)
            printf(" (%c,%d)",(char)(ans[i].first-1+'A'),ans[i].second);
           else
            printf("(%c,%d)",(char)(ans[i].first-1+'A'),ans[i].second);

           cout<<endl;
       }

       cout<<endl;
    }
}





