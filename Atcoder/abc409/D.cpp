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


#define N 2000100

void solve()
{
	int n;string str;
	cin>>n>>str;
	int l=-1,r=-1;
	for(int i=0;i<n-1;i++)
	{
		if(str[i]>str[i+1])
		{
			l=i;
			break;
		}
	}
	if(l>=0)
	{
		for(int i=l+1;i<n;i++)
		{
			if(str[i]>str[l])
			{
				r=i-1;
				break;
			}
		}
		if(r==-1) r=n-1;
	}
//	DEBUG(l,1);
//	DEBUG(r,2);
	if(l!=-1&&r!=-1)
	{
		for(int i=0;i<n;i++)
		{
			if(i<l||i>r) cout<<str[i];
			if(i>=l&&i<r) cout<<str[i+1];
			if(i==r) cout<<str[l];
		}
	}
	else cout<<str;
	cout<<endl;
}

int main()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	cout.precision(10);
	int t=1;
	cin>>t;
	LOOP(t)
	{
		solve();
	}
	return 0;
}
