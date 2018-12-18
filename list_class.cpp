#include "list_class.h"

template class list_class< char >;
template class list_class< class list_cell < char > *>;
template class list_cell < char >;
template class list_cell < class list_cell < char > *>;

template<class dType>
list_cell<dType> * list_cell<dType>::Get_next(){
    return next_ptr;
}

template<class dType>
list_cell<dType> * list_cell<dType>::Get_prew(){
    return prew_ptr;
}

template<class dType>
void list_cell<dType>::Set_next(list_cell<dType> * next){
    next_ptr = next;
}

template<class dType>
void list_cell<dType>::Set_prew(list_cell<dType> * prew){
    prew_ptr = prew;
}

template<class dType>
dType list_cell<dType>::Get_content(){
    return content;
}

template<class dType>
list_class<dType>::list_class(){
    
}

template<class dType>
list_class<dType>::~list_class(){
    list_cell<dType> * current = this->first_cell,
        * next = 0;

    while (current){
        next = current->Get_next();
        delete current;
        current = next;
    }
}

template<class dType>
list_cell<dType> * list_class<dType>::push_back(dType content){
    if (cells_cnt == 0){
        first_cell = new list_cell<dType>(content);
        last_cell = first_cell;
    }
    else{
        list_cell<dType> * new_cell = new list_cell<dType>(last_cell, content);
        last_cell->Set_next(new_cell);
        last_cell = new_cell;
    }
    cells_cnt++;
    return last_cell;
}

template<class dType>
void list_class<dType>::pop_back(){
    if (!last_cell)
        return;
    this->last_cell = this->last_cell->Get_prew();
    cells_cnt--;
    if(cells_cnt != 0)
        last_cell->Set_next(0);
}

template<class dType>
list_cell<dType> * list_class<dType>::end(){
    return this->last_cell;
}

template<class dType>
list_cell<dType> * list_class<dType>::begin(){
    return this->first_cell;
}

template<class dType>
int list_class<dType>::size(){
    return this->cells_cnt;
}

