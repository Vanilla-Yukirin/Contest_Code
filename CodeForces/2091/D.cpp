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

int n,m,k;
//void solve()
//{
//	cin>>n>>m>>k;
//	LL l=1,r=n,mid;
//	while(l<=r)
//	{
//		mid=(l+r)/2;
//		LL one=floor(n*1.0/(mid+1))*mid;
//		if(one*m<k) l=mid+1;
//		else r=mid-1;
//	}
//	cout<<mid<<endl;
//	
//}

void solve()
{
	cin>>n>>m>>k;
	LL part=m;
	for(int kk=30;kk>=0;kk--)
	{
		LL nw=part-(1<<kk);
		if(nw<0) continue;
		LL one=m/(nw+1)*nw+m%(nw+1);
		if(one*n>=k) part=nw;
	}
//	swap(n,m);
	LL part2=0;
//	for(int kk=30;kk>=0;kk--)
//	{
//		LL nw=part2-(1<<kk);
//		if(nw<0) continue;
//		LL one=n/(nw+1)*nw;
//		if(one*m>=k) part2=nw;
//	}
	cout<<max(part,part2)<<endl;
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
