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
int n;
LL m;
struct node{
	LL p,k,cnt;
	node(LL xx,LL yy,LL zz){
		p=xx;
		k=yy;
		cnt=zz;
	}
	LL val()
	{
		return p*(2*k-1);
	}
	bool operator<(const node & z)const
	{
		return val()>z.val();
	}
};
priority_queue<node>q0,q1;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		LL p;cin>>p;
		if(p&1) q1.push(node(p,1,1));
		else q0.push(node(p,1,1));
	}
	LL cost=0;
	while(1)
	{
		if(q1.top().val()<q0.top().val())
		{
			node now=q1.top();
			q1.pop();
			//same?
			if(q1.size()&&q1.top().p==now.p)
			{
				now.cnt+=q1.top().cnt;
				q1.pop();
				q1.push(now);
				continue;
			}
			if(cost+now.val()*now.cnt<=m)
			{
				
			}
		}
		
		break;
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
