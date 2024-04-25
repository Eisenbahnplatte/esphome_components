#include "mynamespace_sensor.h"
#include "esphome/core/log.h"
#include <cmath>

namespace esphome {
namespace mynamespace_ {

static const char *const TAG = "mynamespace.sensor";

void MyNamespaceSensor::update() {
  if (!this->f_.has_value())
    return;

  auto val = (*this->f_)();
  if (val.has_value()) {
    this->publish_state(*val);
  }
}
float MyNamespaceSensor::get_setup_priority() const { return setup_priority::HARDWARE; }
void MyNamespaceSensor::set_mynamespace(std::function<optional<float>()> &&f) { this->f_ = f; }
void MyNamespaceSensor::dump_config() {
  LOG_SENSOR("", "MyNamespace Sensor", this);
  LOG_UPDATE_INTERVAL(this);
}

}  // namespace mynamespace_
}  // namespace esphome
