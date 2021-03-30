#include <iostream>

using namespace std;


namespace binarysearchtree
{
    struct BST
    {
        int x;
        BST* left;
        BST* right;
        BST(int a=0) : x(a) , left(nullptr), right(nullptr) {}
    };

    BST* insertnode(int a,BST* node)
    {
        if(node==nullptr)
        {
            node = new BST(a);
            return node;
        }
        else if(node->x > a)
        {
            node->left = insertnode(a,node->left);
            return node;
        }
        else if(node->x < a)
        {
            node->left = insertnode(a,node->left);
            return node;
        }
        return node;
    }
};



namespace linkedlists
{
    struct link
    {
        int x;
        link* next;
        link(int a) : x(a) , next(nullptr) {}
    };
    link* insertnode(int a,link* node)
    {
        if(node == nullptr)
        {
            node = new link(a);
            return node;
        }
        node->next = insertnode(a,node->next);
        return node;
    }
};


struct linklist_binarysearch
{
    binarysearchtree::BST* root;
    linkedlists::link* head;
  
    linklist_binarysearch() : head(nullptr) , root(nullptr) {}
    
    void insert(int a)
    {
       root = binarysearchtree::insertnode(a, root);
       head = linkedlists::insertnode(a,head);
    }

};



struct create_arr
{
    
    linklist_binarysearch* arr[4];
    linklist_binarysearch* updatearr[8];

    create_arr()
    {
        for(int i=0;i<4;i++)
        {
            arr[i] = new linklist_binarysearch;
        }
    }

    create_arr(create_arr* n1, create_arr* n2)
    {
        updatearr[0] = n1->arr[0];
        updatearr[1] = n2->arr[0];
        updatearr[2] = n1->arr[1];
        updatearr[3] = n2->arr[1];
        updatearr[4] = n1->arr[2];
        updatearr[5] = n2->arr[2];
        updatearr[6] = n1->arr[3];
        updatearr[7] = n2->arr[3];
    }



};


int main()
{
  
    create_arr* t1 = new create_arr;
    create_arr* t2 = new create_arr;
    std::swap(t1,t2);
    create_arr* t3 = new create_arr(t1,t2);
    t1 = nullptr;
    t2 = nullptr;
    t3->updatearr[0]->insert(2);
}