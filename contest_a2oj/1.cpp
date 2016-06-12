#include <bits/stdc++.h>

using namespace std;

int main(){
    map<char, char> keys;
    
    keys['~'] = '~';
    keys['1'] = '1';
    keys['2'] = '2';
    keys['3'] = '3';
    keys['4'] = 'q';
    keys['5'] = 'j';
    keys['6'] = 'l';
    keys['7'] = 'm';
    keys['8'] = 'f';
    keys['9'] = 'p';
    keys['0'] = '/';
    keys['-'] = '[';
    keys['='] = ']';
    keys['q'] = '4';
    keys['w'] = '5';
    keys['e'] = '6';
    keys['r'] = '.';
    keys['t'] = 'o';
    keys['y'] = 'r';
    keys['u'] = 's';
    keys['i'] = 'u';
    keys['o'] = 'y';
    keys['p'] = 'b';
    keys['['] = ';';
    keys[']'] = '=';
    keys['\\'] = '\\';
    keys['a'] = '7';
    keys['s'] = '8';
    keys['d'] = '9';
    keys['f'] = 'a';
    keys['g'] = 'e';
    keys['h'] = 'h';
    keys['j'] = 't';
    keys['k'] = 'd';
    keys['l'] = 'c';
    keys[';'] = 'k';
    keys['\''] = '-';
    keys['z'] = '0';
    keys['x'] = 'z';
    keys['c'] = 'x';
    keys['v'] = ',';
    keys['b'] = 'i';
    keys['n'] = 'n';
    keys['m'] = 'w';
    keys[','] = 'v';
    keys['.'] = 'g';
    keys['/'] = '\'';
    
    keys['!'] = '!';
    keys['@'] = '@';
    keys['#'] = '#';
    keys['$'] = 'Q';
    keys['%'] = 'J';
    keys['^'] = 'L';
    keys['&'] = 'M';
    keys['*'] = 'F';
    keys['('] = 'P';
    keys[')'] = '?';
    keys['_'] = '{';
    keys['+'] = '}';
    keys['Q'] = '$';
    keys['W'] = '%';
    keys['E'] = '^';
    keys['R'] = '>';
    keys['T'] = 'O';
    keys['Y'] = 'R';
    keys['U'] = 'S';
    keys['I'] = 'U';
    keys['O'] = 'Y';
    keys['P'] = 'B';
    keys['{'] = ':';
    keys['}'] = '+';
    keys['|'] = '|';
    
    keys['A'] = '&';
    keys['S'] = '*';
    keys['D'] = '(';
    keys['F'] = 'A';
    keys['G'] = 'E';
    keys['H'] = 'H';
    keys['J'] = 'T';
    keys['K'] = 'D';
    keys['L'] = 'C';
    keys[':'] = 'K';
    keys['\"'] = '_';

    keys['Z'] = ')';
    keys['X'] = 'Z';
    keys['C'] = 'X';
    keys['V'] = '<';
    keys['B'] = 'I';
    keys['N'] = 'N';
    keys['M'] = 'W';
    keys['<'] = 'V';
    keys['>'] = 'G';
    keys['?'] = '\"';
    
    string s;
    
    while(getline(cin, s)){
        for(int i = 0; i < s.length(); i++){
            if(keys.find(s[i]) == keys.end()) printf("%c", s[i]);
            else printf("%c", keys[ s[i] ]);
        }
        printf("\n");
    }    
    
    
    return 0;
}