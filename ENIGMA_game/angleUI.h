//=============================================
//
//�G�Ȃǂ̕���������UI[angleUI.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _ANGLEUI_H_ //��`����ĂȂ�������
#define _ANGLEUI_H_ //�Q��C���N���[�h�h�~

#include "main.h"

//=============================================
//�}�N����`
//=============================================
#define NUM_ANGLEUI	(2) //�v���C���[��

//=============================================
//��ʂɑ΂���g���b�v�̒�`
//=============================================
typedef struct
{
	D3DXVECTOR3 pos;
	D3DXVECTOR3 rot;
	float fAlpha; //�A���t�@�l
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