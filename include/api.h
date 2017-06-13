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
        int i=0;
        while (res.s[i] < obj.s[i]){
            i++;
        }
        std::cout<<"less"<<i;
        if(res.s[i] > obj.s[i])
            return false;

        return true;
    }
    bool operator > (rangeC const &obj) {
        rangeC res;
        int i=0;
        while (res.s[i] > obj.s[i]){
            i++;
        }
        std::cout<<"more"<<i;
        if(res.s[i] < obj.s[i])
            return false;

        return true;
    }
    bool operator == (rangeC const &obj) {
        rangeC res;
        int i=0;
        while (res.s[i] == obj.s[i]){
            i++;
        }
        std::cout<<"eq"<<i;
        if(res.s[i] != obj.s[i])
            return false;

        return true;
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
rangeC::rNode *deleteRange(rangeC::rNode *root, rangeC::range r);

// print utility
void inorderPrint(rangeC::rNode *root);
