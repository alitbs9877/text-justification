//
// Created by alitbs on 7/4/19.
//
#include <iostream>
#include <vector>
#include "Line.h"

#ifndef TEXTJUSTIFICATIONS_TEXT_H
#define TEXTJUSTIFICATIONS_TEXT_H

using  namespace std;

class Text {

public:
    Text();
    vector<Line * > lines;
    double totalValue;
    void deleteLastLine( );
    Line * lastLine();
    void calTotalValue( );
    void addLine(Line * line1);
    void deleteLine(int lineNumber);
    Text* add(Text *rhs);

};


#endif //TEXTJUSTIFICATIONS_TEXT_H
