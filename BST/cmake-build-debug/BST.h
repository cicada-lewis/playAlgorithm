//
// Created by 17138 on 2018/6/3 0003.
//

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
        Value *res=&(search(root,key)->val);
        return res;
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

    Node* search(Node* x,Key key){
        if(x== nullptr){
            return nullptr;
        }
        if(x->key==key){
            return x;
        }
        else if(x->key>key){
            return search(x->left,key);
        }
        else if(x->key<key){
            return search(x->right,key);
        }
    }
};

#endif //BST_BST_H
