//学籍番号:4619023 加藤零
#include <iostream>
using namespace std;

class Order {
   private:
    static int p_hamburger;  // ハンバーガーの価格
    static int p_potato;     // ポテトの価格
    static int p_drink;      // ドリンクの価格
    int number;              // 注文No.
    int hamburger;           // ハンバーガーの個数
    int potato;              // ポテトの個数
    int drink;               // ドリンクの個数
    int total;               // 支払金額
   public:
    Order(int num, int c_hamburger, int c_potato, int c_drink) {
        number = num;
        hamburger = c_hamburger;
        potato = c_potato;
        drink = c_drink;
    }
    ~Order() {}

    static void Set_Price(int hamburger, int potato, int drink) {
        p_hamburger = hamburger;
        p_potato = potato;
        p_drink = drink;
    }  // 各アイテムの価格を設定する関数

    void Cal_Total() {
        total = p_hamburger * hamburger + p_drink * drink + p_potato * potato;
    };  // 支払額を計算する関数

    void Disp_Total() {
        cout << "支払金額:" << total << "円 \n";
    }  // 支払額を表示する関数
};

int Order::p_hamburger;
int Order::p_potato;
int Order::p_drink;

int main(void) {
    Order::Set_Price(200, 180, 150);
    Order o(1, 1, 1, 1);
    o.Cal_Total();
    o.Disp_Total();
    return 0;
}
