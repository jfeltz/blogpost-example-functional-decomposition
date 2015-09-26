#include <iostream>
#include <vector>
#include "cnn.hpp"

int main() {
  std::vector<cnn::link> unselected {
    { "/page/us"       , "U.S."     },
    { "/page/world"    , "World"    },
    };

  std::vector<cnn::link> with_selected {
    { "/page/politics" , "Politics" },
    { "/page/health"   , "Health"   }
    };

  std::cout << "cnn-header:" << std::endl;
  std::cout << cnn::header(unselected, with_selected) << std::endl;

  std::move(
    with_selected.begin(),
    with_selected.end(),
    std::back_inserter(unselected));

  std::cout << "cnn-footer: " << std::endl;
  std::cout << cnn::footer(unselected) << std::endl;

  return 0;
  }
