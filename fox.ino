#include <Tone.h>

int relay = 10; //pin for relay
int message[] = {5,4, 6,8, 6,9, 7,3, 2,0, 6,9, 7,3, 2,0, 7,4, 6,8, 6,5, 2,0, 5,3, 6,5, 6,3, 7,2, 6,5, 7,4, 2,0, 6,13, 6,5, 7,3, 7,3, 6,1, 6,7, 6,5, 2,1, 2,1, 2,1};
  
Tone freq1;
Tone freq2;

const int DTMF_freq1[] = { 1336, 1209, 1336, 1477, 1209, 1336, 1477, 1209, 1336, 1477, 1633, 1633, 1633, 1633, 1209, 1447 };
const int DTMF_freq2[] = {  941, 697,  697,  697,  770,  770,  770,  852,  852,  852, 697, 770, 852, 941, 941, 941 };
//0-9,A-D,*,#

int array[] = { 4, 3, 3, 4, 3, 7, 4, 2, 5, 5, 4, 7 };


void setup()
{
  freq1.begin(3);
  freq2.begin(5);
  pinMode(relay,OUTPUT);
}

void playDTMF(uint8_t number, long duration)
{
  freq1.play(DTMF_freq1[number], duration);
  freq2.play(DTMF_freq2[number], duration);
}


void loop()
{
  for(uint8_t i = 0; i < sizeof(array); i ++)
  {
    digitalWrite(relay,HIGH);  //turn relay on
    delay(100);
    playDTMF(message[array[i]], 80);
    delay(100);
    digitalWrite(relay,LOW); //turn relay off
  }
  delay(30000);
}
