#include <iostream> // Header that defines the standard input/output stream objects
#include <string> // This header file defines several functions to manipulate C strings and arrays
#include <cstdlib> // This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting
#include <cctype> // This header declares a set of functions to classify and transform individual characters


using namespace std;

int main()
{		    
	{
		string pesan;
		int a, b;
		cout << "Masukkan pesanmu disini [Plaintext]\t\t\t: ";
		getline(cin, pesan);
		cout << "Masukkan key dengan bilangan prima\t\t: "; cin >> a;
		cout << "Masukkan key dengan angka bebas\t\t\t: "; cin >> b;
		cout << endl;

		//algorithm here [ Encryption Affine Cipher]
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
		cout << "Encrypted Message \t\t\t\t: " << cipher << endl;

		// Multi Encryption using Caesar Cipher
		string encryptedCipher = cipher;
		cout << endl;
		int key;
		cout << "Enter The Key For a Caesarean Section (1-26) \t: "; cin >> key;

		for (int i = 0; i < cipher.length(); i++) { // Length is a Function to count the number of characters in a string variable. The form is of course integer data

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

	return 0;

}
