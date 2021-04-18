//Constructing a binary tree

#include<iostream>
using namespace std;

class node{  //class for node
public:
    int data;
    node *right, *left, *spare;
    node(){  //default constructor
        data=0;
        right=nullptr;
        left=nullptr;
        spare=nullptr;
    };
    node(int n){ //parameterized constructor
        data=n;
        right=nullptr;
        left=nullptr;
        spare=nullptr;
    }
    node* create(node *root){  //function for creating root
        if(root!=nullptr){  //condition if it is already created
            cout<<"Already Created!"<<endl;
            return root;
        }
        node *curr=new node();
        cout<<"Enter value of root node: ";
        cin>>curr->data;
        return curr;}


    void searchn(node* root,int n){ //function for searching and returning a node // having problems with it
        if(root==nullptr)
            return ;
        if(root->data==n)
            spare= root;

        searchn(root->left,n);
        searchn(root->right,n);
    }

    void leftn(node *root){  //function to insert left child of a node with given key
        if(root==nullptr){  //if tree not created
            cout<<"Root not created!"<<endl;
            return;
        }
        int n;
        cout<<"Enter value of parent node: ";
        cin>>n;
        searchn(root,n);
        node *curr=spare; //searcing the node in the tree with given key
        spare=nullptr; //setting spare back to null
        if(curr==nullptr){  //if no such node exists
            cout<<"No such node exists!"<<endl;
            return;
        }
        if(curr->left!=nullptr){  //if left child already exists
            cout<<"Left child already exists!"<<endl;
            return;
        }
        cout<<"Enter value of node to be added: ";
        cin>>n;
        searchn(root,n); //searching if node with value n already exists
        node *addn=spare;
        spare=nullptr; //setting spare back to null
        if(addn!=nullptr){  //if such node exists
            cout<<"Such node already exists!"<<endl;
            return;
        }
        addn=new node(n);
        curr->left=addn;
    }

    void rightn(node *root){  //function to insert right child of a node with given key
        if(root==nullptr){ //if tree not created
            cout<<"Root not created!"<<endl;
            return;
        }
        int n;
        cout<<"Enter value of parent node: ";
        cin>>n;
        searchn(root,n);
        node *curr=spare;  //searching the required node in tree
        spare=nullptr; //setting spare back to null
        if(curr==nullptr){  //if no such node exists
            cout<<"No such node exists!"<<endl;
            return;
        }
        if(curr->right!=nullptr){  //if right child already present
            cout<<"Right child already exists!"<<endl;
            return;
        }

        cout<<"Enter value of node to be added: ";
        cin>>n;
        searchn(root,n);  //searching if such node already exists
        node *addn=spare;
        spare=nullptr; //setting spare back to null
        if(addn!=nullptr){  //if such node exists
            cout<<"Such node already exists!"<<endl;
            return;
        }
        addn=new node(n);
        curr->right=addn;
    }



    void preOrder(node* root){  //function for recursive preorder traversal
        if(root==nullptr)
            return;
        cout<<root->data<<"\t";
        preOrder(root->left);
        preOrder(root->right);
    }

    void postOrder(node* root){  //post order traversal
        if(root==nullptr)
            return;
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<"\t";
    }

    void inOrder(node* root){  //inorder traversal
        if(root==nullptr)
            return;
        inOrder(root->left);
        cout<<root->data<<"\t";
        inOrder(root->right);

    }

};


int main(){
    node *root=nullptr;  //creating root pointer

    cout<<"Make selection: "<<endl;
    cout<<"1. Create a new tree"<<endl;
    cout<<"2. Add left child to a node"<<endl;
    cout<<"3. Add right child to a node"<<endl;
    cout<<"4. Display tree in pre-order fashion"<<endl;
    cout<<"5. Display tree in post-order fashion"<<endl;
    cout<<"6. Display tree in in-order fashion"<<endl;
    int n;
    while(cin>>n){
        switch(n){
        case 1:
            root=root->create(root);  //assigning created root to root
            break;
        case 2:
            root->leftn(root);  //calling left child insert on tree having root as root
            break;
        case 3:
            root->rightn(root);
            break;
        case 4:
            root->preOrder(root);
            cout<<endl;
            break;

        case 5:
            root->postOrder(root);
            cout<<endl;
            break;

        case 6:
            root->inOrder(root);
            cout<<endl;
            break;

        }
    }

}
