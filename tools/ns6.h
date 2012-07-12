/*
 * Header file for the ns6 tool
 *
 */

#define LUI		long unsigned int

#define ETH_ALEN	6		/* Octets in one ethernet addr	 */
#define ETH_HLEN	14		/* Total octets in header.	 */
#define ETH_DATA_LEN	1500		/* Max. octets in payload	 */
#define	ETHERTYPE_IPV6	0x86dd		/* IP protocol version 6 */
#define	ETHER_ADDR_LEN	ETH_ALEN	/* size of ethernet addr */
#define	ETHER_HDR_LEN	ETH_HLEN	/* total octets in header */
#define	ETHERMTU	ETH_DATA_LEN

#define ETHER_ADDR_PLEN	18 /* Includes termination byte */

#define ETHER_ALL_NODES_LINK_ADDR	"33:33:00:00:00:01"
#define ETHER_ALL_ROUTERS_LINK_ADDR	"33:33:00:00:00:02"

#define	MIN_IPV6_HLEN		40
#define	SLLA_OPT_LEN		1

#define IFACE_LENGTH	255

#define MAX_SLLA_OPTION		100
#define ALL_NODES_MULTICAST_ADDR	"FF02::1"
#define ALL_ROUTERS_MULTICAST_ADDR	"FF02::2"

/* Support for IPv6 extension headers */
#define	MAX_IPV6_PAYLOAD	65535
#define FRAG_HDR_SIZE		8
#define MAX_DST_OPT_HDR		256
#define MAX_DST_OPT_U_HDR	MAX_DST_OPT_HDR
#define MAX_HBH_OPT_HDR		MAX_DST_OPT_HDR

/* Constants used with the libpcap functions */
#define PCAP_SNAP_LEN		65535
#define	PCAP_TIMEOUT			1
#define	PCAP_PROMISC			1
#define	PCAP_OPT				1
#ifndef PCAP_NETMASK_UNKNOWN
	#define PCAP_NETMASK_UNKNOWN	0xffffffff
#endif
#define PCAP_NOPACKETS_FILTER	"not ip and not ip6 and not arp"

struct ether_addr{
  u_int8_t a[ETHER_ADDR_LEN];
} __attribute__ ((__packed__));


struct	nd_opt_slla{
    u_int8_t	type;
    u_int8_t	length;
    u_int8_t	address[6];
} __attribute__ ((__packed__));

struct ipv6pseudohdr{
    struct in6_addr srcaddr;
    struct in6_addr dstaddr;
    u_int32_t	len;
    u_int8_t zero[3];
    u_int8_t	nh;
} __attribute__ ((__packed__));

/* 10Mb/s ethernet header */
struct ether_header
{
  struct ether_addr dst;	/* destination eth addr	*/
  struct ether_addr src;	/* source ether addr	*/
  u_int16_t ether_type;		/* packet type ID field	*/
} __attribute__ ((__packed__));



/* These members of struct in6_addr are not defined in the KAME implementation */

#if defined(__FreeBSD__) || defined (__NetBSD__) || defined (__OpenBSD__) || defined(__APPLE__)
    #ifndef s6_addr16
    #define s6_addr16	__u6_addr.__u6_addr16
    #endif

    #ifndef s6_addr8
    #define s6_addr8	__u6_addr.__u6_addr8
    #endif

    #ifndef s6_addr32
    #define s6_addr32	__u6_addr.__u6_addr32
    #endif
#endif
