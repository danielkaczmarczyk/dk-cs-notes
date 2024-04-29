# how to ssh into devices on the same wifi network

This assumes both are macos devices.

1. Broadcast a ping to all the devifes on your network to populate the arp table. Check your setup for that ip or guess - usually it is the network address with the last octet set to 255, i.e. 192.168.1.255. `ping 192.168.1.255`. Let it run for a few seconds.
2. Use `arp -a` to list all the IP addresses and corresponding MAC addresses for all devices on the network.
3. Use the hostname or MAC address of the device you want to ssh into and run `ssh username@ip-address`.

Note - unless you explicitly set it not to, the IP of the target device will change. Consult your router manual on how to set a static address.
