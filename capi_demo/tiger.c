#include <stdio.h>
#include <lua/lua.h>
#include <lua/lauxlib.h>
#include <lua/lualib.h>

static int tiger_test(lua_State *L)
{
    return 0;
}

static int tiger_add_two(lua_State *L)
{
    // TODO
    int a, b;

    a = luaL_checknumber(L, 1);
    b = luaL_checknumber(L, 2);
    lua_pushnumber(L, a + b);
    
    /* 返回的参数有几个这里就填几 */
    return 1;
}

static const struct luaL_Reg tigerlib[] = {
    {"test", tiger_test},
    {"add_two", tiger_add_two},
    {NULL, NULL}
};

/**
 * luaopen_ + 模块名 , 在lua中被调用是 require "模块名"，当前模块名为tiger
 * 返回值要写1，不能写0，这个和c也是不一样的
 */
LUALIB_API int luaopen_tiger(lua_State *L)
{
#if LUA_VERSION_NUM >= 502
    luaL_newlib(L, tigerlib);
#else
    luaL_register(L, "tiger", tigerlib);
#endif

    return 1;
}
