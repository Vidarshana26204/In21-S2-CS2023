/* 
The structure of the node is

typedef struct node {

	int freq;
    char data;
    node * left;
    node * right;
    
} node;

*/


void decode_huff(node * root, string s) {
    string result;  // Empty string
    node* n = root;
    for (std::string::iterator itr = s.begin(); itr != s.end(); ++itr){
        node* next;
        if(*itr == '0'){
            next = n -> left;
        }
        else{
            next = n -> right;
        }
        if(next -> data == '\0'){
            n = next;
        }
        else{
            result += next -> data; // String concatenation
            n = root;
        }
    }
    cout << result << endl;
}