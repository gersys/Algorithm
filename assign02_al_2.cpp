#include <iostream>

using namespace std;

int floor(int* data, int N, int K, int start, int end);
int ceiling(int* data, int N, int K, int start, int end);

int main() {
	int K, N;
	int data[100];

	cin >> N;

	for (int i = 0; i < N ; i++)
		cin >> data[i];

	cin >> K;
	
	int start = 0;
	int end = N;

	int f = floor(data, N, K, start, end);
	int c = ceiling(data, N, K, start, end);
	
	cout << "floor :" << f << endl;
	cout << "ceiling :" << c << endl;

}

int floor(int* data, int N, int K, int start, int end) {
	// K보다 작거나 같으면서 가장 큰 정수를 찾는 함수 floor

	int center = (start + end) / 2;
	/*cout << "start: " << start << endl;
	cout << "end: " << end << endl;
	cout << "center: " << center << endl;*/
	if (abs(end - start) <= 1)
		return data[center];
	if (data[start] > K)
		return -1;
	if (data[N - 1] > K)
		if (data[center] > K) {
			end = center;
			floor(data, N, K, start, end);
		}
		else if (data[center] < K) {
			start = center;
			floor(data, N, K, start, end);
		}
		else
			return data[center];
	else
		return data[N - 1];

}

int ceiling(int* data, int N, int K, int start, int end) {
	// K보다 크거나 같으면서 가장 작은 정수를 찾는 함수 ceiling
	int center =(start + end+1) / 2;
	/*cout << "start: " << start << endl;
	cout << "end: " << end << endl;
	cout << "center: " << center << endl;*/
	if (abs(end - start) <= 1)
		return data[center];
	if (data[N - 1] < K)
		return -1;
	if (data[0] < K)
		if (data[center] > K) {
			end = center;
			ceiling(data, N, K, start, end);
		}
		else if (data[center] < K) {
			start = center;
			ceiling(data, N, K, start, end);
		}
		else
			return data[center];

	else
		return data[N - 1];

}