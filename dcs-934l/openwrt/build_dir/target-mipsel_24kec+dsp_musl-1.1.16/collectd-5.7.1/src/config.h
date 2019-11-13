/* src/config.h.  Generated from config.h.in by configure.  */
/* src/config.h.in.  Generated from configure.ac by autoheader.  */

/* User agent for http requests */
/* #undef COLLECTD_USERAGENT */

/* wether or not to enable feature daemon mode */
#define COLLECT_DAEMON 1

/* wether or not to enable feature debugging */
#define COLLECT_DEBUG 0

/* wether or not to enable feature getifaddrs under Linux */
#define COLLECT_GETIFADDRS 0

/* Wether or not to use the esmtp library */
#define COLLECT_LIBESMTP 0

/* wether or not to enable feature building with -Werror */
#define COLLECT_WERROR 0

/* Maximum length of data buffers */
#define DATA_MAX_NAME_LEN 128

/* Define if endianflip is needed to convert to x86 representation. */
/* #undef FP_LAYOUT_NEED_ENDIANFLIP */

/* Define if intswap is needed to convert to x86 representation. */
/* #undef FP_LAYOUT_NEED_INTSWAP */

/* Define if doubles are stored in x86 representation. */
#define FP_LAYOUT_NEED_NOTHING 1

/* Define to 1 if you have the <amqp.h> header file. */
/* #undef HAVE_AMQP_H */

/* Define to 1 if `library_errno' is a member of `amqp_rpc_reply_t'. */
/* #undef HAVE_AMQP_RPC_REPLY_T_LIBRARY_ERRNO */

/* Define to 1 if you have the <amqp_socket.h> header file. */
/* #undef HAVE_AMQP_SOCKET_H */

/* Define if librabbitmq provides the new TCP socket interface. */
/* #undef HAVE_AMQP_TCP_SOCKET */

/* Define to 1 if you have the <amqp_tcp_socket.h> header file. */
/* #undef HAVE_AMQP_TCP_SOCKET_H */

/* Define to 1 if you have the `argz_add' function. */
/* #undef HAVE_ARGZ_ADD */

/* Define to 1 if you have the `argz_append' function. */
/* #undef HAVE_ARGZ_APPEND */

/* Define to 1 if you have the `argz_count' function. */
/* #undef HAVE_ARGZ_COUNT */

/* Define to 1 if you have the `argz_create_sep' function. */
/* #undef HAVE_ARGZ_CREATE_SEP */

/* Define to 1 if you have the <argz.h> header file. */
/* #undef HAVE_ARGZ_H */

/* Define to 1 if you have the `argz_insert' function. */
/* #undef HAVE_ARGZ_INSERT */

/* Define to 1 if you have the `argz_next' function. */
/* #undef HAVE_ARGZ_NEXT */

/* Define to 1 if you have the `argz_stringify' function. */
/* #undef HAVE_ARGZ_STRINGIFY */

/* Define to 1 if you have the <arpa/inet.h> header file. */
#define HAVE_ARPA_INET_H 1

/* Define to 1 if you have the <arpa/nameser_compat.h> header file. */
#define HAVE_ARPA_NAMESER_COMPAT_H 1

/* Define to 1 if you have the <arpa/nameser.h> header file. */
#define HAVE_ARPA_NAMESER_H 1

/* Define to 1 if you have the <asm/msr-index.h> header file. */
/* #undef HAVE_ASM_MSR_INDEX_H */

/* Define to 1 if you have the `asprintf' function. */
#define HAVE_ASPRINTF 1

/* Define to 1 if you have the <assert.h> header file. */
#define HAVE_ASSERT_H 1

/* Define to 1 if you have the <atasmart.h> header file. */
/* #undef HAVE_ATASMART_H */

/* Define to 1 if you have the <bsd/nlist.h> header file. */
/* #undef HAVE_BSD_NLIST_H */

/* Define to 1 if you have cap_get_bound() (-lcap). */
/* #undef HAVE_CAPABILITY */

/* Define if the clock_gettime(2) function is available. */
#define HAVE_CLOCK_GETTIME 1

/* Define to 1 if you have the `closedir' function. */
#define HAVE_CLOSEDIR 1

/* Define to 1 if you have the `closelog' function. */
#define HAVE_CLOSELOG 1

/* Define to 1 if you have the <CoreFoundation/CoreFoundation.h> header file.
   */
/* #undef HAVE_COREFOUNDATION_COREFOUNDATION_H */

/* Define to 1 if you have the <cpuid.h> header file. */
/* #undef HAVE_CPUID_H */

/* Define to 1 if you have the <ctype.h> header file. */
#define HAVE_CTYPE_H 1

/* Define if curl.h defines CURLINFO_APPCONNECT_TIME. */
#define HAVE_CURLINFO_APPCONNECT_TIME 1

/* Define if libcurl supports CURLOPT_TIMEOUT_MS option. */
#define HAVE_CURLOPT_TIMEOUT_MS 1

/* Define if libcurl supports CURLOPT_USERNAME option. */
#define HAVE_CURLOPT_USERNAME 1

/* Define to 1 if you have the <curl/curl.h> header file. */
#define HAVE_CURL_CURL_H 1

/* Define to 1 if you have the <dbi/dbi.h> header file. */
/* #undef HAVE_DBI_DBI_H */

/* Define to 1 if you have the declaration of `amqp_socket_close', and to 0 if
   you don't. */
/* #undef HAVE_DECL_AMQP_SOCKET_CLOSE */

/* Define to 1 if you have the declaration of `cygwin_conv_path', and to 0 if
   you don't. */
/* #undef HAVE_DECL_CYGWIN_CONV_PATH */

/* Define to 1 if you have the declaration of `strerror_r', and to 0 if you
   don't. */
#define HAVE_DECL_STRERROR_R 1

/* Define to 1 if you have the <dirent.h> header file, and it defines `DIR'.
   */
#define HAVE_DIRENT_H 1

/* Define if you have the GNU dld library. */
/* #undef HAVE_DLD */

/* Define to 1 if you have the <dld.h> header file. */
/* #undef HAVE_DLD_H */

/* Define to 1 if you have the `dlerror' function. */
#define HAVE_DLERROR 1

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define to 1 if you have the <dl.h> header file. */
/* #undef HAVE_DL_H */

/* Define if you have the _dyld_func_lookup function. */
/* #undef HAVE_DYLD */

/* Define to 1 if you have the <endian.h> header file. */
#define HAVE_ENDIAN_H 1

/* Define to 1 if you have the <errno.h> header file. */
#define HAVE_ERRNO_H 1

/* Define to 1 if the system has the type `error_t'. */
/* #undef HAVE_ERROR_T */

/* Define to 1 if you have the <fcntl.h> header file. */
#define HAVE_FCNTL_H 1

/* Define to 1 if you have the <fnmatch.h> header file. */
#define HAVE_FNMATCH_H 1

/* Define to 1 if you have the <fshelp.h> header file. */
/* #undef HAVE_FSHELP_H */

/* Define to 1 if you have the <fs_info.h> header file. */
/* #undef HAVE_FS_INFO_H */

/* Define to 1 if you have the <gcrypt.h> header file. */
/* #undef HAVE_GCRYPT_H */

/* Define if the function getmntent exists. It is the version from libgen. */
/* #undef HAVE_GEN_GETMNTENT */

/* Define to 1 if you have the `getaddrinfo' function. */
#define HAVE_GETADDRINFO 1

/* Define to 1 if you have the `getfsstat' function. */
/* #undef HAVE_GETFSSTAT */

/* Define to 1 if you have the `getgrnam_r' function. */
#define HAVE_GETGRNAM_R 1

/* Define to 1 if you have the `getifaddrs' function. */
#define HAVE_GETIFADDRS 1

/* Define to 1 if you have the `getloadavg' function. */
#define HAVE_GETLOADAVG 1

/* Define to 1 if you have the `getmntent' function. */
#define HAVE_GETMNTENT 1

/* Define to 1 if you have the `getmntent_r' function. */
#define HAVE_GETMNTENT_R 1

/* Define to 1 if you have the `getnameinfo' function. */
#define HAVE_GETNAMEINFO 1

/* Define to 1 if you have the `getpwnam_r' function. */
#define HAVE_GETPWNAM_R 1

/* Define to 1 if you have the `gettimeofday' function. */
#define HAVE_GETTIMEOFDAY 1

/* Define to 1 if you have the `getutent' function. */
#define HAVE_GETUTENT 1

/* Define to 1 if you have the `getutxent' function. */
#define HAVE_GETUTXENT 1

/* Define to 1 if you have the `getvfsstat' function. */
/* #undef HAVE_GETVFSSTAT */

/* Define to 1 if you have the <gm_protocol.h> header file. */
/* #undef HAVE_GM_PROTOCOL_H */

/* Define to 1 if you have the <google/protobuf-c/protobuf-c.h> header file.
   */
/* #undef HAVE_GOOGLE_PROTOBUF_C_PROTOBUF_C_H */

/* Define to 1 if you have the <google/protobuf/util/time_util.h> header file.
   */
/* #undef HAVE_GOOGLE_PROTOBUF_UTIL_TIME_UTIL_H */

/* Define to 1 if you have the <gps.h> header file. */
/* #undef HAVE_GPS_H */

/* Define to 1 if you have the <grpc++/grpc++.h> header file. */
/* #undef HAVE_GRPC___GRPC___H */

/* Define to 1 if you have the <grp.h> header file. */
#define HAVE_GRP_H 1

/* Define to 1 if you have the <hiredis/hiredis.h> header file. */
/* #undef HAVE_HIREDIS_HIREDIS_H */

/* Define to 1 if you have the `host_statistics' function. */
/* #undef HAVE_HOST_STATISTICS */

/* Define if the function htonll exists. */
/* #undef HAVE_HTONLL */

/* Define to 1 if you have the <ifaddrs.h> header file. */
#define HAVE_IFADDRS_H 1

/* Define to 1 if you have the `if_indextoname' function. */
#define HAVE_IF_INDEXTONAME 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the <IOKit/IOBSD.h> header file. */
/* #undef HAVE_IOKIT_IOBSD_H */

/* Define to 1 if you have the <IOKit/IOKitLib.h> header file. */
/* #undef HAVE_IOKIT_IOKITLIB_H */

/* Define to 1 if you have the <IOKit/IOTypes.h> header file. */
/* #undef HAVE_IOKIT_IOTYPES_H */

/* Define to 1 if you have the <IOKit/ps/IOPowerSources.h> header file. */
/* #undef HAVE_IOKIT_PS_IOPOWERSOURCES_H */

/* Define to 1 if you have the <IOKit/ps/IOPSKeys.h> header file. */
/* #undef HAVE_IOKIT_PS_IOPSKEYS_H */

/* Define to 1 if you have the <IOKit/storage/IOBlockStorageDriver.h> header
   file. */
/* #undef HAVE_IOKIT_STORAGE_IOBLOCKSTORAGEDRIVER_H */

/* Define to 1 if the system has the type `ip6tc_handle_t'. */
/* #undef HAVE_IP6TC_HANDLE_T */

/* Define to 1 if the system has the type `iptc_handle_t'. */
/* #undef HAVE_IPTC_HANDLE_T */

/* Define to 1 if you have the <ip_vs.h> header file. */
/* #undef HAVE_IP_VS_H */

/* Define to 1 if you have the <jni.h> header file. */
#define HAVE_JNI_H 1

/* Define to 1 if you have the <kstat.h> header file. */
/* #undef HAVE_KSTAT_H */

/* Define to 1 if `nwrites' is a member of `kstat_io_t'. */
/* #undef HAVE_KSTAT_IO_T_NWRITES */

/* Define to 1 if `nwritten' is a member of `kstat_io_t'. */
/* #undef HAVE_KSTAT_IO_T_NWRITTEN */

/* Define to 1 if `writes' is a member of `kstat_io_t'. */
/* #undef HAVE_KSTAT_IO_T_WRITES */

/* Define to 1 if `wtime' is a member of `kstat_io_t'. */
/* #undef HAVE_KSTAT_IO_T_WTIME */

/* Define to 1 if you have the <kvm.h> header file. */
/* #undef HAVE_KVM_H */

/* Define to 1 if you have the <lauxlib.h> header file. */
#define HAVE_LAUXLIB_H 1

/* Define to 1 if you have the <ldap.h> header file. */
/* #undef HAVE_LDAP_H */

/* Define to 1 if you have the <libaquaero5.h> header file. */
/* #undef HAVE_LIBAQUAERO5_H */

/* Define if libatasmart is present and usable. */
/* #undef HAVE_LIBATASMART */

/* Define if you have the libdl library or equivalent. */
#define HAVE_LIBDL 1

/* Define if libdlloader will be built on this platform */
#define HAVE_LIBDLLOADER 1

/* Define to 1 if you have the esmtp library (-lesmtp). */
/* #undef HAVE_LIBESMTP */

/* Define to 1 if you have the <libesmtp.h> header file. */
/* #undef HAVE_LIBESMTP_H */

/* Define to 1 if you have the ganglia library (-lganglia). */
/* #undef HAVE_LIBGANGLIA */

/* Define to 1 if you have the gcrypt library (-lgcrypt). */
/* #undef HAVE_LIBGCRYPT */

/* Define to 1 if you have the <libgen.h> header file. */
#define HAVE_LIBGEN_H 1

/* Define to 1 if you have the <libhal.h> header file. */
/* #undef HAVE_LIBHAL_H */

/* Define to 1 if you have the <libiptc/libip6tc.h> header file. */
#define HAVE_LIBIPTC_LIBIP6TC_H 1

/* Define to 1 if you have the <libiptc/libiptc.h> header file. */
#define HAVE_LIBIPTC_LIBIPTC_H 1

/* Define to 1 if you have the 'kstat' library (-lkstat) */
/* #undef HAVE_LIBKSTAT */

/* Define to 1 if you have the 'kvm' library with the 'kvm_getprocs' symbol
   (-lkvm) */
/* #undef HAVE_LIBKVM_GETPROCS */

/* Define to 1 if you have the 'kvm' library with the 'kvm_getswapinfo' symbol
   (-lkvm) */
/* #undef HAVE_LIBKVM_GETSWAPINFO */

/* Define to 1 if you have the 'kvm' library with the 'kvm_openfiles' symbol
   (-lkvm) */
/* #undef HAVE_LIBKVM_NLIST */

/* Define if liblvm2app is present and usable. */
/* #undef HAVE_LIBLVM2APP */

/* Define if libmemcached is present and usable. */
/* #undef HAVE_LIBMEMCACHED */

/* Define to 1 if you have the <libmemcached/memcached.h> header file. */
/* #undef HAVE_LIBMEMCACHED_MEMCACHED_H */

/* Define if libmnl is present and usable. */
/* #undef HAVE_LIBMNL */

/* Define to 1 if you have the <libmnl.h> header file. */
/* #undef HAVE_LIBMNL_H */

/* Define to 1 if you have the <libmnl/libmnl.h> header file. */
/* #undef HAVE_LIBMNL_LIBMNL_H */

/* Define to 1 if you have the netapp library (-lnetapp). */
/* #undef HAVE_LIBNETAPP */

/* Define to 1 if you have the pcap library (-lpcap). */
/* #undef HAVE_LIBPCAP */

/* Define if libperl is present and usable. */
/* #undef HAVE_LIBPERL */

/* Define to 1 if you have the <libpq-fe.h> header file. */
/* #undef HAVE_LIBPQ_FE_H */

/* Define to 1 if you have the `pthread' library (-lpthread). */
#define HAVE_LIBPTHREAD 1

/* Define if librabbitmq is present and usable. */
/* #undef HAVE_LIBRABBITMQ */

/* Define if librdkafka is present and usable. */
#define HAVE_LIBRDKAFKA 1

/* Define if librdkafka log facility is present and usable. */
/* #undef HAVE_LIBRDKAFKA_LOGGER */

/* Define if librdkafka log facility is present and usable. */
#define HAVE_LIBRDKAFKA_LOG_CB 1

/* Define to 1 if you have the <librdkafka/rdkafka.h> header file. */
#define HAVE_LIBRDKAFKA_RDKAFKA_H 1

/* Define to 1 if you have the 'resolv' library (-lresolv). */
#define HAVE_LIBRESOLV 1

/* Define to 1 if you have the sensors library (-lsensors). */
/* #undef HAVE_LIBSENSORS */

/* Define to 1 if you have the 'statgrab' library (-lstatgrab) */
/* #undef HAVE_LIBSTATGRAB */

/* Define to 1 if libstatgrab version >= 0.90 */
/* #undef HAVE_LIBSTATGRAB_0_90 */

/* Define to 1 if you have the tokyotyrant library (-ltokyotyrant). */
/* #undef HAVE_LIBTOKYOTYRANT */

/* Define to 1 if you have the udev library (-ludev). */
/* #undef HAVE_LIBUDEV */

/* Define to 1 if you have the <libudev.h> header file. */
/* #undef HAVE_LIBUDEV_H */

/* Define to 1 if you have the <libvirt/libvirt.h> header file. */
/* #undef HAVE_LIBVIRT_LIBVIRT_H */

/* Define to 1 if you have the <libxml/parser.h> header file. */
/* #undef HAVE_LIBXML_PARSER_H */

/* Define to 1 if you have the 'xmms' library (-lxmms). */
#define HAVE_LIBXMMS 0

/* Define if libyajl is present and usable. */
/* #undef HAVE_LIBYAJL */

/* Define to 1 if you have the <limits.h> header file. */
#define HAVE_LIMITS_H 1

/* Define to 1 if you have the <linux/config.h> header file. */
/* #undef HAVE_LINUX_CONFIG_H */

/* Define to 1 if you have the <linux/ethtool.h> header file. */
#define HAVE_LINUX_ETHTOOL_H 1

/* Define to 1 if you have the <linux/gen_stats.h> header file. */
#define HAVE_LINUX_GEN_STATS_H 1

/* Define to 1 if you have the <linux/if.h> header file. */
#define HAVE_LINUX_IF_H 1

/* Define to 1 if you have the <linux/inet_diag.h> header file. */
#define HAVE_LINUX_INET_DIAG_H 1

/* Define to 1 if you have the <linux/ip_vs.h> header file. */
#define HAVE_LINUX_IP_VS_H 1

/* Define to 1 if you have the <linux/major.h> header file. */
#define HAVE_LINUX_MAJOR_H 1

/* Define to 1 if you have the <linux/netdevice.h> header file. */
#define HAVE_LINUX_NETDEVICE_H 1

/* Define to 1 if you have the <linux/pkt_sched.h> header file. */
#define HAVE_LINUX_PKT_SCHED_H 1

/* Define to 1 if you have the <linux/raid/md_u.h> header file. */
#define HAVE_LINUX_RAID_MD_U_H 1

/* Define to 1 if you have the <linux/sockios.h> header file. */
#define HAVE_LINUX_SOCKIOS_H 1

/* Define to 1 if you have the <linux/un.h> header file. */
#define HAVE_LINUX_UN_H 1

/* Define to 1 if you have the <linux/wireless.h> header file. */
#define HAVE_LINUX_WIRELESS_H 1

/* Define to 1 if you have the `listmntent' function. */
/* #undef HAVE_LISTMNTENT */

/* Define to 1 if you have the <locale.h> header file. */
#define HAVE_LOCALE_H 1

/* Define this if a modern libltdl is already installed */
#define HAVE_LTDL 1

/* Define to 1 if you have the <lualib.h> header file. */
#define HAVE_LUALIB_H 1

/* Define to 1 if you have the <lua.h> header file. */
#define HAVE_LUA_H 1

/* Define to 1 if you have the <lvm2app.h> header file. */
/* #undef HAVE_LVM2APP_H */

/* Define to 1 if you have the <mach/host_priv.h> header file. */
/* #undef HAVE_MACH_HOST_PRIV_H */

/* Define to 1 if you have the <mach/kern_return.h> header file. */
/* #undef HAVE_MACH_KERN_RETURN_H */

/* Define to 1 if you have the <mach/mach_error.h> header file. */
/* #undef HAVE_MACH_MACH_ERROR_H */

/* Define to 1 if you have the <mach/mach_host.h> header file. */
/* #undef HAVE_MACH_MACH_HOST_H */

/* Define to 1 if you have the <mach/mach_init.h> header file. */
/* #undef HAVE_MACH_MACH_INIT_H */

/* Define to 1 if you have the <mach/mach_port.h> header file. */
/* #undef HAVE_MACH_MACH_PORT_H */

/* Define to 1 if you have the <mach/mach_types.h> header file. */
/* #undef HAVE_MACH_MACH_TYPES_H */

/* Define to 1 if you have the <mach/message.h> header file. */
/* #undef HAVE_MACH_MESSAGE_H */

/* Define to 1 if you have the <mach-o/dyld.h> header file. */
/* #undef HAVE_MACH_O_DYLD_H */

/* Define to 1 if you have the <mach/processor.h> header file. */
/* #undef HAVE_MACH_PROCESSOR_H */

/* Define to 1 if you have the <mach/processor_info.h> header file. */
/* #undef HAVE_MACH_PROCESSOR_INFO_H */

/* Define to 1 if you have the <mach/processor_set.h> header file. */
/* #undef HAVE_MACH_PROCESSOR_SET_H */

/* Define to 1 if you have the <mach/task.h> header file. */
/* #undef HAVE_MACH_TASK_H */

/* Define to 1 if you have the <mach/thread_act.h> header file. */
/* #undef HAVE_MACH_THREAD_ACT_H */

/* Define to 1 if you have the <mach/vm_map.h> header file. */
/* #undef HAVE_MACH_VM_MAP_H */

/* Define to 1 if you have the <mach/vm_prot.h> header file. */
/* #undef HAVE_MACH_VM_PROT_H */

/* Define to 1 if you have the <mach/vm_region.h> header file. */
/* #undef HAVE_MACH_VM_REGION_H */

/* Define to 1 if you have the <mach/vm_statistics.h> header file. */
/* #undef HAVE_MACH_VM_STATISTICS_H */

/* Define to 1 if you have the <math.h> header file. */
#define HAVE_MATH_H 1

/* Define to 1 if you have the `memcpy' function. */
#define HAVE_MEMCPY 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the <MicAccessApi.h> header file. */
/* #undef HAVE_MICACCESSAPI_H */

/* Define to 1 if you have the <microhttpd.h> header file. */
/* #undef HAVE_MICROHTTPD_H */

/* Define to 1 if you have the <mntent.h> header file. */
#define HAVE_MNTENT_H 1

/* Define to 1 if you have the <mnttab.h> header file. */
/* #undef HAVE_MNTTAB_H */

/* Define to 1 if you have the <modbus/modbus.h> header file. */
/* #undef HAVE_MODBUS_MODBUS_H */

/* Define to 1 if you have the <mongo.h> header file. */
/* #undef HAVE_MONGO_H */

/* Define to 1 if you have the <mosquitto.h> header file. */
/* #undef HAVE_MOSQUITTO_H */

/* Define to 1 if you have the <mysql.h> header file. */
/* #undef HAVE_MYSQL_H */

/* Define to 1 if you have the <mysql/mysql.h> header file. */
/* #undef HAVE_MYSQL_MYSQL_H */

/* Define to 1 if you have the `nanosleep' function. */
#define HAVE_NANOSLEEP 1

/* Define to 1 if you have the <ndir.h> header file, and it defines `DIR'. */
/* #undef HAVE_NDIR_H */

/* Define to 1 if you have the <netapp_api.h> header file. */
/* #undef HAVE_NETAPP_API_H */

/* Define to 1 if you have the <netdb.h> header file. */
#define HAVE_NETDB_H 1

/* Define to 1 if you have the <netinet/icmp6.h> header file. */
#define HAVE_NETINET_ICMP6_H 1

/* Define to 1 if you have the <netinet/if_ether.h> header file. */
#define HAVE_NETINET_IF_ETHER_H 1

/* Define to 1 if you have the <netinet/in.h> header file. */
#define HAVE_NETINET_IN_H 1

/* Define to 1 if you have the <netinet/in_systm.h> header file. */
#define HAVE_NETINET_IN_SYSTM_H 1

/* Define to 1 if you have the <netinet/ip6.h> header file. */
#define HAVE_NETINET_IP6_H 1

/* Define to 1 if you have the <netinet/ip.h> header file. */
#define HAVE_NETINET_IP_H 1

/* Define to 1 if you have the <netinet/ip_icmp.h> header file. */
#define HAVE_NETINET_IP_ICMP_H 1

/* Define to 1 if you have the <netinet/ip_var.h> header file. */
/* #undef HAVE_NETINET_IP_VAR_H */

/* Define to 1 if you have the <netinet/tcp.h> header file. */
#define HAVE_NETINET_TCP_H 1

/* Define to 1 if you have the <netinet/udp.h> header file. */
#define HAVE_NETINET_UDP_H 1

/* Define to 1 if you have the <net/if_arp.h> header file. */
#define HAVE_NET_IF_ARP_H 1

/* Define to 1 if you have the <net/if.h> header file. */
#define HAVE_NET_IF_H 1

/* Define to 1 if you have the <net/if_ppp.h> header file. */
/* #undef HAVE_NET_IF_PPP_H */

/* Define to 1 if you have the <net/ip_vs.h> header file. */
/* #undef HAVE_NET_IP_VS_H */

/* Define to 1 if you have the <net/pfvar.h> header file. */
/* #undef HAVE_NET_PFVAR_H */

/* Define to 1 if you have the <net/ppp_defs.h> header file. */
/* #undef HAVE_NET_PPP_DEFS_H */

/* Define to 1 if you have the <net-snmp/net-snmp-config.h> header file. */
/* #undef HAVE_NET_SNMP_NET_SNMP_CONFIG_H */

/* Define to 1 if you have the <nlist.h> header file. */
/* #undef HAVE_NLIST_H */

/* Define to 1 if you have the <oci.h> header file. */
/* #undef HAVE_OCI_H */

/* Define if the function getmntent exists and takes one argument. */
#define HAVE_ONE_GETMNTENT 1

/* Define to 1 if you have the `opendir' function. */
#define HAVE_OPENDIR 1

/* Define to 1 if you have the <OpenIPMI/ipmi_smi.h> header file. */
/* #undef HAVE_OPENIPMI_IPMI_SMI_H */

/* Define to 1 if you have the `openlog' function. */
#define HAVE_OPENLOG 1

/* Define to 1 if you have the <oping.h> header file. */
/* #undef HAVE_OPING_H */

/* Define to 1 if you have the <owcapi.h> header file. */
/* #undef HAVE_OWCAPI_H */

/* Define to 1 if you have the <paths.h> header file. */
#define HAVE_PATHS_H 1

/* Define to 1 if you have the <pcap.h> header file. */
/* #undef HAVE_PCAP_H */

/* Define to 1 if you have the 'perfstat' library (-lperfstat) */
/* #undef HAVE_PERFSTAT */

/* Define if Perl supports ithreads. */
/* #undef HAVE_PERL_ITHREADS */

/* Define if Perl's struct mgvtbl has member svt_local. */
/* #undef HAVE_PERL_STRUCT_MGVTBL_SVT_LOCAL */

/* Define to 1 if the aggregation plugin is enabled. */
#define HAVE_PLUGIN_AGGREGATION 1

/* Define to 1 if the amqp plugin is enabled. */
/* #undef HAVE_PLUGIN_AMQP */

/* Define to 1 if the apache plugin is enabled. */
/* #undef HAVE_PLUGIN_APACHE */

/* Define to 1 if the apcups plugin is enabled. */
/* #undef HAVE_PLUGIN_APCUPS */

/* Define to 1 if the apple_sensors plugin is enabled. */
/* #undef HAVE_PLUGIN_APPLE_SENSORS */

/* Define to 1 if the aquaero plugin is enabled. */
/* #undef HAVE_PLUGIN_AQUAERO */

/* Define to 1 if the ascent plugin is enabled. */
/* #undef HAVE_PLUGIN_ASCENT */

/* Define to 1 if the barometer plugin is enabled. */
/* #undef HAVE_PLUGIN_BAROMETER */

/* Define to 1 if the battery plugin is enabled. */
/* #undef HAVE_PLUGIN_BATTERY */

/* Define to 1 if the bind plugin is enabled. */
/* #undef HAVE_PLUGIN_BIND */

/* Define to 1 if the ceph plugin is enabled. */
/* #undef HAVE_PLUGIN_CEPH */

/* Define to 1 if the cgroups plugin is enabled. */
/* #undef HAVE_PLUGIN_CGROUPS */

/* Define to 1 if the chrony plugin is enabled. */
/* #undef HAVE_PLUGIN_CHRONY */

/* Define to 1 if the conntrack plugin is enabled. */
/* #undef HAVE_PLUGIN_CONNTRACK */

/* Define to 1 if the contextswitch plugin is enabled. */
/* #undef HAVE_PLUGIN_CONTEXTSWITCH */

/* Define to 1 if the cpu plugin is enabled. */
#define HAVE_PLUGIN_CPU 1

/* Define to 1 if the cpufreq plugin is enabled. */
/* #undef HAVE_PLUGIN_CPUFREQ */

/* Define to 1 if the cpusleep plugin is enabled. */
/* #undef HAVE_PLUGIN_CPUSLEEP */

/* Define to 1 if the csv plugin is enabled. */
/* #undef HAVE_PLUGIN_CSV */

/* Define to 1 if the curl plugin is enabled. */
/* #undef HAVE_PLUGIN_CURL */

/* Define to 1 if the curl_json plugin is enabled. */
/* #undef HAVE_PLUGIN_CURL_JSON */

/* Define to 1 if the curl_xml plugin is enabled. */
/* #undef HAVE_PLUGIN_CURL_XML */

/* Define to 1 if the dbi plugin is enabled. */
/* #undef HAVE_PLUGIN_DBI */

/* Define to 1 if the df plugin is enabled. */
/* #undef HAVE_PLUGIN_DF */

/* Define to 1 if the disk plugin is enabled. */
/* #undef HAVE_PLUGIN_DISK */

/* Define to 1 if the dns plugin is enabled. */
/* #undef HAVE_PLUGIN_DNS */

/* Define to 1 if the dpdkstat plugin is enabled. */
/* #undef HAVE_PLUGIN_DPDKSTAT */

/* Define to 1 if the drbd plugin is enabled. */
/* #undef HAVE_PLUGIN_DRBD */

/* Define to 1 if the email plugin is enabled. */
/* #undef HAVE_PLUGIN_EMAIL */

/* Define to 1 if the entropy plugin is enabled. */
/* #undef HAVE_PLUGIN_ENTROPY */

/* Define to 1 if the ethstat plugin is enabled. */
/* #undef HAVE_PLUGIN_ETHSTAT */

/* Define to 1 if the exec plugin is enabled. */
/* #undef HAVE_PLUGIN_EXEC */

/* Define to 1 if the fhcount plugin is enabled. */
/* #undef HAVE_PLUGIN_FHCOUNT */

/* Define to 1 if the filecount plugin is enabled. */
/* #undef HAVE_PLUGIN_FILECOUNT */

/* Define to 1 if the fscache plugin is enabled. */
/* #undef HAVE_PLUGIN_FSCACHE */

/* Define to 1 if the gmond plugin is enabled. */
/* #undef HAVE_PLUGIN_GMOND */

/* Define to 1 if the gps plugin is enabled. */
/* #undef HAVE_PLUGIN_GPS */

/* Define to 1 if the grpc plugin is enabled. */
/* #undef HAVE_PLUGIN_GRPC */

/* Define to 1 if the hddtemp plugin is enabled. */
/* #undef HAVE_PLUGIN_HDDTEMP */

/* Define to 1 if the hugepages plugin is enabled. */
/* #undef HAVE_PLUGIN_HUGEPAGES */

/* Define to 1 if the intel_rdt plugin is enabled. */
/* #undef HAVE_PLUGIN_INTEL_RDT */

/* Define to 1 if the interface plugin is enabled. */
/* #undef HAVE_PLUGIN_INTERFACE */

/* Define to 1 if the ipc plugin is enabled. */
/* #undef HAVE_PLUGIN_IPC */

/* Define to 1 if the ipmi plugin is enabled. */
/* #undef HAVE_PLUGIN_IPMI */

/* Define to 1 if the iptables plugin is enabled. */
/* #undef HAVE_PLUGIN_IPTABLES */

/* Define to 1 if the ipvs plugin is enabled. */
/* #undef HAVE_PLUGIN_IPVS */

/* Define to 1 if the irq plugin is enabled. */
/* #undef HAVE_PLUGIN_IRQ */

/* Define to 1 if the iwinfo plugin is enabled. */
/* #undef HAVE_PLUGIN_IWINFO */

/* Define to 1 if the java plugin is enabled. */
/* #undef HAVE_PLUGIN_JAVA */

/* Define to 1 if the load plugin is enabled. */
/* #undef HAVE_PLUGIN_LOAD */

/* Define to 1 if the logfile plugin is enabled. */
/* #undef HAVE_PLUGIN_LOGFILE */

/* Define to 1 if the log_logstash plugin is enabled. */
/* #undef HAVE_PLUGIN_LOG_LOGSTASH */

/* Define to 1 if the lpar plugin is enabled. */
/* #undef HAVE_PLUGIN_LPAR */

/* Define to 1 if the lua plugin is enabled. */
/* #undef HAVE_PLUGIN_LUA */

/* Define to 1 if the lvm plugin is enabled. */
/* #undef HAVE_PLUGIN_LVM */

/* Define to 1 if the madwifi plugin is enabled. */
/* #undef HAVE_PLUGIN_MADWIFI */

/* Define to 1 if the match_empty_counter plugin is enabled. */
/* #undef HAVE_PLUGIN_MATCH_EMPTY_COUNTER */

/* Define to 1 if the match_hashed plugin is enabled. */
/* #undef HAVE_PLUGIN_MATCH_HASHED */

/* Define to 1 if the match_regex plugin is enabled. */
/* #undef HAVE_PLUGIN_MATCH_REGEX */

/* Define to 1 if the match_timediff plugin is enabled. */
/* #undef HAVE_PLUGIN_MATCH_TIMEDIFF */

/* Define to 1 if the match_value plugin is enabled. */
/* #undef HAVE_PLUGIN_MATCH_VALUE */

/* Define to 1 if the mbmon plugin is enabled. */
/* #undef HAVE_PLUGIN_MBMON */

/* Define to 1 if the md plugin is enabled. */
/* #undef HAVE_PLUGIN_MD */

/* Define to 1 if the memcachec plugin is enabled. */
/* #undef HAVE_PLUGIN_MEMCACHEC */

/* Define to 1 if the memcached plugin is enabled. */
/* #undef HAVE_PLUGIN_MEMCACHED */

/* Define to 1 if the memory plugin is enabled. */
#define HAVE_PLUGIN_MEMORY 1

/* Define to 1 if the mic plugin is enabled. */
/* #undef HAVE_PLUGIN_MIC */

/* Define to 1 if the modbus plugin is enabled. */
/* #undef HAVE_PLUGIN_MODBUS */

/* Define to 1 if the mqtt plugin is enabled. */
/* #undef HAVE_PLUGIN_MQTT */

/* Define to 1 if the multimeter plugin is enabled. */
/* #undef HAVE_PLUGIN_MULTIMETER */

/* Define to 1 if the mysql plugin is enabled. */
/* #undef HAVE_PLUGIN_MYSQL */

/* Define to 1 if the netapp plugin is enabled. */
/* #undef HAVE_PLUGIN_NETAPP */

/* Define to 1 if the netlink plugin is enabled. */
/* #undef HAVE_PLUGIN_NETLINK */

/* Define to 1 if the network plugin is enabled. */
/* #undef HAVE_PLUGIN_NETWORK */

/* Define to 1 if the nfs plugin is enabled. */
/* #undef HAVE_PLUGIN_NFS */

/* Define to 1 if the nginx plugin is enabled. */
/* #undef HAVE_PLUGIN_NGINX */

/* Define to 1 if the notify_desktop plugin is enabled. */
/* #undef HAVE_PLUGIN_NOTIFY_DESKTOP */

/* Define to 1 if the notify_email plugin is enabled. */
/* #undef HAVE_PLUGIN_NOTIFY_EMAIL */

/* Define to 1 if the notify_nagios plugin is enabled. */
/* #undef HAVE_PLUGIN_NOTIFY_NAGIOS */

/* Define to 1 if the ntpd plugin is enabled. */
/* #undef HAVE_PLUGIN_NTPD */

/* Define to 1 if the numa plugin is enabled. */
/* #undef HAVE_PLUGIN_NUMA */

/* Define to 1 if the nut plugin is enabled. */
/* #undef HAVE_PLUGIN_NUT */

/* Define to 1 if the olsrd plugin is enabled. */
/* #undef HAVE_PLUGIN_OLSRD */

/* Define to 1 if the onewire plugin is enabled. */
/* #undef HAVE_PLUGIN_ONEWIRE */

/* Define to 1 if the openldap plugin is enabled. */
/* #undef HAVE_PLUGIN_OPENLDAP */

/* Define to 1 if the openvpn plugin is enabled. */
/* #undef HAVE_PLUGIN_OPENVPN */

/* Define to 1 if the oracle plugin is enabled. */
/* #undef HAVE_PLUGIN_ORACLE */

/* Define to 1 if the perl plugin is enabled. */
/* #undef HAVE_PLUGIN_PERL */

/* Define to 1 if the pf plugin is enabled. */
/* #undef HAVE_PLUGIN_PF */

/* Define to 1 if the pinba plugin is enabled. */
/* #undef HAVE_PLUGIN_PINBA */

/* Define to 1 if the ping plugin is enabled. */
/* #undef HAVE_PLUGIN_PING */

/* Define to 1 if the postgresql plugin is enabled. */
/* #undef HAVE_PLUGIN_POSTGRESQL */

/* Define to 1 if the powerdns plugin is enabled. */
/* #undef HAVE_PLUGIN_POWERDNS */

/* Define to 1 if the processes plugin is enabled. */
/* #undef HAVE_PLUGIN_PROCESSES */

/* Define to 1 if the protocols plugin is enabled. */
/* #undef HAVE_PLUGIN_PROTOCOLS */

/* Define to 1 if the python plugin is enabled. */
/* #undef HAVE_PLUGIN_PYTHON */

/* Define to 1 if the redis plugin is enabled. */
/* #undef HAVE_PLUGIN_REDIS */

/* Define to 1 if the routeros plugin is enabled. */
/* #undef HAVE_PLUGIN_ROUTEROS */

/* Define to 1 if the rrdcached plugin is enabled. */
/* #undef HAVE_PLUGIN_RRDCACHED */

/* Define to 1 if the rrdtool plugin is enabled. */
/* #undef HAVE_PLUGIN_RRDTOOL */

/* Define to 1 if the sensors plugin is enabled. */
/* #undef HAVE_PLUGIN_SENSORS */

/* Define to 1 if the serial plugin is enabled. */
/* #undef HAVE_PLUGIN_SERIAL */

/* Define to 1 if the sigrok plugin is enabled. */
/* #undef HAVE_PLUGIN_SIGROK */

/* Define to 1 if the smart plugin is enabled. */
/* #undef HAVE_PLUGIN_SMART */

/* Define to 1 if the snmp plugin is enabled. */
/* #undef HAVE_PLUGIN_SNMP */

/* Define to 1 if the statsd plugin is enabled. */
/* #undef HAVE_PLUGIN_STATSD */

/* Define to 1 if the swap plugin is enabled. */
/* #undef HAVE_PLUGIN_SWAP */

/* Define to 1 if the syslog plugin is enabled. */
/* #undef HAVE_PLUGIN_SYSLOG */

/* Define to 1 if the table plugin is enabled. */
/* #undef HAVE_PLUGIN_TABLE */

/* Define to 1 if the tail plugin is enabled. */
/* #undef HAVE_PLUGIN_TAIL */

/* Define to 1 if the tail_csv plugin is enabled. */
/* #undef HAVE_PLUGIN_TAIL_CSV */

/* Define to 1 if the tape plugin is enabled. */
/* #undef HAVE_PLUGIN_TAPE */

/* Define to 1 if the target_notification plugin is enabled. */
#define HAVE_PLUGIN_TARGET_NOTIFICATION 1

/* Define to 1 if the target_replace plugin is enabled. */
#define HAVE_PLUGIN_TARGET_REPLACE 1

/* Define to 1 if the target_scale plugin is enabled. */
#define HAVE_PLUGIN_TARGET_SCALE 1

/* Define to 1 if the target_set plugin is enabled. */
#define HAVE_PLUGIN_TARGET_SET 1

/* Define to 1 if the target_v5upgrade plugin is enabled. */
#define HAVE_PLUGIN_TARGET_V5UPGRADE 1

/* Define to 1 if the tcpconns plugin is enabled. */
/* #undef HAVE_PLUGIN_TCPCONNS */

/* Define to 1 if the teamspeak2 plugin is enabled. */
/* #undef HAVE_PLUGIN_TEAMSPEAK2 */

/* Define to 1 if the ted plugin is enabled. */
/* #undef HAVE_PLUGIN_TED */

/* Define to 1 if the thermal plugin is enabled. */
/* #undef HAVE_PLUGIN_THERMAL */

/* Define to 1 if the threshold plugin is enabled. */
#define HAVE_PLUGIN_THRESHOLD 1

/* Define to 1 if the tokyotyrant plugin is enabled. */
/* #undef HAVE_PLUGIN_TOKYOTYRANT */

/* Define to 1 if the turbostat plugin is enabled. */
/* #undef HAVE_PLUGIN_TURBOSTAT */

/* Define to 1 if the unixsock plugin is enabled. */
/* #undef HAVE_PLUGIN_UNIXSOCK */

/* Define to 1 if the uptime plugin is enabled. */
/* #undef HAVE_PLUGIN_UPTIME */

/* Define to 1 if the users plugin is enabled. */
/* #undef HAVE_PLUGIN_USERS */

/* Define to 1 if the uuid plugin is enabled. */
/* #undef HAVE_PLUGIN_UUID */

/* Define to 1 if the varnish plugin is enabled. */
/* #undef HAVE_PLUGIN_VARNISH */

/* Define to 1 if the virt plugin is enabled. */
/* #undef HAVE_PLUGIN_VIRT */

/* Define to 1 if the vmem plugin is enabled. */
/* #undef HAVE_PLUGIN_VMEM */

/* Define to 1 if the vserver plugin is enabled. */
/* #undef HAVE_PLUGIN_VSERVER */

/* Define to 1 if the wireless plugin is enabled. */
/* #undef HAVE_PLUGIN_WIRELESS */

/* Define to 1 if the write_graphite plugin is enabled. */
/* #undef HAVE_PLUGIN_WRITE_GRAPHITE */

/* Define to 1 if the write_http plugin is enabled. */
/* #undef HAVE_PLUGIN_WRITE_HTTP */

/* Define to 1 if the write_kafka plugin is enabled. */
#define HAVE_PLUGIN_WRITE_KAFKA 1

/* Define to 1 if the write_log plugin is enabled. */
/* #undef HAVE_PLUGIN_WRITE_LOG */

/* Define to 1 if the write_mongodb plugin is enabled. */
/* #undef HAVE_PLUGIN_WRITE_MONGODB */

/* Define to 1 if the write_prometheus plugin is enabled. */
/* #undef HAVE_PLUGIN_WRITE_PROMETHEUS */

/* Define to 1 if the write_redis plugin is enabled. */
/* #undef HAVE_PLUGIN_WRITE_REDIS */

/* Define to 1 if the write_riemann plugin is enabled. */
/* #undef HAVE_PLUGIN_WRITE_RIEMANN */

/* Define to 1 if the write_sensu plugin is enabled. */
/* #undef HAVE_PLUGIN_WRITE_SENSU */

/* Define to 1 if the write_tsdb plugin is enabled. */
/* #undef HAVE_PLUGIN_WRITE_TSDB */

/* Define to 1 if the xencpu plugin is enabled. */
/* #undef HAVE_PLUGIN_XENCPU */

/* Define to 1 if the xmms plugin is enabled. */
/* #undef HAVE_PLUGIN_XMMS */

/* Define to 1 if the zfs_arc plugin is enabled. */
/* #undef HAVE_PLUGIN_ZFS_ARC */

/* Define to 1 if the zone plugin is enabled. */
/* #undef HAVE_PLUGIN_ZONE */

/* Define to 1 if the zookeeper plugin is enabled. */
/* #undef HAVE_PLUGIN_ZOOKEEPER */

/* Define to 1 if you have the <poll.h> header file. */
#define HAVE_POLL_H 1

/* Define to 1 if you have the <pqos.h> header file. */
/* #undef HAVE_PQOS_H */

/* Define if libtool can extract symbol lists from object files. */
#define HAVE_PRELOADED_SYMBOLS 1

/* Define to 1 if you have the `processor_info' function. */
/* #undef HAVE_PROCESSOR_INFO */

/* Define to 1 if you have the procinfo.h */
/* #undef HAVE_PROCINFO_H */

/* Define to 1 if you have the <protobuf-c/protobuf-c.h> header file. */
/* #undef HAVE_PROTOBUF_C_PROTOBUF_C_H */

/* Define to 1 if you have the <pthread.h> header file. */
#define HAVE_PTHREAD_H 1

/* Define to 1 if you have the <pthread_np.h> header file. */
/* #undef HAVE_PTHREAD_NP_H */

/* pthread_setname_np() is available. */
#define HAVE_PTHREAD_SETNAME_NP 1

/* pthread_set_name_np() is available. */
/* #undef HAVE_PTHREAD_SET_NAME_NP */

/* Define to 1 if you have the <pwd.h> header file. */
#define HAVE_PWD_H 1

/* Define to 1 if you have the <Python.h> header file. */
/* #undef HAVE_PYTHON_H */

/* Define to 1 if you have the `readdir' function. */
#define HAVE_READDIR 1

/* Define to 1 if you have the `regcomp' function. */
#define HAVE_REGCOMP 1

/* Define to 1 if you have the `regerror' function. */
#define HAVE_REGERROR 1

/* Define to 1 if you have the `regexec' function. */
#define HAVE_REGEXEC 1

/* Define to 1 if you have the <regex.h> header file. */
#define HAVE_REGEX_H 1

/* Define to 1 if you have the `regfree' function. */
#define HAVE_REGFREE 1

/* Define to 1 if you have the <routeros_api.h> header file. */
/* #undef HAVE_ROUTEROS_API_H */

/* Define to 1 if you have the <rrd.h> header file. */
/* #undef HAVE_RRD_H */

/* Define to 1 if you have the <rte_config.h> header file. */
/* #undef HAVE_RTE_CONFIG_H */

/* Define if struct rtnl_link_stats64 exists and is usable. */
#define HAVE_RTNL_LINK_STATS64 1

/* Define to 1 if you have the `select' function. */
#define HAVE_SELECT 1

/* Define to 1 if you have the <sensors/sensors.h> header file. */
/* #undef HAVE_SENSORS_SENSORS_H */

/* Define if the function getmntent exists. It is the version from libseq. */
/* #undef HAVE_SEQ_GETMNTENT */

/* Define to 1 if you have the `setenv' function. */
#define HAVE_SETENV 1

/* Define to 1 if you have the `setgroups' function. */
#define HAVE_SETGROUPS 1

/* Define to 1 if you have the `setlocale' function. */
#define HAVE_SETLOCALE 1

/* Define if you have the shl_load function. */
/* #undef HAVE_SHL_LOAD */

/* Define to 1 if you have the <signal.h> header file. */
#define HAVE_SIGNAL_H 1

/* Define to 1 if you have the `socket' function. */
#define HAVE_SOCKET 1

/* Define to 1 if you have the `statfs' function. */
#define HAVE_STATFS 1

/* Define to 1 if you have the <statgrab.h> header file. */
/* #undef HAVE_STATGRAB_H */

/* Define to 1 if you have the `statvfs' function. */
#define HAVE_STATVFS 1

/* Define to 1 if you have the <stdarg.h> header file. */
#define HAVE_STDARG_H 1

/* Define to 1 if stdbool.h conforms to C99. */
#define HAVE_STDBOOL_H 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdio.h> header file. */
#define HAVE_STDIO_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the `strcasecmp' function. */
#define HAVE_STRCASECMP 1

/* Define to 1 if you have the `strchr' function. */
#define HAVE_STRCHR 1

/* Define to 1 if you have the `strcmp' function. */
#define HAVE_STRCMP 1

/* Define to 1 if you have the `strdup' function. */
#define HAVE_STRDUP 1

/* Define to 1 if you have the `strerror_r' function. */
#define HAVE_STRERROR_R 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the `strlcat' function. */
#define HAVE_STRLCAT 1

/* Define to 1 if you have the `strlcpy' function. */
#define HAVE_STRLCPY 1

/* Define to 1 if you have the `strlen' function. */
#define HAVE_STRLEN 1

/* Define to 1 if you have the `strncasecmp' function. */
#define HAVE_STRNCASECMP 1

/* Define to 1 if you have the `strncmp' function. */
#define HAVE_STRNCMP 1

/* Define to 1 if you have the `strncpy' function. */
#define HAVE_STRNCPY 1

/* Define to 1 if you have the `strptime' function. */
#define HAVE_STRPTIME 1

/* Define to 1 if you have the `strstr' function. */
#define HAVE_STRSTR 1

/* Define to 1 if you have the `strtol' function. */
#define HAVE_STRTOL 1

/* Define if struct if_data exists and is usable. */
/* #undef HAVE_STRUCT_IF_DATA */

/* Define to 1 if `ifi_ibytes' is a member of `struct if_data'. */
/* #undef HAVE_STRUCT_IF_DATA_IFI_IBYTES */

/* Define to 1 if `ifi_ierrors' is a member of `struct if_data'. */
/* #undef HAVE_STRUCT_IF_DATA_IFI_IERRORS */

/* Define to 1 if `ifi_opackets' is a member of `struct if_data'. */
/* #undef HAVE_STRUCT_IF_DATA_IFI_OPACKETS */

/* Define to 1 if `id' is a member of `struct inet_diag_req'. */
#define HAVE_STRUCT_INET_DIAG_REQ_ID 1

/* Define to 1 if `idiag_states' is a member of `struct inet_diag_req'. */
#define HAVE_STRUCT_INET_DIAG_REQ_IDIAG_STATES 1

/* Define to 1 if the system has the type `struct ip6_ext'. */
#define HAVE_STRUCT_IP6_EXT 1

/* Define to 1 if `imr_ifindex' is a member of `struct ip_mreqn'. */
#define HAVE_STRUCT_IP_MREQN_IMR_IFINDEX 1

/* Define if struct kinfo_proc2 exists in the NetBSD variant. */
/* #undef HAVE_STRUCT_KINFO_PROC2_NETBSD */

/* Define to 1 if `p_pid' is a member of `struct kinfo_proc2'. */
/* #undef HAVE_STRUCT_KINFO_PROC2_P_PID */

/* Define to 1 if `p_uru_maxrss' is a member of `struct kinfo_proc2'. */
/* #undef HAVE_STRUCT_KINFO_PROC2_P_URU_MAXRSS */

/* Define if struct kinfo_proc exists in the FreeBSD variant. */
/* #undef HAVE_STRUCT_KINFO_PROC_FREEBSD */

/* Define to 1 if `ki_pid' is a member of `struct kinfo_proc'. */
/* #undef HAVE_STRUCT_KINFO_PROC_KI_PID */

/* Define to 1 if `ki_rssize' is a member of `struct kinfo_proc'. */
/* #undef HAVE_STRUCT_KINFO_PROC_KI_RSSIZE */

/* Define to 1 if `ki_rusage' is a member of `struct kinfo_proc'. */
/* #undef HAVE_STRUCT_KINFO_PROC_KI_RUSAGE */

/* Define if struct kinfo_proc exists in the OpenBSD variant. */
/* #undef HAVE_STRUCT_KINFO_PROC_OPENBSD */

/* Define to 1 if `p_pid' is a member of `struct kinfo_proc'. */
/* #undef HAVE_STRUCT_KINFO_PROC_P_PID */

/* Define to 1 if `p_vm_rssize' is a member of `struct kinfo_proc'. */
/* #undef HAVE_STRUCT_KINFO_PROC_P_VM_RSSIZE */

/* Define if struct inet_diag_req exists and is usable. */
#define HAVE_STRUCT_LINUX_INET_DIAG_REQ 1

/* Define if struct net_device_stats exists and is usable. */
/* #undef HAVE_STRUCT_NET_DEVICE_STATS */

/* Define to 1 if `rx_bytes' is a member of `struct net_device_stats'. */
/* #undef HAVE_STRUCT_NET_DEVICE_STATS_RX_BYTES */

/* Define to 1 if `rx_errors' is a member of `struct net_device_stats'. */
/* #undef HAVE_STRUCT_NET_DEVICE_STATS_RX_ERRORS */

/* Define to 1 if `tx_packets' is a member of `struct net_device_stats'. */
/* #undef HAVE_STRUCT_NET_DEVICE_STATS_TX_PACKETS */

/* Define to 1 if `tx_window_errors' is a member of `struct
   rtnl_link_stats64'. */
#define HAVE_STRUCT_RTNL_LINK_STATS64_TX_WINDOW_ERRORS 1

/* Define to 1 if `dest' is a member of `struct udphdr'. */
/* #undef HAVE_STRUCT_UDPHDR_DEST */

/* Define to 1 if `source' is a member of `struct udphdr'. */
/* #undef HAVE_STRUCT_UDPHDR_SOURCE */

/* Define to 1 if `uh_dport' is a member of `struct udphdr'. */
#define HAVE_STRUCT_UDPHDR_UH_DPORT 1

/* Define to 1 if `uh_sport' is a member of `struct udphdr'. */
#define HAVE_STRUCT_UDPHDR_UH_SPORT 1

/* Define if the function getmntent exists. It is the version from libsun. */
/* #undef HAVE_SUN_GETMNTENT */

/* Define to 1 if you have the `swapctl' function. */
/* #undef HAVE_SWAPCTL */

/* Define if the function swapctl exists and takes three arguments. */
/* #undef HAVE_SWAPCTL_THREE_ARGS */

/* Define if the function swapctl exists and takes two arguments. */
/* #undef HAVE_SWAPCTL_TWO_ARGS */

/* Define to 1 if you have the `sysconf' function. */
#define HAVE_SYSCONF 1

/* Define to 1 if you have the `sysctl' function. */
/* #undef HAVE_SYSCTL */

/* Define to 1 if you have the `sysctlbyname' function. */
/* #undef HAVE_SYSCTLBYNAME */

/* Define if sysctl supports kern.cp_time */
/* #undef HAVE_SYSCTL_KERN_CP_TIME */

/* Define if sysctl supports kern.cp_times */
/* #undef HAVE_SYSCTL_KERN_CP_TIMES */

/* Define to 1 if you have the `syslog' function. */
#define HAVE_SYSLOG 1

/* Define to 1 if you have the <syslog.h> header file. */
#define HAVE_SYSLOG_H 1

/* Define to 1 if you have the <sys/dir.h> header file, and it defines `DIR'.
   */
/* #undef HAVE_SYS_DIR_H */

/* Define to 1 if you have the <sys/dkstat.h> header file. */
/* #undef HAVE_SYS_DKSTAT_H */

/* Define to 1 if you have the <sys/dl.h> header file. */
/* #undef HAVE_SYS_DL_H */

/* Define to 1 if you have the <sys/fstyp.h> header file. */
/* #undef HAVE_SYS_FSTYP_H */

/* Define to 1 if you have the <sys/fs_types.h> header file. */
/* #undef HAVE_SYS_FS_TYPES_H */

/* Define to 1 if you have the <sys/ioctl.h> header file. */
#define HAVE_SYS_IOCTL_H 1

/* Define to 1 if you have the <sys/isa_defs.h> header file. */
/* #undef HAVE_SYS_ISA_DEFS_H */

/* Define to 1 if you have the <sys/loadavg.h> header file. */
/* #undef HAVE_SYS_LOADAVG_H */

/* Define to 1 if you have the <sys/mntent.h> header file. */
/* #undef HAVE_SYS_MNTENT_H */

/* Define to 1 if you have the <sys/mnttab.h> header file. */
/* #undef HAVE_SYS_MNTTAB_H */

/* Define to 1 if you have the <sys/mount.h> header file. */
#define HAVE_SYS_MOUNT_H 1

/* Define to 1 if you have the <sys/ndir.h> header file, and it defines `DIR'.
   */
/* #undef HAVE_SYS_NDIR_H */

/* Define to 1 if you have the <sys/param.h> header file. */
#define HAVE_SYS_PARAM_H 1

/* Define to 1 if you have the <sys/resource.h> header file. */
#define HAVE_SYS_RESOURCE_H 1

/* Define to 1 if you have the <sys/rndio.h> header file. */
/* #undef HAVE_SYS_RNDIO_H */

/* Define to 1 if you have the <sys/select.h> header file. */
#define HAVE_SYS_SELECT_H 1

/* Define to 1 if you have the <sys/socket.h> header file. */
#define HAVE_SYS_SOCKET_H 1

/* Define to 1 if you have the <sys/statfs.h> header file. */
#define HAVE_SYS_STATFS_H 1

/* Define to 1 if you have the <sys/statvfs.h> header file. */
#define HAVE_SYS_STATVFS_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/swap.h> header file. */
#define HAVE_SYS_SWAP_H 1

/* Define to 1 if you have the <sys/sysctl.h> header file. */
/* #undef HAVE_SYS_SYSCTL_H */

/* Define to 1 if you have the <sys/sysmacros.h> header file. */
#define HAVE_SYS_SYSMACROS_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <sys/ucred.h> header file. */
/* #undef HAVE_SYS_UCRED_H */

/* Define to 1 if you have the <sys/un.h> header file. */
#define HAVE_SYS_UN_H 1

/* Define to 1 if you have the <sys/vfstab.h> header file. */
/* #undef HAVE_SYS_VFSTAB_H */

/* Define to 1 if you have the <sys/vfs.h> header file. */
#define HAVE_SYS_VFS_H 1

/* Define to 1 if you have the <sys/vmmeter.h> header file. */
/* #undef HAVE_SYS_VMMETER_H */

/* Define to 1 if you have <sys/wait.h> that is POSIX.1 compatible. */
#define HAVE_SYS_WAIT_H 1

/* True if the enum-member TCA_STATS exists */
#define HAVE_TCA_STATS 1

/* True if the enum-member TCA_STATS2 exists */
#define HAVE_TCA_STATS2 1

/* Define to 1 if you have the <tcrdb.h> header file. */
/* #undef HAVE_TCRDB_H */

/* Define to 1 if you have the <termios.h> header file. */
#define HAVE_TERMIOS_H 1

/* Define to 1 if the rrd library is thread-safe */
/* #undef HAVE_THREADSAFE_LIBRRD */

/* Define to 1 if you have the `thread_info' function. */
/* #undef HAVE_THREAD_INFO */

/* Define if the function getmntent exists and takes two arguments. */
/* #undef HAVE_TWO_GETMNTENT */

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to 1 if you have the <upsclient.h> header file. */
/* #undef HAVE_UPSCLIENT_H */

/* Define to 1 if the system has the type `UPSCONN'. */
/* #undef HAVE_UPSCONN */

/* Define to 1 if the system has the type `UPSCONN_t'. */
/* #undef HAVE_UPSCONN_T */

/* Define to 1 if you have the <utmpx.h> header file. */
#define HAVE_UTMPX_H 1

/* Define to 1 if you have the <utmp.h> header file. */
#define HAVE_UTMP_H 1

/* Define to 1 if you have the <vapi/vsc.h> header file. */
/* #undef HAVE_VAPI_VSC_H */

/* Define to 1 if you have the <varnishapi.h> header file. */
/* #undef HAVE_VARNISHAPI_H */

/* Varnish 2 API support */
/* #undef HAVE_VARNISH_V2 */

/* Varnish 3 API support */
/* #undef HAVE_VARNISH_V3 */

/* Varnish 4 API support */
/* #undef HAVE_VARNISH_V4 */

/* Define to 1 if you have the <vm/anon.h> header file. */
/* #undef HAVE_VM_ANON_H */

/* Define to 1 if you have the <vsc.h> header file. */
/* #undef HAVE_VSC_H */

/* Define to 1 if you have the <wordexp.h> header file. */
#define HAVE_WORDEXP_H 1

/* This value is set to 1 to indicate that the system argz facility works */
/* #undef HAVE_WORKING_ARGZ */

/* Define to 1 if you have the <xenctrl.h> header file. */
/* #undef HAVE_XENCTRL_H */

/* Define to 1 if you have the <xfs/xqm.h> header file. */
/* #undef HAVE_XFS_XQM_H */

/* Define to 1 if you have the <yajl/yajl_parse.h> header file. */
/* #undef HAVE_YAJL_YAJL_PARSE_H */

/* Define to 1 if you have the <yajl/yajl_version.h> header file. */
/* #undef HAVE_YAJL_YAJL_VERSION_H */

/* Define to 1 if the system has the type `_Bool'. */
#define HAVE__BOOL 1

/* True if program is to be compiled for a AIX kernel */
/* #undef KERNEL_AIX */

/* True if program is to be compiled for a Darwin kernel */
/* #undef KERNEL_DARWIN */

/* True if program is to be compiled for a FreeBSD kernel */
/* #undef KERNEL_FREEBSD */

/* True if program is to be compiled for a Linux kernel */
#define KERNEL_LINUX 1

/* True if program is to be compiled for a NetBSD kernel */
/* #undef KERNEL_NETBSD */

/* True if program is to be compiled for an OpenBSD kernel */
/* #undef KERNEL_OPENBSD */

/* True if program is to be compiled for a Solaris kernel */
/* #undef KERNEL_SOLARIS */

/* Define to used libtool version. */
#define LIBTOOL_VERSION 2

/* Define if the OS needs help to load dependent libraries for dlopen(). */
/* #undef LTDL_DLOPEN_DEPLIBS */

/* Define to the system default library search path. */
#define LT_DLSEARCH_PATH "/lib:/usr/lib:/usr/lib/x86_64-linux-gnu/libfakeroot:/lib/i386-linux-gnu:/usr/lib/i386-linux-gnu:/lib/i686-linux-gnu:/usr/lib/i686-linux-gnu:/usr/local/lib:/lib/x86_64-linux-gnu:/usr/lib/x86_64-linux-gnu:/usr/lib/x86_64-linux-gnu/mesa-egl:/usr/lib/x86_64-linux-gnu/mesa:/lib32:/usr/lib32:/libx32:/usr/libx32"

/* The archive extension */
#define LT_LIBEXT "a"

/* The archive prefix */
#define LT_LIBPREFIX "lib"

/* Define to the extension used for runtime loadable modules, say, ".so". */
#define LT_MODULE_EXT ".so"

/* Define to the name of the environment variable that determines the run-time
   module search path. */
#define LT_MODULE_PATH_VAR "LD_LIBRARY_PATH"

/* Define to the sub-directory in which libtool stores uninstalled libraries.
   */
#define LT_OBJDIR ".libs/"

/* Define if NAN is defined by default and can initialize static variables. */
/* #undef NAN_STATIC_DEFAULT */

/* Define if NAN is defined by __USE_ISOC99 and can initialize static
   variables. */
/* #undef NAN_STATIC_ISOC */

/* Define if NAN can be defined as (0.0 / 0.0) */
#define NAN_ZERO_ZERO 1

/* Define if dlsym() requires a leading underscore in symbol names. */
/* #undef NEED_USCORE */

/* Name of package */
#define PACKAGE "collectd"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT ""

/* Define to the full name of this package. */
#define PACKAGE_NAME "collectd"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "collectd 5.7.1.git"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "collectd"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "5.7.1.git"

/* Define to 1 if your version of the 'perfstat' library supports donation */
/* #undef PERFSTAT_SUPPORTS_DONATION */

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Define to 1 if strerror_r returns char *. */
/* #undef STRERROR_R_CHAR_P */

/* Set to true if strptime is only exported in X/Open mode (GNU libc). */
/* #undef STRPTIME_NEEDS_STANDARDS */

/* Define to 1 if you can safely include both <sys/time.h> and <time.h>. */
#define TIME_WITH_SYS_TIME 1

/* Version number of package */
#define VERSION "5.7.1.git"

/* Define to 1 if `lex' declares `yytext' as a `char *' by default, not a
   `char[]'. */
/* #undef YYTEXT_POINTER */

/* Enable large inode numbers on Mac OS X 10.5.  */
#ifndef _DARWIN_USE_64_BIT_INODE
# define _DARWIN_USE_64_BIT_INODE 1
#endif

/* Number of bits in a file offset, on hosts where this is settable. */
/* #undef _FILE_OFFSET_BITS */

/* Define to enforce ISO C99 compliance. */
/* #undef _ISOC99_SOURCE */

/* Define for large files, on AIX-style hosts. */
/* #undef _LARGE_FILES */

/* Define to enforce POSIX.1-2008 compliance. */
/* #undef _POSIX_C_SOURCE */

/* Define to enforce POSIX thread semantics under Solaris. */
/* #undef _POSIX_PTHREAD_SEMANTICS */

/* Define to enable reentrancy interfaces. */
/* #undef _REENTRANT */

/* Define to use the thread-safe version of errno under AIX. */
/* #undef _THREAD_SAFE_ERRNO */

/* Define to enforce X/Open 7 (XSI) compliance. */
/* #undef _XOPEN_SOURCE */

/* Define so that glibc/gnulib argp.h does not typedef error_t. */
#define __error_t_defined 1

/* Define to empty if `const' does not conform to ANSI C. */
/* #undef const */

/* Define to a type to use for `error_t' if it is not otherwise available. */
#define error_t int

/* Define to `int' if <sys/types.h> doesn't define. */
/* #undef gid_t */

/* Define to `int' if <sys/types.h> does not define. */
/* #undef pid_t */

/* Define to `unsigned int' if <sys/types.h> does not define. */
/* #undef size_t */

/* Define to `int' if <sys/types.h> doesn't define. */
/* #undef uid_t */
