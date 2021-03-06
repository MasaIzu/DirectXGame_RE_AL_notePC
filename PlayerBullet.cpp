#include "PlayerBullet.h"

void PlayerBullet::Initialize(Model* model, const Vector3& position) {
	assert(model);

	model_ = model;
	//テクスチャ読み込み
	textureHandle_ = TextureManager::Load("Black.png");

	//ワールド変換の初期化
	worldTransform_.Initialize();

	//引数で受け取った初期座標をセット
	worldTransform_.translation_ = position;


}

void PlayerBullet::Update() {
	//行列更新
	AffinTrans::affin(worldTransform_);

	worldTransform_.TransferMatrix();
}

void PlayerBullet::Draw(const ViewProjection& viewProjection) {
	model_->Draw(worldTransform_, viewProjection, textureHandle_);
}