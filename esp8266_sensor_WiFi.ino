#include <ESP8266WiFi.h>

#define trigPin D3
#define echoPin D2
 
const char* ssid = "/* Set ssid here ** */";
const char* password = "/* Set password here ** */";
 
WiFiServer server(50007);
 
void setup() {
  Serial.begin(9600);
  delay(10);

  pinMode(trigPin, OUTPUT);       // trigger -> output
  pinMode(echoPin, INPUT);        // echo -> input
 
  // Connect to WiFi network
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL : ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
 
}
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("\nnew client");

  // Return the response
  int v = measure();
  client.println(v);

 
  delay(1);
  Serial.println("Client disconnected");
  Serial.println("");
}


int measure() {
  int tim, avg = 0;
  int measurements[5];

  for (int i=0; i<5; i++) {
    delay(100);
    digitalWrite(trigPin, LOW);     // Start measure
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);     // Measure execute
    
    tim = pulseIn(echoPin, HIGH);   // Get data from echo pin
    measurements[i] = tim / 58;
    Serial.print("Measure: ");
    Serial.print(i);
    Serial.print(" -> ");
    Serial.println(measurements[i]);
  }

  for (int i=0; i<5; i++) 
  avg += measurements[i];
  return avg / 5;
}