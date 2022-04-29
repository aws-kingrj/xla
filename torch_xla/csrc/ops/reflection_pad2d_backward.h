#pragma once

#include <vector>

#include "torch_xla/csrc/ir.h"

namespace torch_xla {

class ReflectionPad2dBackward : public XlaNode {
 public:
  ReflectionPad2dBackward(const XlaValue& gard_output, const XlaValue& input,
                          std::vector<int64_t> padding);

  torch::lazy::NodePtr Clone(OpList operands) const override;

  XlaOpVector Lower(LoweringContext* loctx) const override;

  std::string ToString() const override;

  const std::vector<int64_t>& padding() const { return padding_; }

 private:
  std::vector<int64_t> padding_;
};

}  // namespace torch_xla
