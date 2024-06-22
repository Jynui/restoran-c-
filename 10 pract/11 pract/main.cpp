#include <iostream>
#include <vector>
#include "menu.h"
#include "product.h"
#include "user.h"
#include "order.h"
#include "utils.h"
#include "authentication.h"

void adminMenu(Menu& menu, Authentication& auth);
void guestMenu(Menu& menu, Guest& guest);
void employeeMenu(Menu& menu, const std::string& role);
bool checkProductAvailability(const Menu& menu, const std::vector<Product>& ingredients);

int main() {
    setlocale(LC_ALL, "Russian");

    Menu menu;
    Authentication auth;

    Product sausage(1, "Сосиски", 1.0, 50);
    Product pepperoni(2, "Пепперони", 2.0, 50);
    Product tomato(3, "Перец", 0.5, 50);
    Product cheese(4, "Сыр", 1.0, 60);
    Product dough(5, "Тесто", 1.5, 60);
    Product cheese_mixture(6, "Смесь сыров", 3, 40);

    std::vector<Product> products = { sausage, pepperoni, tomato, cheese, dough, cheese_mixture };
    menu.setProducts(products);

    menu.addItem("Четыре сыра", { pepperoni, cheese, dough }, "Четыре сыра", 20, 4.99);
    menu.addItem("Сырная", { cheese_mixture, dough }, "Супер сырная пицца", 10, 6.99);
    menu.addItem("Маргаритта", { sausage, cheese, tomato }, "Пицца маргаритта со свежими помидорками", 10, 3.99);

    User admin(1, "admin", "Владимирович", "Матвей", "Комолов", "admin", "admin");
    auth.addUser(admin);

    User employee(2, "cook", "Александровна", "Виктория", "Алексеева", "cook", "cook");
    auth.addUser(employee);

    std::cout << "Вы в пиццерии!" << std::endl;

    while (true) {
        std::cout << "\n1. Администратор\n2. Гость\n3. Сотрудник\n4. Выход" << std::endl;
        int choice = Utils::getIntInput("Введите ваш выбор: ");

        switch (choice) {
        case 1: {
            std::cout << "Вход для администратора" << std::endl;
            std::string login = Utils::getStringInput("Введите логин: ");
            std::string password = Utils::getStringInput("Введите пароль: ");
            std::string role;

            if (auth.login(login, password, role) && role == "admin") {
                adminMenu(menu, auth);
            }
            else {
                std::cout << "Неверный логин или пароль!" << std::endl;
            }
            break;
        }
        case 2: {
            std::cout << "Меню для гостя" << std::endl;
            Guest guest(1, "Гость");
            guestMenu(menu, guest);
            break;
        }
        case 3: {
            std::cout << "Меню для сотрудника" << std::endl;
            std::string login = Utils::getStringInput("Введите логин: ");
            std::string password = Utils::getStringInput("Введите пароль: ");
            std::string role;

            if (auth.login(login, password, role)) {
                employeeMenu(menu, role);
            }
            else {
                std::cout << "Неверный логин или пароль!" << std::endl;
            }
            break;
        }
        case 4:
            std::cout << "Выход." << std::endl;
            return 0;
        default:
            std::cout << "Неверный выбор" << std::endl;
        }
    }
}

void adminMenu(Menu& menu, Authentication& auth) {
    while (true) {
        std::cout << "\n1. Добавить пункт меню\n2. Редактировать пункт меню\n3. Удалить пункт меню\n4. Отобразить меню\n5. Управление продуктами\n6. Управление учетными записями\n7. Вернуться в главное меню" << std::endl;
        int choice = Utils::getIntInput("Введите ваш выбор: ");

        switch (choice) {
        case 1: {
            std::string name = Utils::getStringInput("Введите название товара: ");
            std::string description = Utils::getStringInput("Введите описание товара: ");
            double preparationTime = Utils::getDoubleInput("Введите время приготовления (в минутах): ");
            double price = Utils::getDoubleInput("Введите цену: ");

            std::vector<Product> ingredients;
            ingredients.push_back(Product(1, "Перец", 0.5, 50));
            ingredients.push_back(Product(2, "Сыр", 1.0, 60));
            menu.addItem(name, ingredients, description, preparationTime, price);
            break;
        }
        case 2: {
            int id = Utils::getIntInput("Введите ID товара для редактирования: ");
            std::string name = Utils::getStringInput("Введите новое название товара: ");
            std::string description = Utils::getStringInput("Введите новое описание товара: ");
            double preparationTime = Utils::getDoubleInput("Введите новое время приготовления (в минутах): ");
            double price = Utils::getDoubleInput("Введите новую цену: ");

            std::vector<Product> ingredients;
            ingredients.push_back(Product(1, "Сосиски", 0.5, 50));

            menu.editItem(id, name, ingredients, description, preparationTime, price);
            break;
        }
        case 3: {
            int id = Utils::getIntInput("Введите ID товара для удаления: ");
            menu.removeItem(id);
            break;
        }
        case 4:
            menu.displayMenu();
            break;
        case 5: {
            while (true) {
                std::cout << "\n1. Добавить продукт\n2. Редактировать продукт\n3. Удалить продукт\n4. Отобразить продукты\n5. Вернуться" << std::endl;
                int productChoice = Utils::getIntInput("Введите ваш выбор: ");

                switch (productChoice) {
                case 1: {
                    std::string name = Utils::getStringInput("Введите название продукта: ");
                    double cost = Utils::getDoubleInput("Введите стоимость продукта: ");
                    int quantity = Utils::getIntInput("Введите количество продукта: ");
                    int id = menu.getProducts().size() + 1;

                    menu.getProducts().push_back(Product(id, name, cost, quantity));
                    break;
                }
                case 2: {
                    int id = Utils::getIntInput("Введите ID продукта для редактирования: ");
                    std::string name = Utils::getStringInput("Введите новое название продукта: ");
                    double cost = Utils::getDoubleInput("Введите новую стоимость продукта: ");
                    int quantity = Utils::getIntInput("Введите новое количество продукта: ");
                    for (auto& product : menu.getProducts()) {
                        if (product.getId() == id) {
                            product = Product(id, name, cost, quantity);
                            break;
                        }
                    }
                    break;
                }
                case 3: {
                    int id = Utils::getIntInput("Введите ID продукта для удаления: ");
                    menu.getProducts().erase(std::remove_if(menu.getProducts().begin(), menu.getProducts().end(), [id](const Product& product) {
                        return product.getId() == id;
                        }), menu.getProducts().end());
                    break;
                }
                case 4:
                    for (const auto& product : menu.getProducts()) {
                        std::cout << "ID: " << product.getId() << ", Название: " << product.getName() << ", Стоимость: " << product.getCost() << ", Количество: " << product.getQuantity() << std::endl;
                    }
                    break;
                case 5:
                    return;
                default:
                    std::cout << "Неверный выбор" << std::endl;
                }
            }
        }
        case 6: {
            while (true) {
                std::cout << "\n1. Добавить учетную запись\n2. Редактировать учетную запись\n3. Удалить учетную запись\n4. Отобразить учетные записи\n5. Вернуться" << std::endl;
                int userChoice = Utils::getIntInput("Введите ваш выбор: ");

                switch (userChoice) {
                case 1: {
                    std::string role = Utils::getStringInput("Введите роль пользователя: ");
                    std::string surname = Utils::getStringInput("Введите фамилию пользователя: ");
                    std::string name = Utils::getStringInput("Введите имя пользователя: ");
                    std::string patronymic = Utils::getStringInput("Введите отчество пользователя: ");
                    std::string login = Utils::getStringInput("Введите логин пользователя: ");
                    std::string password = Utils::getStringInput("Введите пароль пользователя: ");
                    int id = auth.getUsers().size() + 1;

                    auth.addUser(User(id, role, surname, name, patronymic, login, password));
                    break;
                }
                case 2: {
                    int id = Utils::getIntInput("Введите ID пользователя для редактирования: ");
                    std::string role = Utils::getStringInput("Введите новую роль пользователя: ");
                    std::string surname = Utils::getStringInput("Введите новую фамилию пользователя: ");
                    std::string name = Utils::getStringInput("Введите новое имя пользователя: ");
                    std::string patronymic = Utils::getStringInput("Введите новое отчество пользователя: ");
                    std::string login = Utils::getStringInput("Введите новый логин пользователя: ");
                    std::string password = Utils::getStringInput("Введите новый пароль пользователя: ");
                    for (auto& user : auth.getUsers()) {
                        if (user.getId() == id) {
                            user = User(id, role, surname, name, patronymic, login, password);
                            break;
                        }
                    }
                    break;
                }
                case 3: {
                    int id = Utils::getIntInput("Введите ID пользователя для удаления: ");
                    auth.getUsers().erase(std::remove_if(auth.getUsers().begin(), auth.getUsers().end(), [id](const User& user) {
                        return user.getId() == id;
                        }), auth.getUsers().end());
                    break;
                }
                case 4:
                    for (const auto& user : auth.getUsers()) {
                        std::cout << "ID: " << user.getId() << ", Логин: " << user.getLogin() << ", Фамилия: " << user.getSurname() << ", Имя: " << user.getName() << ", Отчество: " << user.getPatronymic() << ", Роль: " << user.getRole() << std::endl;
                    }
                    break;
                case 5:
                    return;
                default:
                    std::cout << "Неверный выбор" << std::endl;
                }
            }
        }
        case 7:
            return;
        default:
            std::cout << "Неверный выбор" << std::endl;
        }
    }
}

void guestMenu(Menu& menu, Guest& guest) {
    while (true) {
        std::cout << "\n1. Посмотреть меню\n2. Заказать пиццу\n3. Вернуться в главное меню" << std::endl;
        int choice = Utils::getIntInput("Введите ваш выбор: ");

        switch (choice) {
        case 1:
            menu.displayMenu();
            break;
        case 2: {
            int id = Utils::getIntInput("Введите ID товара для заказа: ");
            MenuItem* item = menu.findItemById(id);
            if (item) {
                Order order;
                order.setId(1);
                order.setClient(guest);
                order.addItem(*item);
                guest.addOrder(order);
                std::cout << "Заказ сделан" << std::endl;
            }
            else {
                std::cout << "Пункт меню не найден" << std::endl;
            }
            break;
        }
        case 3:
            return;
        default:
            std::cout << "Неверный выбор" << std::endl;
        }
    }
}

void employeeMenu(Menu& menu, const std::string& role) {
    while (true) {
        std::cout << "\n1. Отобразить меню\n2. Проверить наличие ингредиентов\n3. Вернуться в главное меню" << std::endl;
        int choice = Utils::getIntInput("Введите ваш выбор: ");

        switch (choice) {
        case 1:
            menu.displayMenu();
            break;
        case 2: {
            int id = Utils::getIntInput("Введите ID товара для проверки ингредиентов: ");
            MenuItem* item = menu.findItemById(id);
            if (item) {
                if (checkProductAvailability(menu, item->getIngredients())) {
                    std::cout << "Все ингредиенты в наличии" << std::endl;
                }
                else {
                    std::cout << "Некоторые ингредиенты отсутствуют" << std::endl;
                }
            }
            else {
                std::cout << "Пункт меню не найден" << std::endl;
            }
            break;
        }
        case 3:
            return;
        default:
            std::cout << "Неверный выбор" << std::endl;
        }
    }
}

bool checkProductAvailability(const Menu& menu, const std::vector<Product>& ingredients) {
    for (const auto& ingredient : ingredients) {
        bool found = false;
        for (const auto& product : menu.getProducts()) {
            if (ingredient.getId() == product.getId() && product.getQuantity() >= ingredient.getQuantity()) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}
