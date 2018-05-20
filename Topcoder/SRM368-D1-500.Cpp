// ICPC Champion is here

#include <bits/stdc++.h>
#include<iostream>
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
#define     point                    complex<long double>
#define      PI                      acos(-1)
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
vector< vector<pair<string,string> > > v1(60);
vector< pair<pair<int,int>,pair<int,int> > > seg;
int par[2600],rnk[2600];
int getpar(int n)
{
    if(par[n]==n)
        return n;
    return par[n]=getpar(par[n]);
}
void intial()
{
    for(int i=0;i<2600;i++)
        par[i]=i,rnk[i]=1;
}

void lnk(int a,int b)
{
    a=getpar(a);
    b=getpar(b);

    if(a!=b)
    {
        if(rnk[a]>rnk[b])
        {
            rnk[a]+=rnk[b];
            rnk[b]=0;
            par[b]=a;
        }
        else
        {
            rnk[b]+=rnk[a];
            rnk[a]=0;
            par[a]=b;
        }
    }
}
















int Cross(pair<int,int> a,pair<int,int> b)
{
    return b.first*a.second-a.first*b.second;
}
pair<int,int> VEC(pair<int,int> a,pair<int,int> b)
{
    return mp(b.first-a.first,b.second-a.second);
}
int normal(pair<int,int> a)
{
    return a.first*a.first+a.second*a.second;
}



int ccw(pair<int,int> a,pair<int,int> b,pair<int,int> c)
{

    pair<int,int> v1=VEC(a,b);
    pair<int,int> v2=VEC(a,c);
    int t= Cross(v1,v2);

    if(t>0)
        return 1;
    if(t<0)
        return -1;

    if(v1.first*v2.first<0||v1.second*v2.second<0)
        return -1;
    if(normal(v1)<normal(v2))
        return 1;
    return 0;
}






bool isintersect(int i,int j)
{

    pair<int,int> p1=seg[i].first;
    pair<int,int> p2=seg[i].second;
    pair<int,int> p3=seg[j].first;
    pair<int,int> p4=seg[j].second;

   bool x=(p1==p2);
   bool y=(p3==p4);

   if(x&&y)
    return p1==p3;

   if(x)
    return ccw(p3,p4,p1)==0;
//cout<<p3.first<<" "<<p3.second<<" "<<p4.first<<" "<<p4.second<<endl;
   if(y)
    return ccw(p1,p2,p3)==0;



 return (ccw(p1,p2,p3)*ccw(p1,p2,p4) <=0 && ccw(p3,p4,p1)*ccw(p3,p4,p2) <=0);
}








class PolylineUnion
{
public:
  int countComponents(vector <string> polylines)
  {

      string v="";
      for(int i=0;i<sz(polylines);i++)
        v+=polylines[i];
      intial();
      int id=0;
      string s="",X,Y;
      v+='-';
      for(int i=0;i<sz(v);i++)
      {

          if(isdigit(v[i]))
            s+=v[i];
          else if(v[i]==',')
          {
              X=s;
              s="";
          }
          else if(v[i]=='-')
          {
              Y=s;
              v1[id].pb(mp(X,Y));
              s="";
          }
          else if(v[i]==' ')
          {
              Y=s;
              v1[id].pb(mp(X,Y));
              s="";
              id++;
          }
      }
      for(int i=0;i<=id;i++)
      {
          if(sz(v1[i])==1)
          {
              v1[i].pb(v1[i].back());

          }
          for(int j=0;j<sz(v1[i])-1;j++)
          {

              int x1=atoi(v1[i][j].first.c_str());
              int y1=atoi(v1[i][j].second.c_str());

              int x2=atoi(v1[i][j+1].first.c_str());
              int y2=atoi(v1[i][j+1].second.c_str());
            //  cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
              seg.pb(mp(mp(x1,y1),mp(x2,y2)));
          }

      }
       for(int i=0;i<sz(seg);i++)
       {

           for(int j=i+1;j<sz(seg);j++)
           {

               if(isintersect(i,j))
                lnk(i,j);
           }
       }
      int cnt=0;
      for(int i=0;i<sz(seg);i++)
        if(rnk[i])
        cnt++;

      return cnt;




  }
};

