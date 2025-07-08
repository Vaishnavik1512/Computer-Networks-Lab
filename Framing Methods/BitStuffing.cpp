#include<bits/stdc++.h>
using namespace std;
int main() {
	string payload;
	cin >> payload;
	int i = 0;
	int j = 0;
	int count = 0;
	for(int i = 0; i < payload.size(); i++) {
		cout << payload[i];
		if(payload[i] == '1') count++;
		else {
			count = 0;
		} 
		if(count == 5) {
			cout << '0';
			count = 0;
		}
	}
}
