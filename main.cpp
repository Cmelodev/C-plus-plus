using namespace std;

struct node { //Cria um novo nó
    int valor  //valor
    node *next  //nó
};

class Queue(){  //fila

private:
    Node *head; //cabeça
    Node *tail; //calda
    int n;  //valor


public:
    Queue{  //construtor
        this->head = this->tail = null
    };

    ~Queue{    //desconstrutor
    };

    void enQueue(int n){ //enfilherar
        node* t = new node(); //novo no (caixinha)
        t->valor = n;   //declara o valor
        t->next = null; //declara next null

        if (isEmpty()){
            this->head = t;
            this->tail = t;
        } else {
            this->tail->next = t;
            this->tail = t;
        } this->n++

    };

    void deQueue(){
    };

    void peek() {  //frente
    };

    void isEmpty(){   //vazio
    };

    void Display(){   //mostrar
    };
};


int main{
    printf("Helo world!")
};
