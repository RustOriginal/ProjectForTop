#include "hangman.h"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <string>
#include <vector>

using namespace std;

void drawHangman(int wrong)
{
    cout << "   _______" << endl;
    cout << "  |/      |" << endl;

    if (wrong >= 1)
    {
        cout << "  |      (_)" << endl;
    }

    if (wrong == 2)
    {
        cout << "  |      \\|" << endl;
    }
    else if (wrong == 3)
    {
        cout << "  |      \\|/" << endl;
    }
    else if (wrong >= 4)
    {
        cout << "  |      \\|/" << endl;
        cout << "  |       |" << endl;
    }

    if (wrong == 5)
    {
        cout << "  |       |" << endl;
        cout << "  |      /" << endl;
    }
    else if (wrong == 6)
    {
        cout << "  |       |" << endl;
        cout << "  |      / \\" << endl;
    }

    cout << " _|_" << endl;
    cout << "|   |______" << endl;
    cout << "|          |" << endl;
    cout << "|__________|" << endl;
}

void drawBox(const string& text)
{
    cout << "+";
    for (size_t i = 0; i < text.length() + 2; ++i)
    {
        cout << "-";
    }
    cout << "+" << endl;

    cout << "| " << text << " |" << endl;

    cout << "+";
    for (size_t i = 0; i < text.length() + 2; ++i)
    {
        cout << "-";
    }
    cout << "+" << endl;
}

Hangman::Hangman(const string& word, int maxWrong) : THE_WORD(word), MAX_WRONG(maxWrong)
{
    soFar = string(word.length(), '-');
    used = "";
}

void Hangman::play()
{
    vector<string> words = { "GUESS", "HANGMAN", "DIFFICULT", "STORY", "HERO", "SAMPLE", "RICE" };

    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(words.begin(), words.end());

    THE_WORD = words[0];
    int wrong = 0;

    cout << "Welcome to ChErEsHnYa (Hangman). This game was made by Rust, so, good luck to you.\n";

    while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
    {
        cout << "\n\nYou have " << (MAX_WRONG - wrong) << " incorrect guesses left.\n";
        cout << "\nYou've used the following letters:\n" << used << endl;
        drawBox(soFar);

        char guess;
        cout << "\n\nEnter your guess: ";
        cin >> guess;
        guess = toupper(guess);

        while (used.find(guess) != string::npos)
        {
            cout << "\nYou've already guessed " << guess << endl;
            cout << "Enter your guess: ";
            cin >> guess;
            guess = toupper(guess);
        }

        used += guess;

        if (THE_WORD.find(guess) != string::npos)
        {
            cout << "That's right! " << guess << " is in the word.\n";

            for (unsigned int i = 0; i < THE_WORD.length(); ++i)
            {
                if (THE_WORD[i] == guess)
                {
                    soFar[i] = guess;
                }
            }
        }
        else
        {
            cout << "Sorry, " << guess << " isn't in the word.\n";
            ++wrong;
            drawHangman(wrong);
        }
    }

    if (wrong == MAX_WRONG)
    {
        cout << "\nYou've been hanged!";
    }
    else
    {
        cout << "\nYou guessed it!";
    }

    cout << "\nThe word was " << THE_WORD << endl;
}

