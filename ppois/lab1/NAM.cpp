#include "NAM.h"
#include <iostream>
using namespace std;


/*!
    \brief method of reading tape from a file with checking for compliance with the alphabet, in case of a match writing to a vector,in the opposite case, ignore and read further
    \param input , abc
    \return nothing (void type)
*/
void Tape::input(istream& input, vector <char> abc)
{
    string content;
    while (input >> content)
    {
        bool result = check(abc, content);
        if (result) tape.push_back(content);
        else continue;

    }
    printTape();
}


/*!
    \brief method of displaying the tape on the screen
    \param none
    \return nothing(void type)
*/
void Tape::printTape() 
{
    cout << "Tape:" << endl;
    for (int i = 0; i < tape.size(); i++)
    {
        for (int j = 0; j < tape[i].length(); j++)
        {
            cout << tape[i][j];
        }
        cout << " ";
    }
    cout << endl;

}

/*!
    \brief  method of change the value in a tape cell
    \param index,str
    \return nothing(void type)
*/
void Tape::change(int index, string str)
{
    tape[index] = str;
    printTape();
}

//void Tape::add(string str) 
//{
//    tape.push_back(str);
//    printTape();
//}

/*!
    \brief  method of getting tape values
    \param none
    \return vector<string> tape with values
*/
vector <string> Tape::getTape()
{
    return tape;
}

/*!
    \brief  method of setting tape values
    \param values
    \return nothing(void type)
*/
void Tape::setTape(vector<string> values)
{
    tape.resize(values.size());
    for (int i = 0; i < values.size(); i++)
    {
        tape[i] = values[i];
    }
}

/*!
    \brief method of checking the tape for compliance with the alphabet
    \param alphabet,str
    \return true in case of complete coincidence of the word with the alphabet, false if a character is found that is not in the alphabet
*/
bool Tape::check(vector <char> alphabet, string str)
{
    for (int i = 0; i < str.length(); i++) {
        for (int j = 0; j < alphabet.size(); j++) {
            if (str[i] == alphabet[j]) break;
            if (j == alphabet.size() - 1 && str[i] !=alphabet[j]) 
            {
                cout << "Element is uncorrect" << endl;
                return false;
            }
        }
    }
    return true;

}


/*!
    \brief method of reading alphabet from a file and writing to a vector
    \param input
    \return nothing(void type)
*/
void Alphabet::input(istream& input)
{
    char  element;
    while (input >> element)
    {
        alphabet.push_back(element);
    }
    showAlphabet();
}

/*!
    \brief  method of getting alphabet values
    \param none
    \return vector<char> with alphabet values
*/
vector<char> Alphabet::getAlphabet()
{
    return alphabet;
}

/*!
    \brief  method of setting alphabet values
    \param values
    \return nothing(void type)
*/
void Alphabet::setAlphabet(vector<char> values)
{
    alphabet.resize(values.size());
    for (int i = 0; i < values.size(); i++)
    {
        alphabet[i] = values[i];
    }
}

/*!
    \brief method of displaying the alphabet on the screen
    \param none
    \return nothing(void type)
*/
void Alphabet::showAlphabet()
{
    cout << "Alphabet:" << endl;
    for (int i = 0; i < alphabet.size(); i++)
    {
        cout << alphabet[i]<<" ";
    }
    cout << endl;
}

/*!
    \brief method of reading rules from a file with checking for compliance with the alphabet, in case of a match writing to a vector,in the opposite case, ignore and read further
    \param input , abc
    \return nothing (void type)
*/

void Rules::input(istream& input, vector<char> abc)
{
    string from;
    string to;
   
    while (input >> from >> to)
    {
        pair<string, string> rule(from, to);
        bool result = check(abc, from);
        if (result == false) continue;
        else
        {
            rules.push_back(rule);
        } 
     
    }
    showRules();

}

/*!
    \brief method of displaying the rules on the screen
    \param none
    \return nothing(void type)
*/
void Rules::showRules () 
{
    cout << "Rules:" << endl;
    for (int i = 0; i < rules.size(); i++)
    {
        for (int j = 0; j < rules[i].first.length(); j++)
        {
            cout << rules[i].first[j];
        }
        cout << "->";
        for (int k= 0; k < rules[i].second.length(); k++)
        {
            cout << rules[i].second[k];
        }
        cout << endl;

    }
    cout << endl;
}

/*!
    \brief  method of getting rules values
    \param none
    \return vector<pair<string,string>>
*/
vector<pair<string, string>> Rules::getRules()
{
    return rules;
}

/*!
    \brief  method of setting rules values
    \param values
    \return nothing(void type)
*/
void Rules::setRules(vector<pair<string, string>> values)
{
    rules.resize(values.size());
    for (int i = 0; i < values.size(); i++)
    {
        rules[i].first = values[i].first;
        rules[i].second = values[i].second;
    }
}

/*!
    \brief method of checking the rules for compliance with the alphabet
    \param alphabet,str(the first part of the rule)
    \return true in case of complete coincidence of the word with the alphabet, false if a character is found that is not in the alphabet
*/
bool Rules::check(vector <char> alphabet, string str) 
{
    for (int i = 0; i < str.length(); i++) {
        for (int j = 0; j < alphabet.size(); j++) {
            if (str[i] == alphabet[j]) break;
            if (j == alphabet.size() - 1) 
            {
                cout << "Rule is uncorrect" << endl;
                return false;
            }
        }
    }
    return true;
}

/*!
    \brief method of reading rules,alphabet(calling methodes of input for classes Alphabet,Tape,Rules)
    \param tapeInput,rulesInput,alphabetInput
    \return nothing (void type)
*/
void NAM::input(istream& tapeInput, istream& rulesInput, istream& alphabetInput)///В качестве параметров принимает ссылки на три объекта класса istream(файл содержащий ленту,алфавит и правила)

{
    alphabetObjekt.input(alphabetInput);
    tapeObjekt.input(tapeInput, alphabetObjekt.getAlphabet());
    rulesObjekt.input(rulesInput, alphabetObjekt.getAlphabet());

}

/*!
    \brief method for executing Markov algorithms
    \param none
    \return nothing (void type)
*/
void NAM::run()
{
    vector<pair<string, string>> getRules = rulesObjekt.getRules();
    size_t j = getRules.size();

    for (int i = 0; i < getRules.size(); i++)
    {
        step(getRules[i]);
    }
    j--;

}

/*!
    \brief method of executing one step of the algorithm
    \param Rule
    \return nothing (void type)
*/
void NAM::step(pair<string, string> Rule) 
{
    vector<string> getTape = tapeObjekt.getTape();
    for (int i = 0; i < getTape.size(); i++)
    {
        if (getTape[i] == Rule.first) tapeObjekt.change(i, Rule.second);
    }
}

/*!
    \brief  method of getting alphabet values(calling method of class Alphabet)
    \param none
    \return vector<char> with alphabet values
*/
vector<char> NAM::getAlphabetObjekt()///не принимает параметров
{
    return alphabetObjekt.getAlphabet();
}

/*!
    \brief  method of setting alphabet values(calling method of class Alphabet)
    \param values
    \return nothing(void type)
*/
void NAM::setAlphabetObjekt(vector<char> values)
{
    alphabetObjekt.setAlphabet(values);
}

/*!
    \brief  method of setting tape values(calling method of class Tape)
    \param values
    \return nothing(void type)
*/
void NAM::setTapeObjekt(vector<string> values)
{
    tapeObjekt.setTape(values);
}

/*!
    \brief  method of getting tape values(calling method of class Tape)
    \param none
    \return vector<string> with alphabet values
*/
vector<string> NAM::getTapeObjekt()
{
    return tapeObjekt.getTape();
}

/*!
    \brief  method of setting rules values(calling method of class Rules)
    \param values
    \return nothing(void type)
*/
void NAM::setRulesObjekt(vector<pair<string, string>> values)
{
    rulesObjekt.setRules(values);
}

/*!
    \brief  method of getting rules values(calling method of class Rules)
    \param none
    \return vector<pair<string,string>> with rules values
*/
vector<pair<string, string>> NAM::getRulesObjekt()
{
    return rulesObjekt.getRules();
}

/*!
    \brief method of displaying the result of algorithm work on the screen(calling method of class Tape)
    \param none
    \return nothing(void type)
*/
void NAM::print()
{
    cout << "Result:" << endl;
    tapeObjekt.printTape();
   
}
