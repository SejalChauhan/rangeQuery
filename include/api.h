#include <string>

#pragma once //just include once

#define VERSION "0.0.0"

std::string version();

// represent interval
struct Interval{
    int low, high;
};

// interval search tree node
struct ITNode{
    Interval *i;
    int max;
    ITNode *left, *right;
};

// creates a new node
ITNode * newNode(Interval i);

// insert interval
ITNode *insert(ITNode *root, Interval i);

// utility search interval
bool doOverlap(Interval i1, Interval i2);

// search interval
Interval *overlapSearch(ITNode *root, Interval i);

// delete interval
bool deleteInterval(ITNode *root, Interval i);

// print utility
void inorder(ITNode *root);

