CXX = gcc
CXXFLAGS += -g -Wall -Wextra

NGX_ROOT = /letv/fet/work/nginx-1.10.2/test/

TARGETS = ngx_pool_t_test
TARGETS_C_FILE = $(TARGETS).c

CLEANUP = rm -f $(TARGETS) *.o

all: $(TARGETS)

clean:
	$(CLEANUP)

CORE_INCS = -I. \

NGX_PALLOC = $(NGX_ROOT)/ngx_palloc.c  
NGX_ALLOC = $(NGX_ROOT)/ngx_alloc.c  

$(TARGETS): $(TARGETS_C_FILE)  
	$(CXX) $(CXXFLAGS) $(CORE_INCS) $(NGX_PALLOC) $(NGX_ALLOC) $^ -o $@  
