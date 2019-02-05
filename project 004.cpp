#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class ProblemSet
{
    public:
    string problem, solution;
    ProblemSet(){}
    ProblemSet(string c, string d)
    {
        problem = c;
        solution = d;
    }
    void show()
    {
        cout<<problem<<endl;
        cout<<solution<<endl;
    }
};

class Person
{
public:
    string name, dob;
    void getdata(string c, string d)
    {
        name = c;
        dob = d;
    }
    void putdata()
    {
        cout<<name<<endl;
        cout<<dob<<endl;
    }
};

class Student : public Person
{
public:
    string ID;
    int solved = 0;
    ProblemSet prblmst;
    bool finalist = 0;
    void setInfo(string c,string d, string l, int k, bool j )
    {
        getdata(c,d);
        ID = l;
        solved = k;
        finalist = j;
    }
    void putInfo()
    {
        putdata();
        cout<<ID<<endl;
        cout<<"solved: "<<solved<<endl;
        prblmst.show();
    }
    int getsolved()
    {
        return solved;
    }
    void setProblem(ProblemSet s)
    {
        prblmst = s;
    }
    bool ifFinal()
    {
        return finalist;
    }
    bool operator<(Student B)
    {
        return solved<B.solved;
    }
};

int main()
{
    Student st[5];
    st[0].setInfo("Joynal","22-6-1995", "1308013", 150, false);
    st[1].setInfo("Faruk","17-12-1995", "1308010", 550, false);
    st[2].setInfo("Younus","10-2-1994", "1308004", 1500, true);
    st[3].setInfo("Fatema","2-8-1996", "1308018", 200, false);
    st[4].setInfo("Kamrul","1-1-1994", "1308025", 250, false);
    st[0].setProblem(ProblemSet("Problem", "solution")) ;
    st[0].setProblem(ProblemSet("Problem2", "solution2")) ;
    st[0].setProblem(ProblemSet("Problem3", "solution3")) ;
    st[1].setProblem(ProblemSet("Problem4", "solution4")) ;
    st[1].setProblem(ProblemSet("Problem6", "solution6")) ;
    st[2].setProblem(ProblemSet("Problem7", "solution7")) ;
    st[2].setProblem(ProblemSet("Problem8", "solution8")) ;
    st[3].setProblem(ProblemSet("Problem9", "solution9")) ;
    st[4].setProblem(ProblemSet("Problem10", "solution10")) ;
    st[4].setProblem(ProblemSet("Problem11", "solution11")) ;
    int prbno[5] = {0}, n=0;
    Student ob[2];
    sort(st, st + 5);
    ///Select world finalist
    for(int i = 0; i < 5 && n < 2; i++)
    {
        if(st[i].ifFinal()==true)
        {
            ob[n++] = st[i];
        }
    }
    ///Select non-finalist
    for(int i = 0; i < 5 && n < 2; i++)
    {
        if(st[i].ifFinal()==false)
        {
            ob[n++] = st[i];
        }
    }
    ob[0].putInfo();
    ob[1].putInfo();
    return 0;
}