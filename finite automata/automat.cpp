#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

const int ASCII_SIZE = 256;

void automat(const std::string& pattern, int** transitionTable)
{
    int patternLength = pattern.length();
    for (int i = 0; i <= patternLength; i++)
    {
        for (int j = 0; j < ASCII_SIZE; j++)
        {
            int nextState = std::min(patternLength, i + 1);
            std::string patternPrefix = pattern.substr(0, i) + char(j);
            while (nextState > 0 && patternPrefix.substr(patternPrefix.length() - nextState) != pattern.substr(0, nextState))
            {
                nextState--;
            }
            transitionTable[i][j] = nextState;
        }
    }
}

int ctrl_f(const std::string& text, int** transitionTable, int patternLength)
{
    int textLength = text.length();
    int currentState = 0;
    for (int i = 0; i < textLength; i++)
    {
        currentState = transitionTable[currentState][static_cast<unsigned char>(text[i])];
        if (currentState == patternLength)
        {
            return i - patternLength + 1;
        }
    }
    return -1;
}

int main() {
    std::string text = "abababacaba";
    std::string pattern = "ababaca";

    int patternLength = pattern.length();

    int** stateTable = new int* [patternLength + 1];
    for (int i = 0; i <= patternLength; i++)
    {
        stateTable[i] = new int[ASCII_SIZE] {0};
    }

    automat(pattern, stateTable);
    int patternPosition = ctrl_f(text, stateTable, patternLength);


    if (patternPosition != -1) 
    {
        std::cout << "Wzorzec znaleziony na pozycji: " << patternPosition << std::endl;
    }
    else 
    {
        std::cout << "Wzorzec nie znaleziony." << std::endl;
    }


    for (int i = 0; i <= patternLength; i++)
    {
        delete[] stateTable[i];
    }

    delete[] stateTable;

    return 0;
}
