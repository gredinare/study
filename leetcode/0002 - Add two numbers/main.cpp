#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// ------------- DEBUG -------------

void print_list(ListNode* list) {
    ListNode* temp = list;

    while (temp != nullptr) {
        cout << temp->val << endl;
        temp = temp->next;
    }
}

ListNode* create_list(int* number, int len) {
    ListNode* number_list = nullptr;

    for (int i = 0; i < len; i++) {
        number_list = new ListNode(number[i], number_list);
    }
    
    return number_list;
}

// ------------- SOLUTION -------------

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum_list = new ListNode();
        ListNode* current = sum_list;

        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }

        return sum_list->next;
    }
};

void example() {
    int number_l1[3] = { 3, 4, 2 }; // 342
    int number_l2[3] = { 4, 6, 5 }; // 465

    ListNode* l1 = create_list(number_l1, 3);
    ListNode* l2 = create_list(number_l2, 3);

    Solution* sol = new Solution();
    ListNode* result = sol->addTwoNumbers(l1, l2);


    cout << endl;
    print_list(l1);

    cout << endl;
    print_list(l2);

    cout << endl;
    print_list(result);
}

int main(int argc, char const *argv[]) {
    example();
    return 0;
}