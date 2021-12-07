#pragma once
#include "BehaviourNode.h"
#include <functional>

typedef std::function<BehaviourState(float, BehaviourState)> BehaviourActionFunc;

class BehaviourAction : public BehaviourNode
{
public:
	BehaviourAction(const std::string& nodeName, BehaviourActionFunc func)
		: BehaviourNode(nodeName)
		, function(func)
	{};
	virtual ~BehaviourAction() {};

	BehaviourState Execute(float dt) override
	{
		currentState = function(dt, currentState);
		return currentState;
	};

protected:
	BehaviourActionFunc function;
};