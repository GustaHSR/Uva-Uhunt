#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define f fisrt
#define s second

class Player {
	private:
		int forca,inteligencia,resistencia,poder;
	public:
		Player(int,int,int,int);
		virtual ~Player();
		int getForca();
		int getInteligencia();
		int getResistencia();
		int getPoder();
		bool operator>(Player & player);
		friend 	ostream &operator<< (ostream &saida, Player &player);
};

Player::Player(int strenght, int intel, int resis, int poder) {
	forca = strenght;
	inteligencia = intel;
	resistencia = resis;
	poder = getPoder();
}
Player::~Player() {
}
int Player::getForca() {
	return forca;
}
int Player::getInteligencia() {
	return inteligencia;
}
int Player::getResistencia() {
	return resistencia;

}
int Player::getPoder() {
	return (forca*3)+(inteligencia*4)+(resistencia*2);
}
bool Player::operator>(Player &player) {
	if(getPoder()>player.getPoder()) {
		return true;
	}
	return false;
}
ostream &operator << (ostream &saida, Player &player) {
	saida << "Força: " << player.getForca() << endl;
	saida << "Inteligencia: " << player.getInteligencia() << endl;
	saida << "Resistencia: " << player.getResistencia() << endl;
	saida << "\nPoder Total: " << player.getPoder() << endl;
	saida << endl;
	return saida;
}

int main(){
    srand(time(NULL));
	Player a1(rand()%100+1,rand()%100+1,rand()%100+1,a1.getPoder());
	Player a2(rand()%100+1,rand()%100+1,rand()%100+1,a2.getPoder());

	cout << "Player1: " << endl;;
	cout << a1 << endl;
	cout << "\nPLayer2: " << endl;
	cout << a2 << endl;

	if(a1 > a2) {
		cout << "p1 Wins!" << endl;
	}
	else {
		cout << "p2 Wins!" << endl;
	}
}
