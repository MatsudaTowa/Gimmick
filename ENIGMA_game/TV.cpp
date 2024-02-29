//=============================================
//
//�e���r�̃M�~�b�N[TV.h]
//Auther Matsuda Towa
//
//=============================================
#include "TV.h"
#include "input.h"

//=============================================
//�O���[�o���ϐ�
//=============================================
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffTV = NULL;
LPDIRECT3DTEXTURE9 g_pTextureTV = {}; //�e�N�X�`���|�C���^
//D3DXVECTOR3 g_movefield; //�ړ���
D3DXMATRIX	g_mtxWorldTV;
TV_VISION g_TV_VISION;

//=============================================
//����������
//=============================================
void InitTV(void)
{
	LPDIRECT3DDEVICE9 pDevice;

	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\bathwater.jpg",
		&g_pTextureTV
	);

	//�����̏����ݒ�
	g_TV_VISION.pos = D3DXVECTOR3(0.0f, 30.0f, 0.0f);
	g_TV_VISION.rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	g_TV_VISION.fWide = TVVISION_WIDE;
	g_TV_VISION.fHeight = TVVISION_HEIGHT;
	g_TV_VISION.bUse = false;
	g_TV_VISION.bOn = false;

	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4, D3DUSAGE_WRITEONLY, FVF_VERTEX_3D, D3DPOOL_MANAGED, &g_pVtxBuffTV, NULL);

	VERTEX_3D* pVtx;

	//���_�o�b�t�@�����b�N�����_���ւ̃|�C���^���擾
	g_pVtxBuffTV->Lock(0, 0, (void**)&pVtx, 0);

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(g_TV_VISION.pos.x - g_TV_VISION.fWide, g_TV_VISION.pos.y + g_TV_VISION.fHeight, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(g_TV_VISION.pos.x + g_TV_VISION.fWide, g_TV_VISION.pos.y + g_TV_VISION.fHeight, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(g_TV_VISION.pos.x - g_TV_VISION.fWide, g_TV_VISION.pos.y - g_TV_VISION.fHeight, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(g_TV_VISION.pos.x + g_TV_VISION.fWide, g_TV_VISION.pos.y - g_TV_VISION.fHeight, 0.0f);

	//�@���x�N�g���̐ݒ�
	pVtx[0].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
	pVtx[1].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
	pVtx[2].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
	pVtx[3].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);

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

	g_pVtxBuffTV->Unlock();
}

//=============================================
//�I������
//=============================================
void UninitTV(void)
{
	//�e�N�X�`���̔j��
	if (g_pTextureTV != NULL)
	{
		g_pTextureTV->Release();
		g_pTextureTV = NULL;
	}

	//���_�o�b�t�@�̔j��
	if (g_pVtxBuffTV != NULL)
	{
		g_pVtxBuffTV->Release();
		g_pVtxBuffTV = NULL;
	}
}

//=============================================
//�X�V����
//=============================================
void UpdateTV(void)
{
}

//=============================================
//�`�揈��
//=============================================
void DrawTV(void)
{
	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	D3DXMATRIX mtxRot, mtxTrans; //�v�Z�p�}�g���b�N�X

	if (g_TV_VISION.bUse == true&&g_TV_VISION.bOn == true)
	{
		//�}�g���b�N�X�̏�����
		D3DXMatrixIdentity(&g_mtxWorldTV);

		//�����𔽉f
		D3DXMatrixRotationYawPitchRoll(&mtxRot, g_TV_VISION.rot.y, g_TV_VISION.rot.x, g_TV_VISION.rot.z);

		D3DXMatrixMultiply(&g_mtxWorldTV, &g_mtxWorldTV, &mtxRot);

		//�ʒu�𔽉f
		D3DXMatrixTranslation(&mtxTrans, g_TV_VISION.pos.x, g_TV_VISION.pos.y, g_TV_VISION.pos.z);

		D3DXMatrixMultiply(&g_mtxWorldTV, &g_mtxWorldTV, &mtxTrans);

		//���[���h�}�g���b�N�X�̐ݒ�
		pDevice->SetTransform(D3DTS_WORLD, &g_mtxWorldTV);

		//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
		pDevice->SetStreamSource(0, g_pVtxBuffTV, 0, sizeof(VERTEX_3D));

		//���_�t�H�[�}�b�g�̐ݒ�
		pDevice->SetFVF(FVF_VERTEX_3D);

		//�e�N�X�`���̐ݒ�
		pDevice->SetTexture(0, g_pTextureTV);

		//�|���S���̕`��
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);


		//�e�N�X�`����߂�
		pDevice->SetTexture(0, NULL);
	}
}

//=============================================
//�e���r�̑��쏈��
//=============================================
void TVController(void)
{
	g_TV_VISION.bOn = g_TV_VISION.bOn ? false : true;
}

//=============================================
//�e���r�̉�ʃZ�b�g����
//=============================================
void SetTVVision(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float fWide, float fHeight)
{
	if (g_TV_VISION.bUse == false)
	{
		g_TV_VISION.pos = pos;
		g_TV_VISION.rot = rot;
		g_TV_VISION.fWide = fWide;
		g_TV_VISION.fHeight = fHeight;
		g_TV_VISION.bUse = true;
		g_TV_VISION.bOn = true;
	}
}

//=============================================
//�`�����l���؂�ւ�
//=============================================
void SelectChannel(int nSelectChannel)
{
}

//=============================================
//�e���r�̏��擾
//=============================================
TV_VISION* GetTVPos(void)
{
	return &g_TV_VISION;
}
