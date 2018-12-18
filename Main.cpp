#include <iostream>
#include <fstream>
#include "list_class.h"


class bracket_sequencer{
public:
    bracket_sequencer();
    ~bracket_sequencer();

    bool push_back(char);
    bool is_correct();

private:
    bool correct = 1;
    list_class<char> sequence;
    list_class<list_cell<char> * > openBracketRef;
};

bracket_sequencer::bracket_sequencer(){
}

bracket_sequencer::~bracket_sequencer(){
}

bool bracket_sequencer::push_back(char cur_bracket){
    list_cell<char> * current_bracket_ptr = sequence.push_back(cur_bracket);
    
    if (!correct)
        return false;

    char reverse_bracket;
    bool is_open_bracket = 0;
    
    switch (cur_bracket){
        case '(' :
            is_open_bracket = true;
            reverse_bracket = ')';
            break;
        case '{':
            is_open_bracket = true;
            reverse_bracket = '}';
            break;
        case '[':
            is_open_bracket = true;
            reverse_bracket = ']';
            break;
        case ')':
            is_open_bracket = false;
            reverse_bracket = '(';
            break;
        case '}':
            is_open_bracket = false;
            reverse_bracket = '{';
            break;
        case ']':
            is_open_bracket = false;
            reverse_bracket = '[';
            break;
    }
    
    if (!is_open_bracket){
        if(openBracketRef.end() == NULL)
            correct = false;
        else{
            list_cell<char> * last_open = openBracketRef.end()->Get_content();
            openBracketRef.pop_back();
            if (last_open->Get_content() != reverse_bracket)
                correct = false;
        }
    }
    else{
        openBracketRef.push_back(current_bracket_ptr);
    }
    return correct;
}

bool bracket_sequencer::is_correct(){
    if (correct && openBracketRef.size() == 0)
        return true;
    return false;
}

int main(int argc, char * argv[]){

    std::ifstream ifs;
    bracket_sequencer bs;

    ifs.open(argv[1]);
    char str[64], * s_ptr;
    int read_cnt = 0;

    while (!ifs.eof()){
        ifs.read(str, 64);
        read_cnt = ifs.gcount();
        s_ptr = str;
        while (*s_ptr && (*s_ptr != '\n') && s_ptr != str + read_cnt){
            bs.push_back(*s_ptr++);
        }
    }

    if (bs.is_correct())
        std::cout << "correct sequence\n";
    else
        std::cout << "wrong sequence\n";

    return 0;
}
