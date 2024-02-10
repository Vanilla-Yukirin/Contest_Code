#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>

using namespace std;

const int MAXN = 10000; // 最大顶点数
vector<pair<int, int>> adj[MAXN]; // 邻接表，存储边和边权
bool visited[MAXN]; // 访问标记数组
stack<int> st; // 存储当前路径的栈
int minWeight = numeric_limits<int>::max(); // 最小边权初始化为最大值
vector<int> minCycle; // 存储最小边权的环

void dfs(int u, int parent) {
	visited[u] = true;
	st.push(u);
	
	for (auto &edge : adj[u]) {
		int v = edge.first;
		int weight = edge.second;
		
		if (v == parent) continue; // 忽略到父节点的边
		if (visited[v] && st.size() > 2) {
			// 找到一个环
			vector<int> cycle;
			int cycleMinWeight = numeric_limits<int>::max();
			bool isCycle = false;
			
			for (stack<int> tmp = st; !tmp.empty(); tmp.pop()) {
				int w = tmp.top();
				cycle.push_back(w);
				if (w == v) {
					isCycle = true;
					break;
				}
			}
			
			if (isCycle) {
				// 遍历环，更新环内最小边权
				for (int i = 0; i < cycle.size(); ++i) {
					int cur = cycle[i];
					int next = cycle[(i + 1) % cycle.size()];
					for (auto &e : adj[cur]) {
						if (e.first == next) {
							cycleMinWeight = min(cycleMinWeight, e.second);
							break;
						}
					}
				}
				
				if (cycleMinWeight < minWeight) {
					minWeight = cycleMinWeight;
					minCycle = cycle;
				}
			}
		} else if (!visited[v]) {
			dfs(v, u);
		}
	}
	
	st.pop();
}

int main() {
	int n, m;
	cin >> n >> m; // 读取顶点数和边数
	
	for (int i = 0; i < m; ++i) {
		int u, v, x;
		cin >> u >> v >> x; // 读取每条边的两个顶点和边权
		adj[u].push_back({v, x});
		adj[v].push_back({u, x}); // 因为是无向图，所以需要添加两次
	}
	
	fill(visited, visited + n, false); // 初始化访问标记数组
	
	// 遍历每个顶点，寻找环
	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			dfs(i, -1);
		}
	}
	
	if (minCycle.empty()) {
		cout << "No cycle found." << endl;
	} else {
		cout << "Minimum edge weight in the cycle: " << minWeight << endl;
		cout << "Cycle: ";
		reverse(minCycle.begin(), minCycle.end()); // 反转，因为栈是LIFO
		for (int v : minCycle) {
			cout << v << " ";
		}
		cout << endl;
	}
	
	return 0;
}

