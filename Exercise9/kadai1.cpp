//学籍番号:4619023 加藤零
#include <iostream>

#include "NewOrder1.h"
#include "NewOrder2.h"
using namespace std;

class FinalOrder : public NewOrder1, public NewOrder2 {
   protected:
    static int current_number;

   public:
    FinalOrder();
    ~FinalOrder();
    virtual void Cal_Total();
    void Print_number();
    static void Set_Price() {
        NewOrder1::Set_Price();
        NewOrder2::Set_Price();
    };
};
int FinalOrder::current_number = 0;
FinalOrder::FinalOrder() {
    ++current_number;
    number = current_number;
}
FinalOrder::~FinalOrder() { --current_number; }

void FinalOrder::Cal_Total() {
    Order::Cal_Total();
    total += p_cheeseburger * cheeseburger;
    total += p_fishburger * fishburger;
}

void FinalOrder::Print_number() { cout << "注文番号:" << number << endl; }

int main(void) {
    FinalOrder::Set_Price();
    int n = 10;
    FinalOrder *p = new FinalOrder[n];
    for (int i = 0; i < n; i++) {
        p[i].Set_Drink(1);
        p[i].Set_Potato(1);
        p[i].Set_Hamburger(1);
        p[i].Set_Cheeseburger(1);
        p[i].Set_Fishburger(1);
        p[i].Cal_Total();
        p[i].Disp_Total();
        p[i].Print_number();
    }

    // main関数の定義
    // ハンバーガ200円、ドリンク180円、ポテト150円、チーズバーガ250円、フィッシュバーガ300円
    // 全てのアイテムを1個ずつ購入すると1080円

    return 0;
}
