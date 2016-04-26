#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    
    node(): data(0), left(NULL), right(NULL)
    {}
    
};

class Tree
{
   node *root;
    
public:
    Tree(): root(NULL)
    {}
    
    node *getroot()
    {
        return root;
    }
    
    node *find(int key)
    {
        node *current = root;
        
        while(current->data != key)
        {
            if(key < current->data)
                current = current->left;
            else
                current = current->right;
            if(current ==NULL)
                return NULL;
        }
        return current;
    }
    
    void inorder(node *root)
    {
        if (root != NULL)
        {
            inorder(root->left);
            cout << "  " << root->data;
            inorder(root->right);
            
        }
    }

    void preorder(node *root)
    {
        if (root != NULL)
        {
            cout << "  " << root->data;
            preorder(root->left);
            preorder(root->right);
            
        }
    }
    
    void postorder(node *root)
    {
        if (root != NULL)
        {
            postorder(root->left);
            postorder(root->right);
            cout << "  " << root->data;
            
        }
    }
    

    void insert(int key)
    {
        node *newnode = new node;
        newnode->data= key;
        
       if(root == NULL)
            root = newnode;
       else
        {
            node *current = root;
            node *parent;
            while(true)
            {
                parent = current;
                if(key < current->data)
                {
                    current = current->left;
                    if(current == NULL)
                    {
                        parent->left = newnode;
                        return;
                    }
                }
                else
                {
                    current = current->right;
                    if(current == NULL)
                    {
                        parent->right = newnode;
                        return;
                    }
                }
            }
        }
    }
};



int main(int argc, const char * argv[]) {
   
    node *node;
    Tree mytree;
    
    mytree.insert(20);
    mytree.insert(10);
    mytree.insert(30);
//    mytree.insert(60);
//    mytree.insert(10);
//    mytree.insert(70);
    
  
    // node =   mytree.getroot();
    cout << "\npost order" << endl;
    mytree.postorder(mytree.getroot());
    
    cout << "\nin order" << endl;
    mytree.inorder(mytree.getroot());
    
    
    cout << "\npre order" << endl;
    mytree.preorder(mytree.getroot());

    
    node = mytree.find(20);
    
if(node)
    cout << "\nFound " << node->data;
else
    cout << "\nNot found";
    return 0;
}


