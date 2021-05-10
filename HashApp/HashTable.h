//---------------------------------------------------------------------------
#include "List.h"
#include "HashElem.h"
#include <vcl.h>
#ifndef HashTableH
#define HashTableH
//---------------------------------------------------------------------------
#endif

class HashTable: public List<HashElem>, public HashElem
{
	List<HashElem> hashTable[12];
	public: HashElem elem;

	public: void toHashTable (TMemo* Memo)
	{
		elem.toHash();
		hashTable[elem.hash].PushBack(elem);
		if (hashTable[elem.hash].GetSize() == 1)
			Memo->Lines->Strings[elem.hash] += IntToStr(elem.data);
		else
			Memo->Lines->Strings[elem.hash] += ", " + IntToStr(elem.data);

	}

	public: void deleteElem (TMemo* Memo)
	{
		elem.toHash();
		for(int i = 0; i < hashTable[elem.hash].GetSize(); i++)
			hashTable[elem.hash].PopFront();
		Memo->Lines->Strings[elem.hash] = IntToStr(elem.hash) + ". ";
	}

	public: void findElem (TEdit* Edit, int hash)
	{
		if(hash<=12 && hash>=0)
		{
			Edit->Text="";
			Edit->Font->Color = clWindowText;
			if (hashTable[hash].GetSize() == 0)
				Edit->Text="Ïףסעמ";
			else
			{
				for(int i = 0; i < hashTable[hash].GetSize()-1; i++)
					Edit->Text+=IntToStr(hashTable[elem.hash][i].data)+", ";
				Edit->Text+=IntToStr(hashTable[elem.hash][hashTable[hash].GetSize()-1].data);
			}
		}
		else
		 ShowMessage("Âגוהטעו הויסעגטעוכüםûי ץ‎ר");
	}

	public: void minElem (TEdit* Edit)
	{
		Edit->Text = "";
		for(int i = 0; i < 12; i++)
			if (hashTable[i].GetSize() != 0)
			{
				for(int j = 0; j<hashTable[i].GetSize()-1; j++)
					Edit->Text+=IntToStr(hashTable[i][j].data)+", ";
				Edit->Text+=IntToStr(hashTable[i][hashTable[i].GetSize()-1].data);
                break;
			}

	}
};