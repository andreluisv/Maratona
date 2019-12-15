struct Node{
public:
    string key;
    string element;
    Node* right;
    Node* left;

    Node(string key, string element){
        this->key = key;
        this->element = element;
        this->left = NULL;
        this->right = NULL;
    }

};

class BST{
public:
    Node* root;

    BST(){//Constructor
        this->root = NULL;
    }

    void print(Node* rt){//Prints the entire bst in postorder traversal
        if(rt == NULL)
            return;
        print(rt->left);
        print(rt->right);
        cout << rt->element;
    }
    
    void clearhelp(Node* rt){
        if (rt->left == NULL && rt->right == NULL)
            delete rt;
        else if (rt->left == NULL)
            clearhelp(rt->right);
        else if (rt->right == NULL)
            clearhelp(rt->left);

    }
    
    void clear(){//Clears the entire bst
		clearhelp(this->root);
		this->root = NULL;
    }

    Node* inserthelp(Node* rt, string key, string element){
        if (rt == NULL){
            rt = new Node(key, element);
            return rt;
        }
        else if (rt->key > key)
            rt->left = inserthelp(rt->left, key, element);
        else
            rt->right = inserthelp(rt->right, key, element);
            
        return rt;
    }

    void insert(string key, string element){//Pushes an element with key key to the bst
        this->root = inserthelp(this->root, key, element);
    }

    string findhelp(Node* rt, string key){//Returns the element associated with the key key
        if (rt == NULL)
            return "eh";
        if (rt->key == key)
            return rt->element;
        else if (rt->key > key)
            return findhelp(rt->left, key);
        else
            return findhelp(rt->right, key);
    }

    string find(string key){
        return findhelp(this->root, key);

    }


};
/*
BST* tree = new BST();
tree->insert(key, element);
tree->find(aux)
tree->clear();
*/
