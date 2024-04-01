#include <iostream>
#include <string>
#include <math.h>


#define charsLength 256
#define modulo  101

int ctrl_f(std::string text, std::string pattern)
{
    int textLength = text.length();
    int patternLength = pattern.length();

    //oblicza warto��, kt�ra jest u�ywana do aktualizacji warto�ci hash dla tekstu
    int multiplier = pow(charsLength, patternLength - 1); //do zachowania kolejnosci
    multiplier = multiplier % modulo;

    int textHash = 0;
    int patternHash = 0;

    for (int i = 0; i < patternLength; i++)
    {
        textHash = (charsLength * textHash + text[i]) % modulo;
        patternHash = (charsLength * patternHash + pattern[i]) % modulo;
    }

    int end = textLength - patternLength + 1; //unikniecie porownania wzorca jak zostala krotka czesc tekstu

    for (int i = 0; i < end; i++)
    {
        if (patternHash == textHash)
        {
            for (int j = 0; j < patternLength && text[i + j] == pattern[j]; j++)
            {
                if (j == patternLength - 1)
                    return i;
            }
        }

        textHash = (textHash - text[i] * multiplier) % modulo; //usuniecie pierwszego znaku
        if (textHash < 0) //po wsadzeniu wartosci z ASCII moze wyjsc liczba ujmena nie wieksza niz wartosc modulo
            textHash += modulo;

        textHash = (charsLength * textHash + text[i + patternLength]) % modulo; //dodanie nastepnego znaku
    }

    return NULL;
}

int main()
{
    std::string text = "ABCCBDADSBASFVBER:OWUBV:PYEWWECQPV TERWUBVIERBVEONWPWV";
    std::string pattern = ":OWU";

	int result = ctrl_f(text, pattern);

    if (result == NULL)
        std::cout << "Brak wzorca.\n";
    else
        std::cout << "Wzorzec znaleziony na pozycji: " << result + 1 << "\n";
}