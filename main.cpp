#include <iostream>
#include "commonFunk.h"
#include "AddressBook.h"
#include "User.h"
#include "userMenager.h"
using namespace std;

int main()
{
    AddressBook addressBook( "wszyscyUzytkownicy.txt" );
    addressBook.showAllUsers();

    addressBook.registration();
    addressBook.showAllUsers();
    addressBook.registration();

    return 0;
}
