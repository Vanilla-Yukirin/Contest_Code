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



#define N 1000010




int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(10);
	int t=1;
	cin>>t;
	while(t--)
	{
		int n;cin>>n;
		int zm=-1,sz=-1;
		string str;cin>>str;
		bool flag=1;
		for(int i=0;i<n;i++)
		{
			if((str[i]>'9'||str[i]<'0')&&(str[i]>'z'&&str[i]<'a')) flag=0;
			if(str[i]>='a'&&str[i]<='z'&&i!=n-1)
			{
				if(str[i+1]<='9'&&str[i]>='0') flag=0;
			}
			if(str[i]>='a'&&str[i]<='z')
			{
				if(str[i]-'a'<zm) flag=0;
				zm=max(zm,str[i]-'a');
			}
			if(str[i]>='0'&&str[i]<='9')
			{
				if(str[i]-'0'<sz) flag=0;
				sz=max(sz,str[i]-'0');
			}
		}
		
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}
	return 0;
}
