//=========================================================
//
//弾発射処理関係で使う変数、宣言、構造体[bullet.h]
// Author seiya kagaya
//
//=========================================================
#ifndef _SPEECHBUBBLE_H_

#define _SPEECHBUBBLE_H_//二重インクルード防止

#include"main.h"

#include "game.h"

#define NUMSPEECHBUBBLE	(648)//弾の数

#define TEXNUM	(4)//テクスチャの数

#define ZOOMSPEED	(6)//拡大速度
#define REDSPEED	(4)//縮小速度



typedef enum
{
	SPEECHBUBBLETYPE_Player = 0,
	SPEECHBUBBLETYPE_Enemy,
	SPEECHBUBBLETYPE_MAX,
}SPEECHBUBBLETYPE;

//typedef enum
//{
//	SPEECHBUBBLESTATE_ADD = 0,
//	SPEECHBUBBLESTATE_STANDBY,
//	SPEECHBUBBLESTATE_MAX,
//}SPEECHBUBBLESTATE;


//壁の構造体
typedef struct
{
	D3DXVECTOR3 pos;	//位置
	D3DXMATRIX mtxWorldSpeechBubble;//ワールドマトリックス
//	SPEECHBUBBLESTATE BubbleState;//状態
	int nBubbleCnt;//
	bool bOK;//何処かのタイミングでOKになってればデクリメントさせない
	bool bUse;
}SPEECHBUBBLE;




void InitSpeechBubble(void);
void UninitSpeechBubble(void);
void UpdateSpeechBubble(void);
void DrawSpeechBubble(void);

SPEECHBUBBLE* GetSpeechBubble(void);

//壁の設定-------------------------------アクション番号---[SetType-0が出現、１が縮小]
void SetSpeechBubble(D3DXVECTOR3 Pos,int ActionIndex,int SetType);


// 予測交差点を計算する関数
//D3DXVECTOR3 PredictIntersection(SPEECHBUBBLE bullet, Enemy enemy);


#endif // _SPEECHBUBBLE_H_
