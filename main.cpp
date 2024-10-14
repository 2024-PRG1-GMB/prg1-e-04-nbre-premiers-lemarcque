/**
* \file main.cpp
 * \version 1.0.0
 * \author Henok SESE
 * \date : 8.10.2024
 * \brief : Calculate prime number in range
 */

#include <iomanip>
#include <iostream>

int main()
{
  std::cout << "Ce programme détermine tous les nombres premiers compris entre 1 et une valeur saisie à votre choix." << std::endl;

  bool restart = false;

  do {
    // Ask the user to choose the max prime number to calculate until
    int max_prime_number;
    std::string user_input;

    // Get the limit number
    // note : it does not check
    do {
      std::cout << "Entrez une valeur [2-1000] : ";
      std::cin >> max_prime_number;
      if (std::cin.fail()) {
        std::cout << "I failed, try again ..." << std::endl;
        std::cin.clear();
      }

    }while(max_prime_number < 2 || max_prime_number > 1000);

    std::cout << "Voici la liste des nombres premiers" << std::endl;

    // Calculate all prime number between a range
    // using the primality test
    int col_display_offset = 0;
    for(int i = 2; i <= max_prime_number; i++) {
      bool is_prime = true;
      for(int j = 2; j <= i; j++) {
        if(i % j == 0 && i != j) {
          is_prime = false;
          break;
        }
      }

      if (!is_prime) continue;

      // Display the number
      std::cout << i;
      if(col_display_offset < 4) {
        std::cout << std::setw(5);
        ++col_display_offset;
      } else {
        col_display_offset = 0;
        std::cout << std::endl;
      }
    }

    // Add more space for readability
    std::cout << std::endl;

    bool input_valid = false;

    do {
      std::cout << "Voulez-vous recommencer [O/N]: ";
      char response;
      std::cin >> response;
      restart = std::tolower(response) == 'o';
      input_valid = (char) std::tolower(response) != 'o' && (char) std::tolower(response) != 'n';
    }while(input_valid);
  }while (restart);

  return EXIT_SUCCESS;
}
