/*
direct floyed problem
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
ll inf = 1000000000000000;
vector<int> v1;
map< string,int > mb,mbed;
map<int,string> rmb, rmbed;
typedef struct node
{
    ll e,v;
}N;
N arr[160][160];
int pre[160][160];
int id;

void floyed()
{


      for(int k=1;k<=id;k++)
        for(int i=1;i<=id;i++)
         for(int j=1;j<=id;j++)
          if(arr[i][k].v!=inf&&arr[k][j].v!=inf)
         {
             if(arr[i][j].v>arr[i][k].v+arr[k][j].v)
             {
                 pre[i][j]=pre[k][j];
                 arr[i][j].v=arr[i][k].v+arr[k][j].v;
             }

          }


}
void path(int i,int j)
{
    if(i!=j)
    {
        path(i,pre[i][j]);
    }

    v1.pb(j);


}









int main()
{
    string st;

    for(int i=0;i<160;i++)
        for(int j=0;j<160;j++)
         arr[i][j].e=inf,arr[i][j].v=inf,pre[i][j]=i;

     for(int i=0;i<160;i++)
      arr[i][i].v=0;


   id=1;
   int ided=1;
    while(getline(cin,st))
    {
        if(st=="")
            break;
        string s="";
        vector<string> v;

        for(int i=0;i<sz(st);i++)
        {
            if(st[i]==',')
            {
                v.pb(s);
                s="";
                continue;
            }
            s+=st[i];
        }

        v.pb(s);

        string fr=v[0]; string to= v[1]; string ed= v[2]; string cost= v[3];

        if(mb[fr]==0)
            mb[fr]=id++;
        if(mb[to]==0)
            mb[to]=id++;
        if(mbed[ed]==0)
            mbed[ed]=ided++;

        int a=mb[fr];  int b=mb[to]; int c=atoi(cost.c_str()); int edn= mbed[ed];
        rmb[a]=fr;  rmb[b]=to;  rmbed[edn]=ed;

        if(c<arr[a][b].v)
        {

        arr[a][b].v=c;  arr[a][b].e=edn;
        arr[b][a].v=c;   arr[b][a].e=edn;
        }

    }


    floyed();



    while(getline(cin,st))
    {
        string s="";

        vector<string> v;
        for(int i=0;i<sz(st);i++)
        {
            if(st[i]==',')
            {
                v.pb(s);
                s="";
                continue;
            }
            s+=st[i];
        }
        v.pb(s);
       string fr=v[0];
       string to=v[1];
       int a=mb[fr];
       int b=mb[to];
       cout << endl << endl; // two blank lines before each report

    cout << "From                 To                   Route      Miles" << endl;

    cout << "-------------------- -------------------- ---------- -----" << endl;
        v1.clear();
        path(a,b);


        for(int i=0;i<sz(v1)-1;i++)
        {

            int val1=v1[i];
            int val2=v1[i+1];
            string a=rmb[val1];
            string b=rmb[val2];

            printf("%-20s %-20s %-10s %5d\n",a.c_str(),b.c_str(),rmbed[arr[val1][val2].e].c_str(),arr[val1][val2].v);

        }

        cout << "                                                     -----" << endl;
        printf("                                          Total      %5d\n",arr[a][b].v);



    }
}
