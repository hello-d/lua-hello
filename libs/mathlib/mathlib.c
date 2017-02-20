#include <stdio.h>
#include "mathlib.h"

static int math_average(lua_State *L) {
	int n = lua_gettop(L);
	double sum = 0;
	int i;

	for (i = 1; i <= n; i++) {
		sum += lua_tonumber(L, i);
	}
	// 压入平均值 
	lua_pushnumber(L, sum / n);
	// 压入和
	lua_pushnumber(L, sum);

	// 返回两个结果
	return 2;                   
}

static int math_hello(lua_State* L) {
	printf("hello world!");
	return 0;
}

static const struct luaL_Reg math_funs[] = {
	{ "average", math_average },
	{ "hello", math_hello },
	{ NULL, NULL }
};

LUAMOD_API int luaopen_mathlib(lua_State *L) {
	luaL_openlib(L, "ml", math_funs, 0);
	return 0;
}