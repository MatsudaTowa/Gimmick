//=========================================================
//
//�X�N���[��UI�Ŏg���ϐ��A�錾�A�\����[screenui.h]
// Author seiya kagaya
//
//=========================================================
#ifndef _SCREENUI_H

#define _SCREENUI_H_//��d�C���N���[�h�h�~

#include"main.h"

#define NUM_UI	(2)//UI��ʂ̕\����

//�e�\���̂̒�`
struct ScreenUI
{
	D3DXVECTOR3 pos;//�ʒu
};

//�t�F�[�h�̏��
typedef enum
{
	SCREENUI_1 = 0,//�w�i���
	SCREENUI_WATCH,//�w�i���
	SCREENUI_MAX

}SCREENUISTATE;

//�v���g�^�C�v�錾
void InitScreenUI(void);
void UninitScreenUI(void);
void UpdateScreenUI(void);
void DrawScreenUI(void);

#endif // !_SCREENUI_H_