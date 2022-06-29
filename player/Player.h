#pragma once
#include "WorldTransform.h"
#include "Model.h"
#include <assert.h>
#include "Input.h"
#include "DebugText.h"
#include "affin.h"
#include "PlayerBullet.h"
#include "memory"
#include <list>


class Player {

public:
	/// <summary>
	/// ������
	/// <summary>
	void Initialize(Model* model, uint32_t textureHandle);

	/// <summary>
	/// �X�V
	/// <summary>
	void Move();

	/// <summary>
	/// �X�V
	/// <summary>
	void Update();

	/// <summary>
	/// �`��
	/// <summary>
	void Draw(ViewProjection& viewProjection_);

	///< summary>
	///������
	///</summary>
	void Attack();

	Vector3 bVelocity(Vector3& velocity, WorldTransform& worldTransform);

private:
	//���[���h�ϊ��f�[�^
	WorldTransform worldTransform_;
	//���f��
	Model* model_ = nullptr;
	//�e�N�X�`���n���h��
	uint32_t textureHandle_ = 0u;
	Input* input_ = nullptr;
	DebugText* debugText_ = nullptr;

	//�e
	std::list<std::unique_ptr<PlayerBullet>>bullets_;



};