#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include "queue.hpp"

using namespace std;

class Huffman {
    public:
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
    void decode(Node* root, int& index, string str, string& decodedStr)
    {
        if (root == nullptr) {
            return;
        }

        // found a leaf node
        if (!root->left && !root->right)
        {
            decodedStr += root->ch;
            return;
        }

        index++;

        if (str[index] == '0')
            decode(root->left, index, str, decodedStr);
        else
            decode(root->right, index, str, decodedStr);
    }

    void WriteBit(FILE* f, int bit, unsigned char& bit_buffer, int& current_bit){
                if (bit)
                    bit_buffer |= (1<<current_bit);
                current_bit++;
                        
                if (current_bit == 8) {
                    fwrite(&bit_buffer, 1, 1, f);
                    bit_buffer = 0;
                    current_bit = 0;
                }

    }            

    void Flush_Bits(FILE* f, unsigned char& bit_buffer, int& current_bit) {
                while (current_bit)
                    WriteBit(f, 0, bit_buffer, current_bit);
    }

    void WriteHuffmanCode(const std::string& text, const std::string huffmanCode[], FILE* f) {
                unsigned char bit_buffer = 0;
                int current_bit = 0;

                for (char ch : text) {
                    string code = huffmanCode[ch];

                    for (char c : code)
                        WriteBit(f, 1, bit_buffer, current_bit);

                    WriteBit(f, 0, bit_buffer, current_bit);
                }

                Flush_Bits(f, bit_buffer, current_bit);
    }

    // Builds Huffman Tree and decode given input text
    void buildHuffmanTree(string text, char action)
    {
            // count frequency of appearance of each character and store it in an array
            const int MAX_CHAR = 256;
            int freq[MAX_CHAR] = { 0 };
            for (char ch : text) {
                freq[ch]++;
            }

            // Create an array to store live nodes of Huffman tree;
            Node* pq[MAX_CHAR] = { nullptr };

            // Create a leaf node for each character and add it to the array.
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

                int sum = pq[min1]->freq + pq[min2]->freq;
                    Node* newNode = getNode('\0', sum, pq[min1], pq[min2]);
                pq[min1] = newNode;

                for (int i = min2; i < nodeCount - 1; i++) {
                    pq[i] = pq[i + 1];
                }

                nodeCount--;
            }

            // root stores pointer to root of Huffman Tree
            Node* root = pq[0];

            // traverse the Huffman Tree and store Huffman Codes in a string array. Also prints them
            string huffmanCode[MAX_CHAR];
            encode(root, "", huffmanCode);


        if (action == 'c') {
            // Create and open the binary file for writing
            FILE* f = fopen("compressed.bin", "wb");
            if (f == nullptr) {
                cout << "Error opening file for writing." << endl;
                return;
            }

            // Encode the text and write Huffman code to the binary file
            WriteHuffmanCode(text, huffmanCode, f);

            // Close the file
            fclose(f);
        }
       
        if (action == 'd'){
            std::string encodedStr;

            // Open the binary file for reading
            FILE* f = fopen("compressed.bin", "rb");
            if (f == nullptr) {
                cout << "Error opening file for reading." << endl;
                return;
            }
            // Read the binary file and store its content in encodedStr
            fseek(f, 0, SEEK_END);
            long fileSize = ftell(f);
            fseek(f, 0, SEEK_SET);

            encodedStr.resize(fileSize);
            fread(&encodedStr[0], 1, fileSize, f);

            // Close the file
            fclose(f);

            int index = -1;
            string decodedStr;
            
            while (index < (int)encodedStr.size()) {
                decode(root, index, encodedStr, decodedStr);
            }
            cout << decodedStr << endl;
            // deallocate memory
            delete root;
        }

    }

};

#endif