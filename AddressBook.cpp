#include "AddressBook.h"
#include <iostream>
using namespace std;

AddressBook::AddressBook( string fileName ) {
    setUsersFileName( fileName );
}

void AddressBook::setUsersFileName( string fileName ) {
    usersFileName = fileName;
}

string AddressBook::getUsersFileName() {
    return usersFileName;
}

void AddressBook::loadUsersFile( ) {
    fstream fileUsers;
    checkFileExistence( usersFileName );
    fileUsers.open( usersFileName.c_str(), ios::in );

    string fileLine;
    int nrLine=1;
    User newUser;
    while( getline( fileUsers, fileLine, '|') ) {
        switch( nrLine % 3 ) {
        case 1:
            newUser.setID( atoi( fileLine.c_str() ) );
            break;
        case 2:
            newUser.setLogin( fileLine.c_str()  );
            break;
        case 0:
            newUser.setPassword( fileLine.c_str()  );
            break;
        }
        if( nrLine % 3 == 0 ) {
            users.push_back( newUser );
        }
        nrLine++;
    }
    fileUsers.close();
}

void AddressBook::registration(  ) {
    string userLogin, userPassword;
    displayTitle( "   Rejestracja" );
    cout<< "Liczba uzytkownikow: " << users.size() <<endl;
    cout<< "Podaj  login: " ;
    cin>> userLogin;
    unsigned int i = 0;
    while( i<users.size() ) {
        if( userLogin == users[i].getLogin() ) {
            cout<<"Podany login juz istnieje. Podaj inny login: " <<endl;
            cin>>userLogin;
            i=0;
        } else i++;
    }
    cout<< "Podaj haslo: ";
    cin>> userPassword;
    User newUser( userLogin, userPassword, users.size()+1 );

    users.push_back( newUser );

    saveNewUser( newUser.changeUserDataToOneLine() );
    cout<< "Uzytkownik " << userLogin << " zostal zapisany." <<endl;

    Sleep(1000);
}

void AddressBook::saveNewUser( string userOneLineData ) {
    fstream fileUsers;
    fileUsers.open( usersFileName.c_str(),  ios::app );
    fileUsers<< userOneLineData <<endl;
    fileUsers.close();
}

int AddressBook::signIn(  ) {
    string userLogin, userPassword;
    bool user = false;
    int unsigned i=0;
    int attempt = 3;
    displayTitle( "   Logowanie" );
    while( attempt>0 ) {
        displayTitle( "Podaj  login: ", false, false);
        cin>> userLogin;
        displayTitle( "Podaj  haslo: ", false, false);
        cin>> userPassword;

        while( i<users.size()) {
            if( users[i].getLogin() != userLogin || users[i].getPassword() != userPassword ) {
                user = false;
                i++;
            } else {
                user = true;
                break;
            }
        }
        if( user == false) {
            system("cls");
            i=0;
            attempt--;
            cout<<"Podany login lub haslo jest nieprawidlowe. Pozostalo "<< attempt << " prob."<<endl;
        } else
            break;
    }

    if( user == true ) {
        return users[i].getID();
    } else {
        cout<<"Nie udaloa sie zalogowac."<<endl;
        Sleep(2000);
        return 0;
    }
}

void AddressBook::changePassword( User &user ) {
    string newPassword;
    displayTitle( "   Zmiana hasla" );
    displayTitle( "Podaj nowe haslo: ", false, false);
    cin>> newPassword;
    user.setPassword( newPassword );
    saveAfterPasswordChange ( user.changeUserDataToOneLine(), user.getID() );
    cout<<"Haslo zostalo zmienione.";
    Sleep(1000);

}

void AddressBook::saveAfterPasswordChange ( string userOneLineData, int userID ) {
    string temporaryFileName = usersFileName.substr(0, usersFileName.length() - 4) + "_Tymczasowy.txt" ;
    fstream usersFile;
    fstream tempUsersFile;

    string fileLine;
    usersFile.open( usersFileName.c_str(),  ios::in );
    tempUsersFile.open( temporaryFileName.c_str(),  ios::out );

    while( getline( usersFile, fileLine ) ) {
        if( atoi( fileLine.c_str() ) == userID ) {
            tempUsersFile<< userOneLineData <<endl;
        } else {
            tempUsersFile<< fileLine <<endl;
        }
    }
    tempUsersFile.close();
    usersFile.close();
    remove( usersFileName.c_str() );
    rename( temporaryFileName.c_str(), usersFileName.c_str() );
}

vector<User>::iterator AddressBook::findUserID( int IDLoggedUser ) {
    vector<User>::iterator itr = users.begin();
    vector<User>::iterator endOfVector = users.end();
    while( itr != endOfVector ) {
        if( itr-> getID() == IDLoggedUser )
            break;
        else
            ++itr;
    }
    return itr;
}

int AddressBook::signOut() {
    displayTitle("Wylogouwywanie...");
    Sleep(500);
    return 0;
}


