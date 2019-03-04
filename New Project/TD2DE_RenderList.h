#pragma once

namespace TD2DE 
{
	class TD2DE_RenderListNode //TODO: this node should control WHERE the texture gets rendered
	{
	private:
		TD2DE_RenderListNode* next;
		TD2DE_RenderListNode* last;

		TextureNode* texture;

	public:
		TD2DE_RenderListNode();
		void Delete();
		void SetNext(TD2DE_RenderListNode* newNext);
		void SetLast(TD2DE_RenderListNode* newLast);
	};

	class TD2DE_RenderList
	{
	private:
		TD2DE_RenderListNode* first;
		TD2DE_RenderListNode* last;
		int total;

	public:
		TD2DE_RenderList();
		void Add(TD2DE_RenderListNode* node);
		bool Remove(TD2DE_RenderListNode* node);
		TD2DE_RenderListNode& GetByName(std::string texName);
		TD2DE_RenderListNode& GetByLocation(int location);
	}TD2DE_RENDERLIST;
}

TD2DE::TD2DE_RenderListNode::TD2DE_RenderListNode()
{
	next = NULL;
	last = NULL;
	texture = NULL;
}

void TD2DE::TD2DE_RenderListNode::Delete()
{
	if (last != NULL)
	{

	}
}

void TD2DE::TD2DE_RenderListNode::SetNext(TD2DE_RenderListNode* newNext)
{
	next = newNext;
}

void TD2DE::TD2DE_RenderListNode::SetLast(TD2DE_RenderListNode* newLast)
{
	last = newLast;
}

TD2DE::TD2DE_RenderList::TD2DE_RenderList()
{
	first = NULL;
	last = NULL;
	total = 0;
}

void TD2DE::TD2DE_RenderList::Add(TD2DE_RenderListNode* node)
{	
	if (total == 0)//nothing added to render list yet
	{
		first = node;
		last = node;
		total++;
	}
	else if (total == 1)//we have one object in the render list
	{
		first->SetNext(node);
		node->SetLast(first);
		last = node;
		total++;
	}
	else if (total > 1)//we have more then one object in the list
	{
		node->SetLast(last);
		last->SetNext(node);
		last = node;
		total++;
	}
}


