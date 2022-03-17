#include<iostream>
#include<stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void check(char& d, char& c) {
    if (d > '9') {
        d -= 10;
        c = 1;
    } else {
        c = 0;
    }
}
int main(int argc, char *argv[]) {
    ofstream fout("user.out");
    
    char c;
    
    vector<char> num;
    while (scanf(" %c", &c) && c == '[') {
        int length1 = 0;
        char val, c2;
        num.clear();
        
        do {
            val = getchar();
            c2 = getchar();
            ++length1;
            num.push_back(val);
        } while (c2 == ',');
        scanf(" %c", &c);
        c = 0;
        
        int length2 = 0;
        do {
            val = getchar();
            c2 = getchar();
            char d;
            if (length2 < length1) {
                d = num[length2] + val - '0' + c;
                check(d, c);
            } else {
                d = val + c;
                check(d, c);
            }
            fout << (length2 ? ',' : '[') << d;
            ++length2;
        } while (c2 == ',');
        while (length2 < length1) {
            char d = num[length2] + c;
            if (c) check(d, c);
            fout << ',' << d;
            ++length2;
        }
        if (c != 0) {
            fout << ",1";
        }
        fout << "]\n";
    }
}
#define main deleted_main
struct Solution {
    template<typename... Args>
    ListNode* addTwoNumbers(Args... args) {
        return {};
    }
};
