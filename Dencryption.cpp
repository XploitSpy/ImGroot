#include <iostream> // Header that defines the standard input/output stream objects
#include <string> // This header file defines several functions to manipulate C strings and arrays
#include <cstdlib> // This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting
#include <cctype> // This header declares a set of functions to classify and transform individual characters


using namespace std;

int main()
{

		string pesan;
		cout << "Enter Your Message [Ciphertext]\t\t\t: ";
		getline(cin, pesan);

		int dcyptKey;
		cout << "Enter The Key For a Caesarean Section (1-26)\t: ";
		cin >> dcyptKey;
		cin.ignore();

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
		cout << "Multi Decrypted Message\t\t\t\t: " << decryptMsg;

	return 0;

}