/*
clear; g++ bitwise-operator.cpp  && ./a.exe
*/

#include<iostream>
using namespace std;
/*
*/

#define SET(value, pos) ( value |= (1<<pos))
#define CLEAR(value, pos) ( value &= (1<<pos))
#define TOGGLE(value, pos) ( value ^= (1<<pos))
#define CHECK_IF_SET(value, pos) ( value & (1<<pos))
#define CHECK_IF_CLEAR(value, pos) ( value ^ (1<<pos))

int main(int argc, char *argv[]) {

    return 0;
}