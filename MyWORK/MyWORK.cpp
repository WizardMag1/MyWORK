#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Структура данных для заказа
struct Order {
    int orderNumber;           // Номер заказа (генерируется автоматически)
    struct {
        int day;
        int month;
        int year;
    } orderDate;                // Дата заказа
    string productName;        // Наименование товара
    double pricePerUnit;       // Цена за штуку
    int quantity;              // Количество
    bool delivery;             // Доставка (да / нет)
    double totalAmount;        // Общая сумма (рассчитывается автоматически)
    string orderStatus;        // Статус заказа
};

// Функция для расчета общей суммы заказа
double calculateTotalAmount(const Order& order) {
    double total = order.pricePerUnit * order.quantity;
    if (order.delivery) {
        total += 200.0;
    }
    return total;
}

int main() {
    vector<Order> orders; // Вектор для хранения заказов

    int choice;
    do {
        cout << "Меню:\n";
        cout << "1. Добавить заказ\n";
        cout << "2. Просмотр заказов\n";
        cout << "3. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            // Добавление нового заказа
            Order newOrder;
            newOrder.orderNumber = orders.size() + 1; // Автоматически генерируем номер заказа

            cout << "Введите дату заказа (день месяц год): ";
            cin >> newOrder.orderDate.day >> newOrder.orderDate.month >> newOrder.orderDate.year;

            cin.ignore(); // Очистить буфер ввода
            cout << "Введите наименование товара: ";
            getline(cin, newOrder.productName);

            cout << "Введите цену за штуку: ";
            cin >> newOrder.pricePerUnit;

            cout << "Введите количество: ";
            cin >> newOrder.quantity;

            cout << "Была ли доставка (1 - да, 0 - нет): ";
            cin >> newOrder.delivery;

            // Рассчитываем общую сумму автоматически
            newOrder.totalAmount = calculateTotalAmount(newOrder);

            cin.ignore(); // Очистить буфер ввода
            cout << "Введите статус заказа (Новый, В обработке, Ожидание оплаты, Отправлен, Получен): ";
            getline(cin, newOrder.orderStatus);

            // Добавляем заказ в вектор
            orders.push_back(newOrder);

            cout << "Заказ добавлен!\n";
            break;

        case 2:
            // Просмотр заказов
            if (orders.empty()) {
                cout << "Список заказов пуст.\n";
            }
            else {
                cout << "Список заказов:\n";
                for (const Order& order : orders) {
                    cout << "Номер заказа: " << order.orderNumber << endl;
                    cout << "Дата заказа: " << order.orderDate.day << "/" << order.orderDate.month << "/" << order.orderDate.year << endl;
                    cout << "Наименование товара: " << order.productName << endl;
                    cout << "Цена за штуку: " << order.pricePerUnit << endl;
                    cout << "Количество: " << order.quantity << endl;
                    cout << "Доставка: " << (order.delivery ? "Да" : "Нет") << endl;
                    cout << "Общая сумма: " << order.totalAmount << endl;
                    cout << "Статус заказа: " << order.orderStatus << endl;
                    cout << "----------------------------------------\n";
                }
            }
            break;

        case 3:
            cout << "Выход.\n";
            break;

        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
            break;
        }

    } while (choice != 3);

    return 0;
}
