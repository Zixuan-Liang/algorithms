#include <iostream>
#include <vector>

enum Color {red, black};

struct Node {
    int key;
    Node *parent;
    Node *left;
    Node *right;
    Color color;
};

class RBTree{
private:
    Node *root;
    Node *TNIL;

    void LeftRotate(Node *node){
        Node *y = node->right;
        node->right = y->left;
        if (y->left != TNIL){
            y->left->parent = node;
        }
        y->parent = node->parent;
        if (node->parent == TNIL){
            root = y;
        } else if(node == node->parent->left){
            node->parent->left = y;
        } else{
            node->parent->right = y;
        }
        y->left = node;
        node->parent = y;
    }

    void RightRotate(Node *node){
        Node *y = node->left;
        node->left = y->right;
        if (y->right != TNIL){
            y->right->parent = node;
        }
        y->parent = node->parent;
        if (node->parent == TNIL){
            root = y;
        } else if (node == node->parent->left){
            node->parent->left = y;
        } else{
            node->parent->right = y;
        }
        y->right = node;
        node->parent = y;
    }

    void InsertFixup(Node *node){
        Node *uncle;
        while (node->parent->color == red){
            if (node->parent == node->parent->parent->left){
                uncle = node->parent->parent->right;
                if (uncle->color == red){
                    node->parent->color = black;
                    uncle->color = black;
                    node->parent->parent->color = red;
                    node = node->parent->parent;
                } else{
                    if (node == node->parent->right){
                        node = node->parent;
                        LeftRotate(node);
                    }
                    node->parent->color = black;
                    node->parent->parent->color = red;
                    RightRotate(node->parent->parent);
                }
            } else{
                uncle = node->parent->parent->left;
                if (uncle->color == red){
                    node->parent->color = black;
                    uncle->color = black;
                    node->parent->parent->color = red;
                    node = node->parent->parent;
                } else{
                    if (node == node->parent->left){
                        node = node->parent;
                        RightRotate(node);
                    }
                    node->parent->color = black;
                    node->parent->parent->color = red;
                    LeftRotate(node->parent->parent);
                }
            }
        }
        root->color = black;
    }

    void RBTransplant(Node *u, Node *v){
        if (u->parent == TNIL){
            root = v;
        } else if (u == u->parent->left){
            u->parent->left = v;
        } else{
            u->parent->right = v;
        }
        v->parent = u->parent;
    }

    void DeleteFixup(Node *node){
        Node *w;
        while (node != root && node->color == black){
            if (node == node->parent->left){
                w = node->parent->right;
                if (w->color == red){
                    w->color = black;
                    node->parent->color = red;
                    LeftRotate(node->parent);
                    w = node->parent->right;
                }
                if (w->left->color == black && w->right->color == black){
                    w->color = red;
                    node = node->parent;
                } else{
                    if (w->right->color == black){
                        w->left->color = black;
                        w->color = red;
                        RightRotate(w);
                        w = node->parent->right;
                    }
                    w->color = node->parent->color;
                    node->parent->color = black;
                    w->right->color = black;
                    LeftRotate(node->parent);
                    node = root;
                }
            } else{
                w = node->parent->left;
                if (w->color == red){
                    w->color = black;
                    node->parent->color = red;
                    RightRotate(node->parent);
                    w = node->parent->left;
                }
                if (w->left->color == black && w->right->color == black){
                    w->color = red;
                    node = node->parent;
                } else{
                    if (w->left->color == black){
                        w->right->color = black;
                        w->color = red;
                        LeftRotate(w);
                        w = node->parent->left;
                    }
                    w->color = node->parent->color;
                    node->parent->color = black;
                    w->left->color = black;
                    RightRotate(node->parent);
                    node = root;
                }
            }
        }
        node->color = black;
    }

    void TreePrintRecursive(Node *node, std::string indent, bool last){
        if (node != TNIL){
            std::cout << indent;
            if (last){
                std::cout << "R----";
                indent += "     ";
            } else{
                std::cout << "L----";
                indent += "|    ";
            }
            std::string sColor = node->color==red?"RED":"BLACK";
            std::cout<<node->key<<"("<<sColor<<")"<<std::endl;
            TreePrintRecursive(node->left, indent, false);
            TreePrintRecursive(node->right, indent, true);
        }
    }

public:
    RBTree(){
        TNIL = new Node;
        TNIL->key = 0;
        TNIL->parent = nullptr;
        TNIL->left = nullptr;
        TNIL->right = nullptr;
        TNIL->color = black;
        root = TNIL;
    }

    Node *GetRoot(){
        return root;
    }

    void TreePrint(){
        TreePrintRecursive(root, "", true);
    }

    void InorderTreeWalk(Node *node){
        if (node != TNIL){
            InorderTreeWalk(node->left);
            std::cout << node->key << " ";
            InorderTreeWalk(node->right);
        }
    }

    void PreorderTreeWalk(Node *node){
        if (node != TNIL){
            std::cout << node->key << " ";
            PreorderTreeWalk(node->left);
            PreorderTreeWalk(node->right);
        }
    }

    void PostorderTreeWalk(Node *node){
        if (node != TNIL){
            PostorderTreeWalk(node->left);
            PostorderTreeWalk(node->right);
            std::cout << node->key << " ";
        }
    }

    Node *TreeSearch(Node *node, int k){
        if (node == TNIL || k == node->key){
            return node;
        }
        if (k < node->key){
            return TreeSearch(node->left, k);
        } else{
            return TreeSearch(node->right, k);
        }
    }

    Node *IterativeTreeSearch(Node *node, int k){
        while (node != TNIL && k != node->key){
            if (k < node->key){
                node = node->left;
            } else{
                node = node->right;
            }
        }
        return node;
    }

    Node *Minimum(Node *node){
        while (node->left != TNIL){
            node = node->left;
        }
        return node;
    }

    Node *Maximum(Node *node){
        while (node->right != TNIL){
            node = node->right;
        }
        return node;
    }

    Node *Successor(Node *node){
        if (node->right != TNIL){
            return Minimum(node->right);
        } else{
            Node *ancestor = node->parent;
            while (ancestor != TNIL && node == ancestor->right){
                node = ancestor;
                ancestor = ancestor->parent;
            }
            return ancestor;
        }
    }

    Node *Predecessor(Node *node){
        if (node->left != TNIL){
            return Minimum(node->left);
        } else{
            Node *ancestor = node->parent;
            while (ancestor != TNIL && node == ancestor->left){
                node = ancestor;
                ancestor = ancestor->parent;
            }
            return ancestor;
        }
    }

    void InsertNode(Node *node){
        Node *y = TNIL;
        Node *x = root;
        while (x != TNIL){
            y = x;
            if (node->key < x->key){
                x = x->left;
            } else{
                x = x->right;
            }
        }
        node->parent = y;
        if (y == TNIL){
            root = node;
        } else if (node->key < y->key){
            y->left = node;
        } else{
            y->right = node;
        }
        node->left = TNIL;
        node->right = TNIL;
        node->color = red;
        InsertFixup(node);
    }

    void DeleteNode(Node *node){
        Node *x, *y;
        y = node;
        Color y_original_color = y->color;
        if (node->left == TNIL){
            x = node->right;
            RBTransplant(node, node->right);
        } else if (node->right == TNIL){
            x = node->left;
            RBTransplant(node, node->left);
        } else{
            y = Minimum(node->right);
            y_original_color = y->color;
            x = y->right;
            if (y->parent == node){
                x->parent = y;
            } else{
                RBTransplant(y, y->right);
                y->right = node->right;
                y->right->parent = y;
            }
            RBTransplant(node, y);
            y->left = node->left;
            y->left->parent = y;
            y->color = node->color;
        }
        delete node;
        if (y_original_color == black){
            DeleteFixup(x);
        }
    }

    void Insert(int k){
        InsertNode(new Node{k});
    }

    void Delete(int k){
        DeleteNode(TreeSearch(root, k));
    }
};

int main() {
    RBTree brt;
    std::vector<int> example = {7, 3, 18, 10, 22, 8, 11, 26};
    for (auto & item: example) {
        brt.Insert(item);
    }
    std::cout << "Before inserting 15: " << std::endl;
    brt.TreePrint();
    brt.Insert(15);
    std::cout << "After inserting 15: " << std::endl;
    brt.TreePrint();
    return 0;
}
