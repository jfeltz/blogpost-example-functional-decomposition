#include <vector>
#include "html.hpp"

namespace cnn {
  using namespace html;
  using html = string;

  struct link {
    string url;
    html content;
    };

  attribute to_attribute(const link& l) {
    return href(l.url);
    }

  html to_html(const link& l) {
    return a({ href(l.url) }, l.content);
    }

  html cnn_header(
    const std::vector<link>& unselected,
    const std::vector<link>& with_selected) {

    string table_content;

    auto unsel = std::vector<attribute> { id("unselected") };
    auto sel   = std::vector<attribute> { id("selected") };

      for(auto& u : unselected)
        table_content +=
          td(unsel, a({ id("a-unsel"), href(u.url) }, u.content));

      if(with_selected.size() > 0) {
        table_content +=
          td(sel,
             a({ id("a-sel"), href(with_selected[0].url) },
               with_selected[0].content));

        for(std::size_t i = 1; i < with_selected.size(); i++)
          table_content += td(unsel, to_html(with_selected[i]));
        }

    return table({}, tr({}, table_content));
    }

  html cnn_footer(const std::vector<link>& unselected) {
    auto left  = std::vector<attribute> { id("unbordered") };
    auto right = std::vector<attribute> { id("bordered") };

    string table_content;

    if(unselected.size() > 0) {
      table_content += td(left, to_html(unselected[0]));

      for(std::size_t i = 1; i < unselected.size(); i++)
        table_content += td(right, to_html(unselected[i]));
    }

    return table({}, tr({}, table_content));
  }
} /* cnn */
