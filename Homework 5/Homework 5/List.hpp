#ifndef LIST_HPP
#define LIST_HPP

template <typename T>
class List {
    protected:
        // the current number of elements in the list
        // I never used this part of the code, I thought I was going to need it, but I really never needed 
        //to know how many nodes were created for any of my functions. 
        int length;

    public:
        // default constructor
        List() : length(0) { }

        // destructor
        virtual ~List() { }

        // add the argument to the end of the list
        virtual void append(const T&) = 0;

        // remove all elements in the list, resetting to the initial state
        virtual void clear() = 0;

        // return the current length of the list
        virtual int getLength() const = 0;

        // determine if the list is currently empty
        virtual bool isEmpty() const = 0;

      
};

#endif
