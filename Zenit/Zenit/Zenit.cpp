#include <iostream>

using namespace std;

struct kon {
	int bezR;
	int sR;
	string smutko;

	int plusPodkovy;
};

int main() {
	int n, vel;
	cin >> n >> vel;

	if (n <= 0) return 1;

	if (vel > 100 || vel < 1) {
		cout << "Neda sa";
		return 0;
	}

	kon cowboy[n];

	float avgHappy = 0;
	float max = 0;

	for (int i = 0; i < n; i++) {
		cin >> cowboy[i].bezR >> cowboy[i].sR >> cowboy[i].smutko;
		cowboy[i].plusPodkovy = cowboy[i].sR - cowboy[i].bezR;

		if (cowboy[i].smutko == "nie") {
			if (cowboy[i].sR > cowboy[i].bezR) {
				avgHappy += cowboy[i].sR;
			}
			else {
				avgHappy += cowboy[i].bezR;
			}
		}
		else {
			avgHappy += cowboy[i].bezR;
		}

		max += (cowboy[i].sR > cowboy[i].bezR ? cowboy[i].sR : cowboy[i].bezR);
	}


	cout << endl << endl;

	for (int i = 0; i < n; i++) {
		cout << cowboy[i].bezR << endl;
		cout << cowboy[i].sR << endl;
		cout << cowboy[i].smutko << endl;
		cout << cowboy[i].plusPodkovy << endl;
		cout << endl;
	}

	cout << endl;

	avgHappy /= n;
	max /= n;

	if (max < vel) {
		cout << "Neda sa";
		return 0;
	}

	int poradie[n] = {};
	int pos;

	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			if (poradie[j] < cowboy[i].plusPodkovy || cowboy[i].smutko == "ano") {
				poradie[j] = cowboy[i].plusPodkovy;
				pos = i;
			}
		}
		cowboy[pos].plusPodkovy = 0;
		cout << poradie[j] << " ";
	}

	cout << endl << "-----------------------------------" << endl;

	int count = 0;

	while (true) {
		if (avgHappy >= vel) {
			cout << count;
			break;
		}
		else {
			avgHappy += (poradie[count] / n);
			poradie[count] = 0;
			count++;
		}
	}



	return 0;
}