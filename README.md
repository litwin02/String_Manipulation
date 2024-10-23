# String Manipulation in C

This program provides various string manipulation functions written in C. It can convert a string to uppercase or lowercase, replace non-alphanumeric characters with a custom separator, and replace numbers with their English word equivalents. This project was originally a homework assignment and has since become a great exercise for practicing C programming skills.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [How to Use](#how-to-use)
- [Example](#example)
- [Contributing](#contributing)

## Introduction

This C program manipulates strings using the following functionalities:
- Converts strings to uppercase or lowercase.
- Replaces non-alphanumeric characters with a specified separator.
- Replaces digits with their English word equivalents (e.g., '1' becomes 'one').
- Combines these functionalities for flexible string modifications.

## Features

- **toUpper**: Converts a string to uppercase.
- **toLower**: Converts a string to lowercase.
- **replaceWithSeparator**: Replaces non-alphanumeric characters with a specified separator.
- **replaceNumberWithEnglishSubstitute**: Converts numbers in the string to their English word equivalents.
- **modifyString**: A combined function that performs the following:
  - Replaces non-alphanumeric characters.
  - Converts digits to words.
  - Changes the case of the string (uppercase or lowercase).

## How to Use

### Prerequisites

You will need a C compiler to compile and run the program. You can use either `gcc` or `clang`.

### Compilation

To compile the program, run the following command:

```bash
gcc -o string_manipulation string_manipulation.c
```

### Running the Program

Once compiled, you can run the program like this:
```bash
./string_manipulation
```

By default, the program will modify the string "!!!Hello 1234 World!!!", replacing non-alphanumeric characters with a dash (-), converting numbers to words, and converting the string to lowercase.

## Example

Given the input string "!!!Hello 1234 World!!!" with the separator '-' and the option to convert to lowercase, the output will be:

```text
hello-onetwothreefour-world
```
## Contributing

If you'd like to contribute to this program, feel free to fork the repository and submit a pull request. Suggestions and improvements are always welcome!