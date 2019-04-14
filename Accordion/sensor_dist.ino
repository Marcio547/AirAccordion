    /*
    * Validaço de Ideia sensor Ultrassonico
    * Emulaçao de fole de uma sanfona    *

    */
    // defines pins numbers
    const int trigPin = 8;
    const int echoPin = 7;
    const int plusLed = 10;
    const int minusLed = 11;
    const int zeroLed = 12;
    int d1=0;
    int d2=0;
    int dif=0;

    // defines variables
    long duration;
    int distance;
    void setup() {
      
    pinMode(plusLed, OUTPUT);
    pinMode(minusLed, OUTPUT);
    pinMode(zeroLed, OUTPUT);
      
      
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
    Serial.begin(9600); // Starts the serial communication
    }
    void loop() {

    d1 = calc_distance();
    //Serial.print("Distance[t] ");
    //Serial.println(d1);
    
    delay(100);
    
    d2  = calc_distance();
    //Serial.print("Distance[t+1]: ");
    //Serial.println(d2);
    
    
    dif = d2-d1;
    Serial.print("Variation d2-d1: ");
    Serial.println(dif);
    
    if(dif > 0){
      digitalWrite(plusLed, HIGH);
      digitalWrite(minusLed,LOW);
      digitalWrite(zeroLed,LOW);
    }
    else if(dif < 0){
      digitalWrite(minusLed,HIGH);
      digitalWrite(plusLed,LOW); 
     digitalWrite(zeroLed,LOW); 
    }
    //else if(dif >= -5 && dif <= 5 )
    else if (dif ==0){
      digitalWrite(zeroLed,HIGH);
      digitalWrite(minusLed,LOW);
      digitalWrite(plusLed,LOW); 
      
    }
    
    /*
    if(dif > 10){
      digitalWrite(plusLed, HIGH);
      digitalWrite(minusLed,LOW);
    }
    else if(dif < -10 && dif != 0){
      digitalWrite(minusLed,HIGH);
      digitalWrite(plusLed,LOW);  
    }
    else if(dif == 0)
      digitalWrite(minusLed,LOW);
      digitalWrite(plusLed,LOW); 
      digitalWrite(zeroLed,HIGH);
    }
    */
    int calc_distance(){
    int d_mm;
      //sensor reading at some time instant
    // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    
    // sound velocity = 340 m/s
    // divided by 2 because the pulse walks twice the distance.
    distance= duration*0.034/2;
    
    //measure in milimeters
    d_mm = distance*100;
    // Prints the distance on the Serial Monitor
    return distance;
    
    }
      
      
      
