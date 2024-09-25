#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

    private:
        // miembros privados
		static const int MINSIZE;
		T* arr;
		int max;
		int n;
		void resize(int new_size);
    public:
        // miembros públicos, incluidos los heredados de List<T>
		ListArray();
		~ListArray();
		T operator[](int pos);
		friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list);
		
		//heredados
		void insert(int pos, T e) override final;
		void append(T e) override final;
		void prepend(T e) override final;
		T remove(int pos) override final;
		T get(int pos) override final;
		int search(T e) override final;
		bool empty() override final;
		int size() override final;
};


template <typename T>
const int ListArray<T>::MINSIZE = 2;

template <typename T>
ListArray<T>::ListArray(){
	new T [MINSIZE];
	max = MINSIZE;
	n = 0;
}

template <typename T>
ListArray<T>::~ListArray(){
	delete[] arr;
}

template <typename T>
T ListArray<T>::operator[](int pos){
	if(pos > size()-1 || pos < 0){
		throw std::out_of_range("Esta fuera de rango");
	}
	else{
		return arr[pos];
	}
}

template <typename T>
std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
	for(int i = 0; i < list.n; i++){
		out << list.arr[i] << " ";
	}
	return out;
}

template <typename T>
void ListArray<T>::resize(int new_size){
	T* new_arr = new T[new_size];
	for(int i = 0; i < n; i++){
		new_arr[i] = arr[i];
	}
	delete[] arr;
	arr = new_arr;
	max = new_size;
}


template <typename T>
void ListArray<T>::insert(int pos, T e){
	if(pos < 0 || pos > size()){
		throw std::out_of_range("No esta en rango");
	}
	else{
		ListArray<T>::resize(max+1);
		
		
	





















}
