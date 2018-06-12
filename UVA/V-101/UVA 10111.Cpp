/// using idea dp-masks but with 3 values for each postion insted of 2 (0,for empty),(1,for o),(2,for x)
/// then it's just a normal dp-masks problem.
/* 1  2  3  4
   5  6  7  8
   9  10 11 12
   13 14 15 16
   win index {1,6,11,16} {4,7,10,13}
   horizontal or Vertical
   st {1,2,3,4}  +4
   st {1,5,9,13} +1
*/

// ICPC champion is here
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
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
vector<int> v1;
vector<string> v;
map< pair<int,vector<int> > ,int> mem;
pair<int,int> p;
bool iswin(int r,int c,int t)
{
/*
    if(r==3&&c==0&&t==1)
    {
        for(int i=0;i<16;i++)
            cout<<v1[i]<<" ";
        cout<<endl;
    }
*/
    int fl,id;
    if(t)
    {
        fl=1;
        id=4*r;
        for(int j=0;j<4&&fl;j++,id++)
           if(v1[id]!=2)
                fl=0;
        if(fl)
            return 1;
        fl=1;
        id=c;
        for(int j=0;j<4&&fl;j++,id+=4)
           if(v1[id]!=2)
                fl=0;
        if(fl)
            return 1;

        if(r==c)
        {
            fl=0;
            if(v1[0]==v1[5]&&v1[5]==v1[10]&&v1[10]==v1[15]&&v1[15]==2)
                fl=1;

        }
        if(fl)
            return 1;

        if(r+c==3)
        {
            fl=0;
            if(v1[3]==v1[6]&&v1[6]==v1[9]&&v1[9]==v1[12]&&v1[12]==2)
                fl=1;
        }

         if(fl)
            return 1;
        return 0;
    }
    else
    {
        fl=1;
        id=4*r;
        for(int j=0;j<4&&fl;j++,id++)
           if(v1[id]!=1)
                fl=0;

         if(fl)
            return 1;

        fl=1;
        id=4*r+c;
        for(int j=0;j<4&&fl;j++,id+=4)
           if(v1[id]!=1)
                fl=0;

         if(fl)
            return 1;

        if(r==c)
        {
            fl=0;
            if(v1[0]==v1[5]&&v1[5]==v1[10]&&v1[10]==v1[15]&&v1[15]==1)
                fl=1;

        }

         if(fl)
            return 1;

        if(r+c==3)
        {
            fl=0;
            if(v1[3]==v1[6]&&v1[6]==v1[9]&&v1[9]==v1[12]&&v1[12]==1)
                fl=1;
        }

         if(fl)
            return 1;

        return 0;
    }
}














int solve(int t)
{

    if(mem.find(mp(t,v1))!=mem.end())
        return mem[mp(t,v1)];


     int id=0;
     int fl=0,res,ans;
     for(int i=0;i<4;i++)
     {
         for(int j=0;j<4;j++)
         {

             if(v1[id]!=0)
             {
                 //cout<<"in";
                 id++;
                 continue;
             }
             fl=1;
             if(t)
             {
                 v1[id]=2;
                 res=iswin(i,j,t);
             //    if(i==3&&j==0)
              //   cout<<i<<" "<<j<<" "<<t<<" "<<res<<endl;
                 if(res==1)
                 {
                     p=mp(i,j);
                     v1[id]=0;
                     return mem[mp(t,v1)]=0;
                 }
                 else
               {
                  ans= solve(t^1);
                  v1[id]=0;
                if(ans)
                {
                     p=mp(i,j);
                     return mem[mp(t,v1)]=0;
                }

               }
             }
             else
             {
                 v1[id]=1;
                 res=iswin(i,j,t);
                 if(res==1)
                 {
                      v1[id]=0;
                      return mem[mp(t,v1)]=0;
                 }
                 else
               {
                  ans= solve(t^1);
                  v1[id]=0;

                if(ans)
                    return mem[mp(t,v1)]=0;

               }
             }

             id++;
         }
     }
     if(fl)
     {

         return mem[mp(t,v1)]=1;
     }
    else
    {
        if(t==1)
        {
            return mem[mp(t,v1)]=1;
        }

        return mem[mp(t,v1)]=0;
    }

}









int main()
{
    string qes;
    while(cin>>qes)
    {

      v.clear();
      v1.clear();
      mem.clear();
      if(qes=="$")
        break;
      string st;
      for(int i=0;i<4;i++)
      {
          cin>>st;
          v.pb(st);

          for(int j=0;j<4;j++)
          {
              if(v[i][j]=='.')
                v1.pb(0);
               else if(v[i][j]=='o')
                v1.pb(1);
               else
                v1.pb(2);

          }
      }
    int res=solve(1);

     if(res==1)
     {
         cout<<"#####\n";
     }
     else
     {
         printf("(%d,%d)\n",p.first,p.second);
     }

    }

}








