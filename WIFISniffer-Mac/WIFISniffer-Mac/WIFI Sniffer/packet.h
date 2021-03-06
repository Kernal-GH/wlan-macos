//
//  packet.h
//  WIFISniffer-Mac
//
//  Created by sbxfc on 16/9/12.
//  Copyright © 2016年 me.rungame.sbxfc. All rights reserved.
//

#ifndef packet_h
#define packet_h

#include <sys/types.h>

typedef struct {
    struct {
        unsigned int vers:2;
        unsigned int type:2;
        unsigned int subtype:4;
        unsigned int to_ds:1;
        unsigned int from_ds:1;
        unsigned int more_frag:1;
        unsigned int retry:1;
        unsigned int pw_mg:1;
        unsigned int more_data:1;
        unsigned int encrypted:1;
        unsigned int order:1;
    } __attribute__((__packed__)) frame_control;
    uint16_t durationID;
    unsigned char mac1[6];
    unsigned char mac2[6];
    unsigned char mac3[6];
    uint16_t seqControl;
    // unsigned char mac4[6];
} __attribute__((__packed__)) MACHeader;


/**
 * Logic-link Control 
 */
struct LLC_hdr {
    uint8_t dsap;
    uint8_t ssap;
    uint8_t control_field;
    uint8_t org_code[3];
    uint16_t type;
#define LLC_TYPE_IP 0x0008
};


#endif /* packet_h */
