#include "api.h"
#include<iostream>

// return the version string of the API
std::string version() {
    std::string version(VERSION);
    return version; 
}

// creates a new node
ITNode * newNode(Interval i){
    ITNode *temp = new ITNode;
    temp->i = new Interval(i);
    temp->max = i.high;
    temp->left = temp->right = NULL;
}

// insert interval
ITNode *insert(ITNode *root, Interval i){
    //base case
    if (root == NULL){
        return newNode(i);
    }

    // low value of root interval
    int l = root->i->low;

    // if interval's low value if smaller, left subtree insertion
    if (i.low < l)
        root->left = insert(root->left, i);
    else
        root->right = insert(root->right, i);

    // update max value
    if (root->max < i.high)
        root->max = i.high;

    return root;
}

// utility for search 
bool doOverlap(Interval i1, Interval i2){
    if (i1.low <= i2.high && i2.low <= i1.high)
        return true;
    return false;
}

// search interval
Interval *overlapSearch(ITNode *root, Interval i){
    // base case
    if (root == NULL) return NULL;

    // overlap with root
    if (doOverlap(*(root->i), i))
        return root->i;

    // left child max is greater than or equal
    // to low value of interval, present in left subtree
    if (root->left != NULL && root->left->max >= i.low)
        return overlapSearch(root->left, i);

    // else right subtree
    return overlapSearch(root->right, i);
}

// delete interval
bool deleteInterval(ITNode *root, Interval i){
    // base case
    if (root == NULL) return false;
    // overlap with root
    
    return true;
}

void inorder(ITNode *root){
    if (root == NULL) return;
    inorder(root->left);
    std::cout << "[" << root->i->low << ", " << root->i->high <<"]"
         << "max = "<< root->max <<std::endl;
    inorder(root->right);
}

