//=========================================================
//
//�ȈՃ��[�V����MODEL�錾�Ȃ�[simple_motion_model.h]
// Author seiya kagaya
//
//=========================================================
#ifndef _SIMPELMOTION_//���̃}�N������`����ĂȂ�������

//�}�N����`
#define _SIMPELMOTION_//��d�C���N���[�h�h�~�̃}�N����`

#include "game.h"
//
//#define MAX_BOOSTER	(1)//�u�[�X�^�[�p�[�c��
//#define MAX_BOOSTERPARTS	(2)//�u�[�X�^�[�p�[�c��


//�t�H���g�̎��
//--------------------�t�H���g�̃��x���I��
typedef enum
{
	SIMPLEMOTIONMODEL_Test1 = 0,//
	SIMPLEMOTIONMODEL_Test2,
	SIMPLEMOTIONMODEL_MAX,
}SIMPLEMOTIONMODEL;


//���̍\����
typedef struct
{
	D3DXVECTOR3 pos;	//�ʒu

	D3DXVECTOR3 rot;	//����

	D3DXMATRIX mtxWorld;//���[���h�}�g���b�N�X

	bool bUse;
}SIMPLEMODEL;

//�v���g�^�C�v�錾
void InitSimpleModel(void);
void UninitSimpleModel(void);
void UpdateSimpleModel(void);
void DrawSimpleModel(void);

//�ȈՃ��[�V�������f���ݒ菈��
void SetSimpleModel(SIMPLEMOTIONMODEL SetUpName_Index, D3DXVECTOR3 pos, D3DXVECTOR3 rot);

#endif // !_PLAYER_H_
