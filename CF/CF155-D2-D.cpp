/*
explanation : here the problem is to know whether there is gcd between the new one and
the lighted ones or not, well we can mark all divisors of each lighted one as if there 
is gcd not equal to one between 2 numbers means there is common divisor so i will get
the divisors of the new one and check whether there is pervious one contain any of them
or not if not can be added else cant be so you will return the one have common divisor 
with it ( anyone as he say ).

complexity : O( squart(N)*N )
*/
#include <bits/stdc++.h>
#define sz(v)   ((int)(v).size())
#define  all(v)    ((v).begin()),((v).end())
#define  allr(v)    ((v).rbegin()),((v).rend())
#define   pb         push_back
#define   mp         make_pair
#define   mt         make_tuple
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
#define     si         set<int>
#define    oo         900000000000000000
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
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
int setBit0(int num, int idx) {return num & ~(1<<idx);}
int flipBit(int num, int idx) {return num ^ (1<<idx);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
map<int ,int > mb;
pi arr[100000+9];
int check(int n)
{
    int i;
    for( i=1;i*i<n;i++)
    {
        if(n%i==0)
        {
            if(arr[i].first>0&&i!=1)
                return arr[i].second;

            if(arr[n/i].first>0&&n/i!=1)
            return arr[n/i].second;
        }
    }
     if(i*i==n&&i!=1)
     {
         if(arr[i].first>0)
                return arr[i].second;
     }

      return -1;
}
void update(int n,int v)
{
    int i;
    for( i=1;i*i<n;i++)
    {
        if(n%i==0)
        {
            arr[i].first+=v;
            arr[i].second=n;
            arr[n/i].first+=v;
            arr[n/i].second=n;
        }
    }
     if(i*i==n)
     {
         arr[i].first+=v;
         arr[i].second=n;
     }
}
int main()
{
    int n,m;
    cin>>n>>m;
    int no;
    char ch;
    for(int i=0;i<m;i++)
    {
        cin>>ch>>no;
        if(ch=='-')
        {
            if(mb[no]==0)
                cout<<"Already off\n";
            else
            {
                update(no,-1);
                mb[no]=0;
                cout<<"Success\n";
            }
        }
        else
        {
            if(mb[no]==1)
                cout<<"Already on\n";
            else
            {
               int val = check(no);
                if(val==-1)
                {
                    update(no,1);
                    mb[no]=1;
                    cout<<"Success\n";
                }
                else
                {
                    cout<<"Conflict with "<<val<<endl;
                }
            }
        }
    }
}
