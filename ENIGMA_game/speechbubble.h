//=========================================================
//
//�����o��UI�g���ϐ��A�錾�A�\����[speechbubble.h]
// Author seiya kagaya
//
//=========================================================
#ifndef _SPEECHBUBBLE_H_

#define _SPEECHBUBBLE_H_//��d�C���N���[�h�h�~

#include"main.h"

#include "game.h"

#define NUMSPEECHBUBBLE	(264)//�e�̐�

#define TEXNUM	(5)//�e�N�X�`���̐�

#define ZOOMSPEED	(6)//�g�呬�x
#define REDSPEED	(4)//�k�����x

#define  XMAG (0.6f)
#define  XMAG2 (0.4f)

typedef enum
{
	SPEECHBUBBLETYPE_TRANCE = 0,
	SPEECHBUBBLETYPE_ACTION,
	SPEECHBUBBLETYPE_GET,
	SPEECHBUBBLETYPE_LONGACTION,
	SPEECHBUBBLETYPE_GAMECLEAR,
	SPEECHBUBBLETYPE_MAX,
}SPEECHBUBBLETYPE;


//�ǂ̍\����
typedef struct
{
	D3DXVECTOR3 pos;	//�ʒu
	D3DXMATRIX mtxWorldSpeechBubble;//���[���h�}�g���b�N�X
	SPEECHBUBBLETYPE BubbleSType;//���
	int nBubbleCnt;//
	bool bOK;//�������̃^�C�~���O��OK�ɂȂ��Ă�΃f�N�������g�����Ȃ�
	bool bUse;
}SPEECHBUBBLE;




void InitSpeechBubble(void);
void UninitSpeechBubble(void);
void UpdateSpeechBubble(void);
void DrawSpeechBubble(void);

SPEECHBUBBLE* GetSpeechBubble(void);

//�ǂ̐ݒ�-------------------------------�A�N�V�����ԍ�---[SetType-0���o���A�P���k��]---UI�\���̕␳�l
void SetSpeechBubble(D3DXVECTOR3 Pos,int ActionIndex,int SetType, D3DXVECTOR3 CorrectionValue, SPEECHBUBBLETYPE UI_TYPE);


// �\�������_���v�Z����֐�
//D3DXVECTOR3 PredictIntersection(SPEECHBUBBLE bullet, Enemy enemy);


#endif // _SPEECHBUBBLE_H_
