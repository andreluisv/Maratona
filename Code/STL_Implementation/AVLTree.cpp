struct Node{
public:
    int key;
    int height;
    Node* right;
    Node* left;

    Node(int key){
        this->key = key;
        this->left = NULL;
        this->right = NULL;
    }

};

int getHeight(Node* rt){
    if (rt == NULL)
        return -1;
    return rt->height;
}

int getBalance(Node* rt){
    if (rt == NULL)
        return 0;
    return getHeight(rt->left) - getHeight(rt->right);
}

Node* rightRotate(Node* rt){
    Node* l = rt->left;
    Node* lr = l->right;
    l->right = rt;
    rt->left = lr;
    rt->height = max(getHeight(rt->left), getHeight(rt->right)) + 1;
    l->height = max(getHeight(l->left), getHeight(l->right)) + 1;
    return l;
}

Node* leftRotate(Node* rt){
    Node* r = rt->right;
    Node* rl = r->left;
    r->left = rt;
    rt->right = rl;
    rt->height = max(getHeight(rt->left), getHeight(rt->right)) + 1;
    r->height = max(getHeight(r->left), getHeight(r->right)) + 1;
    return r;
}

class AVL{
public:
    Node* root;

    AVL(){
        this->root = NULL;
    }

    void clear(){
        this->root = NULL;
    }

    void print(Node* rt){
        if(rt == NULL)
            return;
        cout << rt->key << " ";
        print(rt->left);
        print(rt->right);
    }

    Node* inserthelp(Node* rt, int key){
        if (rt == NULL)
            return new Node(key);

        if (rt->key > key)
            rt->left = inserthelp(rt->left, key);
        else
            rt->right = inserthelp(rt->right, key);

        //balanceando
        rt->height = 1 + max(getHeight(rt->left), getHeight(rt->right));
        int balance = getBalance(rt);
        //rotacoes
        if (balance > 1 && key < rt->left->key)
            return rightRotate(rt);
        if (balance < -1 && key >= rt->right->key)
            return leftRotate(rt);
        //rotacoes duplas (RL/LR)
        if(balance > 1 && key >= rt->left->key){
            rt->left = leftRotate(rt->left);
            return rightRotate(rt);
        }
        if (balance < -1 && key < rt->right->key){
            rt->right = rightRotate(rt->right);
            return leftRotate(rt);
        }
        return rt;

    }

    void insert(int key){
        this->root = inserthelp(this->root, key);
    }

    int findhelp(Node* rt, int key){
        if (rt == NULL)
            return -1;
        if (rt->key == key)
            return rt->key;
        else if (rt->key > key)
            return findhelp(rt->left, key);
        else
            return findhelp(rt->right, key);
    }

    int find(int key){
        return findhelp(this->root, key);
    }


};
/*
AVL* avl = new AVL();
avl->clear();
avl->insert(x);
avl->find(x)
*/
