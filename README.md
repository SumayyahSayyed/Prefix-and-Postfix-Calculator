# INFIX TO POSTFIX & INFIX TO PREFIX CALCULATOR

## Table of contents

- [Overview](#overview)
  - [Language](#language)
  - [Working](#working)
- [Methadology](#methadology)
  - [Programming Model](#programming-model)
  - [Functions](#functions)
  - [Libraries](#libraries)
- [Author](#author)

## Overview

### Language

This project is made in [C++] programming language.

### Working

•	The welcome screen is displayed to the user.
•	The user is asked to insert an INFIX Expression.
•	The program recognizes the wrong input like:
        1. An expression cannot be less than the length of 3.
        2. The expression can be of either Alphabets or Numbers but does not allow to enter both in a single expression.3. The program allows you to re-enter the incorrect expression.
•	When the right input is inserted, the program then displays 2 options:
      Convert the INFIX Expression to:
        1. POSTFIX EXPRESSION
        2. PREFIX EXPRESSION
    from which the user chooses an option.
• Entering wrong option from the above two choices will allow to the user to re-enter the incorrect input.
•	This program is made flexible for the user to go back to the main section and choose again.
•	If the user does not want to go to the main section, the program thanks the user for using our program and ends.

## Methadology

### Programming Model

This Project is made with the concept of [Data-Structures].

### Functions

•    void Welcome()  
•    bool Operator(char)
•    bool Operand(char)
•    bool Equal_High(char, char)
•    string Postfix_Convert(string)
•    string Prefix_Convert(string)


### Libraries

•	# include <iostream>
•	# include <stack>   
•	# include <algorithm>	

## Author

[SumayyahSayyed]
