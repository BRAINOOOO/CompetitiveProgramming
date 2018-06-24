/*
the idea is that treat with the boxes as a linked list
*/
// ICPC champion is here
#include <bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<cstring>
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
#define     point                    complex<double>
typedef  long long     ll ;
typedef  unsigned long long ull;
const double eps= (1e-5);
using namespace std;
int dcmp(double a,double b){   return fabs(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
int n,m,pre[100009],nxt[100009];
int main()
{
    int cs=1;
    while(cin>>n>>m)
    {
       clr(nxt,-1);
       clr(pre,-1);


        for(int i=1;i<n;i++)
        {

             pre[i+1]=i;
             nxt[i]=i+1;
        }
        int flip=0,state;
        while(m--)
        {
            //cout<<flip<<endl;
            cin>>state;
            state--;

            if(flip&&(state==0||state==1))
                state^=1;
            int x,y;


            if(state==0)
            {

                cin>>x>>y;
                if(pre[y]!=x)
                {


                if(pre[x]!=-1)
                nxt[pre[x]]=nxt[x];
                if(nxt[x]!=-1)
                pre[nxt[x]]=pre[x];


                if(pre[y]!=-1)
                nxt[pre[y]]=x;

                nxt[x]=y;
                pre[x]=pre[y];
                pre[y]=x;
                }


            }
            else if(state==1)
            {


                cin>>x>>y;
                if( nxt[y]!=x)
                {

                int t1=nxt[y];

                if(pre[x]!=-1)
                nxt[pre[x]]=nxt[x];
                if(nxt[x]!=-1)
                pre[nxt[x]]=pre[x];

                nxt[y]=x;
                if(t1!=-1)
                pre[t1]=x;


                pre[x]=y;
                nxt[x]=t1;
                }

            }
            else if(state==2)
            {
                cin>>x>>y;

                if(nxt[x]==y)
                {
                    int t1=nxt[x];
                    int t2=pre[x];
                    int t3=pre[y];
                    int t4= nxt[y];

                    if(t2!=-1)
                    nxt[t2]=y;
                    if(t4!=-1)
                    pre[t4]=x;
                    pre[y]=t2;
                    nxt[y]=x;
                    pre[x]=y;
                    nxt[x]=t4;

                    continue;

                }

                if(nxt[y]==x)
                {

                    int t1=nxt[x];
                    int t2=pre[x];
                    int t3=pre[y];
                    int t4= nxt[y];

                     if(t3!=-1)
                    nxt[t3]=x;
                    if(t1!=-1)
                    pre[t1]=y;

                    pre[x]=t3;
                    nxt[x]=y;
                    pre[y]=x;
                    nxt[y]=t1;

                    continue;
                }

                int t1=nxt[x];
                int t2=pre[x];
                int t3=pre[y];
                int t4= nxt[y];

                nxt[x]=nxt[y];
                pre[x]=pre[y];

                nxt[y]=t1;
                pre[y]=t2;
                if(t3!=-1)
                nxt[t3]=x;
                if(t4!=-1)
                pre[t4]=x;
                if(t2!=-1)
                nxt[t2]=y;
                if(t1!=-1)
                pre[t1]=y;

            }
            else
                flip^=1;


        }
    int st=0;
      for(int i=1;i<=n&&!st;i++)
      {
          if(flip&&nxt[i]==-1)
            st=i;
          if(!flip&&pre[i]==-1)
            st=i;
      }

       ll id=1,cnt=0;
       while(id<=n)
       {
         cout<<st<<endl;
           if(id&1)
           cnt+=st;

           id++;
           if(!flip)
           st=nxt[st];
           else
           st=pre[st];
       }

       cout<<"Case "<<cs++<<": "<<cnt<<endl;


    }
}







