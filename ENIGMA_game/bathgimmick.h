//=============================================
//
//�����C�̃M�~�b�N[bathgimmick.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _BATHGIMMICK_H_ //��`����ĂȂ�������
#define _BATHGIMMICK_H_ //�Q��C���N���[�h�h�~

#include "main.h"

//=============================================
//�}�N����`
//=============================================
#define BATHWATER_WIDE	(30)
#define BATHWATER_DEPTH	(60)
#define SPAWN_STEAM		(20) //���C���o��J�E���g
#define USE_STEAM		(20) //���̃X�|�[���œ��C���o�鐔

//=============================================
//�����C�̂����̍\�z�̂̒�`
//=============================================
typedef struct
{
	D3DXVECTOR3 pos;
	D3DXVECTOR3 rot;
	int nSteamSpawnCnt; //���C���X�|�[������܂ŃJ�E���g����
	float fWide;
	float fDepth;
	bool bUse;
}BathWater;

//=========================================================
//�v���g�^�C�v�錾
//=========================================================
void InitBathGimmick(void);
void UninitBathGimmick(void);
void UpdateBathGimmick(void);
void DrawBathGimmick(void);
void SetBathWater(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float fWide, float fDepth);
BathWater* GetBathGimmickPos(void);

#endif // _POLYGON_H_ //��`����ĂȂ�������