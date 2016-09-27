#include <string>
#include <iostream>
using namespace std;

class student
{
public:
    student(){
        begin = new info[5];
    }
    student(int size){
        begin = new info[size];
    }




    int get_size(){
        return size;
    }

    ~student(){};
private:
    struct info
    {
        string Stu_number;
        string name;
        unsigned score;
    };
    info * begin;
    int size = 5;

};
int main(){
    student s;
    cout<<s.get_size();
    cout<<"hhh";
    cout<<"hello";
}
