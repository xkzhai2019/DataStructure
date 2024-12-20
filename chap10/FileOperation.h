#ifndef FILEOPS_H
#define FILEOPS_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>

using namespace std;

namespace FileOps {

    bool isCharacter(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }

    int firstCharacterIndex(const string &s, int start) {
        for (int i = start; i < s.length(); i++)
            if (isCharacter(s[i]))
                return i;
        return s.length();
    }

    string lowerS(const string &s) {
        string ret = "";
        for (int i = 0; i < s.length(); i++) {
            assert(isCharacter(s[i]));
            ret += tolower(s[i]);
        }
        return ret;
    }

    bool readFile(const string &filename, vector<string> &words) {
        string line;
        string contents = "";
        ifstream file(filename);
        if (file.is_open()) {
            while (getline(file, line))
                contents += (line + "\n");
            file.close();
        } else {
            cout << "Can not open " << filename << " !!!" << endl;
            return false;
        }

        int start = firstCharacterIndex(contents, 0);
        int i;
        for (i = start + 1; i <= contents.length();) {

            if (i == contents.length() || !isCharacter(contents[i])) {
                words.push_back(lowerS(contents.substr(start, i - start)));
                start = firstCharacterIndex(contents, i);
                i = start + 1;
            } else {
                i++;
            }
        }

        return true;
    }
}

#endif //FILEOPS_H
