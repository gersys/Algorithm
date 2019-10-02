#include<iostream>
#include<fstream>
#include<string>
#include<stack>

using namespace std;

#define Searched 2
#define NORTH 3
#define EAST 4
#define SOUTH 5
#define WEST 6

void show_maze(int maze[10][10], int N);
int search_path(int maze[10][10], int N,int K);
bool next_pos(int maze[10][10],int N);
void put_back(int prev);

int x = 0; //definite starting point
int y = 0;
int num = 0;

stack<int> s;

int main() {
	ifstream file("input1.txt");
	string input;

	file >> input; // T

	int T = stoi(input);

	cout << "T:" << T << endl;

	for (int i = 0; i < T; i++) {
		file >> input;
		const int N = stoi(input); // N
		int maze[10][10];
		for(int i =0 ; i <N ; i++) // maze generation
			for (int j = 0; j < N; j++) {
				file >> input;
				maze[i][j] = stoi(input);
			}
		show_maze(maze, N); // Check if the maze generation was done well 

		file >> input;
		int K = stoi(input); // K
		int num=search_path(maze, N,K);
		cout << num << endl;
	}
}

int search_path(int maze[10][10], int N,int K) {
	maze[y][x] = Searched; // Mark current position as 'Searched'
	bool possible=next_pos(maze, N);
	cout << "x:" << x << "y:" << y << endl;
	cout << "num:" << num << endl;
	show_maze(maze, N);
	cout << "------------------------" << endl;

	if (possible == false) {
		cout << "there is a no way to go" << endl;
		int prev = s.top();
		s.pop();
		put_back(prev);
	}
	num++; // num of move ++
		

	int num = search_path(maze, N, K);

	
	return 1;
}

void put_back(int prev) {
	if (prev == NORTH) {
		num--;
		y++;
	}
	else if (prev == EAST) {
		num--;
		x--;
	}
	else if (prev == SOUTH) {
		num--;
		y--;
	}
	else if (prev == WEST) {
		num--;
		x++;
	}

}

bool next_pos(int maze[10][10],int N) {
	// Sequace: N,E,S,W
	if (y > 0 && maze[y - 1][x] == 0) { //N
		y--;
		s.push(NORTH);
		return true;
	}
	else if (x < N && maze[y][x + 1] == 0) {//E
		x++;
		s.push(EAST);
		return true;
	}
	else if (y < N && maze[y + 1][x] == 0) { //S
		y++;
		s.push(SOUTH);
		return true;
	}
	else if (x < 0 && maze[y][x - 1] == 0) {//W
		x--;
		s.push(WEST);
		return true;
	}
	else
		return false;
}

void show_maze(int maze[10][10], int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << maze[i][j];
		cout << endl;
	}
			
}