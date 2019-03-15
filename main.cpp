#include <iostream>

using namespace std;

class nod
{
    char c;
    nod * precedent;
public:
    char get_c()
    {
        return c;
    }
    friend class stiva;
};

class stiva
{
public:
    nod *vf=NULL;
    void push(char ch)
    {
        nod *p;
        p=new nod;
        p->precedent=vf;
        p->c=ch;
        vf=p;
    }
    void pop()
    {
        nod *p;
        p=vf;
        vf=vf->precedent;
        delete p;
    }
    void top()
    {
        cout<<vf->c;
    }

    stiva operator-(stiva s1);
};

stiva stiva:: operator-(stiva s1)
{
    while(vf!=NULL && s1.vf!=NULL && vf->c==s1.vf->c)
    {
        pop();
        s1.pop();
    }

}

istream &operator>>(istream  &input,stiva &s1)
{
    cout << "numarul de caractere: ";
    int nr,i;
    char ch;
    input >> nr;
    if(nr==0)
        cout<<"nu avem caractere de introdus\n";
    else
    {
    cout << "Introduceti caracterele: ";
    for (i = 0; i < nr; i++)
    {
        input >>ch;
        s1.push(ch);
    }
    }
    return input;
}

ostream &operator<<(ostream &output,stiva &s1)
{
    char chr;
    if(s1.vf==NULL)
        cout<<"stiva este goala";
    while(s1.vf!=NULL)
    {
        chr=s1.vf->get_c();
        output<<chr;
        s1.pop();
        output<<" ";
    }
    return output;
}

int main()
{
    stiva s1,s2;
    cout<<"sirul de caractere\n";
    cin>>s1;
    cout<<"sirul de caractere inversat:";
    cout<<s1;
    cout<<"\n\ncitim prima stiva\n";
    cin>>s1;
    cout<<"\ncitim a doua stiva\n";
    cin>>s2;
    s1-s2;
    cout<<'\n';
    cout<<s1;
    return 0;
}
