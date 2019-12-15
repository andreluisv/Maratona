struct Link{
    char value;
    Link* next;
};

class Stack{
public:
    Link* top;
    int size;

    Stack(){//Constructor
        this->top = new Link;
        this->size = 0;
    }
    
    void clear(){//Empty the stack
      this->top->next = NULL;
      this->size = 0;
    };
    
    void push(char it){//Push an element to the top of the Stack
        Link* aux = this->top->next;
        this->top->next = new Link;
        this->top->next->value = it;
        if (this->size != 0)
            this->top->next->next = aux;
        else
            this->top->next->next = NULL;
        this->size++;
    };
    
    char pop(){//Pops the top element and then returns it
      if (this->top->next == NULL)
          return '#';
      char it = this->top->next->value;
      this->top->next = this->top->next->next;
      this->size--;
      return it;
    };
    
    char topValue(){//Returns the top element
        if (this->top->next == NULL)
            return '#';

        return this->top->next->value;
    };
    
    int lenght(){//Return it's current size
      return this->size;
    };
};
/*
Stack* pilha = new Stack();
lista->push(x)
lista->pop()
lista->lenght()
*/
