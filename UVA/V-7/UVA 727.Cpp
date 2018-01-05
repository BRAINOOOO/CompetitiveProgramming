/*
explanation : here i will use stack as it is an easy data structure in implementing my logic
first input should be ( , ) ,+,-,*,/, digit 
i will make 3 stacks one for digits , operators , brackets .
i will assign each digit and sign to the number of bracket it belongs to it and i will assign each bracket to an index
if it is 
           open bracket ---> just add it to its stack with index = previous bracket idex + 1
           
           closed bracket ----> i will print all the digits plus the operators that only belongs to this bracket Why ? bec the next 
           operations may comes before the pervious ones so i will see when i come to them.
           
           digit -----> just add it to its stack with the index of the bracket it belongs to.
           
           operator ------> all the pervious operators belonging to the same bracket and have a higher periority must be done first after that 
           insert it.
           
 complexity : O(n^2)
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
stack< pair<char,int> > s1,s2,s3;
void fun1(int num,char sig)
{
    string v1="";
    while(!s1.empty())
    {
       char val=s1.top().first;
        s1.pop();
        v1=val+v1;
    }
    for(int i=0;i<sz(v1);i++)
        cout<<v1[i];
    while(!s2.empty())
   {
      int val=s2.top().second;
       if(val==num&&(((s2.top().first=='*'||s2.top().first=='/')&&(sig=='*'||sig=='/'))||(sig=='+'||sig=='-')))
       {
           cout<<s2.top().first;
           s2.pop();
       }
       else
        break;
   }
}
void fun3(int sig)   
{
    char presig;
    int br;
    if(!s2.empty())
   {
    presig= s2.top().first;
    br= s2.top().second;
   }
    if(!(s2.empty())&&(br==s3.top().second))
    {
        fun1(s3.top().second,sig);
    }
     s2.push(mp(sig,s3.top().second));
}
int main()
{
    int t;
    string bl;
    cin>>t;
    cin.ignore();
    getline(cin,bl);
    for(int ts=0;ts<t;ts++)
   {
       if(ts>0)
        cout<<"\n";
        s1=stack<pair<char,int> > ();
        s2=stack<pair<char,int> > ();
        s3=stack<pair<char,int> > ();
        string ch;
        string v="";
       while(getline(cin,ch))
       {
           if(ch=="")
            break;
           v+=(ch[0]);
       }
       if(sz(v)==0)
       {
           cout<<endl;
           continue;
       }
           v='('+v;
           v=v+')';
       for(int i=0;i<sz(v);i++)
       {
           if(isdigit(v[i]))
           {
               s1.push(mp(v[i],s3.top().second));
           }
           else if(v[i]=='(')
           {
               if(s3.empty())
               {
                   s3.push(mp(v[i],0));
               }
               else
               {
                  int ty=s3.top().second+1;
                   s3.push(mp(v[i],ty));
               }
           }
           else if(v[i]==')')
           {
               fun1(s3.top().second,'+');  // '+' just to print all the symbols
               s3.pop();
           }
           else if(v[i]=='*'||v[i]=='/')
           {
               fun3(v[i]);
           }
           else if(v[i]=='+'||v[i]=='-')
           {
               fun3(v[i]);
           }
       }
              cout<<endl;
    }
}
