/**************************************************************
 * Problem: D
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

map<int,int>w;
string str[10];
int ans[N];
void solve()
{
	w['Q']=9;
	w['R']=5;
	w['B']=3;
	w['N']=3;
	w['P']=1;
	for(int i=0;i<8;i++)
	{
		cin>>str[i];
	}
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			char & ch=str[i][j];
			if(ch<='z'&&ch>='a')
			{
				ans[1]+=w[ch-'a'+'A'];
			}
			else
			{
				ans[0]+=w[ch];
			}
		}
	}
	if(ans[0]==ans[1])
	{
		cout<<"Draw"<<endl;
	}
	else
	{
		if(ans[0]>ans[1])
		{
			cout<<"White"<<endl;
		}
		else
		{
			cout<<"Black"<<endl;
		}
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
