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
		
int tar[]={2,3,5,6,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,30,31,32,33,34,38,39,40,46};
int n_tar=sizeof(tar)/sizeof(tar[0]);
set<int>set_tar;
		
void solve()
{
	for(int i=0;i<n_tar;i++)
	{
		set_tar.insert(tar[i]);
	}
//	cout<<set_tar.size();
//	return;
	cout<<49<<endl;
	for(int T=1;T<=49;T++)
	{
		if(set_tar.find(T)==set_tar.end())
		{
			//AC
			cout<<5<<" "<<5<<endl;
			for(int n=1;n<=5;n++)
			{
				cout<<1<<" ";
			}
			cout<<endl;
			for(int q=1;q<=5;q++)
			{
				cout<<1<<" "<<2<<endl;
			}
		}
		else
		{
			//TLE
			cout<<10000<<" "<<10000<<endl;
			for(int n=1;n<=10000;n++)
			{
				cout<<1<<" ";
			}
			cout<<endl;
			for(int q=1;q<=10000;q++)
			{
				cout<<1<<" "<<10000<<endl;
			}
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
