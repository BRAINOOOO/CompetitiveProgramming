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
int inf=100000000;
vector<int> v1;
int pre[52][52],arr[52][52],mem[52][100005];
pair< vector<int> ,int> v[52][52];
vector<int> v3;
void path(int s,int d)
{

    if(s!=d)
    path(s,pre[s][d]);

    v1.pb(d);

}

int solve(int id,int rem)
{

    if(id==sz(v3))
    {
        if(rem!=0)
            return inf;
        return 0;
    }
    if(rem<0)
        return inf;

 int &ret=mem[id][rem];
    if(ret!=-1)
        return ret;


  return ret= min(solve(id+1,rem),2+solve(id,rem-(2*v3[id])));

}






int main()
{
    int t;

    cin>>t;
   int in=0;
    while(t--)
    {
         if(in!=0)
           cout<<endl;
        int n,m;
        cin>>n>>m;
        in=1;
        for(int i=0;i<52;i++)
            for(int j=0;j<52;j++)
             arr[i][j]=inf,pre[i][j]=i;
        for(int i=0;i<52;i++)
            arr[i][i]=0;



        int a,b,c;
        for(int i=0;i<m;i++)
        {

           cin>>a>>b>>c;
           arr[a][b]=min(arr[a][b],c);
           arr[b][a]=arr[a][b];
        }

        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(arr[i][j]> arr[i][k]+arr[k][j])
                    {
                        arr[i][j]=arr[i][k]+arr[k][j];
                        pre[i][j]=pre[k][j];
                    }
                }
            }
        }


        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                v1.clear();
                vector<int> v2;
                path(i,j);
                int sum=0;
                for(int k=1;k<sz(v1);k++)
                {
                    int no=v1[k];
                    int pno=v1[k-1];
                    sum+= arr[pno][no];

                    v2.pb(arr[pno][no]);
                }
                v[i][j]=mp(v2,sum);
            }
        }

        int q;

        cin>>q;

        while(q--)
        {


            cin>>a>>b>>c;

           int s=v[a][b].second;

            if(a==b)
            {
                if(c!=s)
                    cout<<"No\n";
                else
                    cout<<"Yes 0\n";
                continue;
            }

            if(c<s)
            {
                cout<<"No\n";
                continue;
            }

            c-=s;

         v3=v[a][b].first;
         v3.pop_back();
         clr(mem,-1);

        int res= solve(0,c)+sz(v3)+1;

         if(res>100000)
            cout<<"No\n";
         else
            cout<<"Yes "<<res<<endl;
        }
    }
}


