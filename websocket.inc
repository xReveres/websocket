#define USING_MAXCOIN

#define MAX_WEBSOCKETS 32
#define MAX_BUFFER_SIZE	2048


#define WS_DATA_TYPE_TEXT			0
#define WS_DATA_TYPE_BINARY			1

#define WS_STATE_CONNECTING			0
#define WS_STATE_OPEN				1
#define WS_STATE_CLOSING			2
#define WS_STATE_CLOSED				3

#define WS_CLOSE_REASON_NORMAL 			1000
#define WS_CLOSE_REASON_GOING_AWAY 		1001
#define WS_CLOSE_REASON_PROTOCOL_ERROR 		1002
#define WS_CLOSE_REASON_UNPROCESSABLE_INPUT 	1003
#define WS_CLOSE_REASON_RESERVED 		1004 // Reserved value.  Undefined meaning.
#define WS_CLOSE_REASON_NOT_PROVIDED 		1005 // Not to be used on the wire
#define WS_CLOSE_REASON_ABNORMAL 		1006 // Not to be used on the wire
#define WS_CLOSE_REASON_INVALID_DATA 		1007
#define WS_CLOSE_REASON_POLICY_VIOLATION 	1008
#define WS_CLOSE_REASON_MESSAGE_TOO_BIG 	1009
#define WS_CLOSE_REASON_EXTENSION_REQUIRED 	1010
#define WS_CLOSE_REASON_INTERNAL_SERVER_ERROR 	1011
#define WS_CLOSE_REASON_TLS_HANDSHAKE_FAILED 	1015 // Not to be used on the wire

#define WS_BIND_OPEN				0
#define WS_BIND_RECEIVE_TEXT			1
#define WS_BIND_RECEIVE_BINARY			2
#define WS_BIND_CLOSE				3
#define WS_BIND_PONG				4
#define WS_BIND_ERROR				5

/*
 *	Create WebSocket connection handle
 *	retruns websocket handle
*/
native ws_create();

/*
 *	Bind WebSocket event.
 *		bind_type - WS_BIND_* all events
*/
native ws_bind(const WSIndex, bind_type, const fname[]);

/*
 *	Destroy WebSocket connection handle
 *	returns 1 if successfully destroyed or 0 if socket is not closed or -1 when handle is already destroyed
*/
native ws_destroy(const WSIndex);

/*
 *	Create WebSocket connection
 *		ip - host ip address
 *		port - host port
 *		path - must contain '/' character before path or if u want use empty path !
 *	retruns (sockets error) or 1 if successfully opened or -1 when is handle destroyed or -2 when connection is not closed
*/
native ws_open(const WSIndex, const ip[], port, const path[]);

/*
 *	Reconnect to the last opened connection
 *	retruns (sockets error) or 1 if successfully opened or -1 when is handle destroyed or -2 when connection is not closed
*/
native ws_reconnect(const WSIndex);

/*
 *	Send data to server
 *	returns
 *	 -1 when handle is unused
 *	 -2 when websocket is not opened
 *	 1 when successfully send
*/
native ws_send(const WSIndex, type, bool:useMask, const data[], len=0);

/*
 *	Send ping packet to server
 *	pong should be called to callback
 *	TODO !
*/
native ws_ping(const WSIndex);

/*
 *	Close connection
 *		iReason - defines from WS_CLOSE_REASON_*
 *		reason[] - optional payload
*/
native ws_close(const WSIndex, const reason[]="", iReason=WS_CLOSE_REASON_NORMAL);

/*
 *	Get state of WebSocket connection handle
 *	returns WS_State
 *	 or -1 if handle is unused
*/
native ws_state(const WSIndex);
/* AMXX-Studio Notes - DO NOT MODIFY BELOW HERE
*{\\ rtf1\\ ansi\\ deff0{\\ fonttbl{\\ f0\\ fnil Tahoma;}}\n\\ viewkind4\\ uc1\\ pard\\ lang1045\\ f0\\ fs16 \n\\ par }
*/
