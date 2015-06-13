////////////////////////
//Name: Kathleen Levi
//
//Project: EX06_02 (13.2)
//
//Date: 12 June, 2015
////////////////////////

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
//prompts the user to enter a filename
    string filename;
    fstream UserFile(filename, ios::in | ios::out);
    cout << "Enter the name of the file you would like to create: ";
    cin >> filename;
    
    //Create file if it does not exist
    if (!UserFile){
        UserFile.open(filename, ios::out);
    }
    
    if (UserFile.fail()){
        cout << "can't open file for writing" << endl;
        return 0;
    }
    
    //Add some data to count the characters
    UserFile << "Hello and Good Morning";
    
    UserFile.close();
    
    //displays the number of characters in the file
    UserFile.open(filename, ios::in);
    
    int count = 0;
    while (!UserFile.eof()){
        
        UserFile.get();
        count++;
    }
    
    count--;
    
    UserFile.close();

    cout << "File " << filename << " has " << count << " characters." << endl;
}