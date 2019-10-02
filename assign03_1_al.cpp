#include<iostream>
#include<fstream>
#include<string>

using namespace std;

#define Searched 2;

void show_maze(int maze[10][10], int N);
int search_path(int maze[10][10], int N,int K,int x , int y);

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
		int x = 0; //definite starting point 
		int y = 0;
		int num=search_path(maze, N,K,x,y);
		cout << num << endl;
	}
}

int search_path(int maze[10][10], int N,int K,int x, int y) {
	maze[y][x] = Searched; // Mark current position as 'Searched'
	x, y = next_pos(maze, x, y , N);

	
	return 1;
}

int next_pos(int maze[10][10], int x , int y, int N) {
	// Sequace: N,E,S,W
	if (y > 0 && maze[y - 1][x] == 0) //N
		return x, y - 1;
	else if (x < N && maze[y][x+1] == 0) //E
		return x+1, y;
	else if (y < N && maze[y+1][x] == 0) //S
		return x , y+1;
	else if (y < N && maze[y][x-1] == 0) //W
		return x-1, y;

}

void show_maze(int maze[10][10], int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << maze[i][j];
		cout << endl;
	}
			
}