#include <string>
#include <iostream>
#include<stdio.h>
using namespace std;
struct info {
    info() {}
    info(string name_,string stu_number_,int score_):name(name_),Stu_number(stu_number_),score(score_) {}
    string Stu_number="";
    string name="";
    int score=0;
};
class student
{
private:

    info * begin;
    int size = 5;
    int capacity = 5;
    int stu_num = 0;
public:
//big5
    student() {
        begin = new info[5];
    }
    student(int size) {
        begin = new info[size];
        size = size;
        capacity = size;
    }

    student(const student& stu) {
        begin = new info[stu.get_size()];
        copy(stu);
        size = stu.get_size();
        stu_num = stu.stu_num;
        capacity = stu.capacity;
    }

    void add(int num) {
        check(num);
        for(int i = 0; i!= num; ++i) {
            info buf;
            cout<<"please enter information(\"student_number   name    score\") :"<<endl;
//            try {
            cin>>buf.Stu_number>>buf.name>>buf.score;

//            } catch (...) {
//                cout<<"error recording"<<endl;
//                cout<<"quit....";
//                throw("wrong");
//            }
            if(cin.fail()) {
                cout<<"bad input"<<endl;
                return;
            }
            begin[stu_num] = buf;
            ++ stu_num;
            -- capacity;
        }
    }
    void insert(int pos,const info& scr) {

        if(capacity<1) {
            check(2);
        }
        if(pos > stu_num) {
            cerr<<"insert index out of range"<<endl;
            return;
        }
        for(int i = stu_num; i!=pos; --i) {
            begin[i] = begin[i-1];
        }
        begin[pos]=scr;
        ++stu_num;
        --capacity;
    }
//    void insert(int pos,info&& scr) {
//
//        if(capacity<1) {
//            check(2);
//        }
//        if(pos > stu_num) {
//            cout<<"insert index out of range";
//            return;
//        }
//        for(int i = stu_num; i!=pos; --i) {
//            begin[i] = begin[i-1];
//        }
//        begin[pos]=std::move(scr);
//        ++stu_num;
//        --capacity;
//    }

    info& operator[](int i) {
        return begin[i];
    }

    const info& operator[](int i)const {
        return begin[i];
    }

    int get_size() const {
        return stu_num;
    }

    void copy(const student& stu,info* dest= nullptr) {
        info *buf = nullptr;

        if(dest) {
            buf = dest;
        } else {
            buf = begin;
        }

        for(int i = 0; i!= stu.get_size(); ++i) {
            buf[i] = stu.begin[i];
        }

    }

    void check(int dest_size) {

        if(dest_size > capacity) {
            auto buf_begin = new info[size+2*dest_size];
            copy(*this,buf_begin);
            delete[] begin;
            size += 2*dest_size;
            capacity += 2*dest_size;
            begin = buf_begin;
        }

    }

    void print()const {
        printf("          name       student number  score\n");
        for(int i = 0; i != stu_num; ++i) {
//            cout<<begin[i].name<<"  "<<begin[i].Stu_number<<"   "<<begin[i].score<<endl;
            printf("item[%3d] %-10s %-15s %-3d\n",i+1,begin[i].name.data(),begin[i].Stu_number.data(),begin[i].score);
        }
    }

    void print_info()const {
        printf("item number:%-5d array size: %-5dcapacity: %-5d\n",stu_num,size,capacity);
    }
    ~student() {
        delete[] begin;
    }

};
int main()
{
    student s;


    s.add(3);
    s.insert(4, info("33","33",33));
    s.print();
    s.print_info();
//    cout<<s[0].score;
}
