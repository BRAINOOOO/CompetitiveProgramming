/*
explanation : the idea is consider 4 shirts a,b,c,d   if   a(n)-----b(m)             ------- means express
                                                           |          |
                                                           |          |
                                                           d(l)       |
                                                                      c(h)

                                                  so m of b will be equal to l of d since m of b equal to n of a and n of a equal l of d
     
     here is the  idea now the next subproblem is we need to keep the relations when i add a new node or a new tree we can do so 
     by cross multiplication.
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
int countNumBit1(ll mask) {int ret=0; while (mask) 	{mask &= (mask-1ll);++ret;	}return ret;}
int par[600000],rnk[600000];
map<string,int> mb;
map<int,string> rmb;
int N[10000000+9],M[10000000+9];
string S1[10000000+9],S2[10000000+9];
map<int,int> mb2;
void intil()
{
    for(int i=1;i<=sz(mb);i++)
    {
        par[i]=i;
        rnk[i]=1;
    }
}
int pare(int n)
{
    if(par[n]==n)
        return n;
    return par[n]=pare(par[n]);
}
bool link(int a,int b,int n,int m)
{
  int aa=pare(a);
  int bb=pare(b);
   if(mb2.find(a)==mb2.end()&&mb2.find(b)==mb2.end())
   {
       mb2[a]=n;
       mb2[b]=m;
   }
   else if(mb2.find(a)!=mb2.end()&&mb2.find(b)==mb2.end())
   {
       int g=mb2[a];
       mb2[b]= g*m;
       for(int i=1;i<=sz(mb);i++)
       {
          int p=pare(i);
           if(p==aa)
           {
               mb2[i]*=n;
           }
       }
   }
   else if(mb2.find(a)==mb2.end()&&mb2.find(b)!=mb2.end())
   {
       int g=mb2[b];
       mb2[a]= g*n;
       for(int i=1;i<=sz(mb);i++)
       {
          int p=pare(i);
           if(p==bb)
           {
               mb2[i]*=m;
           }
       }
   }
   else if(mb2.find(a)!=mb2.end()&&mb2.find(b)!=mb2.end())
   {
       int g=mb2[a];
       int w=mb2[b];
        for(int i=1;i<=sz(mb);i++)
       {
          int p=pare(i);
           if(p==bb)
           {
               mb2[i]*=g*m;
           }
       }
        for(int i=1;i<=sz(mb);i++)
       {
          int p=pare(i);
           if(p==aa)
           {
               mb2[i]*=w*n;
           }
       }
   }
   if(aa!=bb)
   {
       if(rnk[bb]>=rnk[aa])
       {
           par[aa]=bb;
           rnk[bb]+=rnk[aa];
       }
       else
       {
           par[bb]=aa;
           rnk[aa]+=rnk[bb];
      }
   }
}
bool check(int a,int b)
{
   int aa=pare(a);
   int bb=pare(b);
   if(aa!=bb)
   {
       return 0;
   }
   return 1;
}
int main()
{
    set<string> st;
    char ch;
    string mrk="",eq,s1,s2;
    int n,m;
    int i=0;
    while(1)
    {
        cin>>ch;
        if(ch=='.')
            break;
        if(ch=='!')
        {
            mrk+=ch;
          cin>>n>>s1>>eq>>m>>s2;
          st.insert(s1);
          st.insert(s2);
          N[i]=n;
          S1[i]=s1;
          M[i]=m;
          S2[i]=s2;
        }
        else
        {
            mrk+=ch;
          cin>>s1>>eq>>s2;
          st.insert(s1);
          st.insert(s2);
          S1[i]=s1;
          S2[i]=s2;
        }
        i++;
    }
   int id=1;
    for(auto i=st.begin();i!=st.end();i++)
    {
        mb[(*i)]=id;
        rmb[id]=(*i);
        id++;
    }
    intil();
    for(int j=0;j<i;j++)
    {
        if(mrk[j]=='!')
        {
            int a=mb[S1[j]];
            int b=mb[S2[j]];
            link(a,b,N[j],M[j]);
        }
        else
        {
            int a=mb[S1[j]];
            int b=mb[S2[j]];
           if(!check(a,b))
            {
                cout<<"? "<<S1[j]<<" = ? "<<S2[j]<<"\n";
            }
            else
            {
                int q=mb2[a];
                int l=mb2[b];
                int gg=__gcd(q,l);
                cout<<q/gg<<" "<<S1[j]<<" = "<<l/gg<<" "<<S2[j]<<"\n";
            }
        }
    }
}
