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
#define TEXNUM	(4)//�e�N�X�`���̐�

#define STAGESIZE	(3000.0f)

//�ǂ̌����Ă�����\����
typedef enum
{
	STAGETYPE_test0 = 0,
	STAGETYPE_test1,
	STAGETYPE_test2,
	STAGETYPE_test3,
}STAGETYPE;


//�ǂ̍\����
typedef struct
{
	D3DXVECTOR3 posStage;	//�ʒu
	D3DXVECTOR3 rotStage;	//����
	D3DXMATRIX mtxWorldStage;//���[���h�}�g���b�N�X
	STAGETYPE StageType;//�ǂ̌���
	bool bUse;
}STAGE;




void InitStage(void);
void UninitStage(void);
void UpdateStage(void);
void DrawStage(void);
STAGE* GetStage(void);

//�ǂ̐ݒ�
void SetStage(D3DXVECTOR3 Pos,float angle, float Width, float Height, STAGETYPE testType);


#endif