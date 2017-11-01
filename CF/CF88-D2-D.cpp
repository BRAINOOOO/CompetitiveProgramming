/*
here the the problem is about implementation the only data types are 
void and errtype or a type declared before so i simply test if it is declared 
before ( by checking that the left side is '&' only and the right side is '*'
only due to the language syntax ) so i store all the new datatypes in a map
if the query is to define a new data type i will go know its orgin return it
and the same for the other query
*/
#include <bits/stdc++.h>
#define sz(v)   ((int)(v).size())
#define  all(v)    ((v).begin()),((v).end())
#define  allr(v)    ((v).rbegin()),((v).rend())
#define   pb         push_back
#define   mp         make_pair
#define   mt         make_tuple
#define   inf        0x7fffffff
#define    clr(v,d)      memset( v, d ,sizeof(v))
#define    vi       vector<int>
#define    vd       vector<double>
#define    vvi      vector< vector<int> >
#define    vvll      vector< vector<long long> >
#define    vvpi     vector< vector< pair<int,int> > >
#define    vvpll     vector< vector< pair<long long,long long> > >
#define    vvd      vector< vector<double> >
#define    vs       vector<string>
#define    vvs      vector< vector<string> >
#define     vc        vector<char>
#define     vpi        vector< pair<int ,int> >
#define      pi        pair<int ,int>
#define      pll       pair<long long ,long long>
#define     vpd        vector< pair<double ,double> >
#define     vpll        vector< pair<long long ,long long> >
#define    vll       vector<long long>
#define    dqi        deque< int >
#define     si         set<int>
#define     spi        set< pair<int ,int > >
#define     row          vector< ll >
#define     matrix            vector< row >
#define    lp(i,n)    for(i=0;i<n;i++)
#define     si         set<int>
#define    oo         900000000000000000
#define   MOD         1000000007
#define    X            real
#define    Y            imag
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
#define    scani(n)                  scanf("%d",&n)
#define    scanll(n)                  scanf("%I64d",&n)
#define    printi(n)                 printf("%d",n)
#define    printll(n)                 printf("%I64d",n)
#define    scand(n)                  scanf("%lf",&n)
#define    printd(n)                 printf("%lf",n)
#define    scans(n)                  scanf("%s",&n)
#define    prints(n)                 printf("%s",n)
typedef  long long     ll ;
typedef  unsigned long long ull;
const double eps= (1e-10);
const double  PI= acos(-1.0);
using namespace std;
int dcmp(double a,double b){   return fabs(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
int setBit0(int num, int idx) {return num & ~(1<<idx);}
int flipBit(int num, int idx) {return num ^ (1<<idx);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
map< string,string> mb;

string check(string s1)
{

    for(auto i=mb.begin();i!=mb.end();i++)
    {

        if(s1.find((*i).first)!=string::npos)
        {
           int id=s1.find((*i).first);
           int fl=0;
           string l="";
            for(int i=0;i<id;i++)
            {
                 l+=s1[i];
                  if(s1[i]!='&')
                 {
                     fl=1;
                     break;
                 }
            }
            if(fl)
                continue;

            string r="";
            int siz=sz((*i).first);
            fl=0;
            for(int i=id+siz;i<sz(s1);i++)
             {
                 r+=s1[i];
                 if(s1[i]!='*')
                 {
                     fl=1;
                     break;
                 }
             }

             if(fl)
                continue;


           string tot=l+((*i).second)+r;

            if(((*i).second)=="errtype")
                return "errtype";


            int c2=0,c1=0;
            for(int i=0;i<sz(tot);i++)
            {
                if(tot[i]=='*')
                    c1++;
                else if(tot[i]=='&')
                    c2++;

            }





            if(c2>c1)
                return "errtype";
            else if(c2==c1)
                return "void";
            else
            {
                string ans="void";
                for(int i=0;i<c1-c2;i++)
                    ans+='*';

                return ans;
            }



        }

    }
   int c1=0,c2=0,fl;
    if(s1.find("void")!=string::npos)
    {
        int id=s1.find("void");
           int fl=0;
           string l="";
            for(int i=0;i<id;i++)
            {
                 l+=s1[i];
                  if(s1[i]!='&')
                 {
                     fl=1;
                     break;
                 }
                 c2++;
            }


            string r="";

            for(int i=id+4;i<sz(s1)&&!fl;i++)
             {
                 r+=s1[i];
                 if(s1[i]!='*')
                 {
                     fl=1;
                     break;
                 }
                 c1++;
             }



            if(c2>c1&&!fl)
                return "errtype";
            else if(c2==c1&&!fl)
                return "void";
            else if(!fl)
            {
                string ans="void";
                for(int i=0;i<c1-c2;i++)
                    ans+='*';

                return ans;
            }

    }

    return "errtype";

}
int main()
{
    int n;
    cin>>n;
    string state,s1,nw;

    for(int i=0;i<n;i++)
    {
        cin>>state;
        if(state=="typedef")
        {

            cin>>s1>>nw;
           string s2 = check(s1);
           mb[nw]=s2;



        }
        else
        {
            cin>>s1;

           cout<< check(s1) <<endl;
        }

    }
}
