#include "BinaryTree.h"

template<typename T>
BinaryTree<T>::BinaryTree()
{
    root = nullptr;
}
template<typename T>
Node<T>* BinaryTree<T>::newNode(T d)
{
    Node<T>* node = new Node<T>(d);
    return node;
}
template<typename T>
void BinaryTree<T>::insert()
{
    //root = privateInsert();
    iterativeInsert();
}
template<typename T>
Node<T>* BinaryTree<T>::privateInsert()
{
    std::cout<<"Enter node data: ";
    T nodeData;
    std::cin>> nodeData;
    if(nodeData == -1)
        return nullptr;
    Node<T>* node = newNode(nodeData);
    node->left = privateInsert();
    node->right = privateInsert();
    return node;
}
template<typename T>
void BinaryTree<T>::iterativeInsert()
{
    std::cout<<"Enter the root node: ";
    T rootData;
    std::cin>>rootData;
    std::queue<Node<T>*> queueInsert;
    root = newNode(rootData);
    queueInsert.push(root);
    while(!queueInsert.empty())
    {
        T leftData , rightData;
        Node<T>* temp = queueInsert.front();
        queueInsert.pop();
        std::cout<<"Enter the left Node for "<<temp->data<<" -1 to make it a leaf node: ";
        std::cin>>leftData;
        std::cout<<"Enter the right Node for "<<temp->data<<" -1 to make it a leaf node: ";
        std::cin>>rightData;
        Node<T>* leftNode = nullptr;
        Node<T>* rightNode = nullptr;
        if(leftData!=-1)
        {
            leftNode = newNode(leftData);
            queueInsert.push(leftNode);
        }
        if(rightData!=-1)
        {
            rightNode = newNode(rightData);
            queueInsert.push(rightNode);
        }
        temp->left = leftNode;
        temp->right = rightNode;
    }
}
template<typename T>
void BinaryTree<T>::print()const
{
    privatePrint(root);
}
template<typename T>
void BinaryTree<T>::privatePrint(Node<T>* node)const
{
    if(node == nullptr)
        return;
    std::cout<<node->data<<": ";
    if(node->left!=nullptr)
        std::cout<<"L "<<node->left->data<<"\t";
    if(node->right!=nullptr)
        std::cout<<"R "<<node->right->data<<"\t";
    std::cout<<"\n";
    privatePrint(node->left);
    privatePrint(node->right);
}
template<typename T>
BinaryTree<T>::~BinaryTree()
{
    delete root;
}
