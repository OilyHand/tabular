#include "bitop.h"

int main(){
    int len, len_minterms, len_dontcares;

    std::cout << "변수의 수, minterm의 수, don't care의 수를 차례로 입력하세요:\n";
    if (!(std::cin >> len >> len_minterms >> len_dontcares)) {
        std::cout << "[Error] 입력 형식이 잘못되었습니다.\n";
        return 1;
    }

    TruthTable tt(len, len_minterms, len_dontcares);

    if (len_minterms > 0) {
        std::cout << len_minterms << "개의 minterm 번호를 입력하세요:\n";
        for (int i = 0; i < len_minterms; ++i) {
            Term t;
            std::cin >> t.number;
            t.is_dontCare = false;
            tt.append(t);
        }
    }

    if (len_dontcares > 0) {
        std::cout << len_dontcares << "개의 don't care 번호를 입력하세요:\n";
        for (int i = 0; i < len_dontcares; ++i) {
            Term t;
            std::cin >> t.number;
            t.is_dontCare = true;
            tt.append(t);
        }
    }

    tt.show_table();

    int iter = tt.len_terms();
    for(int i = 0; i < iter; i++){
        Term a = tt.getTerm(i);
        printf("minterm: %d (%s)\n", a.number, a.is_dontCare ? "don't care":"minterm");
    }

    return 0;
}