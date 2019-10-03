#include <iostream>
#include <fstream>
#include <string>

#define MAX 100
#define PATH 0
#define WALL 1
#define VISITED 2
#define BLOCKED 3

using namespace std;

typedef struct offset {
	int east = 0;
	int north = 0;
	int west = 0;
	int south = 0;
} Offset;


void show_maze(int maze[MAX][MAX], int N);
Offset cal_distance(int x, int y, int N, int maze[MAX][MAX]);
bool findmazepath(int x, int y, int N, int maze[MAX][MAX]);




int main() {

	ifstream file("input2.txt");
	string input;

	file >> input;
	int T = stoi(input);

	cout << "T:" << T << endl;

	for (int i = 0; i < T; i++) {
		file >> input;
		int N = stoi(input);
		cout << "N:" << N << endl;
		int maze[MAX][MAX];
		for (int i = 0; i < N; i++) // maze generation
			for (int j = 0; j < N; j++) {
				file >> input;
				maze[i][j] = stoi(input);
			}
		show_maze(maze, N);
		bool goal=findmazepath(0, 0, N, maze);
		if (goal == true)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}


}

bool findmazepath(int x , int y,int N, int maze[MAX][MAX]) {
	//cout << "current position " << "x:" << x << " y:" << y << endl;
	if (x < 0 || y < 0 || x >= N || y >= N)
		return false;
	else if (maze[y][x] != PATH)
		return false;
	else if (x == N - 1 && y == N - 1)
		return true;
	else{
		maze[y][x] = VISITED;
		
		Offset f= cal_distance(x, y, N, maze);
		
		//cout <<"Offset:" << " E: "<<f.east<< " N: " << f.north << " S: " << f.south <<" W: "<< f.west << endl;
		if (findmazepath(x + f.east, y, N, maze) || findmazepath(x, y - f.north, N, maze) || findmazepath(x - f.west, y, N, maze) || findmazepath(x, y + f.south, N, maze))
			return true;
		maze[x][y] = BLOCKED;
		return false;
	}
	
	
}

Offset cal_distance(int x, int y, int N, int maze[MAX][MAX]) {
	Offset f;
	
	while (maze[y ][x + f.east+1] != WALL && (x + f.east )<(N-1))
		f.east++;
	while (maze[y - f.north-1][x] != WALL && (y - f.north)>0)
		f.north++;
	while (maze[y ][x - f.west-1] != WALL && (x - f.west)>0)
		f.west++;
	while (maze[y + f.south+1][x] != WALL && (y + f.south)<(N-1))
		f.south++;
	
	return f;
}


void show_maze(int maze[MAX][MAX], int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << maze[i][j];
		cout << endl;
	}

}
