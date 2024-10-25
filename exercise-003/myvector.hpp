#ifndef MY_VECTOR_HPP
#define MY_VECTOR_HPP

class MyVector {

public:
    MyVector();
    MyVector(unsigned int size);
    ~MyVector();
    int size();




    //Änderungen Anfang
    int size() const; // size sollte die Größe des Vektors zurückgeben
    int& at(unsigned int idx); // Rückgabe per Referenz, damit man das Element ändern kann
    void push_back(int element); // Fügt ein Element ans Ende
    void push_back(const int& element); // Element per Referenz hinzufügen
    void push_back(const int* element); // Zeiger auf Element hinzufügen
    //Änderungen Ende

private:
    int* m_data;
};


#endif /* MY_VECTOR_HPP */