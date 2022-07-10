/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 

Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
 

Constraints:

1 <= word.length, prefix.length <= 2000
word and prefix consist only of lowercase English letters.
At most 3 * 104 calls in total will be made to insert, search, and startsWith.

*/

//---------------------------------------------------------------------------------------
struct Node
{
    Node *links[26];
    bool flag = false;
    
    //checks if the reference trie is present or not
    
    bool containKey(char ch)
    {
        return (links[ch - 'a'] !=NULL);
    }
    
    //creating reference trie
    
    void put(char ch,Node *node)
    {
        links[ch - 'a'] = node;
    }
    
    //to get the next node for traversal
    
    Node *get(char ch)
    {
        return links[ch-'a'];
    }
    
    //setting flag to true at the end of the word
    
    void setEnd()
    {
        flag = true;
    }
    
    //checking if the word is completed or not
    bool isEnd()
    {
        return flag;
    }
};

//---------------------------------------------------------------------------------------

class Trie {

    Node *root;
public:
    Trie() {
        //creating new obejct
        root = new Node();
    }
    
    void insert(string word) {
        //initializing dummy node pointing to root initially
        
        Node * node = root;
        for(int i = 0 ; i<word.size();i++)
        {
            if(!node->containKey(word[i]))
            {
                node ->put(word[i],new Node());
            }
            //moves to reference trie
            node = node -> get(word[i]);
        }
        node -> setEnd();
    }
    
    bool search(string word) {
        
        Node *node = root;
        for(int i = 0 ; i<word.size();i++)
        {
            if(!node->containKey(word[i]))
            {
                return false;
            }
            node = node -> get(word[i]);
        }
        return node -> isEnd();
    }
    
    bool startsWith(string prefix) {
        Node *node = root;
        for(int i = 0 ; i<prefix.size();i++)
        {
            if(!node->containKey(prefix[i]))
            {
                return false;
            }
            node = node -> get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */