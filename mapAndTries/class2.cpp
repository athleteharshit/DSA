#include <iostream>
using namespace std;

class TrieNode
{
public:
    char val;
    TrieNode *children[26];
    bool isTerminal;
    TrieNode(char val)
    {
        this->val = val;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

// insert
void insertWord(TrieNode *root, string word)
{
    cout << word << endl;
    if (word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;
    if (root->children[index] != NULL)
    {
        // present
        child = root->children[index];
    }
    else
    {
        // absent
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    // recussion
    insertWord(child, word.substr(1));
}

int main()
{
    TrieNode *root = new TrieNode('-');

    insertWord(root, "dona");
    insertWord(root, "donekarona");

    return 0;
}