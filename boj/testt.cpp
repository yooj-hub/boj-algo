#include <bits/stdc++.h>

using namespace std;

struct Student {
    int id;
    int esw;

    Student(int id, int esw) {
        this->id = id;
        this->esw = esw;
    }

    void print_info(){
        printf("id : [%d], esw : [%d]\n", id, esw);
    }
};

int main() {
    Student esw = Student(10, 100);
    esw.print_info();
}