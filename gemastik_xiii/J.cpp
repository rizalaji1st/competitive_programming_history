#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int cv1(int d, int h, int m) {
	return d * 24 * 60 + h * 60 + m;
}

void cv2(int m, int *res) {
	res[0] = m / 60 / 24;
	res[1] = (m / 60) % 24;
	res[2] = m % 60;
}

typedef struct table {
	int start;
	int end;
} table;

bool table_sort(table const& lhs, table const& rhs) {
	return lhs.start < rhs.start;
}

int main() {
	int m, s, p;
	std::cin >> m >> s;
	int target[s][2];
	for (int i = 0; i < s; i ++) {
		int day;
		std::cin >> day;
		std::string sta, end;
		std::cin >> sta >> end;
		target[i][0] = cv1(day, std::stoi(sta.substr(0, 2)), std::stoi(sta.substr(3, 2)));
		target[i][1] = cv1(day, std::stoi(end.substr(0, 2)), std::stoi(end.substr(3, 2)));
	}
	std::cin >> p;
	int write[p][2];
	for (int i = 0; i < p; i ++) {
		int day;
		std::cin >> day;
		std::string sta, end;
		std::cin >> sta >> end;
		write[i][0] = cv1(day, std::stoi(sta.substr(0, 2)), std::stoi(sta.substr(3, 2)));
		write[i][1] = cv1(day, std::stoi(end.substr(0, 2)), std::stoi(end.substr(3, 2)));
	}
	std::vector<table> list;
	for (int i = 0; i < s; i ++) {
	for (int j = 0; j < p; j ++) {
		if (target[i][0] / 24 / 60 != write[j][0] / 24 / 60)
			continue;
		int tsta[3], tend[3];
		cv2(target[i][0], tsta);
		cv2(target[i][1], tend);
		//std::cout << "#t " << tsta[0] << " " << tsta[1] << "." << tsta[2] << " " << tend[0] << " " << tend[1] << "." << tend[2];
		cv2(write[j][0], tsta);
		cv2(write[j][1], tend);
		//std::cout << " #w " << tsta[0] << " " << tsta[1] << "." << tsta[2] << " " << tend[0] << " " << tend[1] << "." << tend[2] << std::endl;
		int __sta = std::max(target[i][0], write[j][0]);
		int __end = std::min(target[i][1], write[j][1]);
		if (__end - __sta >= m) {
			table found; found.start = __sta; found.end = __end;
			list.push_back(found);
		}
	}
	}
	if (list.size() <= 0) {
		std::cout << "ikhlaskan saja" << std::endl;
	} else {
		std::sort(list.begin(), list.end(), &table_sort);
		for (size_t i = 0; i < list.size(); i ++) {
			int rsta[3], rend[3];
			cv2(list[i].start, rsta);
			cv2(list[i].end, rend);
			std::cout << rsta[0] << " "
					<< (rsta[1] < 10 ? "0" : "") << rsta[1] << "." << (rsta[2] < 10 ? "0" : "") << rsta[2] << " "
					<< (rend[1] < 10 ? "0" : "") << rend[1] << "." << (rend[2] < 10 ? "0" : "") << rend[2] << std::endl;
		}
	}
	return 0;
}
