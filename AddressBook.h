#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <vector>
#include "user.h"
//#include "userMenager.h"
using namespace std;

class AddressBook{
    string usersFileName;
    vector<User> users;

public:
    AddressBook( string = "wszyscyUzytkownicy.txt" );
    void setUsersFileName( string fileName );
    string getUsersFileName();
    void loadUsersFile(  );
    void registration(  );
    void saveNewUser( User &newUser );
    int signIn(  );
    void changePassword( User &users );
    void saveAfterPasswordChange ( User &users );
    vector<User>::iterator findUserID( int IDLoggedUser );
    int signOut();
};



#endif //ADDRESSBOOK_H
