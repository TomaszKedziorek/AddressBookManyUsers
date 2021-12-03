#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H
#include <iostream>
//#include <cstdlib>
//#include <windows.h>
#include <vector>
#include "user.h"
//#include "userMenager.h"
using namespace std;

class AddressBook{
    string usersFileName;
    vector<User> users;
    void saveAfterPasswordChange ( string userOneLineData,  int userID  );
public:
    AddressBook( string = "wszyscyUzytkownicy.txt" );
    void setUsersFileName( string fileName );
    string getUsersFileName();
    void loadUsersFile(  );
    void registration(  );
    void saveNewUser( string userOneLineData );
    int signIn(  );
    void changePassword( User &user );

    vector<User>::iterator findUserID( int IDLoggedUser );
    int signOut();
};



#endif //ADDRESSBOOK_H
