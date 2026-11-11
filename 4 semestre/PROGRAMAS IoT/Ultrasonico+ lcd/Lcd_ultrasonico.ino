#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Ultrasonic.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // Endereço I2C e tamanho do LCD
Ultrasonic ultrasonic(3, 4);       // Pinos TRIG e ECHO
int distance;

void setup() {
  Serial.begin(9600);
  lcd.init();                      // Inicializa o LCD uma vez
  lcd.backlight();                 // Liga a luz de fundo
}

void loop() {
  distance = ultrasonic.read();   // Lê a distância

  lcd.clear();                    // Limpa o conteúdo anterior
  lcd.setCursor(0, 0);
  lcd.print("Distance in CM:");
  lcd.setCursor(0, 1);
  lcd.print(distance);

  Serial.print("Distance in CM: ");
  Serial.println(distance);

  delay(500);                     // Pequeno atraso para melhor leitura
}
