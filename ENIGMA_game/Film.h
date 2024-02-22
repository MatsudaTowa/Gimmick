//==============================
//
// フィルム動かす[Film.h]
// Author:Kaito Hondo
//
//==============================

#ifndef _FILM_H_	// このマクロ定義がされてなかったら
#define _FILM_H_	// ２重インクルード防止のマクロ定義

#include "main.h"

//マクロ定義
#define FILM_TEXTURE  "data\\TEXTURE\\Film000.png"
#define FILM_TEXTURE2 "data\\TEXTURE\\Film001.png"
#define FILM_TEXTURE3 "data\\TEXTURE\\Film002.png"


// プロトタイプ宣言
void InitFILM(void);
void UninitFILM(void);
void UpdateFILM(void);
void DrawFILM(void);

#endif

