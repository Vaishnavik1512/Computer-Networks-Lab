#include<bits/stdc++.h>

using namespace std;

int main() {
	cout << "Error Control Methods: Simple Parity Check" << endl;
	cout << "*******************************************" << endl;
	
	string sender, receiver;
	cout << "Enter Sender Data: ";
	cin >> sender;
	cout << "Enter Received Data: ";
	cin >> receiver;

	int sender_parity, receiver_parity;
	int send_count = 0, receive_count = 0;
	for(int i = 0; i < sender.length(); i++) {
		if(sender[i] == '1') send_count++;
		if(receiver[i] == '1') receive_count++;
	}
	
	// cout << send_count << " " << receive_count << endl;

	if(send_count % 2 == 0) 
		sender_parity = 0;
	else 
		sender_parity = 1;
	
	if(receive_count % 2 == 0) 
		receiver_parity = 0;
	else 
		receiver_parity = 1;

	if(sender_parity != receiver_parity)
		cout << "There is an error in the received data." << endl;
	else
		cout << "No error in the received data." << endl;
}
