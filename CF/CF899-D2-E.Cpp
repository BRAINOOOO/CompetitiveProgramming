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
set< pair< pair<int,int> , pair<int,int> > > st;
int arr[200009];
map< int, pair<pair<int,int>,int> > mpstr,mpen;
int main()
{
    M();
    int n;
    cin>>n;

   for(int i=0;i<n;i++)
   {

       cin>>arr[i];
   }
   arr[n]=1000000009;
   int str=0,en;
   for(int i=1;i<=n;i++)
   {
       if(arr[i]!=arr[i-1])
       {
           en=i-1;
           st.insert(mp(mp( -(en-str+1),str),mp( en,arr[i-1])));
           str=i;
       }
   }

   for(auto i=st.begin();i!=st.end();i++)
   {
       int str= (*i).first.second;
       int enn= (*i).second.first;
       int len= -(*i).first.first;
       int kd= (*i).second.second;

       mpstr[str]=mp(mp(enn,len),kd);
       mpen[enn]=mp(mp(str,len),kd);
   }
   int ans=0;
   while( !st.empty())
  {

      ans++;

      int len= -(*st.begin()).first.first;
      int str= (*st.begin()).first.second;
      int en= (*st.begin()).second.first;
      int knd= (*st.begin()).second.second;
      // erase my self

      st.erase(st.begin());
      mpstr.erase(mpstr.find(str));
      mpen.erase(mpen.find(en));
      // Done

      if(str==0&&sz(st)>0)
      {

          int e1= mpstr[en+1].first.first;
          int l=mpstr[en+1].first.second;
          int s1= en+1;
          int kd= mpstr[en+1].second;

          // erase nxt to me

          st.erase(st.find(mp( mp( -l,s1), mp(e1,kd))));
          mpstr.erase( mpstr.find( s1));
          mpen.erase( mpen.find( e1));

         int ns=0;
         int ne=e1;
         int nl=l;
         int nkd=kd;

          st.insert(mp(mp(-nl,ns),mp(ne,nkd)));
          mpstr[0]=mp(mp(ne,nl),nkd);
          mpen[ne]=mp(mp(ns,nl),nkd);

      }
     else if(en==n-1&&sz(st)>0)
      {

          int e1= str-1;
          int s1= mpen[e1].first.first;
          int l= mpen[e1].first.second;
          int kd=mpen[e1].second;

          // erase prev to me

          st.erase(st.find(mp(mp( -l,s1),mp(e1,kd))));
          mpstr.erase(mpstr.find(s1));
          mpen.erase(mpen.find(e1));
         int ns=s1;
         int ne=n-1;
         int nl=l;
         int nkd=kd;
         st.insert(mp( mp(-nl,ns),mp(ne,nkd)));
         mpstr[ns]=mp(mp(ne,nl),nkd);
         mpen[ne]=mp(mp(ns,nl),nkd);
      }

      else if(sz(st)>0)
      {

         int lfe= str-1;
         int lfs=mpen[lfe].first.first;
         int lfkd= mpen[lfe].second;
         int lflen= mpen[lfe].first.second;

         int rgs= en+1;
         int rge= mpstr[rgs].first.first;
         int rgkd= mpstr[rgs].second;
         int rglen= mpstr[rgs].first.second;

         if(rgkd== lfkd)
         {

            // erase left

            st.erase(st.find(mp(mp(-lflen,lfs),mp(lfe,lfkd))));
            mpstr.erase(mpstr.find(lfs));
            mpen.erase(mpen.find(lfe));

            // erase right
            st.erase(st.find(mp(mp(-rglen,rgs),mp(rge,rgkd))));
            mpstr.erase(mpstr.find(rgs));
            mpen.erase(mpen.find(rge));

            int ns= lfs;
            int ne= rge;
            int nl= lflen+rglen;
            int nkd=rgkd;

            st.insert(mp(mp(-nl,ns),mp(ne,nkd)));
            mpstr[ns]=mp(mp(ne,nl),nkd);
            mpen[ne]=mp(mp(ns,nl),nkd);
         }
         else
         {
              st.erase(st.find(mp(mp(-lflen,lfs),mp(lfe,lfkd))));
            mpstr.erase(mpstr.find(lfs));
            mpen.erase(mpen.find(lfe));

            int ns= lfs;
            int ne= en;
            int nl= lflen;
            int nkd=lfkd;

            st.insert(mp(mp(-nl,ns),mp(ne,nkd)));
            mpstr[ns]=mp(mp(ne,nl),nkd);
            mpen[ne]=mp(mp(ns,nl),nkd);

         }

      }
  }

  cout<<ans<<endl;
}



