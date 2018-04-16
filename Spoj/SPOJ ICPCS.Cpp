/*
the idea is to binary search on the lower bound and to binary search on the upper bound 
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
pair< pair<ll,ll>,ll> arr[109][19];
ll t,p;
 
vector< vector<ll> > check(ll EP,vector<pair<pair<ll,ll>,ll> > cnt)
{
 
   for(int i=0;i<t;i++)
   {
      ll penl=0;
       for(int j=0;j<p;j++)
       {
 
 
         ll  WA= arr[i][j].first.second;
         ll  TP= arr[i][j].second;
           penl+= TP+EP*WA;
       }
       cnt[i].first.second=penl;
       cnt[i].second=i;
 
   }
   vector< vector<ll> > rel(109,vector<ll>(109,0));
   for(int i=0;i<sz(cnt);i++)
   {
         ll np1,np2,b1,b2,id1,id2;
       for(int j=0;j<sz(cnt);j++)
       {
 
           np1=cnt[i].first.first;
           b1=cnt[i].first.second;
           id1=cnt[i].second;
 
           np2=cnt[j].first.first;
           b2=cnt[j].first.second;
           id2=cnt[j].second;
 
           if(id1==id2)
            continue;
 
           if((np1>np2)||(np1==np2&&b1<b2))
           {
              rel[id1][id2]=1;
           }
           else if(np1==np2&&b1==b2)
            rel[id1][id2]=3;
           else if((np2>np1)||(np2==np1&&b2<b1))
           {
               rel[id1][id2]=2;
           }
 
 
       }
   }
 
   return rel;
}
 
 
bool comp(vector< vector<ll> > a,vector< vector<ll> > b)
{
 
    return a==b;
}
 
 
 
 
 
 
 
 
 
 
 
 
int main()
{
    while(cin>>t>>p&&p&&t)
    {
 
        string st;
        vector<pair<pair<ll,ll>,ll> > cnt(t,mp(mp(0,0),0));
           clr(arr,0);
 
      for(int k=0;k<t;k++)
      {
        for(int i=0;i<p;i++)
        {
            cin>>st;
            string s="";
            int numsub;
            for(int j=0;j<sz(st);j++)
            {
                if(st[j]=='/')
                {
                    numsub=atoi(s.c_str());
                    s="";
                    continue;
                }
 
                s+=st[j];
            }
            if(s=="-")
                ;
            else
            {
                int val=atoi(s.c_str());
                arr[k][i]=mp(mp(1,numsub-1),val);
 
                cnt[k].first.first+=1;
            }
 
        }
     }
 
  vector< vector<ll> >   standard = check(20,cnt);
    ll lw=1,hg=20;
       ll ans;
       while(lw<=hg)
       {
           ll mid=(lw+hg)/2;
 
           if(comp(check(mid,cnt),standard))
           {
               ans=mid;
               hg=mid-1;
           }
           else
           {
               lw=mid+1;
           }
       }
 
     ll L=ans;
 
       lw=20; hg=100005;
 
       while(lw<=hg)
       {
           ll mid=(lw+hg)/2;
 
           if(comp(check(mid,cnt),standard))
           {
               ans=mid;
               lw=mid+1;
           }
           else
           {
               hg=mid-1;
           }
       }
 
    ll R=ans;
 
 
 
     cout<<L<<" ";
   if(R==100005)
        cout<<"*\n";
    else
        cout<<R<<endl;
    }
}
 
