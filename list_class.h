template<class dType>
class list_class;


template<class dType>
class list_cell{
public:
    list_cell(){};
    list_cell(dType content) : content(content){};
    list_cell(list_cell * prew, dType content) :
        prew_ptr(prew), content(content){};
    list_cell(list_cell * next, list_cell * prew, dType content) :
        next_ptr(next), prew_ptr(prew), content(content){};

    ~list_cell(){};
    
    list_cell * Get_next();
    list_cell * Get_prew();
    dType Get_content();
    friend class list_class < dType > ;
private:
    void Set_next(list_cell *);
    void Set_prew(list_cell *);

    list_cell * next_ptr = 0, * prew_ptr = 0;
    dType content;
};

template<class dType>
class list_class{
public:
    list_class();
    ~list_class();

    list_cell<dType> * begin();
    list_cell<dType> * end();
    list_cell<dType> * push_back(dType);
    void pop_back();
    int size();
private:
    list_cell<dType> * first_cell = 0, * last_cell = 0;
    int cells_cnt = 0;
};

