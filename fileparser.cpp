#include "fileparser.h"

#include <QDebug>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <QFile>
#include "iterator.h"
#include "field.h"

using namespace std;

// ****************************************************************************************************
// public members

FileParser::FileParser()
{
}

//GameBoard *FileParser::createBoard(QString filename)
//{
//    qDebug() <<  "parese file " << filename;
//    int fields = 0;             // number of the field
//    string fieldArray[257];     // array of lines from the file


//    QFile boardFile(filename);
//    QString fieldStrings[257];


//    if (boardFile.isOpen()){
//        while(!boardFile.atEnd()){
//            fieldStrings[fields] = boardFile.readLine();
//            fieldArray[fields] = fieldStrings[fields].toStdString();
//            fields++;
//        }
//    }else{
//        qDebug() << "cannot open file" << filename;
//    }
//    boardFile.close();
//    qDebug() <<  fields << " fields found in " << filename;
//    switch(fields){
//    case 37:
//        qDebug() << "seems to be the european board";
//        break;
//    case 33:
//        qDebug() << "seems to be the english board";
//        break;
//    }

//    // create empty board depending on the amount of fields in the file
//    GameBoard *m_gameBoard = new GameBoard(fields);

//    Iterator gameIterator(m_gameBoard);
//    gameIterator.resetToFirst();

//    for(int i = 0; i < fields; i++){
//        gameIterator.insert(i == 0 ? false : true,i,0,0,0,0,0,0,0);
//        ++gameIterator;
//    }

//    qDebug() << "empty board crated";

//    Iterator iterator(m_gameBoard);
//    Iterator iteratorSearch2(m_gameBoard);

//    iterator.resetToFirst();
//    iteratorSearch2.resetToFirst();



//    // line format--->       <Fieldnumber>:<west>,<east>,<north>,<south>
//    // for every field

//    for( int i = 0; i < fields; i++){

//        //************************************************************************************************
//        //PHARSE LINE

//        int neighboursCount = 0;
//        int doublePoint = 0;
//        int firstColon = 0;
//        int secondColon = 0;
//        int thirdColon = 0;

//        //cout << fieldArray[i] << endl;
//        // go trough the line and safe positions of ':' and ','
//        for (unsigned int j=1; j < fieldArray[i].length()+1 ; j++){
//            // if a ':' was found: safe the position of ':' in the doublePoint variable
//            if (fieldArray[i].substr(j,1) == ":"){
//                doublePoint = j;
//                //cout << "\tdouble point: " << doublePoint << endl;
//            }
//            // if a ',' was found: safe the position of the ','
//            if (fieldArray[i].substr(j,1) == ","){
//                neighboursCount++;

//                // safe the positions of the colons to the variables first, second....
//                switch(neighboursCount){
//                case 1:
//                    firstColon = j;
//                    //cout << "\tfirst colon: " << firstColon << endl;
//                    break;
//                case 2:
//                    secondColon = j;
//                    //cout << "\tsecond colon: " << secondColon << endl;
//                    break;
//                case 3:
//                    thirdColon = j;
//                    //cout << "\tthird colon: " << thirdColon << endl << endl << endl;
//                    break;
//                }
//            }
//        }
//        if (neighboursCount != 3){
//            qDebug() << "error found in line " << fields << ": not the right amount of neighbors";
//        }
//        //cout << "in field " << fields << " are " << neighboursCount+1 << " neighbors" << endl;

//        //************************************************************************************************
//        //SAFE NEIGHBOURS
//        string fieldStr = fieldArray[i].substr(0,doublePoint);
//        string westStr = fieldArray[i].substr(doublePoint+1,firstColon-doublePoint);
//        string eastStr = fieldArray[i].substr(firstColon+1,secondColon-firstColon);
//        string northStr = fieldArray[i].substr(secondColon+1,thirdColon-secondColon);
//        string southStr = fieldArray[i].substr(thirdColon+1);

//        int fieldNumber = atoi(fieldStr.c_str());
//        int north = atoi(northStr.c_str());
//        int south = atoi(southStr.c_str());
//        int east = atoi(eastStr.c_str());
//        int west= atoi(westStr.c_str());



//        qDebug() << "------------------------------------";
//        qDebug() << "\t" << fieldNumber << ": W= " << west;
//        qDebug() << "\t" << fieldNumber << ": O= " << east;
//        qDebug() << "\t" << fieldNumber << ": N= " << north;
//        qDebug() << "\t" << fieldNumber << ": S= " << south;


//        //************************************************************************************************
//        //LINK THE LIST

//        //cout << "iterator 1 at the field " << iterator.getCurrentNumber() << endl;

//        // Set south field
//        if(south >= 0){
//            // go with the second iterator to the south fiel
//            iteratorSearch2.resetToFirst();
//            while(iteratorSearch2.getCurrentNumber() != south){
//                ++iteratorSearch2;
//            }
//            iterator.setNeighbors(0,iteratorSearch2.getCurrentField(),0,0);
//            //cout << "south field set to " << iteratorSearch2.getCurrentNumber() << endl << endl <<endl;

//        }
//        // Set north field
//        if(north >= 0){
//            // go with the second iterator to the north fiel
//            iteratorSearch2.resetToFirst();
//            while(iteratorSearch2.getCurrentNumber() != north){
//                ++iteratorSearch2;
//            }
//            iterator.setNeighbors(iteratorSearch2.getCurrentField(),0,0,0);
//            //cout << "north field set to " << iteratorSearch2.getCurrentNumber() << endl << endl <<endl;

//        }

//        // Set east field of the current field
//        if(east >= 0){
//            // go with the second iterator to the east fiel
//            iteratorSearch2.resetToFirst();
//            while(iteratorSearch2.getCurrentNumber() != east){
//                ++iteratorSearch2;
//            }
//            iterator.setNeighbors(0,0,iteratorSearch2.getCurrentField(),0);
//            //cout << "east field set to " << iteratorSearch2.getCurrentNumber() << endl << endl <<endl;

//        }
//        // Set west field
//        if(west >= 0){
//            // go with the second iterator to the east fiel
//            iteratorSearch2.resetToFirst();
//            while(iteratorSearch2.getCurrentNumber() != west){
//                ++iteratorSearch2;
//            }
//            iterator.setNeighbors(0,0,0,iteratorSearch2.getCurrentField());
//            //cout << "west field set to " << iteratorSearch2.getCurrentNumber() << endl << endl <<endl;

//        }

//        ++iterator;
//    }

//    qDebug() << "connections between fields created...";
//    qDebug() << "clean board with all connections created! :)";

//    return m_gameBoard;

//}




GameBoard *FileParser::createBoard(const char* file)
{
    QString fileName(QLatin1String(file));
    QFile qfile(":/european.txt");

    if(!qfile.open(QIODevice::ReadOnly)) {
        qDebug() << "cannot open file";
    }

    qDebug() << qfile.readAll();



    qDebug() <<  "parese file " << file;
    int fields = 0;             // number of the field
    string fieldArray[257];     // array of lines from the file
    char line[50];              // a line from the file (never longer than 50 characters)

    ifstream fileStream(file);

    if (fileStream.is_open()){
        while(fileStream.getline(line,100)){
            fieldArray[fields] = line;
            fields++;
        }
    }else{
        qDebug() << "cannot open file" << file;
    }
    fileStream.close();
    qDebug() <<  fields << " fields found in " << file;
    switch(fields){
    case 37:
        qDebug() << "seems to be the european board";
        break;
    case 33:
        qDebug() << "seems to be the english board";
        break;
    }

    // create empty board depending on the amount of fields in the file
    GameBoard *m_gameBoard = new GameBoard(fields);

    Iterator gameIterator(m_gameBoard);
    gameIterator.resetToFirst();

    for(int i = 0; i < fields; i++){
        //gameIterator.insert(i == 0 ? false : true,i,0,0,0,0,0,0,0);
        gameIterator.insert(true,i,0,0,0,0,0,0,0);
        ++gameIterator;
    }

    qDebug() << "empty board crated";

    Iterator iterator(m_gameBoard);
    Iterator iteratorSearch2(m_gameBoard);

    iterator.resetToFirst();
    iteratorSearch2.resetToFirst();



    // line format--->       <Fieldnumber>:<west>,<east>,<north>,<south>
    // for every field

    for( int i = 0; i < fields; i++){

        //************************************************************************************************
        //PHARSE LINE

        int neighboursCount = 0;
        int doublePoint = 0;
        int firstColon = 0;
        int secondColon = 0;
        int thirdColon = 0;

        //cout << fieldArray[i] << endl;
        // go trough the line and safe positions of ':' and ','
        for (unsigned int j=1; j < fieldArray[i].length()+1 ; j++){
            // if a ':' was found: safe the position of ':' in the doublePoint variable
            if (fieldArray[i].substr(j,1) == ":"){
                doublePoint = j;
                //cout << "\tdouble point: " << doublePoint << endl;
            }
            // if a ',' was found: safe the position of the ','
            if (fieldArray[i].substr(j,1) == ","){
                neighboursCount++;

                // safe the positions of the colons to the variables first, second....
                switch(neighboursCount){
                case 1:
                    firstColon = j;
                    //cout << "\tfirst colon: " << firstColon << endl;
                    break;
                case 2:
                    secondColon = j;
                    //cout << "\tsecond colon: " << secondColon << endl;
                    break;
                case 3:
                    thirdColon = j;
                    //cout << "\tthird colon: " << thirdColon << endl << endl << endl;
                    break;
                }
            }
        }
        if (neighboursCount != 3){
            qDebug() << "error found in line " << fields << ": not the right amount of neighbors";
        }
        //cout << "in field " << fields << " are " << neighboursCount+1 << " neighbors" << endl;

        //************************************************************************************************
        //SAFE NEIGHBOURS
        string fieldStr = fieldArray[i].substr(0,doublePoint);
        string westStr = fieldArray[i].substr(doublePoint+1,firstColon-doublePoint);
        string eastStr = fieldArray[i].substr(firstColon+1,secondColon-firstColon);
        string northStr = fieldArray[i].substr(secondColon+1,thirdColon-secondColon);
        string southStr = fieldArray[i].substr(thirdColon+1);

        int fieldNumber = atoi(fieldStr.c_str());
        int north = atoi(northStr.c_str());
        int south = atoi(southStr.c_str());
        int east = atoi(eastStr.c_str());
        int west= atoi(westStr.c_str());



        qDebug() << "------------------------------------";
        qDebug() << "\t" << fieldNumber << ": W= " << west;
        qDebug() << "\t" << fieldNumber << ": O= " << east;
        qDebug() << "\t" << fieldNumber << ": N= " << north;
        qDebug() << "\t" << fieldNumber << ": S= " << south;


        //************************************************************************************************
        //LINK THE LIST

        //cout << "iterator 1 at the field " << iterator.getCurrentNumber() << endl;

        // Set south field
        if(south >= 0){
            // go with the second iterator to the south fiel
            iteratorSearch2.resetToFirst();
            while(iteratorSearch2.getCurrentNumber() != south){
                ++iteratorSearch2;
            }
            iterator.setNeighbors(0,iteratorSearch2.getCurrentField(),0,0);
            //cout << "south field set to " << iteratorSearch2.getCurrentNumber() << endl << endl <<endl;

        }
        // Set north field
        if(north >= 0){
            // go with the second iterator to the north fiel
            iteratorSearch2.resetToFirst();
            while(iteratorSearch2.getCurrentNumber() != north){
                ++iteratorSearch2;
            }
            iterator.setNeighbors(iteratorSearch2.getCurrentField(),0,0,0);
            //cout << "north field set to " << iteratorSearch2.getCurrentNumber() << endl << endl <<endl;

        }

        // Set east field of the current field
        if(east >= 0){
            // go with the second iterator to the east fiel
            iteratorSearch2.resetToFirst();
            while(iteratorSearch2.getCurrentNumber() != east){
                ++iteratorSearch2;
            }
            iterator.setNeighbors(0,0,iteratorSearch2.getCurrentField(),0);
            //cout << "east field set to " << iteratorSearch2.getCurrentNumber() << endl << endl <<endl;

        }
        // Set west field
        if(west >= 0){
            // go with the second iterator to the east fiel
            iteratorSearch2.resetToFirst();
            while(iteratorSearch2.getCurrentNumber() != west){
                ++iteratorSearch2;
            }
            iterator.setNeighbors(0,0,0,iteratorSearch2.getCurrentField());
            //cout << "west field set to " << iteratorSearch2.getCurrentNumber() << endl << endl <<endl;

        }

        ++iterator;
    }

    qDebug() << "connections between fields created...";
    qDebug() << "clean board with all connections created! :)";

    return m_gameBoard;

}

//void FileParser::printFieldConnections()
//{
//    Iterator iterator(m_gameBoard);
//    iterator.resetToFirst();
//    while(iterator.getCurrentField() != m_gameBoard.getLastField()){
//        qDebug() << "----------------------------------------------";
//        qDebug() << "Field"  << iterator.getCurrentField()->getFieldNumber() << "has neighbours:";
//        if(iterator.getCurrentField()->getNorthField()!=0)qDebug() << "\tn = " << iterator.getCurrentField()->getNorthField()->getFieldNumber();
//        if(iterator.getCurrentField()->getSouthField()!=0)qDebug() << "\ts = " << iterator.getCurrentField()->getSouthField()->getFieldNumber();
//        if(iterator.getCurrentField()->getEastField()!=0)qDebug() << "\te = " << iterator.getCurrentField()->getEastField()->getFieldNumber();
//        if(iterator.getCurrentField()->getWestField()!=0)qDebug() << "\tw = " << iterator.getCurrentField()->getWestField()->getFieldNumber();
//        ++iterator;
//    }
//}
