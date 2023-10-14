#include <iostream>
#include <random>
#include <cassert>
#include <cstdlib>
#include <string>
std::random_device seed;
std::minstd_rand rng(seed());
const int N = 110, MAX_LEVEL = 32;
template <typename T> class skiplist {
private:
    int level; struct Node {
        T key; int level;
        struct nodePointer {
            int span; Node *pointer;
            nodePointer() { this->pointer = nullptr; }
            nodePointer(Node *node) { this->pointer = node; }
            Node *operator->() { return pointer; }
            operator Node *() const { return pointer; }
        };
        nodePointer nxt[MAX_LEVEL];
    } space[N]; int bintop;
    using nodePointer = typename Node::nodePointer;
    Node *head, *tail, *tot, *rubbin[N / 4 * 3];
    #define new_node() (bintop ? rubbin[bintop--] : ++tot)
    #define del_node(x) (rubbin[++bintop] = (x))
    Node *create_node(const int &level, const T &key) { Node *res = new_node(); res->level = level; res->key = key; return res; }
    int random_level() { int res = 1; while (res < MAX_LEVEL && (rng() & 1)) ++res; return res; }
    Node *update[MAX_LEVEL]; int lst_pos[MAX_LEVEL + 1];
public:
    skiplist() {
        tail = nullptr; level = 0; head = tot = space; bintop = 0; length = 0; lst_pos[MAX_LEVEL] = 0;
        for (int i = 0; i < MAX_LEVEL; ++i) head->nxt[i] = nullptr, head->nxt[i].span = 0;
    } void insert(const T &key) {
        Node *cur = head;
        for (int lev = level - 1; lev > -1; --lev) {
            lst_pos[lev] = lst_pos[lev + 1];
            while (cur->nxt[lev] && cur->nxt[lev]->key < key) { lst_pos[lev] += cur->nxt[lev].span; cur = cur->nxt[lev]; }
            update[lev] = cur;
        } int lev = random_level();
        if (lev > level) {
            for (int i = level; i < lev; ++i) { update[i] = head; update[i]->nxt[i].span = length; }
            level = lev;
        } cur = create_node(lev, key);
        for (int i = 0; i < lev; ++i) {
            cur->nxt[i] = update[i]->nxt[i]; update[i]->nxt[i].pointer = cur;
            cur->nxt[i].span = update[i]->nxt[i].span - (lst_pos[0] - lst_pos[i]);
            update[i]->nxt[i].span = lst_pos[0] - lst_pos[i] + 1;
        } for (int i = lev; i < level; ++i) ++update[i]->nxt[i].span;
        ++length;
    } void erase(const T &key) {
        Node *cur = head;
        for (int lev = level - 1; lev != -1; --lev) {
            while (cur->nxt[lev] && cur->nxt[lev]->key < key) cur = cur->nxt[lev];
            update[lev] = cur;
        } cur = cur->nxt[0];
        for (int i = 0; i < level; ++i) {
            if (update[i]->nxt[i] == cur) update[i]->nxt[i].pointer = cur->nxt[i].pointer, update[i]->nxt[i].span += cur->nxt[i].span - 1;
            else --update[i]->nxt[i].span;
        } while (level > 1 && !head->nxt[level - 1]) --level;
        del_node(cur); --length;
    } bool find(const T &key) {
        Node *cur = head;
        for (int lev = level - 1; lev > -1; --lev) while (cur->nxt[lev] && cur->nxt[lev]->key < key) cur = cur->nxt[lev];
        return cur->nxt[0] ? cur->nxt[0]->key == key : false;
    } T findrk(int k) {
        assert(k <= length && k);
        Node *cur = head;
        for (int lev = level - 1; lev > -1; --lev) {
            while (cur->nxt[lev] && k - cur->nxt[lev].span > 0) { k -= cur->nxt[lev].span; cur = cur->nxt[lev]; }
        } return cur->nxt[0]->key;
    }
    int length;
}; skiplist<int> list;
int main() {
    int n, tx; std::cin >> n;
    for (int i = 1; i <= n; ++i) { std::cin >> tx; list.insert(tx); }
    std::string s; while (std::cin >> s) { switch (s[0]) {
        case ('l'): std::cout << list.length << std::endl; break;
        case ('i'): case ('a'): std::cin >> tx; list.insert(tx); break;
        case ('d'): case ('r'): { std::cin >> tx; if (list.find(tx)) list.erase(tx); else std::cout << "该值不存在" << std::endl; break; }
        case ('f'): std::cin >> tx; std::cout << (list.find(tx) ? "存在" : "不存在") << std::endl; break;
        case ('g'): std::cin >> tx; std::cout << list.findrk(tx) << std::endl; break;
        default: std::cout << "未知命令" << std::endl;
    }} return 0;
}
