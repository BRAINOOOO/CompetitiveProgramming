/*
explanation : here the idea is if i am going through a word and in my way i passed by another word so its prefix is another
word so the answer will be no .
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
    map< char,trie* > child;
    int isleaf;
    trie()
    {
        child=map<char,trie*> ();
        isleaf=0;
    }
    void insertt(char *str)
    {
        if(*str=='\0')
         {
             isleaf=1;
         }
        else
        {
            char cur=*str;
            if(child.find(cur)==child.end())
                child[cur]=new trie();
              child[cur]->insertt(str+1);
        }
    }
    bool check(char *str)
    {
        if(*str=='\0')
         {
             isleaf=1;
             return 1;
         }
         else if(isleaf)
         {
             return 0;
         }
        else
        {
            char cur=*str;
            if(child.find(cur)==child.end())
                child[cur]=new trie();
        return child[cur]->check(str+1);
        }
    }
}; 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        trie root;
        string st;
        vector<string> v;
        for(int i=0;i<n;i++)
        {
           cin>>st,v.pb(st);
           char str[15];
            strcpy(str,st.c_str());
           root.insertt(str);
        }
        int fl=0;
        for(int i=0;i<n;i++)
        {
            char str[15];
            st=v[i];
            strcpy(str,st.c_str());
           if(! root.check(str))
          {
             fl=1;
             break;
          }
        }
        if(fl)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
}
