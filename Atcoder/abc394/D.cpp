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

string str;
string ans;
int cnt[4];
map<char,int>mp,way;
void solve()
{
	mp['<']=mp['>']=1;
	mp['(']=mp[')']=2;
	mp['[']=mp[']']=3;
	way['<']=way['(']=way['[']=1;
	way['>']=way[')']=way[']']=2;
	
	cin>>str;
	for(int i=0;i<str.size();i++)
	{
		if(way[str[i]]==1)
		{
//			cnt[mp[str[i]]]++;
			ans.push_back(str[i]);
		}
		else
		{
			if(ans.size()==0)
			{
//				debug
				cout<<"No"<<endl;
				return;
			}
			if(way[ans.back()]!=way[str[i]]&&mp[ans.back()]==mp[str[i]])
			{
				ans.pop_back();
			}
			else	
			{
//				debug
				cout<<"No"<<endl;
				return;
			}
//			cnt[mp[str[i]]]--;
			
		}
	}
	if(ans.size())
	{
		cout<<"No"<<endl;
		return;
	}
	cout<<"Yes"<<endl;
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
