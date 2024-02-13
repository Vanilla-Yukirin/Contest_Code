/**************************************************************
 * Problem: 
 * Author: Vanilla_chan
 * Date: 
 * E-Mail: heshaohong2015@outlook.com
 **************************************************************/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<limits.h>
#define IL inline
#define re register
#define LL long long
#define ULL unsigned long long
#ifdef TH
#define debug printf("Now is %d\n",__LINE__);
#else
#define debug
#endif
#ifdef ONLINE_JUDGE
char buf[1<<23],* p1=buf,* p2=buf,obuf[1<<23],* O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#endif
using namespace std;

namespace oi
{
	inline bool isdigit(const char& ch)
	{
		return ch<='9'&&ch>='0';
	}
	inline bool isalnum(const char& ch)
	{
		return (ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9');
	}
	struct istream
	{
		char ch;
		bool fu;
		template<class T>inline istream& operator>>(T& d)
		{
			fu=d=0;
			while(!isdigit(ch)&&ch!='-') ch=getchar();
			if(ch=='-') fu=1,ch=getchar();
			d=ch-'0';ch=getchar();
			while(isdigit(ch))
				d=(d<<3)+(d<<1)+(ch^'0'),ch=getchar();
			if(fu) d=-d;
			return *this;
		}
		inline istream& operator>>(char& ch)
		{
			ch=getchar();
			for(;!isalnum(ch);ch=getchar());
			return *this;
		}
		inline istream& operator>>(string& str)
		{
			str.clear();
			for(;!isalnum(ch);ch=getchar());
			while(isalnum(ch))
				str+=ch,ch=getchar();
			return *this;
		}
	}cin;
	inline int read()
	{
		int x=0,fu=0;char ch=getchar();
		while(!isdigit(ch)&&ch!='-') ch=getchar();
		if(ch=='-') fu=1,ch=getchar();
		while(isdigit(ch)) { x=x*10+ch-'0';ch=getchar(); }
		if(fu) x=-x;
		return x;
	}
	int G[55];
	template<class T>inline void write(T x)
	{
		int g=0;
		if(x<0) x=-x,putchar('-');
		do { G[++g]=x%10;x/=10; } while(x);
		for(int i=g;i>=1;--i) putchar('0'+G[i]);
		putchar('\n');
	}
};
using oi::read;

#define N 200010


/*


i+j = kx
i-j = ky  =>  i = ky + j

i= (k1x + k2y)/2
j= (k1x - k2y)/2

*/


int t;
int n;
int x,y;
map<int,map<int,int>>m;
int a[N];
int ans;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>x>>y;
		ans=0;
		m.clear();
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			m[a[i]%x][a[i]%y]++;
			//cout<<a[i]%x<<"*"<<a[i]%y<<endl;
		}
		int modx1,modx2,mody1,mody2;
		for(auto it1=m.begin();it1!=m.end();it1++)
		{
			modx1=it1->first;
			//if(modx1>=(x+1)/2) break;
			modx2=x-modx1;
			modx2%=x;
			if(modx1>modx2) break;
			if(m.find(modx2)==m.end()) continue;
			for(auto it2=m[modx1].begin();it2!=	m[modx1].end();it2++)
			{
				mody1=it2->first;
				mody2=mody1;
				if(m[modx2].find(mody2)==m[modx2].end()) continue;
				if(modx1==modx2)
				{
					ans+=(m[modx1][mody1]-1)*(m[modx2][mody2])/2;
				}
				else
				{
					ans+=m[modx1][mody1]*m[modx2][mody2];
				}
				//cout<<modx1<<" "<<modx2<<" "<<mody1<<" "<<mody2<<" add"<<m[modx1][mody1]<<"*"<<m[modx2][mody2]<<endl;
			}
		}
		
		cout<<ans<<endl;
		
		
		
	}
	
	
	
	
	
	
	return 0;
}
