#include "dictionary.h"
#include <set>
#include <string>
#include <iostream>

using namespace std;

Dictionary::Dictionary() {
    words = set<string>();
}

Dictionary::Dictionary(const Dictionary& other) {
    words = other.words;
}

bool Dictionary::exists(const std::string& val) const{
    return words.find(val) != words.end();
}

bool Dictionary::insert(const string& val) {
    bool esta = true;
    if(!words.count(val)){ // Palabra no está
        words.insert(val);
        esta = false;
    }
    return esta;
}
bool Dictionary::erase(const string& val){
    bool esta = false;
    set<string>::iterator it = words.find(val);
    if(it != words.end()){ // Palabra está
        words.erase(it);
        esta = true;
    }
    return esta;
}

void Dictionary::clear(){
    words.clear();
}

bool Dictionary::empty() const{
    return words.empty();
}

unsigned int Dictionary::size() const{
    return words.size();
}

vector<string> Dictionary::wordsOfLength(int length){
    vector<string> aux;
    set<string>::iterator it = words.begin();
    for(; it != words.end(); ++it){
        if((*it).length() == length){
            aux.push_back(*it);
        }
    }

    return aux;
}

int Dictionary::getOcurrances(const char c){
    int n = 0;
    set<string>::iterator it = words.begin();
    for(; it != words.end(); ++it)
        for(int i=0; i<(*it).length(); ++i)
            if((*it).at(i) == c) n++;

    return n;
}

void Dictionary::anade(const Dictionary& dic){
    set<string>::iterator it = dic.words.begin();
    for(; it!=dic.words.end(); ++it)
        words.insert(*it);
}

void Dictionary::toString() const {
    for(set<string>::iterator it = words.begin(); it != words.end(); ++it)
        cout << *it << endl;
}