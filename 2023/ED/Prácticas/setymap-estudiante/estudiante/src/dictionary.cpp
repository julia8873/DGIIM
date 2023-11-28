#include "dictionary.h"
#include <set>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

Dictionary::Dictionary(){
    words = set<string>();
}

Dictionary::Dictionary(Dictionary &other){
    words = other.words;
}

Dictionary::Dictionary(ifstream &f){
    if(f.is_open()){
        string palabra;
        while(f >> palabra)
            insert(palabra);
        f.close();
    }
}

bool Dictionary::exists(const string &val) const{
    set<string>::iterator it;
    it = words.find(val);
    return !(it == words.end());
}

bool Dictionary::insert(const string &val){
    pair<set<string>::iterator, int> res;
    res = words.insert(val);
    return res.second;
}

bool Dictionary::erase(const string &val){
    int res = words.erase(val);
    return res;
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
    vector<string> result;
    for(set<string>::iterator it = words.begin(); it != words.end(); ++it){
        if((*it).length() == length)
            result.push_back(*it);
    }
    return result;
}

int Dictionary::getOccurrences(const char c){
    int sum = 0;
    for(set<string>::iterator it = words.begin(); it != words.end(); ++it){
        sum += count((*it).begin(), (*it).end(), c);
    }
    return sum;
}

void Dictionary::anade(const Dictionary &dic){
    for(set<string>::iterator it = dic.words.begin(); it != dic.words.end(); ++it)
        insert(*it);
}

ostream & operator<<(ostream &os, const Dictionary &dict){
    for(auto it = dict.words.begin(); it != dict.words.end(); ++it){
        os << (*it) << endl;
    }
    return os;
}