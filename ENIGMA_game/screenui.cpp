//============================================================================================
//
//�^�C�g���\�����鏈��[screenui.cpp]
// Author seiya kagaya
//
//============================================================================================
#include "screenui.h"


//#include "player.h"
#//include "input.h"
//#include "fade.h"
//#include "sound.h"




//�O���[�o���ϐ�
LPDIRECT3DTEXTURE9 g_pTextureScreenUI[NUM_UI] = {};//�e�N�X�`���ւ̃|�C���^
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffScreenUI = NULL;//���_�o�b�t�@�ւ̃|���S��
ScreenUI g_ScreenUI[NUM_UI];//�^�C�g���̏��
//D3DXCOLOR g_colorfade[NUM_UI];
SCREENUISTATE g_ScreenUIState;//�t�F�[�h���̎���

//=============================
//�^�C�g����ʂ̏���������
//=============================
void InitScreenUI(void)
{
	int nCntScreenUI = 0;

	g_ScreenUIState = SCREENUI_MAX;

	LPDIRECT3DDEVICE9 pDevice;	//�f�o�C�X�ւ̃|�C���^

	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	VERTEX_2D* pVtx;//���_���̃|�C���^

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\blood.jpg", &g_pTextureScreenUI[0]);	//�Ƃ�܌�
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\Watch.png", &g_pTextureScreenUI[1]);	//�Q�[���̖��O

			//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 12, D3DUSAGE_WRITEONLY, FVF_VERTEX_2D, D3DPOOL_MANAGED, &g_pVtxBuffScreenUI, NULL);

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	g_pVtxBuffScreenUI->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntScreenUI = 0; nCntScreenUI < NUM_UI; nCntScreenUI++)
	{
			//g_colorfade[nCntScreenUI].a = 0.0f;

		g_ScreenUI[nCntScreenUI].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		//rhw�̐ݒ�
		pVtx[0].rhw = 1.0f;//�l�͌Œ�
		pVtx[1].rhw = 1.0f;//�l�͌Œ�
		pVtx[2].rhw = 1.0f;//�l�͌Œ�
		pVtx[3].rhw = 1.0f;//�l�͌Œ�]

		//���_�J���[�̐ݒ�
		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		//���_���W�̍X�V-----------------------------------
		pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		//�e�N�X�`�����W��ݒ�
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);//����
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);//�E��
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);//����
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);//�E��

		pVtx += 4;
	}

	//���_�o�b�t�@���A�����b�N����
	g_pVtxBuffScreenUI->Unlock();

	//PlaySound(SOUND_LABEL_BGM000);
}
//=============================
//�^�C�g����ʂ̏I������
//=============================
void UninitScreenUI(void)
{
	//StopSound(SOUND_LABEL_BGM000);

	int nCntScreenUI = 0;

	for (nCntScreenUI = 0; nCntScreenUI < NUM_UI; nCntScreenUI++)
	{
		//�e�N�X�`���̔j��
		if (g_pTextureScreenUI[nCntScreenUI] != NULL)
		{
			g_pTextureScreenUI[nCntScreenUI]->Release();
			g_pTextureScreenUI[nCntScreenUI] = NULL;
		}
	}
	//���_�o�b�t�@�̔j��
	if (g_pVtxBuffScreenUI != NULL)
	{
		g_pVtxBuffScreenUI->Release();
		g_pVtxBuffScreenUI = NULL;
	}
}
//=============================
//�^�C�g����ʂ̍X�V����
//=============================
void UpdateScreenUI(void)
{
	int nCntScreenUI = 0;

	VERTEX_2D* pVtx;//���_���̃|�C���^

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	g_pVtxBuffScreenUI->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntScreenUI = 0; nCntScreenUI < NUM_UI; nCntScreenUI++)
	{
		if (nCntScreenUI == SCREENUI_1)
		{//
			g_ScreenUI[nCntScreenUI].pos = D3DXVECTOR3(SCREEN_WIDE / 2.0f, SCREEN_HEIGHT / 2.0f, 0.0f);

			//���_���W�̍X�V-----------------------------------
			pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(SCREEN_WIDE, 0.0f, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(0.0f, SCREEN_HEIGHT, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(SCREEN_WIDE, SCREEN_HEIGHT, 0.0f);

			//���_�J���[�̐ݒ�
			pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f);
			pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f);
			pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f);
			pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f);

		}
		else if (nCntScreenUI == SCREENUI_WATCH)
		{//���v�̂Ƃ�
			g_ScreenUI[nCntScreenUI].pos = D3DXVECTOR3((SCREEN_WIDE / 2.0f)-90.0f, SCREEN_HEIGHT -700.0f, 0.0f);

			//���_���W�̍X�V-----------------------------------
			pVtx[0].pos = D3DXVECTOR3(g_ScreenUI[nCntScreenUI].pos.x - 20.0f, g_ScreenUI[nCntScreenUI].pos.y - 20.0f, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_ScreenUI[nCntScreenUI].pos.x + 20.0f, g_ScreenUI[nCntScreenUI].pos.y - 20.0f, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(g_ScreenUI[nCntScreenUI].pos.x - 20.0f, g_ScreenUI[nCntScreenUI].pos.y + 20.0f, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_ScreenUI[nCntScreenUI].pos.x + 20.0f, g_ScreenUI[nCntScreenUI].pos.y + 20.0f, 0.0f);

			//���_�J���[�̐ݒ�
			pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
			pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
			pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
			pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		}


		//�e�N�X�`�����W��ݒ�
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);//����
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);//�E��
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);//����
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);//�E��

		pVtx += 4;
	}
	//���_�o�b�t�@���A�����b�N����
	g_pVtxBuffScreenUI->Unlock();
}
//=============================
//�^�C�g����ʂ̕`�揈��
//=============================
void DrawScreenUI(void)
{
	LPDIRECT3DDEVICE9 pDevice;	//�f�o�C�X�ւ̃|�C���^

	//�f�o�C�X�̎擾
	pDevice = GetDevice();//----------------���������ς�

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, g_pVtxBuffScreenUI, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);//-------���������ς�

	int nCntScreenUI = 0;

	for (nCntScreenUI = 0; nCntScreenUI < NUM_UI; nCntScreenUI++)
	{
		//�e�N�X�`���̐ݒ�
		pDevice->SetTexture(0, g_pTextureScreenUI[nCntScreenUI]);//---------���������ς�

		//�|���S���̕`��
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,//�v���~�e�B�u�̎��//----------���������ς�
			nCntScreenUI * 4,//�`�悷��ŏ��̒��_�C���f�b�N�X
			2);//�`�悷��v���~�e�B�u��
	}
}
