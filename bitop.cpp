#include "bitop.h"

TruthTable::TruthTable(int len, int len_minterms, int len_dontcares){
    len_           = len;
    len_minterms_  = len_minterms;
    len_dontcares_ = len_dontcares;
    len_terms_     = len_minterms_ + len_dontcares_;
    index_         = 0;

    table.resize(len_terms_);
}

TruthTable::~TruthTable() = default;

int TruthTable::size(){
    return len_;
}

int  TruthTable::len_terms(){
    return len_terms_;
}

bool TruthTable::is_full(){
    return index_ == len_terms_;
}

void TruthTable::append(Term t){
    if(!is_full()){
        table[index_++] = t;
        
    } else {
        printf("[Error] Truth Table is full.");
    }

    if(is_full()){
        std::sort(table.begin(), table.end(),
        [](const Term& a, const Term& b) {
            return a.number < b.number;
        });
    };
}

Term TruthTable::getTerm(int index){
    if(index < len_terms_){
        return table[index];
    } else {
        Term t = {0};
        return t;
    }
}


void TruthTable::show_table() {
    int total_rows = 1 << len_; 
    std::vector<int> f_values(total_rows, 0); 

    for (int i = 0; i < index_; ++i) {
        if (table[i].number < total_rows) {
            if (table[i].is_dontCare) {
                f_values[table[i].number] = 2;
            } else {
                f_values[table[i].number] = 1;
            }
        }
    }

    std::cout << "+-";
    for (int i = 0; i < len_; ++i) {
        std::cout << "---";
    }
    std::cout << "+---+\n";

    std::cout << "| ";
    for (int i = len_ - 1; i >= 0; --i) {
        std::cout << "x" << i << " ";
    }
    std::cout << "| F |\n";

    std::cout << "+-";
    for (int i = 0; i < len_; ++i) {
        std::cout << "---";
    }
    std::cout << "+---+\n";

    for (int row = 0; row < total_rows; ++row) {
        std::cout << "| ";
        
        for (int bit_idx = len_ - 1; bit_idx >= 0; --bit_idx) {
            int bit = (row >> bit_idx) & 1;
            
            int width = 2 + std::to_string(bit_idx).length();
            std::cout << std::setw(width - 1) << bit << " ";
        }
        
        std::cout << "| ";
        if (f_values[row] == 1) {
            std::cout << "1";
        } else if (f_values[row] == 2) {
            std::cout << "x";
        } else {
            std::cout << "0";
        }
        std::cout << " |\n";
    }

    std::cout << "+-";
    for (int i = 0; i < len_; ++i) {
        std::cout << "---";
    }
    std::cout << "+---+\n";
}




template <typename DATA_T>
int hamming_weight(DATA_T x){
    int count = 0;
    while(x){
        x &= (x - 1);
        count++;
    } return count;
}

template <typename DATA_T>
int hamming_distance(DATA_T x, DATA_T y){
    return hamming_weight(x ^ y);
}
