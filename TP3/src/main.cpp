#include <iostream>
#include <string>
using namespace std;

// A Tree node
struct Node
{
    char ch;
    int freq;
    Node* left, * right;
};

// Function to allocate a new tree node
Node* getNode(char ch, int freq, Node* left, Node* right)
{
    Node* node = new Node();
    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;
    return node;
}

// Comparison object to be used to order the heap
struct comp
{
    bool operator()(Node* l, Node* r)
    {
        // highest priority item has lowest frequency
        return l->freq > r->freq;
    }
};

// traverse the Huffman Tree and store Huffman Codes
// in a string array.
void encode(Node* root, string str,
    string huffmanCode[])
{
    if (root == nullptr)
        return;

    // found a leaf node
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

// traverse the Huffman Tree and decode the encoded string
void decode(Node* root, int& index, string str)
{
    if (root == nullptr) {
        return;
    }

    // found a leaf node
    if (!root->left && !root->right)
    {
        cout << root->ch;
        return;
    }

    index++;

    if (str[index] == '0')
        decode(root->left, index, str);
    else
        decode(root->right, index, str);
}

// Builds Huffman Tree and decode given input text
void buildHuffmanTree(string text)
{
    // count frequency of appearance of each character
    // and store it in an array
    const int MAX_CHAR = 256;
    int freq[MAX_CHAR] = { 0 };
    for (char ch : text) {
        freq[ch]++;
    }

    // Create an array to store live nodes of Huffman tree;
    Node* pq[MAX_CHAR] = { nullptr };

    // Create a leaf node for each character and add it
    // to the array.
    int nodeCount = 0;
    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq[i] != 0) {
            pq[nodeCount] = getNode(static_cast<char>(i), freq[i], nullptr, nullptr);
            nodeCount++;
        }
    }

    // do till there is more than one node in the array
    while (nodeCount > 1)
    {
        // Find the two nodes with the lowest frequency
        int min1 = 0;
        int min2 = 1;
        for (int i = 2; i < nodeCount; i++) {
            if (pq[i]->freq < pq[min1]->freq) {
                min2 = min1;
                min1 = i;
            }
            else if (pq[i]->freq < pq[min2]->freq) {
                min2 = i;
            }
        }

        // Create a new internal node with these two nodes
        // as children and with frequency equal to the sum
        // of the two nodes' frequencies. Replace the two nodes
        // with the new node in the array.
        int sum = pq[min1]->freq + pq[min2]->freq;
            Node* newNode = getNode('\0', sum, pq[min1], pq[min2]);
        pq[min1] = newNode;

        // Shift the array to remove the second node
        for (int i = min2; i < nodeCount - 1; i++) {
            pq[i] = pq[i + 1];
        }

        nodeCount--;
    }

    // root stores pointer to root of Huffman Tree
    Node* root = pq[0];

    // traverse the Huffman Tree and store Huffman Codes
    // in a string array. Also prints them
    string huffmanCode[MAX_CHAR];
    encode(root, "", huffmanCode);

    cout << "Huffman Codes are :\n" << '\n';
    for (int i = 0; i < MAX_CHAR; i++) {
        if (!huffmanCode[i].empty()) {
            cout << static_cast<char>(i) << " " << huffmanCode[i] << '\n';
        }
    }

    cout << "\nOriginal string was :\n" << text << '\n';

    // print encoded string
    string encodedStr = "";
    for (char ch : text) {
        encodedStr += huffmanCode[ch];
    }

    cout << "\nEncoded string is :\n" << encodedStr << '\n';

    // traverse the Huffman Tree again and this time
    // decode the encoded string
    int index = -1;
    cout << "\nDecoded string is: \n";
    while (index < (int)encodedStr.size() - 2) {
        decode(root, index, encodedStr);
    }
    // deallocate memory
    delete root;
}

// Huffman coding algorithm
int main()
{
    string text = "Hello.";

    buildHuffmanTree(text);

    return 0;
}