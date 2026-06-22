#ifndef BITOP_H_
#define BITOP_H_

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdint>

class Term {
  public:
    uint32_t number;
    bool     is_dontCare;
    Term();
    Term(uint32_t n, bool dc);
};

class Cube {
  public:
    Cube();
    void setNumber(uint32_t n);
    void setMask(uint32_t m);
  
  private:
    bool     selected_;
    uint32_t number_;
    uint32_t mask_;
};

class CNode{
  Cube  content;
  Cube* next;

  CNode();
};

class Group{
  int index;
  
};

class TruthTable {
  public:
    TruthTable(int len,
               int len_minterms,
               int len_dontcares);
    ~TruthTable();

    int  size();
    int  len_terms();
    bool is_full();
    void append(Term t);
    Term getTerm(int index);
    
    void show_table();
    
    private:
    int len_;
    int len_terms_;
    int len_minterms_;
    int len_dontcares_;
    int index_;
    std::vector<Term> table;
};


// =============================================================
//  Bit Operation Functions
// -------------------------------------------------------------

/**
 * Return the number of ones
 */
template <typename DATA_T>
int hamming_weight(DATA_T x);

/**
 * Return bit difference between two arguments
 */
template <typename DATA_T>
int hamming_distance(DATA_T x, DATA_T y);


#endif