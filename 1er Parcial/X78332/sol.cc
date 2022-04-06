#include <iostream>
#include "BinTree.hh"
#include "BinTreeIOint.hh"
#include <stack>
#include <vector>
using namespace std;

int fills(const BinTree<int>& tree, vector<int>& dist) {
	if (tree.empty()) return 0;

	int l = fills(tree.left(), dist);
	int r = fills(tree.right(), dist);
	dist.push_back(l + r + 1);
	return l + r + 1;
}

void i_cami_preferent(const BinTree<int> &a, stack<int> &c,
	const vector<int>& dist, int i) {

	if (a.empty()) return;

	int dist_right = -1;
	int dist_left = -1;

	int i_left = i-1;

	if (not a.right().empty()) i_left -= dist[i-1];
	if (not a.right().empty()) dist_right = dist[i-1];
	if (not a.left().empty()) dist_left = dist[i_left];

	if (dist_left >= dist_right) {
		i_cami_preferent(a.left(), c, dist, i_left);
	}
	else {
		i_cami_preferent(a.right(), c, dist, i-1);
	}
	c.push(a.value());
}

void cami_preferent(const BinTree<int> &a, stack<int> &c) {
	vector<int> dist;
	fills(a, dist);
    
    for (int i = 0; i< dist.size(); ++i) {
        cout << dist[i] << "  ";
    }
    cout << endl;

	i_cami_preferent(a, c, dist, dist.size()-1);
}
/*
void calcular_distancias(BinTree<pair<int,int>>& a_dist, const BinTree<int>& a) {
    if (not a.empty()) {
        BinTree<pair<int, int>> l;
        calcular_distancias(l, a.left());
        BinTree<pair<int, int>> r;
        calcular_distancias(r, a.right());
        if (a.left().empty() and a.right().empty()) {
            a_dist=BinTree<pair<int,int>>(make_pair(a.value(),1),l,r);
        }else if (a.left().empty()){
            a_dist=BinTree<pair<int,int>>(make_pair(a.value(),r.value().second+1),l,r);
        }else if (a.right().empty()){
            a_dist=BinTree<pair<int,int>>(make_pair(a.value(),l.value().second+1),l,r);
        }else {
            a_dist=BinTree<pair<int,int>>(make_pair(a.value(),r.value().second+l.value().second+1),l,r);
        }
    }
}

void recolectando_camino(const BinTree<pair<int,int>>& a_dist, stack<int>& c) {
    if (a_dist.empty()) return;
    else {
        c.push(a_dist.value().first);

        if (a_dist.right().empty()) {
            recolectando_camino(a_dist.left(), c);
        }else if (a_dist.left().empty()) {
            recolectando_camino(a_dist.right(), c);
        }else{
            if (a_dist.right().value().second > a_dist.left().value().second) {
                recolectando_camino(a_dist.right(), c);
            }else{
                recolectando_camino(a_dist.left(), c);
            }
        }
    }
}*/

/* Pre: c esta vacia */
/* Post: c contiene el camino preferente de a; si no esta vacia, el primer elemento del camino esta en la cima de c */
/*
void cami_preferent(const BinTree<int>& a, stack<int>& c) {
    BinTree<pair<int,int>> a_dist;

    calcular_distancias(a_dist, a);

    /*cout << a_dist.value().second << endl;
    cout << a_dist.left().value().second << "-----" << a_dist.right().value().second << endl;*/
/*
    recolectando_camino(a_dist, c);

    stack<int> temp;
    while (not c.empty()) {
        temp.push(c.top());
        c.pop();
    }
    c = temp;
    
}
*/

int main() {
    BinTree<int> a;

    read_bintree_int(a, 99);

    stack<int> c;

    cami_preferent(a, c);

    while (not c.empty()) {
        cout << c.top() << " ";
        c.pop();
    }
    cout << endl;
}


/*
7 6 -2 1 99 99 8 99 99 -3 99 -5 2 99 99 4 99 99 -2 -1 99 99 3 99 10 9 99 99 99

7 6 -1 2 -5 99 99 99 99 3 99 99 -2 8 99 9 99 99 -3 5 99 99 4 99 99
*/