// ICPC Champion is here

//#include <bits/stdc++.h>
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
typedef  long long     ll ;
typedef  unsigned long long ull;
const double eps= (1e-10);
using namespace std;
//int dcmp(long double a,long double b){   return fabsl(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
ll getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
ll setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}

int N,R=100000,tree[4*200009],lazy[4*200009],a[50009],b[50009],dist[50009][3];

void build(int s,int e,int b)
{
    if(s==e)
    {
         tree[b]=0;
         return ;
    }
    int mid=(s+e)>>1;
    build(s,mid,b*2);
    build(mid+1,e,b*2+1);

}
void apply(int s,int mid,int e,int b)
{
    if(lazy[b]==-1)
        return;


    int lf=b*2; int rg=b*2+1;

    lazy[lf]=lazy[b];
    lazy[rg]=lazy[b];
    tree[lf]=lazy[b];
    tree[rg]=lazy[b];

    lazy[b]=-1;
  return;

}
int query(int s,int e,int l,int r,int b)
{

     if(s>r||e<l)
        return 0;

     if(l<=s&&r>=e)
        return tree[b];

     int mid=(s+e)>>1;

      apply(s,mid,e,b);

    return query(s,mid,l,r,b*2)+query(mid+1,e,l,r,b*2+1);

}

void update(int s,int e,int l,int r,int b,int val)
{

    if(s>r||e<l)
        return ;

     if(l<=s&&r>=e)
     {
         tree[b]=val;
         lazy[b]=val;
         return;
     }

     int mid=(s+e)>>1;

      apply(s,mid,e,b);

     update(s,mid,l,r,b*2,val);
     update(mid+1,e,l,r,b*2+1,val);


}






int main()
{
    int S;
    scanf("%d %d",&N,&S);
    S+=R;
    int x1,x2;

    for(int i=1;i<=N;i++)
    {
        scanf("%d %d",&x1,&x2);
        x1+=R; x2+=R;
        a[i]=x1;
        b[i]=x2;

    }

    build(0,200009,1);

    for(int i=1;i<=N;i++)
    {


       int val= query(0,200009,b[i],b[i],1);

        if(val==0)
        {
            dist[i][1]=abs(b[i]-R);
        }
        else
        {
            dist[i][1]=min( dist[val][1]+abs(b[val]-b[i]),dist[val][0]+abs(b[i]-a[val]));
        }

         val= query(0,200009,a[i],a[i],1);

        if(val==0)
        {
            dist[i][0]=abs(a[i]-R);
        }
        else
        {
            dist[i][0]=min( dist[val][1]+abs(b[val]-a[i]),dist[val][0]+abs(a[i]-a[val]));
        }

        update(0,200009,a[i],b[i],1,i);
    }
    int ans= min(dist[N][0]+(S-a[N]),dist[N][1]+(b[N]-S));

    printf("%d\n",ans);
}




