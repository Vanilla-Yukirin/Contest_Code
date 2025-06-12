/**************************************************************
 * Problem: 
 * Author: ArisuVanilla
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


#define N 1000010

int n,m;
int ord[N][2];
set<int>to[3][3];
string str;
int a[N];
void solve()
{
	cin>>n>>m;
	cin>>str;
	for(int i=1;i<=n;i++)
	{
		a[i]=str[i-1]-'a';
	}
	for(int i=0;i<=2;i++)
	{
		for(int j=0;j<=2;j++)
		{
			to[i][j].clear();
		}
	}
	for(int i=1;i<=m;i++)
	{
		char xc,yc;
		int x,y;
		cin>>xc>>yc;
		x=xc-'a';
		y=yc-'a';
		ord[i][0]=x;
		ord[i][1]=y;
		to[x][y].insert(i);
	}
	
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0) continue;
		if(a[i]==1)
		{
			//1->0
			if(to[1][0].size())
			{
				to[1][0].erase(to[1][0].begin());
				a[i]=0;
			}
			else
			{
				//1->2->0
				if(to[1][2].size())
				{
					int pos=*to[1][2].begin();
					set<int>::iterator second=to[2][0].upper_bound(pos);
					if(second!=to[2][0].end())
					{
						to[1][2].erase(to[1][2].begin());
						to[2][0].erase(second);
						a[i]=0;
					}
				}
			}
		}
		if(a[i]==2)
		{
			//2->0
			if(to[2][0].size())
			{
				to[2][0].erase(to[2][0].begin());
				a[i]=0;
			}
			else
			{
				//2->1->0
				if(to[2][1].size())
				{
					int pos=*to[2][1].begin();
					set<int>::iterator second=to[1][0].upper_bound(pos);
					if(second!=to[1][0].end())
					{
						to[2][1].erase(to[2][1].begin());
						to[1][0].erase(second);
						a[i]=0;
					}
					else
					{
						to[2][1].erase(to[2][1].begin());
						a[i]=1;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<(char)('a'+a[i]);
	}
	cout<<endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(10);
	int t=1;
	cin>>t;
	LOOP(t)
	{
		solve();
	}
	return 0;
}
