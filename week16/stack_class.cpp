//Edited line 8, pop_front() from STL list is a void function
template <class T>
class Stack{
    private:   
        list<T> data;
    public:
        void push(T newItem){data.push_front(newItem);};
        T pop() { data.pop_front(); };
        T top() const { return *data.begin(); };
        bool isEmpty() const { return data.size() == 0; };
        int size(){ return data.size();};
        void clear(){ data.clear();};
};
