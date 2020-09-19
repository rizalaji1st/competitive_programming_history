#include <iostream>
#include <string>
#include <queue>

typedef struct ij {
	int i, j;

	bool equal(ij a) {
		return this->i == a.i && this->j == a.j;
	}
} ij;

bool check(char c) {
	if (c == '-' || c == '|' || c == 'x')
		return false;
	return true;
}

int main() {
	int p, l;
	std::cin >> p >> l;
	std::string tempstr;
	std::getline(std::cin, tempstr);
	std::string M[p];
	ij C, D;
	for (int i = 0; i < p; i ++) {
		std::getline(std::cin, M[i]);
		for (int j = 0; j < l; j ++) {
			if (M[i][j] == 'C') { C.i = i; C.j = j; }
			if (M[i][j] == 'D') { D.i = i; D.j = j; }
		}
	}
	// Dawala mengejar Cepot
	bool visited[p + 1][l] = {false};
	visited[D.i + 1][D.j] = true;
	std::queue<ij> Q;
	Q.push(D);
	bool found = false;
	while (!Q.empty()) {
		ij cur = Q.front(); Q.pop();
		if (cur.equal(C)) {
			found = true;
			break;
		} else {
			if (cur.i > 0) {
				if (!visited[cur.i - 1 + 1][cur.j] && check(M[cur.i - 1][cur.j])) {
					visited[cur.i - 1 + 1][cur.j] = true;
					ij top; top.i = cur.i - 1; top.j = cur.j;
					Q.push(top);
				}
			}
			if (cur.i < p - 1) {
				if (!visited[cur.i + 1 + 1][cur.j] && check(M[cur.i + 1][cur.j])) {
					visited[cur.i + 1 + 1][cur.j] = true;
					ij bottom; bottom.i = cur.i + 1; bottom.j = cur.j;
					Q.push(bottom);
				}
			}
			if (cur.j > 0) {
				if (!visited[cur.i + 1][cur.j - 1] && check(M[cur.i][cur.j - 1])) {
					visited[cur.i + 1][cur.j - 1] = true;
					ij left; left.i = cur.i; left.j = cur.j - 1;
					Q.push(left);
				}
			}
			if (cur.j < l - 1) {
				if (!visited[cur.i + 1][cur.j + 1] && check(M[cur.i][cur.j + 1])) {
					visited[cur.i + 1][cur.j + 1] = true;
					ij right; right.i = cur.i; right.j = cur.j + 1;
					Q.push(right);
				}
			}
		}
	}
	if (found) {
		std::cout << "Dawala bertemu Cepot" << std::endl;
	} else {
		std::cout << "Dawala tidak bertemu Cepot" << std::endl;
	}
	// Cepot berusaha kabur
	bool visited2[p + 1][l] = {false};
	visited2[C.i + 1][C.j] = true;
	std::queue<ij> Q2;
	Q2.push(C);
	bool found2 = false;
	while (!Q2.empty()) {
		ij cur = Q2.front(); Q2.pop();
		if (cur.i <= 0 || cur.i >= p - 1 || cur.j <= 0 || cur.j >= l - 1) {
			found2 = true;
			break;
		} else {
			if (cur.i > 0) {
				if (!visited2[cur.i - 1 + 1][cur.j] && check(M[cur.i - 1][cur.j])) {
					visited2[cur.i - 1 + 1][cur.j] = true;
					ij top; top.i = cur.i - 1; top.j = cur.j;
					Q2.push(top);
				}
			} else {
				found2 = true;
				break;
			}
			if (cur.i < p - 1) {
				if (!visited2[cur.i + 1 + 1][cur.j] && check(M[cur.i + 1][cur.j])) {
					visited2[cur.i + 1 + 1][cur.j] = true;
					ij bottom; bottom.i = cur.i + 1; bottom.j = cur.j;
					Q2.push(bottom);
				}
			} else {
				found2 = true;
				break;
			}
			if (cur.j > 0) {
				if (!visited2[cur.i + 1][cur.j - 1] && check(M[cur.i][cur.j - 1])) {
					visited2[cur.i + 1][cur.j - 1] = true;
					ij left; left.i = cur.i; left.j = cur.j - 1;
					Q2.push(left);
				}
			} else {
				found2 = true;
				break;
			}
			if (cur.j < l - 1) {
				if (!visited2[cur.i + 1][cur.j + 1] && check(M[cur.i][cur.j + 1])) {
					visited2[cur.i + 1][cur.j + 1] = true;
					ij right; right.i = cur.i; right.j = cur.j + 1;
					Q2.push(right);
				}
			} else {
				found2 = true;
				break;
			}
		}
	}
	if (found2) {
		std::cout << "ada jalan Cepot lumpat" << std::endl;
	} else {
		std::cout << "tidak ada jalan Cepot lumpat" << std::endl;
	}
	return 0;
}
