#include <Arduino.h>

#include <WiFi.h>
#include <Firebase_ESP_Client.h>
#include <addons/TokenHelper.h>
#include <addons/RTDBHelper.h>

const char* WIFI_SSID = "redxd";
const char* WIFI_PASSWORD= "12345679";


const char* API_KEY= "AIzaSyA27qH92ULZSDeUyTGOV_B_2aUYtGuZEqI";

const char* DATABASE_URL= "https://realtimedb-c1a43-default-rtdb.firebaseio.com"; //<databaseName>.firebaseio.com or <databaseName>.<region>.firebasedatabase.app;

const char* USER_EMAIL= "prueba123@gmail.com";
const char* USER_PASSWORD= "12345678";


FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPrevMillis = 0;

unsigned long count = 0;
 int BUTTON =23;
 int BUTTON2 =22;
 int BUTTON3 =21;
 int BUTTON4 =19;
 int BUTTON5 =18;
 int BUTTON6 =5;

int buttonState = 0;


void setup_WIFI(){
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  unsigned long ms = millis();
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
}

void setupFirebase() {
  config.api_key = "AIzaSyA27qH92ULZSDeUyTGOV_B_2aUYtGuZEqI";
  auth.user.email = "prueba123@gmail.com";
  auth.user.password = "12345678";
  config.database_url = "https://realtimedb-c1a43-default-rtdb.firebaseio.com";
  config.token_status_callback = tokenStatusCallback; // see addons/TokenHelper.h
  config.signer.tokens.legacy_token = "<database secret>";
  Firebase.reconnectNetwork(true);
  fbdo.setBSSLBufferSize(4096, 1024);
  fbdo.setResponseSize(2048);
  Firebase.begin(&config, &auth);
  Firebase.setDoubleDigits(5);
  config.timeout.serverResponse = 10 * 1000;
  Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);

}

void setup() {
    Serial.begin(115200);
    setup_WIFI();
    setupFirebase();
    pinMode(BUTTON,INPUT_PULLUP);
    pinMode(BUTTON2,INPUT_PULLUP);
    pinMode(BUTTON3,INPUT_PULLUP);
    pinMode(BUTTON4,INPUT_PULLUP);
    pinMode(BUTTON5,INPUT_PULLUP);
    pinMode(BUTTON6,INPUT_PULLUP);
    
}


   

 void loop() {
  if (Firebase.ready() && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0))
  {
      if (Firebase.RTDB.setBool(&fbdo, F("/bano"), digitalRead(BUTTON))) {
          Serial.println("Data sent successfully.");
      } else {
          Serial.print("Failed to send data: ");
          Serial.println(fbdo.errorReason().c_str());
      }
  }

  if (Firebase.ready() && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0))
  {
      if (Firebase.RTDB.setBool(&fbdo, F("/cocina"), digitalRead(BUTTON2))) {
          Serial.println("Data sent successfully.");
      } else {
          Serial.print("Failed to send data: ");
          Serial.println(fbdo.errorReason().c_str());
      }
  }

  if (Firebase.ready() && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0))
  {
      if (Firebase.RTDB.setBool(&fbdo, F("/habitacion prin"), digitalRead(BUTTON3))) {
          Serial.println("Data sent successfully.");
      } else {
          Serial.print("Failed to send data: ");
          Serial.println(fbdo.errorReason().c_str());
      }
  }

  if (Firebase.ready() && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0))
  {
      if (Firebase.RTDB.setBool(&fbdo, F("/habitacion2"), digitalRead(BUTTON4))) {
          Serial.println("Data sent successfully.");
      } else {
          Serial.print("Failed to send data: ");
          Serial.println(fbdo.errorReason().c_str());
      }
  }

  if (Firebase.ready() && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0))
  {
      if (Firebase.RTDB.setBool(&fbdo, F("/habitacion3"), digitalRead(BUTTON5))) {
          Serial.println("Data sent successfully.");
      } else {
          Serial.print("Failed to send data: ");
          Serial.println(fbdo.errorReason().c_str());
      }
  }

  if (Firebase.ready() && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0))
  {
      if (Firebase.RTDB.setBool(&fbdo, F("/salon"), digitalRead(BUTTON6))) {
          Serial.println("Data sent successfully.");
      } else {
          Serial.print("Failed to send data: ");
          Serial.println(fbdo.errorReason().c_str());
      }
  }
}







 


