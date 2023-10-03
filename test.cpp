#include "pch.h"
#include <fstream>
#include <vector>
#include "C:/Users/vgavr/source/repos/ppois_sem3_lab1_main/ppois_sem3_lab1_main/NAM.cpp"

TEST(TestNAM, change)
{
    Tape tape;
    vector <string> testTape = { "adhb","ouhefiwu","fehiwu" };
    tape.setTape(testTape);
    tape.change(1, "aaaa");
    vector <string> checkObjekt = tape.getTape();
    EXPECT_EQ(checkObjekt[1], "aaaa");
    EXPECT_TRUE(true);
}

TEST(TestNAM, add)
{
    Tape tape;
    string str = "aaaaaa";
    tape.add(str);
    vector <string> checkObjekt = tape.getTape();
    EXPECT_EQ(checkObjekt[0], "aaaaaa");
    EXPECT_TRUE(true);
}

TEST(TestNAM, checkTape)
{
    Tape tape;
    string elementOfTape = "1abdgrss";
    vector<char> values = { '1','a','b','d','g','r','s' };
    bool check = tape.check(values, elementOfTape);
    EXPECT_EQ(check, true);
    EXPECT_TRUE(true);
}

TEST(TestNAM, checkRules)
{
    Rules rules;
    string firstPartOfRule = "1abdgrss";
    vector<char> values = { '1','a','b','d','g','r','s' };
    bool check=rules.check(values, firstPartOfRule);
    EXPECT_EQ(check,true);
    EXPECT_TRUE(true);
}

TEST(TestNAM, step)
{
    pair<string, string> rule ("hello","bye");
    vector<string> tapeValues = { "hello_","hello","hellohello" };
    NAM objekt;
    objekt.setTapeObjekt(tapeValues);
    objekt.step(rule);
    vector<string> checkObjekt= { "hello_", "bye", "hellohello" };
    EXPECT_EQ ( checkObjekt, objekt.getTapeObjekt());
    EXPECT_TRUE(true);
}
//dayand night I write code in java I don't like c just like math hello
//nightand night I write code in java I don't like java just like physics bye
TEST(TestNAM, run)
{
    NAM objekt;
    vector<pair<string, string>> testRules = {pair<string,string> ("hello","bye") ,pair<string,string> ("day","night"),pair<string,string> ("c","java"),pair<string,string> ("I","you") };
    vector<string> testTape = {"hello","," ,"day","and","night","I","write","code","in","c"};
    vector<string> resultTape = { "bye","," ,"night","and","night","you","write","code","in","java" };
    objekt.setRulesObjekt(testRules);
    objekt.setTapeObjekt(testTape);
    objekt.run();
    EXPECT_EQ(resultTape,objekt.getTapeObjekt());
    EXPECT_TRUE(true);
}
TEST(TestNAM, inputTape)
{
    ifstream inputTape("tape.txt");
    Tape tape;
    vector<char> testAlphabet = { 'a','b','c','d','e'};
    tape.input(inputTape,testAlphabet);
    vector<string> checkObjekt = { "aaaa","d","aa","bbb","c","cc","eeeee"};
    EXPECT_EQ (checkObjekt, tape.getTape());
    EXPECT_TRUE(true);
}
TEST(TestNAM, inputALphabet)
{
    ifstream inputAlphabet("alphabet.txt");
    Alphabet alphabet;
    alphabet.input(inputAlphabet);
    vector<char> checkObjekt = {'a','m','k','q','p'};
    EXPECT_EQ(checkObjekt, alphabet.getAlphabet());
    EXPECT_TRUE(true);
}
TEST(TestNAM, inputRules)
{
    ifstream inputRules("rules.txt");
    Rules rules;
    vector<char> testAlphabet = { 'a','b','c','d','e'};
    rules.input(inputRules, testAlphabet);
    vector<pair<string,string>> checkObjekt = { pair<string,string>("aaaa","bbb"),pair<string,string>("cc","d"),pair<string,string>("eeeee","ff")};
    EXPECT_EQ(checkObjekt, rules.getRules());
    EXPECT_TRUE(true);
   
}

int main(int argc,char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}