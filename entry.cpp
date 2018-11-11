#include "entry.h"

using namespace std;

Entry::Entry(string name){
    title=name;
}
Entry::~Entry(void){
    tags.clear();
    vector<string>().swap(tags);
}
string Entry::showTitle(){
    return title;
}
float Entry::showRating(){
    return rating;
}
int Entry::showLength(){
    return lenght;
}
vector <string> Entry::showTags(){
    return tags;
}
float Entry::showFitness(){
    return fitness;
}

void Entry::showStatistics(void){
    cout<<"----------------------+ENTRY+----------------------"<<endl;
    cout<<"Title: "<<title<<endl;
    cout<<"Rating: "<<rating<<endl;
    cout<<"Fitness: "<<fitness<<endl;
    cout<<"Lenght: "<<lenght<<endl;
    cout<<"Tags: ";
    for(int i=0;i<tags.size();i++){
        cout<<tags[i];
        cout<<", ";
    }
    cout<<endl;
}

void Entry::addTag(string tag){
    tags.push_back(tag);
}

void Entry::setLenght(int tempLenght){
    lenght=tempLenght;
}

void Entry::setRating(float tempRating){
    rating=tempRating;
}

void Entry::removeTag(string tag){
    try{
        for(int i=0;i<tags.size();i++){
            if(tags[i].compare(tag)==true){
                tags.erase(tags.begin()+1);
                return;
            }
        }
        throw invalid_argument("tag didn't match any of the current ones");
    }catch(const invalid_argument is){
        cerr << "Invalid argument: " << is.what();
    }
}
