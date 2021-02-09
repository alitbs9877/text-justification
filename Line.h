//
// Created by alitbs on 7/4/19.
//

#ifndef TEXTJUSTIFICATIONS_LINE_H
#define TEXTJUSTIFICATIONS_LINE_H
#include <iostream>
#include <vector>

using namespace std ;
class Line {
public:
    Line(int limit);
    vector<string> words;
    int value;
    int limit;
    void addWord( string word);
    void deleteWord( int wordNumber);

};


#endif //TEXTJUSTIFICATIONS_LINE_H
