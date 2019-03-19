#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair 
#define MAX_SIZE (1 << 20)
#define READ(x) cin >> x;
#define PRT(x) cout << x << endl;
#define REP(i, n) for(i = 0; i < n; i++)
#define REP1(i, n) for(i = 1; i < n; i++)
#define REVREP(i, n) for(i = n - 1; i >= 0; i--)
#define fi first
#define se second
#define sz(x) ((int)x.size())
#define DASH() cout << "-------------------------" << endl;
typedef long long lli;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;

typedef struct TrieNode tNode;
  
#define ALPHABET_SIZE 120
  

struct TrieNode { 
    tNode *children[ALPHABET_SIZE]; 
    bool isEndOfWord; 
}; 
   
tNode *getNode(void) { 
    tNode *pNode =  new TrieNode; 
    pNode->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        pNode->children[i] = NULL; 
    return pNode; 
} 

void insert(tNode *root, string key) 
{ 
    tNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            pCrawl->children[index] = getNode(); 
  
        pCrawl = pCrawl->children[index]; 
    } 
    pCrawl->isEndOfWord = true; 
} 

bool search(tNode *root, string key) 
{ 
    tNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) return false; 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    return (pCrawl != NULL && pCrawl->isEndOfWord); 
} 

int main() {
    string word = "", text;
    char ch;
    tNode *root = getNode();
    ch = getchar();
    while(ch != '\n') {
        if(ch == ' ') {
            insert(root, word);
            word = "";
        }
        word += ch;
        ch = getchar();
    }
    insert(root, word);
    while(1) {
        cin >> word;
        string out;
        out = search(root, word) ? "Found" : "Not found";
        cout << out << endl;
    }
    return 0;
}