//=========================================================
//
//スクリーンUIで使う変数、宣言、構造体[screenui.h]
// Author seiya kagaya
//
//=========================================================
#ifndef _SCREENUI_H

#define _SCREENUI_H_//二重インクルード防止

#include"main.h"

#define NUM_UI	(2)//UI画面の表示数

//弾構造体の定義
struct ScreenUI
{
	D3DXVECTOR3 pos;//位置
};

//フェードの状態
typedef enum
{
	SCREENUI_1 = 0,//背景状態
	SCREENUI_WATCH,//背景状態
	SCREENUI_MAX

}SCREENUISTATE;

//プロトタイプ宣言
void InitScreenUI(void);
void UninitScreenUI(void);
void UpdateScreenUI(void);
void DrawScreenUI(void);

#endif // !_SCREENUI_H_