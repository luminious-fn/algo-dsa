#include <iostream>
using namespace std;

/*
export PROG="anagram";clear; g++ $PROG.cpp -o $PROG.exe && ./$PROG.exe 
*/
/*
returns false : if not anagrams
returns true : if anagrams
*/

#define NO_OF_CHARS 256
int is_anagram(char *str1, char *str2) {
    int str1_count[NO_OF_CHARS] = {0};
    int str2_count[NO_OF_CHARS] = {0};
    int i;
    for(i = 0; str1[i] && str2[i]; i++) {
        str1_count[str1[i]]++;
        str2_count[str2[i]]++;
    }

    /* if strings are not equal, return 0 */
    if(str1[i] || str2[i]){
        return false;
    }

    for (i = 0; i < NO_OF_CHARS; i++) {
        if (str1_count[i] != str2_count[i]){
            return false;
        }        
    }
    return true;
}

int main(int argc, char *argv[]){    
    char *str1 = (char*)"xabbd";
    char *str2 = (char*)"abxbd";
    cout << endl;
    if (is_anagram(str1, str2)){
        cout << "yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}