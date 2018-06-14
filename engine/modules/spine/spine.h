#pragma once

#include "engine/core/util/StringOption.h"
#include "engine/core/scene/Node.h"
#include "engine/core/render/mesh/Mesh.h"
#include "engine/core/render/Material.h"
#include "engine/core/render/render/Renderable.h"

struct spAtlas;
struct spSkeleton;
struct spSkeletonData;
struct spAnimationState;
struct spAttachmentLoader;

namespace Echo
{
	class Spine : public Node
	{
		ECHO_CLASS(Spine, Node)

	public:
		Spine();
		virtual ~Spine();

		// set spin
		void setSpin(const ResourcePath& res);

		// get spin
		const ResourcePath& getSpin() { return m_spinRes; }

		// set atlas
		void setAtlas(const ResourcePath& res);

		// get atlas
		const ResourcePath& getAtlas() { return m_atlasRes; }
		
		// play anim
		void setAnim(const StringOption& animName);

		// get animations
		const StringOption& getAnim() { return m_animations; }

	protected:
		// update
		virtual void update();

		// get global uniforms
		virtual void* getGlobalUniformValue(const String& name);

		// submit to renderqueue
		void submitToRenderQueue();

		// clear
		void clear();
		void clearRenderable();

	private:
		ResourcePath		m_spinRes;
		ResourcePath		m_atlasRes;
		StringOption		m_animations;
		spAtlas*			m_spAtlas;
		spSkeletonData*		m_spSkeletonData;
		spSkeleton*			m_spSkeleton;
		spAnimationState*	m_spAnimState;
		spAttachmentLoader*	m_attachmentLoader;
		Matrix4				m_matWVP;
	};
}