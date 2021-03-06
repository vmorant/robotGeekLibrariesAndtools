/*****************************************************************************************
 *    RG 101 - Serial Communication     ______
 *    Number Guesser Game              | >_   |   
 *                                     |      |   
 *                                     |______|   
 *                                                 
 *                              
 *  This code will genrerate a random number and prompt you to guess the number via 
 *  the serial monitor.
 *  
 * 
 *    
 * For a more in depth explanation of wiring,  this code and more information on using 
 * serial communication and Arduino check out ourserial communication tutorial
 * http://learn.robotgeek.com/robotgeek-101-1/245-robotgeek-101-serial-communication.html
 *  
 * Important Functions
 *  Serial.begin()
 *  Serial.println()
 *  Serial.available()
 *  Serial.parseInt()
 *  rand()
 *****************************************************************************************/

int randomNumber;      //the random number that the user is trying to guess
int guess;             //the last guess the user entered

//setup runs once when the Geekduino/Arduino is turned on
void setup()
{

  randomSeed(analogRead(7));        //seed the random number generator based on a 'random' reading from an unconnected analog input
  randomNumber = random(1001);   //generate a random number

  Serial.begin(9600);                                               //start the Serial port at a baud rate of 9600 bits per second (bps)
  
  //print prompts  
  Serial.println("Hello! Please enter a number between 0 and 1000. "); 
  
  //uncomment the next 2 lines if you want to see the random number for debugging
  //Serial.print("Random: "); 
  //Serial.println(randomNumber); 

  
} //setup() is done, go to loop()

//loop runs forever once setup is complete
void loop()
{
  //check is there are any characters incoming on the serial buffer.
  if(Serial.available() > 0)
  {
    guess = Serial.parseInt(); //Serial.parseInt is an advanced version of Serial.read(). Serial.parseInt() reads several characters and trys to create an integer out of them. This operation takes longer than a standard Serial.read() which just reads one character at a time
    
    Serial.print("You Guessed: ");  //print static text
    Serial.println(guess); //print the data that was recieved

    if(guess > randomNumber)
    {
      Serial.println("You Guess is too high");  //print static text
    }    
    else if(guess < randomNumber)
    {
      Serial.println("You Guess is too low");  //print static text
    }
    else if(guess == randomNumber)
    {
      Serial.println("You guessed correctly!");  //print static text
    }
  }

}//go back to the first line in loop()

