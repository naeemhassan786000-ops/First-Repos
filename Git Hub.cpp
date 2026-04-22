#include <iostream>
#include <cstring>
#include <string>
using namespace std;

//====Input===
void input_array_display(char* arr, int length) {
	int counter = 0;
	int letter;
	cout << "Enter characters(terminate till new line): ";
	cin.ignore();
	while ((letter = cin.get()) != '\n' && counter < length - 1) {
		*(arr + counter) = letter;
		counter++;
	}
	*(arr + counter) = '\0';

	//===Clear Buffer===
	if (letter != '\n') {
		cin.ignore(100, '\n');
	}
	cout << endl;
	cout << "Array: ";
	for (int index = 0; index < counter; index++) {
		cout << *(arr + index);
	}
}

//===Searching Character===
int Search_char(char* arr, int size, char key) {
	for (int go = 0; go < size; go++) {
		if (key == *(arr + go)) {
			return go;
		}
	}
	return -1;
}
//===Vowels Counter===
int vowels_counting(char* arr, int size) {
	int vowels = 0;
	char icon;
	for (int pos = 0; pos < size; pos++) {
		icon = *(arr + pos);
		if ((icon == 'a' || icon == 'e' || icon == 'i' || icon == 'o' || icon == 'u') ||
			(icon == 'A' || icon == 'E' || icon == 'I' || icon == 'O' || icon == 'U')) {
			vowels++;
		}
	}
	return vowels;
}
//===Extract Vowels===
void extract_vowels(char* arr, int size) {
	char* vowels = new char[20];
	char word;
	int vowel_count = 0;
	int jv = 0;
	for (int pos = 0; pos < size; pos++) {
		word = *(arr + pos);
		if ((word == 'a' || word == 'e' || word == 'i' || word == 'o' || word == 'u') ||
			(word == 'A' || word == 'E' || word == 'I' || word == 'O' || word == 'U')) {
			*(vowels + jv) = *(arr + pos);
			jv += 1;
			vowel_count++;
		}
	}
	*(vowels + jv) = '\0';
	if (vowel_count > 0) {
		cout << "Extracted Array: ";
		for (int m = 0; *(vowels + m) != '\0'; m++) {
			cout << *(vowels + m);
		}
	}
	else {
		cout << "No vowels found\n";
	}
}
//===Reverse Array===
void reverse_array(char* arr, int size) {
	size = strlen(arr);
	cout << "\nReversed array: ";
	for (int i = size - 1; i >= 0; i--) {
		cout << *(arr + i);
	}
	cout << "\n";
}

//===Special Feast Input Handling For Bulid in Functions
void input_disp_build(char* arr, int size) {
	int counter = 0;
	int letter;
	while ((letter = cin.get()) != '\n' && counter < size - 1) {
		*(arr + counter) = letter;
		counter++;
	}
	*(arr + counter) = '\0';
	cout << "Array: ";
	for (int index = 0; index < counter; index++) {
		cout << *(arr + index);
	}
	cout << endl;
}
void build_in_fun(char* arr1, char* arr2) {
	int option;
	do {
		cout << "  Strings length --> Press 1\n"
			<< "  String Compare --> Press 2(ASCII Based)\n"
			<< "  String Concatenation--> Press 3\n "
			<< " Substring Serach(array==arr1,key==arr2)--> Press 4\n"
			<< "  Exit--> Press 0\n"
			<< "  Enter Choice: ";
		cin >> option;
		if (option == 1) {
			cout << "String length (arr1){Excluding null terminator}: " << strlen(arr1) << "\n"
				<< "String length (arr2){Excluding null terminator}: " << strlen(arr2) << "\n\n";
		}
		else if (option == 2) {
			int cmp = strcmp(arr1, arr2);
			if (cmp == 0) {
				cout << "Arrays are equal.\n";
			}
			else if (cmp < 0)
			{
				cout << "Array 2 is larger\n";
			}
			else {
				cout << "Array1 is larger.\n";
			}
			cout << endl;
		}
		else if (option == 3) {
			string str1 = arr1;
			cin.ignore();
			string str2 = arr2;
			str1 += str2;//Concatenates second string to first one
			cout << "Concatenated string: " << str1 << endl;
			cout << endl;
		}
		else if (option == 4) {
			char* p = strstr(arr1, arr2);
			if (p) {
				cout << "Found at (First Occurence): " << p - arr1 << " Index of first letter." << endl;
			}
			else {
				cout << "Substring Not Found.\n";
			}
			cout << endl;
		}
		if (option > 4 || option < 0) {
			cout << "Invalid Option\n\n";
		}
	} while (option != 0);
	cout << "\t\n..Thanks For Building Up...\n";
}
int main() {
	int size = 0;
	char* list = new char[50];

	cout << "\t1-D Charcter Arrays via Pointer Notations";
	int option;
	do {
		cout << endl;
		cout << "\n Input & Display==>Press 1\n"
			<< " Search Character==>Press 2\n"
			<< " Vowels Count==>Press 3\n"
			<< " Extract Vowels==>Press 4\n"
			<< " Reverse String==>Press 5\n"
			<< " BUild In Feast==>Press 6\n"
			<< " Sign Out==>Press 0\n\n";
		cout << " Enter Option: ";
		cin >> option;
		cout << endl;
		if (option == 1) {
			cout << "Enter Size Of array: ";
			cin >> size;
			list = new char[size];
			input_array_display(list, size);
		}
		else if (option == 2) {
			char alph;
			cout << "Enter Alphabet to Search: ";
			cin >> alph;
			if (Search_char(list, size, alph) >= 0) {
				cout << "(First Occurence)Found at index: " << Search_char(list, size, alph) << endl;
			}
			else {
				cout << "Character not found\n";
			}
		}
		else if (option == 3) {
			int fond = vowels_counting(list, size);
			cout << "Number of Vowels found: " << fond << endl;
		}
		else if (option == 4) {
			extract_vowels(list, size);
		}
		else if (option == 5) {
			reverse_array(list, size);
		}
		else if (option == 6) {
			cin.ignore();
			char* a1 = new char[10];
			char* a2 = new char[10];
			cout << "=====================\n"
				<< "   Build In Fest\n"
				<< "=====================\n";
			cout << "Enter Elements of a1{10 characters only}: ";
			input_disp_build(a1, 10);

			cout << "Enter Elements of a2{10 characters only}: ";
			input_disp_build(a2, 10);
			cout << endl;
			build_in_fun(a1, a2);
			delete[]a1, delete[]a2;
		}
		if (option > 6 || option < 0) {
			cout << "Invalid Option\n";
		}
	} while (option != 0);
	cout << "=== GOOD TO GO ===\n";
	delete[]list;
}
