#include <iostream>
using namespace std;

struct Array {
	int T;
	int P;
};
Array* arr;
//int score = 0;
int max_score = 0;
int tmp_score = 0;
int n;



int main() {

	scanf("%d", &n);
	if (n < 1 || n>15) {
		cout << "Exception Occurred" << endl;
		return 0;
	}

	arr = (Array*)malloc(sizeof(Array) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i].T);
		scanf("%d", &arr[i].P);
	}



	cout << endl << max_score << endl;

}