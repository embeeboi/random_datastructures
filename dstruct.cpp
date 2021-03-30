#include <iostream>






class datastruct
{

    public:
        datastruct() : linkroot(nullptr) , bstroot(nullptr) {}
        void link(int data);
        void binarysearch(int data);
        
    private:
        struct linklist
        {
            int data;
            linklist* next;
            linklist* prev;
            linklist(int a) : data(a) , next(nullptr) , prev(nullptr) {}
        };
        struct bst
        {
            int data;
            bst* right;
            bst* left;
            bst(int a) : data(a) , right(nullptr) , left(nullptr) {}
        };
        linklist* linkroot;
        bst* bstroot;
        linklist* linksert(int dataput,linklist* node);
        bst* bsert(int dataput,bst* node);
};


datastruct::linklist* datastruct::linksert(int dataput, linklist*node)
{
    if(node == nullptr)
    {
        node = new linklist(dataput);
        return node;
    }
    node->next = linksert(dataput,node->next);
    node->next->prev = node->next;
    return node;
}


datastruct::bst* datastruct::bsert(int dataput,bst* node)
{
    if(node==nullptr)
    {
        node = new bst(dataput);
        return node;
    }
    else if (node->data > dataput)
     {
        node->left = bsert(dataput,node->left);
        return node;
    }
    else if (node->data < dataput)
     {
        node->right = bsert(dataput,node->right);
        return node;
    }
    return node;
    
}



void datastruct::link(int data)
{
    linkroot = linksert(data,linkroot);
}
void datastruct::binarysearch(int data)
{
    bstroot = bsert(data,bstroot);
}
int main()
{
    datastruct* t = new datastruct;
    t->binarysearch(3);
    t->binarysearch(5);
    t->binarysearch(2);
    t->link(1);
    t->link(3);
}