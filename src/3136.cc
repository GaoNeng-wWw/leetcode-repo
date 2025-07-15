#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3){return false;}
        bool flagA = false;
        bool flagB = false;
        for(char charA :word){
            if(charA >='0'&&charA<='9'){
                continue;
            }else if(charA >='a'&&charA<='z'){
                if(charA == 'a'||charA=='e'||charA=='i'||charA=='o'||charA=='u'){
                    flagA = true;
                }else{
                    flagB = true;
                }
            }else if(charA >='A'&&charA<='Z'){
                if(charA == 'A'||charA=='E'||charA=='I'||charA=='O'||charA=='U'){
                    flagA = true;
                }else{
                    flagB = true;
                }
            }else{
                return false;
            }
        }
        return flagA&&flagB;
    }
};