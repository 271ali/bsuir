#include <iostream>
#include"NAM.h"
#include<fstream>

using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    ifstream tapeInput("tape.txt");
    ifstream rulesInput("rules.txt");
    ifstream alphabetInput("alphabet.txt");
    NAM objekt;
    objekt.input(tapeInput, rulesInput, alphabetInput);
    objekt.run();
    objekt.print();
}