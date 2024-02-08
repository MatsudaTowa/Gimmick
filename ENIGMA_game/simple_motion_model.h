//=========================================================
//
//簡易モーションMODEL宣言など[simple_motion_model.h]
// Author seiya kagaya
//
//=========================================================
#ifndef _SIMPELMOTION_//このマクロが定義されてなかったら

//マクロ定義
#define _SIMPELMOTION_//二重インクルード防止のマクロ定義

#include "game.h"
//
//#define MAX_BOOSTER	(1)//ブースターパーツ数
//#define MAX_BOOSTERPARTS	(2)//ブースターパーツ数


//フォントの種類
//--------------------フォントのラベル的な
typedef enum
{
	SIMPLEMOTIONMODEL_Test1 = 0,//
	SIMPLEMOTIONMODEL_Test2,
	SIMPLEMOTIONMODEL_MAX,
}SIMPLEMOTIONMODEL;


//情報の構造体
typedef struct
{
	D3DXVECTOR3 pos;	//位置

	D3DXVECTOR3 rot;	//向き

	D3DXMATRIX mtxWorld;//ワールドマトリックス

	bool bUse;
}SIMPLEMODEL;

//プロトタイプ宣言
void InitSimpleModel(void);
void UninitSimpleModel(void);
void UpdateSimpleModel(void);
void DrawSimpleModel(void);

//簡易モーションモデル設定処理
void SetSimpleModel(SIMPLEMOTIONMODEL SetUpName_Index, D3DXVECTOR3 pos, D3DXVECTOR3 rot);

#endif // !_PLAYER_H_
