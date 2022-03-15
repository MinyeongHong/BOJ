#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

pair<int,int> move(string s,int x,int y) {
	if(s== "R") {if (x < 7) x += 1;}
	else if(s == "L") {if (x > 0) x -= 1; }
	else if (s == "B") { if (y > 0) y -= 1; }
	else if (s == "T") {if (y < 7) y += 1; }

	else if (s == "RT") {if (x < 7 && y < 7) { x += 1; y += 1; }}
	else if (s == "LT") {if (x > 0 && y < 7) { x -= 1; y += 1; }}
	else if (s == "RB") {if (x < 7 && y > 0) { x += 1; y -= 1; }}
	else if (s == "LB") {if (x > 0 && y > 0 ) { x -= 1; y -= 1; }}

	return { x,y };
}

int main(void) {
	int board_king[9][9] = { 0 };
	int board_rock[9][9] = { 0 };
	int answer = 0;
	int n;
	pair<int, int> p,p2;
	string order;
	string king_pos, rock_pos;
	vector<pair<int, int>> idx;
	cin >> king_pos >> rock_pos >> n;
	int king_y = king_pos[1] - '0' - 1;
	int king_x = king_pos[0] - 'A';
	int rock_y = rock_pos[1] - '0' - 1;
	int rock_x = rock_pos[0] - 'A';

	board_king[king_y][king_x] = 1;
	board_rock[rock_y][rock_x] = 1;

	while (n--) {
		cin >> order;
		p = move(order, king_x, king_y);
		p2 = move(order, rock_x, rock_y);
		if (p == p2) continue;
		else {
			king_x = p.first;
			king_y = p.second;

			if (king_x == rock_x && king_y == rock_y) {

				rock_x = p2.first;
				rock_y = p2.second;

			}
		}
	}
	king_pos[0] = king_x + 'A';
	king_pos[1] = king_y + '0' + 1;
	rock_pos[0] = rock_x + 'A';
	rock_pos[1] = rock_y + '0' + 1;
	
	cout << king_pos << endl;
	cout << rock_pos << endl;
	return 0;
}
