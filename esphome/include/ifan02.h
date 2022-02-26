#include "esphome.h"
using namespace esphome;

class IFan02Output : public Component, public FloatOutput {
  public:
    void write_state(float state) override {
      if (state < 0.3) {
        // OFF
        digitalWrite(5, LOW);
        digitalWrite(4, LOW);
        digitalWrite(15, LOW);
      } else if (state < 0.6) {
        // low speed
        digitalWrite(5, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(15, LOW);
      } else if (state < 0.9) {
        // medium speed
        digitalWrite(5, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(15, LOW);
      } else {
        // high speed
        digitalWrite(5, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(15, HIGH);
      }
    }
};