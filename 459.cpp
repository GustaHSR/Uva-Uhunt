#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define f fisrt
#define s second

vector<int>adj[10100];
bool vis[10100];

void DFS(int k) {
	vis[k] = 1;
	for(auto i: adj[k]) {
		if(!vis[i]) {
			DFS(i);
		}
	}
}

int main(){
	ll casos;
	cin >> casos;
	string line;
	getline(cin, line);

	while(casos--) {
		ll cont;
		
		char a;
		cin >> a;
		cont = 0;
		cin.ignore();
		while(getline(cin, line) and line != "\0") {
			adj[line[0]-65].pb(line[1]-65);
			adj[line[1]-65].pb(line[0]-65);
		}
		for (int j = 0; j <= a-65;j++) {
			if(!vis[j]) {
				DFS(j);
				cont++;
			}
		}
		memset(vis,0,sizeof(vis));
		for (int i = 0; i < 10100; i++) {
		    adj[i].clear();
		}
		cout << cont << endl << endl;
		
	}
}
