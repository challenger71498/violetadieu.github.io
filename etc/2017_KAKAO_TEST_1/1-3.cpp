#include<iostream>
#include<list>
#include<string>

using namespace std;

int main() {

	string cache[30];
	string cities[100];
	int cachesize = 0;
	int time=0;
	int i = 0;
	string tmp;

	cin >> cachesize;

	while (1) {
		if (cities[i-1] == "Q"||cities[i-1]=="q")// Q==�Է� �ߴ�
			break;
		else
			cin >> cities[i];

		i++;
	}

	if (cachesize == 0) {//cache �� ũ�Ⱑ 0�� ���
		time = (i-1) * 5;
		cout << time << endl;
		return 0;
	}

	cachesize--;

	for (int k = 0; k < (i - 1); k++) {
		//ĳ�ÿ� ���� �ִ� ���
		for (int p = 0; p <= cachesize; p++) {
			if (cache[p] == cities[k]) {
				time = time + 1;
				for (int m = p; m < cachesize-1; m++) {
					cache[m] = cache[m + 1];
				}
			}
		}
		//���� ���
		string *f = find(begin(cache), end(cache), cities[k]);
		if (f == end(cache)){
			time = time + 5;
			for (int t = 0; t <= cachesize; t++) {
				cache[t] = cache[t + 1];
			}
		}
		cache[cachesize] = cities[k];
	}

	cout << time << endl;
	return 0;
}