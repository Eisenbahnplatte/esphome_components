#include "esphome.h"


namespace esphome {
namespace my_external_component{

class MyTestExternalComponent : public PollingComponent, public Sensor {
 public:
  // constructor
  MyTestExternalComponent() : PollingComponent(15000) {}

  float get_setup_priority() const override { return esphome::setup_priority::HARDWARE; }

  void setup() override {
    // This will be called by App.setup()
  }
  void update() override {
    publish_state("77.0");
  }
};

}
}