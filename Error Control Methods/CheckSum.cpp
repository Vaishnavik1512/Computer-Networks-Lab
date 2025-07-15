#include<bits/stdc++.h>

using namespace std;

vector<int> binary_add(vector<int> &bin1, vector<int> &bin2) {
	vector<int> ans(bin1.size());
	int sum = 0, carry = 0;

	for(int i = bin1.size() - 1; i >= 0; i--) {
		if(bin1[i] == 0 && bin2[i] == 0) {
			ans[i] = carry;
			carry = 0;
		}
		else if((bin1[i] == 0 && bin2[i] == 1) || (bin1[i] == 1 && bin2[i] == 0)) {
			if(carry == 0) ans[i] = 1;
			else {
				ans[i] = 0;
				carry = 1;
			}
		}
		else {
			if(carry == 0) {
				ans[i] = 0;
				carry = 1;
			}	
			else {
				ans[i] = 1;
				carry = 1;
			}
		}
	}

	if(carry == 1) {
		for(int i = ans.size() - 1; i >= 0; i--) {
			if(ans[i] == 0) {
				ans[i] = 1;
				carry = 0;
				break;
			}
			else {
				ans[i] = 0;
				carry = 1;
			}
		}
	}

	return ans;
}

vector<int> ones_complement(vector<int> &bin) {
	vector<int> ans(bin.size());

	for(int i = 0; i < bin.size(); i++) {
		if(bin[i] == 0) ans[i] = 1;
		else ans[i] = 0;
	}
	return ans;
}

int main() {
	cout << "Error Control Methods: Check Sum" << endl;
	cout << "**************************************" << endl;
	
	int rows, cols;
	cout << "Enter No of rows and columns: ";
	cin >> rows >> cols;

	vector<vector<int>> send(rows, vector<int>(cols));
	cout << "Enter sender data: ";
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			cin >> send[i][j];
		}
	}

	vector<vector<int>> receive(rows, vector<int>(cols));
	cout << "Enter receiver data: ";
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			cin >> receive[i][j];
		}
	}
	
	vector<int> send_sum;
	if(send.size() > 1) {
		send_sum = binary_add(send[0], send[1]);
		for(int i = 2; i < send.size(); i++) {
			send_sum = binary_add(send_sum, send[i]);
		}
	}
	send_sum = ones_complement(send_sum);
	
	vector<int> receive_sum;
	if(receive.size() > 1) {
		receive_sum = binary_add(receive[0], receive[1]);
		for(int i = 2; i < receive.size(); i++) {
			receive_sum = binary_add(receive_sum, receive[i]);
		}
	}
        
	int flag = 0;
	vector<int> check_msg;
	for(int i = 0; i < send_sum.size(); i++) {
		if(send_sum[i] + receive_sum[i] != 1) {
			flag = 1; 
                        break;
		}
	}
	if(flag == 1)
		cout << "Error in the received message." << endl;
	else
		cout << "Received message is correct." << endl;
}
