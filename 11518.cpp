#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define pb push_back

using namespace std;

vector<int>Adj[10100];
bool vis[10100];
int cont = 0;
void DFS(int k) {
    vis[k] =1;
    cont++;
    for(auto i : Adj[k]) {
        if (!vis[i]) {
            
            DFS(i);
        }
    } 
}

int main () {
    int casos; cin >> casos;

    while (casos--) {
        int n,m,l;

        cin >> n >> m >> l;

        for (int i =1; i <= m; i++) {
            int a,b;
            cin >> a >> b;
            a--;b--;
            Adj[a].pb(b);
        }
        memset(vis,false,sizeof(vis));
        cont = 0;
        for (int i =1; i <= l; i++) {
            int k; cin >> k;k--;
            
            if(!vis[k]) {
                DFS(k);
            } 
            
        }
        
        for(int i=0; i<10100; i++)
			      Adj[i].clear();
        cout << cont << endl;
    }
}
