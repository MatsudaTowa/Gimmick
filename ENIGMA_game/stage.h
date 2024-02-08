//=========================================================
//
//�ǂŎg���ϐ��A�錾�A�\����[stage.h]
// Author seiya kagaya mori itsuki
//
//=========================================================
#ifndef _STAGE_H_

#define _STAGE_H__//��d�C���N���[�h�h�~

#include"main.h"

#define NUMSTAGE	(64)//�ǂ̐�
#define STAGETEXNUM	(5)//�e�N�X�`���̐�

#define STAGESIZE	(3000.0f)

//�ǂ̌����Ă�����\����
typedef enum
{
	STAGETYPE_WALL = 0,
	STAGETYPE_FLOOR,
	STAGETYPE_test0,
	STAGETYPE_test1,
}STAGETYPE;

//�e�N�X�`���̎��
typedef enum
{
	TEXTYPE_00 = 0,
	TEXTYPE_01,
	TEXTYPE_02,
	TEXTYPE_03,
	TEXTYPE_04,
	TEXTYPE_MAX
}TEXTYPE;

//�ǂ̍\����
typedef struct
{
	D3DXVECTOR3 posStage;	//�ʒu
	D3DXVECTOR3 rotStage;	//����
	D3DXMATRIX mtxWorldStage;//���[���h�}�g���b�N�X
	//STAGETYPE StageType;//�ǂ̌���
	TEXTYPE TexType;

	bool bCollision;//�����蔻�肪ON��
	D3DXVECTOR3	MaxPos;
	D3DXVECTOR3	MinPos;

	bool bUse;
}STAGE;

void InitStage(void);
void UninitStage(void);
void UpdateStage(void);
void DrawStage(void);
STAGE* GetStage(void);

//�ǂ̐ݒ�
void SetStage(D3DXVECTOR3 Pos, float angle, float bes, float ver,TEXTYPE TexType);


#endif