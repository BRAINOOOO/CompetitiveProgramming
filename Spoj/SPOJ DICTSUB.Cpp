/*
explanation : the idea is greedy we just binary search on the first pos we can obtain the amount of chars we needed 
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
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(ll mask) {int ret=0; while (mask) 	{mask &= (mask-1ll);++ret;	}return ret;}
vector< vector<int> > cnt(10009);
string ch[10009];
vector< vector<int> > arr(27);
int main()
{
    M();

    int t;
    cin>>t;

    while(t--)
    {

       int d; string t;
       cnt.clear();
       cnt.resize(10009);
       for(int i=0;i<10009;i++)
        ch[i].clear();

       cin>>d>>t;
        for(int i=0;i<=26;i++)
        arr[i].clear(),arr[i].resize(sz(t));
       string s;
       for(int i=0;i<d;i++)
       {
           cin>>s;

           stringstream ss(s);
           int no; char chr;
           while(ss>>no>>chr)
           {
               cnt[i].pb(no);
               ch[i]+=chr;
           }

       }

       for(int i=0;i<sz(t);i++)
       {
           for(int j=0;j<26;j++)
           {
               if(t[i]-'A'!=j)
                arr[j][i]= (i==0? 0 : arr[j][i-1]);
               else
                arr[j][i]= (i==0? 0 : arr[j][i-1])+1;
           }
       }
      // for(int i=0;i<sz(t);i++)
      //  cout<<arr[4][i]<<endl;

       for(int i=0;i<d;i++)
       {
           int id=-1; int fl=0;
           for(int j=0;j<sz(cnt[i]);j++)
           {
               int c=cnt[i][j];
               char chr= ch[i][j];

               int val= (id==-1 ? 0 : arr[chr-'A'][id])+c;
               //cout<<chr<<" "<<val<<endl;
               vector<int> :: iterator it;
               it= lower_bound(all(arr[chr-'A']),val);

               if(it==arr[chr-'A'].end())
               {
                   fl=1;
                   break;
               }
               id= distance(arr[chr-'A'].begin(),it);

           }

           if(fl)
            cout<<"NO\n";
           else
            cout<<"YES\n";
       }

       cout<<endl;
    }
}

