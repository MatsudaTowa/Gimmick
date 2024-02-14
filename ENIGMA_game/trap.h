//=============================================
//
//�����C�̃M�~�b�N[trap.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _TRAP_H_ //��`����ĂȂ�������
#define _TRAP_H_ //�Q��C���N���[�h�h�~

#include "main.h"

//=============================================
//�}�N����`
//=============================================
#define BATHWATER_WIDE	(30)
#define BATHWATER_DEPTH	(60)
#define SPAWN_STEAM		(20) //���C���o��J�E���g
#define USE_STEAM		(20) //���̃X�|�[���œ��C���o�鐔
#define RUNWATER_SPEED	(0.5f) //�����X�s�[�h

typedef enum
{
	TRAPTYPEE_NORMAL = 0,
	TRAPTYPE_MAX,
}TrapType;

//=============================================
//�����C�̂����̍\�z�̂̒�`
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