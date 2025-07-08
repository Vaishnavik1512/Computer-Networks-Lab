#include<bits/stdc++.h>

using namespace std;

int main() {
	cout << "Framing Methods: Character Count" << endl;
	cout << "***********************************" << endl;
	int n;
	cout << "Enter length of the sequence" << endl;
	cin >> n;
	cout << "Enter the elements of the payload: " << endl;
	vector<int> arr;
	for(int i = 0; i < n; i++) {
		int ele;
		cin >> ele;
		arr.push_back(ele);
	}

	int p1 = 0, i, frame_count = 1;
	cout << "Frames: " << endl;
	while(p1 < arr.size()) {
		int size = arr[p1];
		cout << "frame " << frame_count << ": ";
		for(i = p1;  i < p1 + size; i++) {
			if(i >= n) cout << "_" << " ";
			else cout << arr[i] << " ";
		}
		cout << endl;
		frame_count++;
		p1 = i;
	}
	
}
