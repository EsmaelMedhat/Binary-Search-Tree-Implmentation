#include <iostream>
using namespace std;
class Node
{
private:
int data;
Node*RightChild;
Node*LeftChild;
public:
void set_data(int data){
this->data=data;
}
void set_rigthchild(Node*RightChild){
this->RightChild=RightChild;
}
void set_leftchild(Node*LeftChild){
this->LeftChild=LeftChild;
}
Node *get_Rightchild(){return RightChild;}
Node *get_Leftchild(){return LeftChild;}
int get_data(){return data;}
Node(){
RightChild=NULL;
LeftChild=NULL;
}
};
class BinarySearchTree{
private:
	Node*MainRoot;
    int length;
Node* insert(int data,Node*root){
   if(root==NULL)
{
Node *newnode=new Node;
newnode->set_data(data);
root=newnode;
length++;
}
else if(data>=root->get_data())
root->set_rigthchild(insert(data,root->get_Rightchild()));
else root->set_leftchild(insert(data,root->get_Leftchild()));

return root;
	}
void InOrder(Node*root){
if(root==NULL)
return;
InOrder(root->get_Leftchild());
cout<<"data :"<<root->get_data()<<endl;
InOrder(root->get_Rightchild());
}
void PreOrder(Node*root){
if(root==NULL)
return;
cout<<"data :"<<root->get_data()<<endl;
PreOrder(root->get_Leftchild());
PreOrder(root->get_Rightchild());
}
void PostOrder(Node*root){
if(root==NULL)
return;
PostOrder(root->get_Leftchild());
PostOrder(root->get_Rightchild());
cout<<"data :"<<root->get_data()<<endl;

}
Node*search(Node*root,int val){
  if(root==NULL)
 return NULL;
  else if(root->get_data()==val)
  return root;
  else if(root->get_data()<val)
 return search(root->get_Rightchild(),val);
 else return search(root->get_Leftchild(),val);
}
Node* find_minmum(Node*root){
if(root==NULL)
return NULL;
else if(root->get_Leftchild()==NULL)
return root;

return find_minmum(root->get_Leftchild());
}
Node*find_maximum(Node*root){
if(root==NULL)
return NULL;
else if(root->get_Rightchild()==NULL)
return root;

return find_maximum(root->get_Rightchild());
}
Node* Delete(Node* root, int data) {
  if (root == NULL) {
    return NULL;
      } else if (data < root->get_data()) {
    root->set_leftchild(Delete(root->get_Leftchild(), data));
  } else if (data > root->get_data()) {
    root->set_rigthchild(Delete(root->get_Rightchild(), data));
  } else {

    if (root->get_Leftchild() == NULL && root->get_Rightchild() == NULL) {
     delete root;
      root = NULL;
    } else if (root->get_Leftchild() != NULL && root->get_Rightchild() == NULL) {

      Node* temp = root;
      root = root->get_Leftchild();
      delete temp;
    } else if (root->get_Leftchild() == NULL && root->get_Rightchild() != NULL) {

      Node* temp = root;
      root = root->get_Rightchild();
      delete temp;
    } else {

      Node* temp = find_maximum(root->get_Leftchild());
      root->set_data(temp->get_data());
      root->set_leftchild(Delete(root->get_Leftchild(), temp->get_data()));
   }
  }
  return root;
}
public:
void insert(int data){
MainRoot=insert(data,MainRoot);
}
BinarySearchTree(){MainRoot=NULL;
length=0;
}
void display(){
PreOrder(MainRoot);
}
bool search(int val){return search(MainRoot,val)!=NULL;}
int get_minmum(){
return find_minmum(MainRoot)->get_data();
}
int get_maximum(){
return find_maximum(MainRoot)->get_data();
}
void Delete(int element){
MainRoot=Delete(MainRoot,element);
length--;
}
int get_size(){return length;}
};
int main(){
BinarySearchTree b;
b.insert(10);
for(int i=0;i<=20;i++)
b.insert(i);
b.insert(10000);
b.Delete(1);
b.Delete(15);
b.Delete(12);
cout<<b.get_size()<<endl;
b.display();
return 0;
}
