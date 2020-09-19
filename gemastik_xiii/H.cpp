#include <iostream>

int main() {
	long N, M, Q;
	std::cin >> N >> M >> Q;
	long A[N][M];
	long sum[N][M];
	for (long i = 0; i < N; i ++) {
		std::cin >> A[i][0];
		sum[i][0] = A[i][0];
		for (long j = 1; j < M; j ++) {
			std::cin >> A[i][j];
			sum[i][j] = sum[i][j - 1] + A[i][j];
		}
	}
	long x1, y1, x2, y2, res;
	while (Q --) {
		std::cin >> x1 >> y1 >> x2 >> y2;
		x1 --; y1 --; x2 --; y2 --;
		res = 0;
		for (long i = x1; i <= x2; i ++) {
			if (y1 <= 0)
				res += sum[i][y2];
			else
				res += sum[i][y2] - sum[i][y1 - 1];
		}
		std::cout << res << std::endl;
	}
	return 0;
}
