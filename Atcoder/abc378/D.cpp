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

#define RED cout << "\033[91m"
#define GREEN cout << "\033[92m"
#define YELLOW cout << "\033[93m"
#define BLUE cout << "\033[94m"
#define MAGENTA cout << "\033[95m"
#define CYAN cout << "\033[96m"
#define RESET cout << "\033[0m"

// 红色
#define DEBUG1(x)                     \
RED;                              \
cout << #x << " : " << x << endl; \
RESET;

// 绿色
#define DEBUG2(x)                     \
GREEN;                            \
cout << #x << " : " << x << endl; \
RESET;

// 蓝色
#define DEBUG3(x)                     \
BLUE;                             \
cout << #x << " : " << x << endl; \
RESET;

// 品红
#define DEBUG4(x)                     \
MAGENTA;                          \
cout << #x << " : " << x << endl; \
RESET;

// 青色
#define DEBUG5(x)                     \
CYAN;                             \
cout << #x << " : " << x << endl; \
RESET;

// 黄色
#define DEBUG6(x)                     \
YELLOW;                           \
cout << #x << " : " << x << endl; \
RESET;

#ifdef ONLINE_JUDGE
char buf[1<<23],* p1=buf,* p2=buf,obuf[1<<23],* O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#endif
using namespace std;



#define N 110
int n,m,k;
int to[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
bool book[N][N];
bool mp[N][N];
LL ans=0;
void dfs(int x,int y,int z)
{
//	cout<<"now "<<x<<" "<<y<<" "<<z<<endl;
	if(z==k+1)
	{
//		cout<<"z="<<z<<endl;
		ans++;
//		cout<<"end "<<x<<" "<<y<<endl;
		return;
	}
	if(z>=k+1) return;
	for(int t=0;t<4;t++)
	{
		int nx=x+to[t][0],ny=y+to[t][1];
		if(nx<1||ny<1||nx>n||ny>n||book[nx][ny]||mp[nx][ny]==0) continue;
		book[nx][ny]=1;
		dfs(nx,ny,z+1);
		book[nx][ny]=0;
	}
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(10);
	int t=1;
//	cin>>t;
	while(t--)
	{
		cin>>n>>m>>k;
		for(int i=1;i<=n;i++)
		{
			string str;cin>>str;
			for(int j=1;j<=m;j++)
			{
				mp[i][j]=(str[j-1]=='.');
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				
//				cout<<"start "<<i<<" "<<j<<endl;
				if(mp[i][j])
				{
					memset(book,0,sizeof(book));
					book[i][j]=1,dfs(i,j,1),book[i][j]=0;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
