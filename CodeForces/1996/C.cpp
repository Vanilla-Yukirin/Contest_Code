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



#define N 2000010
#define M 30

int sum[N][M];
int n,q;

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
		cin>>n>>q;
		string str[2];cin>>str[0]>>str[1];
		str[0]='#'+str[0];
		str[1]='#'+str[1];
		for(int i=1;i<=n;i++)
		{
			for(int c=0;c<26;c++)
			{
				sum[i][c]=sum[i-1][c];
			}
			sum[i][str[0][i]-'a']++;
			sum[i][str[1][i]-'a']--;
		}
		
		while(q--)
		{
			int l,r;cin>>l>>r;
			int diff=0;
			for(int c=0;c<26;c++)
			{
				diff+=abs(sum[r][c]-sum[l-1][c]);
			}
			cout<<diff/2<<endl;
		}
		
	}
	return 0;
}
