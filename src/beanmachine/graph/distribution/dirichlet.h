/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once
#include "beanmachine/graph/distribution/distribution.h"

namespace beanmachine {
namespace distribution {

class Dirichlet : public Distribution {
 public:
  Dirichlet(
      graph::ValueType sample_type,
      const std::vector<graph::Node*>& in_nodes);
  ~Dirichlet() override {}
  Eigen::MatrixXd _matrix_sampler(std::mt19937& gen) const override;
  double log_prob(const graph::NodeValue& value) const override;
  void log_prob_iid(
      const graph::NodeValue& /* value */,
      Eigen::MatrixXd& /* log_probs */) const override;
  void gradient_log_prob_value(
      const graph::NodeValue& /*value*/,
      double& /*grad1*/,
      double& /*grad2*/) const override {}
  void gradient_log_prob_param(
      const graph::NodeValue& /*value*/,
      double& /*grad1*/,
      double& /*grad2*/) const override {}
  void backward_value(
      const graph::NodeValue& value,
      graph::DoubleMatrix& back_grad,
      double adjunct = 1.0) const override;
  void backward_param(const graph::NodeValue& value, double adjunct = 1.0)
      const override;
};

} // namespace distribution
} // namespace beanmachine
