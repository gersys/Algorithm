#include<iostream>
#include<fstream>
#include<string>

using namespace std;

#define Searched 2;

void show_maze(int maze[10][10], int N);
int search_path(int maze[10][10], int N,int K);
void next_pos(int maze[10][10],int N);

int x = 0; //definite starting point
int y = 0;

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
	next_pos(maze, N);
	cout << "x:" << x << "y:" << y << endl;
	show_maze(maze, N);
	cout << "------------------------" << endl;

	if (x == -1 && y == -1)
		return -1;

	int num = search_path(maze, N, K);

	
	return 1;
}

void next_pos(int maze[10][10],int N) {
	// Sequace: N,E,S,W
	if (y > 0 && maze[y - 1][x] == 0) { //N
		y--;
		return;
	}
	else if (x < N && maze[y][x + 1] == 0) {//E
		x++;
		return;
	}
	else if (y < N && maze[y + 1][x] == 0) { //S
		y++;
		return;
	}
	else if (x < 0 && maze[y][x - 1] == 0) {//W
		x--;
		return;
	}
	else
		return;
}

void show_maze(int maze[10][10], int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << maze[i][j];
		cout << endl;
	}
			
}