#include <iostream>

#include "videogame.h"
#include "date.h"
#include "list.h"

using namespace std;

int main() {
    List<VideoGame, 100> myList;

    VideoGame myVideoGame;
    Date myDate;

    string myStr;
    char op;

    do {
        cout << "ID: ";
        getline(cin, myStr);
        myVideoGame.setId(myStr);

        cout << "Name: ";
        getline(cin, myStr);
        myVideoGame.setName(myStr);

        cout << "Developer: ";
        getline(cin, myStr);
        myVideoGame.setDeveloper(myStr);

        cout << "Category: ";
        getline(cin, myStr);
        myVideoGame.setCategory(myStr);

        cout << "Release date (YYYY/MM/DD): ";
        getline(cin, myStr, '/');
        myDate.setYear(atoi(myStr.c_str()));
        getline(cin, myStr, '/');
        myDate.setMonth(atoi(myStr.c_str()));
        getline(cin, myStr);
        myDate.setDay(atoi(myStr.c_str()));

        myVideoGame.setReleaseDate(myDate);

        myList.insertElement(myList.getLastPosition(), myVideoGame);

        cout << "Would you like to insert another element? (y/n): ";
        cin >> op;
        cin.ignore();

    } while(op == 'y');

    cout << endl << endl;
    
    cout << "List contents..." << endl;
    cout << myList.toString() << endl;

    cout << endl << endl;
}