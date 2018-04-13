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
const int inf=INT_MAX;
const int MAX=2*100000+9;
map< pair<int,int>,  pair<int,int> >par;
int v[MAX],rem[MAX];
multiset< pair<int,int> > s;
int N;

void intial()
{
    for(int i=1;i<=N;i++)
        par[mp(i,0)]=mp(i,0);
}
pair<int,int> getpar(pair<int,int> n)
{
    if(n.second==-1)
        return mp(n.first,-1);
    if(par[n].first==n.first)
        return mp(inf,-1);

    return par[n]=getpar(par[n]);
}
void lnk(int a,int b,int c)
{
    if(c==-1)
        par[mp(b,0)]=mp(a,0);
    else
    {
        par[mp(c,0)]=mp(b,0);
        par[mp(b,0)]=mp(a,0);
    }
}
pair<int,int> upgetpar(pair<int,int> n)
{
    if(n.second==-1)
        return  mp(n.first,0);
    if(par[n].first==n.first)
        return mp(inf,-1);

    return par[n]=getpar(par[n]);
}

int main()
{

    cin>>N;

    int no;
    for(int i=1;i<=N;i++)
    {
        cin>>no; v[i]=no; rem[i]=no;
        multiset< pair<int,int> > :: iterator it2,it3;
        auto it= s.upper_bound(mp(no,-1));
        if(it==s.begin())
        {
            it2=s.insert(mp(no,i));
            it3=it2;
            it3++;
            if(it2!=s.begin())
            {
                it2--;
                lnk((*it2).second,i,(it3==s.end()? -1 : (*it3).second));
            }
        }
        else
        {
            int num= (*s.begin()).second;  par[mp(num,0)]=mp(i,-1);
            if(it!=s.end())
            {
            int val=(*it).second;  par[mp(val,0)]=mp(val,0);

            multiset< pair<int,int> > ts(it,s.end());
            s=ts;
            }
            else
                s=multiset< pair<int,int> > ();
            it2=s.insert(mp(no,i));
            it3=it2;
            it3++;
            if(it2!=s.begin())
            {
                it2--;
                lnk((*it2).second,i,(it3==s.end()? -1 : (*it3).second));
            }
        }
    }
   int q;
    cin>>q;
    while(q--)
    {
        int st,p,x;
        cin>>st>>p;
        if(st==1)
        {
            cin>>x;

            int prev=-1;
            while(x>0&&p!=inf)
            {

               if(rem[p]<=x)
               {
                   x-=rem[p];
                   rem[p]=0;
                   if(prev==-1)
                    prev=p;
                   else
                   {
                       upgetpar(mp(prev,0));
                       prev=p;
                   }
                   p=getpar(mp(p,0)).first;
               }
               else
               {
                 rem[p]-=x,x=0;
                   p=getpar(mp(p,0)).first;
               }
            }
        }
        else
            cout<<v[p]-rem[p]<<endl;
    }
}






