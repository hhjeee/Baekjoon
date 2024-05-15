#include <iostream>
#include<string.h>
using namespace std;

int main() {
    char word[101];
    cin >> word;

    int count = 0;

    for(int i=0; i<strlen(word); i++) {
       switch(word[i]) {
        case 'c':
            if(word[i+1] == '=') {
                count++;
                i++;
            }
            else if(word[i+1] == '-') {
                count++;
                i++;
            }
            else{
                count++;
            }
            break;
        case 'd':
            if(word[i+1] == 'z' && word[i+2] == '=') {
                count++;
                i+=2;
            }
            else if(word[i+1] == '-') {
                count++;
                i++;
            }
            else{
                count++;
            }
            break;
        case 'l':
            if(word[i+1] == 'j') {
                count++;
                i++;
            }
            else{
                count++;
            }
            break;
        case 'n':
            if(word[i+1] == 'j') {
                count++;
                i++;
            }
            else{
                count++; 
            }
            break;

        case 's':
            if(word[i+1] == '=') {
                count++;
                i++;
            }
            else{
                count++; 
            }
            break;
        case 'z':
            if(word[i+1] == '=') {
                count++;
                i++;
            }
            else{
                count++; 
            }
            break;
        default:
            count++;
            break;
       }
    }
    
    cout << count;
    return 0;
}