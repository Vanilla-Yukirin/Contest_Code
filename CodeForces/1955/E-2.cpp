/**************************************************************
 * Problem: 
 * Author: Vanilla_chan
 * Date: 
 * E-Mail: heshaohong2015@outlook.com
 **************************************************************/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<limits.h>
#define IL inline
#define re register
#define LL long long
#define ULL unsigned long long
#ifdef TH
#define debug printf("Now is %d\n",__LINE__);
#else
#define debug
#endif
#ifdef ONLINE_JUDGE
char buf[1<<23],* p1=buf,* p2=buf,obuf[1<<23],* O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#endif
using namespace std;



#define int long long
#define endl "\n"

const int inf = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
int n, a[N], f[N]; // f[i]  (i, i + k - 1)  (j+1-k, j-1)

void solve() {
	cin >> n;

	string str;cin>>str;
	for(int i=1;i<=n;i++) a[i]=str[i-1]-'0';
	int ansk = 1, ansm = inf;
	for(int k = 1; k <= n; k++){
		
		int sum = 0, cnt = 0;
		bool flag = true;
		for(int i = 0; i <= n; i++) f[i] = 0;
		
		for(int i = 1; i <= n + 1 - k; i++){
			int beg = i + 1 - k, ed = i - 1;
			if(beg - 1) sum -= f[beg - 1];
			sum += f[ed];
			if((sum&1) == (a[i]&1)) f[i] = 1, cnt++;
			else f[i] = 0;
		}
		for(int i = n + 2 - k; i <= n; i++){
			int beg = i + 1 - k, ed = i - 1;
			if(beg - 1) sum -= f[beg - 1];
			sum += f[ed];
			if((sum&1) == (a[i]&1)) flag = false;
		}
		
		if(flag){
			ansk = k;
		}
	}
	cout << ansk << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
