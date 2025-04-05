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


#define N 200010
int n;
string s;
int cnt[N];
vector<int>pos[200];
void solve()
{
	for(int i='a';i<='z';i++) pos[i].clear();
	
	cin>>s;
	n=s.size();
	s=" "+s;
	cnt[n+1]=0;
	for(int i=n;i>=1;i--)
	{
		cnt[i]=cnt[i+1];
		cnt[i]|=(1<<(s[i]-'a'));
	}
	for(int i=1;i<=n;i++) pos[s[i]].push_back(i);
	string t;
	int now=0,remain=cnt[1];
	int m=0;
	for(int k=0;k<=30;k++) if(remain&(1<<k)) m++;
	for(int i=0;i<m;i++)
	{
//		DEBUG(i,1);
		int jump=0;
		for(char ch='z';ch>='a';ch--)
		{
			if((remain&(1<<(ch-'a')))==0) continue;
//			DEBUG(ch,2);
			int p=upper_bound(pos[ch].begin(),pos[ch].end(),now)-pos[ch].begin();
//			DEBUG(p,3);
			if(p==pos[ch].size()) continue;
			if(((cnt[pos[ch][p]]|(1<<(ch-'a')))&remain)==remain)
			{
				jump=pos[ch][p];
//				cout<<"ready jump to "<<jump<<endl;
			}
			if(jump)
			{
				remain&=(~(1<<(ch-'a')));
				now=jump;
				t.push_back(ch);
				break;
			}
		}
		
	}
	cout<<t<<endl;
}

int main()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	cout.precision(10);
	int t=1;
	cin>>t;
	LOOP(t)
	{
		solve();
	}
	return 0;
}
