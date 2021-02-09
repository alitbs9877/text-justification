//
// Created by alitbs on 7/4/19.
//

#include "Line.h"
Line::Line(int limit) {
    this->limit=limit;
    value=limit;
}
void Line::addWord(string word) {
    if(!words.empty()) value -=1;
    if(word.size()<=value){
        words.push_back(word);
        value -= word.size();
    }
    else {

        cout<< "can't add . limitation " << endl;
    }

}
void Line::deleteWord(int wordNumber) {
    if( wordNumber<=words.size()){
        words.erase(words.begin()+wordNumber-1);
    }
    else{
        cout << " out of index" << endl;
    }
}