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

//D:REFSXC
//右上 左上 右 左 左下 右下
string qwert[3];
int dt[6][2]={-1,+1, -1,0, 0,+1, 0,-1, +1,-1, +1,0};
void solve()
{
	qwert[0]="QWERTYUIOP";
	qwert[1]="ASDFGHJKL";
	qwert[2]="ZXCVBNM";
	char c;cin>>c;
	int x,y;
	for(int i=0;i<3;i++)
	{
		for(unsigned int j=0;j<qwert[i].size();j++)
		{
			if(c==qwert[i][j]) x=i,y=j;
		}
	}
	for(int t=0;t<6;t++)
	{
		int nx=x+dt[t][0],ny=y+dt[t][1];
		if(ny>=0&&nx>=0&&nx<=2&&ny<qwert[nx].size())
		{
			cout<<qwert[nx][ny];
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
