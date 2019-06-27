#include<bits/stdc++.h> 
 
using namespace std;


typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

void decode_huff(node *true_root, node *root, string encoded_string, int index, string &decoded_string) {
    if (!root)
        return;
    
    if (root->data != '\0') {
        decoded_string += root->data;
        
        decode_huff(true_root, true_root, encoded_string, index, decoded_string);
    }
    
    if (encoded_string[index] == '1') {
        decode_huff(true_root, root->right, encoded_string, index + 1, decoded_string);
    } else if (encoded_string[index] == '0') {
        decode_huff(true_root, root->left, encoded_string, index + 1, decoded_string);
    }
}

void decode_huff(node *root, string encoded_string)
{
    string decoded_string;
    decode_huff(root, root, encoded_string, 0, decoded_string);
    
    cout << decoded_string << '\n';
}