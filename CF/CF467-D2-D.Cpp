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
ll getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
ll setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
map<string,int> mb;
const int MAX=5000009;
int dfsN[MAX],RS[MAX],LEN[MAX],lowlink[MAX],instack[MAX],F=1,com[MAX],CRS[MAX],CLEN[MAX],vis[MAX];
stack<int> st;
vector<vector<int>> v(MAX),comp;
vector<int> v1;

void dfs(int n)
{
     dfsN[n]=lowlink[n]=F++;
     instack[n]=1;
     st.push(n);

     for(int i=0;i<sz(v[n]);i++)
     {
         int no=v[n][i];
         if(dfsN[no]==0)
         {
             dfs(no);
             lowlink[n]=min(lowlink[no],lowlink[n]);
         }
         else if(instack[no])
         {
              lowlink[n]=min(lowlink[no],lowlink[n]) ;
         }
     }

     if(lowlink[n]==dfsN[n])
     {
         int x=-1;
         comp.pb(vector<int>());
         while(x!=n)
         {
             x=st.top(); st.pop();
             comp.back().pb(x);
             com[x]=sz(comp)-1;
             instack[x]=0;
         }
     }
}

void dfs2(int n)
{

    vis[n]=1;


    for(int i=0;i<sz(comp[n]);i++)
    {
        int no=comp[n][i];

        for(int j=0;j<sz(v[no]);j++)
        {



        int n2=v[no][j];

        if(com[n2]==com[no])
            continue;

        if(!vis[com[n2]])
            dfs2(com[n2]);

        if(CRS[com[n2]]<CRS[n])
        {
            CRS[n]=CRS[com[n2]];
            CLEN[n]=CLEN[com[n2]];
        }
        else if(CRS[com[n2]]==CRS[n])
        {
            CLEN[n]=min(CLEN[n],CLEN[com[n2]]);
        }
        }

    }

}











int main()
{
    int n;
    cin>>n;
   string st;
   int id=1;
   for(int i=0;i<n;i++)
   {
       cin>>st;
       int cnt=0;
       for(int j=0;j<sz(st);j++)
       {
          if(st[j]>='a'&&st[j]<='z')
          st[j]-=32;

          if(st[j]=='R')
            cnt++;
       }

       if(mb[st]==0)
        mb[st]=id++;
      v1.pb(mb[st]);
      RS[mb[st]]=cnt;
      LEN[mb[st]]=sz(st);
   }
   int m;
   cin>>m;
  string word,mean;
 for(int i=0;i<m;i++)
 {
     cin>>word>>mean;
     int cnt1=0;
     for(int j=0;j<sz(word);j++)
     {
          if(word[j]>='a'&&word[j]<='z')
          word[j]-=32;

          if(word[j]=='R')
            cnt1++;

     }
     int cnt2=0;
    for(int j=0;j<sz(mean);j++)
    {
          if(mean[j]>='a'&&mean[j]<='z')
          mean[j]-=32;

          if(mean[j]=='R')
            cnt2++;
    }

     if(mb[word]==0)
        mb[word]=id++;
     if(mb[mean]==0)
        mb[mean]=id++;
     RS[mb[word]]=cnt1;
     RS[mb[mean]]=cnt2;
     LEN[mb[mean]]=sz(mean);
     LEN[mb[word]]=sz(word);
     v[mb[word]].pb(mb[mean]);
 }



   for(int i=1;i<id;i++)
   {
       if(dfsN[i]==0)
        dfs(i);
   }


   for(int i=0;i<sz(comp);i++)
   {
       int mir=INT_MAX; int mil=INT_MAX;
       for(int j=0;j<sz(comp[i]);j++)
       {
            int no=comp[i][j];

            if(RS[no]<mir)
            {
                mir=RS[no];
                mil=LEN[no];
            }
            else if(RS[no]==mir)
            {
                mil=min(mil,LEN[no]);
            }

       }
       CRS[i]=mir; CLEN[i]=mil;
   }
   for(int i=0;i<sz(comp);i++)
   {
       if(!vis[i])
        dfs2(i);
   }

    ll ansr=0; ll ansl=0;
   for(int i=0;i<sz(v1);i++)
   {
       int no=v1[i];

       ansr+=CRS[com[no]];
       ansl+=CLEN[com[no]];
   }

  cout<<ansr<<" "<<ansl<<endl;
}



