//Search void OnMouseOverIn()
	m_pParent->OnOverInItem(m_dwSlotNumber);
//Change
#ifdef SMART_SLOT_INFO
			TSlot* pSlot;
			if (m_pParent->GetSlotPointer(m_dwSlotNumber, &pSlot))
			{
				if (pSlot->isItem)
				{
					m_pParent->OnOverInItem(m_dwSlotNumber);
				}
				else
				{
					m_pParent->OnOverInSlot(m_dwSlotNumber);
				}
			}
#else
			m_pParent->OnOverInItem(m_dwSlotNumber);
#endif
//Search void OnMouseOverOut()
m_pParent->OnOverOutItem();
//Change
#ifdef SMART_SLOT_INFO
			TSlot* pSlot;
			if (m_pParent->GetSlotPointer(m_dwSlotNumber, &pSlot))
			{
				if (pSlot->isItem)
				{
					m_pParent->OnOverOutItem();
				}
				else
				{
					m_pParent->OnOverOutSlot();
				}
			}
#else
			m_pParent->OnOverOutItem();
#endif
//Search
void CSlotWindow::OnMouseOverOut()
{
	OnOverOutItem();
//Add Under
#ifdef SMART_SLOT_INFO
	OnOverOutSlot();
#endif
//Search
void CSlotWindow::OnMouseOver()
//Change
void CSlotWindow::OnMouseOver()
{
//	if (UI::CWindowManager::Instance().IsCapture())
//	if (!UI::CWindowManager::Instance().IsAttaching())
//		return;

	CWindow * pPointWindow = UI::CWindowManager::Instance().GetPointWindow();
#ifdef SMART_SLOT_INFO
	TSlot* pSlot;
	if (this == pPointWindow)
	{
		if (GetPickedSlotPointer(&pSlot))
		{
			if (OnOverInItem(pSlot->dwSlotNumber))
			{
				return;
			}
			else
			{
				OnOverOutItem();
			}

			if (OnOverInSlot(pSlot->dwSlotNumber))
			{
				return;
			}
			else
			{
				OnOverOutSlot();
			}
			return;
		}
	}

	OnOverOutItem();
	OnOverOutSlot();
#else
	if (this == pPointWindow)
	{
		TSlot* pSlot;
		if (GetPickedSlotPointer(&pSlot))
		{
			if (OnOverInItem(pSlot->dwSlotNumber))
			{
				return;
			}
		}
	}

	OnOverOutItem();
#endif
}
//Search
BOOL CSlotWindow::OnOverInItem(DWORD dwSlotNumber)
//Add Above
#ifdef SMART_SLOT_INFO
BOOL CSlotWindow::OnOverInSlot(DWORD dwSlotNumber)
{
	TSlot* pSlot;
	if (!GetSlotPointer(dwSlotNumber, &pSlot))
	{
		return FALSE;
	}

	if (pSlot->isItem)
	{
		return FALSE;
	}

	if (pSlot->dwSlotNumber == m_dwOverInSlotNumber)
	{
		return TRUE;
	}

	m_dwOverInSlotNumber = dwSlotNumber;
	PyCallClassMemberFunc(m_poHandler, "OnOverIn", Py_BuildValue("(i)", dwSlotNumber));
	return TRUE;
}

void CSlotWindow::OnOverOutSlot()
{
	if (SLOT_NUMBER_NONE == m_dwOverInSlotNumber)
	{
		return;
	}

	m_dwOverInSlotNumber = SLOT_NUMBER_NONE;
	PyCallClassMemberFunc(m_poHandler, "OnOverOut", Py_BuildValue("()"));
}
#endif

//by stoopid	
