#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>

// TODO: IMPLEMENT FUNCTION THAT WILL REPLACE NUMBER WITH ENGLISH SUBTITUTE
typedef enum {
    ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE
} Number;

char* toUpper(char* string)
{
    char* newString = malloc(strlen(string));
    int i;
    for(i=0; i<strlen(string); i++)
    {
        newString[i] = toupper(string[i]);
    }
    // Adding string termination at the end of the string
    newString[i] = '\0';
    return newString;
}

char* toLower(char* string)
{
    char* newString = malloc(strlen(string));
    int i;
    for(i=0; i<strlen(string); i++)
    {
        newString[i] = tolower(string[i]);
    }
    // Adding string termination at the end of the string
    newString[i] = '\0';
    return newString;
}

char* replaceWithSeparator(char* string, char separator, char* upOrDown)
{
    int16_t stringLength = strlen(string);
    char* newString = malloc(stringLength);

    // What is offset? If the non aplhanumeric value is found on the beggining, on the end or there are two or more values
    // next to each other, we need to increase the offset. Why? Because the iterator in the loop increases even when no char is added
    // to new string. So without offset, values would be skipped from the original string.

    int16_t offset = 0;
    int i;
    for(i=0; i<stringLength; i++)
    {
        // If a value in input string is alphanumeric, simply add it to new string
        if(isalnum(string[i]))
        {
            newString[i-offset]=string[i];
            continue;
        }
        else
        {
            // Pretty ugly? First part checks on the first iteration if first char is alnum. If not, increase offset.
            // Second part chcecks if there are two non alnum values next to each other. If it is true, increase offset.
            // Reason why it is togheter it's because in both cases it does the same thing so code is similar,
            // but I wrote comment on four lines to explain it so it's not worth it :D
            if((i==0 && isalnum(string[i])==0) || (isalnum(string[i])==0 && isalnum(string[i+1])==0)){
                offset++;
                continue;
            }
            // If it just one single non alnum value, replace it with separator
            else
                newString[i-offset]=separator;       
        }
    }
    // Adding the string termination at the end of the string
    newString[i-offset]='\0';
    return newString;
}

char* replaceWithEnglishSubtitue(char* string)
{
    int16_t length = strlen(string);
    char* newString = (char *)malloc((length+1)*sizeof(char));
}

char* numberToString(Number number)
{
    switch (number)
    {
    case ZERO:
        return "zero";
        break;
    case ONE:
        return "one";
        break;
    case TWO:
        return "two";
        break;
    case THREE:
        return "three";
        break;
    case FOUR:
        return "four";
        break;
    case FIVE:
        return "five";
        break;
    case SIX:
        return "six";
        break;
    case SEVEN:
        return "seven";
        break;
    case EIGHT:
        return "eight";
        break;
    case NINE:
        return "nine";
        break;
    default:
        break;
    }
}


char* modifyString(char* string, char separator, char* upOrDown)
{
    char* tempString = replaceWithSeparator(string, separator, upOrDown);
    int16_t tempLength = strlen(tempString);
    char* newString = malloc(tempLength);
    if(upOrDown=="UP")
        newString = toUpper(tempString);
    else if(upOrDown=="LOW")
        newString = toLower(tempString);
    else
        return tempString;
    
    return newString;
}

int main(void)
{
    char str[] = "!Hello!World$!$123)";
    char sep = '-';
    printf("%s", modifyString(str, sep, "LOW"));
}