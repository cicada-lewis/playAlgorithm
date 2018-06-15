//
// Created by 17138 on 2018/6/3 0003.
//

#include <istream>
#include <queue>

#ifndef BST_BST_H
#define BST_BST_H


template <typename Key,typename Value>
class BST{
private:
    struct Node{
        Key key;
        Value val;
        Node *left,*right;

        Node(Key key,Value val){
            this->key=key;
            this->val=val;
            this->left=this->right= nullptr;
        }
    };

    Node *root;
    int count;

public:
    BST(){
        root= nullptr;
        count =0;
    }

    ~BST(){
        // TODO
        destroy(root);
    }

    int size(){
        return count;
    }

    bool isEmpty(){
        return count==0;
    }

    void insert(Key key,Value val){
        root=insert(root,key,val);
    }

    bool contain(Key key){
        return contain(root,key);
    }

    Value* search(Key key){
//        Value *res=search(root,key);
        Value *res=search_NonRecur(root,key);
        return res;
    }

    void preOrder(){
        preOrder(root);
    }

    void  midOrder(){
        midOrder(root);
    }

    void postOrder(){
        postOrder(root);
    }

    void levelOrder(){
        levelOrder(root);
    }

    void deleteMin(){
        root=deleteMin(root);
    }

    void deleteMax(){
        root=deleteMax(root);
    }
private:

    Node* insert(Node* x,Key key,Value val){
        if(x== nullptr){
            count++;
            return new Node(key,val);
        }
        if(key==x->key){
            x->val=val;
        }
        else if(key<x->key){
            x->left=insert(x->left,key,val);
        }
        else{
            x->right = insert(x->right,key,val);
        }
        return x;
    }

    Node* insert_NonRecur(Node* x,Key key,Value val){
        Node* p=x;
        while(true){
            if(p== nullptr){
                p=new Node(key,val);
                break;
            }
            else if(key==p->key){
                p->val=val;
                break;
            }
            else if(key<p->key){
                p=p->left;
            }
            else{
                p=p->right;
            }
        }
        return x;
    }

    bool contain(Node* x,Key key){
        if(x== nullptr){
            return false;
        }
        if(x->key==key){
            return true;
        }
        else if(x->key>key){
            return contain(x->left,key);
        }
        else if(x->key<key){
            return contain(x->right,key);
        }
    }

    bool contain_NonRecur(Node * x,Key key){
        Node *p=x;
        while(true){
            if(p== nullptr){
                return false;
            }
            else if(p->key>key){
                p=p->left;
            }
            else if(p->key<key){
                p=p->right;
            }
            else{
                return true;
            }
        }
    }

    Value* search(Node* x,Key key){
        if(x== nullptr){
            return nullptr;
        }
        if(x->key==key){
            return &(x->val);
        }
        else if(x->key>key){
            return search(x->left,key);
        }
        else if(x->key<key){
            return search(x->right,key);
        }
    }

    Value* search_NonRecur(Node* x,Key key){
        Node *p=x;
        while(true){
            if(p== nullptr){
                return nullptr;
            }
            if(p->key==key){
                return &p->val;
            }
            else if(p->key<key){
                p=p->right;
            }
            else{
                p=p->left;
            }
        }
    }

    void preOrder(Node* node){
        if(node!= nullptr){
            std::cout<<node->key<<" : "<<node->val<<std::endl;
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void midOrder(Node* node){
        if(node!= nullptr){
            preOrder(node->left);
            std::cout<<node->key<<" : "<<node->val<<std::endl;
            preOrder(node->right);
        }
    }

    void postOrder(Node* node){
        if(node!= nullptr){
            preOrder(node->left);
            preOrder(node->right);
            std::cout<<node->key<<" : "<<node->val<<std::endl;
        }
    }

    void destroy(Node *node) {
        if(node!= nullptr){
            destroy(node->left);
            destroy(node->right);

            delete node;
            count--;
        }
    }

    void levelOrder(Node *node){
        std::queue<Node*> Q;
        if(node!= nullptr){
            Q.push(node);
        }
        Node* front;
        while(!Q.empty()){
            front=Q.front();Q.pop();
            std::cout<<front->key<<" : " <<front->val<<std::endl;
            if(front->left!= nullptr)
                Q.push(front->left);
            if(front->right!= nullptr)
                Q.push(front->right);
        }
    }

    Node* getMinNode(Node *node){
        if(node->left== nullptr){
            return node;
        }

        return getMinNode(node->left);
    }

    Node* getMaxNode(Node *node){
        if(node->right== nullptr){
            return node;
        }

        return getMaxNode(node->right);
    }

    Node* deleteMin(Node* node){
        if(node->left== nullptr){
            Node* rightNode=node->right;

            delete node;
            count--;
            return rightNode;
        }
        node->left= deleteMin(node->left);
        return node;
    }

    Node* deleteMax(Node* node){
        if(node->right== nullptr){
            Node* leftNode=node->left;
            delete node;
            count--;
            return leftNode;
        }
        node->right =deleteMax(node->right);
        return node;
    }
};

#endif //BST_BST_H
