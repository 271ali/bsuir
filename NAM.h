#pragma once
#pragma once
#include <iostream>
#include <vector>
#include<sstream>
#include <map>
#include <set>
using namespace std;


class Tape
{
public:
    void input(istream&, vector<char>);
    void printTape();
    void change(int, string);
    void add(string str);
    vector <string> getTape();
    void setTape(vector<string>);
    bool check(vector<char>, string);

private:

    vector<string> tape;
};

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