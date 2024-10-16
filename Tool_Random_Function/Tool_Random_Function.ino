void function1();     // Function prototypes
void function2();
void function3();
                      // An array of pointers to function
void (*functionPtr[])() = { function1, function2, function3};


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  randomSeed(A0);       // Seed random number generator
}


void loop() {
  long rnd = random(0, 3);
  functionPtr[rnd]();       // Call a function in random sequence
}

void function1()        // The dummy functions
{
  Serial.println("In function1()");
}
void function2()
{
  Serial.println("In function2()");
}
void function3()
{
  Serial.println("In function3()");
}
