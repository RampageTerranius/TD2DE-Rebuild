#pragma once

namespace TD2DE 
{
	class TD2DE_RenderListNode
	{
	private:
		TD2DE_RenderListNode* next;
		TD2DE_RenderListNode* last;

		

		TextureNode* texture;

	public:
		std::string name;

		TD2DE_RenderListNode();
		void Delete();
		TD2DE_RenderListNode* GetNext();
		void SetNext(TD2DE_RenderListNode* newNext);
		TD2DE_RenderListNode* GetLast();
		void SetLast(TD2DE_RenderListNode* newLast);
		void ReplaceTexture(TextureNode* newTexture);
	};

	class TD2DE_RenderList//TODO: add an array that handles where each layer begins to help with layering images as needed
	{
	private:
		TD2DE_RenderListNode* first;
		TD2DE_RenderListNode* last;
		int total;

	public:
		TD2DE_RenderList();
		void Add(TD2DE_RenderListNode* node);
		bool Remove(TD2DE_RenderListNode* node);
		TD2DE_RenderListNode* GetByName(std::string renderName);
		TD2DE_RenderListNode* GetByIndex(int index);
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
	TD2DE::TD2DE_RENDERLIST.Remove(this);
}

TD2DE::TD2DE_RenderListNode* TD2DE::TD2DE_RenderListNode::GetNext()
{
	return next;
}

void TD2DE::TD2DE_RenderListNode::SetNext(TD2DE_RenderListNode* newNext)
{
	next = newNext;
}

TD2DE::TD2DE_RenderListNode* TD2DE::TD2DE_RenderListNode::GetLast()
{
	return last;
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

bool TD2DE::TD2DE_RenderList::Remove(TD2DE_RenderListNode* node)
{
	TD2DE_RenderListNode* currentNode = node;

	while (currentNode->GetNext() != NULL)
	{
		if (currentNode == node)//we found the node to remove
		{
			if (node->GetNext() != NULL)
				node->GetNext()->SetLast(node->GetLast());
			if (node->GetLast() != NULL)
				node->GetLast()->SetNext(node->GetNext());
			
			//TODO: debug info here...

			return true;
		}
	}

	return false;
}


TD2DE::TD2DE_RenderListNode* TD2DE::TD2DE_RenderList::GetByName(std::string renderName)
{
	TD2DE_RenderListNode* currentNode = first;

	if (first != NULL)
		while (currentNode != NULL)
			if (currentNode->name == renderName)//we found the node
			{
				return currentNode;
				//TODO: debug info here...
			}
			else
				currentNode = currentNode->GetNext();


	//TODO: debug info here...
	//found nothing
	return NULL;
}

//WARNING: the index will constantly change as Render objects are added and removed, it is HIGHLY reccomended you get by name instead
TD2DE::TD2DE_RenderListNode* TD2DE::TD2DE_RenderList::GetByIndex(int index)
{
	TD2DE_RenderListNode* currentNode = first;

	if (first != NULL)
	{
		int i = 0;

		while (i <= index)
		{
			if (i = index)
				return currentNode;//at the correct index
			else if (currentNode->GetNext() != NULL)
			{
				//not yet at correct index, not yet at end of list
				currentNode = currentNode->GetNext();
				i++;
			}
			else
				break;//reached end of list but didnt reach correct index
		}

	}

	//TODO: debug info here...
	//went out of range or ran out of objects
	return NULL;
}