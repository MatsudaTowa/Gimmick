//=========================================================
//
//弾発射処理関係で使う変数、宣言、構造体[map.h]
// Author seiya kagaya
//
//=========================================================
#ifndef _MAP_H_

#define _MAP_H_//二重インクルード防止

#include"main.h"

#include "game.h"


#include "item.h"

#define MAPTEXUINUM	(3)//テクスチャ最大数
#define MAXMAP	(16)//最大数

#define MAPSIZE	(20.0f)//サイズ

#define MAPSIZE2	(36.0f)//サイズ

#define ADDMAP	(0.22f)//地図倍率


#define UVSize	(0.25f)

//#define MAXGETITEM	(3)//アイテム最大所持数

//#define ITEMMOVESPEED_UI	(10.0f)


#define MAP0_START_POS_0 (D3DXVECTOR2(0.5f,0.5f))//地図１スタート地点0

#define MAP1_START_POS_0 (D3DXVECTOR2(0.2f,0.5f))//地図2スタート地点1









typedef enum
{
	MAP_UI_TYPE_PLAYERPIN_1P_0 = 0,//プレイヤーピン1_0
	MAP_UI_TYPE_PLAYERPIN_2P_0,//プレイヤーピン2_0
	MAP_UI_TYPE_PLAYERPIN_1P_1,//プレイヤーピン1_1
	MAP_UI_TYPE_PLAYERPIN_2P_1,//プレイヤーピン2_1
	MAP_UI_TYPE_MAP1, //地図１
	MAP_UI_TYPE_MAP2,//地図２
	MAP_UI_TYPE_MAX

}MAP_UI_TYPE;



//の構造体
typedef struct
{
	D3DXVECTOR3 pos;	//位置
	MAP_UI_TYPE UItype;//UIのタイプ
	
	

	int PosNum;//アイテム本体の時限定、座標位置番号を格納、その他は-1

	int ScreenNum;//プレイヤー番号1/2
	
	bool bUse;

}MAP;









void InitMap(void);
void UninitMap(void);
void UpdateMap(bool Draw1OK, bool Draw2OK);
void DrawMap(void);



void SetMap(D3DXVECTOR3 pos, MAP_UI_TYPE MAPType,int ScreenNum);




#endif // _ITEM_H_
