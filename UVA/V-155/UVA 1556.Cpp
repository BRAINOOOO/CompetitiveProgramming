/*
explanation : the trie data structure allows me to handel that they must be sorted, i treat each vector of strings as a word instead of 
chars strings using map and simply insert them and print them iterating on the map.

complexity : O(N*L).
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
vector< vector<string > > v;
struct trie
{
    map< string,trie* > child;
    int isleaf;
    trie()
    {
        child=map<string,trie*> ();
        isleaf=0;
    }
    void insertt(vector<string> v,int id)
    {
        if(id==sz(v))
            isleaf=1;
        else
        {
            string cur=v[id];
            if(child.find(cur)==child.end())
                child[cur]=new trie();
            child[cur]->insertt(v,id+1);
        }
    }
    void print(int sp)
    {
        for(auto i=child.begin();i!=child.end();i++)
        {
           string a= (*i).first ;
          for(int j=0;j<sp;j++)
            cout<<" ";
           cout<<a<<endl;
           (i->second)->print(sp+1);
        }
    }
};
int main()
{
   int n;
    while(cin>>n)
    {
        v.clear();
        v.resize(500+9);
        cin.ignore();
        for(int i=0;i<n;i++)
        {
           string line;
           getline(cin,line);
           string s="";
           for(int j=0;j<sz(line);j++)
           {
               if(line[j]=='\\')
               {
                   v[i].pb(s);
                   s="";
               }
               else
               s+=line[j];
               if(j==(sz(line)-1))
                {
                    v[i].pb(s);
                }
           }
        }
        trie  root;
        for(int i=0;i<n;i++)
        {
            root.insertt(v[i],0);
        }
        root.print(0);
       cout<<endl;
    }
}
