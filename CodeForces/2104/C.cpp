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


#define N 10000100

int n;
string str;
bool A[N],B[N];
int sumA,sumB;
void solve()
{
	sumA=sumB=0;
	cin>>n>>str;
	str=" "+str;
	for(int i=1;i<=n;i++)
	{
		A[i]=(str[i]=='A');
		B[i]=!A[i];
		sumA+=A[i];
		sumB+=B[i];
	}
	if(A[1]&&(A[n]||sumA==n-1))
	{
		cout<<"Alice"<<endl;
		return;
	}
	if(A[n]&&B[1]&&A[n-1])
	{
		cout<<"Alice"<<endl;
		return;
	}
	cout<<"Bob"<<endl;
	
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
