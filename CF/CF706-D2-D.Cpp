/*
explanation : the idea is i need the max xor between x and some number so from left to right i need the flipping digit to corresponding
x digit when i reached a certain prefix its my periority so i need to search for the numbers having the same prefix and the next digit
is the flipping digit if it exists trie expresses common prefix.
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
vector<string> v;
string converttobin(int x);
ll converttodec(string s);
struct trie
{
    map< char,trie* > child;
    int isleaf;
    trie()
    {
        child=map<char,trie*> ();
        isleaf=0;
    }
};
    void insertt(trie* cur,string word,int id)
    {
        if(id==sz(word))
        {
            cur->isleaf++;
            return ;
        }
       char ch=word[id];
      if(cur->child.find(ch)==cur->child.end())
       {
           cur->child[ch]= new trie();
       }
         trie* node=cur->child[ch];
         insertt(node,word,id+1);
    }
    bool del(trie* cur,string word,int id)
    {
        if(id==sz(word))
        {
            if(cur->isleaf==0)
                return 0;
            cur->isleaf--;
            return sz(cur->child)==0&&cur->isleaf==0;
        }
        char ch=word[id];
      if(cur->child.find(ch)==cur->child.end())
       {
           return 0;
       }
         trie* node=cur->child[ch];
        bool ret=  del(node,word,id+1);
        if(ret)
        {
            cur->child.erase(cur->child.find(ch));
            return sz(cur->child)==0&&cur->isleaf==0;
        }
        return 0;
    }
    ll check(trie* cur, string word, string ans, ll x, int id)
    {
        char ch1= word[id];
        char ch1x= ((word[id]-'0')^1ll)+'0';
       if(id==sz(word))
       {
           int n=converttodec(ans);
           return x^n;
       }
       else if( cur->child.find(ch1x)!=cur->child.end())
       {
           trie* node=cur->child[ch1x];
          return check(node,word,ans+ch1x,x,id+1);
       }
       else
       {
           trie* node=cur->child[ch1];
          return check(node,word,ans+ch1,x,id+1);
       }
    }
string converttobin(int x)
{
    string ans="";
    for(int i=0;i<35;i++)
    {
        int rem=x%2;
        char ch=rem+'0';
        ans=ch+ans;
        x/=2;
    }
    return ans;
}
ll converttodec(string s)
{
    ll num=0;
    ll p=1;
    for(int i=0,j=sz(s)-1;i<sz(s);i++,j--)
    {
       if(s[j]-'0')
           num+=p;
       p*=2;
    }
    return num;
}
int main()
{
    int n;
    cin>>n;
    trie* root=new trie();
    char c;
    ll x;
    string fr=converttobin(0);
    insertt(root,fr,0);
    for(int i=0;i<n;i++)
    {
        cin>>c>>x;
       string bin=converttobin(x);
       if(c=='+')
       {
          insertt(root,bin,0);
       }
       else if(c=='-')
       {
           del(root,bin,0);
       }
       else
       {
           cout<<check(root,bin,"",x,0)<<endl;
       }
    }
}
