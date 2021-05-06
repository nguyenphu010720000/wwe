#include<iostream>
#include <bits/stdc++.h>
using namespace std;
struct Node {
        int sbd;        // So bao danh sinh vien
        string hoTen;   // Ho ten sinh vien
        float dtb;      // dtb = diem trung binh 
        Node* left;
        Node* right;
        // Ham tao
        Node(int s, string h, float dtb,  Node * l, Node * r) 
        {  
            sbd=s;
            hoTen=h;
            dtb=dtb;
            left=l;
            right=r;
        }
};
class BST { 
private:   
    Node* root;

    // Xoa rong cay
    Node* makeEmpty(Node* root) {
    	if(root==NULL)
    		return NULL;
	    	makeEmpty(root->left);
	    	makeEmpty(root->right);
	    	delete root;
    	return NULL;
    }

    /*// Chen thong tin cua 1 sinh vien vao cay
    Node* insert(int sbd, string hoTen,float dtb,int key Node* root){
        if(root == NULL)
            root = new Node(sbd,hoTen,dtb, NULL, NULL);
        else if(sbd < root->sbd)
            root->left = insert(sbd,hoTen,dtb, root->left);
        else if(sbd > root->sbd)
            root->right = insert(sbd,hoTen,dtb, root->right);
        return root;
    }*/
    Node*insert(Node*node,int key){
    	if(node==NULL)return(newNode(key));
    	if(key<node->key)node->left=insert(node->left,key);
    	else if(key>node->key)node->right=insert(node->right,key);
    	else return node;
    	node->height=1+max(height(node->left),height(node->right));
    	int (balanceFactor>1){
    		if(key<node->left->key){
    			return rightRotate(node);
			}
			else if(key>node->left->key){
				node->left=leftRotate(node->left);
				return rightRotate(node);
			}
		}
	}

    // Tim thong tin sinh vien theo so bao danh
    Node * find(Node * r, int sbd){
        if(r==NULL)
        	return NULL;
        else if(sbd<r->sbd)
        	find(r->left,sbd);
        else if(sbd>r->sbd)
        	find(r->right,sbd);
        else
        	return r;
    }

    Node * findMin(Node *r){
        struct Node *temp=r;
        while(temp->left!=NULL){
        	temp=temp->left;
		}
		return temp;
    }

    Node * findMax(Node *r){
        struct Node *temp=r;
        while(temp->right!=NULL){
        	temp=temp->right;
		}
		return temp;
    }

    // Hien thi danh sach sinh vien theo trung thu tu
    void inorder(Node* r) {
       if(r == NULL)
            return;
        inorder(r->left);
        cout << r->sbd<<" "<<r->hoTen<<" "<<r->dtb<<endl;
        inorder(r->right);
    }
    // Hien thi danh sach sinh vien theo tien thu tu
    void preorder(Node* r) {
       if(r == NULL)
            return;
        cout << r->sbd<<" "<<r->hoTen<<" "<<r->dtb<<endl;
        preorder(r->left);
        preorder(r->right);
    }

    // Hien thi danh sach sinh vien theo hau thu tu
    void postorder(Node* r) {
       if(r == NULL)
            return;
        preorder(r->left);
        preorder(r->right);
        cout << r->sbd<<" "<<r->hoTen<<" "<<r->dtb<<endl;
    }

    // Xoa bo sinh vien khoi cay 
    Node * remove(int sbd, Node * root){
        if(root==NULL)
        	return NULL;
        if(sbd<root->sbd)
    		root->left=remove(sbd,root->left);
    	else if(sbd>root->sbd)
    		root->right=remove(sbd,root->right);
    	else{
    		if(root->left==NULL){
    			struct Node* temp=root->right;
    			free(root);
    			return temp;
			}
			else if(root->right==NULL){
    			struct Node* temp=root->left;
    			free(root);
    			return temp;
			}
			struct Node* temp = findMin(root->right);
    		root->sbd=temp->sbd;
    		root->right=remove(temp->sbd, root->right);
		}
		return root;
    }  

public:
    // Ham tao ban dau cay rong
    BST() {
    	root=NULL;
    }
    // Ham huy xoa het cac nut trong cay
    ~BST() { 
		makeEmpty();
    }
    // Kiem tra cay co rong hay khong.
    bool isEmpty()
    {
        return (root==NULL);
    }

    // Xoa het cac nut tren cay.
    void makeEmpty()
    {
       makeEmpty(root);
    }

    // Chen mot sinh vien moi vao cay 
    void insert(int sbd, string hoTen,float dtb) {
    	root=insert(sbd,hoTen,dtb,root);
    }

    // Xoa mot sinh vien khoi cay theo so bao danh 
    void remove(int sbd){
    	root=remove(sbd,root);
    }

    // Hien thi danh sach theo trung, tien, hau thu tu 
    void display() {
    	inorder(root);
    }

    // Ham tiem kiem sinh vien theo so bao danh
    Node * search(int sbd){
    	return find(root,sbd);
    }

   
};

int main() {
    BST t;
    int sbd, sbd_del;
    t.insert(3,"Tran Hai Au",5);
    t.insert(5,"Le Hoang Quoc Bao",5);
    t.insert(7, "Do Van Chung",3);
    t.insert(9, "Hoang Anh Dat",4);
    t.insert(11, "Vo Minh Du",5);
    t.insert(1, "Le Nguyen Tuan Anh",6);
    t.insert(10, "Huynh Thanh Dong",7);
    t.insert(16, "Lam Bao Tho Em",8);
    t.insert(20, "Le Huy Hoang",9);
    t.insert(2, "Tran Minh Anh",10);
    // Hien thi danh sach sinh vien theo thu tu trung thu tu 
    t.display();
    cout<<"Nhap so bao danh can tim: "; cin>>sbd;
    Node * n1 = t.search(sbd); 
    if(n1!=NULL) cout<<"Thong tin cua sinh vien la:"<<" SBD: "<<n1->sbd<<"- Ten: "<<n1->hoTen<<endl;
    else cout<<"Khong tim thay sbd " <<sbd<<endl; 
    // Xoa so bao danh 2 va hien thi lai danh sach sinh vien
    cout<<"Nhap so bao danh sinh vien can xoa: "; cin>>sbd_del;
    t.remove(sbd_del);  
    // Hien thi danh sach sinh vien sau khi xoa
    cout<<"Danh sach sinh vien sau khi xoa:"<<endl;
    t.display();
    return 0;
}
