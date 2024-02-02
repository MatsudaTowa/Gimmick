//=============================================
//
//�����C�̃M�~�b�N[bathgimmick.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "bathgimmick.h"
#include "steam.h"
#include "model.h"

//=============================================
//�O���[�o���ϐ�
//=============================================
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffBathGimmick = NULL;
LPDIRECT3DTEXTURE9 g_pTextureBathGimmick = NULL; //�e�N�X�`���|�C���^
//D3DXVECTOR3 g_movefield; //�ړ���
D3DXMATRIX	g_mtxWorldBathGimmick;
BathWater g_BathWater;

//=============================================
//������
//=============================================
void InitBathGimmick(void)
{
	LPDIRECT3DDEVICE9 pDevice;

	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\bathwater.jpg",
		&g_pTextureBathGimmick
	);

	//�����̏����ݒ�
	g_BathWater.pos = D3DXVECTOR3(0.0f, 30.0f, 0.0f);
	g_BathWater.rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	g_BathWater.nSteamSpawnCnt = 0;
	g_BathWater.fWide = BATHWATER_WIDE;
	g_BathWater.fDepth = BATHWATER_DEPTH;
	g_BathWater.bUse = false;

	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4, D3DUSAGE_WRITEONLY, FVF_VERTEX_3D, D3DPOOL_MANAGED, &g_pVtxBuffBathGimmick, NULL);

	VERTEX_3D* pVtx;

	//���_�o�b�t�@�����b�N�����_���ւ̃|�C���^���擾
	g_pVtxBuffBathGimmick->Lock(0, 0, (void**)&pVtx, 0);

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(g_BathWater.pos.x - g_BathWater.fWide, 0.0f, g_BathWater.pos.z + g_BathWater.fDepth);
	pVtx[1].pos = D3DXVECTOR3(g_BathWater.pos.x + g_BathWater.fWide, 0.0f, g_BathWater.pos.z + g_BathWater.fDepth);
	pVtx[2].pos = D3DXVECTOR3(g_BathWater.pos.x - g_BathWater.fWide, 0.0f, g_BathWater.pos.z - g_BathWater.fDepth);
	pVtx[3].pos = D3DXVECTOR3(g_BathWater.pos.x + g_BathWater.fWide, 0.0f, g_BathWater.pos.z - g_BathWater.fDepth);

	//�@���x�N�g���̐ݒ�
	pVtx[0].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[1].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[2].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[3].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

	//���_�J���[�̐ݒ�
	pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

	//�e�N�X�`���̍��W�w��
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	g_pVtxBuffBathGimmick->Unlock();
}

//=============================================
//�I��
//=============================================
void UninitBathGimmick(void)
{
	//�e�N�X�`���̔j��
	if (g_pTextureBathGimmick != NULL)
	{
		g_pTextureBathGimmick->Release();
		g_pTextureBathGimmick = NULL;
	}

	//���_�o�b�t�@�̔j��
	if (g_pVtxBuffBathGimmick != NULL)
	{
		g_pVtxBuffBathGimmick->Release();
		g_pVtxBuffBathGimmick = NULL;
	}
}

//=============================================
//�X�V
//=============================================
void UpdateBathGimmick(void)
{
	float Random = ((float)rand() / RAND_MAX) * -50.0f;
	if (g_BathWater.bUse == true)
	{
		g_BathWater.nSteamSpawnCnt++;
		if (g_BathWater.nSteamSpawnCnt >= SPAWN_STEAM)
		{
			for (int nUseCnt = 0; nUseCnt < USE_STEAM; nUseCnt++)
			{
				SetSteam(D3DXVECTOR3(g_BathWater.pos.x + Random, g_BathWater.pos.y, g_BathWater.pos.z+ Random), D3DXVECTOR3(0.0f, STEAM_SPEED, 0.0f));
			}
			g_BathWater.nSteamSpawnCnt = 0;
		}
	}
}

//=============================================
//�`��
//=============================================
void DrawBathGimmick(void)
{
	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	D3DXMATRIX mtxRot, mtxTrans; //�v�Z�p�}�g���b�N�X

	if (g_BathWater.bUse == true)
	{
		//�}�g���b�N�X�̏�����
		D3DXMatrixIdentity(&g_mtxWorldBathGimmick);

		//�����𔽉f
		D3DXMatrixRotationYawPitchRoll(&mtxRot, g_BathWater.rot.y, g_BathWater.rot.x, g_BathWater.rot.z);

		D3DXMatrixMultiply(&g_mtxWorldBathGimmick, &g_mtxWorldBathGimmick, &mtxRot);

		//�ʒu�𔽉f
		D3DXMatrixTranslation(&mtxTrans, g_BathWater.pos.x, g_BathWater.pos.y, g_BathWater.pos.z);

		D3DXMatrixMultiply(&g_mtxWorldBathGimmick, &g_mtxWorldBathGimmick, &mtxTrans);

		//���[���h�}�g���b�N�X�̐ݒ�
		pDevice->SetTransform(D3DTS_WORLD, &g_mtxWorldBathGimmick);

		//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
		pDevice->SetStreamSource(0, g_pVtxBuffBathGimmick, 0, sizeof(VERTEX_3D));

		//���_�t�H�[�}�b�g�̐ݒ�
		pDevice->SetFVF(FVF_VERTEX_3D);

		//�e�N�X�`���̐ݒ�
		pDevice->SetTexture(0, g_pTextureBathGimmick);

		//�|���S���̕`��
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
	}
}

//=============================================
//�����̐ݒu
//=============================================
void SetBathWater(D3DXVECTOR3 pos, D3DXVECTOR3 rot , float fWide, float fDepth)
{
	if (g_BathWater.bUse == false)
	{
		g_BathWater.pos = pos;
		g_BathWater.rot = rot;
		g_BathWater.fWide = fWide;
		g_BathWater.fDepth = fDepth;
		g_BathWater.bUse = true;
	}
}

//=============================================
//�����̏��擾
//=============================================
BathWater* GetBathGimmickPos(void)
{
	return &g_BathWater;
}
