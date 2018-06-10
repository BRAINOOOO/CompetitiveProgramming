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
vector<string> v;
int n,m,arr[3000][3000],arr2[3000][3000],dleft[3000][3000],dright[3000][3000],vv[3000][3000];
int shift=1209,S=409;
bool valid(int r,int c)
{
    return (r<n&&r>=0&&c<m&&c>=0);
}
int main()
{
    cin>>n>>m;
    string st;
    for(int i=0;i<n;i++)
    {
        cin>>st;
        v.pb(st);
        for(int j=0;j<m;j++)
        {
            if(j)
                arr[i][j]=arr[i][j-1]+(v[i][j]-'0');
            else
                arr[i][j]=v[i][j]-'0';
        }
    }

    for(int i=0;i<m;i++)
    {

        for(int j=0;j<n;j++)
        {
            if(j)
                arr2[i][j]=arr2[i][j-1]+(v[j][i]-'0');
            else
                arr2[i][j]=v[j][i]-'0';
        }
    }

   for(int i=0;i<n;i++)
   {
       for(int j=409,l=0;l<m;l++,j++)
       {
           vv[i][j]=v[i][l]-'0';
       }
   }

   int r=0,c,X;
    for(int i=0;i<1209;i++)
    {
        r=0;
        c=i;
        X= r+c;
        while(r<1209&&r>=0&&c<1209&&c>=0)
        {
            dleft[X][r]=(r==0? 0:dleft[X][r-1])+vv[r][c];
            r++;
            c--;

        }
    }

     r=0;
    for(int i=0;i<1209;i++)
    {
        r=0;
        c=i;
        X= r-c+shift;
         while(r<1209&&r>=0&&c<1209&&c>=0)
        {

            dright[X][r]=(r==0? 0:dright[X][r-1])+vv[r][c];
            r++;
            c++;

        }
    }

    int mx=max(n,m);
    ll cnt=0;
    int nxtleftrow,nxtleftcl,prevleftrow,prevleftcl,nxtrightrow,nxtrightcl,prevrightrow,prevrightcl;
    for(int len=1;len<=mx;len++)
    {

        for(int i=0;i<n;i++)
        {

            for(int j=0;j<m;j++)
            {
                int range= arr[i][j+len]-(j==0 ? 0: arr[i][j-1]);
                if(j+len>=m||range!=0)
                    continue;

                nxtleftrow= i+len;
                nxtleftcl= j;

                nxtrightrow= i+len;
                nxtrightcl= j+len;
                if(valid(nxtleftrow,nxtleftcl))
                {

                int range2= arr2[j][i+len]-(i==0? 0: arr2[j][i-1]);
                int range3= dleft[i+j+len+S][i+len]- (i==0? 0: dleft[i+j+len+S][i-1]);
                if(range2==0&&range3==0)
                    cnt++;
                }

                if(valid(nxtrightrow,nxtrightcl))
                {

                int range2= arr2[j+len][i+len]-(i==0? 0: arr2[j+len][i-1]);
                int range3= dright[i-j+shift-S][i+len]- (i==0? 0: dright[i-j+shift-S][i-1]);

                if(range2==0&&range3==0)
                    cnt++;
                }
                prevleftrow= i-len;
                prevleftcl= j;

                prevrightrow= i-len;
                prevrightcl= j+len;

                if(valid(prevleftrow,prevleftcl))
                {

                int range2= arr2[j][i]-(i-len==0? 0 : arr2[j][i-len-1]);
                int range3= dright[i-(j+len)+shift-S][i] - (i-len==0? 0 : dright[(i-len)-j+shift-S][i-len-1]);

                if(range2==0&&range3==0)
                    cnt++;
                }

                if(valid(prevrightrow,prevrightcl))
                {
                int range2= arr2[j+len][i]- (i-len==0? 0 : arr2[j+len][i-len-1]);
                int range3= dleft[i+j+S][i] - (i-len==0? 0 : dleft[(i-len)+(j+len)+S][i-len-1]);


                if(range2==0&&range3==0)
                    cnt++;

                }
                if(len%2!=0)
                {
                    continue;
                }

               int nxtcenterrow= i+len/2;
               int nxtcentercl= j+ len/2;

               if(valid(nxtcenterrow,nxtcentercl))
               {

                   int range2= dright[(i+len/2)-(j+len/2)+shift-S][i+len/2] -(i==0? 0: dright[i-j+shift-S][i-1]);
                   int range3= dleft[(i+len/2)+(j+len/2)+S][i+len/2] - (i==0? 0: dleft[(i)+(j+len)+S][i-1]);

                if(range2==0&&range3==0)
                   cnt++;
               }
               int prevcenterrow= i-len/2;
               int prevcentercl= j+ len/2;

               if(valid(prevcenterrow,prevcentercl))
               {

               int range2= dright[(i)-(j+len)+shift-S][i] -(i-len/2==0? 0: dright[(i-len/2)-(j+len/2)+shift-S][i-(len/2)-1]);

               int range3= dleft[ i+j+S][i] - (i-(len/2)==0 ? 0: dleft[(i-len/2)+(j+len/2)+S][i-(len/2)-1]);

                if(range2==0&&range3==0)
                    cnt++;
               }

            }
        }
        for(int i=0;i<m&&len%2==0;i++)
        {
            for(int j=0;j<n;j++)
            {


                int range= arr2[i][j+len]-(j==0 ? 0: arr2[i][j-1]);
                if(j+len>=n||range!=0)
                    continue;

                int nxtcenterrow= j+len/2;
               int nxtcentercl= i+ len/2;
               if(valid(nxtcenterrow,nxtcentercl))
               {

                   int range2= dright[(j+len/2)-(i+len/2)+shift-S][j+len/2] -(j==0? 0: dright[j-i+shift-S][j-1]);
                   int range3= dleft[j+len + i+S][j+len] - ((j+len/2)==0? 0: dleft[(i+len/2)+(j+len/2)+S][(j+len/2)-1]);

                if(range2==0&&range3==0)
                   cnt++;
               }
               int prevcenterrow= j+len/2;
               int prevcentercl= i- len/2;
               if(valid(prevcenterrow,prevcentercl))
               {
               int range2= dright[(j+len)-(i)+shift-S][j+len] -(j+len/2==0? 0: dright[(j+len/2)-(i-len/2)+shift-S][j+(len/2)-1]);

               int range3= dleft[ j+i+S][j+len/2] - (j==0 ? 0: dleft[j+i+S][j-1]);

                if(range2==0&&range3==0)
                    cnt++;
               }

            }

        }

    }
    cout<<cnt<<endl;
}



