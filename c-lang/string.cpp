#include<iostream>
using namespace std;

int strlen(const char *str);

int strlen(const char *str) {    
    int len=0;
    if(str == NULL){
        return 0;
    }
    while(*str++ != '\0') {
        len++;      
    }
    return len;
}

int compare(char *heystack, char *needle) {
    while( *heystack && *needle ) {
        if(*heystack != *needle) {
            return 0;
        }
        heystack++;
        needle++;
    }
    return (*needle == '\0');
}

char * strstr(char *heystack, char *needle) {
    while(*heystack != '\0'){
        if(compare(heystack, needle)) {
            return heystack;
        }
        heystack++;
    }
    return NULL;
    
}

int main(int argc, char *argv[]) {
    cout << "len: " << strlen("omtatsat") << endl;
    char *temp = strstr((char *)"hello", (char *)"llo");
    if (temp == NULL) {
        cout << "not found ";
    } else {
        cout << "ans " << temp ;
    }
    
}
