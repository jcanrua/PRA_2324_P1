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
		template <typename U>
		friend std::ostream& operator<<(std::ostream &out, const ListArray<U> &list);
		
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
		for(int i = max; i > pos; i--){
			arr[i] = arr[i-1];
		}
		arr[pos] = e;
	}
}


template <typename T>
void ListArray<T>::append(T e){
	insert(max+1,e);
}		
	

template <typename T>
void ListArray<T>::prepend(T e){
	insert(0, e);
}		


template <typename T>
T ListArray<T>::remove(int pos){
	T tmp;
	if(pos < 0 || pos > size()-1){
		throw std::out_of_range("Rango incorrecto");
	}
	else{
		tmp = arr[pos];
		for(int i = pos+1; i < max; i++){
			arr[i-1] = arr[i];
		}
		resize(max-1);
		return tmp;
	}		
}


template <typename T>
T ListArray<T>::get(int pos){
	if(pos < 0 || pos > size()-1){
		throw std::out_of_range("Rango incorrecto");
	}
	else{
		return arr[pos];
	}		
}

template <typename T>
int ListArray<T>::search(T e){
	for(int i = 0; i < max; i++){
		if(e = arr[i]){
			return i;
		}
	}
	return -1;
}

template <typename T>
bool ListArray<T>::empty(){
	if(n == 0){
		return true;
	}
	else{
		return false;
	}
}

template <typename T>
int ListArray<T>::size(){
	return n;
}
