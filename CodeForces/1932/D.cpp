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

#define N 10010


int t;
int n;
string King;
char king;
string card[N];
vector<string>CDHS[1000];
bool possible;
vector<string>ans;
bool book[N];
int cmp(string a,string b)//0 < 1 > 2 !=
{
	if(a[1]==king)
	{
		if(b[1]==king) return a[0]>b[0];
		return 1;
	}
	else
	{
		if(b[1]==king) return 0;
		if(a[1]==b[1]) return a[0]>b[0];
		return 2;
	}
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		cin>>King;
		king=King[0];
		memset(book,0,sizeof(book));
		possible=1;
		ans.clear();
		for(int i=0;i<1000;i++) CDHS[i].clear();
		for(int i=0;i<2*n;i++)
		{
			cin>>card[i];
			CDHS[(int)card[i][1]].push_back(card[i]);
		}
		string list="CDHS";
		for(int i=0;i<4;i++)
		{
			char ch=list[i];
			sort(CDHS[(int)ch].begin(),CDHS[(int)ch].end());			
		}
		vector<string>List;
		for(int i=0;i<4;i++)
		{
			char ch=list[i];
			if(ch==king) continue;
			List.insert(List.end(),CDHS[(int)ch].begin(),CDHS[(int)ch].end());

		}
		List.insert(List.end(),CDHS[(int)king].begin(),CDHS[(int)king].end());
		
		for(int i=0;i<(int)List.size();i++)
		{
			if(book[i]) continue;
			bool flag=0;
			for(int j=i+1;j<(int)List.size();j++)
			{
				if((!book[j])&&cmp(List[i],List[j])==0)
				{
					book[j]=1;
					flag=1;
					ans.push_back(List[i]);
					ans.push_back(List[j]);
					break;
				}
			}
			if(flag==0)
			{
				possible=0;
				break;
			}
		}
		
		if(!possible)
		{
			cout<<"IMPOSSIBLE"<<endl;
		}
		else{
			for(int i=0;i<ans.size();i++)
			{
				cout<<ans[i]<<" ";
				if(i&1) cout<<endl;
			}
		}
	}
	
	
	
	
	
	
	return 0;
}
