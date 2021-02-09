//
// Created by alitbs on 7/4/19.
//
#include <math.h>
#include "Text.h"
Text::Text() {

}
Text* Text::add(Text *rhs) {
    Text *newText= new Text;
//    for (int i = 0; i <lines.size() ; ++i) {
////        for (int j = 0; j <lines.at(i)->words.size() ; ++j) {
////            cout<<endl<< lines.at(i)->words.at(j)<<endl;
////        }
//        newText->addLine(lines.at(i));
//    }
//    Line *updatingLine= newText->lastLine();
//    bool haveSpace=false;
//    if(updatingLine->value>0){
//        int remainValue=updatingLine->value;
//        if(!rhs->lines.empty()){
//            Line *pushingLine=rhs->lines.at(0);
//            int boundWord=0;
//            for (int i = 0; i <pushingLine->words.size() ; ++i) {
//                if(pushingLine->words.at(i).size()<remainValue){
//                    updatingLine->addWord(pushingLine->words.at(i));
//                    remainValue-=(1+pushingLine->words.at(i).size());
//                    boundWord++;
//                } else {
//                    break;
//                }
//            }
//            haveSpace=true;
//            newText->addLine(updatingLine);
//
//        }
//    }
//    for (int j = 0; j <rhs->lines.size() ; ++j) {
////        cout << " i in line new "<< j ;
//        if(haveSpace && j==0) continue;
//        newText->addLine(rhs->lines.at(j));
//    }
////

    return newText;

}
void Text::addLine(Line *line1) {
    lines.push_back(line1);

}
void Text::calTotalValue() {
    if(lines.empty()){

        totalValue= 2100000;
        return;
    }

    double sum =0 ;
    for (int i = 0; i <lines.size() ; ++i) {
        sum+=pow(lines.at(i)->value,2);

    }
    totalValue=sum;

}
void Text::deleteLastLine() {
    deleteLine( lines.size());
}
Line* Text::lastLine() {
    if(lines.empty())
        cout << " empty text ";
    else
        return lines.at(lines.size()-1);
}
void Text::deleteLine(int lineNumber) {
    if(lines.size()>=lineNumber)
        lines.erase(lines.begin() + lineNumber-1);
    else
        cout<< "out of index"<<endl;
}
