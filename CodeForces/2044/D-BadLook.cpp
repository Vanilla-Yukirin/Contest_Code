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
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],m.insert(a[i]);
	vector<int>m_vector;
	for(auto it=m.begin();it!=m.end();it++) m_vector.push_back(*it);
	int loop=n/m_vector.size();
	for(int i=0;i<loop*m_vector.size();i++)
	{
		b[i]=m_vector[i%m_vector.size()];
	}
	int no_m=1;
	for(int i=loop*m_vector.size();i<n;i++)
	{
		while(m.find(no_m)!=m.end()) no_m++;
		b[i]=no_m;
		m.insert(no_m);
	}
	for(int i=0;i<n;i++) cout<<b[i]<<" ";
	cout<<endl;
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
