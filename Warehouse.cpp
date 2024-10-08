#include "Warehouse.h"
#include "Ingredient.h"
#include "menuItemInOrder.h"
using namespace std;

Warehouse::Warehouse() : ingredientList(nullptr), ingredientQuantityList(nullptr), numIngredients(0) {}

// Move constructor
Warehouse::Warehouse(Warehouse&& other) noexcept
    : ingredientList(other.ingredientList), ingredientQuantityList(other.ingredientQuantityList), numIngredients(other.numIngredients) {
    other.ingredientList = nullptr;
    other.ingredientQuantityList = nullptr;
    other.numIngredients = 0;
}

// Destructor
Warehouse::~Warehouse() {
    clear();
}

// Move assignment operator
Warehouse& Warehouse::operator=(Warehouse&& other) noexcept {
    if (this != &other) {
        clear();  

        ingredientList = other.ingredientList;
        ingredientQuantityList = other.ingredientQuantityList;
        numIngredients = other.numIngredients;

        other.ingredientList = nullptr;
        other.ingredientQuantityList = nullptr;
        other.numIngredients = 0;
    }
    return *this;
}

// Getters
Ingredient** Warehouse::getIngredientList() const {
    return ingredientList;
}

int* Warehouse::getIngredientQuantityList() const {
    return ingredientQuantityList;
}

// Update ingredient quantity
bool Warehouse::updateIngredientQuantity(const Ingredient* ingredient, int quantity) {
    for (int i = 0; i < numIngredients; ++i) {
        if (compareStrings(ingredientList[i]->getName(), ingredient->getName())) {
            ingredientQuantityList[i] = quantity;
            return true;
        }
    }
    return false;
}

// Add ingredient to warehouse
bool Warehouse::addIngredientToWarehouse(const char* ingredientName, int section) {
    // Create new lists with one additional slot
    Ingredient** newIngredientList = new Ingredient*[numIngredients + 1];
    int* newIngredientQuantityList = new int[numIngredients + 1];

    // Copy existing data to new lists
    for (int i = 0; i < numIngredients; ++i) {
        newIngredientList[i] = ingredientList[i];
        newIngredientQuantityList[i] = ingredientQuantityList[i];
    }

    // Add the new ingredient
    newIngredientList[numIngredients] = new Ingredient(ingredientName, static_cast<Ingredient::eSection>(section), 0);
    newIngredientQuantityList[numIngredients] = 0;

    // Clean up old lists
    delete[] ingredientList;
    delete[] ingredientQuantityList;

    // Assign new lists to class members
    ingredientList = newIngredientList;
    ingredientQuantityList = newIngredientQuantityList;
    numIngredients++;
    print();

    return true;
}

void Warehouse::print() const {
    if (ingredientList && ingredientQuantityList) {
        for (int i = 0; i < numIngredients; ++i) {
            if (ingredientList[i]) {
                ingredientList[i]->print(); // prints the data of every ingridient
                cout << "Quantity: " << ingredientQuantityList[i] << endl;
            }
        }
    }
    else {
        cout << "Warehouse is empty or uninitialized." << endl;
    }
}


// Internal function for memory cleaning
void Warehouse::clear() {
    if (ingredientList) {
        for (int i = 0; i < numIngredients; ++i) {
            delete ingredientList[i]; // deallocate all the aloocated memory in the warehouse
        }
        delete[] ingredientList;
        delete[] ingredientQuantityList;
    }
    ingredientList = nullptr;
    ingredientQuantityList = nullptr;
    numIngredients = 0;
}

// fumction for comparing strings 
bool Warehouse::compareStrings(const char* str1, const char* str2) const {
    while (*str1 && (*str1 == *str2)) {
        ++str1;
        ++str2;
    }
    return *str1 == *str2;
}

// function for finding ingridient by name 
Ingredient* Warehouse::getIngredientByName(const char* ingredientName) const {
    for (int i = 0; i < numIngredients; ++i) {
        if (compareStrings(ingredientList[i]->getName(), ingredientName)) {
            return ingredientList[i];
        }
    }
    return nullptr;
}
