#pragma once

#include <nori/mesh.h>

NORI_NAMESPACE_BEGIN

// 需要的方法: 1,递归build
// 2,击中检测
// 3,击中调用

struct BVHNode {
	int left;
	int right;                 // 对应队列中的序号
	BoundingBox3f m_bbox;
	Mesh const * mesh;         // 按照BVH定义 一个图元对应一个节点
};

class BVH
{
public:
	BVH();
	~BVH();
	void bulid();

private:
	std::vector<BVHNode> BVHTree;
};

inline BVH::BVH()
{
}

inline BVH::~BVH()
{
}
// 输入
// 初始化:构建一个初始节点
// 对初始节点进行划分
// 左节点入队 进行递归划分
// 右节点入队进行递归划分

// 划分方法:找最长的轴
inline void BVH::bulid(Mesh * mesh) {
	BVHNode root;
	root.m_bbox = mesh->getBoundingBox();
	root.left = -1;
	root.right = -1;
	root.mesh = mesh;

	recurseBuild(root);
	
}

inline void BVH::recurseBuild(BVHNode node) {
	for (m : node.mesh) {

	}
}

NORI_NAMESPACE_END