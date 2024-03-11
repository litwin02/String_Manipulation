#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>

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

char* replaceWithSeparator(char* string, char separator)
{
    int16_t stringLength = strlen(string);
    char* newString = malloc(stringLength);

    // What is offset? If the non aplhanumeric value is found on the beggining, on the end or there are two or more values
    // next to each other, we need to increase the offset. Why? Because the iterator in the loop increases even when no char is added
    // to new string. So without offset, values would be skipped from the original string.
    int8_t firstAlnum = 0;
    int16_t offset = 0;
    int i;
    for(i=0; i<stringLength; i++)
    {   
        // If a value in input string is alphanumeric, simply add it to new string
        if(isalnum(string[i]))
        {
            firstAlnum = 1;
            newString[i-offset]=string[i];
            continue;
        }
        else
        {
            // If there are two or more non alnum values next to each other, replace them with separator
            if((isalnum(string[i])==0 && isalnum(string[i+1])==0)){
                offset++;
                continue;
            }
            
            // If the non alnum value is found on the beggining, then start adding the separator
            else if(firstAlnum){
                newString[i-offset]=separator;
                continue;
            }
            offset++;        
        }
    }
    // Adding the string termination at the end of the string
    newString[i-offset]='\0';
    return newString;
}

char* replaceNumberWithEnglishSubstitute(char* string)
{
    // Allocating memory for the new string
    char* newString = malloc(sizeof(char)*(strlen(string)*3+1));
    // If the memory allocation fails, return NULL
    if (newString == NULL) {
        return NULL;
    }
    newString[0] = '\0';
    for(int i=0; i<strlen(string); i++)
    {
        if(isdigit(string[i]))
        {
            switch(string[i])
            {
                case '0':
                    strcat(newString, "zero");
                    break;
                case '1':
                    strcat(newString, "one");
                    break;
                case '2':
                    strcat(newString, "two");
                    break;
                case '3':
                    strcat(newString, "three");
                    break;
                case '4':
                    strcat(newString, "four");
                    break;
                case '5':
                    strcat(newString, "five");
                    break;
                case '6':
                    strcat(newString, "six");
                    break;
                case '7':
                    strcat(newString, "seven");
                    break;
                case '8':
                    strcat(newString, "eight");
                    break;
                case '9':
                    strcat(newString, "nine");
                    break;
            }
        }
        else
        {
            // creating a temporary string with the current character and adding it to the new string
            char temp[2] = {string[i], '\0'};
            strcat(newString, temp);
        }
    }
    return newString;
}

char* modifyString(char* string, char separator, char* upOrDown)
{
    char* tempString = replaceWithSeparator(string, separator);
    char* modifiedString = malloc(strlen(tempString));
    modifiedString = replaceNumberWithEnglishSubstitute(tempString);
    char* finalString = malloc(strlen(modifiedString));
    if(upOrDown=="UP")
        finalString = toUpper(modifiedString);
    else if(upOrDown=="LOW")
        finalString = toLower(modifiedString);
    else
        return modifiedString;
    
    return finalString;
}

int main(void)
{
    char str[] = "!!!Hello 1234 World!!!";
    char sep = '-';
    printf("%s", modifyString(str, sep, "LOW"));
}