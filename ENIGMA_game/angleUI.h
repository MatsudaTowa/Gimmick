//=============================================
//
//敵などの方向を示すUI[angleUI.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _ANGLEUI_H_ //定義されてなかったら
#define _ANGLEUI_H_ //２種インクルード防止

#include "main.h"

//=============================================
//マクロ定義
//=============================================
#define NUM_ANGLEUI	(2) //プレイヤー分

//=============================================
//画面に対するトラップの定義
//=============================================
typedef struct
{
	D3DXVECTOR3 pos;
	D3DXVECTOR3 rot;
	float fAlpha; //アルファ値
	float fLength;
	float fAngle;
	bool bUse;
}AngleUI;

void InitAngleUI(void);
void UninitAngleUI(void);
void UpdateAngleUI(void);
void DrawAngleUI(void);
void SetAngleUI(int nPlayer);

#endif