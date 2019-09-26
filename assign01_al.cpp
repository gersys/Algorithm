#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int complex_N(int* arr, int start, int end);
int* pre_processing(int* arr, int len, int M);
int complex_root_N(int* arr, int* arr_M, int start, int end, int M);

int main() {
	
	ifstream file("data.txt");
	string input;
	int* arr;
	int* arr_M;
	int len = 0;
	int start, end;
	int M;
	
	file >> input;

	arr = (int*)malloc(stoi(input) * sizeof(int));


	while (file) {
		file >> input;
		arr[len] = stoi(input);
		len++;
	}
	int min = 0;
	M = sqrt(len);

	arr_M=pre_processing(arr, len,M);
	cin >> start;
	cin >> end;
	min = complex_root_N(arr, arr_M, start, end, M);
	cout << "min: " << min << endl;

	return 0;

}

int complex_root_N(int*arr, int* arr_M, int start, int end,int M) {
	int arr_total[300];
	int len;
	int min;
	int i = 0;

	int test_len = 0;


	for (int j = start; j < (start / M + 1) * M; j++) {
		arr_total[i] = arr[j];
		i++;
	}



	for (int j = start / M + 1; j < end / M; j++) {
		arr_total[i] = arr_M[j];
		i++;
	}

	for (int j = (end / M) * M; j < end; j++) {
		arr_total[i] = arr[j];
		i++;
	}

	len = i;

	min = complex_N(arr_total, 0, len);



	return min;

}

int complex_N(int* arr, int start, int end) {
	int min = arr[0];

	for (int i = start; i < end; i++)
		if (min > arr[i])
			min = arr[i];

	return min;
}

int* pre_processing(int* arr, int len,int M) {


	int* arr_M;
	arr_M = (int*)malloc(M * sizeof(int));
	cout << "M: " << M << endl;

	for (int i = 0; i < (len / M); i++)
		arr_M[i]=complex_N(arr, (0 + M * i), (M * (i + 1) - 1));


	return arr_M;
}