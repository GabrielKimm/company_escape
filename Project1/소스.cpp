#include <iostream>
using namespace std;

struct Array {
	int T;
	int P;
};
Array* arr;
int max_score = 0;
int n;

void calc(int cur, int score);
void recursion(int cur, int score);

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
	for (int i = 0; i < n; i++) {
		calc(i + arr[i].T, arr[i].P);
	}
	cout << max_score;
}

void calc(int cur, int score) {
	for (cur; cur < n; cur++) {
		if (arr[cur].T == 1) {
			score += arr[cur].P;
		}
		else {
			recursion(cur, score);
		}
	}
	recursion(cur, score);
}

void recursion(int cur, int score) {
	if (cur + arr[cur].T > n || cur > n - 1) {
		if (cur > n) {
			return;
		}
		if (score > max_score) {
			max_score = score;
		}
		return;
	}
	else {
		recursion(cur + arr[cur].T, score + arr[cur].P);
	}
}