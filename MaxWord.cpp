#include <iostream>

using namespace std;

struct node {
    char chr;
    node *next;
};

struct linked_list{
    node first;
};

bool is_letter(char a) {
    return (a >= 'A' && a <= 'z');
}

void add_next_node(node *curr_node) {
    node *next_node = new node;
    next_node->next = curr_node->next;
    curr_node->next = next_node;
}

linked_list input_list() {
    char in_chr;
    linked_list text;
    text.first.next = NULL;
    node *pcurr_chr = &text.first;
    do {
        cin.get(in_chr);
        pcurr_chr->chr = in_chr;
        if (in_chr != '\n') {
            add_next_node(pcurr_chr);
            pcurr_chr = pcurr_chr->next;
        } else {
            break;
        }
    } while(true);
    return(text);
}

void show_list(linked_list *text) {
    node *pcurr_node = &text->first;
    while(pcurr_node->next != NULL) {
        cout << pcurr_node->chr;
        pcurr_node = pcurr_node->next;
    }
}

int find_max_word(linked_list *text, linked_list *maxword){
    int lmax = 0;
    int l = 0;
    maxword->first.next = NULL;
    linked_list word;
    word.first.next = NULL;
    node *pcurr_node = &text->first;
    node *pcurr_letter = &word.first;
    while(pcurr_node->next != NULL) {
        if(pcurr_node->chr != ' ') {
            if (is_letter(pcurr_node->chr)) {
                l++;
                pcurr_letter->chr = pcurr_node->chr;
                add_next_node(pcurr_letter);
                pcurr_letter = pcurr_letter->next;
            }
        } else {
            if(l > lmax) {
                lmax = l;
                maxword->first = word.first;
            }
            l = 0;
            word.first.next = NULL;
            pcurr_letter = &word.first;
        }
        pcurr_node = pcurr_node->next;
    }
    if(l > lmax) {
        lmax = l;
        *maxword = word;
    }
    l = 0;
    return(lmax);
}

int main() {
    cout << "Эта программа ищет слово с максимальной длиной.\n\nВведите слова:\n";
    linked_list text = input_list();
    linked_list maxword;
    int lmax;
    lmax = find_max_word(&text, &maxword);
    cout << "\nСлово с максимальной длиной: ";
    show_list(&maxword);
    cout << "\nЕго длина: " << lmax ;
    return 0;
}