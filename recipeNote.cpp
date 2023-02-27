//
// Created by Asus on 26.11.2022.
//

#include "recipeNote.h"

#include <utility>

std::pair<std::string, int> recipeNote::getIngredients() const {return ingredients;}
void recipeNote::setIngredients(std::pair<std::string, int> ingredients) {this->ingredients = ingredients;}

std::string recipeNote::getRecipeDescription() const{return recipeDescription;}
void recipeNote::setRecipeDescription(std::string recipeDescription) {this->recipeDescription = std::move(recipeDescription);}

int recipeNote::getQuantityOfIngredients() const {return quantityOfIngredients;}

void recipeNote::setQuantityOfIngredients(int quantityOfIngredients) {this->quantityOfIngredients = quantityOfIngredients;}

