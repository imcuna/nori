#pragma once

#include <nori/mesh.h>

NORI_NAMESPACE_BEGIN

// 需要的方法: 1,递归build
// 2,击中检测
// 3,击中调用


// 数据结构修改
// 如何保存当前节点的所有mesh?
// 新建一个Mesh太耗了
// 1,对mesh进行排序(可以类似快排的策略 只需要找到中位数 然后把 比他小/大的放在左/右边就行了 )
// 2,保存每次的begin and end 来确定当前包围盒对应的meshes
// 这样一来 需要保存的就是当前mesh对应的BBox
// 
// 关于击中检测:
// node里需要保存: 当前bBox,左节点在队列中的位置,右节点在队列中的位置 如果是叶节点 那么应该还要保存当前节点的三角形坐标
// 击中检测中在非叶节点时 不需要当前bbox mesh信息!!!!!

// mesh的数据结构:
// faces中保存了顶点编号
// 顶点位置保存在m_V中 1,直接对faces进行排序 2,建立一个faces的索引 对这个索引进行排序
struct BVHNode {
	int left;
	int right;                 // 对应队列中的序号
	BoundingBox3f m_bbox;
	int meshIdx;         // 按照BVH定义 一个图元对应一个节点
};

class BVH
{
public:
	BVH();
	~BVH();
	void bulid();

private:
	std::vector<BVHNode> BVHTree;
	std::vector<uint32_t> meshIndexes;
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

	for (uint32_t idx = 0; idx < m_mesh->getTriangleCount(); ++idx) {  // todo:可以改成直接对原数据排序?
		meshIndexes.emplace_back(idx);
		
	}

	recurseBuild(root);
	
}
// 1,找到最长的轴
// 2,用快速选择算法,找到中间的元素
// 3,
inline void BVH::recurseBuild(BVHNode node) {
	auto nodeBox = node.mesh->getBoundingBox();
	int longestAxis = nodeBox.getLargestAxis();
	auto bboxCenter = nodeBox.getCenter();

	std::nth_element();

	for (uint32_t idx = 0; idx < node.mesh->getTriangleCount(); ++idx) {
		auto curBbox = node.mesh->getBoundingBox(idx);
		if (bboxCenter[longestAxis] <= curBbox.getCenter()[longestAxis]) {
			leftMesh.addChild()
		}
		
	}
}

NORI_NAMESPACE_END