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
//�����C�̂����̍\�z�̂̒�`
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