#include <iostream>
#include <string>


int* patternMap(std::string pattern) //do cofania po wzorcu
{
    int patternLength = pattern.length(), longestPrefix = 0;
    int* tab = new int[patternLength];
    tab[0] = 0; //pattern jednoznakowego prefixu nie moze byc niepusty

    for (int i = 1; i < patternLength; i++) 
    {
        if (pattern[longestPrefix] == pattern[i])
        {
            longestPrefix++;
        }
        else
        {
            while (longestPrefix > 0 && pattern[longestPrefix] != pattern[i]) //jak nie pasuja to cofka do pasujacego prefixa/sufixa
            {
                longestPrefix = tab[longestPrefix - 1];
            }
        }
        tab[i] = longestPrefix;
    }
    return tab;
}

void displayPatternMap(int* tab, int length) 
{
    for (int i = 0; i < length; ++i) 
    {
        std::cout << tab[i] << " ";
    }
    std::cout << std::endl;
}


void KMP(std::string text, std::string pattern)
{
    int* tab = patternMap(pattern);
    int textLength = text.length();
    int patternLength = pattern.length();
    int textIndex = 0;
    int patternIndex = 0;

    // Przechodzenie przez cały tekst
    while (textIndex < textLength)
    {
        if (pattern[patternIndex] == text[textIndex])//sprawdzenie czy znaki do siebie pasuja
        {
            if (patternIndex == patternLength - 1) //znalazl
            {
                std::cout << "Wzorzec znaleziony na " << textIndex - patternIndex + 1 <<" pozycji." << std::endl;
                patternIndex = tab[patternIndex]; 
                textIndex++;
            }
            else
            {
                patternIndex++;
                textIndex++;
            }
        }
        else
        {
            // w przypadku niezgodności znaków
            if (patternIndex != 0)
            {
                // cofka we wzorcu zgodnie z tablica prefiksow
                patternIndex = tab[patternIndex - 1];
            }
            else
            {
                textIndex++;
            }
        }
    }

    delete[] tab;
}


int main() 
{
    std::string text = "ABC ABCDAB ABCDABCDABDE";
    std::string pattern = "CDA";
    KMP(text, pattern);
    return 0;
}
