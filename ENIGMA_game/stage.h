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
#define TEXNUM	(4)//テクスチャの数

#define STAGESIZE	(3000.0f)

//壁の向いてる方向構造体
typedef enum
{
	STAGETYPE_test0 = 0,
	STAGETYPE_test1,
	STAGETYPE_test2,
	STAGETYPE_test3,
}STAGETYPE;


//壁の構造体
typedef struct
{
	D3DXVECTOR3 posStage;	//位置
	D3DXVECTOR3 rotStage;	//向き
	D3DXMATRIX mtxWorldStage;//ワールドマトリックス
	STAGETYPE StageType;//壁の向き
	bool bUse;
}STAGE;




void InitStage(void);
void UninitStage(void);
void UpdateStage(void);
void DrawStage(void);
STAGE* GetStage(void);

//壁の設定
void SetStage(D3DXVECTOR3 Pos,float angle, float Width, float Height, STAGETYPE testType);


#endif