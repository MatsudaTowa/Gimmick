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
//お風呂のお湯の構想体の定義
//=============================================
typedef struct
{
	D3DXVECTOR3 pos;
	D3DXVECTOR3 rot;
	bool bUse;
}EyeTrap;

void InitEyeTrap(void);
void UninitEyeTrap(void);
void UpdateEyeTrap(void);
void DrawEyeTrap(void);

#endif