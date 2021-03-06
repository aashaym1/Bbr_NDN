Implementation Of BBR algorithm in NDN

**Summary:**

This repository is an implementation of the BBR(Bottleneck Bandwidth and Round-trip propagation time) queueing algorithm in NDN(Named-data-Networks)

**BBR:**

BBR is a bandwidth-based queueing algorithm where instead of focusing on bandwidth based congestion control instead of loss-based congestion control. This was done to manage throughput and maintain a consistent throughput. A better explanation can be found here: [https://cloud.google.com/blog/products/gcp/tcp-bbr-congestion-control-comes-to-gcp-your-internet-just-got-faster](https://cloud.google.com/blog/products/gcp/tcp-bbr-congestion-control-comes-to-gcp-your-internet-just-got-faster)

**NDN:**

This algorithm is implemented into NDN-chunks. NDN is a new network layer architecture to replace the IP layer of the current internet. The motivation is to move to a CCN(Content centric network) based architecture. The reasoning behind the same is the changing needs of the average internet user. For platforms which are linked to E-commerce, online banking, streaming an end to end communication-based architecture(like IP) is sufficient yet not optimal. There are numerous advantages to moving to a CCN based architecture including the removal of DHCP, added security, etc.

A more detailed explanation can be found here: [https://named-data.net/project/archoverview/](https://named-data.net/project/archoverview/)

Running: In order to run the code you would first need to install ndn-tools and it&#39;s dependencies. Instructions for the same can be found here: [https://github.com/named-data/ndn-tools/blob/master/INSTALL.md](https://github.com/named-data/ndn-tools/blob/master/INSTALL.md)

Once ndn-tools is successfully installed:
