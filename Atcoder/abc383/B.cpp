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
#define pb(a,b) push_back(a,b)
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

int h,w,d;
int mp[N][N];
int can[N][N];
int ans;
void solve()
{
	cin>>h>>w>>d;
	for(int i=1;i<=h;i++)
	{
		string str;cin>>str;
		for(int j=1;j<=w;j++)
		{
			mp[i][j]=(str[j-1]=='.');
		}
	}
	
	for(int x01=1;x01<=h;x01++)
	{
		for(int y01=1;y01<=w;y01++)
		{
			if(mp[x01][y01]==0) continue;
			for(int x02=1;x02<=h;x02++)
			{
				for(int y02=1;y02<=w;y02++)
				{
					if(mp[x02][y02]==0) continue;
					if(x01==x02&&y01==y02) continue;
					//clear
					int now=0;
					for(int i=1;i<=h;i++)
					{
						for(int j=1;j<=w;j++)
						{
							if(mp[i][j]&&(abs(i-x01)+abs(j-y01)<=d||abs(i-x02)+abs(j-y02)<=d)) now++;
						}
					}
					ans=max(ans,now);
				}
			}
		}
	}
	cout<<ans<<endl;
	
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
