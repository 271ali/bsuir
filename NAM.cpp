#include "NAM.h"
#include <iostream>
using namespace std;

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

void Tape::change(int index, string str)//помен€ть значение в одной €чейке ленты
{
    tape[index] = str;
    //print();
}
void Tape::add(string str) //добавить элемент в ленту
{
    tape.push_back(str);
    //print();
}
vector <string> Tape::getTape() //геттер дл€ ленты
{
    return tape;
}
void Tape::setTape(vector<string> values)
{
    tape.resize(values.size());
    for (int i = 0; i < values.size(); i++)
    {
        tape[i] = values[i];
    }
}
bool Tape::check(vector <char> alphabet, string str)
{
    for (int i = 0; i < str.length(); i++) {
        for (int j = 0; j < alphabet.size(); j++) {
            if (str[i] == alphabet[j]) break;
            if (j == alphabet.size() - 1 && str[i] !=alphabet[j]) {
                cout << "Element is uncorrect" << endl;
                return false;
            }
        }
    }
    return true;

}
void Alphabet::input(istream& input)
{
    char  element;
    while (input >> element)
    {
        alphabet.push_back(element);
    }
    showAlphabet();
}
vector<char> Alphabet::getAlphabet()
{
    return alphabet;
}
void Alphabet::setAlphabet(vector<char> values)
{
    alphabet.resize(values.size());
    for (int i = 0; i < values.size(); i++)
    {
        alphabet[i] = values[i];
    }

}
void Alphabet::showAlphabet()
{
    cout << "Alphabet:" << endl;
    for (int i = 0; i < alphabet.size(); i++)
    {
        cout << alphabet[i]<<" ";
    }
    cout << endl;
}
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
    cout<<endl;
}
vector<pair<string, string>> Rules::getRules()
{
    return rules;
}
void Rules::setRules(vector<pair<string, string>> values)
{
    rules.resize(values.size());
    for (int i = 0; i < values.size(); i++)
    {
        rules[i].first = values[i].first;
        rules[i].second = values[i].second;
    }
}
bool Rules::check(vector <char> alphabet, string str) //тест
{
    for (int i = 0; i < str.length(); i++) {
        for (int j = 0; j < alphabet.size(); j++) {
            if (str[i] == alphabet[j]) break;
            if (j == alphabet.size() - 1) {
                cout << "Rule is uncorrect" << endl;
                return false;
            }
        }
    }
    return true;
}

void NAM::input(istream& tapeInput, istream& rulesInput, istream& alphabetInput)

{
    alphabetObjekt.input(alphabetInput);
    tapeObjekt.input(tapeInput, alphabetObjekt.getAlphabet());
    rulesObjekt.input(rulesInput, alphabetObjekt.getAlphabet());

}

void NAM::run()//тест
{
    vector<pair<string, string>> getRules = rulesObjekt.getRules();
    size_t j = getRules.size();

    for (int i = 0; i < getRules.size(); i++)
    {
        step(getRules[i]);
    }
    j--;

}
void NAM::step(pair<string, string> Rule) //тест
{
    vector<string> getTape = tapeObjekt.getTape();
    for (int i = 0; i < getTape.size(); i++)
    {
        if (getTape[i] == Rule.first) tapeObjekt.change(i, Rule.second);
    }
}
vector<char> NAM::getAlphabetObjekt()
{
    return alphabetObjekt.getAlphabet();
}
void NAM::setAlphabetObjekt(vector<char> values)
{
    alphabetObjekt.setAlphabet(values);
}
void NAM::setTapeObjekt(vector<string> values)
{
    tapeObjekt.setTape(values);
}
vector<string> NAM::getTapeObjekt()
{
    return tapeObjekt.getTape();
}
void NAM::setRulesObjekt(vector<pair<string, string>> values)
{
    rulesObjekt.setRules(values);
}
vector<pair<string, string>> NAM::getRulesObjekt()
{
    return rulesObjekt.getRules();
}
void NAM::print()
{
    cout << "Result:" << endl;
    tapeObjekt.printTape();
   
}
