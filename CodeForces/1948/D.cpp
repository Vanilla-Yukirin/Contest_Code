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



#define N 10000


char ch[N];
int n;
int ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	cin>>t;
	while(t--)
	{
		cin>>(ch+1);
		n=strlen(ch+1);
//		cout<<n<<endl;
		ans=0;
		bool flag;
		for(int i=1;i<=n;i++)
		{
//			for(len=max(ans,1);i+len*2-1<=n;len++)
			for(int len=(n-i+1)/2;len>=ans;len--)
			{
				flag=1;
				for(int j=0;j<len;j++)
				{
					if(ch[i+j]!=ch[i+len+j]&&ch[i+j]!='?'&&ch[i+len+j]!='?') flag=0;
				}
				if(flag)
				{
					ans=len;
					break;
				}
			}
		}
		cout<<ans*2<<'\n';
	}
	return 0;
}
