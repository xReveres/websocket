/* Plugin generated by AMXX-Studio */

#include <amxmodx>
#include <amxmisc>
#include "./websocket.inc"

#define PLUGIN "New Plug-In"
#define VERSION "1.0"
#define AUTHOR "Reveres"

new Handle;

public plugin_init() {
	register_plugin(PLUGIN, VERSION, AUTHOR)
	
	set_task(5.0, "startopen");
}

public startopen()
{
	server_print("- [TEST] Creating WS handle");
	Handle = ws_create();
	server_print("- [TEST] Handle created %d", Handle);
	
	ws_bind(Handle, WS_BIND_OPEN, "OnWSOpened");
	ws_bind(Handle, WS_BIND_RECEIVE_TEXT, "OnWSReceivedText");
	//ws_bind(Handle, WS_BIND_RECEIVE_BINARY, "OnWSReceivedBinary");
	ws_bind(Handle, WS_BIND_CLOSE, "OnWSClosed");
	ws_bind(Handle, WS_BIND_ERROR, "OnWSError");
	
	server_print("- [TEST] ws_open...");
	new status = ws_open(Handle, "echo.websocket.org", 80, "/");
	server_print("- [TEST] Opened with status %d", status);
}

public OnWSOpened()
{
	server_print("- [TEST] OnWSOpened called");
	ws_send(Handle, WS_DATA_TYPE_TEXT, false, "Hello world");
	//ws_send(Handle, WS_DATA_TYPE_BINARY, false, "xxx", 3);
	set_task(10.0, "close");
}

public close()
{
	server_print("- [TEST] closing connection");
	ws_close(Handle, "Goodbye");
	//set_task(5.0, "reconnect");
}

public reconnect()
{
	new status = ws_reconnect(Handle);
	server_print("- [TEST] Reconnected with status %d", status);
}

public OnWSReceivedText(const text[])
{
	server_print("- [TEST] OnWSReceivedText called. %s", text);
}

public OnWSReceivedBinary(const data[], dataLen)
{
	server_print("- [TEST] OnWSReceivedBinary called. %d", dataLen);
}

public OnWSClosed(reason, const data[])
{
	server_print("- [TEST] OnWSClose called. %s | %d", data, reason);
}

public OnWSError(reason)
{
	server_print("- [TEST] OnWSError called. %d", reason);
}
