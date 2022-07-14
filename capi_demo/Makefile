
# 这里不能像编写c的动态库一样命名，因为lua的规则是去检索tiger.so这个全名
LIBNAME := tiger.so
CFLAGS += -g -Wall -llua5.3.5
# 这里根据当前设备版本lua默认查找的路径来填写
PATH_LIB := /usr/lib64/lua/5.3

all: build install

build: $(LIBNAME)

$(LIBNAME): tiger.c
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $<

install:
	cp -f $(LIBNAME) $(PATH_LIB)

uninstall:
	rm -rf $(PATH_LIB)/$(LIBNAME)


clean: uninstall
	rm -rf *.so

.PHONY: all build clean install uninstall
