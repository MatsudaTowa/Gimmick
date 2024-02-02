//=========================================================
//
//�Q�[����ʂŎg���ϐ��A�錾�A�\����[game.h]
// Author seiya kagaya
//
//=========================================================
#ifndef _GAME_H_

#define _GAME_H_//��d�C���N���[�h�h�~

#include"main.h"
#include "model.h"
#include "Actionzone.h"

//#define MAX_WORD	(8192)
//#define MAX_WORD3	(512)

#define MAX_MODEL	(256) //���f���̍ő吔
#define NUM_MODEL	(25) //���f���̎��
#define MAX_FIELD	(256) //���̍ő吔
#define MAX_WALL	(256) //�ǂ̍ő吔
#define GAME_END_DELAY	(180)//�]�C
#define MODEL_FILE	"data\\Model.bin" //���f���t�@�C��
#define FIELD_FILE	"data\\Field.bin" //���t�@�C��
#define WALL_FILE	"data\\Wall.bin" //�ǃt�@�C��

//#define GAMETIME	(10)

//#define MAXARRANGEMENTS	(20)//���f�����̂̍ő吔

//#define MAXENEMYMODEL	(4)//�G���



//#define MAXARRANGEMENTSMODEL	(40)//�z�u���̎��

//typedef struct
//{
//	D3DXVECTOR3 POS;//�o���ʒu
//	D3DXVECTOR3 ROT;//�������Ƃ̈ړ����x
//	int Type;//�G�̎��
//	char cModelFileName[MAXENEMYMODEL][MAX_WORD3];//�Ƃ肠����20�Ńt�@�C�������Ǘ�--0�Ԗڂł��ׂĊǗ�
//}ENEMYSET;//���f�����(�G)
//
//
//typedef struct
//{
//	D3DXVECTOR3 POS;//�o���ʒu
//	D3DXVECTOR3 ROT;//�������Ƃ̈ړ����x
//	int Type;//�z�u���̎��
//	char cModelFileName[MAXENEMYMODEL][MAX_WORD3];//�Ƃ肠����20�Ńt�@�C�������Ǘ�--0�Ԗڂł��ׂĊǗ�
//}MODELSET;//���f�����(�z�u��)
//

//=============================================
//���f���ǂݍ��݂̍\�z�̂̒�`
//=============================================
typedef struct
{
	D3DXVECTOR3 pos;
	D3DXVECTOR3 rot;
	D3DXVECTOR3 move;
	D3DXMATRIX mtxWorld;
	D3DCOLORVALUE Diffuse[MAX_MODEL];
	ModelType nType;
	bool bUse;
	bool bUseGame;
}ModelInfo;

//=============================================
//�Ǔǂݍ��݂̍\�z�̂̒�`
//=============================================
typedef struct
{
	D3DXVECTOR3 pos;
	D3DXVECTOR3 rot;
	int nType;
	float fWide;
	float fHeight;
	bool bUse;
	bool bUseGame;
}WallInfo;

//=============================================
//���ǂݍ��݂̍\�z�̂̒�`
//=============================================
typedef struct
{
	D3DXVECTOR3 pos;
	D3DXVECTOR3 rot;
	int nType;
	float fWide;
	float fDepth;
	bool bUse;
	bool bUseGame;
}FieldInfo;


//��������
//#define ENDFRAME	(6000)//6000��100�b
//#define CASTPOSY	(-8000)//�͂��߂ɔz�u����������

//�v���g�^�C�v�錾
void InitGame(void);
void UninitGame(void);
void UpdateGame(void);
void DrawGame(void);
void  GameClear(void);
void ReleasePause(void);
void LoadModel(void);
void LoadField(void);
void LoadWall(void);

//���C�𗘗p�����~�`���m�̓����蔻��
bool CheckCollisionWithRay(D3DXVECTOR3 start, D3DXVECTOR3 direction, D3DXVECTOR3 move, float selfRadius, float targetRadius, D3DXVECTOR3 centerPos);

//void LoadEnemySet(void);
//void LoadMODELSet(void);

//ENEMYSET* GetEnemySet(void);//�G

//MODELSET* GetModelSet(void);//�z�u��



//���^�����蔻��
void BoxCollisionPlayer(D3DXVECTOR3 PlayerMin, D3DXVECTOR3 PlayerMax, D3DXVECTOR3 HitMin, D3DXVECTOR3 HitMax,int PlayerIndex);

//�v���C���[�ƃJ�����̊Ԃ̏�Q������
void AdjustPlayerPositionToCollision_CAMERA(D3DXVECTOR3 playerPos, int CameraIndex, D3DXVECTOR3 HitMin, D3DXVECTOR3 HitMax);

//�v���C���[�ƒ����_�̊Ԃ̏�Q������
void AdjustPlayerPositionToCollision_VIEWPOS(D3DXVECTOR3 playerPos, int PlayerIndex, D3DXVECTOR3 HitMin, D3DXVECTOR3 HitMax);

//�]�ږ哖���蔻��
void BoxCollisionGate(D3DXVECTOR3 PlayerMin, D3DXVECTOR3 PlayerMax, D3DXVECTOR3 GateMin, D3DXVECTOR3 GateMax, int PlayerIndex, int GateIndex, int ParentIndex);

//�s���G���A�����蔻��
void SphereCollisionZone(D3DXVECTOR3 PlayerPos, int PlayerIndex, int ZoneIndex);

//�v���C���[���^�����蔻��--�A�C�e��
void BoxCollisionItem(D3DXVECTOR3 PlayerMin, D3DXVECTOR3 PlayerMax, D3DXVECTOR3 HitPos, int PlayerIndex, int ItemIndex);


//�������牺�A������p

//���^�����蔻��--�G�g�p
//void BoxCollisionEnamy(int EnemyIndex, D3DXVECTOR3 EnamyMin, D3DXVECTOR3 EnamyMax, D3DXVECTOR3 HitMin, D3DXVECTOR3 HitMax);

//���^�����蔻��--�o���b�g�g�p
//void BoxCollisionBullet(int BulletIndex, D3DXVECTOR3 HitMin, D3DXVECTOR3 HitMax, EXISTENCETYPE type);




#endif 