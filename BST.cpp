#include <iostream>
#include<cstdlib>

#include "BST.h"

using namespace std;


BST::BST()
{
    root = NULL;
}

BST::node* BST::CreateLeaf(int key)
{
    node* n = new node();
    n->key = key;
    n->right = NULL;
    n->left = NULL;

    return n;
}

void BST::AddLeaf(int key)
{
    AddLeafPrivate(key, root);
}

void BST::AddLeafPrivate(int key, node* Ptr)
{
    if (root == NULL)
    {
        root = CreateLeaf(key);
    }
    else if (key < Ptr->key)
    {
        if (Ptr->left != NULL)
        {
            AddLeafPrivate(key, Ptr->left);
        }
        else
        {
            Ptr->left = CreateLeaf(key);
        }
    }
    else if (key > Ptr->key)
    {
        if (Ptr->right != NULL)
        {
            AddLeafPrivate(key, Ptr->right);
        }
        else
        {
            Ptr->right = CreateLeaf(key);
        }
    }
    else
    {
        cout << "The key " << "key has already been added to the tree" << endl;
    }
}

void BST::PrintInOrder()
{
    PrintInOrderPrivate(root);
}

void BST::PrintInOrderPrivate(node* Ptr) {
    if (root != NULL)
    {
        if (Ptr->left != NULL)
        {
            PrintInOrderPrivate(Ptr->left);

        }
        cout << Ptr->key << " ";
        if (Ptr->right != NULL)
        {
            PrintInOrderPrivate(Ptr->right);
        }

    }
    else
    {
        cout << "The tree is empty" << endl;
    }
}

BST::node* BST::ReturnNode(int key)
{
    return ReturnNodePrivate(key, root);
}

BST::node* BST::ReturnNodePrivate(int key, node* Ptr)
{

    if (Ptr != NULL)
    {
        if (Ptr->key == key)
            return Ptr;

        else
        {
            if (key < Ptr->key)
            {
                return ReturnNodePrivate(key, Ptr->left);
            }
            else
            {
                return ReturnNodePrivate(key, Ptr->right);

            }



        }

    }
    else
    {
        return NULL;
    }

}

int  BST::ReturnRootKey()
{
    if (root != NULL)
        return root->key;
    else
        return -1;
}

void BST::PrintChildren(int key)
{
    node* Ptr = ReturnNode(key);
    if (Ptr != NULL)
    {
        cout << "Parent Node = " << Ptr->key << endl;
        Ptr->left == NULL ? cout << "Left Child = NULL\n" : cout << "Left Child = " << Ptr->left->key << endl;
        Ptr->right == NULL ? cout << "Right Child = NULL\n" : cout << "Right Child = " << Ptr->right->key << endl;
    }
    else
    {
        cout << "Key " << key << " is not in the tree\n";
    }
}


int BST::FindSmallest()
{
    return FindSmallestPrivate(root);

}

int BST::FindSmallestPrivate(node* Ptr)
{

    if (root == NULL)
    {   cout << "The tree is empty\n";
        return -1;
    }
    else
    {   if (Ptr->left != NULL) {
            return FindSmallestPrivate(Ptr -> left);
        }
        else
        {
            return Ptr->key;
        }
    }

}




void BST::RemoveNode(int key)
{
    RemoveNodePrivate(root, key);
}

void BST::RemoveNodePrivate(node* parent, int key)
{
    if (parent != NULL)
    {
        if (parent->key == key)
        {
            RemoveRootMatch();
        }
        else
        {

            if (key < parent->key && parent->left != NULL)
            {
                parent->left->key == key ? RemoveMatch(parent, parent->left, true) : RemoveNodePrivate(parent->left, key);
            }
            else if (key > parent->key && parent->right != NULL)
            {
                parent->right->key == key ? RemoveMatch(parent, parent->right, right) : RemoveNodePrivate(parent->right, key);
            }
            else {
                cout << "The key " << key << " was not found in the tree\n";
            }

        }
    }
    else
    {
        cout << "The tree is empty\n";
    }
}

void BST::RemoveRootMatch()
{
    if (root != NULL)
    {
        node* delPtr = root;
        int rootKey = root->key;
        int smallestInRightSubtree;

        //Case 1 - 0 children
        if (root->left == NULL && root-> right == NULL)
        {
            root = NULL;
            delete delPtr;
        }

        //Case 2 - 1 children
        else if (root->left == NULL && root ->right != NULL)
        {
            root = root ->right;
            delPtr -> right = NULL;
            delete delPtr;
            cout << "The root node with key " << rootKey << " was deketed." <<
                 "The new root contains key " << root->key << endl;
        }

        else if (root->right == NULL && root ->left != NULL)
        {
            root = root ->left;
            delPtr -> left = NULL;
            delete delPtr;
            cout << "The root node with key " << rootKey << " was deketed." <<
                 "The new root contains key " << root->key << endl;
        }
        else {
            smallestInRightSubtree = FindSmallestPrivate(root->right);

            RemoveNodePrivate(root, smallestInRightSubtree);
            root->key = smallestInRightSubtree;
            cout << "The root key containing key " << rootKey << " was overwritten with key " << root->key << endl;
        }

    }
    else
    {
        cout << "Can not remove root. The tree is empty.\n";

    }
}

void BST::RemoveMatch(node* parent, node* match, bool left)
{
    if (root != NULL)
    {
        node* delPtr;
        int matchKey = match->key;
        int smallestInRightSubtree;

        //case 0-0 children
        if (match->left == NULL && match->right == NULL)
        {
            delPtr = match;
            left == true ? parent->left = NULL : parent->right = NULL;
            delete delPtr;
            cout << "The node containing key " << matchKey << " was removed\n";
        }
        // Case 1 - 1 Child
        else if (match->left == NULL && match->right != NULL)
        {
            left == true ? parent->left = match->right : parent->right = match->right;
            match->right = NULL;
            delPtr = match;
            delete delPtr;
            cout << "The node containing key " << matchKey << " was removed\n";
        }
        else if (match->left != NULL && match -> right == NULL)
        {
            left == true ? parent->left = match -> left : parent->right = match->left;
            match->left = NULL;
            delPtr = match;
            delete delPtr;
            cout << "The node containing key " << matchKey << " was removed\n";
        }

        // Case 2-2 children
        else
        {
            smallestInRightSubtree = FindSmallestPrivate(match->right);
            RemoveNodePrivate(match, smallestInRightSubtree);
            match->key = smallestInRightSubtree;
        }

    }
    else
    {
        cout << "Cannot Remove match. The tree is empty\n";
    }
}