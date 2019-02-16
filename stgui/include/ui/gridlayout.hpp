#pragma once

#include "layout.hpp"

namespace st {
namespace ui {

class GridLayout final : public Layout {
public:
  GridLayout(Widget* parent);

  virtual ~GridLayout() = default;

  void paint() override;
};

}
}
