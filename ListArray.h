#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

    private:
        // miembros privados
		void resize(int new_size);
		T* arr;
		int max;
		int n;
		static const int MINSIZE
    public:
        // miembros públicos, incluidos los heredados de List<T>
		ListArray();
		~ListArray();
		T operator[](int pos);
		friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list);

};
