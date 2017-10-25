/*
Here is first think without any topic as it is just adhock problem but on a graph we need for each node
the number of the opened brackets and the closed ones then we dont want to consider balanced sub expressions
and consider the extra opened brackets and closed ones so in the merging step will count all opened brackets 
form the 2 nodes then subtracting the min between opened brackets in the left and the closed brackets on the right 
but why we dont subtrct the closed brackets in the left ??!!  because we dont count the balanced expressions 
and we dont need to query because off course all the queries on all range so simply check node 1 at tree.
*/
#include <bits/stdc++.h>
#define sz(v)   ((int)(v).size())
#define  all(v)    ((v).begin()),((v).end())
#define  allr(v)    ((v).rbegin()),((v).rend())
#define   pb         push_back
#define   mp         make_pair
#define   mt         make_tuple
#define   inf        0x7fffffff
#define    clr(v,d)      memset( v, d ,sizeof(v))
#define    vi       vector<int>
#define    vd       vector<double>
#define    vvi      vector< vector<int> >
#define    vvll      vector< vector<long long> >
#define    vvpi     vector< vector< pair<int,int> > >
#define    vvpll     vector< vector< pair<long long,long long> > >
#define    vvd      vector< vector<double> >
#define    vs       vector<string>
#define    vvs      vector< vector<string> >
#define     vc        vector<char>
#define     vpi        vector< pair<int ,int> >
#define      pi        pair<int ,int>
#define      pll       pair<long long ,long long>
#define     vpd        vector< pair<double ,double> >
#define     vpll        vector< pair<long long ,long long> >
#define    vll       vector<long long>
#define    dqi        deque< int >
#define     si         set<int>
#define     spi        set< pair<int ,int > >
#define     row          vector< ll >
#define     matrix            vector< row >
#define    lp(i,n)    for(i=0;i<n;i++)
#define     si         set<int>
#define    oo         100000000000000000
#define   MOD         1000000007
#define    X            real
#define    Y            imag
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
#define    scani(n)                  scanf("%d",&n)
#define    scanll(n)                  scanf("%I64d",&n)
#define    printi(n)                 printf("%d",n)
#define    printll(n)                 printf("%I64d",n)
#define    scand(n)                  scanf("%lf",&n)
#define    printd(n)                 printf("%lf",n)
#define    scans(n)                  scanf("%s",&n)
#define    prints(n)                 printf("%s",n)
typedef  long long     ll ;
typedef  unsigned long long ull;
const double eps= (1e-10);
const double  PI= acos(-1.0);
using namespace std;
int dcmp(double a,double b){   return fabs(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
int setBit0(int num, int idx) {return num & ~(1<<idx);}
int flipBit(int num, int idx) {return num ^ (1<<idx);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
int N=100000;
pi tree[262143+9];

void update(int place,char num,int s=0,int e=N-1,int p=1)
{
    if(s==e)
     {
         if(num==')')
        tree[p].second=1,tree[p].first=0;
        else
            tree[p].second=0,tree[p].first=1;
        return;
     }

    if(place<=(s+e)/2)
        update(place,num,s,(s+e)/2,p*2);
    else
        update(place,num,(s+e)/2+1,e,2*p+1);


   int dif=min( tree[p*2].first,tree[2*p+1].second);

   tree[p].first= tree[2*p].first+tree[2*p+1].first-dif;
   tree[p].second=tree[2*p].second+tree[2*p+1].second-dif;




   return ;

}





int main()
{

    int n,q;

    for(int t=1;t<=10;t++)
    {

    cin>>n;
    string v;
    cin>>v>>q;
  clr(tree,0);
    cout<<"Test "<<t<<":\n";

    for(int i=0;i<n;i++)
    {
        update(i,v[i]);
    }



   int no;
    for(int i=0;i<q;i++)
    {
        cin>>no;

        if(no==0)
        {

          if(tree[1].first==0&&tree[1].second==0)
            cout<<"YES\n";
          else
            cout<<"NO\n";

        }
        else
        {
            if(v[no-1]==')')
            {
              v[no-1]='(';
            update(no-1,v[no-1]);
            }
            else
           {
               v[no-1]=')';
             update(no-1,v[no-1]);
           }

        }
    }


}
}
