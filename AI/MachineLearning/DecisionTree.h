#ifndef decisiontree_h
#define decisiontree_h

#include <vector>
using std::vector;

class Classification
{

};

class LearningExample
{
private:
	Classification classification;
public:
	LearningExample()
	{
	}
	Classification& getClassification()
	{
		return classification;
	}
};

template <class T>
class Attribute
{
	vector<T> values;
};

class Goal
{

};

class DecisionTree
{
private:
	Attribute root;
	DecisionTree(const Attribute& root)
	{
		this->root = root;
	}

public:
	DecisionTree decisionTreeLearning(
			const vector<LearningExample>& examples,
			const vector<Attribute>& attributes,
			const Goal& goal)
	{
		if (examples.size() == 0)
		{
			return goal;
		}
		else if (allSameClassification(example))
		{
			return example.getClassification();
		}
		else if (attributes.size() == 0)
		{
			return majorityValue(examples);
		}
		else
		{
			Attribute best = chooseAttribute(attributes, examples);
			DecisionTree tree(best);
			LearningExample majority = majorityValue(examples);
			for(int i = 0; i < best.values.size(); i++)
			{
				//examples_i = { elements of examples with best = v_i }
				//subtree = decisionlearningtree(examples, attribs - best, m)
				//add branch to tree with label v_i and subtree subtree
			}

			return tree;
		}
	}

	bool allSameClassification(vector<LearningExample>& examples)
	{

	}

	Attribute& chooseAttribute(vector<Attribute>& attributes,
			vector<LearningExamples>& examples)
	{
		//temporary
		return attributes.at(0);
	}

	LearningExample& majorityValue(vector<LearningExample>& examples)
	{
		//temporary
		return examples.at(0);
	}
};

#endif
