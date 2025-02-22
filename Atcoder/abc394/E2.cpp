/**************************************************************
 * Problem: 
 * Author: Vanilla_chan
 * Date: 
 * E-Mail: heshaohong2015@outlook.com
 **************************************************************/
#include<bits/stdc++.h>
#define IL inline
#define re register
#define LL long long
#define ll long long
#define ULL unsigned long long
#define ull unsigned long long
#define mk(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define endl '\n'
#ifdef TH
#define debug cout<<"Now is "<<__LINE__<<endl;
#else
#define debug
#endif

std::string COLORS[]={"\033[0m","\033[91m","\033[92m","\033[93m","\033[94m","\033[95m","\033[96m"};
std::string COLOR_NAMES[]={"RESET","RED","GREEN","YELLOW","BLUE","MAGENTA","CYAN"};

#define DEBUG(x,color)                   \
cout<<COLORS[color];                     \
cout << #x << " : " << x << endl;        \
cout<<COLORS[0];                         \
cout.flush();

#define LOOP(While_times) while(While_times-->0)
using namespace std;


#define N 110

int n;
string mp[N];
int dp[N][N];
const int inf = 1000000000;
void solve()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>mp[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			dp[i][j]=inf;
		}
	}
	for(int i=0;i<n;i++)
	{
		dp[i][i]=0;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(mp[i][j]!='-')
			dp[i][j]=min(dp[i][j],1);
		}
	}
	while(1)
	{
		bool change=0;
		
		for(char c='a';c!='z'+1;c++)
		{
			for(int x1=0;x1<n;x1++)
			{
				for(int y1=0;y1<n;y1++)
				{
					if(mp[x1][y1]==c)
					{
						for(int x2=0;x2<n;x2++)
						{
							for(int y2=0;y2<n;y2++)
							{
								if(mp[x2][y2]==c&&(x1!=x2||y1!=y2))
								{
									if(dp[y1][x2]!=inf)
									{
										if(dp[x1][y2]>dp[y1][x2]+2)
										{
											dp[x1][y2]=dp[y1][x2]+2;
											change=1;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		
		if(!change) break;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(dp[i][j]==inf) dp[i][j]=-1;
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
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
	LOOP(t)
	{
		solve();
	}
	return 0;
}
