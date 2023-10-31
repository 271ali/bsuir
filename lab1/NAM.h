#pragma once
#pragma once
#include <iostream>
#include <vector>
#include<sstream>
#include <map>
#include <set>
#include <locale.h>
using namespace std;

/*!
    \brief Implementation of the class Tape
*/
class Tape
{
public:
    void input(istream&, vector<char>);
    void printTape();
    void change(int, string);
    vector <string> getTape();
    void setTape(vector<string>);
    bool check(vector<char>, string);
private:
    vector<string> tape;
};

/*!
    \brief Implementation of the class Alphabet
*/
class Alphabet
{
public:

    void input(istream& input);
    vector<char> getAlphabet();
    void setAlphabet(vector<char>);
    void showAlphabet();

private:

    vector<char> alphabet;
};

/*!
    \brief Implementation of the class Rules
*/
class Rules
{
public:

    void input(istream& input, vector<char>);
    void showRules();
    vector<pair<string, string>> getRules();
    void setRules(vector<pair<string, string>>);
    bool check(vector <char> alphabet, string str);
   

private:

    vector <pair<string, string>> rules;

};
/*!
    \brief Implementation of the class NAM
*/
class NAM
{
public:

    void input(istream& tapeInput, istream& rulesInput, istream& alphabetInput);
    void run();
    void step(pair<string, string> Rule);
    void setAlphabetObjekt(vector<char>);
    vector<char> getAlphabetObjekt();
    void setTapeObjekt(vector<string>);
    vector<string> getTapeObjekt();
    void setRulesObjekt(vector<pair<string, string>>);
    vector<pair<string, string>> getRulesObjekt();
    void print();
private:

    Alphabet alphabetObjekt;
    Tape tapeObjekt;
    Rules rulesObjekt;

};