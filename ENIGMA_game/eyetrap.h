//=============================================
//
//��ʂɑ΂���g���b�v[eyetrap.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _EYETRAP_H_ //��`����ĂȂ�������
#define _EYETRAP_H_ //�Q��C���N���[�h�h�~

#include "main.h"

//=============================================
//�}�N����`
//=============================================
#define NUM_TRAP	(2) //�v���C���[��
#define BLIND_TIME	(120) //�p������

//=============================================
//��ʂɑ΂���g���b�v�̒�`
//=============================================
typedef struct
{
	D3DXVECTOR3 pos;
	D3DXVECTOR3 rot;
	float fAlpha; //�A���t�@�l
	int nBlindCnt; //�p���J�E���g
	bool bUse;
}EyeTrap;

void InitEyeTrap(void);
void UninitEyeTrap(void);
void UpdateEyeTrap(void);
void DrawEyeTrap(void);
void SetEyeTrap(int nPlayer);

#endif