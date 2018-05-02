/*
the idea is to binary search on the point and check the idea of the check function is the point to see the room in must be in its range
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
ll inf=100000000000;
typedef struct p
{
    int x,y;
    p(int x,int y) : x(x),y(y) {}
}pnt;
typedef struct e
{
    pnt a,b;
    int st;
    e(pnt a,pnt b,int st) : a(a),b(b),st(st) {}
}edge;
vector< pnt > v;
vector<edge> ed,r;
int check1(double x)
{



     for(int i=0;i<sz(r);i++)
     {

         pnt l=r[i].a;
         pnt ri=r[i].b;

         if(l.x>ri.x)
            swap(l,ri);
         else if(l.y>ri.y)
            swap(l,ri);

         if((l.y==ri.y&&dcmp(x,l.x)!=-1&&dcmp(x,ri.x)!=1)||(l.x==ri.x))
            continue;

         if(dcmp(x,l.x)==-1)
            return 1;
         if(dcmp(x,ri.x)==1)
            return 2;
     }
     return 0;
}
int check2(double y)
{



     for(int i=0;i<sz(r);i++)
     {

         pnt l=r[i].a;
         pnt ri=r[i].b;

         if(l.x>ri.x)
            swap(l,ri);
         else if(l.y>ri.y)
            swap(l,ri);

         if((l.x==ri.x&&dcmp(y,l.y)!=-1&&dcmp(y,ri.y)!=1)||(l.y==ri.y))
            continue;

         if(dcmp(y,l.y)==-1)
            return 1;
         if(dcmp(y,ri.y)==1)
            return 2;
     }
     return 0;
}

















int main()
{
    int n,cs=1;
    while(cin>>n)
    {
        v.clear();
        ed.clear();
        r.clear();
        if(!n)
            break;
        int x,y;
        for(int i=0;i<n;i++)
        {
            cin>>x>>y;
            v.pb(pnt(x,y));
        }
        int fv,fh;
        if(v[0].x==v[1].x)
            fv=1;
        else if(v[0].y==v[1].y)
            fh=1;

        if(fv)
        {

            for(int i=0;i<=n+1;i++)
            {
                  pnt cur= v[(i)%n]; pnt nxt=v[(i+1)%n];
                  int stat;
                  if(cur.x==nxt.x&&cur.y<nxt.y)
                    stat=0;
                  else if(cur.x==nxt.x&&cur.y>nxt.y)
                    stat=1;
                  else if(cur.y==nxt.y&&cur.x<nxt.x)
                    stat=3;
                  else if(cur.y==nxt.y&&cur.x>nxt.x)
                    stat=2;
                  ed.pb(edge(cur,nxt,stat));

            }
        }
        else
        {
            for(int i=0;i<=n+1;i++)
            {
                  pnt cur= v[(i)%n]; pnt nxt=v[(i+1)%n];
                  int stat;
                  if(cur.x==nxt.x&&cur.y<nxt.y)
                    stat=0;
                  else if(cur.x==nxt.x&&cur.y>nxt.y)
                    stat=1;
                  else if(cur.y==nxt.y&&cur.x<nxt.x)
                    stat=3;
                  else if(cur.y==nxt.y&&cur.x>nxt.x)
                    stat=2;
                  ed.pb(edge(cur,nxt,stat));

            }
        }

        for(int i=0;i<sz(ed)-2;i++)
        {

            int cur=ed[i].st;
            int nxt=ed[i+1].st;
            int nnxt=ed[i+2].st;

            if(cur==3&&nxt==1&&nnxt==2)
                r.pb(ed[i+1]);
            else if(cur==1&&nxt==2&&nnxt==0)
                r.pb(ed[i+1]);
            else if(cur==2&&nxt==0&&nnxt==3)
                r.pb(ed[i+1]);
            else if(cur==0&&nxt==3&&nnxt==1)
                r.pb(ed[i+1]);
        }


        int T=1000;
        double X,Y;
        double l=-100000000; double h=100000000;
        double res=-inf;
        while(T--)
        {

           double mid=(l+h)/2;

           int ans=check1(mid);
           if(ans==0)
           {
               res=mid;
               break;
           }
           else if(ans==1)
           {
               l=mid+1;
           }
           else
           {
               h=mid-1;
           }
        }
        X=res;
        T=1000;
        l=-100000000;  h=100000000; res=-inf;
        while(T--)
        {

           double mid=(l+h)/2;

           int ans=check2(mid);
           if(ans==0)
           {
               res=mid;
               break;
           }
           else if(ans==1)
           {
               l=mid+1;
           }
           else
           {
               h=mid-1;
           }
        }
        Y=res;
        cout<<"Floor #"<<cs++<<endl;
        if(Y==-inf||X==-inf)
            cout<<"Surveillance is impossible.\n\n";
        else
         cout<<"Surveillance is possible.\n\n";
    }

}




