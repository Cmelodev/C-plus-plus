#include <iostream>

using namespace std;

struct Node {
    int item;
    Node *next;
};

class List {
private:
    Node *head;
    Node *tail;
    int n;

    //Função usada para obter um nó da lista
    //pelo seu índice (0 .. n-1).
    Node* getNode (int pos){
        int i = 0;
        Node *t = this->head;
        while (i < pos){
            t = t->next;
            i++;
        }
        return t;
    }


public:
    //Construtor
    List(){
        this->head = NULL;
        this->tail = NULL;
        this->n = 0;
    }

    //Detrutor
    ~List(){
        this->clear();
    }

    //Inserir no início
    void pushFront (int item){

        Node *t = new Node();
        t->item = item;
        t->next = NULL;

        if ( this->isEmpty() ){
            this->head = t;
            this->tail = t;
        }
        else{
            t->next = this->head;
            this->head = t;
        }
        this->n++;
    }

    //Inserir no final
    void pushBack (int item){

        if (this->isEmpty() ){
            this->pushFront(item);
        }
        else {
            Node *t = new Node ();
            t->item = item;
            t->next = NULL;
            this->tail->next = t;
            this->tail = t;
            this->n++;
        }
    }

    //Insrir em uma posição
    void push (int item, int pos){
        if (pos < 0 || pos > this->n){
            cout << "Erro: indice invalido.\n";
            return;
        }

        if (pos == 0){
            this->pushFront(item);
        }
        else if (pos == n){
            this->pushBack(item);
        }
        else { //Neste caso exitem pelo menos 2 elementos na lista
               //e não estou inserindo nem no início nem no fim
            Node *nn = new Node();
            nn->item = item;

            //Posicionar um temporário na posição anterior
            Node *t1 = this->getNode(pos - 1);
            Node *t2 = t1->next;
            t1->next = nn;
            nn->next = t2;
            this->n++;
        }
    }

    //Remover do início
    int popFront (){

        if ( this->isEmpty() ){
            cout << "Erro: Lista vazia.\n";
            return -1;
        }
        else {
            int item = this->head->item;

            if (this->n == 1){
                delete this->head;
                this->head = NULL;
                this->tail = NULL;
            }
            else {
                Node *t = this->head;
                this->head = this->head->next;
                delete t;
            }
            this->n--;
            return item;
        }
    }




    //Remover do final
    int popBack () {
        if ( this->isEmpty() ){
            cout << "Erro: Lista vazia.\n";
            return -1;
        }

        else if (this->n == 1){
            return this->popFront();
        }
        else{
            Node *t = this->getNode(this->n - 2);
            int item = this->tail->item;
            delete this->tail;
            t->next = NULL;
            this->tail = t;
            this->n--;
            return item;
        }
    }

    //Remover de uma posição
    int pop ( int pos ){
        if (this->isEmpty){
            cout << "Erro: Lista Vazia.\n";
            return -1;
        }else if (pos == 1){
            return this->popFront();
        }else if (pos == this->n - 2){
            return popBack();
        }else{
            Node *t = this->getNode(pos);
            int cont = 2;


        }


    }

    //Retorna o item do início
    int getFront () {

    }

    //Retorna o item do final
    int getBack () {

    }

    //Retorna o item de uma posição
    int get (int pos){

    }

    //Tamanho da lista
    int size () {
        return this->n;
    }

    //Verifica se está vazia
    bool isEmpty () {
        return this->n == 0;
    }

    //Apaga todos os elementos da lista
    void clear () {
        while ( !this->isEmpty() )
            this->popFront();
    }


    //Mostra todos os elementos da lista
    void show () {

        cout << "Lista: ";
        for ( Node *t = this->head; t != NULL ; t=t->next ){
            cout << t->item << " ";
        }
        cout << "\n";

    }

};




int main()
{
    List L;
    L.pushFront(10);
    L.pushFront(20);
    L.pushBack(10);
    L.pushBack(20);
    L.show();

    return 0;
}
