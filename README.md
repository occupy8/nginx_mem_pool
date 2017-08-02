# nginx_mem_pool

从nginx里弄出来的mempool

它的思想是，小块内存，多次从内存池申请，一次释放，大块内存malloc

缺点是：不能随意free。业务上有局限性
