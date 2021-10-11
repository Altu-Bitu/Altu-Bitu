#include <iostream>
#include <string>

using namespace std;

char str[3000];

int main() {
    cin >> str;
    int len = strlen(str);
    
    //최댓값
    int max = 0;
    int pos = 1;
    for(int i=0;i<len;i++){
        max += str[i]*pos;
        pos *= 10;
    }
    
    int min = 0;
    pos = 1;
    for(int i=0;i<len;i++){
        
    }
    
    
    
    return 0;
}
