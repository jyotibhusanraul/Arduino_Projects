/*RFID tag scan code */
 
#include <SPI.h>
#include <MFRC522.h> //Firstly, the SPI bus and MFRC522 libraries are included

#define RST_PIN 9
#define SS_PIN  10  //Secondly, the RST and SDA pins are defined.

MFRC522 mfrc522(SS_PIN, RST_PIN); //an object is created for this library. Also, it includes PINs above

void setup() {
  Serial.begin(9600);
  while (!Serial);
  SPI.begin();
  mfrc522.PCD_Init();
  delay(4);
  mfrc522.PCD_DumpVersionToSerial();
  Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks...")); //In the setup function, the serial monitor, SPI bus, and RFID library are started. 
                                                                            //Also, RFID tags information is printed on the serial monitor
}
//The loop function includes RFID tag read codes
void loop() {
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }
  mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
}
