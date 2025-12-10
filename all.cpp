#include<iostream>
#include<string>
using namespace std;

// Node for BST
struct Node{
    int bookID;
    string bookName;
    Node* left;
    Node* right;

    Node(int id,string name){
        bookID=id;
        bookName=name;
        left=right=NULL;
    }
};

// Insert into BST
Node* insert(Node* root,int id,string name){
    if(root==NULL)
        return new Node(id,name);
    if (id<root->bookID)
        root->left=insert(root->left,id,name);
    else
        root->right=insert(root->right,id,name);
    return root;
}

// Search Book by ID
Node* search(Node* root,int id){
    if(root==NULL) return NULL;
    if(root->bookID==id) return root;
    if(id<root->bookID)
        return search(root->left,id);
    return search(root->right,id);
}

// Display sorted books
void inorder(Node* root){
    if(root==NULL)return;
    inorder(root->left);
    cout<<"Book ID: "<<root->bookID<< "Book Name: "<<root->bookName<<endl;
    inorder(root->right);
}

// Wait for Enter
void wait() {
    cout<<"\nPress ENTER to continue...";
    cin.ignore();
    cin.get();
}
int main() {
    Node* root = NULL;

    // Preloaded data
    root = insert(root, 45, "Data Structures");
    root = insert(root, 10, "C Programming");
    root = insert(root, 78, "Digital Electronics");
    root = insert(root, 23, "Engineering Mathematics");
    root = insert(root, 5,  "Basic Electrical");
    root = insert(root, 60, "OOP in C++");

    int choice;
    while (true) {

        cout<<"\nMENU\n";
        cout<<"1. Store Returned Book\n";
        cout<<"2. Check Returned Book\n";
        cout<<"3. Show ALL Returned Books (Sorted)\n";
        cout<<"4. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        // Clear leftover characters
        cin.ignore();
        if(choice==1) {
            int id;
            string name;
            cout<<"Enter Book ID: ";
            cin>>id;
            cin.ignore();
            cout<<"Enter Book Name: ";
            getline(cin,name);
            root=insert(root,id,name);
            cout<<"\nBook Stored Successfully!\n";
            wait();
        }
        else if(choice==2) {
            int id;
            cout<<"Enter Book ID to search: ";
            cin>>id;

            Node* result=search(root,id);
            if(result!=NULL) {
                cout<<"\nBook Found:\n";
                cout<<"Book ID: "<<result->bookID<<endl;
                cout<<"Book Name: "<<result->bookName<<endl;
            } else{
                cout<<"\nBook NOT Returned Yet!\n";
            }
            wait();
        }
        else if(choice==3){
            cout<<"\nReturned Books (Sorted):\n";
            inorder(root);
            wait();
        }
        else if(choice==4){
            cout<<"\nExiting Program...\n";
            break;
        }
        else{
            cout<<"\nInvalid choice! Try again.\n";
            wait();
        }
    }
    return 0;
}