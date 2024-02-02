//=========================================================
//
//�e���ˏ����֌W�Ŏg���ϐ��A�錾�A�\����[bullet.h]
// Author seiya kagaya
//
//=========================================================
#ifndef _SPEECHBUBBLE_H_

#define _SPEECHBUBBLE_H_//��d�C���N���[�h�h�~

#include"main.h"

#include "game.h"

#define NUMSPEECHBUBBLE	(648)//�e�̐�

#define TEXNUM	(4)//�e�N�X�`���̐�

#define ZOOMSPEED	(6)//�g�呬�x
#define REDSPEED	(4)//�k�����x



typedef enum
{
	SPEECHBUBBLETYPE_Player = 0,
	SPEECHBUBBLETYPE_Enemy,
	SPEECHBUBBLETYPE_MAX,
}SPEECHBUBBLETYPE;

//typedef enum
//{
//	SPEECHBUBBLESTATE_ADD = 0,
//	SPEECHBUBBLESTATE_STANDBY,
//	SPEECHBUBBLESTATE_MAX,
//}SPEECHBUBBLESTATE;


//�ǂ̍\����
typedef struct
{
	D3DXVECTOR3 pos;	//�ʒu
	D3DXMATRIX mtxWorldSpeechBubble;//���[���h�}�g���b�N�X
//	SPEECHBUBBLESTATE BubbleState;//���
	int nBubbleCnt;//
	bool bOK;//�������̃^�C�~���O��OK�ɂȂ��Ă�΃f�N�������g�����Ȃ�
	bool bUse;
}SPEECHBUBBLE;




void InitSpeechBubble(void);
void UninitSpeechBubble(void);
void UpdateSpeechBubble(void);
void DrawSpeechBubble(void);

SPEECHBUBBLE* GetSpeechBubble(void);

//�ǂ̐ݒ�-------------------------------�A�N�V�����ԍ�---[SetType-0���o���A�P���k��]
void SetSpeechBubble(D3DXVECTOR3 Pos,int ActionIndex,int SetType);


// �\�������_���v�Z����֐�
//D3DXVECTOR3 PredictIntersection(SPEECHBUBBLE bullet, Enemy enemy);


#endif // _SPEECHBUBBLE_H_
