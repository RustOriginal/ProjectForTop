
#pragma once
#ifndef HANGMAN_H
#define HANGMAN_H

#include <string>
using namespace std;

class Hangman
{
public:
    Hangman(const string& word, int maxWrong);
    void play();

private:
    string THE_WORD;
    int MAX_WRONG;
    string soFar;
    string used;
};

#endif
