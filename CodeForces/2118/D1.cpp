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
LL k;
LL pos[N];
LL delay[N];
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>pos[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>delay[i];
	}
	int q;
	cin>>q;
	while(q--)
	{
		set<pair<int,int>>s;
		LL now;cin>>now;
		LL tme=0;
		int way=1;
		while(1)
		{
			//find next light
			int next_idx=0;
			LL next_pos;
			if(way==1) next_pos=(LL)1e16;
			else next_pos=-1;
			for(int i=1;i<=n;i++)
			{
				if(way==1)
				{
					//l*k+d==pos-now+tme
					//pos-now+tme-d %k=0
					if(pos[i]>=now&&((pos[i]-now+tme-delay[i])%k+k)%k==0)
					{
						if(pos[i]<next_pos)
						{
							next_pos=pos[i];
							next_idx=i;
						}
					}
				}
				else
				{
					if(pos[i]<=now&&((now-pos[i]+tme-delay[i])%k+k)%k==0)
					{
						if(pos[i]>next_pos)
						{
							next_pos=pos[i];
							next_idx=i;
						}
					}
				}
			}
			if(next_idx)
			{
//				cout<<"撞击"<<next_idx<<" pos="<<pos[next_idx]<<endl;
				if(s.find(mk(next_idx,way))!=s.end())
				{
					cout<<"NO"<<endl;
					break;
				}
				s.insert(mk(next_idx,way));
				way=-way;
				tme+=abs(now-next_pos);
				now=next_pos;
				//撞击后再走一步
				tme++;
				now+=way;
			}
			else
			{
				cout<<"YES"<<endl;
				break;
			}
		}
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
