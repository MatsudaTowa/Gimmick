//=============================================
//
//�����C�̃M�~�b�N[trap.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "trap.h"

//=============================================
//�ǂ̃e�N�X�`���̎��
//=============================================
static const char* TRAP_TEX_NAME =
{
	"data\\TEXTURE\\trap000.png",
};

//=========================================================
//�O���[�o���ϐ�
//=========================================================
LPDIRECT3DTEXTURE9 g_pTextureTrap = {};//�e�N�X�`���ւ̃|�C���^
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffTrap = NULL;//���_�o�b�t�@�ւ̃|���S��
Trap g_Trap;	//�|�[�Y�\���̂̏��

//=============================================
//�g���b�v�̏�����
//=============================================
void InitTrap(void)
{
	LPDIRECT3DDEVICE9 pDevice;	//�f�o�C�X�ւ̃|�C���^

//�f�o�C�X�̎擾
	pDevice = GetDevice();

	//	int nCntPause = 0;

		//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		TRAP_TEX_NAME,
		&g_pTextureTrap
	);

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4, D3DUSAGE_WRITEONLY, FVF_VERTEX_2D, D3DPOOL_MANAGED, &g_pVtxBuffTrap, NULL);

	VERTEX_2D* pVtx;//���_���̃|�C���^

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	g_pVtxBuffTrap->Lock(0, 0, (void**)&pVtx, 0);
	g_Trap.pos = D3DXVECTOR3(SCREEN_WIDE / 4.0f, SCREEN_HEIGHT / 3.0f, 0.0f);
	pVtx[0].pos = D3DXVECTOR3(g_Trap.pos.x - SCREEN_WIDE / 4.0f, g_Trap.pos.y - SCREEN_HEIGHT / 3.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(g_Trap.pos.x + SCREEN_WIDE / 4.0f, g_Trap.pos.y - SCREEN_HEIGHT / 3.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(g_Trap.pos.x - SCREEN_WIDE / 4.0f, g_Trap.pos.y + SCREEN_HEIGHT / 3.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(g_Trap.pos.x + SCREEN_WIDE / 4.0f, g_Trap.pos.y + SCREEN_HEIGHT / 3.0f, 0.0f);
	//rhw�̐ݒ�
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	//���_�J���[�̐ݒ�
	pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 200);
	pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 200);
	pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 200);
	pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 200);

	//�e�L�X�`���̍��W�ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	g_pVtxBuffTrap->Unlock();
}

//=============================================
//�g���b�v�̏I��
//=============================================
void UninitTrap(void)
{
	//�e�N�X�`���̔j��
	if (g_pTextureTrap != NULL)
	{
		g_pTextureTrap->Release();
		g_pTextureTrap = NULL;
	}
	//���_�o�b�t�@�̔j��
	if (g_pVtxBuffTrap != NULL)
	{
		g_pVtxBuffTrap->Release();
		g_pVtxBuffTrap = NULL;
	}

}

//=============================================
//�g���b�v�̍X�V
//=============================================
void UpdateTrap(void)
{

}

//=============================================
//�g���b�v�̕`��
//=============================================
void DrawTrap(void)
{
	LPDIRECT3DDEVICE9 pDevice;	//�f�o�C�X�ւ̃|�C���^

//�f�o�C�X�̎擾
	pDevice = GetDevice();//----------------���������ς�

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, g_pVtxBuffTrap, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);//-------���������ς�

	//�e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, g_pTextureTrap);//---------���������ς�

	//�|���S���̕`��
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,//�v���~�e�B�u�̎��//----------���������ς�
		0,//�`�悷��ŏ��̒��_�C���f�b�N�X
		2);//�`�悷��v���~�e�B�u��
}
