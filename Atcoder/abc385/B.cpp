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


#define N 1000010

int h,w,ans;
string mp[N];
void solve()
{
	int x,y;
	cin>>h>>w>>x>>y;
	x--;
	y--;
	for(int i=0;i<h;i++)
	{
		cin>>mp[i];
	}
	string str;cin>>str;
	map<char,pair<int,int>>dt;
	dt['U']=mk(-1,0);
	dt['D']=mk(1,0);
	dt['L']=mk(0,-1);
	dt['R']=mk(0,1);
	for(unsigned int i=0;i<str.size();i++)
	{
		int nx=x+dt[str[i]].first,ny=y+dt[str[i]].second;
//		cout<<"now mp="<<mp[nx][ny]<<endl;
		if(nx>=0&&ny>=0&&nx<h&&ny<w&&mp[nx][ny]!='#')
		{
			x=nx;
			y=ny;
			if(mp[nx][ny]=='@')
			{
				ans++;
				mp[nx][ny]='.';
			}
		}
//		DEBUG(x+1,1);
//		DEBUG(y+1,2);
	}
	cout<<x+1<<" "<<y+1<<" "<<ans<<endl;
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
