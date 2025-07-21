#include<bits/stdc++.h>

using namespace std;

int main() {
	cout << "Framing Methods: Byte Stuffing"<< endl;
	cout << "**********************************" << endl;
	
	string FLAG = "FLAG";
	string ESC = "ESC";
	
	string seq;
	cout << "Enter the string: " << endl;
	cin >> seq;
	int flag_count = 0;
	vector<string> payload;
	int i = 0, j;
	cout << flag_count << endl;
	for(i = 0; i < seq.length(); i++) {
		if(seq.substr(i, 4) == FLAG && flag_count == 0) {
			j = i + 4;
			flag_count++;
			cout << flag_count << endl;
			while(seq.substr(j, 4) != FLAG && j < seq.length()) {
				cout << j << endl;
				if(seq.substr(j, 3) == ESC) {
					j = j + 3;
					if(seq.substr(j, 3) == ESC) {
						payload.push_back(ESC);
						j += 3;
					}
					else if(seq.substr(j, 4) == FLAG) {
						payload.push_back(FLAG);
						j += 4;
					}
				}
				else {
					payload.push_back("" + seq[j]);
					j++;
				}
			}
			i = j;
			cout << i << endl;
			if(seq.substr(i, 4) == FLAG)
				break;
		}
	}

	for(i = 0; i < payload.size(); i++){
		cout << payload[i];
	}
	cout << endl;
}
