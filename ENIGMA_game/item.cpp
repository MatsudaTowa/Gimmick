//=========================================================
//
//�A�C�e����\�����鏈��[billboard.cpp]
// Author seiya kagaya
//
//=========================================================
#include "main.h"
#include "item.h"
//#include "sound.h"
#include "input.h"
//#include "shadow.h"
#include "player.h"
#include "particle.h"


//�O���[�o���ϐ��錾
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffItem = NULL; //���_�o�b�t�@�ւ̃|�C���^
LPDIRECT3DTEXTURE9 g_pTextureItem[ITEMTYPE_MAX] = {};       //�e�N�X�`���ւ̃|�C���^



//D3DXVECTOR3 g_Item[nItem].posItem;	//�ʒu
//D3DXVECTOR3 g_Item[nItem].rotItem;	//����
//D3DXMATRIX g_Item[nItem].mtxWorldItem;//���[���h�}�g���b�N�X


ITEM g_Item[NUMITEM];//���쒆�@�\����
//
//ITEMCNT g_ItemCnt_1P[ITEMTYPE_MAX];//�A�C�e���J�E���^�[
//
//ITEMCNT g_ItemCnt_2P[ITEMTYPE_MAX];//�A�C�e���J�E���^�[

int g_nldShadow4 = -1;

//=============================
//�A�C�e���̏���������
//=============================
void InitItem(void)
{
	////�A�C�e���J�E���^�[
	//for (int n = 0; n < ITEMTYPE_MAX; n++)
	//{
	//	g_ItemCnt_1P[n].ItemCnt = 0;
	//	g_ItemCnt_2P[n].ItemCnt = 0;
	//}

	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\item000.png", &g_pTextureItem[0]);//��D
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\item001.png", &g_pTextureItem[1]);//��
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\item002.png", &g_pTextureItem[2]);//������
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\item003.png", &g_pTextureItem[3]);//�g����
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\item004.png", &g_pTextureItem[4]);//���_

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4 * NUMITEM, D3DUSAGE_WRITEONLY, FVF_VERTEX_3D, D3DPOOL_MANAGED, &g_pVtxBuffItem, NULL);

	VERTEX_3D* pVtx;//���_���ւ̃|�C���^
	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	g_pVtxBuffItem->Lock(0, 0, (void**)&pVtx, 0);

	for (int nItem = 0; nItem < NUMITEM; nItem++)
	{
		//g_Item[nItem].g_Item[nItem].posItem
		//g_Item[nItem].rotItem
		//g_Item[nItem].

		g_Item[nItem].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);//�ʒu
		g_Item[nItem].bGetNO = false;
		g_Item[nItem].nStayGetCnt = 0;
		//g_Item[nItem].rotItem = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	//����

		//g_Item[nItem].mtxWorldItem= D3DXMATRIX(0.0f,0.0f,0.0f);//���[���h�}�g���b�N�X
		g_Item[nItem].bUse = false;
		g_Item[nItem].nfloatCnt = 0;
		g_Item[nItem].move = D3DXVECTOR3(0.2f, 0.1f, 1.0f) * ITEMMOVESPEED_LOCK;
		g_Item[nItem].bRetentionl = false;

		//�e�ݒ�
		g_Item[nItem].nShadowNum = -1;

		//���_���W�̐ݒ�
		pVtx[0].pos = D3DXVECTOR3(-ITEMSIZE, ITEMSIZE, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(ITEMSIZE, ITEMSIZE, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(-ITEMSIZE, -ITEMSIZE, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(ITEMSIZE, -ITEMSIZE, 0.0f);

		//�@���x�N�g���̐ݒ�
		pVtx[0].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		pVtx[1].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		pVtx[2].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		pVtx[3].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);

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

		pVtx += 4;
	}
	//���_�o�b�t�@�̃A�����b�N
	g_pVtxBuffItem->Unlock();





}
//=============================
//�A�C�e���̏I������
//=============================
void UninitItem(void)
{
	//StopSound(SOUND_LABEL_SE_SHOT);
	//StopSound(SOUND_LABEL_SE_EXPLOSIONBOMB);
	//�e�N�X�`���̔j��
	for (int i = 0; i < ITEMTYPE_MAX; i++)
	{
		if (g_pTextureItem[i] != NULL)
		{
			g_pTextureItem[i]->Release();
			g_pTextureItem[i] = NULL;
		}
	}
	//���_�o�b�t�@�̔j��
	if (g_pVtxBuffItem != NULL)
	{
		g_pVtxBuffItem->Release();
		g_pVtxBuffItem = NULL;
	}
}
//=============================
//�A�C�e���̍X�V����
//=============================
void UpdateItem(void)
{

	VERTEX_3D* pVtx;//���_���ւ̃|�C���^

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	g_pVtxBuffItem->Lock(0, 0, (void**)&pVtx, 0);

	for (int nItem = 0; nItem < NUMITEM; nItem++)
	{
		if (g_Item[nItem].bUse == true)
		{
			if (g_Item[nItem].bGetNO == true)
			{
				if (g_Item[nItem].nStayGetCnt > 0)
				{
					g_Item[nItem].nStayGetCnt--;
				}

				if (g_Item[nItem].nStayGetCnt <= 0)
				{
					g_Item[nItem].bGetNO = false;
				}
			}


			//g_Item[nItem].oldPos = g_Item[nItem].pos;
			//�ʒu���X�V
			g_Item[nItem].pos += g_Item[nItem].move;



		
			
			//-------------------------------------------------------------�ӂ�ӂ핂�V
			g_Item[nItem].nfloatCnt++;
			
			if (g_Item[nItem].nfloatCnt > 50)
			{
				if (g_Item[nItem].bfloatRot==false)
				{//���~�ɐ؂�ւ�
					g_Item[nItem].nfloatCnt = 0;
					g_Item[nItem].bfloatRot = true;
				}
				else if (g_Item[nItem].bfloatRot == true)
				{//�㏸�ɐ؂�ւ�
					g_Item[nItem].nfloatCnt = 0;
					g_Item[nItem].bfloatRot = false;

					if (g_Item[nItem].pos.y <= ITEMSIZE)
					{//�����ɐڐG
						g_Item[nItem].pos.y = ITEMSIZE + 0.1f;
						g_Item[nItem].bRetentionl = true;
					}
					else
					{//�ؗ�����

						g_Item[nItem].bRetentionl = false;
					}
				}
			}
			if (g_Item[nItem].bRetentionl == true)
			{//�ؗ����
				if (g_Item[nItem].bfloatRot == true)
				{//���~
					g_Item[nItem].pos.y -= 0.5f;
					
					if (g_Item[nItem].pos.y <= ITEMSIZE)
					{//�����ɐڐG
						g_Item[nItem].pos.y = ITEMSIZE + 0.1f;
					}
				}
				else if (g_Item[nItem].bfloatRot == false)
				{//�㏸
					g_Item[nItem].pos.y += 0.5f;
				}
			}
			else
			{//�ؗ�����Ȃ�
				//�d��
				if (g_Item[nItem].pos.y > ITEMSIZE)
				{//��(�n��ł͂Ȃ�)�̎�
					//�d��
					g_Item[nItem].move.y -= (GRAVITY * 0.29f);
				}
				else
				{//�n��
					g_Item[nItem].bRetentionl = true;//�ؗ���ԂɈڍs
					g_Item[nItem].pos.y = ITEMSIZE +0.1f;
				}
			}
			//-------------------------------------------------------------�ӂ�ӂ핂�V�����܂�

			//�ړ��ʂ��X�V(�^�������Ō���)
			g_Item[nItem].move.x += (0.0f - g_Item[nItem].move.x) * DAMPING_RATIO;
			g_Item[nItem].move.y += (0.0f - g_Item[nItem].move.y) * DAMPING_RATIO;
			g_Item[nItem].move.z += (0.0f - g_Item[nItem].move.z) * DAMPING_RATIO;



			if (g_Item[nItem].ItemType == ITEMTYPE_OHUDA)//��D
			{
				SetParticle(g_Item[nItem].pos, 30.0f, 12, PARTICLETYPE_ITEM, D3DXCOLOR(1.0f, 0.0f, 0.0f, 0.04f));
			}
			else if (g_Item[nItem].ItemType == ITEMTYPE_KAIHUKU)//�񕜃A�C�e��
			{
				SetParticle(g_Item[nItem].pos, 30.0f, 12, PARTICLETYPE_ITEM, D3DXCOLOR(0.0f, 1.0f, 0.0f, 0.04f));
			}
			else if (g_Item[nItem].ItemType == ITEMTYPE_EMA)//�G�n(������??)
			{
				SetParticle(g_Item[nItem].pos, 30.0f, 12, PARTICLETYPE_ITEM, D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.04f));
			}
			else if (g_Item[nItem].ItemType == ITEMTYPE_WARANINGYO)//�g����l�`
			{
				SetParticle(g_Item[nItem].pos, 30.0f, 12, PARTICLETYPE_ITEM, D3DXCOLOR(1.0f, 0.0f, 1.0f, 0.04f));
			}
			else if (g_Item[nItem].ItemType == ITEMTYPE_SIKIGAMI)//���_
			{
				SetParticle(g_Item[nItem].pos, 30.0f, 12, PARTICLETYPE_ITEM, D3DXCOLOR(1.0f, 1.0f, 0.0f, 0.04f));
			}



			




			//SetPositionShadow(g_Item[nItem].nShadowNum, g_Item[nItem].pos, SHADOWSIZE_ITEM);

			//--------------------------------����
			//g_Item[nItem].nLife--;

			//if (g_Item[nItem].nLife < 0)
			//{
			//	//SetExplosion(g_Item[nItem].pos);
			//	g_Item[nItem].bUse = false;
			//	EndProcessShadow(g_Item[nItem].nShadowNum);

			//}
			//--------------------------------����

			if (g_Item[nItem].pos.y < 0.0f)
			{

				//EndProcessShadow(g_Item[nItem].nShadowNum);
				//g_Item[nItem].bUse = false;
			}



		}
		pVtx += 4;
	}
	//���_�o�b�t�@�̃A�����b�N
	g_pVtxBuffItem->Unlock();

}
//=============================
//�A�C�e���̕`�揈��
//=============================
void DrawItem(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	D3DXMATRIX  mtxTrans;//�v�Z�p�}�g���b�N�X
	D3DXMATRIX mtxView;//�r���[�}�g���b�N�X�̎擾

	for (int nItem = 0; nItem < NUMITEM; nItem++)
	{
		if (g_Item[nItem].bUse == true)
		{
			//���C�g�𖳌��ɂ���
			pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

			////Z�̔�r�ύX
			//pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_ALWAYS);
			////Z�o�b�t�@�ɏ������܂Ȃ�
			pDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);




			//���[���h�}�g���b�N�X�̏�����
			D3DXMatrixIdentity(&g_Item[nItem].mtxWorldItem);

			//�����𔽉f
			//D3DXMatrixRotationYawPitchRoll(&mtxRot, g_Item[nItem].rotItem.y, g_Item[nItem].rotItem.x, g_Item[nItem].rotItem.z);

			//D3DXMatrixMultiply(&g_Item[nItem].mtxWorldItem, &g_Item[nItem].mtxWorldItem, &mtxRot);

					//�ʒu�𔽉f
			D3DXMatrixTranslation(&mtxTrans, g_Item[nItem].pos.x, g_Item[nItem].pos.y, g_Item[nItem].pos.z);

			D3DXMatrixMultiply(&g_Item[nItem].mtxWorldItem, &g_Item[nItem].mtxWorldItem, &mtxTrans);



			//�r���[�}�g���b�N�X���擾
			pDevice->GetTransform(D3DTS_VIEW, &mtxView);

			//�|���S�����J�����ɑ΂��Đ��ʂɌ�����
			D3DXMatrixInverse(&g_Item[nItem].mtxWorldItem, NULL, &mtxView);//�t�s�S�����߂�

			g_Item[nItem].mtxWorldItem._41 = 0.0f;
			g_Item[nItem].mtxWorldItem._42 = 0.0f;
			g_Item[nItem].mtxWorldItem._43 = 0.0f;


			//�ʒu�𔽉f
			D3DXMatrixTranslation(&mtxTrans, g_Item[nItem].pos.x, g_Item[nItem].pos.y, g_Item[nItem].pos.z);

			D3DXMatrixMultiply(&g_Item[nItem].mtxWorldItem, &g_Item[nItem].mtxWorldItem, &mtxTrans);

			//���[���h�}�g���b�N�X�̐ݒ�
			pDevice->SetTransform(D3DTS_WORLD, &g_Item[nItem].mtxWorldItem);

			//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
			pDevice->SetStreamSource(0, g_pVtxBuffItem, 0, sizeof(VERTEX_3D));

			//���_�t�H�[�}�b�g�̐ݒ�
			pDevice->SetFVF(FVF_VERTEX_3D);


			//�e�N�X�`���̐ݒ�
			pDevice->SetTexture(0, g_pTextureItem[g_Item[nItem].ItemType]);

			////�A���t�@�u�����f�B���O�����Z�����ɐݒ�
			//pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
			//pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
			//pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);


			//�A�C�e���̕`��
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,//�v���~�e�B�u�̎��
				nItem * 4,//�`�悷��ŏ��̒��_�C���f�b�N�X
				2);//�`�悷��v���~�e�B�u��


			////�A���t�@�u�����f�B���O�����Ƃɖ߂�
			//pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
			//pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
			//pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);


			//���C�g��L���ɂ���
			pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);

			////Z�̔�r�ύX
			//pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
			////Z�o�b�t�@�ɏ������܂Ȃ�
			pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);

			
			//�e�N�X�`����߂�
			pDevice->SetTexture(0, NULL);
		}
	}
}
//=============================
//�A�C�e���̎擾����
//=============================
ITEM* GetItem(void)
{
	return &g_Item[0];
}

////=============================
////�A�C�e���J�E���g�̎擾����
////=============================
//ITEMCNT* GetItemCnt_1P(void)
//{
//	return &g_ItemCnt_1P[0];
//}
////=============================
////�A�C�e���J�E���g�̎擾����
////=============================
//ITEMCNT* GetItemCnt_2P(void)
//{
//	return &g_ItemCnt_2P[0];
//}

//=============================
//�A�C�e���̐ݒ菈��
//=============================
void SetItem(D3DXVECTOR3 Pos, D3DXVECTOR3 Rot, ITEMTYPE Type)
{
	VERTEX_3D* pVtx;//���_���ւ̃|�C���^

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	g_pVtxBuffItem->Lock(0, 0, (void**)&pVtx, 0);

	for (int nItem = 0; nItem < NUMITEM; nItem++)
	{
		if (g_Item[nItem].bUse == false)
		{

			g_Item[nItem].pos = Pos;//�ʒu

			g_Item[nItem].move = Rot;
			g_Item[nItem].move *= ITEMMOVESPEED_LOCK;
				
			// ���A������ق�
			g_Item[nItem].ItemType = Type;
			g_Item[nItem].bUse = true;
			//g_Item[nItem].nLife = 200;
			break;
		}
		pVtx += 4;
	}
	//���_�o�b�t�@�̃A�����b�N
	g_pVtxBuffItem->Unlock();
}


//=============================
//�A�C�e���̎擾�����t���ݒ菈��
//=============================
void SetItem2(D3DXVECTOR3 Pos, D3DXVECTOR3 Rot, ITEMTYPE Type, int NoGetCnt)
{
	VERTEX_3D* pVtx;//���_���ւ̃|�C���^

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	g_pVtxBuffItem->Lock(0, 0, (void**)&pVtx, 0);

	for (int nItem = 0; nItem < NUMITEM; nItem++)
	{
		if (g_Item[nItem].bUse == false)
		{

			g_Item[nItem].pos = Pos;//�ʒu

			g_Item[nItem].move = Rot;
			g_Item[nItem].move *= ITEMMOVESPEED_LOCK;

			// ���A������ق�
			g_Item[nItem].ItemType = Type;
			g_Item[nItem].bUse = true;
			g_Item[nItem].bGetNO = true;
			g_Item[nItem].nStayGetCnt = NoGetCnt;



			break;
		}
		pVtx += 4;
	}
	//���_�o�b�t�@�̃A�����b�N
	g_pVtxBuffItem->Unlock();
}