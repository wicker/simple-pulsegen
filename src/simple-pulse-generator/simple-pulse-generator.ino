  // AD9833 Waveform Generator
  // Jenner Hanni
  // Wickerbox Electronics


  #include "DDS.h"
#include <SPI.h>

void setup()
{
 pinMode( DDS_FSYNC, OUTPUT );
 digitalWrite( DDS_FSYNC, HIGH );
 Serial.begin(19200);
 SPI.setDataMode( SPI_MODE2 );
 SPI.setClockDivider( SPI_CLOCK_DIV2 );
 SPI.setDataMode( MSBFIRST );
 SPI.begin();
 set_timer1_clock();
 delay( 100 );
 Serial.println( "Set timer1" );
 dds_init();
 Serial.println( "DDS Init" );
 dds_set_frequency(1000);
 Serial.println( "DDS Set frequency" );
}

void loop()
{
 
}

void set_timer1_clock()
{
 // Disable timer1
 TCCR1B = 0;
 
 TCCR1A = _BV(COM1A0);
 OCR1A = 7;
 // Start Timer in CTC mode
 TCCR1B = _BV(WGM12) | 1;
}
