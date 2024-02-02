//=========================================================
//
//�e���ˏ����֌W�Ŏg���ϐ��A�錾�A�\����[item.h]
// Author seiya kagaya
//
//=========================================================
#ifndef _ITEMUI_H_

#define _ITEMUI_H_//��d�C���N���[�h�h�~

#include"main.h"

#include "game.h"


#include "item.h"

#define MAXITEMUI	(32)

#define ITEMUISIZE	(30.0f)

typedef enum
{
	ITEM_UI_TYPE_FRAME = 0,//�g
	ITEM_UI_TYPE_POINTER, //�|�C���^�[
	ITEM_UI_TYPE_MAINBODY,//�{��

}ITEM_UI_TYPE;



//�̍\����
typedef struct
{
	D3DXVECTOR3 pos;	//�ʒu
	ITEM_UI_TYPE UItype;//UI�̃^�C�v
	bool bUse;

}ITEM_UI;









void InitItem_UI(void);
void UninitItem_UI(void);
void UpdateItem_UI(void);
void DrawItem_UI(void);



void SetItem_UI(D3DXVECTOR3 pos, ITEM_UI_TYPE ItemUIType);




#endif // _ITEM_H_
