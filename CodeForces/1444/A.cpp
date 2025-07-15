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


#define N 500000010




LL p,q;
void solve()
{
	cin>>p>>q;
	if(p%q)
	{
		cout<<p<<endl;
	}
	else
	{
		LL tt=p/q;
		LL qq=q;
		vector<pair<int,int>>vec;
		for(int i=2;i*i<=qq;i++)
		{
			if(qq%i==0)
			{
				vec.push_back(mk(i,0));
				while(qq%i==0) vec.back().second++,qq/=i;
			}
		}
		if(qq!=1)
		{
			vec.push_back(mk(qq,1));
		}
		
		LL ans=0;
		for(int i=0;i<vec.size();i++)
		{
//			DEBUG(vec[i].first,1);
			LL now=p;
			while(now%vec[i].first==0) now/=vec[i].first;
			for(int j=1;j<vec[i].second;j++) now*=vec[i].first;
			ans=max(ans,now);
		}
		cout<<ans<<endl;
	}
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
