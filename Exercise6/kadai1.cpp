//学籍番号:4619023 加藤零
#include <iostream>
using namespace std;

class Order {
   protected:
    static int p_hamburger;  // ハンバーガーの価格 (静的メンバ変数)
    static int p_potato;     // ポテトの価格 (静的メンバ変数)
    static int p_drink;      // ドリンクの価格 (静的メンバ変数)

    int number;     // 注文No.
    int hamburger;  // ハンバーガーの個数
    int potato;     // ポテトの個数
    int drink;      // ドリンクの個数
    int total;      // 支払金額

   public:
    Order();
    void Cal_Total();   // 支払い額を求める関数
    void Disp_Total();  // 支払額を表示する関数
    void Set_Hamburger(int num);  // ハンバーガの購入数を設定する関数 num:購入数
    void Set_Potato(int num);  // ポテトの購入数を設定する関数 num:購入数
    void Set_Drink(int num);  // ドリンクの購入数を設定する関数 num:購入数

    static void Set_Price() {  // 各アイテムの価格を設定する静的関数
        p_hamburger = 200;  // ハンバーガ 200円
        p_potato = 180;     // ポテト 180円
        p_drink = 150;      // ドリンク 150円
    };
};

int Order::p_hamburger;  // 静的メンバ変数の宣言
int Order::p_potato;
int Order::p_drink;

Order::Order() {  // コンストラクタ
    hamburger = 0;
    potato = 0;
    drink = 0;
    total = 0;
}

void Order::Cal_Total() {
    total = p_hamburger * hamburger + p_potato * potato + p_drink * drink;
}

void Order::Disp_Total() { cout << "支払金額:" << total << "円 " << endl; }

void Order::Set_Hamburger(int num) { hamburger = num; }

void Order::Set_Potato(int num) { potato = num; }

void Order::Set_Drink(int num) { drink = num; }

class NewOrder : public Order {
   protected:
    static int p_cheeseburger;

    int cheeseburger;

   public:
    NewOrder();
    void Cal_Total();
    void Set_Cheeseburger(int num);

    static void Set_Price() {
        p_cheeseburger = 250;
        Order::Set_Price();
    };
};
int NewOrder::p_cheeseburger;
NewOrder::NewOrder() { cheeseburger = 0; }

void NewOrder::Set_Cheeseburger(int num) { cheeseburger = num; }
void NewOrder::Cal_Total() {
    total = p_hamburger * hamburger + p_potato * potato + p_drink * drink +
            p_cheeseburger * cheeseburger;
}

int main(void) {
    NewOrder::Set_Price();
    NewOrder o;
    o.Set_Drink(1);
    o.Set_Potato(1);
    o.Set_Hamburger(1);
    o.Set_Cheeseburger(1);
    o.Cal_Total();
    o.Disp_Total();
    return 0;
}
