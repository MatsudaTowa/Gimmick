//============================================================================================
//
//�A�C�e��UI�\�����鏈��[result.cpp]
// Author seiya kagaya
//
//============================================================================================
#include "item.h"
#include "itemUI.h"
#include "game.h"


//�O���[�o���ϐ�
LPDIRECT3DTEXTURE9 g_pTextureItem_UI[2] = {};//�e�N�X�`���ւ̃|�C���^
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffItem_UI = NULL;//���_�o�b�t�@�ւ̃|���S��


ITEM_UI g_ItemUI[MAXITEMUI];


//=============================
//�A�C�e��UI�̏���������
//=============================
void InitItem_UI(void)
{
	

	LPDIRECT3DDEVICE9 pDevice;	//�f�o�C�X�ւ̃|�C���^

	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	int nCntItem_UI;

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\frame.png", &g_pTextureItem_UI[0]);//--------���������ς�
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\frameselect.png", &g_pTextureItem_UI[1]);//--------���������ς�


	
	//�A�C�e��UI�̏��̏�����(�����鏉���n�_)
	for (nCntItem_UI = 0; nCntItem_UI < MAXITEMUI; nCntItem_UI++)
	{
		g_ItemUI[nCntItem_UI].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_ItemUI[nCntItem_UI].bUse = false;//�g�p���Ă��Ȃ���Ԃɂ���
	}

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * MAXITEMUI, D3DUSAGE_WRITEONLY, FVF_VERTEX_2D, D3DPOOL_MANAGED, &g_pVtxBuffItem_UI, NULL);

	VERTEX_2D* pVtx;//���_���̃|�C���^

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	g_pVtxBuffItem_UI->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntItem_UI = 0; nCntItem_UI < MAXITEMUI; nCntItem_UI++)
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
		pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[2].col = D3DCOLOR_RGBA(255, 255, 225, 255);
		pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

		//�e�N�X�`�����W��ݒ�
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);//����
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);//�E��
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);//����
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);//�E��

		pVtx += 4;//���_�̃|�C���^��4���i�߂�
	}
	//���_�o�b�t�@���A�����b�N����
	g_pVtxBuffItem_UI->Unlock();

	//�\���ꏊ�̐ݒ�
	for (int SetCnt = 0; SetCnt <= ITEMTYPE_MAX; SetCnt++)
	{
		SetItem_UI(D3DXVECTOR3(ITEMUISIZE + 10.0f + (ITEMUISIZE*2.1f * SetCnt), 460.0f, 0),ITEM_UI_TYPE_FRAME);
	}

	SetItem_UI(D3DXVECTOR3(ITEMUISIZE + 10.0f, 460.0f, 0), ITEM_UI_TYPE_POINTER);





}
//=============================
//�A�C�e��UI�̏I������
//=============================
void UninitItem_UI(void)
{
	for (int i = 0; i < 2; i++)
	{


		//�e�N�X�`���̔j��
		if (g_pTextureItem_UI[i] != NULL)
		{
			g_pTextureItem_UI[i]->Release();
			g_pTextureItem_UI[i] = NULL;
		}
	}
	//���_�o�b�t�@�̔j��
	if (g_pVtxBuffItem_UI != NULL)
	{
		g_pVtxBuffItem_UI->Release();
		g_pVtxBuffItem_UI = NULL;
	}
}
//=============================
//�A�C�e��UI�̍X�V����
//=============================
void UpdateItem_UI(void)
{
	//VERTEX_2D* pVtx;//���_���̃|�C���^

	////���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	//g_pVtxBuffItem_UI->Lock(0, 0, (void**)&pVtx, 0);

	//for (int nCntItem_UI = 0; nCntItem_UI < ITEMTYPE_MAX; nCntItem_UI++)
	//{
	//
	//	pVtx += 4;//���_�̃|�C���^��4���i�߂�
	//}
	////���_�o�b�t�@���A�����b�N����
	//g_pVtxBuffItem_UI->Unlock();
}
//=============================
//�A�C�e��UI�̕`�揈��
//=============================
void DrawItem_UI(void)
{
	LPDIRECT3DDEVICE9 pDevice;	//�f�o�C�X�ւ̃|�C���^

	int nCntItem_UI = 0;
	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, g_pVtxBuffItem_UI, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);//-------���������ς�
	for (nCntItem_UI = 0; nCntItem_UI < MAXITEMUI; nCntItem_UI++)
	{
		if (g_ItemUI[nCntItem_UI].bUse == true)
		{//�A�C�e��UI���g�p����Ă���
			
			//�񋓂�int��
			int EscapeNum = static_cast<int>(g_ItemUI[nCntItem_UI].UItype);

			//�e�N�X�`���̐ݒ�
			pDevice->SetTexture(0, g_pTextureItem_UI[EscapeNum]);//---------���������ς�


					//�|���S���̕`��
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,//�v���~�e�B�u�̎��
				nCntItem_UI * 4,//�`�悷��ŏ��̒��_�C���f�b�N�X
				2);//�`�悷��v���~�e�B�u��
		}
	}
}
//=============================
//�A�C�e��UI�̐ݒ菈��
//=============================
void SetItem_UI(D3DXVECTOR3 pos, ITEM_UI_TYPE ItemUIType)
{//���̂Ƃ���ł��Ăԉ\��������̂ł��̂܂܂̂ق����֗�

	VERTEX_2D* pVtx;//���_���̃|�C���^
	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	g_pVtxBuffItem_UI->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCntItem_UI = 0; nCntItem_UI < MAXITEMUI; nCntItem_UI++)
	{
		if (g_ItemUI[nCntItem_UI].bUse == false)
		{//�A�C�e��UI���g�p����Ă��Ȃ�

			g_ItemUI[nCntItem_UI].bUse = true;//�g�p���Ă�ɂ���

			g_ItemUI[nCntItem_UI].pos = pos;
			g_ItemUI[nCntItem_UI].UItype = ItemUIType;


			//���_���W�̍X�V-----------------------------------
			pVtx[0].pos = D3DXVECTOR3(g_ItemUI[nCntItem_UI].pos.x - ITEMUISIZE, g_ItemUI[nCntItem_UI].pos.y - ITEMUISIZE, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_ItemUI[nCntItem_UI].pos.x + ITEMUISIZE, g_ItemUI[nCntItem_UI].pos.y - ITEMUISIZE, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(g_ItemUI[nCntItem_UI].pos.x - ITEMUISIZE, g_ItemUI[nCntItem_UI].pos.y + ITEMUISIZE, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_ItemUI[nCntItem_UI].pos.x + ITEMUISIZE, g_ItemUI[nCntItem_UI].pos.y + ITEMUISIZE, 0.0f);



			//���_�J���[�̐ݒ�
			pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 200);
			pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 200);
			pVtx[2].col = D3DCOLOR_RGBA(255, 255, 225, 200);
			pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 200);

			break;
		}
		pVtx += 4;//�|�C���^���S�i�߂�
	}
	//���_�o�b�t�@���A�����b�N����
	g_pVtxBuffItem_UI->Unlock();
}
