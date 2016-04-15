#include <Arduino.h>
#include <SPI.h>
#include "DDS.h"

uint16_t control_reg_value = 0;
uint16_t waveform_mode = DDS_SINE;

void dds_write(uint16_t con)
{
 //SPI.setDataMode( SPI_MODE3 );
 digitalWrite( DDS_FSYNC, LOW );
 delay( 10 );
 SPI.transfer( highByte(con) );
 SPI.transfer( lowByte(con) );
 digitalWrite( DDS_FSYNC, HIGH );
 
 //SPI.setDataMode( SPI_MODE0 );
}

void dds_init()
{
 // Set DDS chip into reset.
 dds_write( _BV(DDS_RESET) );
 
 dds_disable_reset();
}

// Frequency is in 100 mHz increments.
void dds_set_frequency(uint32_t freq)
{
 Serial.println( freq );
 int32_t freq_setting = map_frequency(freq );
 Serial.println( freq_setting );
 dds_write( _BV(DDS_B28) | _BV(DDS_RESET) | waveform_mode );
 // Write frequecy LSBs
 dds_write( (int16_t)(0x4000 | (freq_setting&0x3FFF)) );
 // Write frequency MSBs
 dds_write( (int16_t)(0x4000 | ((freq_setting>>14)&0x3FFF)) );
 
 // Write phase register.
 dds_write( 0b1100000000000000 );

 dds_disable_reset();
}

void dds_set_reset()
{
 dds_write( _BV(DDS_B28) | _BV(DDS_RESET) | waveform_mode );
}

void dds_disable_reset()
{
 dds_write( _BV(DDS_B28) | waveform_mode );
}

void dds_set_waveform_mode(uint16_t mode)
{
 waveform_mode = mode;
 dds_write( _BV(DDS_B28) | waveform_mode );
}

uint64_t map_frequency( uint64_t frequency)
{
 return frequency * DDS_F_SETTING_MAX / DDS_MCLK;
}
