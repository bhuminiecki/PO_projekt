//
// Created by Wombat on 11/11/2018.
//

#include "menu.h"

using namespace std;

void Menu::creationMenu(){
    cout<< "----------------------+CREATOR+----------------------" << endl;
    cout<< "specify whether you'd like to create a 'movie','series' or 'event' entry"<<endl;
    string entryType;
    cin>>entryType;
    template Handler<Movie> movieCreator();

    //switch(stoi(entryType)){
        //case stoi("movie"):

}
