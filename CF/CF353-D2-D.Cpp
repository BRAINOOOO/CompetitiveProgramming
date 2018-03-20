/*
explanation : at the end of the operations the girls must be at first and the boys must be at the last for eg FFFFMMMM
so you can let the problem be like you want to deliver each F to its position F num i must be at the ith position from left
okay now what is the total operations needed for that you may think that by calculating the distance between the current idex of
F and the position it have to be in finally and sum up this would be the solution but this is not true bec they all move together 
so the solution is i have 2 cases
1- when the F move to the left it may stuck with another F so it will take what the F stuck with takes plus one
2- it makes a number of operations with others but it have to make extra operations so here i will calculate the 
extra operations and added to the pervious F operations

if you don't understand just trace more examples and observe.
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
int arr[1000009],pos[1000009];
int main()
{
    string s;
    cin>>s;
    s="X"+s;

    int n=sz(s);
    int cntf=0,cntm=0,mx=0;
    for(int i=1;i<=n;i++)
    {
       if(s[i]=='M')
       {
           cntm++;
           arr[i]=arr[i-1];
           pos[i]=pos[i-1];
       }

       if(s[i]=='F')
       {
           cntf++;
           pos[i]=i;
           if(i==cntf)
            arr[i]=0;
           else if(s[i-1]=='F')
            arr[i]=arr[i-1]+1;
           else if(s[i-1]=='M')
           {

               if(pos[i-1]==0)
                arr[i]=cntm;
               else
               {
                   int wait= arr[i-1]-(pos[i-1]-(cntf-1));
                   int reach=cntm;
               if(reach>wait)
               {
                  int val= ((i-arr[i-1])-cntf)+arr[i-1];
                   arr[i]=val;
               }
               else
               {

                   arr[i]= arr[i-1]+1;
               }

              }

         }

             cntm=0;
           mx=max(mx,arr[i]);
        }
    }
    cout<<mx<<endl;
}
