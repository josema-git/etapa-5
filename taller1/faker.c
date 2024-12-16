#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libnet.h>
#include <net/ethernet.h>

#define SRC_MAC "\xA0\x36\xBC\xAA\x82\xbc"
#define SRC_IP "192.168.1.139"

#define DST_MAC "\xA0\x36\xBC\xAA\x88\x49"
#define DST_IP "192.168.1.166"
#define DST_PORT 9000

#define MESSAGE "yo si\n"

#define SRC_PORT 36964  
#define SEQ 0x39fddf85 + 38
#define ACK 0x69c622d8
#define ID 0x2064 +2

int main() {
    libnet_t *l;
    char errbuf[LIBNET_ERRBUF_SIZE];
    
    l = libnet_init(LIBNET_LINK, NULL, errbuf);
    if (l == NULL) {
        fprintf(stderr, "libnet_init() failed: %s\n", errbuf);
        exit(1);
    }

    u_int32_t src_ip = libnet_name2addr4(l, SRC_IP, LIBNET_RESOLVE);
    u_int32_t dst_ip = libnet_name2addr4(l, DST_IP, LIBNET_RESOLVE);

    libnet_ptag_t tcp = libnet_build_tcp(
        SRC_PORT,
        DST_PORT,
        SEQ,
        ACK,
        TH_PUSH | TH_ACK,
        502,
        0,
        0,
        LIBNET_TCP_H + strlen(MESSAGE),
        (u_int8_t*)MESSAGE,
        strlen(MESSAGE),
        l,
        0
    );

    if (tcp == -1) {
        fprintf(stderr, "Error building TCP header: %s\n", libnet_geterror(l));
        libnet_destroy(l);
        exit(1);
    }

    libnet_ptag_t ip = libnet_build_ipv4(
        LIBNET_IPV4_H + LIBNET_TCP_H + strlen(MESSAGE),
        0,
        ID,
        0,
        64,
        IPPROTO_TCP,
        0,
        src_ip,
        dst_ip,
        NULL,
        0,
        l,
        0
    );

    if (ip == -1) {
        fprintf(stderr, "Error building IP header: %s\n", libnet_geterror(l));
        libnet_destroy(l);
        exit(1);
    }

    libnet_ptag_t eth = libnet_build_ethernet(
        (u_int8_t*)DST_MAC,
        (u_int8_t*)SRC_MAC,
        ETHERTYPE_IP,
        NULL,
        0,
        l,
        0
    );

    if (eth == -1) {
        fprintf(stderr, "Error building Ethernet header: %s\n", libnet_geterror(l));
        libnet_destroy(l);
        exit(1);
    }

    int bytes_written = libnet_write(l);
    if (bytes_written == -1) {
        fprintf(stderr, "Error sending packet: %s\n", libnet_geterror(l));
    } else {
        printf("Data packet sent successfully (%d bytes)\n", bytes_written);
    }

    libnet_destroy(l);
    return 0;
}