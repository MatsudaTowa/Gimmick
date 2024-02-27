//============================================================================================
//
//�}�b�vUI�\�����鏈��[result.cpp]
// Author seiya kagaya
//
//============================================================================================
//#include "item.h"
#include "map.h"
#include "game.h"
#include "particle.h"
#include "input.h"
#include "player.h"
#include "camera.h"
#include "player2.h"
#include "text.h"


//�O���[�o���ϐ�
LPDIRECT3DTEXTURE9 g_pTextureMap[MAPTEXUINUM] = {};//�e�N�X�`���ւ̃|�C���^
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffMap = NULL;//���_�o�b�t�@�ւ̃|���S��

MAP g_Map[MAXMAP];

//�`��\��(�A�b�v�f�[�g�ŕϓ��E�`��Ŏg�p)
bool g_DrawOK2[2] = {};//�O�Ԗڂ������ture

D3DXVECTOR2 g_UVpos[2];//�s���̂݁@

//=============================
//�}�b�vUI�̏���������
//=============================
void InitMap(void)
{
	g_DrawOK2[0] = false;
	g_DrawOK2[1] = false;

	g_UVpos[0] = D3DXVECTOR2(0.5f, 0.5f);//UV��̈ʒu
	g_UVpos[1] = D3DXVECTOR2(0.5f, 0.5f);//UV��̈ʒu

	LPDIRECT3DDEVICE9 pDevice;	//�f�o�C�X�ւ̃|�C���^

	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	int nCntMap;

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\PlayerPin.png", &g_pTextureMap[0]);//�v���C���[�s��
	
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\TestMap.png", &g_pTextureMap[1]);//�n�}
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\TestMap.png", &g_pTextureMap[2]);//�n�}



	//�}�b�vUI�̏��̏�����(�����鏉���n�_)
	for (nCntMap = 0; nCntMap < MAXMAP; nCntMap++)
	{
		g_Map[nCntMap].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_Map[nCntMap].UItype = MAP_UI_TYPE_MAX;
		g_Map[nCntMap].ScreenNum = -1;
		g_Map[nCntMap].PosNum = -1;
		g_Map[nCntMap].bUse = false;//�g�p���Ă��Ȃ���Ԃɂ���
	}

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * MAXMAP, D3DUSAGE_WRITEONLY, FVF_VERTEX_2D, D3DPOOL_MANAGED, &g_pVtxBuffMap, NULL);

	VERTEX_2D* pVtx;//���_���̃|�C���^

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	g_pVtxBuffMap->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntMap = 0; nCntMap < MAXMAP; nCntMap++)
	{
		//���_���W�̍X�V-----------------------------------
		pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		//rhw�̐ݒ�
		pVtx[0].rhw = 1.0f;//�l�͌Œ�
		pVtx[1].rhw = 1.0f;//�l�͌Œ�
		pVtx[2].rhw = 1.0f;//�l�͌Œ�
		pVtx[3].rhw = 1.0f;//�l�͌Œ�

		//���_�J���[�̐ݒ�
		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		//�e�N�X�`�����W��ݒ�
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);//����
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);//�E��
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);//����
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);//�E��

		pVtx += 4;//���_�̃|�C���^��4���i�߂�
	}
	//���_�o�b�t�@���A�����b�N����
	g_pVtxBuffMap->Unlock();

	//
	//�n�}
	SetMap(D3DXVECTOR3(SCREEN_WIDE * 0.38f, SCREEN_HEIGHT * 0.8f, 0.0f), MAP_UI_TYPE_MAP1, 0);
	//�n�}
	SetMap(D3DXVECTOR3(SCREEN_WIDE * 0.88f, SCREEN_HEIGHT * 0.8f, 0.0f), MAP_UI_TYPE_MAP1, 1);

	//��
	SetMap(D3DXVECTOR3(SCREEN_WIDE * 0.88f, SCREEN_HEIGHT * 0.8f, 0.0f), MAP_UI_TYPE_PLAYERPIN_2P_0, 0);
	SetMap(D3DXVECTOR3(SCREEN_WIDE * 0.38f, SCREEN_HEIGHT * 0.8f, 0.0f), MAP_UI_TYPE_PLAYERPIN_1P_0, 0);

	//�E
	SetMap(D3DXVECTOR3(SCREEN_WIDE * 0.38f, SCREEN_HEIGHT * 0.8f, 0.0f), MAP_UI_TYPE_PLAYERPIN_1P_1, 1);
	SetMap(D3DXVECTOR3(SCREEN_WIDE * 0.88f, SCREEN_HEIGHT * 0.8f, 0.0f), MAP_UI_TYPE_PLAYERPIN_2P_1, 1);





//	SetMap(D3DXVECTOR3(MAPSIZE + 10.0f, 460.0f, 0), MAP_UI_TYPE_POINTER, ITEMTYPE_MAX, -1, 1);//�|�C���^�[�����ʒu

//	SetMap(D3DXVECTOR3(MAPSIZE + 640.0f, 460.0f, 0), MAP_UI_TYPE_POINTER, ITEMTYPE_MAX, -1, 2);//�|�C���^�[�����ʒu

	//	//�\���ꏊ�̐ݒ�
	//for (int SetCnt = 0; SetCnt < MAXGETITEM; SetCnt++)
	//{
	//	SetMap(D3DXVECTOR3(MAPSIZE + 10.0f + (MAPSIZE * 2.1f * SetCnt), 460.0f, 0), ITEM_UI_TYPE_FRAME, ITEMTYPE_MAX, -1, 1);//�g
	//}
	////�\���ꏊ�̐ݒ�
	//for (int SetCnt2 = 0; SetCnt2 < MAXGETITEM; SetCnt2++)
	//{
	//	SetMap(D3DXVECTOR3(MAPSIZE + 640.0f + (MAPSIZE * 2.1f * SetCnt2), 460.0f, 0), ITEM_UI_TYPE_FRAME, ITEMTYPE_MAX, -1, 2);//�g
	//}


	//SetMap(D3DXVECTOR3(SCREEN_WIDE - 100.0f, 35.0f, 0), ITEM_UI_TYPE_KEYUI, ITEMTYPE_MAX, -1, 2);//��

}
//=============================
//�}�b�vUI�̏I������
//=============================
void UninitMap(void)
{
	for (int i = 0; i < MAPTEXUINUM; i++)
	{
		//�e�N�X�`���̔j��
		if (g_pTextureMap[i] != NULL)
		{
			g_pTextureMap[i]->Release();
			g_pTextureMap[i] = NULL;
		}
	}
	//���_�o�b�t�@�̔j��
	if (g_pVtxBuffMap != NULL)
	{
		g_pVtxBuffMap->Release();
		g_pVtxBuffMap = NULL;
	}
}
//=============================
//�}�b�vUI�̍X�V����
//=============================
void UpdateMap(bool Draw1OK, bool Draw2OK)
{
	Player* pPlayer;
	pPlayer = GetPlayer();

	Player_2P* pPlayer2;
	pPlayer2 = GetPlayer_2P();

	VERTEX_2D* pVtx;//���_���̃|�C���^

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	g_pVtxBuffMap->Lock(0, 0, (void**)&pVtx, 0);

	g_DrawOK2[0] = Draw1OK;
	g_DrawOK2[1] = Draw2OK;



	for (int nCntMap = 0; nCntMap < MAXMAP; nCntMap++)
	{
		if (g_Map[nCntMap].bUse == true)
		{//�}�b�vUI���g�p����Ă���

	D3DXVECTOR2 EscapeUV;

			switch (g_Map[nCntMap].UItype)
			{
			case MAP_UI_TYPE_PLAYERPIN_1P_0:

				EscapeUV.x = -pPlayer->pos.x * 0.005f;
				EscapeUV.y = pPlayer->pos.z * 0.005f;

				g_UVpos[0] = EscapeUV;//UV��̈ʒu
				
				//�e�N�X�`�����W��ݒ�
				pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);//����
				pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);//�E��
				pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);//����
				pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);//�E��

				break;

			case MAP_UI_TYPE_PLAYERPIN_2P_1:

				EscapeUV.x =-pPlayer2->pos.x * 0.005f;
				EscapeUV.y = pPlayer2->pos.z * 0.005f;

				g_UVpos [1]= EscapeUV;//UV��̈ʒu

				//�e�N�X�`�����W��ݒ�
				pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);//����
				pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);//�E��
				pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);//����
				pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);//�E��

				break;


	
			case MAP_UI_TYPE_PLAYERPIN_2P_0://����
				
				

				//�e�N�X�`�����W��ݒ�
				pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);//����
				pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);//�E��
				pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);//����
				pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);//�E��

				break;

			case MAP_UI_TYPE_PLAYERPIN_1P_1://����

				//�e�N�X�`�����W��ݒ�
				pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);//����
				pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);//�E��
				pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);//����
				pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);//�E��
				
				break;

			case MAP_UI_TYPE_MAP1:
				
				g_UVpos[0] += MAP0_START_POS_0;

				//�e�N�X�`�����W��ݒ�
				pVtx[0].tex = D3DXVECTOR2(g_UVpos[g_Map[nCntMap].ScreenNum].x - UVSize,g_UVpos[g_Map[nCntMap].ScreenNum].y - UVSize);//����
				pVtx[1].tex = D3DXVECTOR2(g_UVpos[g_Map[nCntMap].ScreenNum].x + UVSize,g_UVpos[g_Map[nCntMap].ScreenNum].y - UVSize);//�E��
				pVtx[2].tex = D3DXVECTOR2(g_UVpos[g_Map[nCntMap].ScreenNum].x - UVSize,g_UVpos[g_Map[nCntMap].ScreenNum].y + UVSize);//����
				pVtx[3].tex = D3DXVECTOR2(g_UVpos[g_Map[nCntMap].ScreenNum].x + UVSize,g_UVpos[g_Map[nCntMap].ScreenNum].y + UVSize);//�E��
				
				break;

			case MAP_UI_TYPE_MAP2:
				
				g_UVpos[0] += MAP1_START_POS_0;

				//�e�N�X�`�����W��ݒ�
				pVtx[0].tex = D3DXVECTOR2(g_UVpos[g_Map[nCntMap].ScreenNum].x - UVSize, g_UVpos[g_Map[nCntMap].ScreenNum].y - UVSize);//����
				pVtx[1].tex = D3DXVECTOR2(g_UVpos[g_Map[nCntMap].ScreenNum].x + UVSize, g_UVpos[g_Map[nCntMap].ScreenNum].y - UVSize);//�E��
				pVtx[2].tex = D3DXVECTOR2(g_UVpos[g_Map[nCntMap].ScreenNum].x - UVSize, g_UVpos[g_Map[nCntMap].ScreenNum].y + UVSize);//����
				pVtx[3].tex = D3DXVECTOR2(g_UVpos[g_Map[nCntMap].ScreenNum].x + UVSize, g_UVpos[g_Map[nCntMap].ScreenNum].y + UVSize);//�E��
			
				break;
			}





			////���_���W�̍X�V-----------------------------------
			//pVtx[0].pos = D3DXVECTOR3(g_Map[nCntMap].pos.x - MAPSIZE, g_Map[nCntMap].pos.y - MAPSIZE, 0.0f);
			//pVtx[1].pos = D3DXVECTOR3(g_Map[nCntMap].pos.x + MAPSIZE, g_Map[nCntMap].pos.y - MAPSIZE, 0.0f);
			//pVtx[2].pos = D3DXVECTOR3(g_Map[nCntMap].pos.x - MAPSIZE, g_Map[nCntMap].pos.y + MAPSIZE, 0.0f);
			//pVtx[3].pos = D3DXVECTOR3(g_Map[nCntMap].pos.x + MAPSIZE, g_Map[nCntMap].pos.y + MAPSIZE, 0.0f);

		}
		pVtx += 4;//���_�̃|�C���^��4���i�߂�
	}
	//���_�o�b�t�@���A�����b�N����
	g_pVtxBuffMap->Unlock();
}
//=============================
//�}�b�vUI�̕`�揈��
//=============================
void DrawMap(void)
{
	LPDIRECT3DDEVICE9 pDevice;	//�f�o�C�X�ւ̃|�C���^

	int nCntMap = 0;
	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, g_pVtxBuffMap, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);//-------���������ς�
	for (nCntMap = 0; nCntMap < MAXMAP; nCntMap++)
	{
		if (g_Map[nCntMap].bUse == true)
		{//�}�b�vUI���g�p����Ă���

			int SelectTex = 0;

			switch (g_Map[nCntMap].UItype)
			{
			case MAP_UI_TYPE_PLAYERPIN_1P_0:
				SelectTex = 0;
				break;

			case MAP_UI_TYPE_PLAYERPIN_2P_0:
				SelectTex = 0;
				break;


			case MAP_UI_TYPE_PLAYERPIN_1P_1:
				SelectTex = 0;
				break;

			case MAP_UI_TYPE_PLAYERPIN_2P_1:
				SelectTex = 0;
				break;

			case MAP_UI_TYPE_MAP1:
				SelectTex = 1;
				break;

			case MAP_UI_TYPE_MAP2:
				SelectTex = 2;
				break;
			}
			//�e�N�X�`���̐ݒ�
			pDevice->SetTexture(0, g_pTextureMap[SelectTex]);//---------���������ς�


			if (g_DrawOK2[g_Map[nCntMap].ScreenNum] == true)
			{
				//�|���S���̕`��
				pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,//�v���~�e�B�u�̎��
					nCntMap * 4,//�`�悷��ŏ��̒��_�C���f�b�N�X
					2);//�`�悷��v���~�e�B�u��

				
				//�e�N�X�`����߂�
				pDevice->SetTexture(0, NULL);
			}

		

			//�|���S���̕`��
		//	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,//�v���~�e�B�u�̎��
		//		nCntMap * 4,//�`�悷��ŏ��̒��_�C���f�b�N�X
		//		2);//�`�悷��v���~�e�B�u��
		}
	}


	//DrawTextSet(D3DXVECTOR3(110.0f, 460.0f, 0.0f), 25, FONT_AKABARASINDELERA, D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f), "1������%d�|�C���^�ʒu%d", g_ItemNum, g_PointNum[0]);

//	DrawTextSet(D3DXVECTOR3(110.0f, 560.0f, 0.0f), 25, FONT_AKABARASINDELERA, D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f), "2������%d�|�C���^�ʒu%d", g_ItemNum2, g_PointNum[1]);
}
//=============================
//�}�b�vUI�̐ݒ菈��
//=============================
void SetMap(D3DXVECTOR3 pos, MAP_UI_TYPE MAPType,int ScreenNum)
{//���̂Ƃ���ł��Ăԉ\��������̂ł��̂܂܂̂ق����֗�

	VERTEX_2D* pVtx;//���_���̃|�C���^
	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	g_pVtxBuffMap->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCntMap = 0; nCntMap < MAXMAP; nCntMap++)
	{
		if (g_Map[nCntMap].bUse == false)
		{//�}�b�vUI���g�p����Ă��Ȃ�

			g_Map[nCntMap].bUse = true;//�g�p���Ă�ɂ���

			g_Map[nCntMap].pos = pos;
			g_Map[nCntMap].UItype = MAPType;

			g_Map[nCntMap].ScreenNum = ScreenNum;


				switch (MAPType)
				{
				case MAP_UI_TYPE_PLAYERPIN_1P_0:

					//���_���W�̍X�V-----------------------------------
					pVtx[0].pos = D3DXVECTOR3(g_Map[nCntMap].pos.x - MAPSIZE2, g_Map[nCntMap].pos.y - MAPSIZE2, 0.0f);
					pVtx[1].pos = D3DXVECTOR3(g_Map[nCntMap].pos.x + MAPSIZE2, g_Map[nCntMap].pos.y - MAPSIZE2, 0.0f);
					pVtx[2].pos = D3DXVECTOR3(g_Map[nCntMap].pos.x - MAPSIZE2, g_Map[nCntMap].pos.y + MAPSIZE2, 0.0f);
					pVtx[3].pos = D3DXVECTOR3(g_Map[nCntMap].pos.x + MAPSIZE2, g_Map[nCntMap].pos.y + MAPSIZE2, 0.0f);

					//���_�J���[�̐ݒ�
					pVtx[0].col = D3DCOLOR_RGBA(255, 0, 0, 100);
					pVtx[1].col = D3DCOLOR_RGBA(255, 0, 0, 100);
					pVtx[2].col = D3DCOLOR_RGBA(255, 0, 0, 100);
					pVtx[3].col = D3DCOLOR_RGBA(255, 0, 0, 100);

					//�e�N�X�`�����W��ݒ�
					pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);//����
					pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);//�E��
					pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);//����
					pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);//�E��

					break;

				case MAP_UI_TYPE_PLAYERPIN_2P_0:
					
					//���_���W�̍X�V-----------------------------------
					pVtx[0].pos = D3DXVECTOR3(g_Map[nCntMap].pos.x - MAPSIZE2, g_Map[nCntMap].pos.y - MAPSIZE2, 0.0f);
					pVtx[1].pos = D3DXVECTOR3(g_Map[nCntMap].pos.x + MAPSIZE2, g_Map[nCntMap].pos.y - MAPSIZE2, 0.0f);
					pVtx[2].pos = D3DXVECTOR3(g_Map[nCntMap].pos.x - MAPSIZE2, g_Map[nCntMap].pos.y + MAPSIZE2, 0.0f);
					pVtx[3].pos = D3DXVECTOR3(g_Map[nCntMap].pos.x + MAPSIZE2, g_Map[nCntMap].pos.y + MAPSIZE2, 0.0f);

					//���_�J���[�̐ݒ�
					pVtx[0].col = D3DCOLOR_RGBA(0, 0, 255, 100);
					pVtx[1].col = D3DCOLOR_RGBA(0, 0, 255, 100);
					pVtx[2].col = D3DCOLOR_RGBA(0, 0, 255, 100);
					pVtx[3].col = D3DCOLOR_RGBA(0, 0, 255, 100);

					//�e�N�X�`�����W��ݒ�
					pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);//����
					pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);//�E��
					pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);//����
					pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);//�E��

					break;


				case MAP_UI_TYPE_PLAYERPIN_1P_1:

					//���_���W�̍X�V-----------------------------------
					pVtx[0].pos = D3DXVECTOR3(g_Map[nCntMap].pos.x - MAPSIZE2, g_Map[nCntMap].pos.y - MAPSIZE2, 0.0f);
					pVtx[1].pos = D3DXVECTOR3(g_Map[nCntMap].pos.x + MAPSIZE2, g_Map[nCntMap].pos.y - MAPSIZE2, 0.0f);
					pVtx[2].pos = D3DXVECTOR3(g_Map[nCntMap].pos.x - MAPSIZE2, g_Map[nCntMap].pos.y + MAPSIZE2, 0.0f);
					pVtx[3].pos = D3DXVECTOR3(g_Map[nCntMap].pos.x + MAPSIZE2, g_Map[nCntMap].pos.y + MAPSIZE2, 0.0f);

					//���_�J���[�̐ݒ�
					pVtx[0].col = D3DCOLOR_RGBA(255, 0, 0, 100);
					pVtx[1].col = D3DCOLOR_RGBA(255, 0, 0, 100);
					pVtx[2].col = D3DCOLOR_RGBA(255, 0, 0, 100);
					pVtx[3].col = D3DCOLOR_RGBA(255, 0, 0, 100);

					//�e�N�X�`�����W��ݒ�
					pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);//����
					pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);//�E��
					pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);//����
					pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);//�E��

					break;

				case MAP_UI_TYPE_PLAYERPIN_2P_1:

					//���_���W�̍X�V-----------------------------------
					pVtx[0].pos = D3DXVECTOR3(g_Map[nCntMap].pos.x - MAPSIZE2, g_Map[nCntMap].pos.y - MAPSIZE2, 0.0f);
					pVtx[1].pos = D3DXVECTOR3(g_Map[nCntMap].pos.x + MAPSIZE2, g_Map[nCntMap].pos.y - MAPSIZE2, 0.0f);
					pVtx[2].pos = D3DXVECTOR3(g_Map[nCntMap].pos.x - MAPSIZE2, g_Map[nCntMap].pos.y + MAPSIZE2, 0.0f);
					pVtx[3].pos = D3DXVECTOR3(g_Map[nCntMap].pos.x + MAPSIZE2, g_Map[nCntMap].pos.y + MAPSIZE2, 0.0f);

					//���_�J���[�̐ݒ�
					pVtx[0].col = D3DCOLOR_RGBA(0, 0, 255, 100);
					pVtx[1].col = D3DCOLOR_RGBA(0, 0, 255, 100);
					pVtx[2].col = D3DCOLOR_RGBA(0, 0, 255, 100);
					pVtx[3].col = D3DCOLOR_RGBA(0, 0, 255, 100);

					//�e�N�X�`�����W��ݒ�
					pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);//����
					pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);//�E��
					pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);//����
					pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);//�E��

					break;

				case MAP_UI_TYPE_MAP1:
					//���_���W�̍X�V-----------------------------------
					pVtx[0].pos = D3DXVECTOR3(g_Map[nCntMap].pos.x - ((SCREEN_WIDE*0.5f)* ADDMAP), g_Map[nCntMap].pos.y - ((SCREEN_WIDE * 0.5f) * ADDMAP), 0.0f);
					pVtx[1].pos = D3DXVECTOR3(g_Map[nCntMap].pos.x + ((SCREEN_WIDE * 0.5f) * ADDMAP), g_Map[nCntMap].pos.y - ((SCREEN_WIDE * 0.5f) * ADDMAP), 0.0f);
					pVtx[2].pos = D3DXVECTOR3(g_Map[nCntMap].pos.x - ((SCREEN_WIDE * 0.5f) * ADDMAP), g_Map[nCntMap].pos.y + ((SCREEN_WIDE * 0.5f) * ADDMAP), 0.0f);
					pVtx[3].pos = D3DXVECTOR3(g_Map[nCntMap].pos.x + ((SCREEN_WIDE * 0.5f) * ADDMAP), g_Map[nCntMap].pos.y + ((SCREEN_WIDE * 0.5f) * ADDMAP), 0.0f);

					//���_�J���[�̐ݒ�
					pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 200);
					pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 200);
					pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 200);
					pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 200);

					//�e�N�X�`�����W��ݒ�
					pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);//����
					pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);//�E��
					pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);//����
					pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);//�E��


						//�e�N�X�`�����W��ݒ�
					pVtx[0].tex = D3DXVECTOR2(g_UVpos[0].x - UVSize, g_UVpos[0].y - UVSize);//����
					pVtx[1].tex = D3DXVECTOR2(g_UVpos[0].x + UVSize, g_UVpos[0].y - UVSize);//�E��
					pVtx[2].tex = D3DXVECTOR2(g_UVpos[0].x - UVSize, g_UVpos[0].y + UVSize);//����
					pVtx[3].tex = D3DXVECTOR2(g_UVpos[0].x + UVSize, g_UVpos[0].y + UVSize);//�E��

					break;

				case MAP_UI_TYPE_MAP2:

					//���_���W�̍X�V-----------------------------------
					pVtx[0].pos = D3DXVECTOR3(g_Map[nCntMap].pos.x - ((SCREEN_WIDE * 0.5f) * ADDMAP), g_Map[nCntMap].pos.y - ((SCREEN_WIDE * 0.5f) * ADDMAP), 0.0f);
					pVtx[1].pos = D3DXVECTOR3(g_Map[nCntMap].pos.x + ((SCREEN_WIDE * 0.5f) * ADDMAP), g_Map[nCntMap].pos.y - ((SCREEN_WIDE * 0.5f) * ADDMAP), 0.0f);
					pVtx[2].pos = D3DXVECTOR3(g_Map[nCntMap].pos.x - ((SCREEN_WIDE * 0.5f) * ADDMAP), g_Map[nCntMap].pos.y + ((SCREEN_WIDE * 0.5f) * ADDMAP), 0.0f);
					pVtx[3].pos = D3DXVECTOR3(g_Map[nCntMap].pos.x + ((SCREEN_WIDE * 0.5f) * ADDMAP), g_Map[nCntMap].pos.y + ((SCREEN_WIDE * 0.5f) * ADDMAP), 0.0f);

					//���_�J���[�̐ݒ�
					pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 200);
					pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 200);
					pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 200);
					pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 200);

					//�e�N�X�`�����W��ݒ�
					pVtx[0].tex = D3DXVECTOR2(g_UVpos[g_Map[nCntMap].ScreenNum].x - UVSize, g_UVpos[g_Map[nCntMap].ScreenNum].y - UVSize);//����
					pVtx[1].tex = D3DXVECTOR2(g_UVpos[g_Map[nCntMap].ScreenNum].x + UVSize, g_UVpos[g_Map[nCntMap].ScreenNum].y - UVSize);//�E��
					pVtx[2].tex = D3DXVECTOR2(g_UVpos[g_Map[nCntMap].ScreenNum].x - UVSize, g_UVpos[g_Map[nCntMap].ScreenNum].y + UVSize);//����
					pVtx[3].tex = D3DXVECTOR2(g_UVpos[g_Map[nCntMap].ScreenNum].x + UVSize, g_UVpos[g_Map[nCntMap].ScreenNum].y + UVSize);//�E��
					
					break;
				}

				


		
			break;
		}
		pVtx += 4;//�|�C���^���S�i�߂�
	}
	//���_�o�b�t�@���A�����b�N����
	g_pVtxBuffMap->Unlock();
}
