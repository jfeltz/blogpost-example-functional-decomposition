#include <string>

/*
  This importable doesn't violate the taxonomy, as it only depends on
  standard library
*/
namespace html {
  using namespace std;

  struct attribute {
    string name;
    string value;
    };

  string encode(const attribute& a) {
    return a.name + "=\"" + a.value + "\"";
    }

  attribute href(string value) {
    return attribute { "href", value };
    }

  attribute id(string value) {
    return attribute { "id", value };
    }
  }
