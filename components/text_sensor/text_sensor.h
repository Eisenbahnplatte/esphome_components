#pragma once

#include "esphome/core/component.h"
#include "esphome/core/helpers.h"

namespace esphome {
namespace demo {

class DemoTextSensor : public text_sensor::TextSensor, public PollingComponent {
 public:
  void update() override {
    float val = random_float();
    if (val < 0.33) {
      this->publish_state("foo");
    } else if (val < 0.66) {
      this->publish_state("bar");
    } else {
      this->publish_state("foobar");
    }
  }
};