/*
explanation : here it is a dp state is solve ( the ith tank, sum of tanks visited % k ) the idea is if the v % k==0 so simply 
accumualte all the tanks water in one tank and take v/k from it, it takes v/k operations but the problem is when v%k != 0 so i will 
try to make the reminder through the reminders of the tanks .
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
int n,k,v,r,arr[5009],mem[5009][5009];
vector<int> sol;
int solve(int id,int s)
{

    if(id==n+1)
    {
        if(s==r)
            return mem[id][s]=1;
        return mem[id][s]=0;
    }

    if(mem[id][s]!=-1)
        return mem[id][s];
    int p1=0,p2=0;
    p1= solve(id+1,s);
    p2=solve(id+1,(s+arr[id])%k);

    return mem[id][s]=max(p1,p2);
}
void print(int id,int s)
{

    if(id==n+1)
    {
      return ;
    }

    if(mem[id+1][s]==1)
    {
        print(id+1,s);

    }
   else
   {
       sol.pb(id);
      print(id+1,(s+arr[id])%k);
   }


}



int main()
{

    cin>>n>>k>>v;
    int s=0;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        s+=arr[i];
    }

    if(s<v)
    {
        cout<<"NO"<<endl;
        return 0;
    }
     r=v%k;
    if(r==0)
    {
        cout<<"YES\n";
        for(int i=1;i<=n;i++)
        {
            if(i==2)
                continue;
            cout<<100000<<" "<<i<<" "<<2<<endl;
        }
        if(v/k>0)
        cout<<v/k<<" "<<2<<" "<<1<<endl;
        return 0;
    }

    clr(mem,-1);

    int res=solve(1,0);
    if(res==0)
    {
        cout<<"NO\n";
        return 0;
    }
    print(1,0);
    int tank=sol[0];
    cout<<"YES\n";
    for(int i=1;i<sz(sol);i++)
    {
        cout<<100000<<" "<< sol[i] <<" "<< tank<<endl;
        arr[tank]+=arr[sol[i]];
        arr[sol[i]]=0;
    }
    if(arr[tank]==v)
    {
        return 0;
    }
    if(arr[tank]<v)
    {
        int tank2=1;
        if(tank==1)
            tank2=2;
        for(int i=1;i<=n;i++)
        {
            if((i==tank2||i==tank)||(arr[i]==0))
                continue;
                cout<<1000000<<" "<<i<<" "<<tank2<<endl;
        }
        if((v-arr[tank])/k>0)
        cout<<(v-arr[tank])/k <<" "<<tank2<<" "<<tank<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        if(i==tank)
            continue;
            if((arr[tank]-v)/k>0)
        cout<<(arr[tank]-v)/k<<" "<<tank<<" "<<i<<endl;
        break;
    }
}
