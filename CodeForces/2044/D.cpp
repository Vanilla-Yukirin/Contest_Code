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

int a[N];
int n;
int b[N];
set<int>m;
int no_m;
int no_m_generator()
{
	while(m.find(no_m)!=m.end()) no_m++;
	m.insert(no_m);
	return no_m;
}

map<int,int>cnt;
void solve()
{
	no_m=1;
	cnt.clear();
	m.clear();
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],m.insert(a[i]);
	for(int i=1;i<=n;i++)
	{
		if(cnt[a[i]]==0)
		{
			b[i]=a[i];
//			DEBUG(i,1)
		}
		else
		{
			b[i]=no_m_generator();
//			DEBUG(i,2)
		}
		cnt[a[i]]++;
	}
	for(int i=1;i<=n;i++) cout<<b[i]<<" ";
	cout<<endl;
//	cout.flush();
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
