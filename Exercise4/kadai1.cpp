//学籍番号: 4619023 氏名:　加藤　零
#include <iostream>
using namespace std;

class Order {
   private:
    int p_hamburger;  // ハンバーガーの価格
    int p_potato;     // ポテトの価格
    int p_drink;      // ドリンクの価格

   public:
    int number;     // 注文No.
    int hamburger;  // ハンバーガーの個数
    int potato;     // ポテトの個数
    int drink;      // ドリンクの個数
    int total;      // 支払金額

    void Set_Price();   // 各アイテムの価格を設定する関数
    void Cal_Total();   // 支払額を計算する関数
    void Disp_Total();  // 支払額を表示する関数
};

void Order::Set_Price() {
    p_hamburger = 200;
    p_potato = 180;
    p_drink = 150;
}

void Order::Cal_Total() {
    total = p_hamburger * hamburger + p_drink * drink + p_potato * potato;
}

void Order::Disp_Total() { cout << "支払金額:" << total << "円 \n"; }

int main(void) {
    Order o;
    o.Set_Price();
    o.number = 1;
    o.hamburger = 1;
    o.potato = 1;
    o.drink = 1;
    o.Cal_Total();
    o.Disp_Total();
    return 0;
}
