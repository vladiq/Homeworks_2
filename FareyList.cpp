#include <iostream>

using namespace std;

struct node {
    int a;
    int b;
    node* next;
};

struct linked_list {
    node first;
};

void add_next_node(int x, int y, node *pcurr_node) {
    node *pnext_node = new node;
    pnext_node->a = x;
    pnext_node->b = y;
    pnext_node->next = pcurr_node->next;
    pcurr_node->next = pnext_node;
}

void show_Farey(linked_list *pFarey){
    node *pcurr_node = &pFarey->first;
    while (pcurr_node->next != NULL) {
        cout << pcurr_node->a << "/" << pcurr_node->b <<", ";
        pcurr_node = pcurr_node->next;
    }
    cout << pcurr_node->a << "/" << pcurr_node->b;
}

linked_list get_Farey(int needed_order) {
    linked_list Farey;
    Farey.first.next = NULL;
    Farey.first.a = 0;
    Farey.first.b = 1;
    add_next_node(1, 1, &Farey.first); //сделал ряд Фарея 1-ого порядка
    int curr_order = 1;
    while(curr_order <= needed_order) {
        node *pcurr_node = &Farey.first;
        while(pcurr_node->next != NULL) {
            if(pcurr_node->b + pcurr_node->next->b <= curr_order) {
                add_next_node(pcurr_node->a + pcurr_node->next->a, pcurr_node->b + pcurr_node->next->b, pcurr_node);
            }
            pcurr_node = pcurr_node->next;
        }
        curr_order++;
    }
    return(Farey);
}

int main() {
    int order;
    cout << "\nЭта программа выводит ряд Фарея n-ого порядка.\n\nВведите n: ";
    cin >> order;
    while(cin.fail()) {
        cout << "Вы ввели неправильно. Введите n: ";
        cin.clear();
        cin.ignore(10000,'\n');
        cin >> order;
    }
    linked_list Farey;
    Farey = get_Farey(order);
    cout << "\n";
    show_Farey(&Farey);
    cout << "\n";
    return 0;
}

