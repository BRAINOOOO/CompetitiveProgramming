/*
explanation : here the idea is i will traverse till the end of the prefix then i will return the node i reached
from it i will just print all the words but take care if the word is the prefix doesn't considered and its 
sorted since i search for the chars from smaller to bigger from left to right.

complexity : O( N*L ) L --- > length of string / N----> count of strings.
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
struct trie
{
    trie* child[27];
    int isleaf;
    trie()
    {
        clr(child,0);
        isleaf=0;
    }
    void insertt(char* str)
    {
        if(*str=='\0')
            isleaf=1;
        else
        {
            int cur=*str-'a';
            if(child[cur]==0)
                child[cur]=new trie();
            child[cur]->insertt(str+1);
        }
    }
    pair< bool,trie* > prefix(char* str)
    {
            int cur=*str-'a';
            if(child[cur]==0)
                return mp(false,child[cur]);
 
            if(*(str+1)!='\0')
             return child[cur]->prefix(str+1);
           else
           {
               return mp(true,child[cur]);
           }
    }
    void print(string ans,string t)
    {
           char cc[30];
           if(isleaf&&ans!="")
           {
               strcpy(cc,(t+ans).c_str());
               printf("%s\n",cc);
           }
           for(int i=0;i<26;i++)
           {
               if(child[i]!=0)
                child[i]->print(ans+(char)(97+i),t);
           }
    }
};
int main()
{
   int n;
    scanf("%d",&n);
    char st[29];
    trie root ;
    for(int i=0;i<n;i++)
    {
        scanf("%s",&st);
        root.insertt(st);
    }
  int p;
   scanf("%d",&p);
   for(int i=1;i<=p;i++)
   {
       scanf("%s",&st);
       string st1=st;
       printf("Case #%d:\n",i);
       pair<bool,trie*> ans=root.prefix(st);
       if(!ans.first)
       {
           printf("No match.\n");
       }
       else
       {
           (*ans.second).print("",st1);
       }
 
   }
}
