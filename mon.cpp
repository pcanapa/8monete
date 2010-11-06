#include<iostream>
#include<string>
#define pesoReale 10

using namespace std;
struct moneta
{
    int peso;
    int numero;
    struct moneta *next;
};

moneta destra[3];
moneta sinistra[3];

struct moneta *head;
struct moneta *end;
struct moneta *p;


void loadTail()
{
    int i = 0;
    int num = 1, flag = 0;
    while(i < 8)
    {
        string scelta;
        p = new(moneta);

        if(flag == 0)
        {
            cout<<"moneta numero "<<i+1<<endl;
            cout<<"Inserire moneta falsa?(scrivi y)\n";
            cin>>scelta;
        }

        if(scelta == "y" || scelta == "Y" && flag != 1)
        {
            cin>>p->peso;
            flag = 1;
        }
        else
        {
            p->peso = pesoReale;
        }
        p->numero = num++;
        p->next = NULL;
        if(head == NULL && end == NULL)
        {
            head = end = p;
        }
        else
        {
            end->next = p;
            end = p;
        }
        i++;
    }
}

void checkFalseCoin()
{
    int i, totDestra = 0, totSinistra = 0;
    i = 0;
    while(i < 3)
    {
        p = head;
        head = p->next;
        destra[i].peso = p->peso;
        destra[i].numero = p->numero;
        destra[i].next = NULL;
        delete(p);
        i++;
    }
    i = 0;
    while(i < 3)
    {
        p = head;
        head = p->next;
        sinistra[i].peso = p->peso;
        sinistra[i].numero = p->numero;
        sinistra[i].next = NULL;
        delete(p);
        i++;
    }
    i = 0;
    while(i < 3)
    {
        totDestra += destra[i].peso;
        i++;
    }
    i = 0;
    while(i < 3)
    {
        totSinistra += sinistra[i].peso;
        i++;
    }
    if(totDestra == totSinistra)
    {
        if(head->peso == pesoReale)
        {
            cout<<"La moneta falsa è la numero "<<end->numero<<endl;
        }
        else
        {
            cout<<"La moneta falsa è la numero "<<head->numero<<endl;
        }
    }
    else if(totDestra != pesoReale * 3)
    {
        if(destra[0].peso == destra[1].peso)
        {
            cout<<"La moneta falsa è la numero "<<destra[2].numero<<endl;
        }
        else if(destra[1].peso == destra[2].peso)
        {
            cout<<"La moneta falsa è la numero "<<destra[0].numero<<endl;
        }
        else
        {
            cout<<"La moneta falsa è la numero "<<destra[1].numero<<endl;
        }
    }
     else if(totSinistra != pesoReale * 3)
    {
        if(sinistra[0].peso == sinistra[1].peso)
        {
            cout<<"La moneta falsa è la numero "<<sinistra[2].numero<<endl;
        }
        else if(sinistra[1].peso == sinistra[2].peso)
        {
            cout<<"La moneta falsa è la numero "<<sinistra[0].numero<<endl;
        }
        else
        {
            cout<<"La moneta falsa è la numero "<<sinistra[1].numero<<endl;
        }
    }

}
int main()
{
    head = NULL;
    end = NULL;
    loadTail();
    checkFalseCoin();
}
