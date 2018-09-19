#include "neural_network.h"

namespace Echo
{
	NeuralNetwork::NeuralNetwork()
		: m_lossFunction(nullptr)
		, m_learningRate(0.001f)
	{

	}

	void NeuralNetwork::bindMethods()
	{
		CLASS_BIND_METHOD(NeuralNetwork, train,			  DEF_METHOD("train"));
		CLASS_BIND_METHOD(NeuralNetwork, computeOutput,   DEF_METHOD("computeCouput"));
		CLASS_BIND_METHOD(NeuralNetwork, getLearningRate, DEF_METHOD("getLearningRate"));
		CLASS_BIND_METHOD(NeuralNetwork, setLearningRate, DEF_METHOD("setLearningRate"));

		CLASS_REGISTER_PROPERTY(NeuralNetwork, "LearningRate", Variant::Type::Real, "getLearningRate", "setLearningRate");
	}

	// train
	void NeuralNetwork::train(const RealVector& inputVector, const RealVector& expectedOutput)
	{
		// build data structure or sync data
		organzieStructureBaseOnNodeTree();

		// compute output
		computeOutput(inputVector);

		// learn
		learn( expectedOutput);
	}

	// compute output
	RealVector NeuralNetwork::computeOutput(const RealVector& inputVector)
	{
		RealVector output;

		return output;
	}

	// neuron
	Neuron* NeuralNetwork::getNeuron(i32 layer, i32 idx)
	{
		return nullptr;
	}

	// reset
	void NeuralNetwork::reset()
	{

	}

	// organize by node tree structure
	void NeuralNetwork::organzieStructureBaseOnNodeTree()
	{

	}

	// learn
	void NeuralNetwork::learn(const RealVector& expectedOutput)
	{
		Matrix YStar = Matrix(expectedOutput);
	}
}