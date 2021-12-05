#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H
#include <iostream>
//#include <cstdlib>
//#include <windows.h>
#include "user.h"
#include "userMenager.h"
using namespace std;

class AddressBook{
    UserMenager userMenager;

public:
    AddressBook( string usersFileName );
    void registration();
    void showAllUsers();
    int signIn();
    void changePassword( int idLoggedUser );
    int signOut();


};



#endif //ADDRESSBOOK_H
