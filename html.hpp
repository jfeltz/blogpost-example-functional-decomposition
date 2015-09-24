#include <string>
#include <vector>
#include "html/attribute.hpp"

namespace html {
  using namespace std;
  using html = string;

  html tag(
    const string& name,
    const std::vector<attribute>& attrs,
    const html& content) {

    string attributes;

    for (auto& a : attrs)
      attributes += " " + encode(a);

    return "<" + name + attributes + ">" + content + "</" + name + ">";
  }

  html a(const std::vector<attribute>& attrs, const html& content) {
    return tag("a", attrs, content);
  }

  html td(const std::vector<attribute>& attrs, const html& content) {
    return tag("td", attrs, content);
  }

  html tr(const std::vector<attribute>& attrs, const html& content) {
    return tag("tr", attrs, content);
  }

  html table(const std::vector<attribute>& attrs, const html& content) {
    return tag("table", attrs, content);
  }
}
