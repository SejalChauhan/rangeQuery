
#include<string>
#include<iostream>

#pragma once //just include once

#define VERSION "0.0.0"

std::string version();

class rangeC {
private:
    std::string s;
public:
// represent range
    struct range {
        std::string low, high;
    };

// interval search tree node
    struct rNode {
        range *ivl;
        std::string max;
        rNode *left, *right;
    };


// overload comparator
    bool operator < (rangeC const &obj) {
        rangeC res;
        return res.s < obj.s;
    }
    bool operator > (rangeC const &obj) {
        rangeC res;
        return res.s > obj.s;
    }
    bool operator == (rangeC const &obj) {
        rangeC res;
        return res.s == obj.s;
    }
};

// creates a new node
rangeC::rNode *newNode(rangeC::range r);

// insert range
rangeC::rNode *insertRange(rangeC::rNode *root, rangeC::range r);

// utility search range
bool checkOverlap(rangeC::range r1, std::string r2);

// search range
rangeC::range *searchRange(rangeC::rNode *root, std::string r);

// delete range
bool deleteRange(rangeC::rNode *root, rangeC::range r);

// print utility
void inorderPrint(rangeC::rNode *root);
