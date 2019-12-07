#include<iostream>
#include<string>
using namespace std;

//template<class T>

class People
{
public:
    string name,year,sex,address,tel;
    People(string Name,string Year,string Sex,string Address,string Tel);
    ~People();
};
People::People(string Name,string Year,string Sex,string Address,string Tel)
{
    this->name=Name;
    this->year=Year;
    this->sex=Sex;
    this->address=Address;
    this->tel=Tel;
}
People::~People()
{

}
class Teacher:virtual public People
{
private:
public:
    string title;
    Teacher(string Name,string Year,string Sex,string Address,string Tel,string Title);
    ~Teacher();
};

Teacher::Teacher(string Name,string Year,string Sex,string Address,string Tel,string Title):People(Name,Year,Sex,Address,Tel),title(Title)
{
}

Teacher::~Teacher()
{
}

class Cadre:virtual public People
{
private:
public:
    string post;
    Cadre(string Name,string Year,string Sex,string Address,string Tel,string Post);
    ~Cadre();
};

Cadre::Cadre(string Name,string Year,string Sex,string Address,string Tel,string Post):People(Name,Year,Sex,Address,Tel),post(Post)
{
}

Cadre::~Cadre()
{
}

class Teacher_Cadre: public Teacher,virtual public Cadre 
{
private:
public:
    string wages;
    friend ostream & operator <<(ostream & , Teacher_Cadre &);
    Teacher_Cadre(string Name,string Year,string Sex,string Address,string Tel,string Title,string Post,string Wages);
    ~Teacher_Cadre();
};

Teacher_Cadre::Teacher_Cadre(string Name,string Year,string Sex,string Address,string Tel,string Title,string Post,string Wages):People(Name,Year,Sex,Address,Tel),Teacher(Name,Year,Sex,Address,Tel,Title),Cadre(Name,Year,Sex,Address,Tel,Post),wages(Wages)
{
}

Teacher_Cadre::~Teacher_Cadre ()
{
}

ostream & operator <<(ostream & os,const Teacher_Cadre & c)
{
    os << c.name << " " << c.year << " "<<c.sex<<" "<<c.title<<" "<<c.address<<" "<<c.tel<<" "<<c.post<<" "<<c.wages<<endl; 
    return os;
}

int main()
{
 
 Teacher_Cadre person("jason","27","B","Nanjing","12345213","porfessor","monitor","20000");
// cout<<person;
 system("pause");
}
