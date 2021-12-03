#include <iostream>
#include "commonFunk.h"
#include "AddressBook.h"
#include "User.h"
#include "userMenager.h"
using namespace std;

int main()
{
    AddressBook addressBook;
    addressBook.showAllUsers();

    addressBook.registration();
    addressBook.showAllUsers();
    addressBook.registration();

    return 0;
}
