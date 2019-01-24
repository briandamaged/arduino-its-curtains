


class Curtain {
  private:
    const int activation_pin;
    const int direction_pin;
    const int stopper_pin;
  
  public:
  
    Curtain(const int activation_pin, const int direction_pin, const int stopper_pin):
      activation_pin(activation_pin),
      direction_pin(direction_pin),
      stopper_pin(stopper_pin)
    {
      this->attach();
    };

    void attach() {
      pinMode(this->activation_pin, OUTPUT);
      pinMode(this->direction_pin, OUTPUT);
      pinMode(this->stopper_pin, INPUT);

      this->stop();
    }


    void update() {
      const int stopper_state = digitalRead(this->stopper_pin);
      if(stopper_state == HIGH) {
        // Serial.println("Pressed");
        this->stop();
      }
    }

    void open() {
      digitalWrite(this->direction_pin, HIGH);
      digitalWrite(this->activation_pin, HIGH);
    }
  
    void close() {
      digitalWrite(this->direction_pin, LOW);
      digitalWrite(this->activation_pin, HIGH);
    }
  
    void stop() {
      digitalWrite(this->activation_pin, LOW);
    }
};



Curtain left = Curtain(2, 4, 7);


const int OPEN_BUTTON = 9;
const int CLOSE_BUTTON = 8;


void setup() {
  pinMode(OPEN_BUTTON, INPUT);
  pinMode(CLOSE_BUTTON, INPUT);

  Serial.begin(9600);
}


void loop() {
  left.update();

  if(digitalRead(CLOSE_BUTTON) == HIGH) {
    left.close();
  }

  if(digitalRead(OPEN_BUTTON) == HIGH) {
    left.open();
  }
}
