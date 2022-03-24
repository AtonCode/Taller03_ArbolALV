#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#define pow2(n) (1 << (n))
using namespace std;


struct NodoAVL {
   int d;
   struct NodoAVL *l;
   struct NodoAVL *r;
}*r;

class avl_tree {
   public:
      int height(NodoAVL *);
      int difference(NodoAVL *);
      NodoAVL *rr_rotat(NodoAVL *);
      NodoAVL *ll_rotat(NodoAVL *);
      NodoAVL *lr_rotat(NodoAVL*);
      NodoAVL *rl_rotat(NodoAVL *);
      NodoAVL * balance(NodoAVL *);
      NodoAVL * insert(NodoAVL*, int);
      void show(NodoAVL*, int);
      void inorder(NodoAVL *);
      void preorder(NodoAVL *);
      void postorder(NodoAVL*);
      avl_tree() {
         r = NULL;
      }
};
int avl_tree::height(NodoAVL *t) {
   int h = 0;
   if (t != NULL) {
      int l_height = height(t->l);
      int r_height = height(t->r);
      int max_height = max(l_height, r_height);
      h = max_height + 1;
   }
   return h;
}
int avl_tree::difference(NodoAVL *t) {
   int l_height = height(t->l);
   int r_height = height(t->r);
   int b_factor = l_height - r_height;
   return b_factor;
}
NodoAVL *avl_tree::rr_rotat(NodoAVL *parent) {
   avl *t;
   t = parent->r;
   parent->r = t->l;
   t->l = parent;
   cout<<"Right-Right Rotation";
   return t;
}
NodoAVL *avl_tree::ll_rotat(NodoAVL *parent) {
   avl *t;
   t = parent->l;
   parent->l = t->r;
   t->r = parent;
   cout<<"Left-Left Rotation";
   return t;
}
NodoAVL *avl_tree::lr_rotat(NodoAVL *parent) {
   avl *t;
   t = parent->l;
   parent->l = rr_rotat(t);
   cout<<"Left-Right Rotation";
   return ll_rotat(parent);
}
NodoAVL *avl_tree::rl_rotat(NodoAVL *parent) {
   avl *t;
   t = parent->r;
   parent->r = ll_rotat(t);
   cout<<"Right-Left Rotation";
   return rr_rotat(parent);
}
NodoAVL *avl_tree::balance(NodoAVL *t) {
   int bal_factor = difference(t);
   if (bal_factor > 1) {
      if (difference(t->l) > 0)
         t = ll_rotat(t);
      else
         t = lr_rotat(t);
   } else if (bal_factor < -1) {
      if (difference(t->r) > 0)
         t = rl_rotat(t);
      else
         t = rr_rotat(t);
   }
   return t;
}
NodoAVL *avl_tree::insert(NodoAVL *r, int v) {
   if (r == NULL) {
      r = new avl;
      r->d = v;
      r->l = NULL;
      r->r = NULL;
      return r;
   } else if (v< r->d) {
      r->l = insert(r->l, v);
      r = balance(r);
   } else if (v >= r->d) {
      r->r = insert(r->r, v);
      r = balance(r);
   } return r;
}
void avl_tree::show(NodoAVL *p, int l) {
   int i;
   if (p != NULL) {
      show(p->r, l+ 1);
      cout<<" ";
      if (p == r)
         cout << "Root -> ";
      for (i = 0; i < l&& p != r; i++)
         cout << " ";
         cout << p->d;
         show(p->l, l + 1);
   }
}
void avl_tree::inorder(NodoAVL *t) {
   if (t == NULL)
      return;
      inorder(t->l);
      cout << t->d << " ";
      inorder(t->r);
}
void avl_tree::preorder(NodoAVL *t) {
   if (t == NULL)
      return;
      cout << t->d << " ";
      preorder(t->l);
      preorder(t->r);
}
void avl_tree::postorder(NodoAVL *t) {
   if (t == NULL)
      return;
      postorder(t ->l);
      postorder(t ->r);
      cout << t->d << " ";
}
int main() {
   int c, i;
   avl_tree avl;
   while (1) {
      cout << endl;
      cout << "1.Insert Element into the tree" << endl;
      cout << "2.show Balanced AVL Tree" << endl;
      cout << "3.InOrder traversal" << endl;
      cout << "4.PreOrder traversal" << endl;
      cout << "5.PostOrder traversal" << endl;
      cout << "6.Exit" << endl;
      cout << "Enter your Choice: ";
      cin >> c;
      switch (c) {
         case 1:
            cout << "Enter value to be inserted: ";
            cin >> i;
            r = avl.insert(r, i);
         break;
         case 2:
            if (r == NULL) {
               cout << "Tree is Empty" << endl;
               continue;
            }
            cout << "Balanced AVL Tree:" << endl;
            avl.show(r, 1);
            cout<<endl;
         break;
         case 3:
            cout << "Inorder Traversal:" << endl;
            avl.inorder(r);
            cout << endl;
         break;
         case 4:
            cout << "Preorder Traversal:" << endl;
            avl.preorder(r);
            cout << endl;
         break;
         case 5:
            cout << "Postorder Traversal:" << endl;
            avl.postorder(r);
            cout << endl;
         break;
         case 6:
            exit(1);
         break;
         default:
            cout << "Wrong Choice" << endl;
      }
   }
   return 0;
}