#include <iostream>

using namespace std;


int cti(char ch)
{
    return ( (int)(ch) - (int)('a') );
}

struct TrieNode
{
    int wordend;
    char letter;
    TrieNode* children[26];

    TrieNode(char l)
    {
        wordend = 0;
        letter = l;

        for(int i=0; i<26; i++)
        {
            children[i] = NULL;
        }
    }
};

class Dictionary
{
    private:
    TrieNode* root;

    public:
    Dictionary()
    {
        root = new TrieNode('0');        
    }

    void add(string word)
    {
        TrieNode* node = root;
        
        for(int i=0; word[i] != '\0'; i++)
        {
            if(node->children[cti(word[i])] == NULL)
            {
                //create new TrieNode
                TrieNode* newChar = new TrieNode(word[i]);
                //make it a child of the current node
                node->children[cti(word[i])] = newChar;
                //move onto this new node
                node = newChar;
            }
            else
            {
                //move onto the existing node
                node = node->children[cti(word[i])];
            }
        }

        node->wordend = 1;
    }

    void printAll(string word, TrieNode* node)
    {
        if(node->wordend)
        {
            cout<<word<<endl;
        }

        for(int i=0; i<26; i++)
        {
            if(node->children[i] != NULL)
                printAll(word + node->children[i]->letter, node->children[i]);   
        }
    }

    void printAllWords()
    {
        printAll("", root);
    }

    TrieNode* search(string str)
    {
        TrieNode* node = root;

        for(int i=0; str[i] != '\0'; i++)
        {
            //if the character is present
            if(node->children[cti(str[i])] != NULL)
            {
                //then move on to the the node
                node = node->children[cti(str[i])];
            }
            else
            {
                return NULL;
            }
        }

        return node;
    }

    void autocomplete(string query)
    {
        TrieNode* node = search(query);

        if(node != NULL)
        {
            printAll(query, node);
        }
    }
};

int main()
{
    Dictionary dictionary;
    string word, query;
    int choice;

    while(true)
    {
        cout<<"----------\n";
        cout<<"1. add a new word to the dictionary\n";
        cout<<"2. list all the words in the dictionary\n";
        cout<<"3. autocomplete\n";
        cout<<"----------\n";

        cin>>choice;

        switch (choice)
        {
            case 1:
                cout<<"enter new word to add: ";
                cin>>word;
                cout<<endl;
                dictionary.add(word);
                break;
            case 2:
                dictionary.printAllWords();
                break;
            case 3:
                cout<<"enter query: ";
                cin>>query;
                cout<<endl;
                dictionary.autocomplete(query);
                break;
            default:
                break;
        }
        cout<<endl;
    }

    return 0;
}