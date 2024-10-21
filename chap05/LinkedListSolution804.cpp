#include <iostream>
using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",
                                ".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",
                                ".--","-..-","-.--","--.."};
        LinkedListSet<string> *listSet = new LinkedListSet<string>();
        for(string word: words){
            string code =  "";
            for(char c: word){
                code += morse[c - 'a'];
            }
            listSet->add(code);
        }
        return listSet->getSize();
    }
};
