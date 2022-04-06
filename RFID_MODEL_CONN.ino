//includes the SPI Bus Library and the MFRC 522 Library. Also, RST, SDA, Buzzer, and LED pins are defined.
#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9
//#define Buzzer 2
#define LED1 3
//#define LED2 4

//an object is created for this library. Also, it includes RST and SDA PINs
MFRC522 rfid(SS_PIN, RST_PIN);

byte led1 = 0;
//byte led2 = 0;


//In the setup function, the serial monitor, SPI bus, and RFID library are started. Also, the LED and buzzer pins are set as OUTPUT pins.
void setup() {
  Serial.begin(9600);
  Serial.println("Please put your card..");
  SPI.begin();
  rfid.PCD_Init();
  pinMode(LED1, OUTPUT);
  //pinMode(LED2, OUTPUT);
 // pinMode(Buzzer, OUTPUT);
}


//In loop functions, the main code of this project is included. 
//The first part of this code reads the RFID tag. Then, these RFID tag UIDs are inserted into a string variable
void loop() {
  if ( ! rfid.PICC_IsNewCardPresent())
    return;
  if ( ! rfid.PICC_ReadCardSerial())
    return;

  Serial.print("NUID tag is :");
  //tone(Buzzer, 700);
  //delay(200);
  //noTone(Buzzer);
  String ID = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(rfid.uid.uidByte[i], HEX);
    ID.concat(String(rfid.uid.uidByte[i] < 0x10 ? " 0" : " "));
    ID.concat(String(rfid.uid.uidByte[i], HEX));
    delay(300);
  }
  Serial.println();
  ID.toUpperCase();

//Next, the second part of this code tests this UID using the IF condition. 
//Also, we need to paste the previously copied RFID tag UIDs into this code. For that, use your RFID tag UIDs.

  if (ID.substring(1) == "90 B2 BA 43" && led1 == 0 ) {
    digitalWrite(LED1, HIGH);
    Serial.println("LIGHT IS ON NOW..");
    led1 = 1;
  } else if (ID.substring(1) == "90 B2 BA 43" && led1 == 1 ) {
    digitalWrite(LED1, LOW);
    Serial.println("LIGHT IS OFF NOW..");
    led1 = 0;
//  } else if (ID.substring(1) == "D1 0D 16 21" && led2 == 0 ) {
//    digitalWrite(LED2, HIGH);
//    Serial.println("LED2 is ON..");
//    led2 = 1;
//  } else if (ID.substring(1) == "D1 0D 16 21" && led2 == 1 ) {
//    digitalWrite(LED2, LOW);
//    Serial.println("LED2 is OFF..");
//    led2 = 0;
  } else {
    Serial.print("Wrong card!Please put correct card!");
  }
}
