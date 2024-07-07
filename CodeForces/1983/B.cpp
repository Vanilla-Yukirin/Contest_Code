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



#define N 600

int a[N][N],b[N][N];
int n,m;



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
		cin>>n>>m;
		string str;
		for(int i=1;i<=n;i++)
		{
			cin>>str;
			for(int j=1;j<=m;j++) a[i][j]=str[j-1]-'0';
		}
		for(int i=1;i<=n;i++)
		{
			cin>>str;
			for(int j=1;j<=m;j++)
			{
				b[i][j]=str[j-1]-'0';
				a[i][j]=((a[i][j]-b[i][j])%3+3)%3;
			}
		}
		bool flag=1;
		for(int i=1;i<n&&flag;i++)
		{
			for(int j=1;j<m&&flag;j++)
			{
				if(a[i][j]==1)
				{
					a[i][j]=(a[i][j]+2)%3;
					a[i+1][j+1]=(a[i+1][j+1]+2)%3;
					a[i+1][j]=(a[i+1][j]+1)%3;
					a[i][j+1]=(a[i][j+1]+1)%3;
				}
				else if(a[i][j]==2)
				{
					a[i][j]=(a[i][j]+1)%3;
					a[i+1][j+1]=(a[i+1][j+1]+1)%3;
					a[i+1][j]=(a[i+1][j]+2)%3;
					a[i][j+1]=(a[i][j+1]+2)%3;
				}
			}
			if(a[i][m]) flag=0;
		}
		for(int j=1;j<=m;j++)
		{
			if(a[n][j]) flag=0;
		}
		
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
		
		
		
		
		
		
	}
	return 0;
}
