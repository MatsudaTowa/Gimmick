//=========================================================
//
//�e���ˏ����֌W�Ŏg���ϐ��A�錾�A�\����[map.h]
// Author seiya kagaya
//
//=========================================================
#ifndef _MAP_H_

#define _MAP_H_//��d�C���N���[�h�h�~

#include"main.h"

#include "game.h"


#include "item.h"

#define MAPTEXUINUM	(3)//�e�N�X�`���ő吔
#define MAXMAP	(16)//�ő吔

#define MAPSIZE	(20.0f)//�T�C�Y

#define MAPSIZE2	(36.0f)//�T�C�Y

#define ADDMAP	(0.22f)//�n�}�{��


#define UVSize	(0.25f)

//#define MAXGETITEM	(3)//�A�C�e���ő及����

//#define ITEMMOVESPEED_UI	(10.0f)


#define MAP0_START_POS_0 (D3DXVECTOR2(0.5f,0.5f))//�n�}�P�X�^�[�g�n�_0

#define MAP1_START_POS_0 (D3DXVECTOR2(0.2f,0.5f))//�n�}2�X�^�[�g�n�_1









typedef enum
{
	MAP_UI_TYPE_PLAYERPIN_1P_0 = 0,//�v���C���[�s��1_0
	MAP_UI_TYPE_PLAYERPIN_2P_0,//�v���C���[�s��2_0
	MAP_UI_TYPE_PLAYERPIN_1P_1,//�v���C���[�s��1_1
	MAP_UI_TYPE_PLAYERPIN_2P_1,//�v���C���[�s��2_1
	MAP_UI_TYPE_MAP1, //�n�}�P
	MAP_UI_TYPE_MAP2,//�n�}�Q
	MAP_UI_TYPE_MAX

}MAP_UI_TYPE;



//�̍\����
typedef struct
{
	D3DXVECTOR3 pos;	//�ʒu
	MAP_UI_TYPE UItype;//UI�̃^�C�v
	
	

	int PosNum;//�A�C�e���{�̂̎�����A���W�ʒu�ԍ����i�[�A���̑���-1

	int ScreenNum;//�v���C���[�ԍ�1/2
	
	bool bUse;

}MAP;









void InitMap(void);
void UninitMap(void);
void UpdateMap(bool Draw1OK, bool Draw2OK);
void DrawMap(void);



void SetMap(D3DXVECTOR3 pos, MAP_UI_TYPE MAPType,int ScreenNum);




#endif // _ITEM_H_