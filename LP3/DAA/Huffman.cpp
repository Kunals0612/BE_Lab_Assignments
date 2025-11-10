#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
using namespace std;

class Node{
    public:
        char ch;
        int freq;
        Node* left;
        Node* right;
        Node(char ch, int freq){
            this->ch = ch;
            this->freq = freq;
            left = NULL;
            right = NULL;
        }
};

struct compare{
    bool operator()(Node* a, Node* b){
        return a -> freq > b -> freq;
    }
};

class Huffman{
    private:
        void generateCodes(Node* root, string code, unordered_map<char, string>& codes){
            if(!root){
                return;
            }

            if(!root->left && !root->right){
                codes[root->ch] = code;
            }

            generateCodes(root->left, code + '0', codes);
            generateCodes(root->right, code + '1', codes);
        }
    public:
        void huffamEncode(string& text){
            if(text.empty()){
                cout << "Text is Empty" << endl;
                return;
            }

            unordered_map<char, int> freq;
            for(char& ch : text){
                freq[ch]++;
            }

            priority_queue<Node*, vector<Node*>, compare> pq;
            for(auto& it : freq){
                pq.push(new Node(it.first, it.second));
            }

            while(pq.size() > 1){
                Node* left = pq.top();
                pq.pop();
                Node* right = pq.top();
                pq.pop();
                Node* merged = new Node('\0', left->freq + right->freq);
                merged->left = left;
                merged->right = right;
                pq.push(merged);
            }

            unordered_map<char, string> codes;
            Node* root = pq.top();
            generateCodes(root,"",codes);

            cout << "Encoded values" << endl;
            for(auto &it : codes){
                cout << it.first << " " << it.second << endl;
            }

            cout << "Encoded Text" << endl;
            for(char ch : text){
                cout << codes[ch];
            }
            cout << endl;
        }
};

int main(){
    string text;
    cout << "Enter the text" << endl;
    getline(cin, text);

    Huffman hf;
    hf.huffamEncode(text);
}