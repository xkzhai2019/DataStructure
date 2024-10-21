#include <iostream>
using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",
                                ".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",
                                ".--","-..-","-.--","--.."};
        BSTSet<string> *bstSet = new BSTSet<string>();
        for(string word: words){
            string code =  "";
            for(char c: word){
                code += morse[c - 'a'];
            }
            bstSet->add(code);
        }
        return bstSet->getSize();
    }
};
