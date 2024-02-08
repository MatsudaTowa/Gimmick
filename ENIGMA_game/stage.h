//=========================================================
//
//壁で使う変数、宣言、構造体[stage.h]
// Author seiya kagaya mori itsuki
//
//=========================================================
#ifndef _STAGE_H_

#define _STAGE_H__//二重インクルード防止

#include"main.h"

#define NUMSTAGE	(64)//壁の数
#define STAGETEXNUM	(5)//テクスチャの数

#define STAGESIZE	(3000.0f)

//壁の向いてる方向構造体
typedef enum
{
	STAGETYPE_WALL = 0,
	STAGETYPE_FLOOR,
	STAGETYPE_test0,
	STAGETYPE_test1,
}STAGETYPE;

//テクスチャの種類
typedef enum
{
	TEXTYPE_00 = 0,
	TEXTYPE_01,
	TEXTYPE_02,
	TEXTYPE_03,
	TEXTYPE_04,
	TEXTYPE_MAX
}TEXTYPE;

//壁の構造体
typedef struct
{
	D3DXVECTOR3 posStage;	//位置
	D3DXVECTOR3 rotStage;	//向き
	D3DXMATRIX mtxWorldStage;//ワールドマトリックス
	//STAGETYPE StageType;//壁の向き
	TEXTYPE TexType;

	bool bCollision;//当たり判定がONか
	D3DXVECTOR3	MaxPos;
	D3DXVECTOR3	MinPos;

	bool bUse;
}STAGE;

void InitStage(void);
void UninitStage(void);
void UpdateStage(void);
void DrawStage(void);
STAGE* GetStage(void);

//壁の設定
void SetStage(D3DXVECTOR3 Pos, float angle, float bes, float ver,TEXTYPE TexType);


#endif