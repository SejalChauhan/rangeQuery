/* Driver program for running the API.
 * This program is simple.
 */

#include <iostream>
#include "api.h"


int main(int argc, char **argv) {
    std::cout << "Starting Driver Program. API version " << version()
              << std::endl;
    rangeC::range ints[] = {{"Aaa", "BBB"}, {"CC", "DD"}, {"EE", "FF"}};
    int n = sizeof(ints)/sizeof(ints[0]);
    rangeC::rNode *root = NULL;
    for (int i = 0; i < n; i++){
        root = insertRange(root, ints[i]);
    }

    std::cout << "Inorder traversal\n";
    inorderPrint(root);

    std::string x = {"c"};
    std::cout << "searching for " << x<<std::endl;
    rangeC::range *res = searchRange(root, x);
    if (res == NULL)
        std::cout << "None found.\n";
    else
        std::cout << "Overlaps with [" << res->low <<", " << res->high
                  << "]";

    return 0;
}

