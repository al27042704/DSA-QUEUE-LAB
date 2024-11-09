#include<iostream>
using namespace std;

class node {
public:    
    int data;
    node *left;
    node *right;
    
    node(int val) 
	{
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

class tree {
public:
    node *root;
   
    tree() 
	{
        root=nullptr;
    }
    
    void preorder(node *temp) 
	{
        if(temp!=nullptr) 
		{
            cout<<temp->data<< " ";      
            preorder(temp->left);           
            preorder(temp->right);          
        }
}
    void postorder(node *temp) 
	{
        if(temp!=nullptr) {
            postorder(temp->left);          
            postorder(temp->right);        
            cout<<temp->data<<" ";      
        }
    }

    void inorder(node *temp) 
	{
        if(temp!=nullptr) 
		{
            inorder(temp->left);           
            cout<<temp->data <<" ";      
            inorder(temp->right);         
        }
    }

    node* Insert(node* n, int val) 
	{
        if(n == nullptr) 
		{
            return new node(val);  
        }
        if(val<n->data) 
		{
            n->left=Insert(n->left,val);  
        } 
		else 
		{
            n->right=Insert(n->right,val);  
        }
        return n;
    }
    
	void insert(int val) 
	{
        root=Insert(root,val); 
    }

    void preorderh() 
	{
        cout<<"Preorder:";
        preorder(root);
        cout<<endl;
    }

    void postorderh() 
	{
        cout<<"Postorder:";
        postorder(root);
        cout<<endl;
    }

    void inorderh() 
	{
        cout<<"Inorder: ";
        inorder(root);
        cout<<endl;
    }
};

int main() 
{
    tree t;
    t.insert(50);
    t.insert(30);
    t.insert(20);
    t.insert(40);
    t.insert(70);
    t.insert(60);
    t.insert(80);
    cout << "Preorder " << endl;
    t.preorderh();
    cout << "Postorder " << endl;
    t.postorderh();
    cout << "Inorder " << endl;
    t.inorderh();
    return 0;
}