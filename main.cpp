#include <iostream>
#include "Text.h"
#include "Line.h"
#include "Line.cpp"
#include "Text.cpp"
vector < string > allWords;
Text **majorText ;
void show(Text *text){
    for (int i = 0; i <text->lines.size() ; ++i) {
        for (int j = 0; j < text->lines.at(i)->words.size(); ++j) {
            cout << text->lines.at(i)->words.at(j) << " ";

        }
        cout<<endl;
    }

}
Text  combainTextes(Text fText,Text sText){
    int minValue=5000000;
    Text newText;
    Text mainText;

    for (int i = 0; i <fText.lines.size() ; ++i) {
//        for (int j = 0; j <lines.at(i)->words.size() ; ++j) {
//            cout<<endl<< lines.at(i)->words.at(j)<<endl;
//        }
        newText.addLine(fText.lines.at(i));
        mainText.addLine(fText.lines.at(i));

    }
    Line *updatingLine= newText.lastLine();
    bool haveSpace=false;
    if(updatingLine->value>0){

        int remainValue=updatingLine->value;

        if(!sText.lines.empty()){
            for (int j = 0; j < sText.lines.at(0)->words.size(); ++j) {
//                cout << " in adding word till " << j << endl ;
                Line updatingLine2= *updatingLine;

                int value=remainValue;
//                cout << " remain value " << value << endl ;
                Line *pushingLine=sText.lines.at(0);
                int boundWord=0;
                for (int i = 0; i <=j ; ++i) {
//                    cout << " every word " << i << " " << pushingLine->words.at(i)<< endl ;
                    if(pushingLine->words.at(i).size()<value){
//                        cout << " can add this word"  << endl ;

                        updatingLine2.addWord(pushingLine->words.at(i));
                        value-=(1+pushingLine->words.at(i).size());
                        boundWord++;
//                        cout << " remain value in changing  " << value << " and bounded bourd"<< boundWord<< endl ;

                        haveSpace=true;

                    } else {
                        break;
                    }
                }
                if(haveSpace) {

                    newText.deleteLastLine();
                    Line *line=new Line(pushingLine->limit);
                    *line=updatingLine2;
                    newText.addLine(line);
                    Line *newLine=new Line(pushingLine->limit);

                    for (int i = boundWord; i <pushingLine->words.size() ; ++i) {
                        newLine->addWord(pushingLine->words.at(i));
//                        cout << pushingLine->words.at(i) << " push shod " << endl;
                    }
                    for (int k = 1; k <sText.lines.size() ; ++k) {
//                        if(haveSpace && k==0) continue;
//                        cout << k << " K PUSH  " << endl;

                        newText.addLine(sText.lines.at(k));
                    }
                    newText.calTotalValue();
                    mainText.calTotalValue();
                    if (newText.totalValue<mainText.totalValue) {
                        mainText=newText;
                    }
                }else{

                    for (int k = 0; k <sText.lines.size() ; ++k) {
//                        if(haveSpace && k==0) continue;
                        mainText.addLine(sText.lines.at(k));
                    }
                }

            }
        }
    }else {

        for (int k = 0; k <sText.lines.size() ; ++k) {
            mainText.addLine(sText.lines.at(k));
//            cout << " just test "  << endl;
        }

    }
    return mainText;

//


}
/*
void textJustifications(Text **text,int first , int last ,int  limitation){
    cout << "test firt "<< first  <<" last " <<last<< endl;

    if(last-first<=1){
        cout << "test a"<<endl;

        Line *line2= new  Line(limitation);
        line2->addWord(allWords.at(first));
        (*text)->addLine(line2);
        if(last-first>0) {
            if (allWords.at(first).size() + allWords.at(last).size()+1 <= limitation) {


                line2->addWord(allWords.at(last));
            } else {
                Line *line3 = new Line(limitation);

                line3->addWord(allWords.at(last));
                (*text)->addLine(line3);

            }
        }
        return;
    }

    for (int i = first; i <last ; ++i) {

        cout <<  " i " << i << endl;
        Text *newText1 = new Text;
        textJustifications(&newText1,first,i,limitation);
        int valueOfLastLine=newText1->lastLine()->value;
        cout << "test value of last line "<< valueOfLastLine<< endl;

        Text *newText2 = new Text;

        int bound = i + 1;

//        if(valueOfLastLine==0){
//
//        }else {
//            for (int j = bound; j < last; ++j) {
//                if (allWords.at(j).size() <= valueOfLastLine) {
//                    bound++;
//                    valueOfLastLine -= allWords.at(j).size();
//                } else {
//                    break;
//                }
//            }
//            cout << "test bound " << bound << endl;
//
//            Line *newLine = new Line(limitation);
//
//            Line *lastLine_fNewText1 = newText1->lastLine();
//            for (int j = 0; j < lastLine_fNewText1->words.size(); j++) {
//                newLine->addWord(lastLine_fNewText1->words.at(j));
//            }
//            for (int k = i + 1; k < bound; ++k) {
//                newLine->addWord(allWords.at(k));
//            }
//            newText1->deleteLastLine();
//            newText1->addLine(newLine);
//        }
        textJustifications(&newText2,bound,last,limitation);

        Text *mainText= new Text;
        mainText=newText1->add(newText2);
        show(mainText);
        cout << " text main "<<endl;

        mainText->calTotalValue();

        cout << " text cal value  "<<mainText->totalValue <<endl;
        (*text)->calTotalValue();
        if(mainText->totalValue<(*text)->totalValue){
            *text=mainText;

            cout << " can replace them to them "<<endl ;
            show(mainText);

        }

    }
}
*/
 void textJustificationDp(int n, int limitation  ){
    Text *texts=new Text;

    for (int l = 0; l <n ; ++l) {


        Line *line2= new  Line(limitation);
        line2->addWord(allWords.at(l));
        majorText[l][l].addLine(line2);

    }
    for (int i = n-1; i >=0 ; i--) {

        for (int j = i; j <n ; ++j) {


        cout << " this  is i " << i<< " & J " << j<< endl;


            for (int k = i; k <j; ++k) {


                cout << " K " << k << endl;
//                if(k==1 && j ==3 && i == 1) {
//                    cout << " testvpedar sokhte  " << k << endl;
//                    show(&majorText[1][1]);
//                    cout << " testvpedar sag " << k << endl;
//
//                }
                Text *newText1 = new Text;
                *newText1=majorText[i][k];

                show(newText1);

                cout << " i  "<< i << " & k "<< k <<endl;
                Text *newText2 = new Text;

                int bound = k + 1;

              *newText2=majorText[bound][j];
                show(newText2);


                cout << "bound  "<< bound<< " & j "<< j<< endl;
              Text mainText;

                mainText = combainTextes(majorText[i][k],majorText[bound][j]);

//                majorText[i][j]=mainText;
//                newText1=&mainText;

                mainText.calTotalValue();
                if(majorText[i][j].lines.empty()) {
                    show(&mainText);

                    cout << " text main i  "<< i << " j "<<j<<endl;
                    majorText[i][j]=mainText;
                }
                else {
                    majorText[i][j].calTotalValue();

                    if (mainText.totalValue < majorText[i][j].totalValue) {
                        show(&mainText);

                        cout << " text main i  "<< i << " j "<<j<<endl;
                        majorText[i][j]= mainText;
                    }
                }
            }
        }


    }

};
int main() {
    cout << " write your text without any enter " << endl;

    int n=4 ;
//    cin >>"write num of words" >> n ;
//    allWords.clear();
//    for (int j = 0; j <n ; ++j) {
//        string word;
//        cin >> word;
//        allWords.push_back(word);
//    }
    (majorText) = new Text*[n];
    for(int i = 0; i < n; ++i) {
        majorText[i] = new Text[n];
    }

    allWords={
            "aaa" , "bb","cccc" ,"dddddd"
    };
    Text *text= new Text;
    n=4;

    textJustificationDp(4,10);
     cout << "show final mission :"<<endl ;
     show(&majorText[0][3]);

    return 0;
}