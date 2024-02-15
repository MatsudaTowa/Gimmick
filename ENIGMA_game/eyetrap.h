//=============================================
//
//画面に対するトラップ[eyetrap.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _EYETRAP_H_ //定義されてなかったら
#define _EYETRAP_H_ //２種インクルード防止

#include "main.h"

//=============================================
//マクロ定義
//=============================================
#define NUM_TRAP	(2) //プレイヤー分
#define BLIND_TIME	(120) //継続時間

//=============================================
//画面に対するトラップの定義
//=============================================
typedef struct
{
	D3DXVECTOR3 pos;
	D3DXVECTOR3 rot;
	float fAlpha; //アルファ値
	int nBlindCnt; //継続カウント
	bool bUse;
}EyeTrap;

void InitEyeTrap(void);
void UninitEyeTrap(void);
void UpdateEyeTrap(void);
void DrawEyeTrap(void);
void SetEyeTrap(int nPlayer);

#endif