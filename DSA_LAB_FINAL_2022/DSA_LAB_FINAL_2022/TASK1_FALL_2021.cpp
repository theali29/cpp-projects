#include"LinkList.h"
template<class T>
Node<T>* make_2d_list(T mat[][3], int i, int j, int m, int n) {
    if (i > n - 1 || j > m - 1)
        return NULL;
    Node<T>* temp = new Node<T>(mat[i][j]);
    temp->right = make_2d_list(mat, i, j + 1, m, n);
    temp->down = make_2d_list(mat, i + 1, j, m, n);
    return temp;
}
int main() {
    LinkList<int>L1;
    
    int m = 3, n = 3;
    int mat[][3] = {
       { 1,2,3 },
       { 4, 5, 6 },
       { 7, 8, 9 } };
    
    Node<int>*head=make_2d_list(mat, 0, 0, m, n);
    L1.show_2d_list(head);
}