/*
  Showing number 0-9 on a Common Anode 7-segment LED display
  Displays the numbers 0-9 on the display, with one second inbetween.
    A
   ---
F |   | B
  | G |
   ---
E |   | C
  |   |
   ---
    D
  This example code is in the public domain.
 */
 
// Pin 2-8 is connected to the 7 segments of the display.

 int pinA = 11;
  int pinB = 12;
  int pinC = A3;
  int pinD = A4;
  int pinE = A5;
  int pinF = 10;
  int pinG = 9;
  int pinDP = A2;
  int a1K = 2;
  int a1S = 3;
  int a1Y = 4;
  int a2K = 13;
  int a2S = 8;
  int a2Y = 7;
  int buton1=5;
  int buton2=A1;
  int sayac1=0;
  int sayac2=0; 
  int butonDurumu1=0;
  int butonDurumu2=0;
 
int q=1;
void setup() {                
  // initialize the digital pins as outputs.

  Serial.begin(9600); //Serial portu buton a kaç defa basıldığını görmek için kullandım

  
  pinMode(pinA,OUTPUT);
  pinMode(pinB,OUTPUT);
  pinMode(pinC,OUTPUT);
  pinMode(pinD,OUTPUT);
  pinMode(pinE,OUTPUT);
  pinMode(pinF,OUTPUT);
  pinMode(pinG,OUTPUT);
  pinMode(a1K,OUTPUT);
  pinMode(a1S,OUTPUT);
  pinMode(a1Y,OUTPUT);
  pinMode(a2K,OUTPUT);
  pinMode(a2S,OUTPUT);
  pinMode(a2Y,OUTPUT);
  pinMode(buton1, INPUT);
  pinMode(buton2, INPUT);
   
}

void loop()
{
  if (q==1)
  {
  digitalWrite(a1K,HIGH);
  digitalWrite(a2Y,HIGH);
  display();
  digitalWrite(a1K,LOW);
  digitalWrite(a2Y,LOW);
  digitalWrite(a1S,HIGH);
  digitalWrite(a2S,HIGH);
  delay(3000);
  digitalWrite(a1S,LOW);
  digitalWrite(a2S,LOW);
  digitalWrite(a1Y,HIGH);
  digitalWrite(a2K,HIGH); 
  delay(10000);
  digitalWrite(a1Y,LOW);
  digitalWrite(a2K,LOW);   
  digitalWrite(a1S,HIGH);
  digitalWrite(a2S,HIGH);
  delay(3000);
  digitalWrite(a1S,LOW);
  digitalWrite(a2S,LOW);
  
  
  }
  q++;
  butonDurumu1=digitalRead(buton1); //Butona basılıp basılmadığını okuyorum.
  if(butonDurumu1==HIGH) //Eğer butona basılmışsa
  {
    sayac1=sayac1+1; //sayacım 1 artacak
    Serial.println(sayac1); //Ekrana sayac değerini basacak
    if(sayac1==4) //Eğer sayac 1 ise
    {
  digitalWrite(a1K,HIGH);
  digitalWrite(a2Y,HIGH);
  display();
  digitalWrite(a1K,LOW);
  digitalWrite(a2Y,LOW);


    }

    else if (sayac1==5) // Eğer sayac 2 ise
    {
  
    digitalWrite(a1Y,HIGH);
    digitalWrite(a2K,HIGH); 
  delay(10000);
  digitalWrite(a1Y,LOW);
  digitalWrite(a2K,LOW);
  
    sayac1=0;
    
    }
  


  }

  q++;
  butonDurumu2=digitalRead(buton2); //Butona basılıp basılmadığını okuyorum.
  if(butonDurumu2==HIGH) //Eğer butona basılmışsa
  {
    sayac2=sayac2+1; //sayacım 1 artacak
    Serial.println(sayac2); //Ekrana sayac değerini basacak
    if(sayac2==4) //Eğer sayac 1 ise
    {
  digitalWrite(a2K,HIGH);
  digitalWrite(a1Y,HIGH);
  delay(10000);
  digitalWrite(a2K,LOW);
  digitalWrite(a1Y,LOW);


    }

    else if (sayac2==5) // Eğer sayac 2 ise
    {
  
  digitalWrite(a2Y,HIGH);
  digitalWrite(a1K,HIGH);
  delay(10000);
  digitalWrite(a2Y,LOW);
  digitalWrite(a1K,LOW);
    sayac2=0;
    
    }
  


  }
  
  while(butonDurumu1==HIGH) //buton durumu 1 ise
  {
  delay(10); //10ms bekle
  butonDurumu1=digitalRead(buton1); //butonu tekrar oku
  //Bu işlemi yapma amacımız butona bir kere basıldığında program çok hızlı bir şekilde döndüğü için defalarca kez basılmış gibi algıyabiliriz. Dolayısıyla buton bir kere high olduğunda bu loop a girecek ve buton low olana kadar bu loop içerisinden çıkmayacak
  }
  
  while (butonDurumu1==LOW)//Buton Low ise
  {
  delay(10); //10ms bekle
  butonDurumu1=digitalRead(buton1); //Butonu tekrar oku
  //Buton HIGH olana kadar bu loop içerisinde kalacak. Hıgh olduğundaysa void loop un ilk satırına tekrar dönecek.
  }

  while(butonDurumu2==HIGH) //buton durumu 1 ise
  {
  delay(10); //10ms bekle
  butonDurumu2=digitalRead(buton2); //butonu tekrar oku
  //Bu işlemi yapma amacımız butona bir kere basıldığında program çok hızlı bir şekilde döndüğü için defalarca kez basılmış gibi algıyabiliriz. Dolayısıyla buton bir kere high olduğunda bu loop a girecek ve buton low olana kadar bu loop içerisinden çıkmayacak
  }
  
  while (butonDurumu2==LOW)//Buton Low ise
  {
  delay(10); //10ms bekle
  butonDurumu2=digitalRead(buton2); //Butonu tekrar oku
  //Buton HIGH olana kadar bu loop içerisinde kalacak. Hıgh olduğundaysa void loop un ilk satırına tekrar dönecek.
  }


  
  
}



void display(){ 
  

  //9
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);   
  delay(1000);               // wait for a second
  
  //8
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);   
  delay(1000);               // wait for a second
  
  //7
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);     
  delay(1000);    // wait for a second
  
  //6
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);     
  delay(1000);               // wait for a second

  //5
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);     
  delay(1000);               // wait for a second
  
  //4
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);     
  delay(1000);               // wait for a second
  
  //3
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, LOW);     
  delay(1000);               // wait for a second
  
  //2
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, LOW);     
  delay(1000);               // wait for a second
  
  //1
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);     
  delay(1000);               // wait for a second

  //0
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);     
  delay(1000); 

}
