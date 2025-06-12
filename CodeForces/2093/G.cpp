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


struct node
{
	int son[2];
	int mx;
#define mx(x) trie[x].mx
#define son(x) trie[x].son
}trie[N*4];
int cnt;
int new_node()
{
	cnt++;
	son(cnt)[0]=son(cnt)[1]=0;
	mx(cnt)=0;
	return cnt;
}

void add(int x,int pos)
{
	int p=1;
	vector<int>vec;
	for(int i=29;i>=0;i--)
	{
		bool xx=(x>>i)&1;
		vec.push_back(p);
		if(son(p)[xx]==0) son(p)[xx]=new_node();
		p=son(p)[xx];
	}
	mx(p)=pos;
	while(vec.size())
	{
		mx(vec.back())=max(mx(vec.back()),max(mx(son(vec.back())[0]),mx(son(vec.back())[1])));
		vec.pop_back();
	}
}

int n,k;
int find(int x)
{
	int ans=-1;
	bool flag=1;
	int p=1;
	for(int i=29;i>=0&&flag;i--)
	{
		bool xx=(x>>i)&1;
		bool kk=(k>>i)&1;
		if(kk==1)
		{
			if(son(p)[xx^kk])
			{
				p=son(p)[xx^kk];
			}
			else
			{
				flag=0;
				break;
			}
		}
		else
		{
			//free 0 or 1
			if(son(p)[xx^1])
			{
				ans=max(ans,mx(son(p)[xx^1]));
			}
			if(son(p)[xx^0])
			{
				p=son(p)[xx^0];
			}
			else
			{
				flag=0;
			}
		}
	}
	if(flag)
	{
		ans=max(ans,mx(p));
	}
	return ans;
}
int a[N];
void solve()
{
	cin>>n>>k;
	cnt=0;
	new_node();
	int ans=n+1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		//add a[i]
		add(a[i],i);
		// ask a[i]
		int l=find(a[i]);
		if(l!=-1)
		{
			ans=min(ans,i-l+1);
		}
	}
	if(ans==n+1) ans=-1;
	cout<<ans<<endl;
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
