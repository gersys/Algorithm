#include<iostream>
#include<fstream>
#include<string>

using namespace std;

#define MAX 16
#define PATH 0
#define WALL 1
#define VISITED 2
#define BLOCKED 3


int num = 0;
int sol=0;

void show_maze(int maze[10][10], int N);
int findMazePath(int x, int y, int N, int K, int maze[10][10], int dist);


int main() {

	ifstream file("input1.txt");
	string input;


	file >> input; // T

	int T = stoi(input);
	int x = 0;
	int y = 0;


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
		cout << "---------------------------" << endl;

		file >> input;
		int K = stoi(input); // K
		sol=findMazePath(0, 0, N, K, maze,0);
		show_maze(maze, N);
		cout << "---------------------------" << endl;
		cout << "sol:" <<sol << endl;
	}

	return 0;
}

int findMazePath(int x, int y,int N,int K, int maze[10][10],int dist) {
	int sum = 0;
	if (x < 0 || y < 0 || x >= N || y >= N)
		return 0;
	else if (dist > K)
		return 0;
	else if (maze[x][y] != PATH)
		return 0;
	else if (x == N - 1 && y == N - 1) {
		maze[x][y] = PATH;
		return 1;
	}
	else {
		maze[x][y] = VISITED;
		sum += findMazePath(x - 1, y, N,K, maze, dist + 1) + findMazePath(x, y - 1, N, K, maze, dist + 1) + findMazePath(x + 1, y, N, K, maze, dist + 1) + findMazePath(x, y + 1, N, K, maze, dist + 1);
		if (sum > 0) {
			maze[x][y] = PATH;
			return sum;
		}
		maze[x][y] = PATH;
		return 0;
	}

}

void show_maze(int maze[10][10], int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << maze[i][j];
		cout << endl;
	}

}
