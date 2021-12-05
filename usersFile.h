#ifndef USERSFILE_H
#define USERSFILE_H
#include <iostream>
#include <conio.h>   //getch
#include <windows.h> //exit(0)
#include <vector>
#include <fstream>
#include "user.h"

using namespace std;

class UsersFile{
    string usersFileName;
public:
    UsersFile( string = "wszyscyUzytkownicy.txt" );
    void setUsersFileName( string fileName );
    string getUsersFileName();
    vector<User> loadUsersFile( );
    void saveNewUser( string userOneLineData );
    void saveAfterPasswordChange ( string userOneLineData,  int userID  );
};

#endif // USERSFILE_H
