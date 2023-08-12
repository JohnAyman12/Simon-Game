#define led1 2
#define led2 3
#define led3 4
#define led4 5
#define btn1 7
#define btn2 8
#define btn3 9
#define btn4 10

int seq[10];
int userIn[10];
int score = 0;
int ledCount = 0;
int userCount = 0;
int time = 0;
bool answer;
int level;
int speed;

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  pinMode(btn4, INPUT);
  Serial.println("Select Difficulty. Type 1 for easy, 2 for medium and 3 for hard.");
  delay(5000);
  level = Serial.read();
  switch (level) {
    case 50:
      speed = 750;
      break;
    case 51:
      speed = 500;
      break;
    default:
      speed = 1000;
      break;
  }
}

void loop() {
  if (ledCount < 10) {
    delay(2000);
    Serial.println("Level:");
    Serial.println(ledCount + 1);
    seq[ledCount] = random(2, 6);
    for (int i = 0; i <= ledCount; i++) {
      digitalWrite(seq[i], 1);
      delay(speed);
      digitalWrite(seq[i], 0);
      delay(speed);
    }
    ledCount++;
    Serial.println("Enter your answer.");
    time = millis();
    while (millis() - time < 5000 && userCount < ledCount) {
      if (digitalRead(btn1)) {
        Serial.println("btn1");
        userIn[userCount] = 2;
        time = millis();
        userCount++;
        delay(100);
      }
      if (digitalRead(btn2)) {
        Serial.println("btn2");
        userIn[userCount] = 3;
        time = millis();
        userCount++;
        delay(200);
      }
      if (digitalRead(btn3)) {
        Serial.println("btn3");
        userIn[userCount] = 4;
        time = millis();
        userCount++;
        delay(200);
      }
      if (digitalRead(btn4)) {
        Serial.println("btn4");
        userIn[userCount] = 5;
        time = millis();
        userCount++;
        delay(200);
      }
    }
    for (int i = 0; i < userCount; i++) {
      if (userIn[i] != seq[i]) {
        answer = false;
      } else {
        answer = true;
      }
    }
    if (answer) {
      score++;
      Serial.println("Right! score:");
      Serial.println(score);
    } else {
      Serial.println("Wrong sequence, Score:");
      Serial.println(score);
    }
    userCount = 0;
    for (int i = 0; i < 10; i++) {
      userIn[i] = 0;
    }
    Serial.println("Next Level");
  }
}