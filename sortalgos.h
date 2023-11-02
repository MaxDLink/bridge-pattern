#ifndef SORTALGOS_H
#define SORTALGOS_H

#include <vector>
#include <functional>

template <typename T>
class SortAlgos {
public:
    static void bubbleSort(std::vector<T>& data);
    static void mergeSort(std::vector<T>& data);
    static void insertionSort(std::vector<T>& data);
    static void binaryTreeSort(std::vector<T>& data);

private:
    static void mergeSortRecursive(std::vector<T>& data, int left, int right);
    static void merge(std::vector<T>& data, int left, int middle, int right);

    class TreeNode {
    public:
        T value;
        TreeNode* left;
        TreeNode* right;
        TreeNode(T val) : value(val), left(nullptr), right(nullptr) {}
    };
    static void insertTreeNode(TreeNode*& node, T value);
    static void inOrderTraversal(TreeNode* node, std::vector<T>& data);
};

// Implementation of Bubble Sort
template <typename T>
void SortAlgos<T>::bubbleSort(std::vector<T>& data) {
    bool swapped;
    for (size_t i = 0; i < data.size(); ++i) {
        swapped = false;
        for (size_t j = 0; j < data.size() - i - 1; ++j) {
            if (data[j] > data[j + 1]) {
                std::swap(data[j], data[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// Implementation of Merge Sort
template <typename T>
void SortAlgos<T>::mergeSort(std::vector<T>& data) {
    mergeSortRecursive(data, 0, data.size() - 1);
}

template <typename T>
void SortAlgos<T>::mergeSortRecursive(std::vector<T>& data, int left, int right) {
    if (left >= right) return;
    int middle = left + (right - left) / 2;
    mergeSortRecursive(data, left, middle);
    mergeSortRecursive(data, middle + 1, right);
    merge(data, left, middle, right);
}

template <typename T>
void SortAlgos<T>::merge(std::vector<T>& data, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<T> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = data[left + i];
    for (int j = 0; j < n2; j++) R[j] = data[middle + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            data[k] = L[i];
            i++;
        } else {
            data[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        data[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        data[k] = R[j];
        j++;
        k++;
    }
}

// Implementation of Insertion Sort
template <typename T>
void SortAlgos<T>::insertionSort(std::vector<T>& data) {
    T key;
    int j;
    for (size_t i = 1; i < data.size(); i++) {
        key = data[i];
        j = i - 1;
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

// Implementation of Binary Tree Sort
template <typename T>
void SortAlgos<T>::binaryTreeSort(std::vector<T>& data) {
    TreeNode* root = nullptr;
    for (T& val : data) {
        insertTreeNode(root, val);
    }
    data.clear();
    inOrderTraversal(root, data);
}

template <typename T>
void SortAlgos<T>::insertTreeNode(TreeNode*& node, T value) {
    if (!node) {
        node = new TreeNode(value);
    } else if (value < node->value) {
        insertTreeNode(node->left, value);
    } else {
        insertTreeNode(node->right, value);
    }
}

template <typename T>
void SortAlgos<T>::inOrderTraversal(TreeNode* node, std::vector<T>& data) {
    if (node) {
        inOrderTraversal(node->left, data);
        data.push_back(node->value);
        inOrderTraversal(node->right, data);
    }
}

#endif // SORTALGOS_H
