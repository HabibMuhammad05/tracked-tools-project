
uint8_t buzpin = D5;
 
void satu(int on, int off){ 
  tone(buzpin,264);
  delay(on);
  noTone(buzpin);
  delay(off);}
void dua(int on, int off){ 
  tone(buzpin,297);
  delay(on);
  noTone(buzpin);
  delay(off);}  //Re 
void tiga(int on, int off){ 
  tone(buzpin,330);
  delay(on);
  noTone(buzpin);
  delay(off);}  //Mi 
void empat(int on, int off){ 
  tone(buzpin,352);
  delay(on);
  noTone(buzpin);
  delay(off);}  //Fa
void lima(int on, int off){ 
  tone(buzpin,396);
  delay(on);
  noTone(buzpin);
  delay(off);} //Sol 
void enam(int on, int off){ 
  tone(buzpin,440);
  delay(on);
  noTone(buzpin);
  delay(off);}  //La
void tujuh(int on, int off){ 
  tone(buzpin,495);
  delay(on);
  noTone(buzpin);
  delay(off);}  //Si
void delapan(int on, int off){ 
  tone(buzpin,528);
  delay(on);
  noTone(buzpin);
  delay(off);} //12
void notone() { noTone(buzpin); }
