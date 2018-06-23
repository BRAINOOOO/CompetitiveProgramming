
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
//#define     point                    complex<double>
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


struct point{
  double x,y;
  point(double x=0,double y=0):x(x),y(y){}
  point operator -(point &other){
  	return point(x-other.x,y-other.y);
  }
  point operator +(point &other){
   	return point(x+other.x,y+other.y);
  }
  point operator /(double f){
  	return point(x/f,y/f);
  }
  point operator *(double f){
   	return point(x*f,y*f);
  }

};
const int N=5;
point arr[N];
double EPS=1e-5;
double cross(point v1,point v2){
	return v1.x*v2.y-v1.y*v2.x;
}
int dcmp(double x,double y){
	return fabs(x-y) < EPS?0:x>y?1:-1;
}




bool interSeg(point &a,point &b,point &c,point &d,point &intersect){
double d1 = cross(a - b, d - c), d2 = cross(a - c, d - c), d3 = cross(a - b, a - c);
    if (fabs(d1) < EPS)
        return false;  // Parllel || identical
    
    double t1 = d2 / d1, t2 = d3 / d1;
    intersect =((b - a) * t1) +a;
    
    if (t1>1+EPS||t1 < -EPS || t2 < -EPS || t2 > 1 + EPS)
        return false;
    return true;
}
double area(vector<point>&v){
   double ret=0;
   v.push_back(v[0]);
   for(int i=0;i<(int)v.size()-1;i++){
   	  ret+=cross(v[i],v[i+1]);
   }
   return fabs(ret)/2.0;
}

pair<double,double>polycut(point &A,point &B){
     vector<point> left, right;
    point intersect;
    for (int i = 0; i <4; ++i) {
        point cur = arr[i], nxt = arr[(i + 1)];
        
        if ( cross(B-A, cur-A) >= 0)
            right.push_back(cur);         
        if ( cross(B-A, cur-A) <= 0)
            left.push_back(cur);
        if (interSeg(A, B, cur, nxt, intersect)) {
            right.push_back(intersect);
            left.push_back(intersect);
        }


             
    }
    return make_pair(area(left), area(right));
	
}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
     int cake=1;
      while(true){
         int n=4;     
         bool stop=false;
         for(int i=0;i<n;i++){
         	 scanf("%lf %lf",&arr[i].x,&arr[i].y);
         	 stop|=(arr[i].x>0 ||arr[i].y >0);
         }
         if(!stop)break;
         arr[n]=arr[0];
         vector<point>pts;
         for(int i=0;i<n;i++){
         	  pts.push_back(arr[i]);
         	  point mid=(arr[i]+arr[i+1])/2.0;
         	  pts.push_back(mid);
         }
         double best=1e30;
         double ft=0,se=0;
         for(int i=0;i<pts.size();i++){
         	for(int j=i+1;j<pts.size();j++){

         	    pair<double,double>ret=polycut(pts[i],pts[j]);
//       	    cout<<i<<" "<<j<<" "<<ret.first<<" "<<ret.second<<endl
         	    if(dcmp(fabs(ret.first-ret.second),best)!=1)
                {
         	        best=fabs(ret.first-ret.second);
         	        ft=min(ret.first,ret.second);
         	        se=max(ret.first,ret.second);
         	    }
         	}
         }
         
         printf("Cake %d: %.3f %.3f\n",cake++,ft,se);
      
      }



}

