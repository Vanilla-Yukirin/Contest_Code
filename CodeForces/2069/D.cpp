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
string str;
void solve()
{
	cin>>str;
	int n=str.size();
	int same=0;
	for(int i=0;i*2<n;i++)
	{
		if(str[i]!=str[n-i-1]) break;
		same=i+1;
	}
//	DEBUG(same,1);
	str=str.substr(same,n-same*2);
	cout<<str<<endl;
	n=str.size();
	int ans=n;
	vector<int>cnt1(120),cnt2(120);
	for(int i=0;i<n;i++) cnt1[str[i]]++;
	for(int i=n-1;i>=0;i--)
	{
		//try to not use str[i]
		if(i>=n/2) cnt2[str[i]]++,cnt1[str[i]]--;
		else cnt2[str[i]]--,cnt1[str[i]]--;
		// print
//		DEBUG(i,2);
//		for(int i=0;i<120;i++)
//		{
//			if(cnt1[i]||cnt2[i])
//			{
//				cout<<(char)i<<" : "<<cnt1[i]<<" "<<cnt2[i]<<endl;
//			}
//		}
		//test
		bool succ=1;
		for(int i=0;i<120;i++)
		{
			if(cnt1[i]<cnt2[i]) succ=0;
		}
		if(succ) ans=i;
		else break;
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
	cin>>t;
	LOOP(t)
	{
		solve();
	}
	return 0;
}
