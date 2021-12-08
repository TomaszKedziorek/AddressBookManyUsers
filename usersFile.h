#ifndef USERSFILE_H
#define USERSFILE_H
#include <iostream>
#include <conio.h>   //getch
#include <windows.h> //exit(0)
#include <vector>
#include <fstream>
#include "user.h"

using namespace std;

class UsersFile {
    const string usersFileName;
    string getUsersFileName();
public:
    UsersFile( string USERSFILENAME );
    vector<User> loadUsersFile( );
    void saveNewUser( string userOneLineData );
    void saveAfterPasswordChange ( string userOneLineData,  int userID  );
};

#endif // USERSFILE_H
