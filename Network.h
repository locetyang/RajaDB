/*****************************************************************************\
* Copyright (c), Future Entertainment World / Seoul, Republic of Korea        *
* All Rights Reserved.                                                        *
*                                                                             *
* This document contains proprietary and confidential information.  No        *
* parts of this document or the computer program it embodies may be in        *
* any way copied, duplicated, reproduced, translated into a different         *
* programming language, or distributed to any person, company, or             *
* corporation without the prior written consent of Future Entertainment World *
\*****************************************************************************/

#ifndef _DRAGON_PROTOCOL_
#define _DRAGON_PROTOCOL_

#include "stdafx.h"
#include "define.h"

#include "hsel.h"
#include "sqltypes.h"

#ifdef __CLIENT_PROGRAM__
	#include "ItemTable.h"
#else
	#include "charlist.h" 
	#include "ItemList.h"
#endif

#define SIZE_OF_WS				(200 * sizeof( unsigned char ))
#define SIZE_OF_PS				(200 * sizeof( unsigned char ))
#define SIZE_OF_SKILL			(200 * sizeof( unsigned char ))	//1219 YGI
#define SIZE_OF_SKILL_EXP		(45  * sizeof( unsigned int	 ))	
#define SIZE_OF_TAC_SKILL_EXP	(13  * sizeof( unsigned int	 ))	

#define SIZE_OF_SCRIPT_VAR		(300 * sizeof( int ))	
#define	SIZE_OF_INV				(3*3*8* sizeof( ItemAttr )) 
#define	SIZE_OF_EQUIP			(    8* sizeof( ItemAttr )) 
#define	SIZE_OF_QUICK			(    6* sizeof( ItemAttr )) 
#define SIZE_OF_BANKITEM		(5*3*6* sizeof( ItemAttr )) 

#define	SIZE_OF_PARTY			(    31 * 6 )
#define	SIZE_OF_RELATION		(    31 * 3 ) 
#define	SIZE_OF_EMPLOYMENT		(    31 * 6 ) 
#define	SIZE_OF_ITEMINDEX		(  1000 * sizeof( short int ) )

#define MAX_CHECK_IP_		3
#define MAX_STORE_LIST			30		//1213
#define MAX_STORE_ITEM_LIST    300		// 0710 YGI
#define OPTIMIZE_COUNT					10
#define VERSION				  			20
#define LOGIN_QUEUE						50
#define DRAGON_QUEUE					50
#define LOGIN_MAX_CONNECTIONS			MAX_USER_NUM
#define DRAGON_MAX_CONNECTIONS			1
#define DRAGON_CONNECTIONS_START		2
#define LOGIN_SERVER_CONNECT			0	// 공지사항 모든 서버에 연결하기 위한 서버 wka
#define DB_DEMON						1	//	게임서버에 할당된 DB데몬
#define PACKEET_SEND_TRY				10

#define CONNECT_FAIL					0
#define CONNECT_OK						1
#define CONNECT_LOGIN_KEIN				2	// 맵간 이동
#define CONNECT_LOGIN					3
#define CONNECT_JOIN					4
#define CONNECT_JOIN_START				5

#define MAX_CHARACTEROFID				4 
#define MAX_PACKET_SIZE					3000
#define MAX_SERVER_QUEUE_OUT_BUFFER		(1024*1024*10 )
#define MAX_CLIENT_QUEUE_OUT_BUFFER		16584
#define MAX_DIR_TABLE					256

#define ID_LENGTH						20
#define PW_LENGTH						20
#define NM_LENGTH						20
#define IP_LENGTH						16
#define TEXT_LENGTH						255

//--------------------------------------------------------
#define CMD_NONE						0

#define CMD_INVALID_ID					1
#define CMD_INVALID_PW					2
#define CMD_INVALID_DB					3
#define CMD_INVALID_PAY					4
										 
#define CMD_PING						5
 
#define CMD_ACCESS_LOGIN				6066	//010707 lsw 수정 
#define CMD_ACCEPT_LOGIN				6067	//010707 lsw 수정 
#define CMD_ACCESS_LOGOUT				12
#define CMD_ACCEPT_CREATE				13
#define CMD_USED_ID						14
#define CMD_ACCEPT_DELETE				15
#define CMD_INVALID_VERSION				16
#define CMD_INVALID_AGE					17		// 030929 kyo


#define CMD_USER_ADD					20
#define CMD_USER_REMOVE					21
#define CMD_YOU_REMOVE					22

#define CMD_ACCESS_JOIN					30
#define CMD_ASSIGN_SERVER_ID			31

#define CMD_ACCEPT_JOIN					32
typedef struct server_accept_join
{
	short int x, y;
}t_server_accept_join;

#define CMD_ALL_READY					33
typedef struct all_ready
{
	short int x,y;

}t_all_ready;

#define CMD_USER_DB						40
#define CMD_ENVIR_INFO					41

#define CMD_CREATE_CHAR					50
#define CMD_DELETE_CHAR                 52

#define	CMD_NPC_ADD						60	
#define	CMD_NPC_REMOVE					61

#define	CMD_ITEM_ADD 					70
#define	CMD_ITEM_REMOVE					71
#define	CMD_ITEM_DROP					72
#define	CMD_ITEM_TAKE					73
#define	CMD_ITEM_EQUIP					74
#define	CMD_YOU_GOT_ITEM				75
#define CMD_ITEM_STATUS					76
#define CMD_CHANGE_EQUIP				77
#define CMD_ITEM_ATTR_CHANGE			78
#define CMD_ITEM_DOOR_OPEN_CLOSE		79
typedef struct item_door_open_close			
{
	short int item_id;
	char  openclose;
}t_item_door_open_close;

#define CMD_ITEM_BOX_BREAK				210		
typedef struct client_item_box_break
{
	short int		item_id;
}t_client_item_box_break;
typedef struct server_item_box_break
{
	short int		server_id;
	short int		item_id;
	char			type;

}t_server_item_box_break;

											
#define CMD_ITEM_BOX_BREAK_RESULT		212	
typedef struct client_item_box_break_result	
{														
	short int		item_id;				
}t_client_item_box_break_result;				
											
#define CMD_ITEM_BOX_REFRESH			211	
											
// 매직으로 아이템을 부술때 사용한다.		
#define CMD_ITEM_BOX_MAGIC_BREAK		214		
typedef struct client_item_box_magic_break	
{													
	short int		item_id;					
}t_client_item_box_magic_break;						
											
#define CMD_ITEM_BOX_MAGIC_BREAK_RESULT	213 
typedef struct server_item_box_magic_break_result
{												
	short int		item_id;							
	char			type;								
}t_server_item_box_magic_break_result;							
											

#define CMD_JUST_ATTACK_ANIMATION		215
typedef struct client_just_attack_animation{
	short int		item_id;
}t_client_just_attack_animation;


//2001/11/20 zhh
#define CMD_LOGIN_FAIL_MASSAGE						13006
typedef struct client_login_fail_reason
{
	int		dwType;					//로그인이 어떤이유에서 안되는지의 원인 . switch문 용
	char	szExpireDate[12];		//끝나는 날짜가 들어간다.
	char	cPaytype;				//결제의 종류가 들어간다. ex) 포인트, 날짜. 등등
	long	dwPoint;				//남아있는 포인트
	char	cReserverdData;			//만약 같은 타입이라도 경우에 따라서 다른 메시지가 찍혀야 할 경우를 대비한 변수.
}t_client_login_fail_reason;

#define CMD_MOVE						6100	//010707 lsw 수정
#define CMD_ATTACK						6200	//010707 lsw 수정
#define CMD_CHAT_DATA					6250	//010707 lsw 수정
#define CMD_WEATHER						83	
												
#define CMD_STARTING_MAGIC				84	
#define CMD_DOING_MAGIC					6220	//010707 lsw 수정

#define CMD_NPC_ATTACK					86

///////////////// 0604 lkh 수정 /////////////////
typedef struct npc_attack
{
	short int	attack_id;
	short int	defend_id;

	short int	backdraw_X;
	short int	backdraw_Y;
}t_npc_attack;

											
#define CMD_MAGIC_RESULT				87	
typedef struct client_magic_result			
{											
	short int magic_no;						
	short int target_id;					
	short int x, y;							
}t_client_magic_result;							
											
typedef struct server_magic_result			
{											
	short int magic_no;
//	short int caster_id;
	short int target_id;
//	short int x, y;
	char	  type;
	short int Change_HP;
	short int Change_MP;
	////////////////////// 1228 이규훈 수정 ///////////////////////////
	BYTE	  Condition;
	//////////////////////////////////////////////////////////////////
}t_server_magic_result;


#define CMD_INSERT_MAGIC				624
typedef struct server_insert_magic
{
	short int item_id;
	short int effectno;
	short int tx, ty;
}t_server_insert_magic;


	


//------------ 은행 메뉴 추가 -------------------------------

#define	REQ_MY_DEPOSIT_INFO				90
#define	REP_YOUR_DEPOSIT_INFO			91

#define	REQ_MY_REPAYMENT_INFO			92
#define	REP_YOUR_REPAYMENT_INFO			93

//------------------------------------------------------------------

#define	CMD_CHR_ITEM_INFO_0				5000	// Inventory
#define	CMD_CHR_ITEM_INFO_1				5001	// Equip
#define	CMD_CHR_ITEM_INFO_2				5002	// quick.

// server_char_basic_data
#define CMD_CHAR_INFO_BASIC 			5003
typedef struct char_info_basic
{	short int kind;
	DWORD  data;
	char   password;

}t_char_info_basic;



#define CMD_CHAR_INFO_MAGIC				5004
typedef struct char_info_magic{	
	unsigned char magic[ 200 ];
}t_char_info_magic;


#define CMD_CHAR_INFO_SKILL				5005
typedef struct char_info_skill{	
	unsigned char skill[ 200 ];
}t_char_info_skill;


#define CMD_OTHER_INFO_BASIC 			5006
typedef struct other_info_basic
{	short int server_id;
	short int kind;
	DWORD  data;
}t_other_info_basic;



#define CMD_GIVE_ITEM					5007
typedef struct server_give_item	
{
	char p1, p2, p3;
	ItemAttr item;
}t_server_give_item;

typedef struct client_item_inv // 1218 YGI
{
	short int count;
}k_client_item_inv;



#define CMD_CHAR_INFO_TAC_SKILL_EXP		5008
typedef struct char_info_tac_skillexp
{
	unsigned int tac_skillEXP[ 13];

}t_char_info_tac_skillexp;


#define CMD_ITEM_EXCHANGE				88
#define CMD_ITEM_EXCHANGE_REFUSE		89

#define CMD_ITEM_EQUIP_OK				98

#define CMD_FOOT_ON_TRAP_0_ITEM			99
//< CSD-010907
/*
typedef struct client_foot_on_trap0
{
	short int server_id;
}t_client_foot_on_trap0;

typedef struct server_foot_on_trap0
{
	short int server_id;
	short int item_id;
	short int hp;
}t_server_foot_on_trap0;
*/
struct t_client_foot_on_trap0
{
  WORD idServer;
};

struct t_server_foot_on_trap0
{
  WORD idServer;
  WORD idItem;
  __int32 nLife;
};
//> CSD-010907

#define CMD_FOOT_ON_TRAP_1_ITEM			621
//< CSD-010907
/*
typedef struct client_foot_on_trap1
{
	short int server_id;
}t_client_foot_on_trap1;

typedef struct server_foot_on_trap1
{
	short int server_id;
	short int item_id;
	short int hp;
}t_server_foot_on_trap1;
*/
struct t_client_foot_on_trap1
{
  WORD idServer;
};

struct t_server_foot_on_trap1
{
  WORD idServer;
  WORD idItem;
  __int32 nLife;
};
//> CSD-010907


#define CMD_ATTACK_RESULT				6110	//010707 lsw 수정 

//----------- Event ---------------------------------
#define CMD_EVENT						100
#define CMD_DOOR_OPEN					101
#define CMD_DOOR_CLOSE					102

// ------- Change Map	----------------------------
#define CMD_CHANGE_MAP					110



#define CMD_MODIFY_POSITION				111
typedef struct server_modidy_position
{
	short int server_id;
	short int gox, goy;
}t_server_modify_position;
typedef struct client_modify_posotion
{
	short int x, y;
}t_client_modify_position;

#define CMD_MODIFY_POSITION_ABSOLUTE	112
typedef struct server_modify_position_absolute
{
	short int id;
	short int x, y;
}t_server_modify_position_absolute;










// ----------  추가 Data 요구---------------------
// 보내지 않은 user/npc/item에 대한 정보가 왔을때 
// 기본 Data를 보내달라고 요구한다. 
#define REQ_NPC_ADD						1000	
#define REQ_PC_ADD						1001
#define REQ_ITEM_ADD					1002

#define CMD_LOST_CONNECTION				127

#define CMD_CONNECT_INFO				200
#define CMD_CONNECT_INFO1				10000		// 1218 YGI

#define CMD_INTERFACE_PEACE				300
#define CMD_INTERFACE_BATTLE			301


// 메뉴,..
#define CMD_CALL_SMALLMENU				2000
#define CMD_STORE_ITEMLIST				2001
#define CMD_ITEM_BUY_REQ				128
#define CMD_ITEM_SELL_REQ				129
#define CMD_MENU_MESSAGE				140
//------------------------------------------------------------------------------------
//길드 Menu 
#define CMD_GUILD_INFO					7000
typedef struct server_guild_info
{
	short int guildindex;
	short int storeindex;
	short int repairindex;
}t_server_guild_info;


#define CMD_LEARN_SKILL					7010
typedef struct client_learn_skill
{ 
	short int guildindex;
	short int skillno;
}t_client_learn_skill;
//			( 어떻게..배우지? 실습을 하나? )
typedef struct server_learn_skill
{
	short int guildindex;
	short int skillno;
	short int money;
	short int skillexp;
}t_server_learn_skill;

	
#define CMD_LEARN_SKILLITEM				7020		
typedef struct server_learn_skillitem
{
	short int		skillitemno[ 30];
	short int		shillmoney[ 30];
	unsigned char	required_lv[30];
}t_server_learn_skillitem;


// 클라이언트 -> 서버 : 
// 길드에서 Item Repair하고자 하는 List를 요구한다.   
#define CMD_ITEM_REPAIR_REQ				7030

#define CMD_REPAIR_ITEMLIST				7040
typedef struct server_repair_itemlist
{
	char  array;
	short int item[ 10]; // 길드에서 취급하는 Item목록.
}t_server_repair_itemlist;


// 
#define CMD_ITEM_REPAIR					7050
typedef struct client_item_repair
{
	short int repairindex;
	short int itemposition;
}t_client_item_repair;
typedef struct server_item_repair
{
	short int	 itemposition;
	ItemAttr	 item;
	unsigned int money;
}t_server_item_repair;	


#define MM_RUMOR_				0		
#define MM_PUBLIC_NOTICE_		1
#define MM_RANK_				2
#define MM_FORUM_				3
#define MM_EVENT_				4
#define MM_MYDIARY_				5
#define MM_BBS_					6
#define MM_ETC_					7


#define CMD_RUMOR_REQ					7060
#define CMD_RUMOR_INFO					7070
#define CMD_I_NEED_RUMOR				7080
typedef struct server_rumor_info
{
	short int money;
}t_server_rumor_info;



#define CMD_PUBLIC_NOTICE_TITLE_REQ		7090
#define CMD_RANK_TITLE_REQ				7100
#define CMD_FORUM_TITLE_REQ				7110
#define CMD_EVENT_TITLE_REQ				7120
#define CMD_MYDIARY_TITLE_REQ			7130
#define CMD_BBS_TITLE_REQ				7140
#define CMD_ETC_TITLE_REQ				7150

#define CMD_MENU_MESSAGE_TITLE			7160

#define CMD_PUBLIC_NOTICE_TEXT_REQ		7170
#define CMD_RANK_TEXT_REQ				7180
#define CMD_FORUM_TEXT_REQ				7190
#define CMD_EVENT_TEXT_REQ				7200
#define CMD_MYDIARY_TEXT_REQ			7210
#define CMD_BBS_TEXT_REQ				7220
#define CMD_ETC_TEXT_REQ				7230

#define CMD_MENU_MESSAGE_TEXT			7240

typedef struct server_menu_message_title
{
	unsigned char   type;
	unsigned char   no;
	unsigned int    date;
	unsigned char   name[  NM_LENGTH ];
	char			title[ TEXT_LENGTH];
}t_server_menu_message_title;
typedef struct client_menu_message_title
{
	unsigned char type;
	unsigned char no;
}t_client_menu_message_title;
typedef struct server_menu_message_text
{
	char			text[ TEXT_LENGTH];
}t_server_menu_message_text;




//---------------------------------------------------------------------------------------



#define CMD_NOTIFY_JOIN_OK				400


#define CMD_LEVELUP_POINT				410
#define CMD_LEVELUP_POINT_OK			420
#define CMD_LEVELUP_POINT_NO			430

//-----------------  Animation---------------------
//-----------------  Animation---------------------

#define CMD_TURN_DIR					500



// -----------------   House -------------------------
// -----------------   House -------------------------
// -----------------   House -------------------------

#define CMD_ROOF_OPEN					8000
#define CMD_ROOF_CLOSE					8001
typedef struct roof_open
{
	short int roofno;
}t_roof_open;
typedef struct roof_close
{
	short int roofno;
}t_roof_close;







/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
typedef struct  server_interface_peace
{
	short int	client_id ;
}t_server_interface_peace;

typedef struct  server_interface_battle
{
	short int	client_id ;
}t_server_interface_battle;


//--------------------------------------------------------
typedef struct server_weather
{
	unsigned int	weather;
	unsigned int	another;
	unsigned int	rainstart;
	unsigned int	rainend;
	short			amount;
	short			temperature;
} t_server_weather;



typedef struct server_npc_add		// Monster
{	
	char            name[ NM_LENGTH];
	
	int				fame_pk;	// 010915 LTS		//Fame_PK -> NWCharacter로 교체 DB에는 실제로 NWCharacter의 값이 들어갑니다.		
	NW_Character	NWCharacter;	// 010915 LTS

	char			spell;
	short int		npc_id;
	char			status;
	BYTE			sprno;
	short int		x;
	short int		y;

//	short int		homex;
//	short int		homey;

} t_server_npc_add;

typedef struct server_npc_remove
{	
	short int		server_id;
} t_server_npc_remove;



//........... Magic............................................
//............Magic............................................
//........... Magic............................................
typedef struct client_starting_magic 
{
	short int		magic_no;
} t_client_starting_magic;

typedef struct server_starting_magic 
{
	short int		server_id;
	short int		magic_no;
} t_server_starting_magic;

typedef struct client_doing_magic			
{
	short int		target_id;
	short int		x;
	short int		y;
	short int		magic_no;
	bool			firePattern;
} t_client_doing_magic;

typedef struct server_doing_magic 
{
	short int		server_id;
	short int		target_id;
	short int		x;
	short int		y;
	short int		magic_no;
	bool			firePattern;
} t_server_doing_magic;



typedef struct t_server_change_equip
{
	unsigned int	server_id;
	unsigned char	equip[4];
	short int		mantle;	//011018 KHS 망또
}server_change_equip;

typedef struct t_client_change_equip
{
	unsigned char	equip[4];
}client_change_equip;


// Attack........................................
// Attack........................................
// Attack........................................
typedef struct client_attack										
{														
	short int		target_id;								
} t_client_attack;											
														
typedef struct server_attack							
{														
	short int		server_id;						
	short int		target_id;					
} t_server_attack;	




		
												
											
// Item......................................
// Item......................................
// Item......................................
typedef struct server_item_add 		
{
	short int		item_id;
	ItemAttr		item;
	short int		offx, offy;
	short int		x, y;
} t_server_item_add;
typedef struct server_item_remove
{
	short int		item_id;
} t_server_item_remove;
typedef struct server_you_got_item
{
	short int		item_id;
} t_server_you_got_item;
typedef struct client_item_drop
{
	ItemAttr		item;
	short int		x,y;
} t_client_item_drop;
typedef struct client_item_take
{
	short int		item_id;
} t_client_item_take;
typedef struct client_item_status
{
	short int		item_id;
	unsigned int 	attr[6];
} t_client_item_status;
typedef struct server_item_status
{
	short int		item_id;
	unsigned int 	attr[6];
} t_server_item_status;
typedef struct chr_item_info0
{
	char        ar0;
	char        ar1;
	ItemAttr	inv[8];
} t_chr_item_info0;
typedef struct chr_item_info1
{
	ItemAttr	equip[8];
} t_chr_item_info1;
typedef struct chr_item_info2
{
	ItemAttr	quick[6];
} t_chr_item_info2;
typedef struct chr_name_info
{
	char	name[ NM_LENGTH];
	char	login_id[20];
} t_chr_name_info;

//---





// Bank........................................
// Bank........................................
// Bank........................................
typedef struct client_bank		
{
	int				total_money;
	int				money;
	int				char_money;
	DWORD			time;
} t_client_bank;



// Event ................................................ ###0923
// Event ................................................
// Event ................................................

typedef struct client_event
{
	short int type;
	short int event_no;
} t_client_event;

typedef struct item_attr_change
{
	short int		item_id;
	char			array;
	unsigned int	attr;
}t_item_attr_change;





/// Change Map .........................................
/// Change Map .........................................
/// Change Map .........................................
typedef struct server_change_map
{
	char			mapname[ NM_LENGTH ];
	char			ip[3][IP_LENGTH];
	int				port;
	short int		x;
	short int		y;
} t_server_change_map;


// Log In  ... Select Character.........................
// Log In  ... Select Character.........................
// Log In  ... Select Character.........................
//--------------------------------------------------------

//1207 zhh
#define MaxCorp		5		//현제 종량제 하고 있는 업체의 수

#define Nownuri		0		//WhatLineUse에 들어가는번호
#define Thrunet		1
#define Channel_i	2
#define Unitel		3
#define Netsgo		4

const int MAX_MY_STRING = 20;
typedef struct CLIENTACCESSLOGIN
{
	HSEL_INITIAL	init;
	char			id[ID_LENGTH];  
	char			pw[PW_LENGTH];
	short int		version;
	char			ip[IP_LENGTH];		//Added by zoung
	WORD			wPort;		// Added by chan78 at 2000/12/17
	BYTE			Foo;
	short int		Corp_Code;	//업체 코드
	char			mystring[MAX_MY_STRING];
	char			User_ID[ID_LENGTH];	//종량제 업체용 ID
	char			GateWayIP[IP_LENGTH];
	short int		mycode;	
	int				GateWayPORT;
}t_ClientAccessLogin, *LPCLIENTACCESSLOGIN;

//--------------------------------------------------------
typedef struct server_accept_login					
{
	short int		server_id;						
	char			name[ MAX_CHARACTEROFID][NM_LENGTH];
	unsigned char	level[ MAX_CHARACTEROFID];		
	unsigned char	job[ MAX_CHARACTEROFID];		
	unsigned char	cla[ MAX_CHARACTEROFID];		
	unsigned char	gender[ MAX_CHARACTEROFID];		

	unsigned char   bodyr[ MAX_CHARACTEROFID];		
	unsigned char   bodyg[ MAX_CHARACTEROFID];		
	unsigned char   bodyb[ MAX_CHARACTEROFID];		
													
	unsigned char   clothr[ MAX_CHARACTEROFID];		
	unsigned char   clothg[ MAX_CHARACTEROFID];		
	unsigned char   clothb[ MAX_CHARACTEROFID];		
													
	short int		age[ MAX_CHARACTEROFID];		
	unsigned int	money[ MAX_CHARACTEROFID];		
	unsigned char	acc_equip1[ MAX_CHARACTEROFID];	
	unsigned char	acc_equip2[ MAX_CHARACTEROFID];	
	unsigned char	acc_equip3[ MAX_CHARACTEROFID];	
	unsigned char	acc_equip4[ MAX_CHARACTEROFID];	
													
	char			nation;							
	short int		remained_day;					

	char			id[ ID_LENGTH];		// 010129 KHS

} t_server_accept_login;

//--------------------------------------------------------
typedef struct client_connect_info
{
	char			name[NM_LENGTH];
	char			startposition;
	char			startmap;
} t_client_connect_info;

typedef struct server_connect_info	// 사용안함.
{
	char			startposition;
	int				port;
	char			ip[3][IP_LENGTH];
} t_server_connect_info;
	
//--------------------------------------------------------
typedef struct client_chat_data
{	
	short int		range;
	unsigned char	type;
	unsigned char	length;
	char			text[TEXT_LENGTH];
} t_client_chat_data;
	
//--------------------------------------------------------
typedef struct server_chat_data
{	
	short int		server_id;
	unsigned char   type;
	unsigned char	length;
	char			text[TEXT_LENGTH];
} t_server_chat_data;
	
//--------------------------------------------------------
typedef struct client_move
{	
	short int		server_id;
	short int		length;
	short int		sx;
	short int		sy;
	short int		gox;
	short int		goy;
	unsigned char	movetype;
	short int       movep;
	unsigned char	dir_tbl[MAX_DIR_TABLE];
} t_client_move;
	
//--------------------------------------------------------
typedef struct server_move
{	
	short int		server_id;
	short int		length;
	short int		sx;
	short int		sy;
	short int		gox;
	short int		goy;
	unsigned char	movetype;
	short int		targetid;
	unsigned int	desttime;
	unsigned char	dir_tbl[MAX_DIR_TABLE];
} t_server_move;
	
//--------------------------------------------------------
typedef struct client_create_char
{	
	char			name[NM_LENGTH];
	unsigned char	gender;
	unsigned char	face;
	short int		age;
	unsigned char	arigement; // CSD-030324
	unsigned char	body_r, body_g, body_b;
	unsigned char	cloth_r, cloth_g, cloth_b;
	unsigned char	tactics;
	unsigned char	Class;
	unsigned char	job;
	unsigned char	spell;
} t_client_create_char;


typedef struct client_delete_char//020820 lsw 
{	
	char	szSecretKeyCode[51];
	char	szName[NM_LENGTH];
}t_client_delete_char;

typedef struct server_assign_server_id
{	
	short int		x, y;
	short int		server_id;
}t_server_assign_server_id;
	
//// LoginServer와 GameServer간의 Access Join관계..
	
#define CMD_REQ_INSERT_USERID			34
#define CMD_REQ_DELETE_USERID			35
#define CMD_JOINABLE					36
#define CMD_NOT_JOINABLE				37
	
#define CMD_UPDATING					38
	
	
typedef struct gs_req_insert_userid
{	
	short int server_id;
	char id[ ID_LENGTH];
	char pw[ PW_LENGTH];
	char name[ NM_LENGTH];
	char mapname[ NM_LENGTH];
}t_gs_req_insert_userid;
	
	
typedef struct gs_req_delete_userid
{	
	short int server_id;
	char id[ ID_LENGTH];
	char mapname[ NM_LENGTH];
}t_gs_req_delete_userid;
	
	
	
	
	
	
typedef struct ls_joinable
{	
	short int server_id;
}t_ls_joinable;
	
typedef struct ls_not_joinable
{	
	short int server_id;
	
}t_ls_not_joinable;
	
	
typedef struct ls_updating		// LoginServer ->  GameServer.	요청한 User는 현재 Data를 Updating하고 있기 때문에 잠시 기다려야 합니다. 
{	
	short int server_id;
	
}t_ls_updating;
	
	
//--------------------------------------------------------
typedef struct server_user_db_data
{	
	short int		lev;
	DWORD			exp;
	char			name[NM_LENGTH];
	short int		Attr[ 10]; //MAX_CHARACTERDATA];
	short int		Avility[20];
	DWORD			money;
	int	nLife;
	int	nMaxHp;
	int	nMana;
	int	nMaxMp;
	int	nHungry;
	int	nMaxHungry;
	char			spell;
	/////////////////////// 1228 이규훈 수정 //////////////////////
	BYTE			condition;
	//////////////////////////////////////////////////////////////

	
	short int		sprno;
	short int		x;
	short int		y;
	
	unsigned char	acc_equip1;
	unsigned char	acc_equip2;
	unsigned char	acc_equip3;
	unsigned char	acc_equip4;
	
	char			mapname[NM_LENGTH];
	
	unsigned char	bodyr, bodyg, bodyb;
	unsigned char	clothr,clothg,clothb;
	int		sight;
	short int		Age;
	
	short int		openhouse;
	short int		reserved_point;
	
	char			viewtype;
	
	short int 		social_status;
	short int		fame;
	short int		fame_pk;		// 010915 LTS		//Fame_PK -> NWCharacter로 교체 DB에는 실제로 NWCharacter의 값이 들어갑니다.		
	NW_Character	NWCharacter;	// 010915 LTS
	short int		nk3;
	short int		nk4;
	short int		nk6;

	DWORD			nation;			//1004 YGI
  //< CSD-011006
  char aStepInfo[20];
  //> CSD-011006
} t_server_user_db_data;
	
//--------------------------------------------------------
typedef struct server_envir_info
{	
	DWORD			currtime_count;
	DWORD			weather_count;
	DWORD			rainstart;
	DWORD			rainend;
	short			amount;
	short			temperature;
	char			mapname[NM_LENGTH];
} t_server_envir_info;
	
//------------------------------------------
typedef struct server_user_add
{	
	char			name[NM_LENGTH];
	int				fame_pk;		// 010915 LTS	//Fame_PK -> NWCharacter로 교체 DB에는 실제로 NWCharacter의 값이 들어갑니다.		
	NW_Character	NWCharacter;	// 010915 LTS
	short int		server_id;
	unsigned char	spr_no;
	char			spell;
	char			face;
	
	unsigned char	body_r, body_g, body_b;
	unsigned char	cloth_r, cloth_g, cloth_b;
	unsigned char	equip[4];
	unsigned char	peacests;
	short int		hp;
	short int		x, y;
	char			viewtype;

} t_server_user_add;
	
//--------------------------------------------------------
typedef struct server_user_remove
{	
	short int		server_id;
} t_server_user_remove;
	
//--------------------------------------------------------


typedef struct req_pc_add
{
	short int server_id;
}t_req_pc_add;

typedef struct req_npc_add
{
	short int server_id;
}t_req_npc_add;

typedef struct req_item_add
{
	short int server_id;
}t_req_item_add;

typedef struct element {
	unsigned char var_kind ;
	short int value ;
} t_element ;

typedef struct mass_data {
	unsigned char num ;
	t_element elements[100] ;
} t_mass_data ;


////////////////////////////////////////////////////////////////  Binary Update..................................
////////////////////////////////////////////////////////////////  Binary Update..................................
////////////////////////////////////////////////////////////////  Binary Update..................................
////////////////////////////////////////////////////////////////  Binary Update..................................
////////////////////////////////////////////////////////////////  Binary Update..................................
////////////////////////////////////////////////////////////////  Binary Update..................................


//1029 zhh
#define CMD_SPECIAL_ITEM				702
typedef struct server_special_item
{
	int No;
	int Now_Store;
	int S_Day;
}t_server_special_item;



#define CMD_UPDATE_CHAR_DB			8500
#define CMD_UPDATE_BINARY_DATA0		8501
#define CMD_UPDATE_BINARY_DATA1		8502
#define CMD_UPDATE_SCRIPT_DATA		8503
#define CMD_UPDATE_INV_DATA			8504	
#define CMD_UPDATE_ITEM_DATA		8505
#define CMD_UPDATE_BANKITEM_DATA	8506	

struct t_update_char_db
{	//< CSD-030807
	char name[NM_LENGTH];
	char id[NM_LENGTH];
	short Level;
	short nGuildCode;
	short social_status; // 신분
	short fame;	// 명성치
	NW_Character NWCharacter; // 국가전 관련 필드 // 010915 LTS
	short Str;	
	short Con;	
	short Dex;
	short Wis;	
	short Int;
	short MoveP;	  
	short Char;
	short Endu;
	short Moral;	  
	short Luck ;	 
	short wsps;
	BYTE Tactics; // 선택한 전투기술 (보여주기 위함)
	DWORD nation; // 1004 YGI
	DWORD Money;
	int	Hp;
	int	HpMax ;
	int	Mana;
	int	ManaMax;
	int Hungry;	
	int	HungryMax;
	BYTE Condition;	// 캐릭터 상태
	char MapName[NM_LENGTH];
	int Sight;		// YGI 020418
	short Age;
	BYTE bAlive; // 캐릭터의 생사여부
	DWORD killmon;	// 1계열몬스터 킬링수
	DWORD killanimal; // 동물 킬링수
	DWORD killpc; // 사람, NPC 킬링수
	short nPoison; // 저주계열 마법에 대한 저항력
	short nCurse; // 저주계열 마법에 대한 저항력	
	short nFire; // 불계열 공격 마법에 대한 저항력
	short nIce;	// 얼음계열 공격 마법에 대한 저항력
	short nElect; // 전격계열 공격 마법에 대한 저향력
	short nHoly; // 신력계열 공격 마법에 대한 저항력
	short X;
	short Y;
	BYTE accessory[4];
	short mantle; // 011018 KHS 망또
	short openhouse;
	short reserved_point ;
	DWORD BankMoney;
	DWORD win_defeat;
	DWORD LadderScore;
	DWORD LastLoan;
	DWORD Exp;
	char disease[6];					
	char viewtype;
	short nk3;
	short nk4;
	short nk6;
	char aStepInfo[20];
	int nCombatAmount;
	int	check_crc; //acer5
};	//> CSD-030807

typedef struct  server_update_binary_data0
{
	char            name[ NM_LENGTH];
	char            id[ NM_LENGTH];

	UCHAR			Ws[SIZE_OF_WS];
	UCHAR			Ps[SIZE_OF_PS];
	UCHAR			Skill[SIZE_OF_SKILL];
	UCHAR			skillexp[SIZE_OF_SKILL_EXP];
	UCHAR			tac_skillEXP[SIZE_OF_TAC_SKILL_EXP];

	int				check_crc;		// acer5
}t_server_update_binary_data0;

typedef struct  server_update_script_data
{
	char            name[ NM_LENGTH];
	char            id[ NM_LENGTH];
	UCHAR			script_var[SIZE_OF_SCRIPT_VAR];
	int				check_crc;		// acer5
} t_server_update_script_data;

typedef struct  server_update_binary_data1
{
	char            name[ NM_LENGTH];
	char            id[ NM_LENGTH];

	UCHAR			equip[SIZE_OF_EQUIP];
	UCHAR			quick[SIZE_OF_QUICK];
	UCHAR			party[SIZE_OF_PARTY];
	UCHAR			relation[SIZE_OF_RELATION];
	UCHAR			employment[SIZE_OF_EMPLOYMENT];		
	int				check_crc;		// acer5
} t_server_update_binary_data1;


typedef struct  server_update_inv_data
{
	char            name[ NM_LENGTH];
	char            id[ NM_LENGTH];
	UCHAR			inv[SIZE_OF_INV];
	int				check_crc;		// acer5
} t_server_update_inv_data;

typedef struct  server_update_item_data
{
	char            name[ NM_LENGTH];
	char            id[ NM_LENGTH];
	UCHAR			Item[SIZE_OF_ITEMINDEX];
	int				check_crc;		// acer5
} t_server_update_item_data;

typedef struct  server_update_bankitem_data
{
	char            name[ NM_LENGTH];
	char            id[ NM_LENGTH];
	char			mapname[ NM_LENGTH];
	UCHAR			bankitem[SIZE_OF_BANKITEM];
	int				check_crc;		// acer5
} t_server_update_bankitem_data;

////////////////////////////////////////////////////////////////  Binary Update..................................
////////////////////////////////////////////////////////////////  Binary Update..................................
////////////////////////////////////////////////////////////////  Binary Update..................................
////////////////////////////////////////////////////////////////  Binary Update..................................



// Character Basic Data*********************************************
typedef struct chr_status_info
{
	short int		Str;				//  힘
	bool			fStr ;
	short int		Con;				//  건강
	bool			fCon ;
	short int		Dex;				//	민첩성
	bool			fDex ;
	short int		Wis;				//	지혜
	bool			fWis ;
	short int		Int;				//	지능
	bool			fInt ;
	short int		MoveP;				//	이동력
	bool			fMoveP ;
	short int		Char;				//	매력
	bool			fChar ;
	short int		Endu;				//  저향력
	bool			fEndu ;
	short int		Health;				//	체력
	bool			fHealth ;
	short int		Moral;				//	사기
	bool			fMoral ;
	short int		Luck;				//	행운
	bool			fLuck ;

	short int		Resis_Poision;		//	독/죽음 저항력
	bool			fPoison ;
	short int		Resis_Stone;		//	석화 마비 저항력
	bool			fStone ;
	short int		Resis_Magic;		//	마법저항력
	bool			fMagic ;
	short int		Resis_Fire;			//	불 저항력
	bool			fFire ;
	short int		Resis_Ice;			//	얼음저항력
	bool			fIce ;
	short int		Resis_Elect;		//	전기저향력
	bool			fElect ;

	short int		Ap ;
	bool			fAp ;
		
	short int		Hp ;
	bool			fHp ;

	short int		HpMax ;
	bool			fHpMax ;
	
	short int		Mp ;
	bool			fMp ;
	short int		MpMax ;
	bool			fMpMax ;

	short int		Ac ;
	bool			fAc ;
	short int		Hit ;
	bool			fHit ;
	short int		Dam_Min, Dam_Max ;
	bool			fDamage ;
	short int		Tactics ;
	bool			fTactic ;
	
	short int		WsPs ;
	bool			fWsPs ;

	int		Sight ;		// YGI 020418
	bool			fSight ;

} t_chr_status_info ;


typedef struct item_ex_info				// 메뉴에서 사용 (아이템)( 서버용 )
{
//	ItemAttr item_attr;
	int		itemno ;
	POS		pos_s;
	POS		pos_t;
} t_item_ex_info;
typedef struct item_exchange			// 클라이언트용...
{
	int		item_no;
	POS		pos_s;
	POS		pos_t;
} t_item_exchange;

// ===========================================================================================
// 설명: CLIENT가 자신의 공격을 서버에 알려주기 위한 구조체
// 전송: CLIENT --> SERVER
// 헤더: CMD_ATTACK
// -------------------------------------------------------------------------------------------
/////////////// 0604 lkh ////////////////
typedef struct attack_info
{
	short int	defender_id ;
	short int	backdraw_X;
	short int	backdraw_Y;
} t_attack_info ;
// ===========================================================================================



// ===========================================================================================
// 설명: CLIENT의 공격행동과 그 결과를 다른 CLIENT로 멀티캐스팅 해줄때 사용될 구조체
// 전송: SERVER ==> CLIENT(S)
// 헤더: CMD_ATTACK_RESULT
// -------------------------------------------------------------------------------------------
typedef struct attack_result
{
	short int attacker_id ;
	short int defender_id ;
	short int damage ;
	short int hp;
	short int hpmax;
	char	  tac_skill;
	DWORD	  tac_skillEXP;

//	short int lev;
//	short int dex;
//	short int str;
//	short int addexp;
	
	short int tox, toy;

	char	  result ;		// HIT AND DEAD, HIT AND NOTDEAD, HIT FAILED
	//bool LevelUp_flag ;
	//unsigned int Exp ;
} t_attack_result ;
// ===========================================================================================


// Menu..
// ===========================================================================================
// 설명: 클라이언트가 어떤 메뉴를 띄울지 이벤트에 따라 메뉴ID를 알려주기위한 구조체
// 전송: SERVER ==> CLIENT
// 헤더: CMD_CALL_SMALLMENU
// -------------------------------------------------------------------------------------------
typedef struct server_call_smallmenu
{
	short int	menu;
	short int   storelistindex;
} t_server_call_smallmenu;


typedef struct server_store_itemlist
{
	unsigned char	no;
	short int		smallmenu;
	short int		storelistindex;
	short int		item[MAX_STORE_ITEM_LIST];		//### 1212
	short int		price[MAX_STORE_ITEM_LIST];		//### 1227
}t_server_store_itemlist;

typedef struct client_item_buy
{
	short int store_id;
	short int item_no;								//### 1217
	short int inv_position;

}t_client_item_buy;
typedef struct client_item_sell
{
	short int store_id;
	short int item_position;
}t_client_item_sell;

#define MM_RUMOR_				0
#define MM_ALL_BROADCAST_TEXT	1
#define MM_RANK					2
typedef struct server_menu_message
{
	unsigned char	type;
	char			text[TEXT_LENGTH];
}t_server_menu_message;
	

// ===========================================================================================

//< CSD-010907
/*
typedef struct client_levelup_point
{
	unsigned short int point[11];
}t_client_levelup_point;

typedef struct server_levelup_point
{
	short int		server_id;
	unsigned char   point;
	short int		hp;
}t_server_levelup_point;
*/
struct t_client_levelup_point
{
  WORD aPoint[11];
};
	struct t_server_levelup_point
{
  WORD idServer;
  BYTE nPoint;
  __int32 nLife;
};
//> CSD-010907
//------------  Animation --------------------------------
//------------  Animation --------------------------------
//------------  Animation --------------------------------
//------------  Animation --------------------------------
//------------  Animation --------------------------------

typedef struct server_turn_dir
{
	short int  server_id;
	DIRECTION  dir;
}t_server_turn_dir;

// ----------------- Skill -------------------------------
// ----------------- Skill -------------------------------
// ----------------- Skill -------------------------------
// ----------------- Skill -------------------------------
// ----------------- Skill -------------------------------

#define CMD_SKILL_INFO					6150//010707 lsw 수정

typedef struct server_skill_info
{
	short int server_id;
	short int skillno;
	short int x, y;
	short int targettype;
	short int target_id;
}t_server_skill_info;

typedef struct client_skill_info
{
	short int skillno;
	short int x, y;
	short int targettype;
	short int target_id;
	POS		  s;
	char	TargetName[31];
	int		iKey;//030102 lsw
}t_client_skill_info;



#define CMD_SKILL_RESULT				610
typedef struct server_skill_result
{
	short int skillno;
	short int x, y;
	short int result;
}t_server_skill_result;
typedef struct client_skill_result
{
	short int skillno;
	short int x, y;
	short int targettype;
	short int target_id;
}t_client_skill_result;


#define CMD_SKILL_ITEM_MATTER			612
typedef struct client_skill_item_matter
{
	POS pos[20];
}t_client_skill_item_matter;


#define CMD_SKILL_ITEMMAKE_RESULT		614
typedef struct server_skill_itemmake_result
{
	short int skillno;
	ItemAttr item;
}t_server_skill_itemmake_result;



#define CMD_SKILL_RESULT_FAIL			618
typedef struct server_skill_result_fail
{
	short int skillno;
	char      why;
}t_server_skill_result_fail;



#define	CMD_SKILL_RESULT_TOOTHER		619
typedef struct server_skill_result_toother
{	
	short int id;
	short     skillno;
	char	  result;
	
}t_server_skill_result_toother;
	


#define CMD_SKILL_CURSOR_VIEW			611

typedef struct client_skill_cursor_view
{
	short int skillno;
	short int x, y;
}t_client_skill_cursor_view;


#define CMD_SKILL_GAUGE					613

typedef struct client_skill_gauge
{
	short int skillno;
	short int x, y;

}t_client_skill_gauge;
typedef struct server_skill_gauge
{
	short int skillno;
	short int x, y;
	char      min;

}t_server_skill_gauge;


#define CMD_VIEWTYPE_CHANGE				620
typedef struct viewtype_change
{
	short int   server_id; 
	char		viewtype;
}t_viewtype_change;


#define CMD_VIEW_CHAR_INFO				622
typedef struct view_char_info
{
	short int server_id;
	short int type;
	DWORD data;
	char  killer[ 31];
}t_view_char_info;



// Chatting.................................................................
#define CMD_CHAT_SET				7500
typedef struct chat_set
{
	char chattype;
	char chatname[ NM_LENGTH];
}t_chat_set;
#define CMD_CHAT_SET_RESULT			7510		
typedef struct chat_set_result	// 설정했는데 상대가 없다면 없다고 얘기 해준다. 
{
	char result;
}t_chat_set_result;
// .........................................................................

#define CMD_TOTAL_MAP_CONNECTIONS	7520
typedef struct  total_map_connections
{
	short int no;
}t_total_map_connections;

#define CMD_TOTAL_CONNECTIONS		7530
typedef struct  total_connections
{
	short int no;
}t_total_connections;


#define CMD_ISTHERE_CHARNAME		7540
typedef struct client_isthere_charname
{		
	char name[ NM_LENGTH];
}t_client_isthere_charname;
#define CMD_THEREIS_NO_CHARNAME		7541
#define CMD_THEREIS_CHARNAME		7542
		
//------------ NEW_APPEND -------------------------------
#define CMD_GLOBAL_CHAT_DATA		9001
#define CMD_IM_GAME_SERVER         	9011
typedef struct im_game_server
{	
	int my_code;
	int port;
}t_im_game_server;
		
#define CMD_ACCESS_CHAR_DB			9021
#define CMD_ACCEPT_CHAR_DB			9031
#define CMD_ACCEPT_CHAR_GAME_DB		9032
#define CMD_ACCEPT_BINARY_DATA		9033
#define CMD_ACCEPT_SCRIPT_DATA		9034
#define CMD_ACCEPT_INV_DATA			9035
#define CMD_ACCEPT_ITEM_DATA		9036
#define CMD_ACCEPT_BANKITEM_DATA	9037
		
#define CMD_ACCEPT_BINARY_DATA_ERROR	9038
								
							
//-------------------------------------------------------
//------------ NEW_APPEND -------------------------------
typedef struct  server_access_char_db
{							
	short int		server_id;
							
	char			id[ID_LENGTH];
	char			name[NM_LENGTH];
} t_server_access_char_db;	
							
typedef struct  server_accept_char_db // 2308
{
	char			name[20];		// 030923 HK YGI	// 이름으로 확인한다.
	short int		server_id;
							
	short int		Level;	
	DWORD			Exp;	
							
	short int		Gender;	
	short int		Face;							
	short int		nGuildCode; // CSD-030324
	short int		Class;	
	short int		Job;		// 0212YGI
	short int		Spell;	
							
	short int		Str;	
	short int		Con;	
	short int		Dex;	
	short int		Wis;		
	short int		Int;	
	short int		MoveP;	
	short int		Char;	
	short int		Endu;	
	short int		Moral;	
							
	DWORD			Money;	

	__int32	nLife;
	__int32	nMaxHp;
	__int32	nMana;
	__int32	nMaxMp;
	__int32	nHungry;
	__int32	nMaxHungry;
	
	BYTE			Condition;
						
	short int		SprNo;
	short int		X;
	short int		Y;
	char			MapName[NM_LENGTH];
	unsigned char	Peacests;
	int		Sight;		// YGI 020418
	
	short int		BodyR;
	short int		BodyG;
	short int		BodyB;

	short int		ClothR;
	short int		ClothG;
	short int		ClothB;

	short int		Age;
	short int		Luck;
	short int		wsps;
	DWORD			nation;				//1004 YGI

	BYTE			accessory[4];
	short int		mantle;		// 011018 KHS 망또 

	BYTE			bAlive;
	short int		openhouse;
	char			disease[6];		
	DWORD			total_id;

	__int16 nPoison; // 저주계열 마법에 대한 저항력
	__int16 nCurse; // 저주계열 마법에 대한 저항력	
	__int16 nFire;	 // 불계열 공격 마법에 대한 저항력
	__int16 nIce;		 // 얼음계열 공격 마법에 대한 저항력
	__int16 nHoly;	 // 신력계열 공격 마법에 대한 저항력
	__int16 nElect;	 // 전격계열 공격 마법에 대한 저향력
	char			viewtype;

	short int		social_status;
	short int		fame;
	short int		fame_pk;		// 010915 LTS	//Fame_PK -> NWCharacter로 교체 DB에는 실제로 NWCharacter의 값이 들어갑니다.		
	NW_Character	NWCharacter;	// 010915 LTS
 
	char aStepInfo[20];
	int		nUserAge;				// 030929 kyo
  	Event_Join		EventJoin;		// 020115 LTS
} t_server_accept_char_db;

typedef struct  server_accept_char_game_db
{
	char			name[20];		// 030923 HK YGI
	short int		server_id;

	DWORD			BankMoney;

	// 010406 YGI
	DWORD			win_defeat;
	DWORD			LadderScore;
	DWORD			LastLoan;
	//DWORD			LastLoan_time;

	short int		nk3, nk4, nk6;
	DWORD			killmon;
	DWORD			killanimal;
	DWORD			killpc;
	short	int 	reserved_point;
	unsigned char	Tactics;
} t_server_accept_char_game_db;

typedef struct  server_accept_binary_data
{
	char			name[20];	// 030923 HK YGI
	short int		server_id;

	UCHAR			Ws[SIZE_OF_WS];
	UCHAR			Ps[SIZE_OF_PS];
	UCHAR			Skill[SIZE_OF_SKILL];
	UCHAR			skillexp[SIZE_OF_SKILL_EXP];
	UCHAR			tac_skillEXP[SIZE_OF_TAC_SKILL_EXP];
	UCHAR			equip[SIZE_OF_EQUIP];
	UCHAR			quick[SIZE_OF_QUICK];
	UCHAR			party[SIZE_OF_PARTY];
	UCHAR			relation[SIZE_OF_RELATION];
	UCHAR			employment[SIZE_OF_EMPLOYMENT];		
} t_server_accept_binary_data;

typedef struct  server_accept_script_data
{
	char			name[20];	// 030923 HK YGI
	short int		server_id;
	UCHAR			script_var[SIZE_OF_SCRIPT_VAR];
} t_server_accept_script_data;

typedef struct  server_accept_inv_data
{
	char			name[20];	// 030923 HK YGI
	short int		server_id;
	UCHAR			inv[SIZE_OF_INV];
	char			refresh_inventory;		// 맵서버가 다시 클라이언트에 값을 보내줘야 할때	//021030 YGI
} t_server_accept_inv_data;

typedef struct  server_accept_item_data
{
	char			name[20];	// 030923 HK YGI
	short int		server_id;
	UCHAR			Item[SIZE_OF_ITEMINDEX];
} t_server_accept_item_data;

typedef struct  server_accept_bankitem_data
{
	char			name[20];	// 030923 HK YGI
	short int		server_id;
	UCHAR			bankitem[SIZE_OF_BANKITEM];
} t_server_accept_bankitem_data;


typedef struct server_accept_data_error		// login server에서 Error가 발생했다. 
{
	char name[ NM_LENGTH];
}t_server_accept_data_error;


//-------------------------------------------------------



#define CMD_TAME_COMMAND			8100
//-------------------------------------------------------
#define LC_TAME_STOP				18
#define LC_TAME_ATTACK				19	
#define LC_TAME_FOLLOWME			20
#define LC_TAME_NAME				21
typedef struct tame_command
{
	BYTE	cmd;
	char	mybaby[ NM_LENGTH];
	char    toname[ NM_LENGTH]; 
}t_tame_command;

//-------------------------------------------------------
#define CMD_TAME_NAME_CHANGE		8101
typedef struct tame_name_change 
{
	short int id;
	char name[ NM_LENGTH];
}t_tame_name_change;

#define CMD_TAME_HOST_NAME			8102
typedef struct tame_host_name
{
	short int id;
	char hostname[ NM_LENGTH];
}t_tame_host_name;

#define CMD_TAME_COMMAND_RESULT		8103
typedef struct tame_command_result
{
	char	result;
}t_tame_command_result;

#define CMD_TAME_END				8104
typedef struct tame_end
{
	short int id;
}t_tame_end;

#define CMD_YOU_DIE					8200
typedef struct
{
	short int	id;
	short int	t;
}t_you_die;

#define CMD_DEBUG_REQ_CHAR_INFO		8300

typedef struct debug_server_req_char_info
{
	short int id;
	int		lv;
	int		exp;
	int		 ac;
	int		Str;				//  힘
	int		Con;				//  건강
	int		Dex;				//	민첩성
	int		Wis;				//	지혜
	int		Int;				//	지능
	int		MoveP;				//	이동력
	int		Char;				//	매력
	int		Endu;				//  저향력
	int		Moral;				//	사기
	int		Luck;				//	행운
	int		wsps;				//  마법력->마법 메모라이즈

	int     Hp, HpMax;
	int     Mp, MpMax;
	int		Hungry,HungryMax;		

	short int event_no;			// 0131 YGI

}t_debug_server_req_char_info;

typedef struct debug_client_req_char_info
{
	short int id;
}t_debug_client_req_char_info;


#define CMD_PLEASE_GIVE_LIFE		8400
#define CMD_PLEASE_GIVE_LIFE1		8401
//< CSD-010907
/*
typedef struct please_give_life
{
	short int		id;
	short int       hp;
	short int       mana;
	short int       hungryp;
	short int       who;
}t_please_give_life;
*/
struct t_please_give_life
{
  short int id;
  short int who;
  __int32 nLife;
  __int32 nMana;
  __int32 hHungry;
};
//> CSD-010907
#define CMD_GOTO_EDELBROY_TOGETLIFE		8402

#define CMD_SMILE_FACE			8410
typedef struct client_smile_face	
{
	char smileno;
}t_client_smile_face;
typedef struct server_smile_face	
{
	short int id;
	char  smileno;
}t_server_smile_face;

// 공지사항 공고....
#define		CMD_BBS					8411
typedef struct server_bbs
{
	char bbs[ MAX_PATH];
}t_server_bbs;

#define CMD_ACCESS_JOIN_YOU_ALREADY_IN_MAP			8412	// id와 Password를 들고 접근하지만. 당신은 이미 맵에 있다. 또는 현재 Update중이다. 


#define CMD_HOW_MANY_IN_MAP							8413
typedef struct how_many_in_map
{
	char		map[ NM_LENGTH ];
	short int	how;
}t_how_many_in_map;

// 게임 운영자용
#define CMD_BLOCK_ATTACK_START						8414
#define CMD_BLOCK_ATTACK_END						8415
#define CMD_BLOCK_MOVE_START 						8416
#define CMD_BLOCK_MOVE_END							8417
#define CMD_BLOCK_MAGIC_START						8418
#define CMD_BLOCK_MAGIC_END							8419
#define CMD_BLOCK_GIVE_LIFE_START					8420
#define CMD_BLOCK_GIVE_LIFE_END						8421


#define CMD_ABSOLUTE_LOGOUT							8422
typedef struct absolute_logout
{
	short id;
}t_absolute_logout;

#define CMD_MAKE_GHOST								8423
typedef struct make_ghost
{
	short id;
}t_make_ghost;


#define CMD_GIVE_LIFE								8425
typedef struct give_life 
{
	short id;
}t_give_life;




#define CMD_ITEM_DURATION_CHANGE					8426
typedef struct item_duration_change
{
	BYTE pos;
	WORD dur;
}t_item_duration_change;



////////////////////////////////////////////////////////////////////////////////////////
//
// NPC를 제어하기 위한 프로토콜
//

#define CMD_NPC_CHAT_DATA							8427
typedef struct npc_chat_data
{
	short int id;
	char      data[ TEXT_LENGTH];
}t_npc_chat_data;


#define CMD_NPCCTRL_MURI_8							8428
typedef struct npcctrl_muri_8	
{								
	short int id;				
	short int oldpatterntype;		
	short int patterntype;		
	short int bossid;
	DWORD	  Exp;
}t_npcctrl_muri_8;				
								
								
#define CMD_NPCCTRL_MURI_18							8429
typedef struct npcctrl_muri_18	
{								
	short int id;				
	short int oldpatterntype;	
	short int patterntype;		
	short int bossid;
	DWORD	  Exp;
}t_npcctrl_muri_18;				
								
									
#define CMD_NPCCTRL_MURI_28							8430
typedef struct npcctrl_muri_28 
{								
	short int id;				
	short int oldpatterntype;	
	short int patterntype;		
	short int bossid;
	DWORD	  Exp;

}t_npcctrl_muri_28;				

#define CMD_NPCCTRL_WANDER_MAUL						8431
typedef struct npcctrl_wander_maul 
{
	short int id;
	short int oldpatterntype;
	short int patterntype;
}t_npcctrl_wander_maul;

#define CMD_NPCCTRL_NO_MOVE							8432
typedef struct npcctrl_no_move 
{
	short int id;
	short int oldpatterntype;
	short int patterntype;
}t_npcctrl_no_move;

#define CMD_NPCCTRL_WANDER_GUARD					8433
typedef struct npcctrl_wander_guard 
{	
	short int id;
	short int oldpatterntype;
	short int patterntype;
}t_npcctrl_wander_guard;

#define CMD_NPCCTRL_WANDER_38						8434
typedef struct npcctrl_wander_38 
{
	short int id;
	short int oldpatterntype;
	short int patterntype;
	short int bossid;
}t_npcctrl_wander_38;


#define CMD_NPCCTRL_TAME	   						8435
typedef struct npcctrl_tame
{
	short int id;
	short int oldpatterntype;
	short int patterntype;
	short int bossid;
	short int HostId;
	char	  TargetName[31];
	short int tame;
	BYTE	  tame_cmd;
					
}t_npcctrl_tame;	
	
#define CMD_NPC_MODIFY_POS							8436
typedef struct npc_modify_pos
{				 	
	short int id;	
	short int mx, my;
}t_npc_modify_pos;	
					
							
#define CMD_SEND_NPC_PARAMETER						8437
typedef struct send_npc_parameter
{					
	short id;
	short type;
	short data;
}t_send_npc_parameter;
						
#define CMD_SEND_NPC_STRING_PARAMETER				8438
typedef struct send_npc_string_parameter
{							
	short id;			
	short type;				
	char data[ 31];		
}t_send_npc_string_parameter;
						
						
#define CMD_START_GOODBAD							8439
typedef struct start_goodbad
{						
	short int id;		
	int		  fame_pk;
						
}t_start_goodbad;			
						
#define CMD_ENDOF_GOODBAD							8440
typedef struct endof_goodbad
{							
	short int id;			
}t_endof_goodbad;				
							
#define	CMD_LOGIN_BBS								8450
typedef struct login_bbs
{
	char	bbs[ MAX_PATH];
}t_login_bbs;



#define	CMD_CHAR_IN_GAME							8460	
typedef struct char_in_game							
{
	char name[ NM_LENGTH];
}t_char_in_game;



// Login Server -> Game Server
// id를 가진 놈을 끊어라...
#define CMD_CLOSE_LOGIN_ID							8462
typedef struct login_close_login_id 
{
	char id[ NM_LENGTH];
}t_login_close_login_id;



#define CMD_UPDATE_VERY_IMPORTANT_STATUS			8465
typedef struct update_very_important_status
{
	char            name[ NM_LENGTH];
	
	short int		Level;

	short int		Str  ;	
	short int		Con  ;	
	short int		Dex  ;	
	short int		Wis  ;	
	short int		Int  ;	
	short int		MoveP;	  
	short int		Char ;	 
	short int		Endu ;	 
	short int		Moral;	  
	short int		Luck ;	 
	short int		wsps ;	 

	int				HpMax ;
	int				ManaMax;
	int				HungryMax;

	short int		reserved_point;

	DWORD			Exp;

}t_update_very_important_status;



#define CMD_UPDATE_VERY_IMPORTANT_TACTICS		8466
typedef struct update_very_important_tactics
{
	char name[ NM_LENGTH];
	char tac_skillEXP[ SIZE_OF_TAC_SKILL_EXP];
}t_update_very_important_tactics;




#define CMD_TRIP_AROUND		8468
typedef struct trip_around
{
	int x, y;
}t_trip_around;





#define CMD_TACTICS_PARRYING_EXP		8470
typedef struct tactics_parrying_exp
{
	DWORD exp;
}t_tactics_parrying_exp;
	
	
	
	
#define CMD_DUAL_PROPOSAL			8472
typedef struct dual_proposal	
{	
	char name[ NM_LENGTH];
}t_dual_fight_proposal;
	
#define CMD_DUAL_PROPOSAL_ACCEPT	8472
typedef struct dual_proposal_accept
{	
	char name[NM_LENGTH];
}t_dual_proposal_accept;

#define CMD_DUAL_PROPOSAL_REFUSE	8472

#define CMD_DUAL_SURRENDER			8476



#define CMD_SERVER_ITEMTABLE_RELOAD	 8480




#define  CMD_DEBUG_CHANGE_SKILL_EXP		8490
typedef struct debug_change_skill_exp
{
	short int id;
	DWORD			skillexp[45];		// 1219 YGI 경험치


}t_debug_change_skill_exp;




// 국가전에 대한  packet..





#define CMD_SEALSTONE_WAR_LEFTTIME			8850

typedef struct sealstone_warlefttime
{				
	char  nation;
	DWORD lefttime;
}t_sealstone_warlefttime;

#define CMD_SEALSTONE_WAR_START				8851
typedef struct sealstone_war_start
{				
	char  nation;
}t_sealstone_war_start;

	
#define CMD_SEALSTONE_RE_GENTIME			8860
typedef struct sealstone_regentime
{	
	char nation;
	DWORD regentime;
}t_sealstone_regentime;
 
 
#define CMD_SEALSTONE_START_RE_GENTIME		8869
#define CMD_SEALSTONE_END_RE_GENTIME		8870
 
 
#define CMD_SEALSTONE_RESULT				8880


 
typedef struct sealstone_result
{	
	char aresult;
	char anation;
	
	char bresult;
	char bnation;
}t_sealstone_result;


#define CMD_SEALSTONEFROMKING				8890
typedef struct	sealstone_fromking
{
	char nation;
}t_sealstone_fromking;


#define CMD_SEALSTONE_STATUS				8892
typedef struct sealstone_status
{
	char sealstonesprno;
	short int id;
	char mapnumber;
	short int x, y;
	char status;

}t_sealstone_status;


#define CMD_STEALSTONE_BREAKABLE			8894
#define CMD_STEALSTONE_NON_BREAKABLE 		8896
#define CMD_STEALSTONE_NON_BREAKABLE_PEACE  8898


#define CMD_NATION2NATION_RELATION			8910

typedef struct nation2nation_relation
{
	char a,b;
	char relation;
	short int year, yday, hour;
	DWORD howlong;

}t_nation2nation_relation;


#define CMD_NATION2NATION_RELATION_RESULT		8912

typedef struct nation2nation_relation_result
{
	BYTE why;

}t_nation2nation_relation_result;





//////////////// Chr_Log 

#define CMD_CHR_LOG_CHAR_DB				9002

typedef struct server_chr_log_basic_data
{
	char id[ NM_LENGTH];
	char name[ NM_LENGTH];
	char state;
	BYTE btLevel; // CSD-030806
	int	 fame_pk;						// 010915 LTS	//Fame_PK -> NWCharacter로 교체 DB에는 실제로 NWCharacter의 값이 들어갑니다.		
	NW_Character	NWCharacter;		// 010915 LTS
	int  Str;
	int  Con;
	int  Dex;
	int  Wis;
	int  Int;
	int  MoveP;
	int  Char;
	int  Endu;
	int  Moral;
	int  Luck;
	int  wsps;

	int  Tactics;
	DWORD nation;	

	DWORD Money;
	int HpMax ;
	int ManaMax;

	char MapName[ NM_LENGTH];
	int HungryMax;

	int Resis_Poison;
	int Resis_Stone	;
	int Resis_Magic	;
	int Resis_Fire	;
	int Resis_Ice	;
	int Resis_Elect	;

	int X, Y;

	int		reserved_point;
	DWORD	BankMoney;
	DWORD	Exp;

}t_server_chr_log_basic_data;


#define CMD_CHR_LOG_BINARY_DATA0	9003
typedef struct server_chr_log_binary_data0
{

	char name[ NM_LENGTH];
	char Skill[ SIZE_OF_SKILL];
	char skillexp[ SIZE_OF_SKILL_EXP];
	char tac_skillEXP[ SIZE_OF_TAC_SKILL_EXP];
}t_server_chr_log_binary_data0;


#define CMD_CHR_LOG_BINARY_DATA1	9004
typedef struct server_chr_log_binary_data1
{
	char name[ NM_LENGTH];
	char equip[ SIZE_OF_EQUIP];
	char quick[ SIZE_OF_QUICK];
}t_server_chr_log_binary_data1;

	
#define CMD_CHR_LOG_BINARY_DATA2	9005
typedef struct server_chr_log_inv_binary_data2
{
		char name[ NM_LENGTH];
		char inv[ SIZE_OF_INV];
}t_server_chr_log_binary_data2;


#define CMD_CHR_LOG_BINARY_DATA3	9006
typedef struct server_chr_log_binary_data3
{
	char name[ NM_LENGTH];
	char bankitem[ SIZE_OF_BANKITEM];
}t_server_chr_log_binary_data3;





#define CMD_HACKING_USER			9007
typedef struct hacking_user
{
	char	id[ ID_LENGTH];
	char	name[NM_LENGTH];
	short	type;
	char	ip[IP_LENGTH];
	char	cause[100];
}t_hacking_user;

typedef struct FriendStatus_ // finito 09/08/07
{
	bool online;
	char name1[20];
	char name2[20];
} t_FriendStatus;

typedef struct check_guilds_ //Eleval 12/09/06
{
	short int idPlayer;
	WORD guildCode;
	char id[20];
} t_check_guilds;

typedef struct sex_change_ //Eleval 12/06/09 - Sex Change
{
	WORD idUser;
	short int iSex;
	char cId[20];
} t_sex_change;

typedef struct ask_squest_tp_ //Eleval 10/08/09 - To bring ppl back in quest
{
	short int cn;
	int	questfloor;
	int nX;
	int nY;
	int nbMap;
	char charname[32];
} t_ask_squest_tp;


#pragma pack (push,1)

	
#include "network2.h"
#include "Network3.h"
#include "NetWork4.h"	// 010915 LTS
#include "NetWork6.h"	// 020110 lsw
//--------------------------------------------------------
//--------------------------------------------------------

//010909 lsw
typedef struct dragon_header
{					
	short int		type;
	short int		size;
	char			crc;	
} t_header;
					
//--------------------------------------------------------
typedef struct packet
{					
	union			
	{				
		char					data[sizeof(t_header)];
		t_header				header;
	} h;			
						
	union			
	{				
		char					data[MAX_PACKET_SIZE];
						
		t_server_weather		server_weather;
		t_server_npc_add		server_npc_add;
		t_server_npc_remove		server_npc_remove;
		t_server_doing_magic	server_doing_magic ;
		t_server_starting_magic server_starting_magic ;
		t_client_doing_magic	client_doing_magic ;
		t_client_starting_magic client_starting_magic ;
		t_client_attack			client_attack;
		t_server_attack			server_attack;

		t_server_modify_position				server_modify_position;
		t_client_modify_position				client_modify_position;
		t_server_modify_position_absolute		server_modify_position_absolute;

		t_server_item_add		server_item_add;
		t_server_item_remove	server_item_remove;
		t_server_you_got_item	server_you_got_item;
		t_client_item_drop		client_item_drop;
		t_client_item_take		client_item_take;
		t_client_item_status	client_item_status;
		t_server_item_status	server_item_status;

		t_client_bank			client_bank;
		
		t_server_accept_login	server_accept_login;
		t_server_accept_join	server_accept_join;
		t_server_assign_server_id server_assign_server_id;
		t_all_ready				all_ready;

		t_client_connect_info	client_connect_info;
		t_server_connect_info	server_connect_info;

		t_client_chat_data		client_chat_data;
		t_server_chat_data		server_chat_data;
		t_client_move			client_move;
		t_server_move			server_move;
		t_client_create_char	client_create_char;
		t_client_delete_char	client_delete_char;


		t_client_event							client_event; // ###0923
		t_item_attr_change						item_attr_change;
		t_item_door_open_close					item_door_open_close;
		t_client_item_box_break					client_item_box_break;
		t_server_item_box_break		 			server_item_box_break;
		t_client_item_box_break_result			client_item_box_break_result;

		t_client_item_box_magic_break			client_item_box_magic_break;
		t_server_item_box_magic_break_result	server_item_box_magic_break_result;

		t_client_just_attack_animation			client_just_attack_animation;

		t_server_change_map						server_change_map;


		t_server_foot_on_trap0		server_foot_on_trap0;
		t_client_foot_on_trap0		client_foot_on_trap0;
		t_server_foot_on_trap1		server_foot_on_trap1;
		t_client_foot_on_trap1		client_foot_on_trap1;

		t_chr_item_info0			chr_item_info0;
		t_chr_item_info1			chr_item_info1;
		t_chr_item_info2			chr_item_info2;
		t_char_info_basic			char_info_basic;
		t_char_info_magic			char_info_magic;
		t_char_info_skill			char_info_skill;
		t_other_info_basic			other_info_basic;
		t_server_give_item			server_give_item;
		k_client_item_inv			client_item_inv;	// 1218
		t_char_info_tac_skillexp	char_info_tac_skillexp;

		t_req_pc_add				req_pc_add;
		t_req_npc_add				req_npc_add;
		t_req_item_add				req_item_add;


		t_server_user_db_data		server_user_db_data;
		t_server_user_add			server_user_add;
		t_server_envir_info			server_envir_info;
		t_server_user_remove		server_user_remove;

		t_item_ex_info				item_ex_info ;
		t_item_exchange				item_exchange;
		t_chr_status_info			chr_status_info ;

		t_attack_result				attack_result ;
		t_attack_info				attack_info ;

		t_server_change_equip		server_change_equip ;
		t_client_change_equip		client_change_equip ;

		t_client_magic_result		client_magic_result ;
		t_server_magic_result		server_magic_result ;
		t_mass_data					mass_data ;

		t_server_insert_magic		server_insert_magic;
		//t_inv_info				inv_info ;
		//t_equip_info				equip_info ;

		t_server_interface_battle	server_interface_battle ;
		t_server_interface_peace	server_interface_peace ;

		// Menu..
		t_server_call_smallmenu		server_call_smallmenu ;
		t_server_store_itemlist		server_store_itemlist;
		t_client_item_buy			client_item_buy ;
		t_client_item_sell			client_item_sell ;
		t_server_menu_message		server_menu_message;

		t_server_guild_info			server_guild_info;
		t_client_learn_skill		client_learn_skill;
		t_server_learn_skill		server_learn_skill;
		t_server_learn_skillitem	server_learn_skillitem;				//### 1214 수정 
		t_server_repair_itemlist	server_repair_itemlist;
		t_client_item_repair		client_item_repair;
		t_server_item_repair		server_item_repair;
		t_server_rumor_info			server_rumor_info;
		t_server_menu_message_title server_menu_message_title;
		t_client_menu_message_title client_menu_message_title;
		t_server_menu_message_text	server_menu_message_text;

		t_client_levelup_point		client_levelup_point;
		t_server_levelup_point		server_levelup_point;

		// Animation..
		t_server_turn_dir			server_turn_dir;

		// Skill..
		t_server_skill_info			server_skill_info;
		t_client_skill_info			client_skill_info;
		t_server_skill_result		server_skill_result;
		t_client_skill_result		client_skill_result;

		t_client_skill_item_matter		client_skill_item_matter;
		t_server_skill_itemmake_result	server_skill_itemmake_result;
		t_server_skill_result_fail		server_skill_result_fail;
		t_server_skill_result_toother	server_skill_result_toother;
		t_client_skill_cursor_view		client_skill_cursor_view;

		t_client_skill_gauge			client_skill_gauge;
		t_server_skill_gauge			server_skill_gauge;

		t_viewtype_change				viewtype_change;
		t_view_char_info				view_char_info;

		t_roof_open						roof_open;
		t_roof_close					roof_close;


		t_chat_set_result				chat_set_result;
		t_chat_set						chat_set;

		t_total_map_connections			total_map_connections;
		t_total_connections				total_connections;

		t_client_isthere_charname		client_isthere_charname;

		t_tame_command					tame_command;
		t_tame_name_change				tame_name_change;
		t_tame_host_name				tame_host_name;
		t_tame_command_result			tame_command_result;
		t_tame_end						tame_end;


		t_you_die						you_die;

		t_debug_server_req_char_info	debug_server_req_char_info;
		t_debug_client_req_char_info	debug_client_req_char_info;

		t_please_give_life				please_give_life;

		t_client_smile_face				client_smile_face;
		t_server_smile_face				server_smile_face;

		// 공지사항..
		t_server_bbs					server_bbs;


		// 게임서버 인식 
		t_im_game_server				im_game_server;


		//------------------- NEW_APPEND -------------------------
		t_server_access_char_db			server_access_char_db;
		t_server_accept_char_db			server_accept_char_db;
		t_server_accept_char_game_db	server_accept_char_game_db;
		t_server_accept_binary_data		server_accept_binary_data;
		t_server_accept_script_data		server_accept_script_data;
		t_server_accept_inv_data		server_accept_inv_data;
		t_server_accept_item_data		server_accept_item_data;
		t_server_accept_bankitem_data	server_accept_bankitem_data;

		t_server_accept_data_error		server_accept_data_error;

		// 운영자용 
		t_absolute_logout				absolute_logout;
		t_make_ghost					make_ghost;
		t_give_life						give_life;


		// Update to LoginServer....
		t_update_char_db				update_char_db;
		t_server_update_binary_data0	server_update_binary_data0;
		t_server_update_binary_data1	server_update_binary_data1;
		t_server_update_script_data		server_update_script_data;
		t_server_update_inv_data		server_update_inv_data;
		t_server_update_item_data		server_update_item_data;
		t_server_update_bankitem_data	server_update_bankitem_data;


		// GameServer와  LoginServer와의 Access Join관계..
		t_gs_req_insert_userid	gs_req_insert_userid;
		t_gs_req_delete_userid	gs_req_delete_userid;
		t_ls_joinable			ls_joinable;
		t_ls_not_joinable		ls_not_joinable;
		t_ls_updating			ls_updating;

		t_how_many_in_map		how_many_in_map;

		// Item Duration 감소처리....
		t_item_duration_change	item_duration_change;


		// Client에서 NPC관리를 위한 프로토콜
		t_npc_attack			npc_attack;
		t_npc_chat_data			npc_chat_data;

		t_npcctrl_muri_8		npcctrl_muri_8;
		t_npcctrl_muri_18		npcctrl_muri_18;
		t_npcctrl_muri_28		npcctrl_muri_28;		
		t_npcctrl_wander_38		npcctrl_wander_38;
		t_npcctrl_wander_maul	npcctrl_wander_maul;
		t_npcctrl_no_move		npcctrl_no_move;
		t_npcctrl_wander_guard	npcctrl_wander_guard;
		t_npcctrl_tame			npcctrl_tame;

		t_npc_modify_pos				npc_modify_pos;
		t_send_npc_parameter			send_npc_parameter;
		t_send_npc_string_parameter		send_npc_string_parameter;

		t_start_goodbad					start_goodbad;
		t_endof_goodbad					endof_goodbad;

		t_login_bbs						login_bbs;

		t_char_in_game					char_in_game;	// 게임서버에 그러한 놈이 잇는가 없는가를 Check한다. 
		t_login_close_login_id			login_close_login_id;

		t_update_very_important_status	update_very_important_status;
		t_update_very_important_tactics update_very_important_tactics;

		t_tactics_parrying_exp			tactics_parrying_exp;

		t_debug_change_skill_exp		debug_change_skill_exp;

		// 국가전에 대한 packet.
		t_sealstone_warlefttime		sealstone_warlefttime;
		t_sealstone_war_start		sealstone_war_start;
		t_sealstone_result			sealstone_result;
		t_sealstone_fromking		sealstone_fromking;
		t_sealstone_status			sealstone_status;			


		t_nation2nation_relation		nation2nation_relation;
		t_nation2nation_relation_result	nation2nation_relation_result;


		// ZHH's 
		t_server_special_item	server_special_item;

		CLIENTACCESSLOGIN	ClientAccessLogin;

		t_server_chr_log_basic_data		server_chr_log_basic_data;
		t_server_chr_log_binary_data0 server_chr_log_binary_data0;
		t_server_chr_log_binary_data1 server_chr_log_binary_data1;
		t_server_chr_log_binary_data2 server_chr_log_binary_data2;
		t_server_chr_log_binary_data3 server_chr_log_binary_data3;

		t_client_login_fail_reason		client_login_fail_reason;

		t_hacking_user				hacking_user;
		t_rare_item_make_log		rare_item_make_log;

		t_ConformSadonix			ConformSadonix;
		t_SadonixCountUpdate		SadonixCountUpdate;
		t_ComformResetAbililty		ComformResetAbililty;
		
		//021008 lsw
		t_SearchPacketServer		SearchPacketServer	;
		t_SellerItemRequest			SellerItemRequest;
		t_SellerItemRegister		SellerItemRegister;
		t_SellerItemDelete			SellerItemDelete;
		t_MerchantItemBuy			MerchantItemBuy;
		t_MerchantResultTake		MerchantResultTake;
		t_MerchantExchangeRequest	MerchantExchangeRequest;
		//021008 lsw
		t_SearchResultList SearchResultList;
		t_angra angra;
		t_kein kein;
		t_NationWar NationWar;
		t_Hwoarang Hwoa;
		LOTTO_EVENT_INFO Lotto_Info;//soto-030504
		t_BUY_LOTTO	Lotto_Buy;
		t_CHECK_WINNER Check_Winner;
		t_WINNER_MENU Lotto_Winner_Menu;
		t_LOTTERY_INFO Lotto_BroadCast;//soto-HK030924
		t_LOTTOPAPER_SEEK Lotto_Seek;//soto-Lotto추가.
		t_DEL_LOTTO_USER_OK	Lotto_Del_Ok;		// BBD 040127	로또 프로세스 변경
		t_EVENT_RARE_ITEM_LIST		Event_Item_List;	// BBD 040308	이벤트레어아이템 확인용 구조체
		t_FriendStatus				FriendStatus; // finito 09/08/07
		t_check_guilds				check_guilds; // Eleval 12/06/09

		t_sex_change			sex_change; //Eleval 12/06/09 - Sex Change

		t_ask_squest_tp			ask_squest_tp; //Eleval 10/08/09 - To bring ppl back in quest
	} u;
	
	struct packet *next;

} t_packet;


#pragma pack (pop)

	



//--------------------------------------------------------
//--------------------------------------------------------
//--------------------------------------------------------

//#endif
//--------------------------------------------------------
//--------------------------------------------------------
//--------------------------------------------------------

typedef struct connection 
{
//	SOCKET			socket;
//	struct			sockaddr_in addr;
	int				state;
//	t_packet		*inbuf;
//	t_packet		*outbuf;
	int				receive;
//	int				receive_count;
    DWORD			connect_time;
	DWORD			monitor_time;
	DWORD			send_bytes;
	DWORD			receive_bytes;
	int				send_try;		// 보내기 횟수...

	int				send_addlen;

	char			ip_address[IP_LENGTH];
	int				myconnectedagentport;

	int				last_year;
	int				last_mon;
	int				last_day;
	int				last_hour;
	int				last_min;

	int				login_year;
	int				login_mon;
	int				login_day;
	int				login_hour;
	int				login_min;
	int				login_sec;

	t_packet		packet;
	int				packet_pnt;
	int				packet_size;
	int				packet_status;
	int				packet_count[2];

	int				kick_out;
	DWORD			kick_out_time;

	int				save_db;
	DWORD			save_db_time;

	char			id[ID_LENGTH];
	char			pw[PW_LENGTH];
	char			name[NM_LENGTH];
	char			mapname[NM_LENGTH];

	//------------ NEW_APPEND -------------------------------
	int				server_check;
	//-------------------------------------------------------

    CHARLIST		chrlst;

	char		*SendBuf;				// send()로 보낼 내용을 다음에 담아 놓는다. 
	int			SendBufSize;			// send()로 보낼 내용의 크기. 
	int			SendErr;				// send()로 보낼 내용의 크기. 
	DWORD		dwMyAgentIndex;
	DWORD		dwUserID;
	DWORD		dwConIndex;
	BOOL		bUse;
} t_connection;


#ifndef __CLIENT_PROGRAM__

#ifdef _GAME_SERVER_
	extern t_connection	connections[DRAGON_MAX_CONNECTIONS];
#else 
	extern t_connection	connections[LOGIN_MAX_CONNECTIONS];
#endif

	extern DWORD		global_time;
	extern DWORD		alive_time;

#else
	extern int curr_connect;
	extern t_connection	connections[2];

	extern DWORD 		g_ping_delay;
	extern DWORD 		g_ping_time;

#endif

///////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
extern "C"
{
#endif



//-----------------------------------------------------------------
//-----------------------------------------------------------------
//-----------------------------------------------------------------
	extern void CalcLogFName(void);
	extern void AddLogMessage(t_connection c[], int cn);
	extern void CheckProcessRoutine(t_connection c[]);
	extern void CheckBytesRoutine(void);
	extern int  QueuePacket(t_connection c[], int cn, t_packet *packet, int type);
	extern int  DequeuePacket(t_connection c[], int cn, t_packet *packet, int type);
	extern void SendWeatherRoutine(t_connection c[]);

	enum eCloseConnectionType
	{
		CCT_NORMAL			= -41,
		CCT_ID_USING_NOW	= -44,
		CCT_ID_NOT_EXIST	= -45,
		CCT_WRONG_PASSWORD	= -46,
		CCT_PAYMENT_NEED	= -47,
		CCT_AGE_NOT_PERMIT	= -50,	// 030929 kyo
		CCT_INVALID_CLIENT	= -100,
		CCT_AGENT_ORDER		= -	1,
		CCT_FORCED = -40,
	};
	extern void closeconnection(t_connection c[], int cn, const eCloseConnectionType errnum);

	//------------ NEW_APPEND -------------------------------
	extern int	ConnectServer(t_connection c[], int cn, LPSTR lpIP, int nPort );
	//-------------------------------------------------------
	extern int  HandleAccepting(t_connection c[], SOCKET lsock);
	extern int  HandleCommand(t_connection c[], DWORD dwIndex, t_packet *packet, DWORD dwUserID, int cn);
	extern int  HandleCommand2(t_connection c[], DWORD dwIndex, t_packet *packet, DWORD dwUserID, const int cn);//020410 lsw
	extern int  HandleReading(t_connection c[], int cn);
	extern int  HandleWriting(t_connection c[], int cn);
	extern int  HandleWriting_neo(t_connection c[], int cn);
	extern void SendUserData(t_connection c[]);
	
	extern int SettingMoveData_( int j, CHARLIST *c, t_packet *p );

	extern void RecvCMD_ITEM_BOX_BREAK( int cn, t_client_item_box_break *p );
	extern void RecvCMD_JUST_ATTACK_ANIMATION( int cn, t_client_just_attack_animation *p );
	extern void RecvCMD_ITEM_BOX_BREAK_RESULT( int cn, t_client_item_box_break_result *p );
	extern void RecvCMD_ITEM_BOX_MAGIC_BREAK( int cn, t_client_item_box_magic_break	*p );
	extern void RecvTotalMapConnections( int cn );
	extern void RecvTotalConnections( int cn );

	extern void SaveBallancing( LPCHARLIST a, LPCHARLIST d, int magicno, int damage, int mana, int attack, int attacktype, int tac  );

	
//-----------------------------------------------------------------
//-----------------------------------------------------------------
//-----------------------------------------------------------------



#ifdef __cplusplus
}
#endif

#endif	// __NETWORK_H__

