#include <iostream> // Header that defines the standard input/output stream objects
#include <string> // This header file defines several functions to manipulate C strings and arrays
#include <cstdlib> // This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting
#include <cctype> // This header declares a set of functions to classify and transform individual characters

using namespace std;

void Encryption(){

		string pesan;
		int a, b;
		cout << "Enter Your Message [Plaintext]\t\t\t: ";
		getline(cin, pesan);
		cout << "Enter The key Using Prime Numbers\t\t: "; cin >> a;
		cout << "Enter The key using Numbers\t\t\t: "; cin >> b;
		cout << endl;

		//algorithm here [ Encryption Affine Cipher]
		/*
		Affine Cipher Formula
		C ≡ m P + b (mod n) [Encryption]
		P ≡ m-1(C – b ) (mod n) [Decryption]
		*/
		string cipher = " ";
		for (int i = 0; i < pesan.length(); i++) {

			if (isupper(pesan[i])) {
				cipher = cipher + (char)((((a * (pesan[i] - 'A')) + b ) % 26) + 'A'); // for uppercase letters
			}
			else if (islower(pesan[i])) {
				cipher = cipher + (char)((((a * (pesan[i] - 'a')) + b ) % 26) + 'a'); // for lowercase letters
			}
			else {
				cipher += pesan[i]; // Add Spacing characters
			}
		}
		cout << "Encrypted Message\t\t\t\t: " << cipher << endl;

		// Multi Encryption using Caesar Cipher
		/*
		Caesar Cipher Formula
		CipherText 	= E(P)	= (P+k) mod 26 [Encryption]
	 	Plaintext 	= D(C)  = (C-k) mod 26 [Decryption]
		*/
		string encryptedCipher = cipher;
		cout << endl;
		int key;
		cout << "Enter The Key For a Caesarean Section (1-26) \t: "; cin >> key;

		for (int i = 0; i < cipher.length(); i++) {

			if (cipher[i] == 32) {
				continue; //32 is ASCII of space character, we will ignore it
			}
			else {

				if ((cipher[i] + key) > 122) {
					//after lowercase z move back to a, z's ASCII is 122
					int temp = (cipher[i] + key) - 122;
					encryptedCipher[i] = 96 + temp;
				}
				else if (cipher[i] + key > 90 && cipher[i] <= 96) {
					//after uppercase Z move back to A, 90 is Z's ASCII
					int temp = (cipher[i] + key) - 90;
					encryptedCipher[i] = 64 + temp;
				}
				else {
					//in case of characters being in between A-Z & a-z
					encryptedCipher[i] += key;
				}

			} //if
		} // for

		cout << "Multi Encrypted Message\t\t\t\t: " << encryptedCipher << endl;

}

void Decryption(){

		string pesan;
		cout << "Enter Your Message [Ciphertext]\t\t\t: ";
		getline(cin, pesan);

		int dcyptKey;
		cout << "Enter The Key For a Caesarean Section (1-26)\t: "; cin >> dcyptKey;

		string decryptedCipher = pesan;

		// Multi dencryption using Caesar Cipher
		for (int i = 0; i < pesan.length(); i++) {
			if (pesan[i] == 32) {
				continue; //ignoring space
			}
			else {
				if ((pesan[i] - dcyptKey) < 97 && (pesan[i] - dcyptKey) > 90) {
					int temp = (pesan[i] - dcyptKey) + 26; // For uppercase letters
					decryptedCipher[i] = temp;
				}
				else if ((pesan[i] - dcyptKey) < 65) {
					int temp = (pesan[i] - dcyptKey) + 26;
					decryptedCipher[i] = temp; // for lowercase letters
				}
				else {
					decryptedCipher[i] = pesan[i] - dcyptKey;
				}
			}
		}

		cout << "Decrypted Message\t\t\t\t: " << decryptedCipher << endl;
		
		string decryptedAffine = decryptedCipher;
		cout << endl;

		int a,b;
		cout << "Enter The key Using Prime Numbers\t\t: "; cin >> a;
		cout << "Enter The key using Numbers\t\t\t: "; cin >> b;
		cout << endl;

		//algorithm here [Affine Cipher]
		string decryptMsg;
		int a_inv = 0;
		int flag = 0;

		for (int i = 0; i < 26; i++) {
			flag = (a * i) % 26;
			if (flag == 1) a_inv = i;
		}
		
		for (int i = 0; i < decryptedAffine.length(); i++) {
			if (isupper(decryptedAffine[i])) {
				decryptMsg = decryptMsg + (char)(((a_inv * (((decryptedAffine[i] - 'A') - b + 26)) % 26)) + 'A'); // for uppercase letters
			}
			else if (islower(decryptedAffine[i])) {
				decryptMsg = decryptMsg + (char)(((a_inv * (((decryptedAffine[i] - 'a') - b + 26)) % 26)) + 'a'); // for lowercase letters
			}

			else {
				decryptMsg += decryptedAffine[i]; // Add Spacing characters
			}
		}

		cout << "Multi Decrypted Message\t\t\t\t: " << decryptMsg << endl;

}

void Menu(){

	int choice;
	cout << "[1] Encryption\n[2] Decryption\nEnter Your Choice [1,2] : ";
	cin >> choice;
	cin.ignore();
	cout << endl;
	cout << endl;

	if(choice == 1){
		Encryption();
		cout << endl;
	}
	else if(choice == 2){
		Decryption();
		cout << endl;
	}
	else{
		cout << "Your choice is wrong !!!" << endl;
	}

}

int main(){

	cout <<"\t\t\t\t  ___   __   __   __    _______  ______    _______  _______  _______ \n"; 
	cout <<"\t\t\t\t |   | |  | |  |_|  |  |       ||    _ |  |       ||       ||       | \n";
	cout <<"\t\t\t\t |   | |__| |       |  |    ___||   | ||  |   _   ||   _   ||_     _| \n";
	cout <<"\t\t\t\t |   |      |       |  |   | __ |   |_||_ |  | |  ||  | |  |  |   |   \n";
	cout <<"\t\t\t\t |   |      |       |  |   ||  ||    __  ||  |_|  ||  |_|  |  |   |  \n";
	cout <<"\t\t\t\t |   |      | ||_|| |  |   |_| ||   |  | ||       ||       |  |   |  \n";
	cout <<"\t\t\t\t |___|      |_|   |_|  |_______||___|  |_||_______||_______|  |___|  \n";
	cout <<"												\n";
	cout << "\t\tSend a quick message with simple text encryption, basically in Affine Cipher with Multi Encryption";
	cout << "\t\t\t\t\t\tbased algorithm on ASCII and Caesar Cipher\n\n";
	cout << "\t\t\t\t\t Author \t: XploitSpy and Secsparrow\n\n";
	cout << "\t\t\t\t\t Version \t: 1.0 Beta\n\n";
	cout << "\t\t\t\t\t Project \t: www.github.com/XploitSpy/ImGroot\n\n";
	cout << "\t\t\t\t\t\t Press any key to see menu...\n\n\n";
	cin.get();

	char again;
	int userChoice;
	cout << "[1] List Menu Program\n[2] Exit The Program\nEnter Your Choice [1,2] : ";
	cin >> userChoice;

	if(userChoice == 1){

		Menu(); // Open to Other Function 
		cout << endl;
	}
	else if(userChoice == 2){
		exit(0); // Exit The Program
	}
	else{
		cout << "Your Choice Is Wrong !!!\n\n" << endl;
	}

	cout << "Do You Want To Use The ImGroot Program Again [Y/N] ??? " ; 
	cin >> again;

	if (again == 'Y' || again == 'y'){

		Menu(); // Return To Function Void Menu
	}
	else{
		cout << "Thank You For Using This Program" << endl;
	}

	return 0;
}