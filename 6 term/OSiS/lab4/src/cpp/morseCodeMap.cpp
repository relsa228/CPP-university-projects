#include "../headers/morseCodeMap.h"

void loadMorseDecodeTable(std::map <std::string, std::string> &MORSE_CODE) {
    MORSE_CODE[" "] = " ";
    MORSE_CODE["-----"] = "0";
    MORSE_CODE[".----"] = "1";
    MORSE_CODE["..---"] = "2";
    MORSE_CODE["...--"] = "3";
    MORSE_CODE["....-"] = "4";
    MORSE_CODE["....."] = "5";
    MORSE_CODE["-...."] = "6";
    MORSE_CODE["--..."] = "7";
    MORSE_CODE["---.."] = "8";
    MORSE_CODE["----."] = "9";
    MORSE_CODE[".-"] = "a";
    MORSE_CODE["-..."] = "b";
    MORSE_CODE["-.-."] = "c";
    MORSE_CODE["-.."] = "d";
    MORSE_CODE["."] = "e";
    MORSE_CODE["..-."] = "f";
    MORSE_CODE["--."] = "g";
    MORSE_CODE["...."] = "h";
    MORSE_CODE[".."] = "i";
    MORSE_CODE[".---"] = "j";
    MORSE_CODE["-.-"] = "k";
    MORSE_CODE[".-.."] = "l";
    MORSE_CODE["--"] = "m";
    MORSE_CODE["-."] = "n";
    MORSE_CODE["---"] = "o";
    MORSE_CODE[".--."] = "p";
    MORSE_CODE["--.-"] = "q";
    MORSE_CODE[".-."] = "r";
    MORSE_CODE["..."] = "s";
    MORSE_CODE["-"] = "t";
    MORSE_CODE["..-"] = "u";
    MORSE_CODE["...-"] = "v";
    MORSE_CODE[".--"] = "w";
    MORSE_CODE["-..-"] = "x";
    MORSE_CODE["-.--"] = "y";
    MORSE_CODE["--.."] = "z";
    MORSE_CODE["--..--"] = ",";
    MORSE_CODE["..--.."] = "?";
    MORSE_CODE["---..."] = ":";
    MORSE_CODE["-....-"] = "-";
    MORSE_CODE[".-..-."] = "\"";
    MORSE_CODE["-.--."] = "(";
    MORSE_CODE["-...-"] = "=";
    MORSE_CODE["-..-"] = "*";
    MORSE_CODE[".-.-.-"] = ".";
    MORSE_CODE["-.-.-."] = ";";
    MORSE_CODE["-..-."] = "/";
    MORSE_CODE[".----."] = "\'";
    MORSE_CODE["..--.-"] = "_";
    MORSE_CODE["-.--.-"] = ")";
    MORSE_CODE[".-.-."] = "+";
    MORSE_CODE[".--.-."] = "@";
}

void loadMorseCodeTable(std::map <char, std::string> &MORSE_CODE) {
    MORSE_CODE[' '] = " ";
    MORSE_CODE['0'] = "-----";
    MORSE_CODE['1'] = ".----";
    MORSE_CODE['2'] = "..---";
    MORSE_CODE['3'] = "...--";
    MORSE_CODE['4'] = "....-";
    MORSE_CODE['5'] = ".....";
    MORSE_CODE['6'] = "-....";
    MORSE_CODE['7'] = "--...";
    MORSE_CODE['8'] = "---..";
    MORSE_CODE['9'] = "----.";
    MORSE_CODE['a'] = ".-";
    MORSE_CODE['b'] = "-...";
    MORSE_CODE['c'] = "-.-.";
    MORSE_CODE['d'] = "-..";
    MORSE_CODE['e'] = ".";
    MORSE_CODE['f'] = "..-.";
    MORSE_CODE['g'] = "--.";
    MORSE_CODE['h'] = "....";
    MORSE_CODE['i'] = "..";
    MORSE_CODE['j'] = ".---";
    MORSE_CODE['k'] = "-.-";
    MORSE_CODE['l'] = ".-..";
    MORSE_CODE['m'] = "--";
    MORSE_CODE['n'] = "-.";
    MORSE_CODE['o'] = "---";
    MORSE_CODE['p'] = ".--.";
    MORSE_CODE['q'] = "--.-";
    MORSE_CODE['r'] = ".-.";
    MORSE_CODE['s'] = "...";
    MORSE_CODE['t'] = "-";
    MORSE_CODE['u'] = "..-";
    MORSE_CODE['v'] = "...-";
    MORSE_CODE['w'] = ".--";
    MORSE_CODE['x'] = "-..-";
    MORSE_CODE['y'] = "-.--";
    MORSE_CODE['z'] = "--..";
    MORSE_CODE[','] = "--..--";
    MORSE_CODE['?'] = "..--..";
    MORSE_CODE[':'] = "---...";
    MORSE_CODE['-'] = "-....-";
    MORSE_CODE['\"'] = ".-..-.";
    MORSE_CODE['('] = "-.--.";
    MORSE_CODE['='] = "-...-";
    MORSE_CODE['*'] = "-..-";
    MORSE_CODE['.'] = ".-.-.-";
    MORSE_CODE[';'] = "-.-.-.";
    MORSE_CODE['/'] = "-..-.";
    MORSE_CODE['\''] = ".----.";
    MORSE_CODE['_'] = "..--.-";
    MORSE_CODE[')'] = "-.--.-";
    MORSE_CODE['+'] = ".-.-.";
    MORSE_CODE['@'] = ".--.-.";
}