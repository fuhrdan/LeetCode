#include <string>
#include <vector>
#include <cctype>

using namespace std;

class Solution
{
private:
    int keyboardRow(char c)
    {
        c = static_cast<char>(tolower(static_cast<unsigned char>(c)));

        if (string("qwertyuiop").find(c) != string::npos)
        {
            return 1;
        }

        if (string("asdfghjkl").find(c) != string::npos)
        {
            return 2;
        }

        return 3;
    }

public:
    vector<string> findWords(vector<string>& words)
    {
        vector<string> retVal;

        for (const string& word : words)
        {
            if (word.empty())
            {
                continue;
            }

            int row = keyboardRow(word[0]);
            bool valid = true;

            for (int i = 1; i < static_cast<int>(word.size()); i++)
            {
                if (keyboardRow(word[i]) != row)
                {
                    valid = false;
                    break;
                }
            }

            if (valid)
            {
                retVal.push_back(word);
            }
        }

        return retVal;
    }
};
