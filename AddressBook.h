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
    AddressBook();
    void registration();
    void showAllUsers();
    int signIn();


};



#endif //ADDRESSBOOK_H
