#pragma once

#include "base.h"

template <class KeyType>
class AvlTree : public Competitor {

 private:
  size_t data_size;

  class node{
        public:
            T key;
            int height;
            node * left;
            node * right;
            uint64_t index;

            node(T k, uint64_t i){
                height = 1;
                key = k;
                index = i;
                left = NULL;
                right = NULL;
            }
    };

    node * root = NULL;
    int n;

    int height(node * head){
        if(head==NULL) return 0;
        return head->height;
    }
    node * rightRotation(node * head){
        node * newhead = head->left;
        head->left = newhead->right;
        newhead->right = head;
        head->height = 1+max(height(head->left), height(head->right));
        newhead->height = 1+max(height(newhead->left), height(newhead->right));
        return newhead;
    }

    node * leftRotation(node * head){
        node * newhead = head->right;
        head->right = newhead->left;
        newhead->left = head;
        head->height = 1+max(height(head->left), height(head->right));
        newhead->height = 1+max(height(newhead->left), height(newhead->right));
        return newhead;
    }

    void inorderUtil(node * head){
        if(head==NULL) return ;
        inorderUtil(head->left);
        cout<<head->key<<" ";
        inorderUtil(head->right);
    }

    node * insertUtil(node * head, T x, int i){
        if(head==NULL){
            n+=1;
            node * temp = new node(x,i);
            return temp;
        }
        if(x < head->key) head->left = insertUtil(head->left, x, i);
        else if(x > head->key) head->right = insertUtil(head->right, x, i);
        head->height = 1 + max(height(head->left), height(head->right));
        int bal = height(head->left) - height(head->right);
        if(bal>1){
            if(x < head->left->key){
                return rightRotation(head);
            }else{
                head->left = leftRotation(head->left);
                return rightRotation(head);
            }
        }else if(bal<-1){
            if(x > head->right->key){
                return leftRotation(head);
            }else{
                head->right = rightRotation(head->right);
                return leftRotation(head);
            }
        }
        return head;
    }
    node * removeUtil(node * head, T x){
        if(head==NULL) return NULL;
        if(x < head->key){
            head->left = removeUtil(head->left, x);
        }else if(x > head->key){
            head->right = removeUtil(head->right, x);
        }else{
            node * r = head->right;
            if(head->right==NULL){
                node * l = head->left;
                delete(head);
                head = l;
            }else if(head->left==NULL){
                delete(head);
                head = r;
            }else{
                while(r->left!=NULL) r = r->left;
                head->key = r->key;
                head->right = removeUtil(head->right, r->key);
            }
        }
        if(head==NULL) return head;
        head->height = 1 + max(height(head->left), height(head->right));
        int bal = height(head->left) - height(head->right);
        if(bal>1){
            if(height(head->left) >= height(head->right)){
                return rightRotation(head);
            }else{
                head->left = leftRotation(head->left);
                return rightRotation(head);
            }
        }else if(bal < -1){
            if(height(head->right) >= height(head->left)){
                return leftRotation(head);
            }else{
                head->right = rightRotation(head->right);
                return leftRotation(head);
            }
        }
        return head;
    }
    node * searchUtil(node * head, T x){
        if(head == NULL) return NULL;
        T k = head->key;
        if(k == x) return head;
        if(k > x) return searchUtil(head->left, x);
        if(k < x) return searchUtil(head->right, x);
    }

 public:
 
  uint64_t Build(const std::vector<KeyValue<KeyType>>& data) {
    this -> root = NULL;

    data_size = data.size();

    for(uint64_t i = 0; i < data_size; i++){
        insert(root, data[i].key, i);
    }

    return 0;
  }

  SearchBound EqualityLookup(const KeyType lookup_key) const {
    node* res = searchUtil(root,x);
    return (SearchBound){res->index, res->index};
  }

  void insert(T x, uint64_t i){
        root=insertUtil(root, x, i);
    }
    void remove(T x){
        root=removeUtil(root, x);
    }

  std::string name() const { return "AVLTree"; }

  std::size_t size() const { return 0; }

};
