#include <iostream>
#include "userMenager.h"

using namespace std;
void UserMenager::loadUsersFromFile(){
    users = userFile.loadUsersFile(  );
}
void UserMenager::registration(  ) {
    string userLogin ="", userPassword ="";
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

    userFile.saveNewUser( newUser.changeUserDataToOneLine() );
    cout<< "Uzytkownik " << userLogin << " zostal zapisany." <<endl;

    Sleep(1000);
}

int UserMenager::signIn(  ) {
    string userLogin ="", userPassword ="";
    bool user = false;
    int unsigned i = 0;
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

void UserMenager::changePassword( User &user ) {
    string newPassword = "";
    displayTitle( "   Zmiana hasla" );
    displayTitle( "Podaj nowe haslo: ", false, false);
    cin>> newPassword;
    user.setPassword( newPassword );
    userFile.saveAfterPasswordChange ( user.changeUserDataToOneLine(), user.getID() );
    cout<<"Haslo zostalo zmienione.";
    Sleep(1000);

}

vector<User>::iterator UserMenager::findUserID( int IDLoggedUser ) {
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

int UserMenager::signOut() {
    displayTitle("Wylogouwywanie...");
    Sleep(500);
    return 0;
}

void UserMenager::showAllUsers(){
    for( unsigned int i=0; i< users.size(); i++)
        users[i].showUserData();
}
