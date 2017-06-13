/* Driver program for running the API.
 * This program is simple.
 */

#include "api.h"
#include <iostream>

int main(int argc, char **argv) {
    std::cout << "Starting Driver Program. API version " << version()
        << std::endl;
    Interval ints[] = {{15, 20}, {10, 30}, {17, 19}, {5, 20}, {12, 15},
                        {30, 40}};
    int n = sizeof(ints)/sizeof(ints[0]);
    ITNode *root = NULL;
    for (int i = 0; i < n; i++){
        root = insert(root, ints[i]);
    }

    std::cout << "Inorder traversal\n";
    inorder(root);

    Interval x = {6,7};
    std::cout << "searching for [" << x.low << ", " << x.high << "]\n";
    Interval *res = overlapSearch(root, x);
    if (res == NULL)
        std::cout << "None found.\n";
    else
        std::cout << "Overlaps with [" << res->low <<", " << res->high
             << "]";

    return 0;
}
