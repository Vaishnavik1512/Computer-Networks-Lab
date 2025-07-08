#include<bits/stdc++.h>

using namespace std;

int main() {
	cout << "Error Control Methods: 2D Parity Check" << endl;
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

	vector<int> send_row_parity(rows);
	vector<int> send_col_parity(cols);

	vector<int> receive_row_parity(rows);
	vector<int> receive_col_parity(cols);
	
	int send_count, receive_count;

	// Finding row parity
	for(int i = 0; i < rows; i++) {
		send_count = 0;
		receive_count = 0;
		for(int j = 0; j < cols; j++) {
			if(send[i][j] == 1) send_count++;
			if(receive[i][j] == 1) receive_count++;
		}

		if(send_count % 2 == 0) send_row_parity[i] = 0;
		else send_row_parity[i] = 1;

		if(receive_count % 2 == 0) receive_row_parity[i] = 0;
		else receive_row_parity[i] = 1;
	}

	// Finding col parity
	for(int i = 0; i < cols; i++) {
		send_count = 0;
		receive_count = 0;
		for(int j = 0; j < rows; j++) {
			if(send[j][i] == 1) send_count++;
			if(receive[j][i] == 1) receive_count++;
		}

		if(send_count % 2 == 0) send_col_parity[i] = 0;
		else send_col_parity[i] = 1;

		if(receive_count % 2 == 0) receive_col_parity[i] = 0;
		else receive_col_parity[i] = 1;
	}

	int flag = 0;
	int err_row = 0, err_col = 0;

	// Checking row and col parities of send and receive data
	for(int i = 0; i < rows; i++) {
		if(send_row_parity[i] != receive_row_parity[i]) {
			err_row = i;
			flag = 1;
			break;
		}
	}
	
	for(int i = 0; i < cols; i++) {
		if(send_col_parity[i] != receive_col_parity[i]) {
			err_col = i;
			flag = 1;
			break;
		}
	}
	
	if(flag == 1) {
		cout << "Error in data" << endl;
		cout << "Positions of error: x = " << err_row << ", y = " << err_col << endl;
	}
	else
		cout << "No error in data" << endl;
}
