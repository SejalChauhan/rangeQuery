//
// Created by Sejal on 6/13/17.
//

#include<string>
#include<iostream>
#include "api.h"

// return the version string of the API
std::string version() {
    std::string version(VERSION);
    return version;
}

// creates a new node
rangeC::rNode * newNode(rangeC::range r){
    rangeC::rNode *temp = new rangeC::rNode;
    temp->ivl = new rangeC::range(r);
    temp->max = r.high;
    temp->left = temp->right = NULL;
    return temp;
}

// insert range
rangeC::rNode *insertRange(rangeC::rNode *root, rangeC::range r){
    //base case
    if (root == NULL){
        return newNode(r);
    }

    // low value of root interval
    std::string l = root->ivl->low;

    // if interval's low value if smaller, left subtree insertion
    if (r.low.compare(l) < 0)
        root->left = insertRange(root->left, r);
    else
        root->right = insertRange(root->right, r);

    // update max value
    if (root->max.compare(r.high) > 0)
        root->max.assign(r.high);

    return root;
}

// utility for search
bool checkOverlap(rangeC::range r1, std::string r2){
    /*std::cout << "compare " <<r1.low << " and "<<r2<< " result "
              <<r1.low.compare(r2) <<", compare " << r1.high<<" and "<< r2 <<
              " result " <<r1.high.compare(r2)<<std::endl;
    if ((r1.low.compare(r2) < 0 || r1.low.compare(r2) == 0) &&
            (r1.high.compare(r2) > 0 || r1.high.compare(r2) == 0)) {*/
    std::cout<<"compare " <<r1.low << " and "<<r2<< " result "
             <<(r1.low < r2) <<", compare " << r1.high<<" and "<< r2 <<
             " result " <<(r1.high > r2)<<std::endl;
    if ((r1.low < r2 || r1.low == r2) && (r1.high > r2 || r1.high == r2 ))
        return true;

    return false;
}

// search range
rangeC::range *searchRange(rangeC::rNode *root, std::string r){
    // base case
    if (root == NULL) return NULL;

    // overlap with root
    if (checkOverlap(*(root->ivl), r))
        return root->ivl;

    // left child max is greater than or equal
    // to low value of interval, present in left subtree
    if (root->left != NULL && root->left->max >= r)
        return searchRange(root->left, r);

    // else right subtree
    return searchRange(root->right, r);
}

rangeC::rNode * minValNode(rangeC::rNode* node)
{
    rangeC::rNode* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

// delete interval
rangeC::rNode *deleteRange(rangeC::rNode *root, rangeC::range *r){

    // base case
    if (root == NULL) return root;

    if ((root->ivl->low < r->high || root->ivl->low == r->high) &&
            (root->ivl->high > r->low || root->ivl->high == r->low))
        root->left = deleteRange(root->left, r);
    else if ((root->ivl->high < r->low || root->ivl->low == r->high) &&
            (root->ivl->high > r->low || root->ivl->high == r->low))
        root->right = deleteRange(root->right, r);

    else {
        if (root->left == NULL){
            rangeC::rNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL){
            rangeC::rNode *temp = root->left;
            free(root);
            return temp;
        }
        rangeC::rNode *temp = minValNode(root->right);
        root->ivl = temp->ivl;
        root->right = deleteRange(root->right, temp->ivl);
    }

    return root;
}

void inorderPrint(rangeC::rNode *root){
    if (root == NULL) return;
    inorderPrint(root->left);
    std::cout << "[" << root->ivl->low << ", " << root->ivl->high <<"]"
              << "max = "<< root->max <<std::endl;
    inorderPrint(root->right);
}