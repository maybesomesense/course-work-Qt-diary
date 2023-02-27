#include "note.h"

class recipeNote: public note{
private:
    std::string recipeDescription;
    int quantityOfIngredients;
    std::pair<std::string, int> ingredients;
public:
    // геттеры и сеттеры
    std::string getRecipeDescription() const;
    void setRecipeDescription(std::string recipeDescription);

    std::pair<std::string, int> getIngredients() const;
    void setIngredients(std::pair<std::string, int> ingredients);

    int getQuantityOfIngredients() const;
    void setQuantityOfIngredients(int quantityOfIngredients);
    //------------------

    void operator=(recipeNote& object);

    friend istream& operator>>(istream& in, recipeNote& object);
    friend ostream& operator<<(ostream& out, recipeNote& object);


    virtual void edit() {                        //редактирование

        std::cout << "Enter 1 to edit";
        int choice;
        std::cin >> choice;
        if (choice != 1) { return; }                   //отказ редактирования
        while (true) {
            std::cout << "1 - change recipe description" << std::endl
                      << "2 - quantity of ingredients" << std::endl
                      << "0 - end edit" << std::endl;
            string name;
            string date;
            string bDate;
            std::cin >> choice;
            if(choice == 0){break;}
            switch (choice) {                                //выбор действия

                case 1:                                      //изменить название
                    std::cout << "New recipe description: ";
                                                 //строка для ввода
                    cin >> recipeDescription;                             //ввод строки
                    break;
                case 2:                                        //изменить дату
                    std::cout << "New quantity of ingredients: ";
                                                 //строка для ввода
                    cin >> quantityOfIngredients;                             //ввод строки
                    break;
            }
        }
    }
};
