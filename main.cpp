#include <iostream>
#include "commonFunk.h"
#include "AddressBook.h"
#include "User.h"
#include "userMenager.h"
using namespace std;

int main()
{
    AddressBook addressBook;
    cout<<addressBook.getUsersFileName()<<endl;
    addressBook.loadUsersFile();
    //addressBook.registration();
    vector<User>::iterator u2 = addressBook.findUserID( 2 );
    addressBook.changePassword( (*u2) );
    addressBook.registration();

    return 0;
}
