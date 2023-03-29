#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define endl '\n'

int n;
int m;
char world[150][150];
bool vis[150][150];
int linha[4] =  {1,0,-1,0};
int coluna[4] = {0,1,0,-1};

void zerar() {
    for (int i =0; i < 150; i++) {
        for (int j = 0; j < 150; j++) {
            vis[i][j] = 0;
        }
    }
}

bool visitou(int n, int m) {
    for (int i =0; i < n; i++) {
        for (int j = 0; j < m; j++) {
           if(!vis[i][j]) return false;
        }
    }
    return true;
}

void floodfill(int x, int y, int n, int m,char a) {
    vis[x][y] = 1;
    for(int i= 0; i < 4;i++) {
        int nx = x+linha[i], ny = y+coluna[i];
        if(nx >= 0 and nx < n and ny >= 0 and ny < m and !vis[nx][ny]) {
            if(world[nx][ny] == a) {
                floodfill(nx,ny,n,m,a);
            }
        }
    }
}

template <typename K, typename V>
multimap<V, K,greater<V>>

invertMap(map<K,V> const& myMap) //Função que inverte o map da porcentagem dos estados para imprimir as porcentagens em ordem crescente
{
    multimap<V,K,greater<V>>mapa;

    for (auto const& pair : myMap) {
        mapa.insert(make_pair(pair.second,pair.first));
    }
    return mapa;
}

int main () {
    int n,m;
    int casos; cin >> casos;
    int k = 0;
    while(casos--) {
        k++;
        cin >> n >> m;
        for (int i =0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> world[i][j];
            }
        }
        cout << "World #" << k << endl;
        char a;
        map<char,int>mp;
        while(!visitou(n,m)) {
            for (int i =0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (!vis[i][j]) {
                        a = world[i][j];
                        floodfill(i,j,n,m,a);
                        mp[a] +=1;
                    }
                }
            }
        }
        zerar();
        multimap<int,char,greater<int>>mapa = invertMap(mp);
        for(auto it : mapa) cout << it.second << ": " << it.first << endl;
    }
}
