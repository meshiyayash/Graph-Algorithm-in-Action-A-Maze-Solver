class Node {
public:
    char val;
    unordered_map<int, Node*> store;
    bool isTerminal;
    Node() {
    }
    Node(char val) {
        this->val = val;
        isTerminal = false;
    }
};
class Trie {
    Node* head;
public:
    Trie() {
        head = new Node('-');
    }
    void insert(string word) {
        Node* temp = head;
        int pos = 0;
        while (pos < word.size()) {
            if (temp->store.find(word[pos]) != temp->store.end()) {
                temp = temp->store[word[pos]];
            }
            else {
                Node* newNode = new Node(word[pos]);
                temp->store[word[pos]] = newNode;
                temp = newNode;
            }
            if (pos == word.size() - 1) {
                temp->isTerminal = true;
            }
            pos++;
        }
    }
    bool search(string word) {
        Node* temp = head;
        int pos = 0;
        while (pos < word.size()) {
            if (temp->store.find(word[pos]) != temp->store.end()) {
                temp = temp->store[word[pos]];
            }
            else {
                return false;
            }
            if (pos == word.size() - 1) {
                return temp->isTerminal;
            }
            pos++;
        }
        return true;
    }
    bool startsWith(string prefix) {
        Node* temp = head;
        int pos = 0;
        while (pos < prefix.size()) {
            if (temp->store.find(prefix[pos]) != temp->store.end()) {
                temp = temp->store[prefix[pos]];
            }
            else {
                return false;
            }
            pos++;
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
