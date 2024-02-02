//=========================================================
//
//弾発射処理関係で使う変数、宣言、構造体[item.h]
// Author seiya kagaya
//
//=========================================================
#ifndef _ITEMUI_H_

#define _ITEMUI_H_//二重インクルード防止

#include"main.h"

#include "game.h"


#include "item.h"

#define MAXITEMUI	(32)

#define ITEMUISIZE	(30.0f)

typedef enum
{
	ITEM_UI_TYPE_FRAME = 0,//枠
	ITEM_UI_TYPE_POINTER, //ポインター
	ITEM_UI_TYPE_MAINBODY,//本体

}ITEM_UI_TYPE;



//の構造体
typedef struct
{
	D3DXVECTOR3 pos;	//位置
	ITEM_UI_TYPE UItype;//UIのタイプ
	bool bUse;

}ITEM_UI;









void InitItem_UI(void);
void UninitItem_UI(void);
void UpdateItem_UI(void);
void DrawItem_UI(void);



void SetItem_UI(D3DXVECTOR3 pos, ITEM_UI_TYPE ItemUIType);




#endif // _ITEM_H_
