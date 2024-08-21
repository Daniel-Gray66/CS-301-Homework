template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
: head(nullptr) { }

//copy contructor 

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& copyObj) {
    copy(copyObj);
}

//overload = operator

template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList <T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
}

template <typename T>
void DoublyLinkedList<T>::append(const T& elem) {
    Node* n = new Node(elem);

    if (head == nullptr) {
        head = n;
    }
    else {
        Node* curr = head;

        while (curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = n;
    }

    this->length++;
}

template <typename T>
void DoublyLinkedList<T>::clear() {
    Node* prev = nullptr;

    while (head != nullptr) {
        prev = head;
        head = head->next;
        delete prev;
    }

    this->length = 0;
}

template <typename T>
void DoublyLinkedList<T>::copy(const DoublyLinkedList<T>& copyObj) {
    this->length = copyObj.length;
    head         = nullptr;

    if (this->length > 0) {
        head           = new Node(copyObj.head->value);
        Node* myCurr   = head;
        Node* copyCurr = copyObj.head->next;

        while (copyCurr != nullptr) {
            Node* n      = new Node(copyCurr->value);
            myCurr->next = n;
            myCurr       = n;
            copyCurr     = copyCurr->next;
        }
    }
}

template <typename T>
T DoublyLinkedList<T>::getElement(int position) const {
    if (position <0 || position >= this->length) {
        throw string("getElement: error, position out of bounds");
    }
    
    Node* curr = head;

    for (int i = 0; i <position; i++) {
        curr = curr->next;
    }

    return curr->value;
}

template <typename T>
int DoublyLinkedList<T>::getLength() const {
    return this->length;
}

template <typename T>
void DoublyLinkedList<T>::insert(int position, const T& elem) {
    if (position <0 || position >= this->length) {
        throw string("insert: error, position out of bounds");
    }

    Node* n    = new Node(elem);
    Node* curr = head;
    Node* prev = nullptr;

    for (int i = 0; i <position; i++) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == head) {
        head = n;
    }
    else {
        prev->next = n;
    }

    n->next = curr;
    this->length++;
}

template <typename T>
bool DoublyLinkedList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
void DoublyLinkedList<T>::remove(int position) {
    if (position <0 || position >= this->length) {
        throw string("remove: error, position out of bounds");
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
    }
    else {
        Node* curr = head;
        Node* prev = nullptr;

        for (int i = 0; i <position; i++) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == head) {
            head = head->next;
        }
        else {
            prev->next = curr->next;
        }

        delete curr;
    }

    this->length--;
}

template <typename T>
void DoublyLinkedList<T>::replace(int position, const T& elem) {
    if (position <0 || position >= this->length) {
        throw string("replace: error, position out of bounds");
    }

    Node* curr = head;

    for (int i = 0; i <position; i++) {
        curr = curr->next;
    }

    curr->value = elem;
}

template <typename T>
ostream& operator<<(ostream& outStream, const DoublyLinkedList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        typename DoublyLinkedList<T>::Node* curr = myObj.head;
        while (curr != nullptr) {
            outStream <<curr->value;
            if (curr->next != nullptr) {
                outStream << " --> ";
            }
            curr = curr->next;
        }
        outStream <<endl;
    }

    Return outStream;
}
