#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define endl '\n'


int n;
int m;
char oil[150][150];
bool vis[150][150];
int linha[8] =  {1,0,-1,0,1,1,-1,-1};
int coluna[8] = {0,1,0,-1,1,-1,-1,1};

void zerar() {
    for (int i =0; i < 150; i++) {
        for (int j = 0; j < 150; j++) {
            vis[i][j] = 0;
        }
    }
}
int conta;

void floodfill(int x, int y, int n, int m) {
    conta++;
    vis[x][y] = 1;
    for(int i= 0; i < 8;i++) {
        int nx = x+linha[i], ny = y+coluna[i];
        if(nx >= 0 and nx < n and ny >= 0 and ny < m and !vis[nx][ny]) {
            if(oil[nx][ny] == '*') {
                conta++;
                floodfill(nx,ny,n,m);
            }
        }
    }
    
}


int main () {

    int n,m;
    while(cin >> n >> m and n != 0 and m != 0) {
        for (int i =0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> oil[i][j];
            }
        }
        conta = 0;
        int cont = 0;
        for (int i =0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (oil[i][j] == '*' and !vis[i][j]) {
                    floodfill(i,j,n,m);
                    if(conta ==1) cont++;
                    conta = 0;
                }
            }
        }
        zerar();
        cout << cont << endl;
    }
}
