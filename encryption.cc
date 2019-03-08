/*
*
*  Program: encryption.cc
*  Name: Zachary Knoblauch
*  Date: 5/March/2019
*  Description: Displays menu.
*               Option 1: User inputs a value for key
*               Option 2: User inputs file name to encrypt and file name to encrypt to
*               Option 3: User inputs file name to decrypt and file name to decrypt to
*               Option 4: Quits the program
*
*/


#include <iostream>
#include <cstdlib>
#include <fstream>

void displayMenu();//displays the menu and options
int getKey();//gets an encryption key from the user
void encrypt(int key);//encrypts a file and outputs to a different file
void decrypt(int key);//decrypts a file and outputs to a different file

using namespace std;

int main(){

int choice, key;
key = 3;//default

  do{
    displayMenu();
    cin >> choice;
      if(choice == 1){//call the set key function and assign to key
        key = getKey();
      }
      else if(choice == 2){//call the encryption function
        encrypt(key);
      }
      else if(choice == 3){//call the decryption function
        decrypt(key);
      }
  } while(choice != 4);
  return 0;
}//main

void displayMenu(){//displays the menu and options
  cout << "1. Set the shift key value [default is 3]" << endl;
  cout << "2. Encrypt a file" << endl;
  cout << "3. Decrypt a file" << endl;
  cout << "4. Quit" << endl;
  cout << "Choose an option: ";
}

int getKey(){//gets an encryption key from the user
int num = 0;

  do{
    cout << "Enter a key value between 1 and 10 for encryption: ";
    cin >> num;
  } while(num < 1 || num > 10);//checks that num is between 1 and 10
  return num;
}

void encrypt(int key){//encrypts a file and outputs to a different file
ifstream read;
ofstream write;
string start;
string end;
char ch;

  cout << "Enter a file name to encrypt: ";//file name to encrypt
  cin >> start;
  cout << "\nEnter a file name for the new encrypted file: ";//file name to encrypt to
  cin >> end;

  read.open(start.c_str());
  if(read.fail()){
    exit(1);
  }
  write.open(end.c_str());
  if(write.fail()){
    exit(1);
  }

  read.get(ch);
  while(!read.eof()){
    ch = ch + key;
    write << ch;
    read.get(ch);
  }


}

void decrypt(int key){//decrypts a file and outputs to a different file
ifstream read;
ofstream write;
string start;
string end;
char ch;

  cout << "Enter a file name to decrypt: ";//file name to decrypt
  cin >> start;
  cout << "\nEnter a file name for the new decrypted file: ";//file name to decrypt to
  cin >> end;

  read.open(start.c_str());
  if(read.fail()){
    exit(1);
  }
  write.open(end.c_str());
  if(write.fail()){
    exit(1);
  }

  read.get(ch);
  while(!read.eof()){
    ch = ch - key;
    write << ch;
    read.get(ch);
  }

}
