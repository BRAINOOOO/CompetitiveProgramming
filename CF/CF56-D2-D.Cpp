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
string s,t;
int mem[1009][1009];
int inf=INT_MAX/10;
vector<vector<int> > v(28);
int solve(int i,int j)
{

   int &ret=mem[i][j];

   if(ret!=-1)
    return ret;

   if(j==sz(t))
   {
       return sz(s)-i;
   }
    if(i==sz(s))
        return sz(t)-j;

   int fl,p1=inf,p2=inf,p3=inf,p4=inf,id;
  if(s[i]==t[j])
   p1= solve(i+1,j+1);


  p2= 1+solve(i+1,j+1);  // replace
  p3= 1+solve(i,j+1);   // insert

  p4= 1+solve(i+1,j);  // delete


     return ret=min(p1,min(p2,min(p3,p4)));
}

void print(int i,int j,int ex)
{



   if(j==sz(t))
   {
       for(int l=i;l<sz(s);l++)
            cout<<"DELETE "<<i+ex+1<<endl;

            return;
   }
    if(i==sz(s))
    {
        for(int k=j;k<sz(t);k++)
            cout<<"INSERT "<<i+ex+1<<" "<<t[k]<<endl,ex++;
        return ;
    }

   int fl,p1=inf,p2=inf,p3=inf,p4=inf,id;
  if(s[i]==t[j])
   p1= solve(i+1,j+1);


  p2= 1+solve(i+1,j+1);  // replace
  p3= 1+solve(i,j+1);   // insert
  if(!fl)
  p4= 1+solve(i+1,j);  // delete


     if(p2<=p1&&p2<=p3&&p2<=p4)
     {
            cout<<"REPLACE "<<i+ex+1<<" "<<t[j]<<endl;
            return print(i+1,j+1,ex);
     }
     else if(p3<=p1&&p3<=p2&&p3<=p4)
      {
        cout<<"INSERT "<<i+ex+1<<" "<<t[j]<<endl;
        return print(i,j+1,ex+1);
      }
     else if(p4<=p1&&p4<=p2&&p4<=p3)
     {

            cout<<"DELETE "<<i+ex+1<<endl;

          return  print(i+1,j,ex-1);
     }
     else if(p1<=p2&&p1<=p3&&p1<=p4)
       return  print(i+1,j+1,ex);

}







int main()
{

    cin>>s>>t;

    for(int i=0;i<sz(s);i++)
    {
        int no=s[i]-'A';
        v[no].pb(i);
    }




    clr(mem,-1);
    cout<<solve(0,0)<<endl;
    print(0,0,0);
}
