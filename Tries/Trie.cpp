#include <iostream>

using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch);
};

TrieNode::TrieNode(char ch)
{
    data = ch;
    for (int i = 0; i < 26; i++)
    {
        children[i] = nullptr;
    }
    isTerminal = false;
}

class Trie
{
private:
    TrieNode *root;

    void insertUtil(TrieNode *root, string word);
    bool searchUtil(TrieNode *root, string word);
    void removeUtil(TrieNode *root, string word);

public:
    // Constructor
    Trie();

    // Insert
    void insertWord(string word);

    // Search
    bool search(string word);

    // Remove
    void remove(string word);
};

// Constructor - Create New Root (Master)
Trie::Trie()
{
    root = new TrieNode('\0');
}

// Insert
void Trie::insertUtil(TrieNode *root, string word)
{
    if (word.size() == 0)
    {
        root->isTerminal = true;
        return;
    }

    int index = word[0] - 'A';

    TrieNode *child;

    if (root->children[index] != nullptr)
    { // Present

        child = root->children[index];
    }
    else
    { // Absent

        child = new TrieNode(word[0]);
        root->children[index] = child;
    }

    // recursion
    insertUtil(child, word.substr(1));
}

void Trie::insertWord(string word)
{
    insertUtil(root, word);
}
// Insert End

// Search
bool Trie::searchUtil(TrieNode *root, string word)
{
    if (word.length() == 0)
    {
        return root->isTerminal;
    }
    int index = word[0] - 'A';

    TrieNode *child;

    if (root->children[index] != NULL)
    { // Present

        child = root->children[index];
    }
    else
    { // Absent

        return false;
    }

    return searchUtil(child, word.substr(1));
}

bool Trie::search(string word)
{
    return searchUtil(root, word);
}
// Search End

// Remove
void Trie::removeUtil(TrieNode *root, string word)
{
    if (word.length() == 0)
    {
        root->isTerminal = false;
        return;
    }

    int index = word[0] - 'A';

    TrieNode *child;

    if (root->children[index] != nullptr)
    {
        child = root->children[index];
    }
    else
    {
        return;
    }

    return removeUtil(child, word.substr(1));
}

void Trie::remove(string word)
{
    removeUtil(root, word);
}
// Remove End

int main()
{
    Trie *t = new Trie();

    t->insertWord("ABCDE");
    t->insertWord("ABAAD");
    t->insertWord("\0");

    cout << t->search("ABAAD") << endl;

    t->remove("ABAAD");

    cout << t->search("ABAAD") << endl;

    return 0;
}