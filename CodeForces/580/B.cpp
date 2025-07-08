/**************************************************************
 * Problem: L
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
int n;
LL d;
vector<pair<LL,LL>>vec;

void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		LL x,y;
		cin>>x>>y;
		vec.push_back(mk(x,y));
	}
	sort(vec.begin(),vec.end());
	int l=0;
	LL sum=0;
	LL ans=0;
	for(int r=0;r<n;r++)
	{
		sum+=vec[r].second;
		while(vec[r].first>=d+vec[l].first&&l<r)
		{
			sum-=vec[l].second;
			l++;
		}
		if(vec[r].first<d+vec[l].first)
		{
//			cout<<"l="<<l<<" r="<<r<<endl;
			ans=max(ans,sum);
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
