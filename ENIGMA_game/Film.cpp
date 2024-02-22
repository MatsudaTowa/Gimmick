//==============================
//
// �t�B����������[Film.cpp]
// Author:Kaito Hondo
//
//==============================

#include "main.h"
#include "Film.h"

// �}�N����`
#define NUM_FILM	(3)// �w�i�̐�

// �O���[�o���ϐ�
LPDIRECT3DTEXTURE9 g_apTextureFILM[NUM_FILM] = {};	// �e�N�X�`���i�R�����j�ւ̃|�C���^
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffFILM = NULL;	// ���_�o�b�t�@�ւ̃|�C���^
float g_aPosTexV[NUM_FILM];						// �e�N�X�`�����W�̊J�n�ʒu�iV�l�j

// �w�i�̏���������
void InitFILM(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntFILM;

	// �f�o�C�X�̎擾
	pDevice = GetDevice();

	// �e�N�X�`���R�����̓ǂݍ���
	// �e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice, FILM_TEXTURE, &g_apTextureFILM[0]);
	// �e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice, FILM_TEXTURE2, &g_apTextureFILM[1]);
	// �e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice, FILM_TEXTURE3, &g_apTextureFILM[2]);

	// �e�N�X�`�����W�̊J�n�ʒu�iV�l�j�̏�����
	for (nCntFILM = 0; nCntFILM < NUM_FILM; nCntFILM++)
	{
		g_aPosTexV[nCntFILM] = 0.0f;
	}

	// ���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * NUM_FILM, D3DUSAGE_WRITEONLY, FVF_VERTEX_2D, D3DPOOL_MANAGED, &g_pVtxBuffFILM, NULL);

	VERTEX_2D* pVtx;

	// ���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���l��
	g_pVtxBuffFILM->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntFILM = 0; nCntFILM < NUM_FILM; nCntFILM++)
	{
		// ���_���W�̐ݒ�
		pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(SCREEN_WIDE, 0.0f, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(0.0f, SCREEN_HEIGHT, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(SCREEN_WIDE, SCREEN_HEIGHT, 0.0f);

		// rhw�̐ݒ�
		pVtx[0].rhw = 1.0f;
		pVtx[1].rhw = 1.0f;
		pVtx[2].rhw = 1.0f;
		pVtx[3].rhw = 1.0f;

		// ���_�J���[�̐ݒ�
		pVtx[0].col = D3DXCOLOR(255, 255, 255, 255);
		pVtx[1].col = D3DXCOLOR(255, 255, 255, 255);
		pVtx[2].col = D3DXCOLOR(255, 255, 255, 255);
		pVtx[3].col = D3DXCOLOR(255, 255, 255, 255);

		// �e�N�X�`�����W�̐ݒ�
		pVtx[0].tex = D3DXVECTOR2(0.0f, g_aPosTexV[nCntFILM]);
		pVtx[1].tex = D3DXVECTOR2(1.0f, g_aPosTexV[nCntFILM]);
		pVtx[2].tex = D3DXVECTOR2(0.0f, g_aPosTexV[nCntFILM] + 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, g_aPosTexV[nCntFILM] + 1.0f);

		pVtx += 4;// ���_�f�[�^�̃|�C���^���S���i�߂�
	}

	// ���_�o�b�t�@���A�����b�N����
	g_pVtxBuffFILM->Unlock();
}

// �w�i�̏I������
void UninitFILM(void)
{
	int nCount;

	// �e�N�X�`���̔j��
	for (nCount = 0; nCount < NUM_FILM; nCount++)
	{

		if (g_apTextureFILM[nCount] != NULL)
		{
			g_apTextureFILM[nCount]->Release();
			g_apTextureFILM[nCount] = NULL;
		}
	}
	// ���_�o�b�t�@�̔j��
	if (g_pVtxBuffFILM != NULL)
	{
		g_pVtxBuffFILM->Release();
		g_pVtxBuffFILM = NULL;
	}
}

// �w�i�̍X�V����
void UpdateFILM(void)
{
	int nCntFILM;
	VERTEX_2D* pVtx;

	// ���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	g_pVtxBuffFILM->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntFILM = 0; nCntFILM < NUM_FILM; nCntFILM++)
	{
		g_aPosTexV[nCntFILM] += -0.009f;

		pVtx[0].tex = D3DXVECTOR2(0.0f, g_aPosTexV[nCntFILM]);
		pVtx[1].tex = D3DXVECTOR2(1.0f, g_aPosTexV[nCntFILM]);
		pVtx[2].tex = D3DXVECTOR2(0.0f, g_aPosTexV[nCntFILM] + 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, g_aPosTexV[nCntFILM] + 1.0f);

		pVtx += 4;
	}

	// ���_�o�b�t�@���A�����b�N
	g_pVtxBuffFILM->Unlock();
}

// �w�i�̕`�揈��
void DrawFILM(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntFILM;

	// �f�o�C�X�̎擾
	pDevice = GetDevice();

	// ���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, g_pVtxBuffFILM, 0, sizeof(VERTEX_2D));
	// ���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	for (nCntFILM = 0; nCntFILM < NUM_FILM; nCntFILM++)
	{
		// �e�N�X�`���̐ݒ�
		pDevice->SetTexture(0, g_apTextureFILM[nCntFILM]);

		// �|���S���̕`��
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCntFILM * 4, 2);

	}
}