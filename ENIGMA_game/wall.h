//=========================================================
//
//�ǂŎg���ϐ��A�錾�A�\����[wall.h]
// Author seiya kagaya
//
//=========================================================
#ifndef _WALL_H

#define _WALL_H_//��d�C���N���[�h�h�~

#include"main.h"

#define NUMWALL	(64)//�ǂ̐�
#define TEXNUM	(4)//�e�N�X�`���̐�

#define WALLSIZE	(3000.0f)

//�ǂ̌����Ă�����\����
typedef enum
{
	WALLTYPE_test0 = 0,
	WALLTYPE_test1,
	WALLTYPE_test2,
	WALLTYPE_test3,
}WALLTYPE;


//�ǂ̍\����
typedef struct
{
	D3DXVECTOR3 posWall;	//�ʒu
	D3DXVECTOR3 rotWall;	//����
	D3DXMATRIX mtxWorldWall;//���[���h�}�g���b�N�X

	WALLTYPE WallType;//�ǂ̌���

	bool bUse;
}WALL;




void InitWall(void);
void UninitWall(void);
void UpdateWall(void);
void DrawWall(void);
WALL* GetWall(void);

//�ǂ̐ݒ�
void SetWall(D3DXVECTOR3 Pos,float angle,int Width,int height, WALLTYPE testType);


#endif