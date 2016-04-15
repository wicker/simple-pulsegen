#ifndef DDS_H
#define DDS_H

#include <stdint.h>

#define DDS_F_SETTING_MAX 0xFFFFFFFL
#define DDS_MCLK 1000000L

#define DDS_B28 13
#define DDS_HLB 12
#define DDS_FSELECT 11
#define DDS_PSELECT 10
#define DDS_RESET 8
#define DDS_SLEEP1 7
#define DDS_SLEEP12 6
#define DDS_OPBITEN 5
#define DDS_DIV2 3
#define DDS_MODE 1

#define DDS_FSYNC 9

#define DDS_SINE (0)
#define DDS_TRIANGLE (_BV(DDS_MODE))
#define DDS_SQUARE (_BV(DDS_OPBITEN))

void dds_write_control_reg(uint16_t);

void dds_init();
void dds_set_frequency(uint32_t);
void dds_set_reset();
void dds_disable_reset();

void dds_set_waveform_mode(uint16_t);

uint64_t map_frequency( uint64_t );

#endif
