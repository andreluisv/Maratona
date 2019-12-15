struct Link{
    int value;
    Link* next;
};

class Queue{
public:
    Link* front;
    Link* rear;
    int size;

    Queue(){//Constructor
        Link* front = NULL;
        Link* rear = NULL;
        int size = 0;
    }

    Queue* create_queue(){//Reset the current Queue and returns it
        this->front = NULL;
        this->rear = NULL;
        size = 0;
        return this;
    }
    void enqueue(int it){//Push an element to the back of the queue
        Link* temp = new Link;
        temp->value = it;
        temp->next = NULL;

        if (this->front == NULL){
            this->front = temp;
            this->rear = temp;
            this->size++;
        }else{
            this->rear->next = temp;
            this->rear = temp;
            this->size++;
        }
    }
    int dequeue(){//Remove the front element and than returns it
        if (this->size == 0)
            return -1;
        int it = this->front->value;
        this->front = this->front->next;
        if (this->front->next == nullptr)
            this->rear = this->front;
        this->size--;
        return it;
    }
    int frontValue(){//Returns the front element
        if (this->size == 0)
            return -1;
        return this->front->value;
    }

    int rearValue(){//Returns the back element
        if (this->size == 0)
            return -1;
        return this->rear->value;
    }

    int length(){//Returns it's current size
        return this->size;
    }

};
/*
Queue Cards;
Cards.create_queue()
Cards.enqueue(x)
Cards.dequeue()
Cards.frontValue()
*/
