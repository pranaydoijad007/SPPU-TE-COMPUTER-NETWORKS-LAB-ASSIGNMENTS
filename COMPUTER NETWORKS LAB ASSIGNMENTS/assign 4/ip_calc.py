#!/usr/bin/env python
import ipaddress
import sys

for arg in sys.argv[1:]:
    print(arg)    #printing command line argument 1
    addr = ipaddress.ip_interface(arg)  #extracting address
    print("IP address =", addr.ip)
    print("Netmask =", addr.netmask)
    print("Network Address =", addr.network.network_address)
    print("Broadcast Address=", addr.network.broadcast_address)
    start_ip = addr.network.network_address + 1
    end_ip = addr.network.broadcast_address - 1
    print("Range:",start_ip,"to",end_ip)
    print("Max Nodes:",addr.network.num_addresses-2)
    print()
