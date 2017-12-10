/*
explanation : here it is obvious that if there is at least one 1 so it we can convert all the 
to 1 in n-cntof1s steps but if there is no 1 so i will tryall the segments to get 1 and minmize
on the length of segments then just add n to convert all to 1 + the steps to get 1, you will note
that there is no need to do the operation on 2 numbers more than one time .

complexity : O( n^2*log(n) )
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
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
int setBit0(int num, int idx) {return num & ~(1<<idx);}
int flipBit(int num, int idx) {return num ^ (1<<idx);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
int mi,n;
void check(int l,vector<int> v)
{
        for(int i=l;i<n-1;i++)
        {
           int g=__gcd(v[i],v[i+1]);
            if(g==1)
            {
               mi= min(mi,i+1-l-1);
               break;
            }
            v[i+1]=g;
        }
        for(int i=l;i>0;i--)
        {
          int  g=__gcd(v[i],v[i-1]);
            if(g==1)
            {
                mi=min(l-(i-1)-1,mi);
                break;
            }
            v[i-1]=g;
        }
}
int main()
{
    cin>>n;
    int cnt=0,no;
    vector<int> v;
    mi=100000;
    for(int i=0;i<n;i++)
    {
         cin>>no,v.push_back(no);
         if(no==1)
            cnt++;
    }
    for(int l=0;l<n&&cnt==0;l++)
    {
            check(l,v);
    }
   if(cnt>0)
   {
       cout<<n-cnt<<endl;
   }
    else if(mi==100000)
        cout<<-1<<endl;
    else
       cout<< mi+n <<endl;
}
