#include <ostream>

template <typename T> 
class Node {
    public:
   		T data;
		Node<T>* next;
		Node(T data, Node<T>* next=nullptr);
		template <typename U>
		friend std::ostream& operator<<(std::ostream &out, const Node<T> &node);
};

template <typename T>
Node<T>::Node(T data, Node<T>* next){
	this->data = data;
	this->next = next;
}


template <typename T>
std::ostream& operator<<(std::ostream &out, const Node<T> &node){
	Node<T>* current = &node;
	do{
		out << current->data << " ";
		current = current->next;
	} while(current != nullptr);
	return out;
}
