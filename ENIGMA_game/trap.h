//=============================================
//
//お風呂のギミック[trap.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _TRAP_H_ //定義されてなかったら
#define _TRAP_H_ //２種インクルード防止

#include "main.h"

//=============================================
//マクロ定義
//=============================================
#define BATHWATER_WIDE	(30)
#define BATHWATER_DEPTH	(60)
#define SPAWN_STEAM		(20) //湯気が出るカウント
#define USE_STEAM		(20) //一回のスポーンで湯気が出る数
#define RUNWATER_SPEED	(0.5f) //流れるスピード

typedef enum
{
	TRAPTYPEE_NORMAL = 0,
	TRAPTYPE_MAX,
}TrapType;

//=============================================
//お風呂のお湯の構想体の定義
//=============================================
typedef struct
{
	D3DXVECTOR3 pos;
	D3DXVECTOR3 rot;
	TrapType nType;
	float fWide;
	float fHeight;
	bool bUse;
}Trap;

void InitTrap(void);
void UninitTrap(void);
void UpdateTrap(void);
void DrawTrap(void);

#endif