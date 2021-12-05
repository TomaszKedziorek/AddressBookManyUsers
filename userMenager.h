#ifndef USERMENAGER_H
#define USERMENAGER_H
#include <iostream>
#include <conio.h>   //getch
#include <windows.h> //exit(0)
#include "user.h"
#include "usersFile.h"
#include <vector>

using namespace std;

class UserMenager{
    vector<User> users;
    UsersFile userFile;
public:
    UserMenager( string usersFileName );
    void loadUsersFromFile();
    void registration();
    int signIn();
    void changePassword( User &user );
    vector<User>::iterator findUserID( int IDLoggedUser );
    int signOut();
    void showAllUsers();
};
#endif // USERMENAGER_H
